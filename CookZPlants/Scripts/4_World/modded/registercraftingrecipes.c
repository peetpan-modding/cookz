modded class PluginRecipesManager
{
    override void RegisterRecipies()
    {
        super.RegisterRecipies();
        RegisterRecipe(new CookZ_CutOutWheatSeeds);
        RegisterRecipe(new CookZ_CutOutSoyBeanSeeds);
        RegisterRecipe(new CookZ_CutOutSunflowerSeeds);
        RegisterRecipe(new CookZ_CraftMortarAndPestle);
        RegisterRecipe(new CookZ_CraftFlour);
        RegisterRecipe(new CookZ_CraftCornFlour);
        RegisterRecipe(new CookZ_CraftDough);
        RegisterRecipe(new CookZ_CraftCornDough);
        RegisterRecipe(new PeelCookZPlants_Onion);
        RegisterRecipe(new CutOutCookZPlants_Chili);
        RegisterRecipe(new CutOutCookZPlants_Corn);
        RegisterRecipe(new CookZ_CraftMushroomSpawn);
    }
}

class CookZ_CutOutSplitableSeeds_Base extends RecipeBase
{
    override void Init()
    {
        m_Name = "#STR_cutoutseeds0";
        m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
        m_AnimationLength = 1;//animation length in relative time units
        m_Specialty = -0.01;// value > 0 for roughness, value < 0 for precision
        
        
        //conditions
        m_MinDamageIngredient[0] = -1;//-1 = disable check
        m_MaxDamageIngredient[0] = 3;//-1 = disable check
        
        m_MinQuantityIngredient[0] = -1;//-1 = disable check
        m_MaxQuantityIngredient[0] = -1;//-1 = disable check
        
        m_MinDamageIngredient[1] = -1;//-1 = disable check
        m_MaxDamageIngredient[1] = 3;//-1 = disable check
        
        m_MinQuantityIngredient[1] = -1;//-1 = disable check
        m_MaxQuantityIngredient[1] = -1;//-1 = disable check
        //----------------------------------------------------------------------------------------------------------------------
        
        //INGREDIENTS
        m_IngredientAddHealth[0] = 0;// 0 = do nothing
        m_IngredientSetHealth[0] = -1; // -1 = do nothing
        m_IngredientAddQuantity[0] = -1;// 0 = do nothing
        m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
        m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
        
        //ingredient 2
        InsertIngredient(1,"Sickle");//you can insert multiple ingredients this way
        InsertIngredient(1,"KukriKnife");
        InsertIngredient(1,"FangeKnife");
        InsertIngredient(1,"Hacksaw");
        InsertIngredient(1,"HandSaw");
        InsertIngredient(1,"KitchenKnife");
        InsertIngredient(1,"SteakKnife");
        InsertIngredient(1,"StoneKnife");
        InsertIngredient(1,"Cleaver");
        InsertIngredient(1,"CombatKnife");
        InsertIngredient(1,"HuntingKnife");
        InsertIngredient(1,"Machete");
        InsertIngredient(1,"CrudeMachete");
        InsertIngredient(1,"OrientalMachete");
        InsertIngredient(1,"WoodAxe");
        InsertIngredient(1,"Hatchet");
        InsertIngredient(1,"FirefighterAxe");
        InsertIngredient(1,"Sword");
        InsertIngredient(1,"AK_Bayonet");
        InsertIngredient(1,"M9A1_Bayonet");
        InsertIngredient(1,"Mosin_Bayonet");
        InsertIngredient(1,"SKS_Bayonet");
        InsertIngredient(1,"BoneKnife");
        
        m_IngredientAddHealth[1] = -5;// 0 = do nothing
        m_IngredientSetHealth[1] = -1; // -1 = do nothing
        m_IngredientAddQuantity[1] = 0;// 0 = do nothing
        m_IngredientDestroy[1] = false;// false = do nothing
        m_IngredientUseSoftSkills[1] = true;// set 'true' to allow modification of the values by softskills on this ingredient
        //----------------------------------------------------------------------------------------------------------------------
        
        //result1
        m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
        m_ResultSetQuantity[0] = 8;//-1 = do nothing
        m_ResultSetHealth[0] = -1;//-1 = do nothing
        m_ResultInheritsHealth[0] = 0;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
        m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
        m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
        m_ResultUseSoftSkills[0] = true;// set 'true' to allow modification of the values by softskills on this result
        m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
    }

