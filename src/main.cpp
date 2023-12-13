#include <swiftly/swiftly.h>
#include <swiftly/server.h>
#include <swiftly/gameevents.h>

Server *server = nullptr;
PlayerManager *g_playerManager = nullptr;

void OnProgramLoad(const char *pluginName, const char *mainFilePath)
{
    Swiftly_Setup(pluginName, mainFilePath);
    server = new Server();
    g_playerManager = new PlayerManager();
}

void OnPlayerHurt(Player *player, Player *attacker, short dmgHealth, short hitgroup, bool fatal)
{
    g_playerManager->SendMsg(HUD_PRINTTALK, FetchTranslation("showdamage.centertext"), dmgHealth, player->GetName(), hitgroup);
}

void OnPluginStart()
{
}

void OnPluginStop()
{
}

const char *GetPluginAuthor()
{
    return "moongetsu";
}

const char *GetPluginVersion()
{
    return "1.0.0";
}

const char *GetPluginName()
{
    return "Show Damage (center)";
}

const char *GetPluginWebsite()
{
    return "https://github.com/moongetsu/swiftly_showdamage";
}