modded class CookZ_Cookbook
{
    override void RegisterAnyIngredients()
    {
        super.RegisterAnyIngredients();

        RegisterAnyIngredient(COOKING_INGREDIENT_ANY_VEG, "CookZPlants_Chili");
    }
}