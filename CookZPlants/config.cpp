class CfgPatches
{
    class CookZPlants
    {
        requiredAddons[] =
        {
            "DZ_Data", "DZ_Gear_Cultivation", "DZ_Gear_Food", "CookZ"
        };
    };
};

class CfgMods
{
    class CookZPlants
    {
        type = "mod";
        dependencies[] =
        {
            "Game", "World", "Mission"
        };
        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = {"CookZPlants/Scripts/3_Game"};
            };
            class worldScriptModule
            {
                value = "";
                files[] = {"CookZPlants/Scripts/4_World"};
            };
            class missionScriptModule
            {
                value = "";
                files[] = {"CookZPlants/Scripts/5_Mission"};
            };
        };
    };
};

class FruitStageTransitions;

class CfgVehicles
{
    // imports

    class Edible_Base;
    class Inventory_Base;
    class SeedBase;
    class PlantBase;
    class FoodAnimationSources;

    class CookZ_Cookbook_Item: Inventory_Base
    {
        chapters[] += {
            "CookZPlants\data\cookbook\01_plant_dishes.html"
        };
        chapterIcons[] += {
            "CookZPlants/data/cookbook/icon_wheat.edds"
        };
    };

    // bases

    class CookZPlants_FoodStageable_Base: Edible_Base
    {
        scope=0;
        debug_ItemCategory=6;
        rotationFlags=12;
        weight=0;
        stackedUnit="g";
        varQuantityInit=150;
        varQuantityMin=0;
        varQuantityMax=150;
        quantityBar=1;
        varTemperatureFreezeTime=2376;
        varTemperatureThawTime=2376;
        varTemperatureMax=110;
        temperaturePerQuantityWeight=1;
        inventorySlot[]={ "Ingredient", "DirectCookingA", "DirectCookingB", "DirectCookingC", "SmokingA", "SmokingB", "SmokingC", "SmokingD", "Trap_Bait", "Trap_Bait_2" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=10;
                    healthLevels[]={{1, {}}, {0.69999999, {}}, {0.5, {}}, {0.30000001, {}}, {0, {}}};
                };
            };
        };
        class Trapping
        {
            baitTypes[]={3};
            baitTypeChances[]={0.69999999};
            resultQuantityBaseMod=0;
            resultQuantityDispersionMin=0;
            resultQuantityDispersionMax=0;
        };
        class AnimationSources: FoodAnimationSources {};
        soundImpactType="organic";
        class AnimEvents
        {
            class SoundWeapon
            {
                class openTunaCan
                { 
                    soundSet="openTunaCan_SoundSet";
                    id=204;
                };
                class pickUpItem
                {
                    soundSet="Zucchini_pickup_SoundSet";
                    id=797;
                };
                class Eating_TakeFood
                {
                    soundSet="Eating_TakeFood_Soundset";
                    id=889;
                };
                class Eating_BoxOpen
                {
                    soundSet="Eating_BoxOpen_Soundset";
                    id=893;
                };
                class Eating_BoxShake
                {
                    soundSet="Eating_BoxShake_Soundset";
                    id=894;
                };
                class Eating_BoxEnd
                {
                    soundSet="Eating_BoxEnd_Soundset";
                    id=895;
                };
            };
        };
    };

    class CookZPlants_SeedsPack_Base: Inventory_Base
    {
        scope=0;
        model="\dz\gear\cultivation\tomato_seeds_pack.p3d";
        hiddenSelections[]={"zbytek"};
        rotationFlags=17;
        quantityBar=1;
        itemSize[]={1,1};
        weight=30;
        spawnOffset=0;
        lootCategory="Materials";
        lootTag[]=
        {
            "Farm",
            "Kitchen",
            "Forester"
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=5;
                    healthLevels[]=
                    {
                        {1,             {"DZ\gear\cultivation\data\tomato_seeds.rvmat"}},
                        {0.69999999,    {"DZ\gear\cultivation\data\tomato_seeds.rvmat"}},
                        {0.5,           {"DZ\gear\cultivation\data\tomato_seeds_damage.rvmat"}},
                        {0.30000001,    {"DZ\gear\cultivation\data\tomato_seeds_damage.rvmat"}},
                        {0,             {"DZ\gear\cultivation\data\tomato_seeds_destruct.rvmat"}}
                    };
                };
            };
        };
        class UserActions
        {
            class EmptyPack
            {
                displayNameDefault="Empty the pack";
                displayName="Empty the pack";
                position="action";
                onlyForPlayer=1;
                radius=2;
                condition="true";
                statement="this callMethod ['EmptySeedPack', _person];";
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickup
                {
                    soundSet="seedpack_pickup_SoundSet";
                    id=797;
                };
            };
        };
    };

    class CookZPlants_Seeds_Base: SeedBase
    {
        scope=0;
        canBeSplit=1;
        varQuantityInit=20;
        varQuantityMin=0;
        varQuantityMax=20;
        model="CookZPlants\data\plants\seeds\cookz_seeds.p3d";
        hiddenSelections[]={"seeds"};
    };

    class CookZPlants_Seed_Base: SeedBase
    {
        scope=0;
        varQuantityInit=1;
        varQuantityMin=0;
        varQuantityMax=1;
        varTemperatureFreezeTime=2640;
        varTemperatureThawTime=2640;
        varTemperatureFreezePoint=-2;
        varTemperatureThawPoint=-2;
        varTemperatureMax=105;
        varTemperatureMin=-100;
        rotationFlags=12;
        weight=0;
        itemSize[]={2,1};
        stackedUnit="g";
        absorbency=0.2;
    };

    class CookZPlants_Plant_Base: PlantBase
    {
        scope=0;
        hiddenSelections[]=
        {
            "stick",
            "seed_package",
            "plantStage_01",
            "plantStage_02",
            "plantStage_03",
            "plantStage_04",
            "plantStage_04_crops",
            "plantStage_05",
            "plantStage_05_crops"
        };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\plants\cookz_stick_co.paa"
        };
    };

    class CookZPlants_FlourBag_Base: Edible_Base
    {
        scope=0;
        debug_ItemCategory=6;
        weight=60;
        itemSize[]={1,2};
        varQuantityInit=500;
        varQuantityMin=0;
        varQuantityMax=500;
        absorbency=0.89999998;
        rotationFlags=63;
        hiddenSelections[]= { "flour_bag" };
    };
    
    class CookZPlants_StackableIngredientBase: Inventory_Base
    {
        scope=0;
        soundImpactType="organic";
        canBeSplit=1;
        varQuantityInit=1;
        varQuantityMin=0;
        varQuantityMax=10;
        varQuantityDestroyOnMin=1;
        rotationFlags=17;
        weight=36.279999;
    };

    class CookZPlants_Dough_Base: Inventory_Base
    {
        scope=0;
        itemSize[]={1,1};
        model="CookZPlants\data\ingredients\cookz_dough.p3d";
        hiddenSelections[]=
        {
            "dough"
        };
        weight=160;
        cookz_staticQuantity=160;
        soundImpactType="organic";
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=120;
        class Nutrition
        {
            energy=300;
            water=200;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=40;
                    healthLevels[]=
                    {
                        {1, {"CookZPlants\data\ingredients\cookz_dough.rvmat"}},
                        {0.69999999, {"CookZPlants\data\ingredients\cookz_dough.rvmat"}},
                        {0.5, {"CookZPlants\data\ingredients\cookz_flour_bag_damage.rvmat"}},
                        {0.30000001, {"CookZPlants\data\ingredients\cookz_flour_bag_damage.rvmat"}},
                        {0, {"CookZPlants\data\ingredients\cookz_flour_bag_destruct.rvmat"}}
                    };
                };
            };
        };
    };
    
    // wheat

    class CookZPlants_WheatSeedsPack: CookZPlants_SeedsPack_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_WheatSeedsPack_DN";
        descriptionShort="$STR_CookZPlants_WheatSeedsPack_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\wheat\cookz_wheat_seeds_package_co.paa"};
        class Horticulture
        {
            ContainsSeedsType="CookZPlants_WheatSeeds";
            ContainsSeedsQuantity=10;
        };
    };

    class CookZPlants_WheatSeeds: CookZPlants_Seeds_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_WheatSeeds_DN";
        descriptionShort="$STR_CookZPlants_WheatSeeds_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\seeds\cookz_seeds_wheat_co.paa"};
        class Horticulture
        {
            PlantType="CookZPlants_PlantWheat";
        };
    };

    class CookZPlants_PlantWheat: CookZPlants_Plant_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PlantWheat_DN";
        descriptionShort="$STR_CookZPlants_PlantWheat_DS";
        model="CookZPlants\data\plants\wheat\cookz_wheat_plant.p3d";
        hiddenSelectionsTextures[]+=
        {
            "CookZPlants\data\plants\wheat\cookz_wheat_seeds_package_co.paa",
            "CookZPlants\data\plants\wheat\cookz_wheat_plant_co.paa",
            "CookZPlants\data\plants\wheat\cookz_wheat_plant_co.paa",
            "CookZPlants\data\plants\wheat\cookz_wheat_plant_co.paa",
            "CookZPlants\data\plants\wheat\cookz_wheat_plant_ripe_co.paa",
            "CookZPlants\data\plants\wheat\cookz_wheat_plant_ripe_co.paa",
            "CookZPlants\data\plants\wheat\cookz_wheat_plant_moldy_co.paa",
            "CookZPlants\data\plants\wheat\cookz_wheat_plant_moldy_co.paa"
        };
        class Horticulture
        {
            GrowthStagesCount=6;
            CropsCount=4;
            CropsType="CookZPlants_WheatEars";
        };
    };

    class CookZPlants_WheatEars: CookZPlants_StackableIngredientBase
    {
        scope=2;
        displayName="$STR_CookZPlants_WheatEars_DN";
        descriptionShort="$STR_CookZPlants_WheatEars_DS";
        itemSize[]={2,1};
        model="CookZPlants\data\plants\wheat\cookz_wheat_ears.p3d";
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=40;
                    healthLevels[]=
                    {
                        {1, {"CookZPlants\data\plants\wheat\cookz_wheat_ears.rvmat"}},
                        {0.69999999, {"CookZPlants\data\plants\wheat\cookz_wheat_ears.rvmat"}},
                        {0.5, {"CookZPlants\data\plants\wheat\cookz_wheat_ears_damage.rvmat"}},
                        {0.30000001, {"CookZPlants\data\plants\wheat\cookz_wheat_ears_damage.rvmat"}},
                        {0, {"CookZPlants\data\plants\wheat\cookz_wheat_ears_destruct.rvmat"}}
                    };
                };
            };
        };
    };

    class CookZPlants_MortarAndPestle: Inventory_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_MortarAndPestle_DN";
        descriptionShort="$STR_CookZPlants_MortarAndPestle_DS";
        itemSize[]={2,2};
        model="CookZPlants\data\tools\cookz_mortarpestle.p3d";
        hiddenSelections[]=
        {
            "mortarpestle"
        };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\tools\cookz_mortarpestle_co.paa"
        };
        rotationFlags=8;
        weight=1700;
        soundImpactType="metal";
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=500;
                    healthLevels[]=
                    {
                        {1, {"CookZPlants\data\tools\cookz_mortarpestle.rvmat"}},
                        {0.69999999, {"CookZPlants\data\tools\cookz_mortarpestle.rvmat"}},
                        {0.5, {"CookZPlants\data\tools\cookz_mortarpestle_damage.rvmat"}},
                        {0.30000001, {"CookZPlants\data\tools\cookz_mortarpestle_damage.rvmat"}},
                        {0, {"CookZPlants\data\tools\cookz_mortarpestle_destruct.rvmat"}}
                    };
                };
            };
        };
    };

    class CookZPlants_FlourBag: CookZPlants_FlourBag_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_FlourBag_DN";
        descriptionShort="$STR_CookZPlants_FlourBag_DS";
        model="CookZPlants\data\ingredients\cookz_flour_bag.p3d";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\ingredients\cookz_flour_bag_co.paa"
        };
        hiddenSelectionsMaterials[]=
        {
            "CookZPlants\data\ingredients\cookz_flour_bag.rvmat"
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=40;
                    healthLevels[]=
                    {
                        {1, {"CookZPlants\data\ingredients\cookz_flour_bag.rvmat"}},
                        {0.69999999, {"CookZPlants\data\ingredients\cookz_flour_bag.rvmat"}},
                        {0.5, {"CookZPlants\data\ingredients\cookz_flour_bag_damage.rvmat"}},
                        {0.30000001, {"CookZPlants\data\ingredients\cookz_flour_bag_damage.rvmat"}},
                        {0, {"CookZPlants\data\ingredients\cookz_flour_bag_destruct.rvmat"}}
                    };
                };
            };
        };
    };

    class CookZPlants_Dough: CookZPlants_Dough_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_Dough_DN";
        descriptionShort="$STR_CookZPlants_Dough_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\ingredients\cookz_dough_co.paa"
        };
    };

    // chili

    class CookZPlants_ChiliSeedsPack: CookZPlants_SeedsPack_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_ChiliSeedsPack_DN";
        descriptionShort="$STR_CookZPlants_ChiliSeedsPack_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\chili\cookz_chili_seeds_package_co.paa"};
        class Horticulture
        {
            ContainsSeedsType="CookZPlants_ChiliSeeds";
            ContainsSeedsQuantity=10;
        };
    };

    class CookZPlants_ChiliSeeds: CookZPlants_Seeds_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_ChiliSeeds_DN";
        descriptionShort="$STR_CookZPlants_ChiliSeeds_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\seeds\cookz_seeds_chili_co.paa"};
        class Horticulture
        {
            PlantType="CookZPlants_PlantChili";
        };
    };

    class CookZPlants_PlantChili: CookZPlants_Plant_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PlantChili_DN";
        descriptionShort="$STR_CookZPlants_PlantChili_DS";
        model="CookZPlants\data\plants\chili\cookz_chili_plant.p3d";
        hiddenSelectionsTextures[]+=
        {
            "CookZPlants\data\plants\chili\cookz_chili_seeds_package_co.paa",
            "CookZPlants\data\plants\chili\cookz_chili_plant_co.paa",
            "CookZPlants\data\plants\chili\cookz_chili_plant_co.paa",
            "CookZPlants\data\plants\chili\cookz_chili_plant_co.paa",
            "CookZPlants\data\plants\chili\cookz_chili_plant_ripe_co.paa",
            "CookZPlants\data\plants\chili\cookz_chili_plant_ripe_co.paa",
            "CookZPlants\data\plants\chili\cookz_chili_plant_moldy_co.paa",
            "CookZPlants\data\plants\chili\cookz_chili_plant_moldy_co.paa"
        };
        class Horticulture
        {
            GrowthStagesCount=6;
            CropsCount=4;
            CropsType="CookZPlants_Chili";
        };
    };

    class CookZPlants_Chili: CookZPlants_FoodStageable_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_Chili_DN";
        descriptionShort="$STR_CookZPlants_Chili_DS";
        containsSeedsType="Cultivation_CookZPlants_ChiliSeeds"; // unused?
        containsSeedsQuantity="10"; // unused?
        model="CookZPlants\data\plants\chili\cookz_chili.p3d";
        itemSize[]={1,2};
        hiddenSelections[]= { "cs_raw" };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\plants\chili\cookz_chili_raw_co.paa",
            "CookZPlants\data\plants\chili\cookz_chili_raw_co.paa",
            "CookZPlants\data\plants\chili\cookz_chili_raw_co.paa",
            "CookZPlants\data\plants\chili\cookz_chili_raw_co.paa",
            "CookZPlants\data\plants\chili\cookz_chili_raw_co.paa",
            "CookZPlants\data\plants\chili\cookz_chili_raw_co.paa"
        };
        hiddenSelectionsMaterials[]=
        {
            "CookZPlants\data\plants\chili\cookz_chili_raw.rvmat",
            "CookZPlants\data\plants\chili\cookz_chili_baked.rvmat",
            "CookZPlants\data\plants\chili\cookz_chili_boiled.rvmat",
            "CookZPlants\data\plants\chili\cookz_chili_dried.rvmat",
            "CookZPlants\data\plants\chili\cookz_chili_burned.rvmat",
            "CookZPlants\data\plants\chili\cookz_chili_rotten.rvmat"
        };
        class InventorySlotsOffsets
        {
            class Ingredient
            {
                position[]={0.01,0.0,0.075};
                orientation[]={0,90,0};
            };
            class DirectCookingA
            {
                position[]={0.01,0.0,0.0};
                orientation[]={110,0,90};
            };
            class DirectCookingB
            {
                position[]={0.01,0.0,0.0};
                orientation[]={110,0,90};
            };
            class DirectCookingC
            {
                position[]={0.01,0.0,0.0};
                orientation[]={110,0,90};
            };
        };
        class Food
        {
            class FoodStages
            {
                class Raw
                {
                    // selection / texture / material
                    visual_properties[]={0,0,0};
                    nutrition_properties[]={1,100,33,1,0};
                    cooking_properties[]={0,0};
                };
                class Baked
                {
                    visual_properties[]={0,1,1};
                    nutrition_properties[]={1,250,20,1,0};
                    cooking_properties[]={70,35};
                };
                class Boiled
                {
                    visual_properties[]={0,2,2};
                    nutrition_properties[]={1,200,53,1,0};
                    cooking_properties[]={105,45};
                };
                class Dried
                {
                    visual_properties[]={0,3,3};
                    nutrition_properties[]={1,200,7,1,0};
                    cooking_properties[]={70,30,80};
                };
                class Burned
                {
                    visual_properties[]={0,4,4};
                    nutrition_properties[]={5,100,0,1,0,16,1,3};
                    cooking_properties[]={100,20};
                };
                class Rotten
                {
                    visual_properties[]={0,5,5};
                    nutrition_properties[]={10,50,13,1,0,16,1,9};
                    cooking_properties[]={0,0};
                };
            };
            class FoodStageTransitions: FruitStageTransitions {};
        };
    };

    // corn

    class CookZPlants_CornSeedsPack: CookZPlants_SeedsPack_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_CornSeedsPack_DN";
        descriptionShort="$STR_CookZPlants_CornSeedsPack_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\corn\cookz_corn_seeds_package_co.paa"};
        class Horticulture
        {
            ContainsSeedsType="CookZPlants_CornSeeds";
            ContainsSeedsQuantity=10;
        };
    };

    class CookZPlants_CornSeeds: CookZPlants_Seeds_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_CornSeeds_DN";
        descriptionShort="$STR_CookZPlants_CornSeeds_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\seeds\cookz_seeds_corn_co.paa"};
        class Horticulture
        {
            PlantType="CookZPlants_PlantCorn";
        };
    };

    class CookZPlants_PlantCorn: CookZPlants_Plant_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PlantCorn_DN";
        descriptionShort="$STR_CookZPlants_PlantCorn_DS";
        model="CookZPlants\data\plants\corn\cookz_corn_plant.p3d";
        hiddenSelectionsTextures[]+=
        {
            "CookZPlants\data\plants\corn\cookz_corn_seeds_package_co.paa",
            "CookZPlants\data\plants\corn\cookz_corn_plant_co.paa",
            "CookZPlants\data\plants\corn\cookz_corn_plant_co.paa",
            "CookZPlants\data\plants\corn\cookz_corn_plant_co.paa",
            "CookZPlants\data\plants\corn\cookz_corn_plant_co.paa",
            "CookZPlants\data\plants\corn\cookz_corn_plant_co.paa",
            "CookZPlants\data\plants\corn\cookz_corn_plant_moldy_co.paa",
            "CookZPlants\data\plants\corn\cookz_corn_plant_moldy_co.paa"
        };
        class Horticulture
        {
            GrowthStagesCount=6;
            CropsCount=3;
            CropsType="CookZPlants_Corn";
        };
    };

    class CookZPlants_Corn: CookZPlants_FoodStageable_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_Corn_DN";
        descriptionShort="$STR_CookZPlants_Corn_DS";
        containsSeedsType="Cultivation_CookZPlants_CornSeeds"; // unused?
        containsSeedsQuantity="10"; // unused?
        model="CookZPlants\data\plants\corn\cookz_corn.p3d";
        itemSize[]={1,2};
        hiddenSelections[]= { "cs_raw" };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\plants\corn\cookz_corn_plant_co.paa",
            "CookZPlants\data\plants\corn\cookz_corn_plant_co.paa",
            "CookZPlants\data\plants\corn\cookz_corn_plant_co.paa",
            "CookZPlants\data\plants\corn\cookz_corn_plant_co.paa",
            "CookZPlants\data\plants\corn\cookz_corn_plant_co.paa",
            "CookZPlants\data\plants\corn\cookz_corn_plant_co.paa"
        };
        hiddenSelectionsMaterials[]=
        {
            "CookZPlants\data\plants\corn\cookz_corn_raw.rvmat",
            "CookZPlants\data\plants\corn\cookz_corn_baked.rvmat",
            "CookZPlants\data\plants\corn\cookz_corn_boiled.rvmat",
            "CookZPlants\data\plants\corn\cookz_corn_dried.rvmat",
            "CookZPlants\data\plants\corn\cookz_corn_burned.rvmat",
            "CookZPlants\data\plants\corn\cookz_corn_rotten.rvmat"
        };
        class InventorySlotsOffsets
        {
            class Ingredient
            {
                position[]={0.0,0.0,0.0};
                orientation[]={0,90,0};
            };
            class DirectCookingA
            {
                position[]={0.0,0.0,0.0};
                orientation[]={0,90,0};
            };
            class DirectCookingB
            {
                position[]={0.0,0.0,0.0};
                orientation[]={0,90,0};
            };
            class DirectCookingC
            {
                position[]={0.0,0.0,0.0};
                orientation[]={0,90,0};
            };
        };
        class Food
        {
            class FoodStages
            {
                class Raw
                {
                    // selection / texture / material
                    visual_properties[]={0,0,0};
                    // fullness / energy / water / nutritional index / toxicity / agents / digestibility / agents per digest
                    nutrition_properties[]={1,100,33,1,0};
                    cooking_properties[]={0,0};
                };
                class Baked
                {
                    visual_properties[]={0,1,1};
                    nutrition_properties[]={1,250,20,1,0};
                    cooking_properties[]={70,35};
                };
                class Boiled
                {
                    visual_properties[]={0,2,2};
                    nutrition_properties[]={1,200,53,1,0};
                    cooking_properties[]={105,45};
                };
                class Dried
                {
                    visual_properties[]={0,3,3};
                    nutrition_properties[]={1,200,7,1,0};
                    cooking_properties[]={70,30,80};
                };
                class Burned
                {
                    visual_properties[]={0,4,4};
                    nutrition_properties[]={5,100,0,1,0,16,1,3};
                    cooking_properties[]={100,20};
                };
                class Rotten
                {
                    visual_properties[]={0,5,5};
                    nutrition_properties[]={10,50,13,1,0,16,1,9};
                    cooking_properties[]={0,0};
                };
            };
            class FoodStageTransitions: FruitStageTransitions {};
        };
    };

    class CookZPlants_CornFlourBag: CookZPlants_FlourBag_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_CornFlourBag_DN";
        descriptionShort="$STR_CookZPlants_CornFlourBag_DS";
        model="CookZPlants\data\ingredients\cookz_flour_bag.p3d";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\ingredients\cookz_cornflour_bag_co.paa"
        };
        hiddenSelectionsMaterials[]=
        {
            "CookZPlants\data\ingredients\cookz_cornflour_bag.rvmat"
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=40;
                    healthLevels[]=
                    {
                        {1, {
                            // first one needs to be rvmat linked in .p3d
                            "CookZPlants\data\ingredients\cookz_flour_bag.rvmat",
                            "CookZPlants\data\ingredients\cookz_cornflour_bag.rvmat"
                        }},
                        {0.69999999, {"CookZPlants\data\ingredients\cookz_cornflour_bag.rvmat"}},
                        {0.5, {"CookZPlants\data\ingredients\cookz_cornflour_bag_damage.rvmat"}},
                        {0.30000001, {"CookZPlants\data\ingredients\cookz_cornflour_bag_damage.rvmat"}},
                        {0, {"CookZPlants\data\ingredients\cookz_cornflour_bag_destruct.rvmat"}}
                    };
                };
            };
        };
    };

    class CookZPlants_CornDough: CookZPlants_Dough_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_CornDough_DN";
        descriptionShort="$STR_CookZPlants_CornDough_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\ingredients\cookz_corn_dough_co.paa"
        };
    };

    // onion

    class CookZPlants_OnionSeedsPack: CookZPlants_SeedsPack_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_OnionSeedsPack_DN";
        descriptionShort="$STR_CookZPlants_OnionSeedsPack_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\onion\cookz_onion_seeds_package_co.paa"};
        class Horticulture
        {
            ContainsSeedsType="CookZPlants_OnionSeeds";
            ContainsSeedsQuantity=10;
        };
    };

    class CookZPlants_OnionSeeds: CookZPlants_Seeds_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_OnionSeeds_DN";
        descriptionShort="$STR_CookZPlants_OnionSeeds_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\seeds\cookz_seeds_onion_co.paa"};
        class Horticulture
        {
            PlantType="CookZPlants_PlantOnion";
        };
    };

    class CookZPlants_OnionSeed: CookZPlants_Seed_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_OnionSeed_DN";
        descriptionShort="$STR_CookZPlants_OnionSeed_DS";
        model="CookZPlants\data\plants\onion\cookz_onion_seed.p3d";
        itemSize[]={1,1};
        hiddenSelections[]= { "skin" };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\plants\onion\cookz_onion_seed_co.paa",
        };
        hiddenSelectionsMaterials[]=
        {
            "CookZPlants\data\plants\onion\cookz_onion_seed.rvmat",
        };
        class Horticulture
        {
            PlantType="CookZPlants_PlantOnion";
        };
    };

    class CookZPlants_PlantOnion: CookZPlants_Plant_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PlantOnion_DN";
        descriptionShort="$STR_CookZPlants_PlantOnion_DS";
        model="CookZPlants\data\plants\onion\cookz_onion_plant.p3d";
        hiddenSelectionsTextures[]+=
        {
            "CookZPlants\data\plants\onion\cookz_onion_seeds_package_co.paa",
            "CookZPlants\data\plants\onion\cookz_onion_plant_co.paa",
            "CookZPlants\data\plants\onion\cookz_onion_plant_co.paa",
            "CookZPlants\data\plants\onion\cookz_onion_plant_co.paa",
            "CookZPlants\data\plants\onion\cookz_onion_plant_co.paa",
            "CookZPlants\data\plants\onion\cookz_onion_plant_co.paa",
            "CookZPlants\data\plants\onion\cookz_onion_plant_moldy_co.paa",
            "CookZPlants\data\plants\onion\cookz_onion_plant_moldy_co.paa"
        };
        class Horticulture
        {
            GrowthStagesCount=6;
            CropsCount=3;
            CropsType="CookZPlants_OnionSeed";
        };
    };

    class CookZPlants_Onion: CookZPlants_FoodStageable_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_Onion_DN";
        descriptionShort="$STR_CookZPlants_Onion_DS";
        model="CookZPlants\data\plants\onion\cookz_onion.p3d";
        itemSize[]={1,1};
        hiddenSelections[]= { "cs_raw" };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\plants\onion\cookz_onion_co.paa",
            "CookZPlants\data\plants\onion\cookz_onion_co.paa",
            "CookZPlants\data\plants\onion\cookz_onion_co.paa",
            "CookZPlants\data\plants\onion\cookz_onion_co.paa",
            "CookZPlants\data\plants\onion\cookz_onion_co.paa",
            "CookZPlants\data\plants\onion\cookz_onion_co.paa"
        };
        hiddenSelectionsMaterials[]=
        {
            "CookZPlants\data\plants\onion\cookz_onion_raw.rvmat",
            "CookZPlants\data\plants\onion\cookz_onion_baked.rvmat",
            "CookZPlants\data\plants\onion\cookz_onion_boiled.rvmat",
            "CookZPlants\data\plants\onion\cookz_onion_dried.rvmat",
            "CookZPlants\data\plants\onion\cookz_onion_burned.rvmat",
            "CookZPlants\data\plants\onion\cookz_onion_rotten.rvmat"
        };
        class InventorySlotsOffsets
        {
            class Ingredient
            {
                position[]={0.0,-0.05,0.01};
                orientation[]={0,0,0};
            };
            class DirectCookingA
            {
                position[]={0.0,-0.01,0.0};
                orientation[]={0,0,0};
            };
            class DirectCookingB
            {
                position[]={0.0,-0.01,0.0};
                orientation[]={0,0,0};
            };
            class DirectCookingC
            {
                position[]={0.0,-0.01,0.0};
                orientation[]={0,0,0};
            };
        };
        class Food
        {
            class FoodStages
            {
                class Raw
                {
                    // selection / texture / material
                    visual_properties[]={0,0,0};
                    nutrition_properties[]={1,100,33,1,0};
                    cooking_properties[]={0,0};
                };
                class Baked
                {
                    visual_properties[]={0,1,1};
                    nutrition_properties[]={1,250,20,1,0};
                    cooking_properties[]={70,35};
                };
                class Boiled
                {
                    visual_properties[]={0,2,2};
                    nutrition_properties[]={1,200,53,1,0};
                    cooking_properties[]={105,45};
                };
                class Dried
                {
                    visual_properties[]={0,3,3};
                    nutrition_properties[]={1,200,7,1,0};
                    cooking_properties[]={70,30,80};
                };
                class Burned
                {
                    visual_properties[]={0,4,4};
                    nutrition_properties[]={5,100,0,1,0,16,1,3};
                    cooking_properties[]={100,20};
                };
                class Rotten
                {
                    visual_properties[]={0,5,5};
                    nutrition_properties[]={10,50,13,1,0,16,1,9};
                    cooking_properties[]={0,0};
                };
            };
            class FoodStageTransitions: FruitStageTransitions {};
        };
    };

    // soy bean

    class CookZPlants_SoyBeanSeedsPack: CookZPlants_SeedsPack_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_SoyBeanSeedsPack_DN";
        descriptionShort="$STR_CookZPlants_SoyBeanSeedsPack_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\soybean\cookz_soybean_seeds_package_co.paa"};
        class Horticulture
        {
            ContainsSeedsType="CookZPlants_SoyBeanSeeds";
            ContainsSeedsQuantity=10;
        };
    };

    class CookZPlants_SoyBeanSeeds: CookZPlants_Seeds_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_SoyBeanSeeds_DN";
        descriptionShort="$STR_CookZPlants_SoyBeanSeeds_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\seeds\cookz_seeds_soybean_co.paa"};
        class Horticulture
        {
            PlantType="CookZPlants_PlantSoyBean";
        };
    };

    class CookZPlants_PlantSoyBean: CookZPlants_Plant_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PlantSoyBean_DN";
        descriptionShort="$STR_CookZPlants_PlantSoyBean_DS";
        model="CookZPlants\data\plants\soybean\cookz_soybean_plant.p3d";
        hiddenSelectionsTextures[]+=
        {
            "CookZPlants\data\plants\soybean\cookz_soybean_seeds_package_co.paa",
            "CookZPlants\data\plants\soybean\cookz_soybean_plant_co.paa",
            "CookZPlants\data\plants\soybean\cookz_soybean_plant_co.paa",
            "CookZPlants\data\plants\soybean\cookz_soybean_plant_co.paa",
            "CookZPlants\data\plants\soybean\cookz_soybean_plant_ripe_co.paa",
            "CookZPlants\data\plants\soybean\cookz_soybean_plant_ripe_co.paa",
            "CookZPlants\data\plants\soybean\cookz_soybean_plant_moldy_co.paa",
            "CookZPlants\data\plants\soybean\cookz_soybean_plant_moldy_co.paa"
        };
        class Horticulture
        {
            GrowthStagesCount=6;
            CropsCount=4;
            CropsType="CookZPlants_SoyBeanPod";
        };
    };

    class CookZPlants_SoyBeanPod: CookZPlants_StackableIngredientBase
    {
        scope=2;
        displayName="$STR_CookZPlants_SoyBeanPod_DN";
        descriptionShort="$STR_CookZPlants_SoyBeanPod_DS";
        itemSize[]={1,2};
        model="CookZPlants\data\plants\soybean\cookz_soybean_pod.p3d";
        hiddenSelections[]= { "pod" };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\plants\soybean\cookz_soybean_pod_co.paa",
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=40;
                    healthLevels[]=
                    {
                        {1, {"CookZPlants\data\plants\soybean\cookz_soybean_pod.rvmat"}},
                        {0.69999999, {"CookZPlants\data\plants\soybean\cookz_soybean_pod.rvmat"}},
                        {0.5, {"CookZPlants\data\plants\soybean\cookz_soybean_pod_damage.rvmat"}},
                        {0.30000001, {"CookZPlants\data\plants\soybean\cookz_soybean_pod_damage.rvmat"}},
                        {0, {"CookZPlants\data\plants\soybean\cookz_soybean_pod_destruct.rvmat"}}
                    };
                };
            };
        };
    };

    class CookZPlants_Tofu: CookZPlants_FoodStageable_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_Tofu_DN";
        descriptionShort="$STR_CookZPlants_Tofu_DS";
        model="CookZPlants\data\ingredients\cookz_tofu.p3d";
        itemSize[]={2,1};
        hiddenSelections[]= { "cs_raw" };
        varQuantityInit=600;
        varQuantityMin=0;
        varQuantityMax=600;
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\ingredients\cookz_tofu_co.paa",
            "CookZPlants\data\ingredients\cookz_tofu_co.paa",
            "CookZPlants\data\ingredients\cookz_tofu_co.paa",
            "CookZPlants\data\ingredients\cookz_tofu_co.paa",
            "CookZPlants\data\ingredients\cookz_tofu_co.paa",
            "CookZPlants\data\ingredients\cookz_tofu_co.paa"
        };
        hiddenSelectionsMaterials[]=
        {
            "CookZPlants\data\ingredients\cookz_tofu_raw.rvmat",
            "CookZPlants\data\ingredients\cookz_tofu_baked.rvmat",
            "CookZPlants\data\ingredients\cookz_tofu_boiled.rvmat",
            "CookZPlants\data\ingredients\cookz_tofu_dried.rvmat",
            "CookZPlants\data\ingredients\cookz_tofu_burned.rvmat",
            "CookZPlants\data\ingredients\cookz_tofu_rotten.rvmat"
        };
        class InventorySlotsOffsets
        {
            class Ingredient
            {
                position[]={0.0,0.0,-0.03};
                orientation[]={90,0,-90};
            };
            class DirectCookingA
            {
                position[]={0.0,0.035,-0.03};
                orientation[]={90,0,-90};
            };
            class DirectCookingB
            {
                position[]={0.0,0.035,-0.03};
                orientation[]={90,0,-90};
            };
            class DirectCookingC
            {
                position[]={0.0,0.035,-0.03};
                orientation[]={90,0,-90};
            };
        };
        class Food
        {
            class FoodStages
            {
                class Raw
                {
                    // selection / texture / material
                    visual_properties[]={0,0,0};
                    // fullness / energy / water / nutritional index / toxicity / agents / digestibility / agents per digest
                    nutrition_properties[]={1,100,33,1,0};
                    cooking_properties[]={0,0};
                };
                class Baked
                {
                    visual_properties[]={0,1,1};
                    nutrition_properties[]={1,250,20,1,0};
                    cooking_properties[]={70,35};
                };
                class Boiled
                {
                    visual_properties[]={0,2,2};
                    nutrition_properties[]={1,200,53,1,0};
                    cooking_properties[]={105,45};
                };
                class Dried
                {
                    visual_properties[]={0,3,3};
                    nutrition_properties[]={1,200,7,1,0};
                    cooking_properties[]={70,30,80};
                };
                class Burned
                {
                    visual_properties[]={0,4,4};
                    nutrition_properties[]={5,100,0,1,0,16,1,3};
                    cooking_properties[]={100,20};
                };
                class Rotten
                {
                    visual_properties[]={0,5,5};
                    nutrition_properties[]={10,50,13,1,0,16,1,9};
                    cooking_properties[]={0,0};
                };
            };
            class FoodStageTransitions: FruitStageTransitions {};
        };
    };

    // mushrooms

    class CookZPlants_MushroomSpawn : SeedBase
    {
        scope=2;
        displayName="$STR_CookZPlants_MushroomSpawn_DN";
        descriptionShort="$STR_CookZPlants_MushroomSpawn_DS";
        canBeSplit=1;
        varQuantityInit=3;
        varQuantityMin=0;
        varQuantityMax=3;
        weight=2000;
        itemSize[]={5,2};
        model="CookZPlants\data\plants\mushroom\cookz_mushroom_spawn.p3d";
        hiddenSelections[]={"spawn"};
        hiddenSelectionsTextures[]= {"CookZPlants\data\plants\mushroom\cookz_mushroom_spawn_co.paa"};
        class Horticulture
        {
            PlantType="CookZPlants_PlantMushroom";
        };
        // TODO correct damage rvmats? firewood does not have them ... it's a bug though
        class InventorySlotsOffsets
        {
            class SeedBase_1 { position[]={0.0,0.3,0.0}; orientation[]={-10,90,0}; };
            class SeedBase_2 { position[]={0.0,0.3,0.0}; orientation[]={-10,90,0}; };
            class SeedBase_3 { position[]={0.0,0.3,0.0}; orientation[]={-10,90,0}; };
            class SeedBase_4 { position[]={0.0,0.3,0.0}; orientation[]={-10,90,0}; };
            class SeedBase_5 { position[]={0.0,0.3,0.0}; orientation[]={-10,90,0}; };
            class SeedBase_6 { position[]={0.0,0.3,0.0}; orientation[]={-10,90,0}; };
            class SeedBase_7 { position[]={0.0,0.3,0.0}; orientation[]={-10,90,0}; };
            class SeedBase_8 { position[]={0.0,0.3,0.0}; orientation[]={-10,90,0}; };
            class SeedBase_9 { position[]={0.0,0.3,0.0}; orientation[]={-10,90,0}; };
            class SeedBase_10 { position[]={0.0,0.3,0.0}; orientation[]={-10,90,0}; };
            class SeedBase_11 { position[]={0.0,0.3,0.0}; orientation[]={-10,90,0}; };
            class SeedBase_12 { position[]={0.0,0.3,0.0}; orientation[]={-10,90,0}; };
            class SeedBase_13 { position[]={0.0,0.3,0.0}; orientation[]={-10,90,0}; };
        };
    };

    // see CookZPlants_PlantMushroom.Horticulture.CropsType
    class CookZPlants_DummyMushroom : Edible_Base
    {
        // no scope, should not spawn
        displayName="$STR_CookZPlants_DummyMushroom_DN";
    }

    class CookZPlants_PlantMushroom: CookZPlants_Plant_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PlantMushroom_DN";
        descriptionShort="$STR_CookZPlants_PlantMushroom_DS";
        model="CookZPlants\data\plants\mushroom\cookz_mushroom_plant.p3d";
        hiddenSelections[]+={"spawn"};
        hiddenSelectionsTextures[]+=
        {
            "CookZPlants\data\plants\mushroom\cookz_mushroom_seeds_package_co.paa", // seeds package
            "CookZPlants\data\plants\mushroom\cookz_mushroom_plant_co.paa", // stage 1
            "CookZPlants\data\plants\mushroom\cookz_mushroom_plant_co.paa", // stage 2
            "CookZPlants\data\plants\mushroom\cookz_mushroom_plant_co.paa", // stage 3
            "CookZPlants\data\plants\mushroom\cookz_mushroom_plant_co.paa", // stage 4
            "CookZPlants\data\plants\mushroom\cookz_mushroom_plant_co.paa", // stage 4 crops
            "CookZPlants\data\plants\mushroom\cookz_mushroom_plant_moldy_co.paa", // stage 5
            "CookZPlants\data\plants\mushroom\cookz_mushroom_plant_moldy_co.paa", // stage 5 crops
            "CookZPlants\data\plants\mushroom\cookz_mushroom_spawn_co.paa" // spawn
        };
        class Horticulture
        {
            GrowthStagesCount=6;
            CropsCount=3;
            // just for displaying a name for harvest action
            // random mushrooms are created
            CropsType="CookZPlants_DummyMushroom";
        };
    };

    // sugar beet
    
    class CookZPlants_SugarBeetSeedsPack: CookZPlants_SeedsPack_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_SugarBeetSeedsPack_DN";
        descriptionShort="$STR_CookZPlants_SugarBeetSeedsPack_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\sugarbeet\cookz_sugarbeets_seeds_package_co.paa"};
        class Horticulture
        {
            ContainsSeedsType="CookZPlants_SugarBeetSeeds";
            ContainsSeedsQuantity=10;
        };
    };

    class CookZPlants_SugarBeetSeeds: CookZPlants_Seeds_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_SugarBeetSeeds_DN";
        descriptionShort="$STR_CookZPlants_SugarBeetSeeds_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\seeds\cookz_seeds_sugarbeet_co.paa"};
        class Horticulture
        {
            PlantType="CookZPlants_PlantSugarBeet";
        };
    };

    class CookZPlants_PlantSugarBeet: CookZPlants_Plant_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PlantSugarBeet_DN";
        descriptionShort="$STR_CookZPlants_PlantSugarBeet_DS";
        model="CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_plant.p3d";
        hiddenSelectionsTextures[]+=
        {
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeets_seeds_package_co.paa", // seeds package
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_plant_co.paa", // stage 1
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_plant_co.paa", // stage 2
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_plant_co.paa", // stage 3
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_plant_co.paa", // stage 4
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_plant_co.paa", // stage 4 crops
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_plant_moldy_co.paa", // stage 5
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_plant_moldy_co.paa", // stage 5 crops
        };
        class Horticulture
        {
            GrowthStagesCount=6;
            CropsCount=3;
            CropsType="CookZPlants_SugarBeet";
        };
    };

    class CookZPlants_SugarBeet: CookZPlants_FoodStageable_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_SugarBeet_DN";
        descriptionShort="$STR_CookZPlants_SugarBeet_DS";
        model="CookZPlants\data\plants\sugarbeet\cookz_sugarbeet.p3d";
        itemSize[]={1,2};
        hiddenSelections[]= { "cs_raw" };
        varQuantityInit=500;
        varQuantityMin=0;
        varQuantityMax=500;
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_raw_co.paa", // raw
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_baked_co.paa", // baked
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_boiled_co.paa", // boiled
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_dried_co.paa", // dried
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_burned_co.paa", // burned
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_rotten_co.paa"  // rotten
        };
        hiddenSelectionsMaterials[]=
        {
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_raw.rvmat", // raw
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_raw.rvmat", // baked
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_raw.rvmat", // boiled
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_raw.rvmat", // dried
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_raw.rvmat", // burned
            "CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_raw.rvmat"  // rotten
        };
        class InventorySlotsOffsets
        {
            class Ingredient
            {
                position[]={0.0,0.0,0.04};
                orientation[]={0,90,0};
            };
            class DirectCookingA
            {
                position[]={0.0,0.025,0.0};
                orientation[]={0,80,0};
            };
            class DirectCookingB
            {
                position[]={0.0,0.025,0.0};
                orientation[]={0,80,0};
            };
            class DirectCookingC
            {
                position[]={0.0,0.025,0.0};
                orientation[]={0,80,0};
            };
        };
        class Food
        {
            class FoodStages
            {
                class Raw
                {
                    // selection / texture / material
                    visual_properties[]={0,0,0};
                    // fullness / energy / water / nutritional index / toxicity / agents / digestibility / agents per digest
                    nutrition_properties[]={1,150,50,1,0};
                    cooking_properties[]={0,0};
                };
                class Baked
                {
                    visual_properties[]={0,1,1};
                    nutrition_properties[]={1,250,20,1,0};
                    cooking_properties[]={70,35};
                };
                class Boiled
                {
                    visual_properties[]={0,2,2};
                    nutrition_properties[]={1,200,70,1,0};
                    cooking_properties[]={105,45};
                };
                class Dried
                {
                    visual_properties[]={0,3,3};
                    nutrition_properties[]={1,200,7,1,0};
                    cooking_properties[]={70,30,80};
                };
                class Burned
                {
                    visual_properties[]={0,4,4};
                    nutrition_properties[]={5,100,0,1,0,16,1,3};
                    cooking_properties[]={100,20};
                };
                class Rotten
                {
                    visual_properties[]={0,5,5};
                    nutrition_properties[]={10,50,13,1,0,16,1,9};
                    cooking_properties[]={0,0};
                };
            };
            class FoodStageTransitions: FruitStageTransitions {};
        };
    };

    class CookZPlants_SugarBag: Edible_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_SugarBag_DN";
        descriptionShort="$STR_CookZPlants_SugarBag_DS";
        weight=400;
        itemSize[]={1,2};
        varQuantityInit=500;
        varQuantityMin=0;
        varQuantityMax=500;
        model="CookZPlants\data\ingredients\cookz_sugar_bag.p3d";
        hiddenSelections[]= { "sugar_bag" };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\ingredients\cookz_sugar_bag_co.paa"
        };
        class Nutrition
        {
            totalVolume=1;
            energy=400;
            water=0;
            nutritionalIndex=1;
            toxicity=0;
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=40;
                    healthLevels[]=
                    {
                        {1, {"CookZPlants\data\ingredients\cookz_sugar_bag.rvmat"}},
                        {0.69999999, {"CookZPlants\data\ingredients\cookz_sugar_bag.rvmat"}},
                        {0.5, {"CookZPlants\data\ingredients\cookz_sugar_bag_damage.rvmat"}},
                        {0.30000001, {"CookZPlants\data\ingredients\cookz_sugar_bag_damage.rvmat"}},
                        {0, {"CookZPlants\data\ingredients\cookz_sugar_bag_destruct.rvmat"}}
                    };
                };
            };
        };
        class InventorySlotsOffsets 
        {
            class DirectCookingA
            {
                position[]={0.0,0.025,0};
                orientation[]={0,0,0};
            };
            class DirectCookingB
            {
                position[]={0.0,0.05,0};
                orientation[]={0,0,0};
            };
            class DirectCookingC
            {
                position[]={0.0,0.075,0};
                orientation[]={0,0,0};
            };
        };
    };

    // sunflower

    class CookZPlants_SunflowerSeedsPack: CookZPlants_SeedsPack_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_SunflowerSeedsPack_DN";
        descriptionShort="$STR_CookZPlants_SunflowerSeedsPack_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\sunflower\cookz_sunflower_seeds_package_co.paa"};
        class Horticulture
        {
            ContainsSeedsType="CookZPlants_SunflowerSeeds";
            ContainsSeedsQuantity=10;
        };
    };

    class CookZPlants_SunflowerSeeds: CookZPlants_Seeds_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_SunflowerSeeds_DN";
        descriptionShort="$STR_CookZPlants_SunflowerSeeds_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\seeds\cookz_seeds_sunflower_co.paa"};
        class Horticulture
        {
            PlantType="CookZPlants_PlantSunflower";
        };
    };

    class CookZPlants_PlantSunflower: CookZPlants_Plant_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PlantSunflower_DN";
        descriptionShort="$STR_CookZPlants_PlantSunflower_DS";
        model="CookZPlants\data\plants\sunflower\cookz_sunflower_plant.p3d";
        hiddenSelectionsTextures[]+=
        {
            "CookZPlants\data\plants\sunflower\cookz_sunflower_seeds_package_co.paa", // seeds package
            "CookZPlants\data\plants\sunflower\cookz_sunflower_plant_co.paa", // stage 1
            "CookZPlants\data\plants\sunflower\cookz_sunflower_plant_co.paa", // stage 2
            "CookZPlants\data\plants\sunflower\cookz_sunflower_plant_co.paa", // stage 3
            "CookZPlants\data\plants\sunflower\cookz_sunflower_plant_co.paa", // stage 4
            "CookZPlants\data\plants\sunflower\cookz_sunflower_plant_co.paa", // stage 4 crops
            "CookZPlants\data\plants\sunflower\cookz_sunflower_plant_moldy_co.paa", // stage 5
            "CookZPlants\data\plants\sunflower\cookz_sunflower_plant_moldy_co.paa", // stage 5 crops
        };
        class Horticulture
        {
            GrowthStagesCount=6;
            CropsCount=3;
            CropsType="CookZPlants_SunflowerHead";
        };
    };

    class CookZPlants_SunflowerHead: CookZPlants_StackableIngredientBase
    {
        scope=2;
        displayName="$STR_CookZPlants_SunflowerHead_DN";
        descriptionShort="$STR_CookZPlants_SunflowerHead_DS";
        itemSize[]={2,2};
        rotationFlags = 32;
        varQuantityMax=5;
        model="CookZPlants\data\plants\sunflower\cookz_sunflower_head.p3d";
        hiddenSelections[]= { "head" };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\plants\sunflower\cookz_sunflower_head_co.paa",
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=40;
                    healthLevels[]=
                    {
                        {1, {"CookZPlants\data\plants\sunflower\cookz_sunflower_head.rvmat"}},
                        {0.69999999, {"CookZPlants\data\plants\sunflower\cookz_sunflower_head.rvmat"}},
                        {0.5, {"CookZPlants\data\plants\sunflower\cookz_sunflower_head_damage.rvmat"}},
                        {0.30000001, {"CookZPlants\data\plants\sunflower\cookz_sunflower_head_damage.rvmat"}},
                        {0, {"CookZPlants\data\plants\sunflower\cookz_sunflower_head_destruct.rvmat"}}
                    };
                };
            };
        };
    };

    class CookZPlants_SunflowerOil: Edible_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_SunflowerOil_DN";
        descriptionShort="$STR_CookZPlants_SunflowerOil_DS";
        itemSize[]={1,2};
        weight=500;
        varTemperatureFreezePoint=-200;
        varTemperatureThawPoint=-200;
        varTemperatureFreezeTime=1980;
        varTemperatureThawTime=1980;
        varTemperatureMax=110;
        varQuantityInit=500;
        varQuantityMin=0;
        varQuantityMax=500;
        temperaturePerQuantityWeight=1;
        model="CookZPlants\data\ingredients\cookz_sunflower_oil.p3d";
        hiddenSelections[]={"bottle"};
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\ingredients\cookz_sunflower_oil_co.paa",
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=50;
                    healthLevels[]=
                    {
                        {1, {"CookZPlants\data\ingredients\cookz_sunflower_oil.rvmat"}},
                        {0.69999999, {"CookZPlants\data\ingredients\cookz_sunflower_oil.rvmat"}},
                        {0.5, {"CookZPlants\data\ingredients\cookz_sunflower_oil_damage.rvmat"}},
                        {0.30000001, {"CookZPlants\data\ingredients\cookz_sunflower_oil_damage.rvmat"}},
                        {0, {"CookZPlants\data\ingredients\cookz_sunflower_oil_destruct.rvmat"}}
                    };
                };
            };
        };
        soundImpactType="metal";
        class Nutrition
        {
            totalVolume=1;
            energy=800;
            water=0;
            nutritionalIndex=1;
            toxicity=0;
        };
        class InventorySlotsOffsets 
        {
            class DirectCookingA
            {
                position[]={0.0,0.075,0};
                orientation[]={0,0,0};
            };
            class DirectCookingB
            {
                position[]={0.0,0.075,0};
                orientation[]={0,0,0};
            };
            class DirectCookingC
            {
                position[]={0.0,0.075,0};
                orientation[]={0,0,0};
            };
        };
    };

    // cabbage

    class CookZPlants_CabbageSeedsPack: CookZPlants_SeedsPack_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_CabbageSeedsPack_DN";
        descriptionShort="$STR_CookZPlants_CabbageSeedsPack_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\cabbage\cookz_cabbage_seeds_package_co.paa"};
        class Horticulture
        {
            ContainsSeedsType="CookZPlants_CabbageSeeds";
            ContainsSeedsQuantity=10;
        };
    };

    class CookZPlants_CabbageSeeds: CookZPlants_Seeds_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_CabbageSeeds_DN";
        descriptionShort="$STR_CookZPlants_CabbageSeeds_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\seeds\cookz_seeds_cabbage_co.paa"};
        class Horticulture
        {
            PlantType="CookZPlants_PlantCabbage";
        };
    };

    class CookZPlants_PlantCabbage: CookZPlants_Plant_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PlantCabbage_DN";
        descriptionShort="$STR_CookZPlants_PlantCabbage_DS";
        model="CookZPlants\data\plants\cabbage\cookz_cabbage_plant.p3d";
        hiddenSelectionsTextures[]+=
        {
            "CookZPlants\data\plants\cabbage\cookz_cabbage_seeds_package_co.paa", // seeds package
            "CookZPlants\data\plants\cabbage\cookz_cabbage_plant_co.paa", // stage 1
            "CookZPlants\data\plants\cabbage\cookz_cabbage_plant_co.paa", // stage 2
            "CookZPlants\data\plants\cabbage\cookz_cabbage_plant_co.paa", // stage 3
            "CookZPlants\data\plants\cabbage\cookz_cabbage_plant_co.paa", // stage 4
            "CookZPlants\data\plants\cabbage\cookz_cabbage_plant_co.paa", // stage 4 crops
            "CookZPlants\data\plants\cabbage\cookz_cabbage_plant_moldy_co.paa", // stage 5
            "CookZPlants\data\plants\cabbage\cookz_cabbage_plant_moldy_co.paa", // stage 5 crops
        };
        class Horticulture
        {
            GrowthStagesCount=6;
            CropsCount=1;
            CropsType="CookZPlants_CabbageHead";
        };
    };

    class CookZPlants_CabbageHead: Inventory_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_CabbageHead_DN";
        descriptionShort="$STR_CookZPlants_CabbageHead_DS";
        itemSize[]={2,2};
        rotationFlags = 2;
        model="CookZPlants\data\plants\cabbage\cookz_cabbage_head.p3d";
        hiddenSelections[]= { "head" };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\plants\cabbage\cookz_cabbage_head_co.paa",
        };
        weight=2000;
        soundImpactType="organic";
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=120;
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=40;
                    healthLevels[]=
                    {
                        {1, {"CookZPlants\data\plants\cabbage\cookz_cabbage_head.rvmat"}},
                        {0.69999999, {"CookZPlants\data\plants\cabbage\cookz_cabbage_head.rvmat"}},
                        {0.5, {"CookZPlants\data\plants\cabbage\cookz_cabbage_head_damage.rvmat"}},
                        {0.30000001, {"CookZPlants\data\plants\cabbage\cookz_cabbage_head_damage.rvmat"}},
                        {0, {"CookZPlants\data\plants\cabbage\cookz_cabbage_head_destruct.rvmat"}}
                    };
                };
            };
        };
    };

    class CookZPlants_CabbageSlice: CookZPlants_FoodStageable_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_CabbageSlice_DN";
        descriptionShort="$STR_CookZPlants_CabbageSlice_DS";
        model="CookZPlants\data\plants\cabbage\cookz_cabbage_slice.p3d";
        itemSize[]={1,2};
        hiddenSelections[]= { "cs_raw" };
        varQuantityInit=500;
        varQuantityMin=0;
        varQuantityMax=500;
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\plants\cabbage\cookz_cabbage_head_co.paa", // raw
            "CookZPlants\data\plants\cabbage\cookz_cabbage_slice_baked_co.paa", // baked
            "CookZPlants\data\plants\cabbage\cookz_cabbage_slice_boiled_co.paa", // boiled
            "CookZPlants\data\plants\cabbage\cookz_cabbage_slice_dried_co.paa", // dried
            "CookZPlants\data\plants\cabbage\cookz_cabbage_slice_burned_co.paa", // burned
            "CookZPlants\data\plants\cabbage\cookz_cabbage_slice_rotten_co.paa"  // rotten
        };
        hiddenSelectionsMaterials[]=
        {
            "CookZPlants\data\plants\cabbage\cookz_cabbage_head.rvmat", // raw
            "CookZPlants\data\plants\cabbage\cookz_cabbage_head.rvmat", // baked
            "CookZPlants\data\plants\cabbage\cookz_cabbage_head.rvmat", // boiled
            "CookZPlants\data\plants\cabbage\cookz_cabbage_head.rvmat", // dried
            "CookZPlants\data\plants\cabbage\cookz_cabbage_head.rvmat", // burned
            "CookZPlants\data\plants\cabbage\cookz_cabbage_head.rvmat"  // rotten
        };
        class InventorySlotsOffsets
        {
            class Ingredient
            {
                position[]={0.0,0.0,0.04};
                orientation[]={0,90,0};
            };
            class DirectCookingA
            {
                position[]={0.0,0.025,0.0};
                orientation[]={90,0,90};
            };
            class DirectCookingB
            {
                position[]={0.0,0.025,0.0};
                orientation[]={90,0,90};
            };
            class DirectCookingC
            {
                position[]={0.0,0.025,0.0};
                orientation[]={90,0,90};
            };
        };
        class Food
        {
            class FoodStages
            {
                class Raw
                {
                    // selection / texture / material
                    visual_properties[]={0,0,0};
                    // fullness / energy / water / nutritional index / toxicity / agents / digestibility / agents per digest
                    nutrition_properties[]={1,150,50,1,0};
                    cooking_properties[]={0,0};
                };
                class Baked
                {
                    visual_properties[]={0,1,1};
                    nutrition_properties[]={1,250,20,1,0};
                    cooking_properties[]={70,35};
                };
                class Boiled
                {
                    visual_properties[]={0,2,2};
                    nutrition_properties[]={1,200,70,1,0};
                    cooking_properties[]={105,45};
                };
                class Dried
                {
                    visual_properties[]={0,3,3};
                    nutrition_properties[]={1,200,7,1,0};
                    cooking_properties[]={70,30,80};
                };
                class Burned
                {
                    visual_properties[]={0,4,4};
                    nutrition_properties[]={5,100,0,1,0,16,1,3};
                    cooking_properties[]={100,20};
                };
                class Rotten
                {
                    visual_properties[]={0,5,5};
                    nutrition_properties[]={10,50,13,1,0,16,1,9};
                    cooking_properties[]={0,0};
                };
            };
            class FoodStageTransitions: FruitStageTransitions {};
        };
    };

    // cucumber

    class CookZPlants_CucumberSeedsPack: CookZPlants_SeedsPack_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_CucumberSeedsPack_DN";
        descriptionShort="$STR_CookZPlants_CucumberSeedsPack_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\cucumber\cookz_cucumber_seeds_package_co.paa"};
        class Horticulture
        {
            ContainsSeedsType="CookZPlants_CucumberSeeds";
            ContainsSeedsQuantity=10;
        };
    };

    class CookZPlants_CucumberSeeds: CookZPlants_Seeds_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_CucumberSeeds_DN";
        descriptionShort="$STR_CookZPlants_CucumberSeeds_DS";
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\seeds\cookz_seeds_cucumber_co.paa"};
        class Horticulture
        {
            PlantType="CookZPlants_PlantCucumber";
        };
    };

    class CookZPlants_PlantCucumber: CookZPlants_Plant_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PlantCucumber_DN";
        descriptionShort="$STR_CookZPlants_PlantCucumber_DS";
        model="CookZPlants\data\plants\cucumber\cookz_cucumber_plant.p3d";
        hiddenSelections[]+={"rack"};
        hiddenSelectionsTextures[]+=
        {
            "CookZPlants\data\plants\cucumber\cookz_cucumber_seeds_package_co.paa", // seeds package
            "CookZPlants\data\plants\cucumber\cookz_cucumber_plant_co.paa", // stage 1
            "CookZPlants\data\plants\cucumber\cookz_cucumber_plant_co.paa", // stage 2
            "CookZPlants\data\plants\cucumber\cookz_cucumber_plant_co.paa", // stage 3
            "CookZPlants\data\plants\cucumber\cookz_cucumber_plant_co.paa", // stage 4
            "CookZPlants\data\plants\cucumber\cookz_cucumber_plant_co.paa", // stage 4 crops
            "CookZPlants\data\plants\cucumber\cookz_cucumber_plant_moldy_co.paa", // stage 5
            "CookZPlants\data\plants\cucumber\cookz_cucumber_plant_moldy_co.paa", // stage 5 crops
            "CookZPlants\data\plants\cucumber\cookz_cucumber_plant_rack_co.paa" // rack
        };
        class Horticulture
        {
            GrowthStagesCount=6;
            CropsCount=5;
            CropsType="CookZPlants_Cucumber";
        };
    };

    class CookZPlants_Cucumber: CookZPlants_FoodStageable_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_Cucumber_DN";
        descriptionShort="$STR_CookZPlants_Cucumber_DS";
        model="CookZPlants\data\plants\cucumber\cookz_cucumber.p3d";
        itemSize[]={1,2};
        hiddenSelections[]= { "cs_raw" };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\plants\cucumber\cookz_cucumber_raw_co.paa", // raw
            "CookZPlants\data\plants\cucumber\cookz_cucumber_baked_co.paa", // baked
            "CookZPlants\data\plants\cucumber\cookz_cucumber_boiled_co.paa", // boiled
            "CookZPlants\data\plants\cucumber\cookz_cucumber_dried_co.paa", // dried
            "CookZPlants\data\plants\cucumber\cookz_cucumber_burned_co.paa", // burned
            "CookZPlants\data\plants\cucumber\cookz_cucumber_rotten_co.paa"  // rotten
        };
        hiddenSelectionsMaterials[]=
        {
            "CookZPlants\data\plants\cucumber\cookz_cucumber.rvmat",    // raw
            "CookZPlants\data\plants\cucumber\cookz_cucumber.rvmat",    // baked
            "CookZPlants\data\plants\cucumber\cookz_cucumber.rvmat",    // boiled
            "CookZPlants\data\plants\cucumber\cookz_cucumber.rvmat",    // dried
            "CookZPlants\data\plants\cucumber\cookz_cucumber.rvmat",    // burned
            "CookZPlants\data\plants\cucumber\cookz_cucumber.rvmat"     // rotten
        };
        class InventorySlotsOffsets
        {
            class Ingredient
            {
                position[]={0.01,0.0,0.075};
                orientation[]={0,90,0};
            };
            class DirectCookingA
            {
                position[]={0.01,0.0,0.0};
                orientation[]={110,0,90};
            };
            class DirectCookingB
            {
                position[]={0.01,0.0,0.0};
                orientation[]={110,0,90};
            };
            class DirectCookingC
            {
                position[]={0.01,0.0,0.0};
                orientation[]={110,0,90};
            };
        };
        class Food
        {
            class FoodStages
            {
                class Raw
                {
                    // selection / texture / material
                    visual_properties[]={0,0,0};
                    nutrition_properties[]={1,100,33,1,0};
                    cooking_properties[]={0,0};
                };
                class Baked
                {
                    visual_properties[]={0,1,1};
                    nutrition_properties[]={1,250,20,1,0};
                    cooking_properties[]={70,35};
                };
                class Boiled
                {
                    visual_properties[]={0,2,2};
                    nutrition_properties[]={1,200,53,1,0};
                    cooking_properties[]={105,45};
                };
                class Dried
                {
                    visual_properties[]={0,3,3};
                    nutrition_properties[]={1,200,7,1,0};
                    cooking_properties[]={70,30,80};
                };
                class Burned
                {
                    visual_properties[]={0,4,4};
                    nutrition_properties[]={5,100,0,1,0,16,1,3};
                    cooking_properties[]={100,20};
                };
                class Rotten
                {
                    visual_properties[]={0,5,5};
                    nutrition_properties[]={10,50,13,1,0,16,1,9};
                    cooking_properties[]={0,0};
                };
            };
            class FoodStageTransitions: FruitStageTransitions {};
        };
    };
};

