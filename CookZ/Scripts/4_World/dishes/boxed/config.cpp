class CfgPatches
{
    class CookZ {};
};

class CfgVehicles
{
    // imports

    class Edible_Base;

    // bases

    class CookZ_Box_Base: Edible_Base
    {
        scope=2;
		debug_ItemCategory=6;
		rotationFlags=32;
		itemSize[]={2,2};
		weight=265;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		isMeleeWeapon=1;
		model="CookZ\data\dishes\boxed\food_box.p3d";
        hiddenSelections[]=
		{
			"box"
		};
		soundImpactType="metal";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						{1,             {"CookZ\data\dishes\boxed\box.rvmat"}},
						{0.69999999,    {"CookZ\data\dishes\boxed\box.rvmat"}},
						{0.5,           {"CookZ\data\dishes\boxed\box_damage.rvmat"}},
						{0.30000001,    {"CookZ\data\dishes\boxed\box_damage.rvmat"}},
						{0,             {"CookZ\data\dishes\boxed\box_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="ammoboxUnpack_SoundSet";
					id=204;
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
    }

    class CookZ_BoxOpened_Base: Edible_Base
    {
        scope=2;
		debug_ItemCategory=6;
		itemSize[]={2,2};
		weight=265;
		varQuantityMin=0;
		isMeleeWeapon=1;
		model="CookZ\data\dishes\boxed\food_box_opened.p3d";
        hiddenSelections[]=
		{
			"box_opened",
            "food"
		};
		soundImpactType="metal";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						{1,             {"CookZ\data\dishes\boxed\box.rvmat"}},
						{0.69999999,    {"CookZ\data\dishes\boxed\box.rvmat"}},
						{0.5,           {"CookZ\data\dishes\boxed\box_damage.rvmat"}},
						{0.30000001,    {"CookZ\data\dishes\boxed\box_damage.rvmat"}},
						{0,             {"CookZ\data\dishes\boxed\box_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="ammoboxUnpack_SoundSet";
					id=204;
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
    }

    // items

    class CookZ_FriedPotatoesBox: CookZ_Box_Base
    {
        displayName="Fried Potatoes";
        descriptionShort="A nutritious and long-lasting box of fried potatoes. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_fried_potatoes_co.paa"
        };
    };
    class CookZ_FriedPotatoesBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Fried Potatoes";
        descriptionShort="A nutritious box of fried potatoes. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_fried_potatoes_co.paa",
            "CookZ\data\dishes\boxed\box_food_fried_potatoes_co.paa"
        };
        varQuantityInit=1000;
        varQuantityMax=1000;
    };

