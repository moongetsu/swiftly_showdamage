#include <swiftly/swiftly.h>
#include <swiftly/server.h>
#include <swiftly/gameevents.h>

Server server = nullptr;
PlayerManagerg_playerManager = nullptr;

void OnProgramLoad(const char pluginName, const charmainFilePath)
{
    Swiftly_Setup(pluginName, mainFilePath);
    server = new Server();
    g_playerManager = new PlayerManager();
}

void OnPlayerHurt(Player player, Playerattacker, short dmgHealth, short dmgArmor, short hitgroup, const char weapon, bool fatal)
{
    int method = config->Fetch<int>("showdamage.method");
    if (method == 0)
    {
        player->SendMsg(HUD_PRINTCENTER, FetchTranslation("showdamage.centertext"), dmgHealth, player->GetName());
    }
    else if (method == 1)
    {
        player->SendMsg(HUD_PRINTCENTER, FetchTranslation("showdamage.messagetext"), dmgHealth, player->GetName());
    }
}

void OnPluginStart()
{
}

void OnPluginStop()
{
}

const charGetPluginAuthor()
{
    return "moongetsu";
}

const char GetPluginVersion()
{
    return "1.0.0";
}

const charGetPluginName()
{
    return "Show Damage (multi methods)";
}

const char *GetPluginWebsite()
{
    return "https://github.com/moongetsu/swiftly_showdamage";
}