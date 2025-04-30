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