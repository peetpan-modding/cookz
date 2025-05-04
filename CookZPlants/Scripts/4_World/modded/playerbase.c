modded class PlayerBase
{
    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, rpc_type, ctx);

        switch (rpc_type)
        {
            case COOKZPLANTS_CONFIG_RPC_TYPE:
            {
                Param1<CookZPlants_Config> configParams;
                if (!ctx.Read(configParams))
                {
                    return;
                }

                GetDayZGame().SetCookZPlants_Config(configParams.param1);
                break;
            }
        }
    }
}
