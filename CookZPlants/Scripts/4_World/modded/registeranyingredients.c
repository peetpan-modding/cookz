modded class CookZ_Cookbook
{
    override void RegisterAnyIngredients()
    {
        super.RegisterAnyIngredients();

        RegisterAnyIngredient(COOKING_INGREDIENT_ANY_VEG, "CookZPlants_Chili");
        RegisterAnyIngredient(COOKING_INGREDIENT_ANY_VEG, "CookZPlants_Corn");
        RegisterAnyIngredient(COOKING_INGREDIENT_ANY_VEG, "CookZPlants_Onion");
        RegisterAnyIngredient(COOKING_INGREDIENT_ANY_VEG, "CookZPlants_SugarBeet");
        RegisterAnyIngredient(COOKING_INGREDIENT_ANY_VEG, "CookZPlants_CabbageSlice");
        RegisterAnyIngredient(COOKING_INGREDIENT_ANY_VEG, "CookZPlants_Cucumber");

        RegisterAnyIngredient(COOKING_INGREDIENT_ANY_SAUSAGE, "CookZPlants_Tofu_Sausage");
    }
}