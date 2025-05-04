modded class MissionServer
{
    void MissionServer()
    {
        CookZPlants_Config config;
        CookZPlants_ConfigService.LoadConfig(COOKZPLANTS_CONFIG_FILE_NAME, config);
        GetDayZGame().SetCookZPlants_Config(config);
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);
        auto configParams = new Param1<CookZPlants_Config>(GetDayZGame().GetCookZPlants_Config());
        GetGame().RPCSingleParam(player, COOKZPLANTS_CONFIG_RPC_TYPE, configParams, true, identity);
    }
};