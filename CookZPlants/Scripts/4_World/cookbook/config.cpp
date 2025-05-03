class CfgPatches
{
    class CookZPlants_Cookbook {};
};

class CfgVehicles
{
    class CookZ_Recipes
    {
        // --- Boxed Food ---

        class CookZPlants_PierogiBox    // name needs to be name of dish to be created
        {
            allowPot = false;           // can pot be used for recipe?
            allowCauldron = false;      // can cauldron be used for recipe?
            allowPan = true;            // can pan be used for recipe?
            needsWater = false;         // is water needed? only makes sense if pot or cauldron is allowed
            needsEmptyCan = false;      // is an empty can needed
            needsEmptyBox = true;       // is an empty box needed
            doNotReplaceIngredients = false; // do not replace ingredients by dish (e.g. disenfecting rags)
            canBeOpened = true;         // does dish need to be opened before eating
            numDishes = 1;              // number of dishes that will be created
            ingredients[] = {
                "AnyMeat,1",            // <NAME>,<QUANITY>, name must be the food item name OR AnyMeat etc
                "Lard,1",
                "CookZPlants_Dough,2"
            };
        };

        class CookZPlants_CornDogBox
        {
            allowPan = true;
            needsEmptyBox = true;
            canBeOpened = true;
            numDishes = 1;
            ingredients[] = {
                "CookZPlants_CornDough,2",
                "Lard,1",
                "AnySausage,1"
            };
        };

        // --- Canned Food ---

        class CookZPlants_FagioliAllaBudCan
        {
            allowPot = true;
            allowCauldron = true;
            needsEmptyCan = true;
            canBeOpened = true;
            numDishes = 1;
            ingredients[] = {
                "BakedBeansCan_Opened,1",
                "Lard,1",
                "CookZPlants_Chili,1",
                "CookZPlants_Onion,1"
            };
        };

        class CookZPlants_SweetCornCan
        {
            allowPot = true;
            allowCauldron = true;
            needsEmptyCan = true;
            needsWater = true;
            canBeOpened = true;
            numDishes = 1;
            ingredients[] = {
                "CookZPlants_Corn,4"
            };
        };

        // --- Sausages ---

        class CookZPlants_Tofu_Sausage
        {
            allowPot = true;
            allowCauldron = true;
            numDishes = 2;
            ingredients[] = {
                "Guts,1",
                "CookZPlants_Tofu,1"
            };
        };

        // --- Tofu ---

        class CookZPlants_Tofu
        {
            allowPot = true;
            allowCauldron = true;
            needsWater = true;
            ingredients[] = {
                "Rag,1",
                "CookZPlants_SoyBeanPod,10"
            };
        };

        // --- Pizza ---

        class CookZPlants_MargheritaPizza
        {
            allowPan = true;
            needsEmptyBox = true;
            canBeOpened = true;
            ingredients[] = {
                "CookZPlants_Dough,2",
                "Tomato,2",
                "CookZ_Cheese,2"
            };
        };
        class CookZPlants_PepperoniPizza
        {
            allowPan = true;
            needsEmptyBox = true;
            canBeOpened = true;
            ingredients[] = {
                "CookZPlants_Dough,2",
                "Tomato,2",
                "CookZ_Cheese,1",
                "AnySausage,1"
            };
        };
        class CookZPlants_SeafoodPizza
        {
            allowPan = true;
            needsEmptyBox = true;
            canBeOpened = true;
            ingredients[] = {
                "CookZPlants_Dough,2",
                "Tomato,2",
                "CookZ_Cheese,1",
                "AnyFishFillet,2"
            };
        };
        class CookZPlants_VegetablePizza
        {
            allowPan = true;
            needsEmptyBox = true;
            canBeOpened = true;
            ingredients[] = {
                "CookZPlants_Dough,2",
                "Tomato,2",
                "CookZ_Cheese,1",
                "Zucchini,1",
                "GreenBellPepper,1"
            };
        };
        class CookZPlants_MushroomPizza
        {
            allowPan = true;
            needsEmptyBox = true;
            canBeOpened = true;
            ingredients[] = {
                "CookZPlants_Dough,2",
                "Tomato,2",
                "CookZ_Cheese,1",
                "AnyMushroom,3"
            };
        };
    };
};
