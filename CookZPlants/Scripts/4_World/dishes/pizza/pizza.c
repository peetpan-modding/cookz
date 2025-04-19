class CookZPlants_Pizza_Base: CookZ_ClosedDish
{
    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionOpen);
    }
}

class CookZPlants_Pizza_Opened_Base: CookZ_OpenedDish
{
    override void OnVariablesSynchronized()
    {
        float delta = m_VarQuantity - m_VarQuantityPrev;
        super.OnVariablesSynchronized();

        if(delta != 0)
        {
            RecalculateSlices();
        }
    }

    private void RecalculateSlices()
    {
        float sliceSize = GetQuantityMax() / 8.0;
        int sliceThreshold = Math.Ceil(GetQuantity() / sliceSize);
        for (int i=0;i<8;i++)
        {
            // needs to be in sync with cpp CookZ_PizzaOpened_Base.simpleHiddenSelections
            // (can be fetched dynamically, but this is more efficient - worth it?)
            SetSimpleHiddenSelectionState(i, i < sliceThreshold);
            SetSimpleHiddenSelectionState(i + 8, i < sliceThreshold);
        }

    }
}

class CookZPlants_MargheritaPizza : CookZPlants_Pizza_Base {}
class CookZPlants_PepperoniPizza : CookZPlants_Pizza_Base {}
class CookZPlants_SeafoodPizza : CookZPlants_Pizza_Base {}
class CookZPlants_VegetablePizza : CookZPlants_Pizza_Base {}
class CookZPlants_MushroomPizza : CookZPlants_Pizza_Base {}

class CookZPlants_MargheritaPizza_Opened : CookZPlants_Pizza_Opened_Base {}
class CookZPlants_PepperoniPizza_Opened : CookZPlants_Pizza_Opened_Base {}
class CookZPlants_SeafoodPizza_Opened : CookZPlants_Pizza_Opened_Base {}
class CookZPlants_VegetablePizza_Opened : CookZPlants_Pizza_Opened_Base {}
class CookZPlants_MushroomPizza_Opened : CookZPlants_Pizza_Opened_Base {}
