class CookZ_DrumPeeler : Pot
{
    override bool CanReceiveItemIntoCargo(EntityAI item)
    {
        if (item.GetType() != "PotatoSeed" && item.GetType() != "Potato")
        {
            return false;
        }
        
        return super.CanReceiveItemIntoCargo(item);
    }

    override void SetActions()
    {
        super.SetActions();
        AddAction(CookZ_ActionDrumPeel);
    }
};
