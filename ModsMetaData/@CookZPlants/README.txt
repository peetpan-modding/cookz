A couple of parameters can be configured via a server config file. This file is generated with
default values at "$missionFolder\CookZ\CookZPlants_VXXX.json" the first time you start the server with the
mod installed. After modifying the configuration, you need to restart the server.

(!) If the mod is updated and new configuration is added, then a file with an incremented version suffix is created,
    e.g. CookZPlants_V023.json. You need to transfer your changes from the previous version and restart your server –
    but you only need to keep the latest version.

The file has the following default content, enriched here with some documentation.

Boolean values are set by 1 for true and by 0 for false.

{
    // The time in seconds it takes for a wheat plant to become fully mature (ready to be harvested).
    // Note: DayZ adds a random number between -60 and 180 per plant.
    // Note: The minimum is capped at 100 to prevent strange effects with values that are too low.
    "FullMaturityTimeWheat": 1350,
    
    // see FullMaturityTimeWheat for chili
    "FullMaturityTimeChili": 1350,
    
    // see FullMaturityTimeWheat for corn
    "FullMaturityTimeCorn": 1350,
    
    // see FullMaturityTimeWheat for onion
    "FullMaturityTimeOnion": 1350,
    
    // see FullMaturityTimeWheat for soybean
    "FullMaturityTimeSoybean": 1350,

    // is plant infection disabled
    "DisablePlantInfection": 1
}
