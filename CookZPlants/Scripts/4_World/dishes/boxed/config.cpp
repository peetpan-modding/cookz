class CfgPatches
{
    class CookZPlants_BoxedDishes
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

    class CookZ_Box_Base;
    class CookZ_BoxOpened_Base;

    // items

    class CookZPlants_PierogiBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PierogiBox_DN";
        descriptionShort="$STR_CookZPlants_PierogiBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\boxed\box_pierogi_co.paa"
        };
    };
    class CookZPlants_PierogiBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PierogiBox_DN";
        descriptionShort="$STR_CookZPlants_PierogiBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\boxed\box_pierogi_co.paa",
            "CookZPlants\data\dishes\boxed\box_food_pierogi_co.paa"
        };
        varQuantityInit=770;
        varQuantityMax=770;
        class Nutrition
        {
            energy=300;
            water=98.7013;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZPlants_CornDogBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_CornDogBox_DN";
        descriptionShort="$STR_CookZPlants_CornDogBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\boxed\box_corn_dog_co.paa"
        };
    };
    class CookZPlants_CornDogBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_CornDogBox_DN";
        descriptionShort="$STR_CookZPlants_CornDogBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\boxed\box_corn_dog_co.paa",
            "CookZPlants\data\dishes\boxed\box_food_corn_dog_co.paa"
        };
        varQuantityInit=1020;
        varQuantityMax=1020;
        class Nutrition
        {
            energy=287.745;
            water=111.275;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZPlants_PopcornSaltyBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PopcornSaltyBox_DN";
        descriptionShort="$STR_CookZPlants_PopcornSaltyBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\boxed\box_popcorn_salty_co.paa"
        };
    };
    class CookZPlants_PopcornSaltyBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PopcornSaltyBox_DN";
        descriptionShort="$STR_CookZPlants_PopcornSaltyBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\boxed\box_popcorn_salty_co.paa",
            "CookZPlants\data\dishes\boxed\box_food_popcorn_co.paa"
        };
        varQuantityInit=1050;
        varQuantityMax=1050;
        class Nutrition
        {
            energy=488.095;
            water=8.57143;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZPlants_PopcornSweetBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PopcornSweetBox_DN";
        descriptionShort="$STR_CookZPlants_PopcornSweetBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\boxed\box_popcorn_sweet_co.paa"
        };
    };
    class CookZPlants_PopcornSweetBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PopcornSweetBox_DN";
        descriptionShort="$STR_CookZPlants_PopcornSweetBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\boxed\box_popcorn_sweet_co.paa",
            "CookZPlants\data\dishes\boxed\box_food_popcorn_co.paa"
        };
        varQuantityInit=1450;
        varQuantityMax=1450;
        class Nutrition
        {
            energy=491.379;
            water=6.2069;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZPlants_KohlrouladenBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_KohlrouladenBox_DN";
        descriptionShort="$STR_CookZPlants_KohlrouladenBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\boxed\box_kohlrouladen_co.paa"
        };
    };
    class CookZPlants_KohlrouladenBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_KohlrouladenBox_DN";
        descriptionShort="$STR_CookZPlants_KohlrouladenBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\boxed\box_kohlrouladen_co.paa",
            "CookZPlants\data\dishes\boxed\box_food_kohlrouladen_co.paa"
        };
        varQuantityInit=1700;
        varQuantityMax=1700;
        class Nutrition
        {
            energy=214.706;
            water=85.8824;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };
};
