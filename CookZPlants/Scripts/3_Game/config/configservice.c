class CookZPlants_Config
{
    int FullMaturityTimeWheat;
    int FullMaturityTimeChili;
    int FullMaturityTimeCorn;
    int FullMaturityTimeOnion;
    int FullMaturityTimeSoybean;
    int FullMaturityTimeMushroom;
    bool DisablePlantInfection;
};

class CookZPlants_ConfigService
{
    static void LoadConfig(string configName, out CookZPlants_Config config)
    {
        string configPath = COOKZ_CONFIG_ROOT + configName;
        
        if (!FileExist(configPath))
        {
            CreateDefaultConfig(config);
            MakeDirectory(COOKZ_CONFIG_ROOT);

            string saveErrorMessage;
            if (!JsonFileLoader<CookZPlants_Config>.SaveFile(configPath, config, saveErrorMessage))
            {
                Print(string.Format("[CookZPlants] Error generating configuration: %1", saveErrorMessage));
            }
            else
            {
                Print("[CookZPlants] Successfully generated configuration.");
            }
            return;
        }

        string loadErrorMessage;
        if (!JsonFileLoader<CookZPlants_Config>.LoadFile(configPath, config, loadErrorMessage))
        {
            Print(string.Format("[CookZPlants] Error loading configuration: %1", loadErrorMessage));
        }
        else
        {
            Print("[CookZPlants] Successfully loaded configuration.");
        }
    }

    protected static void CreateDefaultConfig(out CookZPlants_Config config)
    {
        config = new CookZPlants_Config();

        config.FullMaturityTimeWheat = 1350;
        config.FullMaturityTimeChili = 1350;
        config.FullMaturityTimeCorn = 1350;
        config.FullMaturityTimeOnion = 1350;
        config.FullMaturityTimeSoybean = 1350;
        config.FullMaturityTimeMushroom = 1350;
        config.DisablePlantInfection = true;
    }
};

modded class DayZGame
{    
    protected ref CookZPlants_Config m_CookZPlants_Config;
    
    void SetCookZPlants_Config(CookZPlants_Config config)
    {
        m_CookZPlants_Config = config;
    }

    CookZPlants_Config GetCookZPlants_Config()
    {
        return m_CookZPlants_Config;
    }
};