class CookZPlants_WheatSeedsPack extends SeedPackBase {}
class CookZPlants_ChiliSeedsPack extends SeedPackBase {}
class CookZPlants_CornSeedsPack extends SeedPackBase {}
class CookZPlants_OnionSeedsPack extends SeedPackBase {}
class CookZPlants_SoyBeanSeedsPack extends SeedPackBase {}
class CookZPlants_SugarBeetSeedsPack extends SeedPackBase {}
class CookZPlants_SunflowerSeedsPack extends SeedPackBase {}
class CookZPlants_CabbageSeedsPack extends SeedPackBase {}
class CookZPlants_CucumberSeedsPack extends SeedPackBase {}

class CookZPlants_WheatSeeds : SeedBase {};
class CookZPlants_ChiliSeeds : SeedBase {};
class CookZPlants_CornSeeds : SeedBase {};
class CookZPlants_OnionSeeds : SeedBase {};
class CookZPlants_OnionSeed : SeedBase {};
class CookZPlants_SoyBeanSeeds : SeedBase {};
class CookZPlants_SugarBeetSeeds : SeedBase {};
class CookZPlants_MushroomSpawn : SeedBase {};
class CookZPlants_SunflowerSeeds : SeedBase {};
class CookZPlants_CabbageSeeds : SeedBase {};
class CookZPlants_CucumberSeeds : SeedBase {};

modded class PlantBase
{
    // access private variables in extending classes
    
    protected void CookZPlants_DisableInfection()
    {
         m_InfestationChance = 0;
    }

    protected int CookZPlants_GetCropsCount()
    {
        return m_CropsCount;
    }

    protected string CookZPlants_GetCropsType()
    {
        return m_CropsType;
    }

    protected void CookZPlants_SetHasCrops(bool value)
    {
        m_HasCrops = value;
    }
};

class CookZPlants_PlantBase : PlantBase
{
    override void Init(GardenBase garden_base, float fertility, float harvesting_efficiency, float water)
    {
        if (GetDayZGame().GetCookZPlants_Config().DisablePlantInfection)
        {
            CookZPlants_DisableInfection(); // set before super call because already used in Init
        }
        super.Init(garden_base, fertility, harvesting_efficiency, water);
    }
};

class CookZPlants_PlantWheat : CookZPlants_PlantBase
{
    void CookZPlants_PlantWheat()
    {
        if (GetDayZGame().GetCookZPlants_Config())
        {
            m_FullMaturityTime = Math.Max(100, GetDayZGame().GetCookZPlants_Config().FullMaturityTimeWheat);
        }
        else
        {
            // this can only happen on client if rpc config did not arrive yet, but server value counts anyway
            m_FullMaturityTime = 1350;
        }
    }

    // harvest an item that is splitable - i.e. only create one item and set the quantity to m_CropsCount
    override void Harvest( PlayerBase player )
    {
        if (IsHarvestable())
        {
            vector pos = player.GetPosition();
            ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx( CookZPlants_GetCropsType(), pos, ECE_PLACE_ON_SURFACE ) );
            item.SetQuantity(CookZPlants_GetCropsCount());
        }
        
        CookZPlants_SetHasCrops(false);

        SetSynchDirty();

        UpdatePlant();
        GetGarden().SyncSlots();
    }
};

class CookZPlants_PlantChili : CookZPlants_PlantBase
{
    void CookZPlants_PlantChili()
    {
        if (GetDayZGame().GetCookZPlants_Config())
        {
            m_FullMaturityTime = Math.Max(100, GetDayZGame().GetCookZPlants_Config().FullMaturityTimeChili);
        }
        else
        {
            // this can only happen on client if rpc config did not arrive yet, but server value counts anyway
            m_FullMaturityTime = 1350;
        }
    }
};

class CookZPlants_PlantCorn : CookZPlants_PlantBase
{
    void CookZPlants_PlantCorn()
    {
        if (GetDayZGame().GetCookZPlants_Config())
        {
            m_FullMaturityTime = Math.Max(100, GetDayZGame().GetCookZPlants_Config().FullMaturityTimeCorn);
        }
        else
        {
            // this can only happen on client if rpc config did not arrive yet, but server value counts anyway
            m_FullMaturityTime = 1350;
        }
    }
};

