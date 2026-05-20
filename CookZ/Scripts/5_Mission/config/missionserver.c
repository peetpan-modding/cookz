modded class MissionServer
{
    void MissionServer()
    {
        CookZ_Config cookz_config;
        CookZ_ConfigService.LoadConfig(COOKZ_CONFIG_FILE_NAME, cookz_config);
        GetDayZGame().SetCookZ_Config(cookz_config);
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);
        auto configParams = new Param1<CookZ_Config>(GetDayZGame().GetCookZ_Config());
        GetGame().RPCSingleParam(player, COOKZ_CONFIG_RPC_TYPE, configParams, true, identity);
    }
};