class CfgPatches
{
    class CookZPlants_CannedDishes
    {
        requiredAddons[] =
        {
            "DZ_Data"
        };
    };
};

class CfgVehicles
{
    // imports

    class SpaghettiCan;
    class SpaghettiCan_Opened;

    // items

    class CookZPlants_FagioliAllaBudCan: SpaghettiCan
    {
        scope=2;
        displayName="$STR_CookZPlants_FagioliAllaBudCan_DN";
        descriptionShort="$STR_CookZPlants_FagioliAllaBudCan_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\canned\canned_fagioli_alla_bud_co.paa"
        };
    };
    class CookZPlants_FagioliAllaBudCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="$STR_CookZPlants_FagioliAllaBudCan_DN";
        descriptionShort="$STR_CookZPlants_FagioliAllaBudCan_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\canned\canned_fagioli_alla_bud_co.paa"
        };
        varQuantityInit=900;
        varQuantityMax=900;
        class Nutrition
        {
            energy=238.889;
            water=24.4444;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZPlants_SweetCornCan: SpaghettiCan
    {
        scope=2;
        displayName="$STR_CookZPlants_SweetCornCan_DN";
        descriptionShort="$STR_CookZPlants_SweetCornCan_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\canned\canned_sweet_corn_co.paa"
        };
    };
    class CookZPlants_SweetCornCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="$STR_CookZPlants_SweetCornCan_DN";
        descriptionShort="$STR_CookZPlants_SweetCornCan_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\canned\canned_sweet_corn_co.paa"
        };
        varQuantityInit=600;
        varQuantityMax=600;
        class Nutrition
        {
            energy=200;
            water=119.667;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZPlants_PicklesCan: SpaghettiCan
    {
        scope=2;
        displayName="$STR_CookZPlants_PicklesCan_DN";
        descriptionShort="$STR_CookZPlants_PicklesCan_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\canned\canned_pickles_co.paa"
        };
    };
    class CookZPlants_PicklesCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="$STR_CookZPlants_PicklesCan_DN";
        descriptionShort="$STR_CookZPlants_PicklesCan_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\canned\canned_pickles_co.paa"
        };
        varQuantityInit=800;
        varQuantityMax=800;
        class Nutrition
        {
            energy=150;
            water=89.75;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZPlants_SauerkrautCan: SpaghettiCan
    {
        scope=2;
        displayName="$STR_CookZPlants_SauerkrautCan_DN";
        descriptionShort="$STR_CookZPlants_SauerkrautCan_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\canned\canned_sauerkraut_co.paa"
        };
    };
    class CookZPlants_SauerkrautCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="$STR_CookZPlants_SauerkrautCan_DN";
        descriptionShort="$STR_CookZPlants_SauerkrautCan_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\canned\canned_sauerkraut_co.paa"
        };
        varQuantityInit=1700;
        varQuantityMax=1700;
        class Nutrition
        {
            energy=176.471;
            water=85.2941;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };
};