class CookZPlants_PlantOnion : CookZPlants_PlantBase
{
    void CookZPlants_PlantOnion()
    {
        if (GetDayZGame().GetCookZPlants_Config())
        {
            m_FullMaturityTime = Math.Max(100, GetDayZGame().GetCookZPlants_Config().FullMaturityTimeOnion);
        }
        else
        {
            // this can only happen on client if rpc config did not arrive yet, but server value counts anyway
            m_FullMaturityTime = 1350;
        }
    }
};

class CookZPlants_PlantSoyBean : CookZPlants_PlantBase
{
    void CookZPlants_PlantSoyBean()
    {
        if (GetDayZGame().GetCookZPlants_Config())
        {
            m_FullMaturityTime = Math.Max(100, GetDayZGame().GetCookZPlants_Config().FullMaturityTimeSoybean);
        }
        else
        {
            // this can only happen on client if rpc config did not arrive yet, but server value counts anyway
            m_FullMaturityTime = 1350;
        }
    }

    // harvest an item that is splitable - i.e. only create one item and set the quantity to m_CropsCount
    override void Harvest( PlayerBase player )
    {
        if (IsHarvestable())
        {
            vector pos = player.GetPosition();
            ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx( CookZPlants_GetCropsType(), pos, ECE_PLACE_ON_SURFACE ) );
            item.SetQuantity(CookZPlants_GetCropsCount());
        }
        
        CookZPlants_SetHasCrops(false);

        SetSynchDirty();

        UpdatePlant();
        GetGarden().SyncSlots();
    }
};

class CookZPlants_PlantMushroom : CookZPlants_PlantBase
{
    // exclude not-spawning content "PsilocybeMushroom", "AmanitaMushroom", "AuriculariaMushroom"
    static ref array<string> m_RandomMushrooms = {"AgaricusMushroom", "BoletusMushroom", "LactariusMushroom", "MacrolepiotaMushroom", "PleurotusMushroom", "CraterellusMushroom"};

    void CookZPlants_PlantMushroom()
    {
        if (GetDayZGame().GetCookZPlants_Config())
        {
            m_FullMaturityTime = Math.Max(100, GetDayZGame().GetCookZPlants_Config().FullMaturityTimeMushroom);
        }
        else
        {
            // this can only happen on client if rpc config did not arrive yet, but server value counts anyway
            m_FullMaturityTime = 1350;
        }
    }

    override void RemovePlantEx( vector pos )
    {
        if ( g_Game && g_Game.IsServer() )
        {
            UnlockFromParent();
            
            ItemBase item = ItemBase.Cast( g_Game.CreateObjectEx( "FireWood", pos, ECE_PLACE_ON_SURFACE ) );
            item.SetQuantity(1);
            
            RemoveSlot();
        }
    }

    override void Harvest( PlayerBase player )
    {
        if (IsHarvestable())
        {
            for ( int i = 0; i < CookZPlants_GetCropsCount(); i++ )
            {
                vector pos = player.GetPosition();
                ItemBase item = ItemBase.Cast( g_Game.CreateObjectEx( m_RandomMushrooms.GetRandomElement(), pos, ECE_PLACE_ON_SURFACE ) );
                item.SetQuantity( item.GetQuantityMax() );
            }
        }

        CookZPlants_SetHasCrops(false);

        SetSynchDirty();

        UpdatePlant();
        GetGarden().SyncSlots();
    }
};

class CookZPlants_PlantSugarBeet : CookZPlants_PlantBase
{
    void CookZPlants_PlantSugarBeet()
    {
        if (GetDayZGame().GetCookZPlants_Config())
        {
            m_FullMaturityTime = Math.Max(100, GetDayZGame().GetCookZPlants_Config().FullMaturityTimeSugarBett);
        }
        else
        {
            // this can only happen on client if rpc config did not arrive yet, but server value counts anyway
            m_FullMaturityTime = 1350;
        }
    }

