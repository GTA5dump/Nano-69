#include "stdafx.h"
#include "discord.h"
#include "Discord/include/discord_rpc.h"
#include "Discord/include/discord_register.h"
#pragma comment(lib, "Discord/lib/discord-rpc.lib")

DiscordRichPresence discordPresence;
void UpdatePresence()
{
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.state = "Nano69 Base";
    discordPresence.startTimestamp = 112343;
    discordPresence.largeImageText = "Version: 0.1";
    discordPresence.smallImageText = "Nano69 Base";
    discordPresence.partyId = "h";
    Discord_UpdatePresence(&discordPresence);
}

void Initialize()
{
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));
	Discord_Initialize("REPLACE WITH DISCORD DEVOLPER KEY!", &handlers, TRUE, nullptr);
}

void Shutdown()
{
	Discord_Shutdown();
}

void DiscordMain()
{
	Initialize();
	UpdatePresence();
}