modded class MissionServer
{
    void MissionServer()
    {
        CookZPlants_Config cookzplants_config;
        CookZPlants_ConfigService.LoadConfig(COOKZPLANTS_CONFIG_FILE_NAME, cookzplants_config);
        GetDayZGame().SetCookZPlants_Config(cookzplants_config);
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);
        auto configParams = new Param1<CookZPlants_Config>(GetDayZGame().GetCookZPlants_Config());
        GetGame().RPCSingleParam(player, COOKZPLANTS_CONFIG_RPC_TYPE, configParams, true, identity);
    }
};