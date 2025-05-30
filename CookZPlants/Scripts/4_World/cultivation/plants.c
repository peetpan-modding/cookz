class CookZPlants_WheatSeedsPack extends SeedPackBase {}
class CookZPlants_ChiliSeedsPack extends SeedPackBase {}
class CookZPlants_CornSeedsPack extends SeedPackBase {}
class CookZPlants_OnionSeedsPack extends SeedPackBase {}
class CookZPlants_SoyBeanSeedsPack extends SeedPackBase {}

class CookZPlants_WheatSeeds : SeedBase {};
class CookZPlants_ChiliSeeds : SeedBase {};
class CookZPlants_CornSeeds : SeedBase {};
class CookZPlants_OnionSeeds : SeedBase {};
class CookZPlants_OnionSeed : SeedBase {};
class CookZPlants_SoyBeanSeeds : SeedBase {};

modded class PlantBase
{
    // needs to be directly in PlantBase as m_InfestationChance is private
    void CookZPlants_DisableInfection()
    {
         m_InfestationChance = 0;
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
};
