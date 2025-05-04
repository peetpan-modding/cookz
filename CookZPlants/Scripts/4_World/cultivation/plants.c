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
        CookZPlants_DisableInfection(); // set before super call because already used in Init
        super.Init(garden_base, fertility, harvesting_efficiency, water);
    }
};

class CookZPlants_PlantWheat : CookZPlants_PlantBase
{
    void CookZPlants_PlantWheat()
    {
        m_FullMaturityTime = 1350;
    }
};

class CookZPlants_PlantChili : CookZPlants_PlantBase
{
    void CookZPlants_PlantChili()
    {
        m_FullMaturityTime = 1350;
    }
};

class CookZPlants_PlantCorn : CookZPlants_PlantBase
{
    void CookZPlants_PlantCorn()
    {
        m_FullMaturityTime = 1350;
    }
};

class CookZPlants_PlantOnion : CookZPlants_PlantBase
{
    void CookZPlants_PlantOnion()
    {
        m_FullMaturityTime = 1350;
    }
};

class CookZPlants_PlantSoyBean : CookZPlants_PlantBase
{
    void CookZPlants_PlantSoyBean()
    {
        m_FullMaturityTime = 1350;
    }
};
