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

void OnPlayerHurt(Player *player, Player *attacker, short dmgHealth, short dmgArmor, short hitgroup, const char *weapon, int fatal)
{
    int messagetype = config->Fetch<int>("showdamage.method");
    if (messagetype == 0)
    {
        attacker->SendMsg(HUD_PRINTCENTER, FetchTranslation("showdamage.centertext"), dmgHealth, player->GetName());
        print("Metoda 0 merge frate \n");
    }
    else if (messagetype == 1)
    {
        attacker->SendMsg(HUD_PRINTTALK, FetchTranslation("showdamage.messagetext"), dmgHealth, player->GetName());
        print("Metoda 1 merge frate \n");
    }
}

void OnPluginStart()
{
    int messagetype = config->Fetch<int>("showdamage.method");
    if (messagetype == 0)
    {
       print("------------------------------------------------------- \n");
       print("Acum este setata metoda cu numarul 0 \n");
       print("------------------------------------------------------- \n");
    }
    else if (messagetype == 1)
    {
       print("------------------------------------------------------- \n");
       print("Acum este setata metoda cu numarul 1 \n");
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