    override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
    {
        return true;
    }

    // ToDo PP without this dayz throws an error when closing the client ... why?!
    override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
    {
        super.Do( ingredients, player, results, specialty_weight);
    }
}

class CookZ_CutOutWheatSeeds extends CookZ_CutOutSplitableSeeds_Base
{    
    override void Init()
    {
        super.Init();
        InsertIngredient(0,"CookZPlants_WheatEars");
        AddResult("CookZPlants_WheatSeeds");
    }
};

class CookZ_CutOutSoyBeanSeeds extends CookZ_CutOutSplitableSeeds_Base
{    
    override void Init()
    {
        super.Init();
        InsertIngredient(0,"CookZPlants_SoyBeanPod");
        AddResult("CookZPlants_SoyBeanSeeds");
    }
};

class CookZ_CutOutSunflowerSeeds extends CookZ_CutOutSplitableSeeds_Base
{    
    override void Init()
    {
        super.Init();
        InsertIngredient(0,"CookZPlants_SunflowerHead");
        AddResult("CookZPlants_SunflowerSeeds");
    }
};

class CookZ_CraftMortarAndPestle extends RecipeBase    
{    
    override void Init()
    {
        m_Name = "#Craft #STR_CookZPlants_MortarAndPestle_DN";
        m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
        m_AnimationLength = 0.5;//animation length in relative time units
        m_Specialty = 0.02;// value > 0 for roughness, value < 0 for precision

        //conditions
        m_MinDamageIngredient[0] = -1;//-1 = disable check
        m_MaxDamageIngredient[0] = 3;//-1 = disable check

        m_MinQuantityIngredient[0] = 1;//-1 = disable check
        m_MaxQuantityIngredient[0] = -1;//-1 = disable check

        m_MinDamageIngredient[1] = -1;//-1 = disable check
        m_MaxDamageIngredient[1] = 3;//-1 = disable check

        m_MinQuantityIngredient[1] = 1;//-1 = disable check
        m_MaxQuantityIngredient[1] = -1;//-1 = disable check
        //----------------------------------------------------------------------------------------------------------------------

        //INGREDIENTS
        //ingredient 1
        InsertIngredient(0,"Stone");

        m_IngredientAddHealth[0] = 0;// 0 = do nothing
        m_IngredientSetHealth[0] = -1; // -1 = do nothing
        m_IngredientAddQuantity[0] = 0;// 0 = do nothing
        m_IngredientDestroy[0] = true;//true = destroy, false = do nothing
        m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient

        //ingredient 2
        InsertIngredient(1,"Hammer");

        m_IngredientAddHealth[1] = 0;// 0 = do nothing
        m_IngredientSetHealth[1] = -1; // -1 = do nothing
        m_IngredientAddQuantity[1] = 0;// 0 = do nothing
        m_IngredientDestroy[1] = false;//true = destroy, false = do nothing
        m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
        //----------------------------------------------------------------------------------------------------------------------

        //result1
        AddResult("CookZPlants_MortarAndPestle");//add results here

        m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
        m_ResultSetQuantity[0] = 1;//-1 = do nothing
        m_ResultSetHealth[0] = -1;//-1 = do nothing
        m_ResultInheritsHealth[0] = 1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
        m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
        m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
        m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
        m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
    }

    override bool CanDo( ItemBase ingredients[], PlayerBase player )
    {
        return true;
    }

    // ToDo PP without this dayz throws an error when closing the client ... why?!
    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
    {
        super.Do(ingredients, player, results, specialty_weight);
    }
};