class CfgHorticulture
{
    class Plants
    {
        class CookZPlants_PlantWheat
        {
            infestedTex="";
            infestedMat="";
            healthyTex="CookZPlants\data\plants\wheat\cookz_wheat_plant_ripe_co.paa";
            healthyMat="CookZPlants\data\plants\wheat\cookz_wheat_plant.rvmat";
        };

        class CookZPlants_PlantChili
        {
            infestedTex="";
            infestedMat="";
            healthyTex="CookZPlants\data\plants\chili\cookz_chili_plant_co.paa";
            healthyMat="CookZPlants\data\plants\chili\cookz_chili_plant.rvmat";
        };

        class CookZPlants_PlantCorn
        {
            infestedTex="";
            infestedMat="";
            healthyTex="CookZPlants\data\plants\corn\cookz_corn_plant_co.paa";
            healthyMat="CookZPlants\data\plants\corn\cookz_corn_plant.rvmat";
        };

        class CookZPlants_PlantOnion
        {
            infestedTex="";
            infestedMat="";
            healthyTex="CookZPlants\data\plants\onion\cookz_onion_plant_co.paa";
            healthyMat="CookZPlants\data\plants\onion\cookz_onion_plant.rvmat";
        };

        class CookZPlants_PlantSoyBean
        {
            infestedTex="";
            infestedMat="";
            healthyTex="CookZPlants\data\plants\soybean\cookz_soybean_plant_co.paa";
            healthyMat="CookZPlants\data\plants\soybean\cookz_soybean_plant.rvmat";
        };

