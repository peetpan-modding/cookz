modded class PlantBase
{
    // harvest an item that is splitable - i.e. only create one item and set the quantity to m_CropsCount
    override void Harvest( PlayerBase player )
    {
        if (this.Type() != CookZPlants_PlantWheat && this.Type() != CookZPlants_PlantSoyBean)
        {
            super.Harvest(player);
            return;
        }

        if (!IsSpoiled())
        {
            vector pos = player.GetPosition();
            ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx( m_CropsType, pos, ECE_PLACE_ON_SURFACE ) );
            item.SetQuantity(m_CropsCount);
        }
        
        m_HasCrops = false;
        SetSynchDirty();
        UpdatePlant();
    }

    // access private variables in extending classes

    protected int CookZPlants_GetCropsCount()
    {
        return m_CropsCount;
    }

    protected string CookZPlants_GetCropsType()
    {
        return m_CropsType;
    }

    protected void CookZPlants_SetHasCrops(bool value)
    {
        m_HasCrops = value;
    }
}