class CookZ_CraftFlour extends RecipeBase    
{    
    override void Init()
    {
        m_Name = "#STR_CookZPlants_UseMortarAndPestle #STR_CookZPlants_WheatEars_DN";
        m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
        m_AnimationLength = 0.5;//animation length in relative time units
        m_Specialty = 0.02;// value > 0 for roughness, value < 0 for precision

        //conditions
        m_MinDamageIngredient[0] = -1;//-1 = disable check
        m_MaxDamageIngredient[0] = 3;//-1 = disable check

        m_MinQuantityIngredient[0] = 1;//-1 = disable check
        m_MaxQuantityIngredient[0] = -1;//-1 = disable check

        m_MinDamageIngredient[1] = -1;//-1 = disable check
        m_MaxDamageIngredient[1] = 3;//-1 = disable check

        m_MinQuantityIngredient[1] = 1;//-1 = disable check
        m_MaxQuantityIngredient[1] = -1;//-1 = disable check
        //----------------------------------------------------------------------------------------------------------------------

        //INGREDIENTS
        //ingredient 1
        InsertIngredient(0,"CookZPlants_MortarAndPestle");

        m_IngredientAddHealth[0] = 0;// 0 = do nothing
        m_IngredientSetHealth[0] = -1; // -1 = do nothing
        m_IngredientAddQuantity[0] = 0;// 0 = do nothing
        m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
        m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient

        //ingredient 2
        InsertIngredient(1,"CookZPlants_WheatEars");

        m_IngredientAddHealth[1] = 0;// 0 = do nothing
        m_IngredientSetHealth[1] = -1; // -1 = do nothing
        m_IngredientAddQuantity[1] = 0;// 0 = do nothing
        m_IngredientDestroy[1] = true;//true = destroy, false = do nothing
        m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
        //----------------------------------------------------------------------------------------------------------------------

        //result1
        AddResult("CookZPlants_FlourBag");//add results here

        m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
        m_ResultSetQuantity[0] = -1;//-1 = do nothing
        m_ResultSetHealth[0] = -1;//-1 = do nothing
        m_ResultInheritsHealth[0] = 1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
        m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
        m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
        m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
        m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
    }

    override bool CanDo( ItemBase ingredients[], PlayerBase player )
    {
        return true;
    }

    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
    {
        // Adjusts quantity of results to n times quantity of ingredient 1
        Inventory_Base item_ingredient = Inventory_Base.Cast(ingredients[1]);
        float maxQuantityIngredient = item_ingredient.GetQuantityMax();
        
        ItemBase result = results[0];
        float maxQuantityResult = result.GetQuantityMax();
        
        float resultQuantityPerIngredientQuantity = (maxQuantityResult / maxQuantityIngredient) / 2;
        
        float quantityIngredient = item_ingredient.GetQuantity();
        float resultQuantity = resultQuantityPerIngredientQuantity * quantityIngredient;
        result.SetQuantity(resultQuantity);
    }
};

class CookZ_CraftCornFlour extends RecipeBase
{    
    override void Init()
    {
        m_Name = "#STR_CookZPlants_UseMortarAndPestle #STR_CookZPlants_Corn_DN";
        m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
        m_AnimationLength = 0.5;//animation length in relative time units
        m_Specialty = 0.02;// value > 0 for roughness, value < 0 for precision

        //conditions
        m_MinDamageIngredient[0] = -1;//-1 = disable check
        m_MaxDamageIngredient[0] = 3;//-1 = disable check

        m_MinQuantityIngredient[0] = 1;//-1 = disable check
        m_MaxQuantityIngredient[0] = -1;//-1 = disable check

        m_MinDamageIngredient[1] = -1;//-1 = disable check
        m_MaxDamageIngredient[1] = 3;//-1 = disable check

        m_MinQuantityIngredient[1] = 1;//-1 = disable check
        m_MaxQuantityIngredient[1] = -1;//-1 = disable check
        //----------------------------------------------------------------------------------------------------------------------

        //INGREDIENTS
        //ingredient 1
        InsertIngredient(0,"CookZPlants_MortarAndPestle");

        m_IngredientAddHealth[0] = 0;// 0 = do nothing
        m_IngredientSetHealth[0] = -1; // -1 = do nothing
        m_IngredientAddQuantity[0] = 0;// 0 = do nothing
        m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
        m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient

        //ingredient 2
        InsertIngredient(1,"CookZPlants_Corn");

        m_IngredientAddHealth[1] = 0;// 0 = do nothing
        m_IngredientSetHealth[1] = -1; // -1 = do nothing
        m_IngredientAddQuantity[1] = 0;// 0 = do nothing
        m_IngredientDestroy[1] = true;//true = destroy, false = do nothing
        m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
        //----------------------------------------------------------------------------------------------------------------------

        //result1
        AddResult("CookZPlants_CornFlourBag");;//add results here

        m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
        m_ResultSetQuantity[0] = 150;//-1 = do nothing
        m_ResultSetHealth[0] = -1;//-1 = do nothing
        m_ResultInheritsHealth[0] = 1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
        m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
        m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
        m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
        m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
    }