    class CookZ_StirFryBox: CookZ_Box_Base
    {
        displayName="Stir Fry";
        descriptionShort="A nutritious and long-lasting box of stir fry. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_stir_fry_co.paa"
        };
    };
    class CookZ_StirFryBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Stir Fry";
        descriptionShort="A nutritious box of stir fry. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_stir_fry_co.paa",
            "CookZ\data\dishes\boxed\box_food_stir_fry_co.paa"
        };
        varQuantityInit=850
        varQuantityMax=850
    };

    class CookZ_FishAndChipsBox: CookZ_Box_Base
    {
        displayName="Fish And Chips";
        descriptionShort="A nutritious and long-lasting box of fish and chips. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_fish_and_chips_co.paa"
        };
    };
    class CookZ_FishAndChipsBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Fish And Chips";
        descriptionShort="A nutritious box of fish and chips. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_fish_and_chips_co.paa",
            "CookZ\data\dishes\boxed\box_food_fish_and_chips_co.paa"
        };
        varQuantityInit=1100
        varQuantityMax=1100
    };
    
    class CookZ_RicePuddingBox: CookZ_Box_Base
    {
        displayName="Rice Pudding";
        descriptionShort="A nutritious and long-lasting box of rice pudding. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_rice_pudding_co.paa"
        };
    };
    class CookZ_RicePuddingBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Rice Pudding";
        descriptionShort="A nutritious box of rice pudding. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_rice_pudding_co.paa",
            "CookZ\data\dishes\boxed\box_food_rice_pudding_co.paa"
        };
        varQuantityInit=950
        varQuantityMax=950
    };

    class CookZ_MushroomRisottoBox: CookZ_Box_Base
    {
        displayName="Mushroom Risotto";
        descriptionShort="A nutritious and long-lasting box of mushroom risotto. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_mushroom_risotto_co.paa"
        };
    };
    class CookZ_MushroomRisottoBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Mushroom Risotto";
        descriptionShort="A nutritious box of mushroom risotto. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_mushroom_risotto_co.paa",
            "CookZ\data\dishes\boxed\box_food_mushroom_risotto_co.paa"
        };
        varQuantityInit=800
        varQuantityMax=800
    };

    class CookZ_PilafBox: CookZ_Box_Base
    {
        displayName="Pilaf";
        descriptionShort="A nutritious and long-lasting box of pilaf. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_pilaf_co.paa"
        };
    };
    class CookZ_PilafBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Pilaf";
        descriptionShort="A nutritious box of pilaf. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_pilaf_co.paa",
            "CookZ\data\dishes\boxed\box_food_pilaf_co.paa"
        };
        varQuantityInit=1000
        varQuantityMax=1000
    };

    class CookZ_GaghBox: CookZ_Box_Base
    {
        displayName="Gagh";
        descriptionShort="A nutritious and long-lasting box of gagh. Will last two to five years depending on storage conditions. Earth-Style: the worms are cooked.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_gagh_co.paa"
        };
    };
    class CookZ_GaghBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Gagh";
        descriptionShort="A nutritious box of gagh. Eat up before it spoils. Earth-Style: the worms are cooked.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_gagh_co.paa",
            "CookZ\data\dishes\boxed\box_food_gagh_co.paa"
        };
        varQuantityInit=800
        varQuantityMax=800
    };

    class CookZ_HaggisBox: CookZ_Box_Base
    {
        displayName="Haggis with Mashed Potatoes";
        descriptionShort="A nutritious and long-lasting box of haggis with mashed potatoes. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_haggis_co.paa"
        };
    };
    class CookZ_HaggisBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Haggis with Mashed Potatoes";
        descriptionShort="A nutritious box of haggis with mashed potatoes. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_haggis_co.paa",
            "CookZ\data\dishes\boxed\box_food_haggis_co.paa"
        };
        varQuantityInit=900
        varQuantityMax=900
    };

    class CookZ_StuffedPeppersBox: CookZ_Box_Base
    {
        displayName="Suffed Peppers";
        descriptionShort="A nutritious and long-lasting box of stuffed peppers. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_stuffed_peppers_co.paa"
        };
    };
    class CookZ_StuffedPeppersBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Suffed Peppers";
        descriptionShort="A nutritious box of stuffed peppers. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_stuffed_peppers_co.paa",
            "CookZ\data\dishes\boxed\box_food_stuffed_peppers_co.paa"
        };
        varQuantityInit=950
        varQuantityMax=950
    };

    class CookZ_PommdoenerBox: CookZ_Box_Base
    {
        displayName="Pommdoener";
        descriptionShort="A nutritious and long-lasting box of pommdoener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_pommdoener_co.paa"
        };
    };
    class CookZ_PommdoenerBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Pommdoener";
        descriptionShort="A nutritious box of pommdoener. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_pommdoener_co.paa",
            "CookZ\data\dishes\boxed\box_food_pommdoener_co.paa"
        };
        varQuantityInit=1100
        varQuantityMax=1100
    };

    class CookZ_BangersAndMashBox: CookZ_Box_Base
    {
        displayName="Bangers And Mash";
        descriptionShort="A nutritious and long-lasting box of bangers and mash. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_bangers_and_mash_co.paa"
        };
    };
    class CookZ_BangersAndMashBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Bangers And Mash";
        descriptionShort="A nutritious box of bangers and mash. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_bangers_and_mash_co.paa",
            "CookZ\data\dishes\boxed\box_food_bangers_and_mash_co.paa"
        };
        varQuantityInit=900
        varQuantityMax=900
    };

    class CookZ_CurrywurstBox: CookZ_Box_Base
    {
        displayName="Currywurst";
        descriptionShort="A nutritious and long-lasting box of currywurst. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_currywurst_co.paa"
        };
    };
    class CookZ_CurrywurstBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Currywurst";
        descriptionShort="A nutritious box of currywurst. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_currywurst_co.paa",
            "CookZ\data\dishes\boxed\box_food_currywurst_co.paa"
        };
        varQuantityInit=1000
        varQuantityMax=1000
    };
}