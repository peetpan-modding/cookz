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
    class GreenBellPepper;

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
        model="\dz\gear\cultivation\tomato_seeds.p3d";
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

    class CookZPlants_WheatEars: Inventory_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_WheatEars_DN";
        descriptionShort="$STR_CookZPlants_WheatEars_DS";
        itemSize[]={2,1};
        rotationFlags=17;
        model="CookZPlants\data\plants\wheat\cookz_wheat_ears.p3d";
        weight=36.279999;
        soundImpactType="organic";
        canBeSplit=1;
        varQuantityInit=1;
        varQuantityMin=0;
        varQuantityMax=10;
        varQuantityDestroyOnMin=1;
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

    class CookZPlants_FlourBag: Edible_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_FlourBag_DN";
        descriptionShort="$STR_CookZPlants_FlourBag_DS";
        model="CookZPlants\data\ingredients\cookz_flour_bag.p3d";
        debug_ItemCategory=6;
        weight=60;
        itemSize[]={1,2};
        varQuantityInit=500;
        varQuantityMin=0;
        varQuantityMax=500;
        absorbency=0.89999998;
        rotationFlags=63;
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

    class CookZPlants_Dough: Inventory_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_Dough_DN";
        descriptionShort="$STR_CookZPlants_Dough_DS";
        itemSize[]={1,1};
        model="CookZPlants\data\ingredients\cookz_dough.p3d";
        hiddenSelections[]=
        {
            "dough"
        };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\ingredients\cookz_dough_co.paa"
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
        model="\dz\gear\cultivation\tomato_seeds.p3d";
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

    class CookZPlants_Chili: GreenBellPepper
    {
        scope=2;
        displayName="$STR_CookZPlants_Chili_DN";
        descriptionShort="$STR_CookZPlants_Chili_DS";
        containsSeedsType="Cultivation_CookZPlants_ChiliSeeds"; // unused?
        containsSeedsQuantity="10"; // unused?
        model="CookZPlants\data\plants\chili\cookz_chili.p3d";
        hiddenSelections[]=
        {
            "cs_raw"
        };
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
        model="\dz\gear\cultivation\tomato_seeds.p3d";
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

    class CookZPlants_Corn: GreenBellPepper
    {
        scope=2;
        displayName="$STR_CookZPlants_Corn_DN";
        descriptionShort="$STR_CookZPlants_Corn_DS";
        containsSeedsType="Cultivation_CookZPlants_CornSeeds"; // unused?
        containsSeedsQuantity="10"; // unused?
        model="CookZPlants\data\plants\corn\cookz_corn.p3d";
        hiddenSelections[]=
        {
            "cs_raw"
        };
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
    };
};