    override bool CanDo( ItemBase ingredients[], PlayerBase player )
    {
        return true;
    }

    // ToDo PP without this dayz throws an error when closing the client ... why?!
    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
    {
        super.Do(ingredients, player, results, specialty_weight);
    }
};

class CookZ_CraftDough_Base extends RecipeBase
{
    override void Init()
    {
        m_Name = "#STR_CookZPlants_KneadDough";
        m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
        m_AnimationLength = 1;//animation length in relative time units
        m_Specialty = 0.02;// value > 0 for roughness, value < 0 for precision
        
        //conditions
        m_MinDamageIngredient[0] = -1;//-1 = disable check
        m_MaxDamageIngredient[0] = 3;//-1 = disable check
        
        m_MinQuantityIngredient[0] = 60;//-1 = disable check
        m_MaxQuantityIngredient[0] = -1;//-1 = disable check
        
        m_MinDamageIngredient[1] = -1;//-1 = disable check
        m_MaxDamageIngredient[1] = 3;//-1 = disable check
        
        m_MinQuantityIngredient[1] = 100;//-1 = disable check
        m_MaxQuantityIngredient[1] = -1;//-1 = disable check
        //----------------------------------------------------------------------------------------------------------------------
        
        //INGREDIENTS
        //ingredient 1
        InsertIngredient(0,"Bottle_Base");
        InsertIngredient(0,"Barrel_ColorBase");
        
        m_IngredientAddHealth[0] = 0;// 0 = do nothing
        m_IngredientSetHealth[0] = -1; // -1 = do nothing
        m_IngredientAddQuantity[0] = -60;// 0 = do nothing
        m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
        m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
        
        //ingredient 2
        m_IngredientAddHealth[1] = 0;// 0 = do nothing
        m_IngredientSetHealth[1] = -1; // -1 = do nothing
        m_IngredientAddQuantity[1] = -100;// 0 = do nothing
        m_IngredientDestroy[1] = false;// false = do nothing
        m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
        //----------------------------------------------------------------------------------------------------------------------
        
        //result1
        m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
        m_ResultSetQuantity[0] = 1;//-1 = do nothing
        m_ResultSetHealth[0] = -1;//-1 = do nothing
        m_ResultInheritsHealth[0] = 1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
        m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
        m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
        m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
        m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
    }

    override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
    {
        ItemBase vessel = ItemBase.Cast(ingredients[0]);
        
        if (vessel && vessel.GetQuantity() >= 100 && vessel.IsLiquidContainer()) // if vessel has water in it
        {
            return vessel.GetLiquidType() == LIQUID_WATER;
        }
        
        return false;
    }

    // ToDo PP without this dayz throws an error when closing the client ... why?!
    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
    {
        super.Do(ingredients, player, results, specialty_weight);
    }
};

class CookZ_CraftDough extends CookZ_CraftDough_Base
{    
    override void Init()
    {
        super.Init();
        InsertIngredient(1,"CookZPlants_FlourBag");
        AddResult("CookZPlants_Dough");
    }
};

class CookZ_CraftCornDough extends CookZ_CraftDough_Base
{    
    override void Init()
    {
        super.Init();
        InsertIngredient(1,"CookZPlants_CornFlourBag");
        AddResult("CookZPlants_CornDough");
    }
};