    override void Harvest( PlayerBase player )
    {        
        if (IsHarvestable())
        {
            vector pos = player.GetPosition();
            for ( int i = 0; i < CookZPlants_GetCropsCount(); i++ )
            {
                ItemBase item = ItemBase.Cast( g_Game.CreateObjectEx( CookZPlants_GetCropsType(), pos, ECE_PLACE_ON_SURFACE ) );
                item.SetQuantity( item.GetQuantityMax() );
            }
            // create some seeds when harvesting - cutting them out is imho too unrealistic
            ItemBase seeds = ItemBase.Cast( g_Game.CreateObjectEx( "CookZPlants_SugarBeetSeeds", pos, ECE_PLACE_ON_SURFACE ) );
            seeds.SetQuantity( CookZPlants_GetCropsCount() );
        }
        
        CookZPlants_SetHasCrops(false);

        SetSynchDirty();

        UpdatePlant();
        GetGarden().SyncSlots();
    }
};

class CookZPlants_PlantSunflower : CookZPlants_PlantBase
{
    void CookZPlants_PlantSunflower()
    {
        if (GetDayZGame().GetCookZPlants_Config())
        {
            m_FullMaturityTime = Math.Max(100, GetDayZGame().GetCookZPlants_Config().FullMaturityTimeSunflower);
        }
        else
        {
            // this can only happen on client if rpc config did not arrive yet, but server value counts anyway
            m_FullMaturityTime = 1350;
        }
    }

    // harvest an item that is splitable - i.e. only create one item and set the quantity to m_CropsCount
    override void Harvest( PlayerBase player )
    {
        if (IsHarvestable())
        {
            vector pos = player.GetPosition();
            ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx( CookZPlants_GetCropsType(), pos, ECE_PLACE_ON_SURFACE ) );
            item.SetQuantity(CookZPlants_GetCropsCount());
        }
        
        CookZPlants_SetHasCrops(false);

        SetSynchDirty();

        UpdatePlant();
        GetGarden().SyncSlots();
    }
};

class CookZPlants_PlantCabbage : CookZPlants_PlantBase
{
    void CookZPlants_PlantCabbage()
    {
        if (GetDayZGame().GetCookZPlants_Config())
        {
            m_FullMaturityTime = Math.Max(100, GetDayZGame().GetCookZPlants_Config().FullMaturityTimeCabbage);
        }
        else
        {
            // this can only happen on client if rpc config did not arrive yet, but server value counts anyway
            m_FullMaturityTime = 1350;
        }
    }

    override void Harvest( PlayerBase player )
    {        
        if (IsHarvestable())
        {
            vector pos = player.GetPosition();
            for ( int i = 0; i < CookZPlants_GetCropsCount(); i++ )
            {
                ItemBase item = ItemBase.Cast( g_Game.CreateObjectEx( CookZPlants_GetCropsType(), pos, ECE_PLACE_ON_SURFACE ) );
                item.SetQuantity( item.GetQuantityMax() );
            }
            // create some seeds when harvesting - cutting them out is imho too unrealistic
            ItemBase seeds = ItemBase.Cast( g_Game.CreateObjectEx( "CookZPlants_CabbageSeeds", pos, ECE_PLACE_ON_SURFACE ) );
            seeds.SetQuantity(3);
        }
        
        CookZPlants_SetHasCrops(false);

        SetSynchDirty();

        UpdatePlant();
        GetGarden().SyncSlots();
    }
};

class CookZPlants_PlantCucumber : CookZPlants_PlantBase
{
    void CookZPlants_PlantCucumber()
    {
        if (GetDayZGame().GetCookZPlants_Config())
        {
            m_FullMaturityTime = Math.Max(100, GetDayZGame().GetCookZPlants_Config().FullMaturityTimeCabbage);
        }
        else
        {
            // this can only happen on client if rpc config did not arrive yet, but server value counts anyway
            m_FullMaturityTime = 1350;
        }
    }
};