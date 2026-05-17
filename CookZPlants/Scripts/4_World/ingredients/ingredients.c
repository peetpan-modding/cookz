class CookZPlants_FlourBag_Base: Edible_Base
{
    override void InitItemVariables()
    {
        super.InitItemVariables();
        can_this_be_combined = true;
    }
};

class CookZPlants_FlourBag: CookZPlants_FlourBag_Base {};
class CookZPlants_CornFlourBag: CookZPlants_FlourBag_Base {};

class CookZPlants_Dough: Inventory_Base {};

class CookZPlants_Chili: GreenBellPepper {}
class CookZPlants_Corn: GreenBellPepper {}
class CookZPlants_Tofu: GreenBellPepper {}
class CookZPlants_Onion: GreenBellPepper {}
class CookZPlants_SugarBeet: GreenBellPepper {}
class CookZPlants_CabbageSlice: GreenBellPepper {}
class CookZPlants_Cucumber: GreenBellPepper {}