class PeelCookZPlants_Onion extends RecipeBase
{	
	override void Init()
	{
		m_Name = "#STR_CookZPlants_Peel";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 1;//animation length in relative time units
		m_Specialty = 0.01;// value > 0 for roughness, value < 0 for precision
		
		m_AnywhereInInventory = false;//is this recipe valid even when neither of the items is in hands
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[0] = -1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"CookZPlants_OnionSeed");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = true;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1,"Sickle");
		InsertIngredient(1,"KukriKnife");
		InsertIngredient(1,"FangeKnife");
		InsertIngredient(1,"Hacksaw");
		InsertIngredient(1,"KitchenKnife");
		InsertIngredient(1,"SteakKnife");
		InsertIngredient(1,"StoneKnife");
		InsertIngredient(1,"Cleaver");
		InsertIngredient(1,"CombatKnife");
		InsertIngredient(1,"HuntingKnife");
		InsertIngredient(1,"Machete");
		InsertIngredient(1,"CrudeMachete");
		InsertIngredient(1,"OrientalMachete");
		InsertIngredient(1,"AK_Bayonet");
		InsertIngredient(1,"M9A1_Bayonet");
		InsertIngredient(1,"Mosin_Bayonet");
		InsertIngredient(1,"SKS_Bayonet");
		InsertIngredient(1,"Sword");
		InsertIngredient(1,"Screwdriver");
		InsertIngredient(1,"Hatchet");
		InsertIngredient(1,"HandSaw");
		InsertIngredient(1,"BoneKnife");
		
		m_IngredientAddHealth[1] = -0.5;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = 0;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = true;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		AddResult("CookZPlants_Onion");//add results here

		m_ResultSetFullQuantity[0] = true;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[0] = -1;//-1 = do nothing
		m_ResultSetHealth[0] = -1;//-1 = do nothing
		m_ResultInheritsHealth[0] = -2;// (value) == -1 means do nothing; a (value) >= 0 means thi s result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0] = -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
		
		//----------------------------------------------------------------------------------------------------------------------
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		ItemBase ingredient = ingredients[0];
		
		for (int i=0; i < results.Count(); i++)
		{
			ItemBase item_result;
			Class.CastTo(item_result, results.Get(i));
			
			MiscGameplayFunctions.TransferItemProperties(ingredient, item_result);
			
			float quantityMultiplier = ingredient.GetHealth01("",""); 
			item_result.SetQuantityNormalized(quantityMultiplier);
			
			//temperature check
			if (!ingredient.CanHaveTemperature())
				item_result.SetTemperatureDirect(GameConstants.ITEM_TEMPERATURE_NEUTRAL_ZONE_MIDDLE);
			
			if (!ingredient.CanFreeze())
				item_result.SetFrozen(false);
		}
	}
};

class CutOutCookZPlantSeeds_Base extends CutOutSeeds
{
    override void Init()
    {
        m_Name = "#STR_cutoutseeds0";
        m_IsInstaRecipe = false;            // should this recipe be performed instantly without animation
        m_AnimationLength = 1;              // animation length in relative time units

        //conditions
        m_MinDamageIngredient[0]    = -1;   // -1 = disable check
        m_MaxDamageIngredient[0]    = 3;    // -1 = disable check
        m_MinQuantityIngredient[0]  = -1;   // -1 = disable check
        m_MaxQuantityIngredient[0]  = -1;   // -1 = disable check

        m_MinDamageIngredient[1]    = -1;
        m_MaxDamageIngredient[1]    = 3;
        m_MinQuantityIngredient[1]  = -1;
        m_MaxQuantityIngredient[1]  = -1;
        //----------------------------------------------------------------------------------------------------------------------
        
        //INGREDIENTS

        m_IngredientAddHealth[0]    = 0;    // 0 = do nothing
        m_IngredientSetHealth[0]    = -1;   // -1 = do nothing
        m_IngredientAddQuantity[0]  = 0;    // 0 = do nothing
        m_IngredientDestroy[0]      = true; // true = destroy, false = do nothing

        //ingredient 2
        InsertIngredient(1,"Sickle");
        InsertIngredient(1,"KukriKnife");
        InsertIngredient(1,"FangeKnife");
        InsertIngredient(1,"Hacksaw");
        InsertIngredient(1,"HandSaw");
        InsertIngredient(1,"KitchenKnife");
        InsertIngredient(1,"SteakKnife");
        InsertIngredient(1,"StoneKnife");
        InsertIngredient(1,"Cleaver");
        InsertIngredient(1,"CombatKnife");
        InsertIngredient(1,"HuntingKnife");
        InsertIngredient(1,"Machete");
        InsertIngredient(1,"CrudeMachete");
        InsertIngredient(1,"OrientalMachete");
        InsertIngredient(1,"WoodAxe");
        InsertIngredient(1,"Hatchet");
        InsertIngredient(1,"FirefighterAxe");
        InsertIngredient(1,"Sword");
        InsertIngredient(1,"AK_Bayonet");
        InsertIngredient(1,"M9A1_Bayonet");
        InsertIngredient(1,"Mosin_Bayonet");
        InsertIngredient(1,"SKS_Bayonet");
        InsertIngredient(1,"BoneKnife");

        m_IngredientAddHealth[1]    = -1;
        m_IngredientSetHealth[1]    = -1;
        m_IngredientAddQuantity[1]  = 0;
        m_IngredientDestroy[1]      = false;

        //----------------------------------------------------------------------------------------------------------------------
        //RESULTS

        m_ResultSetFullQuantity[0]      = false;    // true = set full quantity, false = do nothing
        m_ResultSetQuantity[0]          = 12;       // -1 = do nothing
        m_ResultSetHealth[0]            = -1;       // -1 = do nothing
        m_ResultInheritsHealth[0]       = 0;        // (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
        m_ResultInheritsColor[0]        = -1;       // (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
        m_ResultToInventory[0]          = -1;       // (value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
        m_ResultReplacesIngredient[0]   = -1;       // (value) == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
    }
}

