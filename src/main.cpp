#include <swiftly/swiftly.h>
#include <swiftly/server.h>
#include <swiftly/gameevents.h>
#include <swiftly/configuration.h>

Server *server = nullptr;
PlayerManager *g_playerManager = nullptr;
Configuration *config = nullptr;

void OnProgramLoad(const char *pluginName, const char *mainFilePath)
{
    Swiftly_Setup(pluginName, mainFilePath);
    server = new Server();
    g_playerManager = new PlayerManager();
    config = new Configuration();
}

void OnPlayerHurt(Player *player, Player *attacker, short dmgHealth, short dmgArmor, short hitgroup, const char *weapon, bool fatal)
{
    int type = config->Fetch<bool>("showdamage.center");
    if (type == true)
    {
        attacker->SendMsg(HUD_PRINTCENTER, FetchTranslation("showdamage.centertext"), dmgHealth, player->GetName());
        print("centerul merge frate \n");
    }
    else if (type == false)
    {
        attacker->SendMsg(HUD_PRINTTALK, FetchTranslation("showdamage.messagetext"), dmgHealth, player->GetName());
        print("mesajul in chat merge frate \n");
    }
}

void OnPluginStart()
{
    int type = config->Fetch<bool>("showdamage.center");
    if (type == true)
    {
       print("------------------------------------------------------- \n");
       print("Acum este setat tipul pe center \n");
       print("------------------------------------------------------- \n");
    }
    else if (type == false)
    {
       print("------------------------------------------------------- \n");
       print("Acum este setat tipul pe chat \n");
       print("------------------------------------------------------- \n");
    }
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
    return "Show Damage (multi methods)";
}

const char *GetPluginWebsite()
{
    return "https://github.com/moongetsu/swiftly_showdamage";
}