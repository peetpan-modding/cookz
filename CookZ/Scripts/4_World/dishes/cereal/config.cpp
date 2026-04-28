class CfgPatches
{
    class CookZ_Cereal
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

    class BoxCerealCrunchin;

    // bases

    class CookZ_CuteCereal_ColorBase : BoxCerealCrunchin
    {
        scope=0;
        itemSize[]={2,2};
        model="CookZ\data\dishes\cereal\cookz_cereal.p3d";
        hiddenSelections[]={"box"};
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=80;
                    healthLevels[]=
                    {
                        {1,          {"CookZ\data\dishes\cereal\cereal.rvmat"}},
                        {0.69999999, {"CookZ\data\dishes\cereal\cereal.rvmat"}},
                        {0.5,        {"CookZ\data\dishes\cereal\cereal_damage.rvmat"}},
                        {0.30000001, {"CookZ\data\dishes\cereal\cereal_damage.rvmat"}},
                        {0,          {"CookZ\data\dishes\cereal\cereal_destruct.rvmat"}}
                    };
                };
            };
        };
    };

    // items

    class CookZ_CuteCereal_UwU : CookZ_CuteCereal_ColorBase
    {
        scope=2;
		displayName="$STR_CookZ_CuteCereal_UwU_DN";
		descriptionShort="$STR_CookZ_CuteCereal_UwU_DS";
        hiddenSelectionsTextures[]= {"CookZ\data\dishes\cereal\cereal_uwu_co.paa"};
        varQuantityInit=200;
		varQuantityMax=200;
        class Nutrition
        {
            energy=362.5;
            water=12;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_CuteCereal_Hellfire : CookZ_CuteCereal_ColorBase
    {
        scope=2;
		displayName="$STR_CookZ_CuteCereal_Hellfire_DN";
		descriptionShort="$STR_CookZ_CuteCereal_Hellfire_DS";
        hiddenSelectionsTextures[]= {"CookZ\data\dishes\cereal\cereal_hellfire_co.paa"};
        varQuantityInit=200;
		varQuantityMax=200;
        class Nutrition
        {
            energy=362.5;
            water=6;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_CuteCereal_GreenMountain : CookZ_CuteCereal_ColorBase
    {
        scope=2;
		displayName="$STR_CookZ_CuteCereal_GreenMountain_DN";
		descriptionShort="$STR_CookZ_CuteCereal_GreenMountain_DS";
        hiddenSelectionsTextures[]= {"CookZ\data\dishes\cereal\cereal_gm_co.paa"};
        varQuantityInit=250;
		varQuantityMax=250;
        class Nutrition
        {
            energy=325;
            water=12;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };
};