class CutOutCookZPlants_Chili extends CutOutCookZPlantSeeds_Base
{    
    override void Init()
    {
        super.Init();
        InsertIngredient(0, "CookZPlants_Chili");
        AddResult("CookZPlants_ChiliSeeds");
    }
};

class CutOutCookZPlants_Corn extends CutOutCookZPlantSeeds_Base
{    
    override void Init()
    {
        super.Init();
        InsertIngredient(0, "CookZPlants_Corn");
        AddResult("CookZPlants_CornSeeds");
    }
};

class CookZ_CraftMushroomSpawn extends RecipeBase
{
    override void Init()
    {
        m_Name = "#Craft #STR_CookZPlants_MushroomSpawn_DN";
        m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
        m_AnimationLength = 0.5;//animation length in relative time units
        m_Specialty = 0.02;// value > 0 for roughness, value < 0 for precision

        //conditions
        m_MinDamageIngredient[0] = -1;//-1 = disable check
        m_MaxDamageIngredient[0] = 3;//-1 = disable check

        m_MinQuantityIngredient[0] = 1;//-1 = disable check
        m_MaxQuantityIngredient[0] = -1;//-1 = disable check

        m_MinDamageIngredient[1] = -1;//-1 = disable check
        m_MaxDamageIngredient[1] = 3;//-1 = disable check

        m_MinQuantityIngredient[1] = 1;//-1 = disable check
        m_MaxQuantityIngredient[1] = -1;//-1 = disable check
        //----------------------------------------------------------------------------------------------------------------------

        //INGREDIENTS
        //ingredient 1
        InsertIngredient(0,"MushroomBase");

        m_IngredientAddHealth[0] = 0;// 0 = do nothing
        m_IngredientSetHealth[0] = -1; // -1 = do nothing
        m_IngredientAddQuantity[0] = 0;// 0 = do nothing
        m_IngredientDestroy[0] = true;//true = destroy, false = do nothing
        m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient

        //ingredient 2
        InsertIngredient(1,"Firewood");//you can insert multiple ingredients this way

        m_IngredientAddHealth[1] = 0;// 0 = do nothing
        m_IngredientSetHealth[1] = -1; // -1 = do nothing
        m_IngredientAddQuantity[1] = -1;// 0 = do nothing
        m_IngredientDestroy[1] = false;// false = do nothing
        m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
        //----------------------------------------------------------------------------------------------------------------------

        //result1
        AddResult("CookZPlants_MushroomSpawn");//add results here

        m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
        m_ResultSetQuantity[0] = 1;//-1 = do nothing
        m_ResultSetHealth[0] = -1;//-1 = do nothing
        m_ResultInheritsHealth[0] = 1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
        m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
        m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
        m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
        m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
    }

    override bool CanDo( ItemBase ingredients[], PlayerBase player )
    {
        return true;
    }

    // ToDo PP without this dayz throws an error when closing the client ... why?!
    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
    {
        super.Do(ingredients, player, results, specialty_weight);
    }
};