        class CookZPlants_PlantMushroom
        {
            infestedTex="";
            infestedMat="";
            healthyTex="CookZPlants\data\plants\mushroom\cookz_mushroom_plant_co.paa";
            healthyMat="CookZPlants\data\plants\mushroom\cookz_mushroom_plant.rvmat";
        };

        class CookZPlants_PlantSugarBeet
        {
            infestedTex="";
            infestedMat="";
            healthyTex="CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_plant_co.paa";
            healthyMat="CookZPlants\data\plants\sugarbeet\cookz_sugarbeet_plant.rvmat";
        };

        class CookZPlants_PlantSunflower
        {
            infestedTex="";
            infestedMat="";
            healthyTex="CookZPlants\data\plants\sunflower\cookz_sunflower_plant_co.paa";
            healthyMat="CookZPlants\data\plants\sunflower\cookz_sunflower_plant.rvmat";
        };

        class CookZPlants_PlantCabbage
        {
            infestedTex="";
            infestedMat="";
            healthyTex="CookZPlants\data\plants\cabbage\cookz_cabbage_plant_co.paa";
            healthyMat="CookZPlants\data\plants\cabbage\cookz_cabbage_plant.rvmat";
        };

        class CookZPlants_PlantCucumber
        {
            infestedTex="";
            infestedMat="";
            healthyTex="CookZPlants\data\plants\cucumber\cookz_cucumber_plant_co.paa";
            healthyMat="CookZPlants\data\plants\cucumber\cookz_cucumber_plant.rvmat";
        };
    };
};