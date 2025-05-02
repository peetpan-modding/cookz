class CfgPatches
{
    class CookZPlants_Sausage
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

    class CookZ_Sausage_Base;

    // items

    class CookZPlants_Tofu_Sausage: CookZ_Sausage_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_Tofu_Sausage_DN";
        descriptionShort="$STR_CookZPlants_Tofu_Sausage_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\sausage\cookz_sausage_tofu_co.paa"
        };
        varQuantityInit=550;
        varQuantityMax=550;
        class Nutrition
        {
            energy=250;
            water=79.0909;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };
};