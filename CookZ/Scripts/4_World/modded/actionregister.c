modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
        actions.Insert(CookZ_ActionReadBook);
        actions.Insert(CookZ_ActionDrumPeel);
    }
};

class CookZ_ActionReadBook extends ActionSingleUseBase
{
    void CookZ_ActionReadBook()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_DROPITEM_HANDS;
        m_FullBody = false;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_PRONE;
    }

    override void CreateConditionComponents()
    {
        m_ConditionItem = new CCINonRuined;
        m_ConditionTarget = new CCTNone;
    }

    override bool HasTarget()
    {
        return false;
    }

    override string GetText()
    {
        return "#read";
    }

    override void OnExecuteClient( ActionData action_data )
    {
        action_data.m_Player.ToggleCookbookReading();
    }

    override void OnExecuteServer( ActionData action_data )
    {
        if (!GetGame().IsMultiplayer())
            action_data.m_Player.ToggleCookbookReading();
    }
};

class CookZ_ActionDrumPeelCB : ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
        m_ActionData.m_ActionComponent = new CAContinuousTime(0.5);
    }
};

class CookZ_ActionDrumPeel : ActionContinuousBase
{
    static int WATER_PER_POTATO_ML = 20;
    static int HEALTH_PER_POTATO = 1;

    void CookZ_ActionDrumPeel()
    {
        m_CallbackClass     = CookZ_ActionDrumPeelCB;
        m_CommandUID        = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
        m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
        m_Text              = "#PeelPotato";
        m_FullBody          = true;
    }

    override void CreateConditionComponents()  
    {
        m_ConditionItem = new CCINonRuined;
    }

    override bool HasTarget()
    {
        return false;
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        CookZ_DrumPeeler peeler = CookZ_DrumPeeler.Cast(item);
        if (!peeler)
        {
            return false;
        }

        if (peeler.GetLiquidType() != LIQUID_WATER || peeler.GetQuantity() < WATER_PER_POTATO_ML)
        {
            return false;
        }

        CargoBase cargo = peeler.GetInventory().GetCargo();
        if (!cargo)
        {
            return false;
        }

        bool hasOnePotatoSeed = false;
        for (int i = 0; i < cargo.GetItemCount(); i++)
        {
            if (cargo.GetItem(i).GetType() != "PotatoSeed")
            {
                // don't allow != PotatoSeed
                return false;
            }
            else
            {
                // needs at least one PotatoSeed
                hasOnePotatoSeed = true;
            }
        }

        return hasOnePotatoSeed;
    }

    override void OnEndServer( ActionData action_data )
    {
        super.OnEndServer(action_data);
        
        CookZ_DrumPeeler peeler = CookZ_DrumPeeler.Cast(action_data.m_MainItem);
        if (!peeler)
        {
            return;
        }

        CargoBase cargo = peeler.GetInventory().GetCargo();
        if (!cargo)
        {
            return;
        }

        int maxCanBePeeldByWater = peeler.GetQuantity() / WATER_PER_POTATO_ML;

        int numInCargo = cargo.GetItemCount();
        int numPeeled = 0;
        // needs to be i--, replacing an item seems to have an effect on GetItem(i)
        // I would have thought this goes by position in cargo
        for (int i = numInCargo - 1; numPeeled < maxCanBePeeldByWater && i >= 0; i--)
        {
            if (cargo.GetItem(i).GetType() == "PotatoSeed")
            {
                TurnItemIntoItemLambda lambda = new TurnItemIntoItemLambda(cargo.GetItem(i), "Potato", action_data.m_Player);
                // potato quantity is 200, just use something larger or equal
                // for normal potatoes this is not needed, but for some reason for potatoes spawned by VPPAdminTools
                lambda.SetTransferParams(true, true, true, false, 1000);
                if (action_data.m_Player.ServerReplaceItemWithNew(lambda))
                {
                    numPeeled++; 
                }
            }
        }

        peeler.AddQuantity(-(numPeeled*WATER_PER_POTATO_ML));
        peeler.AddHealth("", "", -(numPeeled*HEALTH_PER_POTATO));
    }
};
