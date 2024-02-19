#pragma once
#include "stdafx.h"
#include "Features.h"
#include "shellapi.h"
#include <fstream>
#include <string>
#include <iostream>
#include "PartialFeatures.hpp"
#include "Discord.h"

void Menu::ScriptEventLog(const std::string& text)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY((char*)"STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text.c_str());
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2((char*)"Nano69", (char*)"Logo", true, 5, (char*)"Nano69", (char*)"Nano69", 1.f, (char*)"___menu", 5, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);
}

BOOL firstload = true;
void main() {
	bool firstopen = true;
	while (true) {
		scrollbar();
		Menu::Checks::Controlls();
		Features::UpdateLoop();
		Menu::Drawing::YTD();
		Featuress();
		if (firstopen) {
			LoadMsg();
			load();
			firstopen = false;
		}

		if (Menu::Settings::Virustroll == true)
		{
			if (Menu::Settings::Authcheck == true)
			{
				static float step = 0.001f;
				switch (Menu::Settings::currentMenu) {
				case mainmenu:
				{
					Menu::Title("");
					// Menu::Subtitle("Main Menu");
					Menu::MenuOption("Player", playermenu);//1
					Menu::MenuOption("Teleport", teleports);//2
					Menu::MenuOption("Spawner", vehspawner);//3
					Menu::MenuOption("Vehicle", vehicle);//4
					Menu::MenuOption("Network", network);//5
					Menu::MenuOption("Weapon ", weapon);//6
					Menu::MenuOption("Recovery", recover);//7
					Menu::MenuOption("Protections", protection);//8
					Menu::MenuOption("Settings Menu", settingsmenu);//9
					Menu::Settings::menuWidth = (float)widthkek / 100;
					Menu::Settings::scrollbarWidthIndex = (float)(Menu::Settings::menuWidth / 2) + 0.01f;
					Menu::Info("Activate God Mode to protect against crap free menus who try to blow you up for no reason at all!", 1);
					Menu::Info("Move like no tomorow!", 2);
					Menu::Info("Spawn any car you could need or want!", 3);
					Menu::Info("Make your car look like a new car! VROOOOM", 4);
					Menu::Info("Mess or be kind to your lobby!", 5);
					Menu::Info("Be a a**hole and shoot random payers for fun!", 6);
					Menu::Info("Get money because your broke! [SAFE]", 7);
					Menu::Info("Protect against other modders who try to crash you for no good reason!", 8);
					Menu::Info("Change the theme and make the menu look nice!", 9);
				}
				break;

				case network:
				{
					Menu::Title("Network Options");
					// Menu::Subtitle("NETWORK");
					Menu::MenuOption("Online Players", onlinemenu_playerlist);
					Menu::MenuOption("All Players", allplayers);
					Menu::MenuOption("Tunables", FeaturesS);
					Menu::MenuOption("Misc", mods);//8
					Menu::MenuOption("Lobby Weather", weatheroptions);
				}
				break;

				case outfitss:
				{
					Menu::Title("Outfit Menu");
					// Menu::Subtitle("OUTFITS");
					Menu::MenuOption("Outfit Changer", clothes);
					Menu::MenuOption("Outfits", outfits);

				}
				break;

				case Outfitcolour:
				{
					Menu::Title("Outfit Colour");
					// Menu::Subtitle("OUTFIT COLOUR");

					if (Menu::Int("~r~Red", Features::rbr, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::rbr = NumberKeyboard();
						}
					}

					if (Menu::Int("~g~Green", Features::rbd, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::rbd = NumberKeyboard();
						}
					}

					if (Menu::Int("~b~Blue", Features::rbs, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::rbs = NumberKeyboard();
						}
					}

				}
				break;


				//Super
				case supermenu:
				{
					Menu::Title("Super Menu");
					// Menu::Subtitle("SUPER MENU");
					Menu::MenuOption("helicopter bomber", bomber);
					Menu::MenuOption("Cargobob magnet", cargoop);
					Menu::MenuOption("Container Walker", walker);
					Menu::MenuOption("Train Simulator", trainii);
					Menu::MenuOption("Ghost Rider", ghostw);
					Menu::MenuOption("Zoom Options", zoomi);
					Menu::MenuOption("Explode Waypoint Options", zoomiii);
					Menu::Toggle("Paranormal Mode", Features::Superr, [] { Features::SuperDooper(Features::Superr); });
					Menu::Toggle("Forcefield", Features::flxneav, [] { Features::nearbflx(Features::flxneav); });
					Menu::Toggle("Chaos Mode", Features::ChaosMode, [] { Features::Chaos(Features::ChaosMode); });
					Menu::Toggle("Meteor Shower", Features::AsteroidShower, [] { Features::AsteroidShowerToggle(Features::AsteroidShower); });
					Menu::Toggle("Airstrike Mode", Features::AirstrikeShower, [] { Features::AirstrikehowerToggle(Features::AirstrikeShower); });
					Menu::Toggle("Free Cam", Features::free, [] { Features::freeCam(Features::free); });
					Menu::Toggle("Unlimited Orbital cannon", Features::Orbital, [] { Features::Orbi(Features::Orbital); });
					Menu::Toggle("Unlimited Vehicle Sell Time", Features::Sell, [] { Features::Sel(Features::Sell); });
					Menu::Int("Set Rank for Spoof ", Menu::Settings::setspoofrankpl, 0, 8000);
				}
				break;
				case trainii:
				{
					Menu::Title("Super Menu");
					// Menu::Subtitle("TRAIN");

					Menu::Option("Spawn Train", [] {
						train->spawn_train();
						});
					Menu::Toggle("Controll it", control_veh);
					Menu::Int("Speed", speed_train, -350, 350);
					Menu::Option("Delete Train", [] {
						train->delete_train();
						});
				}
				break;

				case walker:
				{
					Menu::Title("Super Menu");
					// Menu::Subtitle("WALK");
					Menu::Toggle("Container Walker", Features::ride_container, [] { Features::container_rider(Features::ride_container); });
					if (Menu::ListVector("Motorcycles", Motorcycles1, soutprop15)) {
						Features::autovehi(Motorcycles1[soutprop15]);
					}
				}
				break;

#pragma region Clothes
				case clothes:
				{
					Menu::Title("Clothes");
					// Menu::Subtitle("WARDROBE");
					Menu::Int("Outfit Slot", selectedOutfit, 0, 100);
					if (Menu::Option("Save")) {
						SaveOutfit();
					}
					if (Menu::Option("Load")) {
						LoadOutfit(); Ped playerPed = PLAYER::PLAYER_PED_ID();
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 0, outfit1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 1, mask1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 2, mask2, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 3, shirt1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 11, collars1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 8, Accessories1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 4, pants1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 5, hands1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 6, shoes1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 9, mission1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 10, decals1, 0, 0);
					}
					if (Menu::Int("Face", outfit1, 0, 11)) {
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 0, outfit1, 0, 0);
					}
					if (Menu::Int("Mask", mask1, 0, 132)) {
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 1, mask1, 0, 0);
					}
					if (Menu::Int("Hair", mask2, 0, 73)) {
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 2, mask2, 0, 0);
					}
					if (Menu::Int("Gloves", shirt1, 0, 164)) {
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 3, shirt1, 0, 0);
					}
					if (Menu::Int("Top", collars1, 0, 254)) {
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 11, collars1, 0, 0);
					}
					if (Menu::Int("Collar", Accessories1, 0, 131)) {
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 8, Accessories1, 0, 0);
					}
					if (Menu::Int("Pants", pants1, 0, 99)) {
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 4, pants1, 0, 0);
					}
					if (Menu::Int("Accessories", hands1, 0, 69)) {
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 5, hands1, 0, 0);
					}
					if (Menu::Int("Shoes", shoes1, 0, 79)) {
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 6, shoes1, 0, 0);
					}
					if (Menu::Int("Mission Stuff", mission1, 0, 29)) {
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 9, mission1, 0, 0);
					}
					if (Menu::Int("Decals", decals1, 0, 28)) {
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 10, decals1, 0, 0);
					}
				}
				break;

#pragma region LSC
				case lsc1:
				{
					Menu::Title("LSC");
					// Menu::Subtitle("LOS SANTOS CUSTOMS");
					Menu::MenuOption("Colour Changer", Vehcolor);
					Menu::MenuOption("Window Options", windowsceh);
					Menu::MenuOption("Neons Options", Neons);

					if (Menu::Option("Paint Chrome")) {
						VEHICLE::SET_VEHICLE_COLOURS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 120, 120);
					}
					if (Menu::Option("Paint Raindom")) {
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), rand() % 255, rand() % 255, rand() % 255);
						if (VEHICLE::GET_IS_VEHICLE_SECONDARY_COLOUR_CUSTOM(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID())))
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), rand() % 255, rand() % 255, rand() % 255);
					}
					if (Menu::Int("Armor", Amorr, 0, 4))
					{
						LSC(16, Amorr);
					}
					if (Menu::Int("Engine", Enginee, 0, 3))
					{
						LSC(11, Enginee);
					}
					if (Menu::Int("Break", Brake, 0, 3))
					{
						LSC(12, Brake);
					}
					if (Menu::Int("Spoiler", Spoilerr, 0, 6))
					{
						LSC(0, Spoilerr);
					}
					if (Menu::Int("Skirt", Skirtt, 0, 3))
					{
						LSC(3, Skirtt);
					}
					if (Menu::Int("Suspension", Suspensionn, 0, 3))
					{
						LSC(15, Suspensionn);
					}
					if (Menu::Int("Transmission", Transmission, 0, 3))
					{
						LSC(13, Transmission);
					}
					if (Menu::Int("Front Bumper", Bumperr, 0, 3))
					{
						LSC(1, Bumperr);
					}
					if (Menu::Int("Rear Bumper", Bumper2, 0, 3))
					{
						LSC(2, Bumper2);
					}
					if (Menu::Int("Exhaust", Exhaust, 0, 3))
					{
						LSC(4, Exhaust);
					}
					if (Menu::Int("Hood", Bonnet, 0, 3))
					{
						LSC(7, Bonnet);
					}
					if (Menu::Int("Rollcage", Rollcage, 0, 3))
					{
						LSC(5, Rollcage);
					}
					if (Menu::Int("Horn", Klaxonn, 0, 15))
					{
						LSC(14, Klaxonn);
					}
				}
				break;
#pragma endregion


				//pVWeapons 
				case ptfxshoot:
				{

					// Menu::Subtitle("PTFX WEAPON");
					Menu::Title("Effect Gun");
					Menu::Toggle("Shoot clown appears", Features::particlee1, [] { Features::ParticlEE1(Features::particlee1); });
					Menu::Toggle("Shoot trucks_crash", Features::particlee, [] { Features::ParticllE(Features::particlee); });
					Menu::Toggle("Shoot alien teleport", Features::particle3, [] { Features::ParticlE3(Features::particle3); });
					Menu::Toggle("Shoot sniper impact", Features::particle4, [] { Features::ParticlE4(Features::particle4); });
					Menu::Toggle("Shoot banknotes", Features::particle5, [] { Features::ParticlE5(Features::particle5); });
					Menu::Toggle("Shoot Blood", Features::particle6, [] { Features::ParticlE6(Features::particle6); });
					Menu::Toggle("Shoot Firework", Features::particle7, [] { Features::ParticlE7(Features::particle7); });
					Menu::Toggle("Shoot Water Splash", Features::particle8, [] { Features::ParticlE8(Features::particle8); });
					// hmm soweit stimmt alles war das sicher das einzige ? warte, ich überlege
				}
				break;

				//VWeapons 
				case Vehicleguns:
				{
					// Menu::Subtitle("VEHICLE SHOOTER");
					Menu::Title("Vehicle Guns");
					if (Menu::StringVector("1.46 DLC Vehicles", Arenawars, soutprop34)) {
						Features::selectShootVeh = Arenawars[soutprop34];
					}
					if (Menu::StringVector("1.44 DLC Vehicles", Afterhours1, soutprop30)) {
						Features::selectShootVeh = Afterhours1[soutprop30];
					}

					Menu::Toggle("Toggle", Features::vehGunBool);
					Menu::Toggle("Shoot Titan", Features::TITAN, [] { Features::TITANT(Features::TITAN); });
					Menu::Toggle("Shoot AMBULANCE", Features::AMBUL, [] { Features::AMBULANCE(Features::AMBUL); });
					Menu::Toggle("Shoot SHAMAL", Features::SHAMAL, [] { Features::SHAM(Features::SHAMAL); });
					Menu::Toggle("Shoot to Vehicle", Features::Testgun, [] { Features::testgun(Features::Testgun); });
					Menu::Toggle("Shoot Hydra", Features::ShootHydra, [] { Features::Shootthehydra(Features::ShootHydra); });
					Menu::Toggle("Shoot Dump Truck", Features::ShootDump, [] { Features::ShootDumpTruck(Features::ShootDump); });
					Menu::Toggle("Shoot Buzzard", Features::ShootBuz, [] { Features::ShootBuzzard(Features::ShootBuz); });
					Menu::Toggle("Shoot Zentorno", Features::ShootZen, [] { Features::ShootZentorno(Features::ShootZen); });
					Menu::Toggle("Shoot Swift", Features::ShootSWI, [] { Features::ShootSWIFT(Features::ShootSWI); });
					Menu::Toggle("Vehicle Gun", Features::Vehgun, [] { Features::vehgun(Features::Vehgun); });
					Menu::Toggle("Shoot Afterhours Vehicles", Features::Vehgunafter, [] { Features::vehgunafter(Features::Vehgunafter); });

				}
				break;

				//SWeapons 
				case Giveweapon:
				{
					// Menu::Subtitle("GIVE WEAPONS");

					Menu::Title("GiveWweapon");

					if (Menu::Option("Give All ArenaWars Weapons")) {
						uint Weapons[] = { 0xAF3696A1, 0x476BF155, 0xB62D1F67 };
						for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
							WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), Weapons[i], 9999, 1);
						}
					}

					if (Menu::Option("~w~Unlock Upatomizer Skin"))
					{
						unlockUpAtomizerSkin();

					}
					if (Menu::Option("Give All Weapons")) {
						uint Weapons[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D, 0xAF3696A1, 0x476BF155, 0xB62D1F67 };
						for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
							WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), Weapons[i], 9999, 1);
						}
					}
					if (Menu::Option("Give All MK2 Upgrades")) {
						std::vector<Hash> pistolMk2{
						   1329061674, 2396306288, 1140676955, 1709866683, 568543123, 2467084625
						};
						std::vector<Hash> smgMk2{
						   190476639, 2076495324, 2681951826, 3842157419, 1038927834, 1303784126, 2774849419, 966612367
						};
						std::vector<Hash> assltRifleMk2{
						   1675665560, 2640679034, 2076495324, 1108334355, 77277509, 3328927042, 2805810788, 1303784126, 1447477866, 3115408816
						};
						std::vector<Hash> carbineRifleMk2{
						   1141059345, 2640679034, 2076495324, 1108334355, 77277509, 3328927042, 2205435306, 1303784126, 2335983627, 3663056191
						};
						std::vector<Hash> combatMgMk2{
						   1475288264, 2640679034, 1108334355, 1060929921, 3328927042, 1303784126, 3051509595, 3607349581
						};
						std::vector<Hash> heavySniperMk2{
						   2313935527, 2193687427, 3159677559, 3061846192, 776198721, 2890063729, 1764221345, 277524638, 1815270123
						};

						std::vector<Hash> WeaponHash{
						   0xBFE256D4, 0x78A97CD0, 0xDBBD7280, 0x394F415C, 0xFAD1F1C9, 0xA914799
						};


						for (Hash hash : pistolMk2)
							WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), hash);

						for (Hash hash : smgMk2)
							WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), hash);

						for (Hash hash : assltRifleMk2)
							WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), hash);

						for (Hash hash : carbineRifleMk2)
							WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), hash);

						for (Hash hash : combatMgMk2)
							WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), hash);

						for (Hash hash : heavySniperMk2)
							WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), hash);

						for (Hash hash : WeaponHash)
							WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hash, 9999, 0);
					}
					if (Menu::Option("Give DIGISCANNER")) {
						uint Weapons[] = { 0xFDBADCED,4256881901 };
						for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
							WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), Weapons[i], 9999, 1);
						}
					}
					if (Menu::Option("Give Stungun")) {
						uint Weapons[] = { 0x3656C8C1,911657153 };
						for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
							WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), Weapons[i], 9999, 1);
						}
					}
					if (Menu::Option("Give Fireextinuisher")) {
						uint Weapons[] = { 0x060EC506,101631238 };
						for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
							WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), Weapons[i], 9999, 1);
						}
					}
				}
				break;

				//GWeapons 
				case Shootguns:
				{
					// Menu::Subtitle("SPECIAL GUNS");

					Menu::Title("Shoot Guns");

					Menu::Toggle("Shoot Molotov", Features::MOLOTOV, [] { Features::molotov(Features::MOLOTOV); });
					//Menu::Toggle("~w~Shoot BALL", Features::BALL, [] { Features::ball(Features::BALL); });
					Menu::Toggle("Shoot RPG", Features::RPG, [] { Features::rpg(Features::RPG); });
					Menu::Toggle("Shoot Grenades", Features::Grenade, [] { Features::grenade(Features::Grenade); });
					Menu::Toggle("Shoot Smoke Grenades", Features::Smoke, [] { Features::smoke(Features::Smoke); });
					Menu::Toggle("Shoot flamethrower", Features::Flare, [] { Features::flare(Features::Flare); });
					Menu::Toggle("Shoot Red Laser", Features::leagun, [] { Features::leaWgun(Features::leagun); });
					Menu::Toggle("Shoot Green Laser", Features::Raser, [] { Features::raser(Features::leagun); });
					Menu::Toggle("Cartoon Gun", Features::CLOWNGUN, [] { Features::clowngun(Features::CLOWNGUN); });
					Menu::Toggle("Money Gun", Features::moneyGun, [] { Features::MoneyGun(Features::moneyGun); });
					Menu::Toggle("Fake Money Gun", Features::Fake, [] { Features::fake(Features::Fake); });
				}
				break;

				//GWeapons 
				case Wmods:
				{
					// Menu::Subtitle("WEAPON MODS");

					Menu::Title("Weapon Mods");

					Menu::Toggle("Airstrike Gun", Features::Air, [] { Features::air(Features::Air); });
					Menu::Toggle("Valkyire Rocket", Features::VALKYIREROCKET, [] { Features::valkyirerocket(Features::VALKYIREROCKET); });
					Menu::Toggle("Trigger Bot", Features::Trigger, [] { Features::TriggerAim(Features::Trigger); });
					Menu::Toggle("Aimbot", Features::Aimbot, [] { Features::aimbot(Features::Aimbot); });
					Menu::Toggle("Infinite Ammo", Features::infammo, [] { Features::noreloadv(Features::infammo); });
					Menu::Toggle("Asteroid Gun", Features::Weapontest, [] { Features::weapontest(Features::Weapontest); });
					Menu::Toggle("Rainbow Gun", Features::rbgun, [] { Features::RBGuner(Features::rbgun); });
					Menu::Toggle("\"One shot, one kill, you never saw it coming.\"", Features::osk, [] { Features::OSKR(Features::osk); });
					Menu::Toggle("Gravity Gun", Features::GravityGun, [] { Features::gravitygun(Features::GravityGun); });
					Menu::Toggle("Gravity Gun [x2]", Features::GravGun);
					Menu::Toggle("Delete Gun", Features::delgun, [] { Features::DelGun(Features::delgun); });
					Menu::Toggle("Water Gun", Features::waterGun, [] { Features::WaterGun(Features::waterGun); });
					Menu::Toggle("Rapid Fire", Features::rapidfirer);
					Menu::Toggle("Ped Gun", Features::pedGun, [] { Features::PedGun(Features::pedGun); });
					Menu::Toggle("Fire Ammo", Features::fixfire, [] { Features::firefix(Features::fixfire); });
					Menu::Toggle("Explosive Ammo", Features::Penis, [] { Features::penis(Features::Penis); });
					Menu::Toggle("~w~Fire Types", Features::Explodegunn, [] { Features::explodegunn(Features::Explodegunn); });
					if (Menu::Int("Typ", Features::Explosionfick, 1, 38))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::Explosionfick = NumberKeyboard();
						}
					}



					if (Menu::Int("High", Features::ficksize, 1, 10))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::ficksize = NumberKeyboard();
						}
					}



				}
				break;



				//Weapons 
				case weapon:
				{
					// Menu::Subtitle("WEAPON");
					Menu::Title("WEAPON");
					Menu::MenuOption("Vehicle Weapons", Vehicleguns);
					Menu::MenuOption("Special Abilities", Shootguns);
					Menu::MenuOption("Give Weapons", Giveweapon);
					Menu::MenuOption("Weapon Mods", Wmods);
					Menu::Toggle("Fire Ammo", Features::fixfire, [] { Features::firefix(Features::fixfire); });
					Menu::Toggle("Infinite Ammo", Features::infammo, [] { Features::noreloadv(Features::infammo); });
					Menu::Toggle("Rapid Fire", Features::rapidfirer);
					Menu::Toggle("One Shot Kill", Features::osk, [] { Features::OSKR(Features::osk); });
				}
					break;


					//IPLsMenu::Toggle("Rainbow Weapon", Features::rbgun, [] { Features::RBGuner(Features::rbgun); });
				case ipl:
				{
					Menu::Title("IPLs");
					// Menu::Subtitle("IPLS");

					if (Menu::Option("North Yankton")) {
						STREAMING::REQUEST_IPL("prologue01");
						STREAMING::REQUEST_IPL("Prologue01c");
						STREAMING::REQUEST_IPL("Prologue01d");
						STREAMING::REQUEST_IPL("Prologue01e");
						STREAMING::REQUEST_IPL("Prologue01f");
						STREAMING::REQUEST_IPL("Prologue01g");
						STREAMING::REQUEST_IPL("prologue01h");
						STREAMING::REQUEST_IPL("prologue01i");
						STREAMING::REQUEST_IPL("prologue01j");
						STREAMING::REQUEST_IPL("prologue01k");
						STREAMING::REQUEST_IPL("prologue01z");
						STREAMING::REQUEST_IPL("prologue02");
						STREAMING::REQUEST_IPL("prologue03");
						STREAMING::REQUEST_IPL("prologue03b");
						STREAMING::REQUEST_IPL("prologue03_grv_cov");
						STREAMING::REQUEST_IPL("prologue03_grv_dug");
						STREAMING::REQUEST_IPL("prologue03_grv_fun");
						STREAMING::REQUEST_IPL("prologue04");
						STREAMING::REQUEST_IPL("prologue04b");
						STREAMING::REQUEST_IPL("prologue04_cover");
						STREAMING::REQUEST_IPL("prologue05");
						STREAMING::REQUEST_IPL("prologue05b");
						STREAMING::REQUEST_IPL("prologue06");
						STREAMING::REQUEST_IPL("prologue06b");
						STREAMING::REQUEST_IPL("prologue06_int");
						STREAMING::REQUEST_IPL("prologuerd");
						STREAMING::REQUEST_IPL("prologuerdb");
						STREAMING::REQUEST_IPL("prologue_DistantLights");
						STREAMING::REQUEST_IPL("prologue_grv_torch");
						STREAMING::REQUEST_IPL("prologue_m2_door");
						STREAMING::REQUEST_IPL("prologue_LODLights");
						STREAMING::REQUEST_IPL("DES_ProTree_start");
						Vector3 Coords;
						Coords.x = 3595.39673f; Coords.y = -4893.727f; Coords.z = 115.838394f;
						TPto(Coords);
					}
					if (Menu::Option("Porn Yacht")) {
						STREAMING::REQUEST_IPL("smboat");
						Vector3 Coords;
						Coords.x = -2045.8f; Coords.y = -1031.2f; Coords.z = 11.9f;
						TPto(Coords);
					}
					if (Menu::Option("Aircraft Carrier")) {
						STREAMING::REQUEST_IPL("hei_carrier");
						STREAMING::REQUEST_IPL("hei_carrier_DistantLights");
						STREAMING::REQUEST_IPL("hei_Carrier_int1");
						STREAMING::REQUEST_IPL("hei_Carrier_int2");
						STREAMING::REQUEST_IPL("hei_Carrier_int3");
						STREAMING::REQUEST_IPL("hei_Carrier_int4");
						STREAMING::REQUEST_IPL("hei_Carrier_int5");
						STREAMING::REQUEST_IPL("hei_Carrier_int6");
						STREAMING::REQUEST_IPL("hei_carrier_LODLights");
						Vector3 Coords;
						Coords.x = 3069.330f; Coords.y = -4632.4f; Coords.z = 15.043f;
						TPto(Coords);
					}
					if (Menu::Option("Sunken Cargoship")) {
						STREAMING::REQUEST_IPL("sunkcargoship");
						Vector3 Coords;
						Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 0.0f;
						TPto(Coords);
					}
					if (Menu::Option("Hospital")) {
						STREAMING::REQUEST_IPL("RC12B_HospitalInterior");
						STREAMING::REQUEST_IPL("RC12B_Destroyed");
						Vector3 Coords;
						Coords.x = 356.8f; Coords.y = -590.1f; Coords.z = 43.3f;
						TPto(Coords);
					}
					if (Menu::Option("Oneil Farm")) {
						STREAMING::REMOVE_IPL("farm_burnt");
						STREAMING::REMOVE_IPL("farm_burnt_props");
						STREAMING::REQUEST_IPL("farm");
						STREAMING::REQUEST_IPL("farm_props");
						STREAMING::REQUEST_IPL("farmint");
						STREAMING::REQUEST_IPL("farmint_cap");
						Vector3 Coords;
						Coords.x = 2441.2f; Coords.y = 4968.5f; Coords.z = 51.7f;
						TPto(Coords);
					}
					if (Menu::Option("Life Invader Office")) {
						STREAMING::REQUEST_IPL("facelobby");
						STREAMING::REQUEST_IPL("facelobbyfake");
						Vector3 Coords;
						Coords.x = -1047.9f; Coords.y = -233.0f; Coords.z = 39.0f;
						TPto(Coords);
					}
					if (Menu::Option("Cargoship")) {
						STREAMING::REQUEST_IPL("cargoship");
						Vector3 Coords;
						Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 9.3192f;
						TPto(Coords);
					}
					if (Menu::Option("Jewelry Store")) {
						STREAMING::REQUEST_IPL("jewel2fake");
						STREAMING::REQUEST_IPL("post_hiest_unload");
						STREAMING::REQUEST_IPL("bh1_16_refurb");
						Vector3 Coords;
						Coords.x = -630.4f; Coords.y = -236.7f; Coords.z = 40.0f;
						TPto(Coords);
					}
					if (Menu::Option("Morgue")) {
						STREAMING::REQUEST_IPL("Coroner_Int_on");
						Vector3 Coords;
						Coords.x = 244.9f; Coords.y = -1374.7f; Coords.z = 39.5f;
						TPto(Coords);
					}

				}
				break;

				case dropOnline22:
				{
					Menu::Title("Cyrcle Drop");
					// Menu::Subtitle("CIRCLE DROP");

					if (selecArrow) {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
						GRAPHICS::DRAW_MARKER(29, coords.x, coords.y, coords.z + 1.3f, 0, 0, 0, 0, 180, 0, 1, 1, 1, 0, 255, 255, 200, 1, 1, 1, 0, 0, 0, 0);
					}
					Menu::Toggle("Cyrcle Drop", Features::cyrclenew, [] { Features::CyrcleNew(Features::cyrclenew); });
					if (Menu::Int("Amount", Features::DropAmount, 1, 2500))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::DropAmount = NumberKeyboard();
						}
					}


					if (Menu::Int("Height", Features::DropHeight, 1, 50))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::DropHeight = NumberKeyboard();
						}
					}


					if (Menu::Int("Delay", Features::DropDelay, 50, 1000))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::DropDelay = NumberKeyboard();
						}
					}


					Menu::Break("Models");
					dropModelsSelect();


				}
				break;

				case ptfxpp:
				{
					Menu::Title("~w~GuardCheats ~w~VIP");
					// Menu::Subtitle("PTFX");

					Menu::Float("~w~PTFX Scale", Menu::Settings::bulletp, 0.f, 10.f);

					Menu::Toggle("Lightning", Features::moneyeffect);
					Menu::Toggle("Clown Effects", Features::ClownLoop);
					Menu::Toggle("Firework", Features::fireworkloop);
					Menu::Toggle("Alien 1", Features::alien1);
					Menu::Toggle("Alien 2", Features::alien2);
					Menu::Toggle("Electric Boosh", Features::electricberox);
					Menu::Toggle("Water Splash", Features::watereffect);
					Menu::Toggle("Smoke", Features::smokeeffect);
					Menu::Toggle("Burial Dirt", Features::moneyeffect10);
					Menu::Toggle("~w~Ghost Rider", Features::ghosterr);

				}
				break;

				case ptfxveh:
				{
					Menu::Title("~w~PTFX Vehicle");
					// Menu::Subtitle("PTFX VEHICLE");

					Menu::Toggle("Lightning", Features::CarLightning);
					Menu::Toggle("Clown Effects", Features::CarClownLoop);
					Menu::Toggle("Firework", Features::Carfireworkloop);
					Menu::Toggle("Alien 1", Features::Caralien1);
					Menu::Toggle("Alien 2", Features::Caralien2);
					Menu::Toggle("Electric", Features::Carelectric);
					Menu::Toggle("Burial Dirt", Features::moneyeffect15);


				}
				break;

				case landmarks:
				{

					Menu::Title("LANDMARKS");
					// Menu::Subtitle("LANDMARKS");
					if (Menu::Option("Aircraft Carrier")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 3084.7302f, -4770.709f, 15.2617f);
					}
					if (Menu::Option("Airport Runway")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -1336.000f, -3044.000f, 13.9393f);
					}
					if (Menu::Option("Altruist Cult Camp")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -1170.840f, 4926.6460f, 224.2953f);
					}
					if (Menu::Option("Calafia Train Bridege")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -517.8690f, 4425.2842f, 89.7951f);
					}
					if (Menu::Option("Cargo Ship")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 899.6780f, -2882.190f, 19.0130f);
					}
					if (Menu::Option("Chumash Pier")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -3426.683f, 967.7380f, 8.3468f);
					}
					if (Menu::Option("Dell Perro Pier")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -1850.127f, -1231.751f, 13.0172f);
					}
					if (Menu::Option("El Burro Heights")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 1384.0000f, -2057.100f, 51.9993f);
					}
					if (Menu::Option("Elysian Island")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 338.2000f, -2715.899f, 38.4785f);
					}
					if (Menu::Option("North San Andreas")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 24.7750f, 7644.1021f, 19.0559f);
					}
					if (Menu::Option("Ferris Wheel")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -1670.700f, -1125.000f, 13.0379f);
					}
					if (Menu::Option("Fort Zancudo")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -2047.400f, 3132.1001f, 32.8043f);
					}
					if (Menu::Option("Fort Zancudo Tower")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -2358.132f, 3249.7539f, 101.4508f);
					}
					if (Menu::Option("Jetsam")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 760.4000f, -2943.200f, 5.8004f);
					}
					if (Menu::Option("Ghost 23:00am")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 3059.6201f, 5564.2461f, 197.0906f);
						NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(0, 0, 0);
					}
					if (Menu::Option("Merryweather Dock")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 486.4170f, -3339.691f, 6.0699f);
					}
					if (Menu::Option("Mount Chiliad")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 450.7180f, 5566.6138f, 806.1831f);
					}
					if (Menu::Option("Pacific Standart Bank")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 235.0460f, 216.4340f, 106.2869f);
					}
					if (Menu::Option("Police Station")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 436.4910f, -982.1720f, 30.6989f);
					}
					if (Menu::Option("Sandy Shores Airfiled")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 1747.0000f, 3273.7000f, 41.1277f);
					}
				}
				break;

				case Night:
				{
					// Menu::Subtitle("");

					Menu::Title("Nights");

					if (Menu::Option("Downtown Vinewood")) {
						Vector3 Coords;
						Coords.x = 373.260f; Coords.y = 254.730f; Coords.z = 102.954f;
						TPto(Coords);
					}
					if (Menu::Option("Vinewood Middle")) {
						Vector3 Coords;
						Coords.x = 7.939f; Coords.y = 218.331f; Coords.z = 107.607f;
						TPto(Coords);
					}
					if (Menu::Option("Del Perro")) {
						Vector3 Coords;
						Coords.x = -1289.758f; Coords.y = -647.775f; Coords.z = 26.573f;
						TPto(Coords);
					}
					if (Menu::Option("Vespucci")) {
						Vector3 Coords;
						Coords.x = -1164.017f; Coords.y = -1199.575f; Coords.z = 3.772f;
						TPto(Coords);
					}
					if (Menu::Option("Airport")) {
						Vector3 Coords;
						Coords.x = -664.626f; Coords.y = -2462.964f; Coords.z = 13.944;
						TPto(Coords);
					}
					if (Menu::Option("Strawberry")) {
						Vector3 Coords;
						Coords.x = 82.522f; Coords.y = -1298.378f; Coords.z = 29.293f;
						TPto(Coords);
					}
					if (Menu::Option("Cypress Flats")) {
						Vector3 Coords;
						Coords.x = 377.244f; Coords.y = -1111.520f; Coords.z = 29.406f;
						TPto(Coords);
					}
					if (Menu::Option("La Mesa")) {
						Vector3 Coords;
						Coords.x = 784.305f; Coords.y = -1279.764f; Coords.z = 26.358f;
						TPto(Coords);
					}
					if (Menu::Option("Misson Row")) {
						Vector3 Coords;
						Coords.x = 865.235f; Coords.y = -2094.451f; Coords.z = 30.241f;
						TPto(Coords);
					}
					if (Menu::Option("Elysian Island")) {
						Vector3 Coords;
						Coords.x = 188.878f; Coords.y = -3161.526f; Coords.z = 5.787f;
						TPto(Coords);
					}
				}
				break;

				case safehouses:
				{

					Menu::Title("SAFEHOUSES");
					// Menu::Subtitle("SAFE HOUSES");
					if (Menu::Option("Michaels House")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -813.6030f, 179.4740f, 72.1572f);
					}
					if (Menu::Option("Franklins House1")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 7.1190f, 536.6150f, 176.0280f);
					}
					if (Menu::Option("Franklins House2")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -14.3803f, -1483.510f, 31.1044f);
					}
					if (Menu::Option("Trevors House1")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 1972.6100f, 3817.0400f, 33.4283f);
					}
					if (Menu::Option("Trevors House2")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -1151.770f, 1518.140f, 10.6327f);
					}
					if (Menu::Option("Trevors Office")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 97.2707f, -1290.994f, 29.2688f);
					}
				}
				break;

				case underwater:
				{

					Menu::Title("UNDERWATER");
					// Menu::Subtitle("UNDERWATER");
					if (Menu::Option("Hatch")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 4274.2334f, 2975.4146f, -169.5375f);
					}
					if (Menu::Option("Sea Monster")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -3373.730f, 504.7139f, -23.7034f);
					}
					if (Menu::Option("Sunken Body")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -3161.077f, 3001.9915f, -36.8034f);
					}
					if (Menu::Option("Sunken Plane")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -942.3652f, 6608.7627f, -19.5568f);
					}
					if (Menu::Option("Tank")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 4201.6323f, 3643.8167f, -37.6158f);
					}
					if (Menu::Option("Humane Labs Tunnel")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 3838.4746f, 3673.0667f, -18.8467f);
					}
					if (Menu::Option("UFO")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 762.4217f, 7380.3682f, -110.3537f);
					}
				}
				break;

				case StandardLocation:
				{
					Menu::Title("Weather Options");
					// Menu::Subtitle("STANDARD LOCATIONS");

					if (Menu::Option("Ghost 23:00am")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 3059.6201f, 5564.2461f, 197.0906f);
						NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(0, 0, 0);
					}

					if (Menu::Option("Bridge")) {
						Vector3 Coords;
						Coords.x = -556.794f; Coords.y = -2244.583f; Coords.z = 124.003f;
						TPto(Coords);
					}
					if (Menu::Option("High crane")) {
						Vector3 Coords;
						Coords.x = -171.701f; Coords.y = -1003.840f; Coords.z = 296.206f;
						TPto(Coords);
					}
					if (Menu::Option("graveyard")) {
						Vector3 Coords;
						Coords.x = -1724.513f; Coords.y = -192.559f; Coords.z = 60.092f;
						TPto(Coords);
					}
					if (Menu::Option("miniature golf")) {
						Vector3 Coords;
						Coords.x = -1335.633f; Coords.y = -59.032f; Coords.z = 55.245f;
						TPto(Coords);
					}
					if (Menu::Option("railway tunnel")) {
						Vector3 Coords;
						Coords.x = -796.434f; Coords.y = -129.138f; Coords.z = 20.199f;
						TPto(Coords);
					}
					if (Menu::Option("Construction site crane")) {
						Vector3 Coords;
						Coords.x = -473.127f; Coords.y = -961.945f; Coords.z = 69.712f;
						TPto(Coords);
					}
					if (Menu::Option("training area")) {
						Vector3 Coords;
						Coords.x = -1250.207f; Coords.y = -1595.640f; Coords.z = 4.093f;
						TPto(Coords);
					}
					if (Menu::Option("Beach rocks")) {
						Vector3 Coords;
						Coords.x = -1490.086f; Coords.y = -1479.924f; Coords.z = 3.238f;
						TPto(Coords);
					}
					if (Menu::Option("Mount Chiliad")) {
						Vector3 Coords;
						Coords.x = 496.75f; Coords.y = 5591.17f; Coords.z = 795.03f;
						TPto(Coords);
					}
					if (Menu::Option("Maze Bank")) {
						Vector3 Coords;
						Coords.x = -74.94243f; Coords.y = -818.63446f; Coords.z = 326.174347f;
						TPto(Coords);
					}
					if (Menu::Option("Military Base")) {
						Vector3 Coords;
						Coords.x = -2012.8470f; Coords.y = 2956.5270f; Coords.z = 32.8101f;
						TPto(Coords);
					}
					if (Menu::Option("Zancudo Tower")) {
						Vector3 Coords;
						Coords.x = -2356.0940; Coords.y = 3248.645; Coords.z = 101.4505;
						TPto(Coords);
					}
					if (Menu::Option("Mask Shop")) {
						Vector3 Coords;
						Coords.x = -1338.16; Coords.y = -1278.11; Coords.z = 4.87;
						TPto(Coords);
					}
					if (Menu::Option("LS Customs")) {
						Vector3 Coords;
						Coords.x = -373.01; Coords.y = -124.91; Coords.z = 38.31;
						TPto(Coords);
					}
					if (Menu::Option("Ammunation")) {
						Vector3 Coords;
						Coords.x = 247.3652; Coords.y = -45.8777; Coords.z = 69.9411;
						TPto(Coords);
					}
					if (Menu::Option("Airport")) {
						Vector3 Coords;
						Coords.x = -1102.2910f; Coords.y = -2894.5160f; Coords.z = 13.9467f;
						TPto(Coords);
					}
					if (Menu::Option("Clothes Store")) {
						Vector3 Coords;
						Coords.x = -718.91; Coords.y = -158.16; Coords.z = 37.00;
						TPto(Coords);
					}
					if (Menu::Option("Waterfall")) {
						Vector3 Coords;
						Coords.x = -597.9525f; Coords.y = 4475.2910f; Coords.z = 25.6890f;
						TPto(Coords);
					}
					if (Menu::Option("FBI")) {
						Vector3 Coords;
						Coords.x = 135.5220f; Coords.y = -749.0003f; Coords.z = 260.0000f;
						TPto(Coords);
					}
					if (Menu::Option("Human Labs")) {
						Vector3 Coords;
						Coords.x = 3617.231f; Coords.y = 3739.871f; Coords.z = 28.6901f;
						TPto(Coords);
					}
					if (Menu::Option("MMI")) {
						Vector3 Coords;
						Coords.x = -222.1977; Coords.y = -1185.8500; Coords.z = 23.0294;
						TPto(Coords);
					}
					if (Menu::Option("Sandy Shores Airfield")) {
						Vector3 Coords;
						Coords.x = 1741.4960f; Coords.y = 3269.2570f; Coords.z = 41.6014f;
						TPto(Coords);
					}
					if (Menu::Option("Mort Mutual Insurance")) {
						Vector3 Coords;
						Coords.x = -221.749908f; Coords.y = -1158.249756f; Coords.z = 23.040998f;
						TPto(Coords);
					}
					if (Menu::Option("Bennys Garage")) {
						Vector3 Coords;
						Coords.x = -196.349442f; Coords.y = -1303.103271f; Coords.z = 30.650515f;
						TPto(Coords);
					}
					if (Menu::Option("Strip Club")) {
						Vector3 Coords;
						Coords.x = 135.548096f; Coords.y = -1308.388306f; Coords.z = 28.344141f;
						TPto(Coords);
					}
					if (Menu::Option("Darts")) {
						Vector3 Coords;
						Coords.x = 1997.273071f; Coords.y = 3062.091309f; Coords.z = 46.789749f;
						TPto(Coords);

					}
					if (Menu::Option("Rockford Hills")) {
						Vector3 Coords;
						Coords.x = -1365.342163f; Coords.y = -114.440826f; Coords.z = 50.704300f;
						TPto(Coords);

					}
					if (Menu::Option("Ponsonbys")) {
						Vector3 Coords;
						Coords.x = -1460.654419f; Coords.y = -227.550964f; Coords.z = 48.728519f;
						TPto(Coords);

					}
				}
				break;

				case TowerLocation:
				{
					Menu::Title("Weather Options");
					// Menu::Subtitle("TOWER LOCATIONS");

					if (Menu::Option("Secret Army Tower")) {
						Vector3 Coords;
						Coords.x = -2358.946045f; Coords.y = 3252.216797f; Coords.z = 101.450424f;
						TPto(Coords);
					}
					if (Menu::Option("Eclipse Tower Apartment")) {
						Vector3 Coords;
						Coords.x = -810.110901f; Coords.y = 300.467865f; Coords.z = 86.118515f;
						TPto(Coords);
					}
					if (Menu::Option("Tinsel Tower Apartment")) {
						Vector3 Coords;
						Coords.x = -641.864624f; Coords.y = 24.014740f; Coords.z = 39.351025f;
						TPto(Coords);
					}
					if (Menu::Option("Maze Tower")) {
						Vector3 Coords;
						Coords.x = -73.92588f; Coords.y = -818.455078f; Coords.z = 326.174377f;
						TPto(Coords);
					}
					if (Menu::Option("Construction Tower")) {
						Vector3 Coords;
						Coords.x = -143.881927f; Coords.y = -984.810852f; Coords.z = 269.134308f;
						TPto(Coords);
					}
					if (Menu::Option("Clock Tower")) {
						Vector3 Coords;
						Coords.x = -1238.675537f; Coords.y = -847.954590f; Coords.z = 85.161690f;
						TPto(Coords);
					}
					if (Menu::Option("Sniper Tower")) {
						Vector3 Coords;
						Coords.x = -550.989380f; Coords.y = -193.862366f; Coords.z = 76.499336f;
						TPto(Coords);
					}
					if (Menu::Option("Prison Tower")) {
						Vector3 Coords;
						Coords.x = 1541.6290f; Coords.y = 2470.1400f; Coords.z = 62.8751f;
						TPto(Coords);
					}
					if (Menu::Option("Creek(Mountain Tower)")) {
						Vector3 Coords;
						Coords.x = 2784.6060f; Coords.y = 6000.8770f; Coords.z = 357.2007f;
						TPto(Coords);
					}
					if (Menu::Option("Eclipse Towers")) {
						Vector3 Coords;
						Coords.x = -773.351990f; Coords.y = 309.809235f; Coords.z = 85.699196f;
						TPto(Coords);
					}
					if (Menu::Option("Tinsel Towers")) {
						Vector3 Coords;
						Coords.x = -641.864624f; Coords.y = 24.014740f; Coords.z = 39.351025f;
						TPto(Coords);
					}
					if (Menu::Option("Zancudo Tower")) {
						Vector3 Coords;
						Coords.x = -2356.0940; Coords.y = 3248.645; Coords.z = 101.4505;
						TPto(Coords);
					}
				}
				break;

				//Teleport 
				case teleports:
				{
					Menu::Title("Weather Options");
					// Menu::Subtitle("TELEPORTATION");
					Menu::Toggle("Free Cam teleport", Features::freeT, [] { Features::freeCamt(Features::freeT); });

					Menu::MenuOption("Popular", Night);
					Menu::MenuOption("IPLs", ipl);
					Menu::MenuOption("Shops ", shops);
					Menu::MenuOption("Standard Location", StandardLocation);
					Menu::MenuOption("Tower Location", TowerLocation);
					Menu::MenuOption("Underwater Locations", underwater);
					Menu::MenuOption("Safehouses ", safehouses);
					Menu::MenuOption("Landmarks ", landmarks);
					Menu::MenuOption("High Altitude ", highaltitude);




					Menu::Title("Teleport Locations");

					if (Menu::Option("Teleport to Waypoint")) {
						Features::teleportToWaypoint();

					}

				}
				break;













				//World 
				case weatheroptions:
				{
					Menu::Title("Weather Options");
					// Menu::Subtitle("WORLD");

					if (Menu::Option("~y~Random Weather")) {
						GAMEPLAY::SET_RANDOM_WEATHER_TYPE();
					}

					if (Menu::Option("Sun")) {

						GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clear");

						notifyMap("~w~Sunny weather");

					}

					if (Menu::Option("Rain")) {

						GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clearing");

						notifyMap("~w~Rainy weather");

					}

					if (Menu::Option("Snow")) {

						GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Snowlight");

						notifyMap("~w~It's snowing");

					}

					if (Menu::Option("Thunder")) {

						GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Thunder");

						notifyMap("~w~Its storming");

					}

					if (Menu::Option("Blizzard")) {

						GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Blizzard");

						notifyMap("~w~Blizzard");

					}

					if (Menu::Option("Overcast weather")) {

						GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Overcast");

						notifyMap("~w~Overcast weather");

					}

					if (Menu::Option("Foggy")) {

						GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Foggy");

						notifyMap("~w~It is foggy");

					}

					if (Menu::Option("Smog")) {

						GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Smog");

						notifyMap("~w~Dirty air");

					}

					if (Menu::Option("Clouds")) {

						GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clouds");

						notifyMap("~w~Cloudy weather");

					}

					if (Menu::Option("Halloween")) {

						GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("halloween");

						notifyMap("~w~Creepy weather");

					}

					if (Menu::Option("Xmas")) {
						GAMEPLAY::SET_WEATHER_TYPE_NOW("XMAS");
					}

					Menu::Break("Change intensity");

					if (Menu::Int("~g~Waves Intensity", Features::WaterIntense, 0, 100)) {
						WATER::_SET_CURRENT_INTENSITY(Features::WaterIntense);

					}
					if (Menu::Int("Rain Intensity", RainIntensity, 0, 100)) {
						GAMEPLAY::_SET_RAIN_FX_INTENSITY(RainIntensity);
					}
					if (Menu::Int("Cloud Opacity", wind, 0, 100)) {
						GAMEPLAY::_SET_CLOUD_HAT_OPACITY(cloud);
					}
					if (Menu::Int("wind Intensity", wind, 0, 100)) {
						GAMEPLAY::SET_WIND_SPEED(wind);
					}
					if (Menu::Option("Create Lighting")) {
						GAMEPLAY::_CREATE_LIGHTNING_THUNDER();
					}

					Menu::Toggle("Loop Lighting", Features::Light, [] { Features::light(Features::Light); });


					/*if (Menu::Option("Sun")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clear"); }
					if (Menu::Option("Rain")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clearing"); }
					if (Menu::Option("Snow")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Snowlight"); }
					if (Menu::Option("Thunder")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Thunder"); }
					if (Menu::Option("Blizzard")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Blizzard"); }
					if (Menu::Option("Overcast")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Overcast"); }
					if (Menu::Option("Foggy")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Foggy"); }
					if (Menu::Option("Smog")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Smog"); }
					if (Menu::Option("Clouds")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clouds"); }
					if (Menu::Option("halloween")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("halloween"); }*/

				}
				break;

				case sessweather:
				{

					Menu::Title("sessweather");
					// Menu::Subtitle("SESSION WEATHER");

					if (Menu::Option("Sunny")) {


						SCRIPT::SET_PLAYER_WEATHER(1, 1, 76, 0);
					}

					if (Menu::Option("Clear")) {
						SCRIPT::SET_PLAYER_WEATHER(1, 2, 76, 0);
					}

					if (Menu::Option("Clearing 1")) {
						SCRIPT::SET_PLAYER_WEATHER(1, 3, 76, 0);
					}

					if (Menu::Option("Clearing 2")) {
						SCRIPT::SET_PLAYER_WEATHER(1, 4, 76, 0);
					}
					if (Menu::Option("Cloudy")) {
						SCRIPT::SET_PLAYER_WEATHER(1, 5, 76, 0);
					}
					if (Menu::Option("Rain")) {
						SCRIPT::SET_PLAYER_WEATHER(1, 6, 76, 0);
					}
					if (Menu::Option("Thunder")) {
						SCRIPT::SET_PLAYER_WEATHER(1, 7, 76, 0);
					}
					if (Menu::Option("Light Rain")) {
						SCRIPT::SET_PLAYER_WEATHER(1, 8, 76, 0);
					}
					if (Menu::Option("Polluted Rain")) {
						SCRIPT::SET_PLAYER_WEATHER(1, 9, 76, 0);
					}
					if (Menu::Option("Light Snow")) {
						SCRIPT::SET_PLAYER_WEATHER(1, 10, 76, 0);
					}
					if (Menu::Option("Snow")) {
						SCRIPT::SET_PLAYER_WEATHER(1, 11, 76, 0);
					}
					if (Menu::Option("Light Snow")) {
						SCRIPT::SET_PLAYER_WEATHER(1, 12, 76, 0);
					}
					if (Menu::Option("XMAS Snow")) {
						SCRIPT::SET_PLAYER_WEATHER(1, 13, 76, 0);
					}
					if (Menu::Option("Helloween")) {
						SCRIPT::SET_PLAYER_WEATHER(1, 14, 76, 0);
					}
					if (Menu::Option("Black Weather")) {
						SCRIPT::SET_PLAYER_WEATHER(1, 15, 76, 0);
					}

				}
				break;

				case shops:
				{

					Menu::Title("SHOPS");
					// Menu::Subtitle("SHOPS");
					if (Menu::Option("Ammunation")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 247.3652f, -45.8777f, 69.9411f);
					}
					if (Menu::Option("Barber Shop")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -1293.231f, -1117.002f, 6.6402f);
					}
					if (Menu::Option("Bennys")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -205.3417f, -1305.824f, 31.3527f);
					}
					if (Menu::Option("LSC")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -367.7336f, -130.8588f, 38.6772f);
					}
					if (Menu::Option("Clothing Shop")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -159.2996f, -304.3292f, 39.7333f);
					}
					if (Menu::Option("Tattoo Shop")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 319.7877f, 172.2311f, 103.7454f);
					}
				}
				break;

				case onlinerealated:
				{
					Menu::Title("ONLINE RELATED");
					// Menu::Subtitle("ONLINE LOCATIONS");

					if (Menu::Option("10 Car Garage")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 229.3382f, -992.9117f, -98.9999f);
					}
					if (Menu::Option("6 Car Garage")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 197.8153f, -1002.293f, -99.0004f);
					}
					if (Menu::Option("2 Car Garage")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 173.2904f, -1003.600f, -98.9999f);
					}
					if (Menu::Option("Impound Lot")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 391.4746f, -1637.975f, 29.3148f);
					}
					if (Menu::Option("LSPD Char Creator")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 402.6675f, -1003.000f, -99.0040f);
					}
					if (Menu::Option("Mission Carpark")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 405.9359f, -954.0912f, -99.0041f);
					}
					if (Menu::Option("Mors Mutuals")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -222.1977f, -1185.850f, 23.0294f);
					}
				}
				break;

				case highaltitude:
				{

					Menu::Title("HIGH ALTITUDE");
					// Menu::Subtitle("HIGH PLACES");
					if (Menu::Option("Crane Top")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -119.8790f, -977.3570f, 304.2491f);
					}
					if (Menu::Option("FIB Building Roof")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 150.1260f, -754.5910f, 262.8650f);
					}
					if (Menu::Option("Galileo Roof")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -438.8040f, 1076.0970f, 352.4106f);
					}
					if (Menu::Option("IAA Building Roof")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 134.0850f, -637.8590f, 262.8510f);
					}
					if (Menu::Option("Maze Bank Roof")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -75.0150f, -818.2150f, 326.1757f);
					}
					if (Menu::Option("Satellite Dish")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 2034.9880f, 2953.1050f, 74.6007f);
					}
					if (Menu::Option("UFO (Fort Zacudo)")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), -2052.000f, 3237.0000f, 1456.9756f);
					}
					if (Menu::Option("Windmill Top")) {
						PED::SET_PED_COORDS_KEEP_VEHICLE(PLAYER::PLAYER_PED_ID(), 2026.6754f, 1824.6824f, 133.3133f);
					}
				}
				break;

				case VehWeapon:
				{
					Menu::Title("Vehicle Weapons");
					// Menu::Subtitle("VEHICLE WEAPONS");

					Menu::Toggle("Shoot Rockets", Features::ShootR, [] { Features::ShootRocket(Features::ShootR); });
					Menu::Toggle("Shoot FireWorks", Features::ShootT, [] { Features::ShootTanks(Features::ShootT); });
					Menu::Toggle("Shoot Tank Rounds", Features::ShootTankR, [] { Features::ShootTankRounds(Features::ShootTankR); });
					Menu::Toggle("Shoot Balls", Features::ShootBall, [] { Features::ShootBalls(Features::ShootBall); });
					Menu::Toggle("Shoot flamethrower", Features::ShootFlare, [] { Features::Shootflare(Features::ShootFlare); });
					Menu::Toggle("Shoot Bullet", Features::ShootMini, [] { Features::ShootMiniGun(Features::ShootMini); });
					Menu::Toggle("Shoot Green Laser", Features::Laser, [] { Features::laser(Features::Laser); });
					Menu::Toggle("Shoot Red Laser", Features::Raser, [] { Features::raser(Features::Raser); });

				}
				break;

				//Misc Options 
				case misc:
				{
					Menu::Title("World Options");
					// Menu::Subtitle("MISC");

					Menu::MenuOption("Bodyguards", Pedss);
					Menu::MenuOption("World", weatheroptions);
					Menu::Toggle("Kill Peds", Features::killpedsbool);
					Menu::Toggle("Explode Peds", Features::explodepedsbool);
					Menu::Toggle("Explode Cars", Features::explodenearbyvehiclesbool);
					Menu::Toggle("destroy tire", Features::explodenearbytiresbool, [] { Features::explodenearbytires(Features::explodenearbytiresbool); });
					Menu::Toggle("Make cars sound", Features::hornnearbyvehiclesbool, [] { Features::hornnearbyvehicles(Features::hornnearbyvehiclesbool); });
					Menu::Toggle("Delete Cars", Features::deletenearbyvehiclesbool);
					Menu::Toggle("Freeze Time", Features::Freezetime, [] { Features::freezetime(Features::Freezetime); });
					if (Menu::Toggle("Moon Gravity", MoonGravity)) {
						GAMEPLAY::SET_GRAVITY_LEVEL(MoonGravity ? 2 : 0);
					}



					//Menu::Int("~w~Set Vehicle Speed", Features::timeerlevelc, 0, 24, [] { Features::settimechangc(Features::timeerlevelc); });

					Menu::Int("~w~Set Time", Features::timeerlevel, 0, 24, [] { Features::settimechang(Features::timeerlevel); });

					//if (Menu::Float("Camera Zoom", Features::gameCamZoomInt, 0.0f, 100.0f)) { Features::gameCamZoom = true; }

					if (Menu::Option("Rapair near Vehicles")) {

						Features::repairnearbyvehicles();

						notifyMap("Rapair near Vehicles Active");


					}





				}
				break;

				case worldoptions:
				{
					Menu::MenuOption("Weather", weatheroptions);

				}
				break;

				case Vehcolor:
				{
					Menu::Title("~w~All Players");
					// Menu::Subtitle("VEHICLE COLOUR CHANGER");

					Menu::Break(" PRIMARY Color");

					Menu::Toggle("Enable Primary", Features::Color, [] { Features::color(Features::Color); });


					if (Menu::Int("~r~Red", Features::rbr, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::rbr = NumberKeyboard();
						}
					}

					if (Menu::Int("~g~Green", Features::rbd, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::rbd = NumberKeyboard();
						}
					}

					if (Menu::Int("~b~Blue", Features::rbs, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::rbs = NumberKeyboard();
						}
					}

					Menu::Break(" SECONDARY Color");

					Menu::Toggle("Enable Secondary", Features::Colorr, [] { Features::colorr(Features::Colorr); });

					if (Menu::Int("~r~Red", Features::rbrr, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::rbrr = NumberKeyboard();
						}
					}

					if (Menu::Int("~g~Green", Features::rbdd, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::rbdd = NumberKeyboard();
						}
					}

					if (Menu::Int("~b~Blue", Features::rbss, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::rbss = NumberKeyboard();
						}
					}

					Menu::Break(" Smoke Color");

					Menu::Toggle("Enable Smoke", Features::Colorrr, [] { Features::colorrr(Features::Colorrr); });

					if (Menu::Int("~r~Red", Features::rbrrr, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::rbrrr = NumberKeyboard();
						}
					}

					if (Menu::Int("~g~Green", Features::rbddd, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::rbddd = NumberKeyboard();
						}
					}

					if (Menu::Int("~b~Blue", Features::rbsss, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::rbsss = NumberKeyboard();
						}
					}

				}
				break;

				case espcolor:
				{
					Menu::Title("~w~All Players");
					// Menu::Subtitle("ESP");

					Menu::Toggle("ESP", Features::esper, [] {});

					Menu::Break(" Color Changer");


					if (Menu::Int("~r~Red", Features::espr, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::espr = NumberKeyboard();
						}
					}
					if (Menu::Int("~g~Green", Features::espg, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::espg = NumberKeyboard();
						}
					}
					if (Menu::Int("~b~Blue", Features::espb, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::espb = NumberKeyboard();
						}
					}
					Menu::Toggle("Name Tag ESP", Features::NameESP, [] { Features::NameTagESP(Features::NameESP); });

				}
				break;

				case trolli:
				{
					Menu::Title("~w~Troll Options");
					// Menu::Subtitle("GRIEFING");

					Menu::Toggle("Shake Cam", Features::camshaker112, [] { Features::shakecam11(Features::camshaker112); });



					if (Menu::Option("~w~Valkyrie Cannon All Player")) {

						for (int i = 0; i < 32; i++)
						{
							int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
							if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
							{

								Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
								Ped playerPed = PLAYER::PLAYER_PED_ID();
								Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
								FIRE::ADD_EXPLOSION(playerPosition.x, playerPosition.y, playerPosition.z - 1, 38, 0.5f, true, false, 0.0f);
							}

						}
					}

					if (Menu::Option("Take Weps in the Lobby")) {
						for (int i = 0; i < 32; i++)
						{
							if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
								if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) != PLAYER::PLAYER_PED_ID())
								{
									Player allplayers = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
									if (!(Features::cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")))
									{
										WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(allplayers), true);
									}
								}
							}
						}
					}

					if (Menu::Option("Airstrike All Player")) {

						for (int i = 0; i < 32; i++)
						{
							int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
							if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
							{

								Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
								Ped playerPed = PLAYER::PLAYER_PED_ID();
								Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
								Hash airStrike = GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET");
								WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
								while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike))
									WAIT(0);
								GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(playerPosition.x, playerPosition.y, playerPosition.z + 50.f, playerPosition.x, playerPosition.y, playerPosition.z, 250, 1, airStrike, playerPed, 1, 0, -1.0);
							}
						}
					}





					if (Menu::Option("Give Weps in the Lobby")) {

						for (int i = 0; i < 32; i++)
						{
							if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
								Player allplayers = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
								if (!(Features::cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")))
								{
									if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) != PLAYER::PLAYER_PED_ID())
									{
										uint Weapons[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D };
										for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
											WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(allplayers), Weapons[i], 9999, 1);
										}
									}
								}
							}
						}
					}
					if (Menu::Option("~r~Cage All Player")) {
						Features::trapall();
					}
					if (Menu::Option("Kick All From Car")) {
						for (int i = 0; i < 32; i++)
						{
							if (i != PLAYER::PLAYER_ID())
							{
								RequestControlOfEnt(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
								AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
								AI::CLEAR_PED_TASKS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
								AI::CLEAR_PED_SECONDARY_TASK(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
							}
						}
					}

					if (Menu::Option("Explode All"))
					{
						for (int i = 0; i < 32; i++)
						{
							int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
							if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
							{
								if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) continue;
								{
									Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
									FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 1000.f, true, false, 100.f); //patched
								}
							}
						}
					}
					if (Menu::Option("Clone All Player"))
					{
						for (int i = 0; i < 32; i++)
						{
							int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
							if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
							{

								PED::CLONE_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 1, 1, 1);

							}
						}
					}

				}
				break;

				//All Players 
				case allplayers:
				{
					Menu::Title("~w~All Players");
					// Menu::Subtitle("ALL PLAYERS");

					Menu::MenuOption("Drop System", dropOnlineall);
					Menu::MenuOption("Attach to All Player", attachtpall);
					Menu::MenuOption("Vehicle Spawner for All Players", vehspawnerr);
					Menu::MenuOption("Remote Options", Remoteoptall);
					Menu::MenuOption("Troll Options", trolli);
					Menu::MenuOption("ESP", espcolor);



				}
				break;

				case ghostw:
				{
					Menu::Title("~w~Nano69");
					// Menu::Subtitle("GHOST RIDER");
					if (Menu::Option("Spawn Ghost Bike")) {
						Features::autovehi("DAEMON");
						Vehicle Vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
						VEHICLE::SET_VEHICLE_COLOURS(Vehicle, 135, 135);
						VEHICLE::SET_VEHICLE_EXTRA_COLOURS(Vehicle, 127, 127);
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Vehicle, "GHOST");
					}
					Menu::Toggle("~w~Ghost Rider Mode", Features::ghostrider, [] { Features::firerider(Features::ghostrider); });
				}
				break;

				case noclip:
				{

					Menu::Title("Self Options");
					// Menu::Subtitle("Player Movement");
					Menu::Toggle("No-Clip", Features::flybool, [] { Features::playerflyer(Features::flybool);  });
					Menu::Toggle("Super Jump", Features::extremejump, [] { Features::Extremejump(Features::extremejump); });
					Menu::Toggle("Super Hack", Features::isSlideRun, [] { Features::slideRun(Features::isSlideRun); });
					Menu::Toggle("Stealth Walk", Features::isCrouchPlayer, [] { Features::crouchPlayer(Features::isCrouchPlayer); notifyMap("~w~Click CRTL and W"); });
					if (Menu::Int("Run/Swim Speed", Menu::Settings::run, 0, 20))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Menu::Settings::run = NumberKeyboard();
						}
					}
				}

				break;
				//Self  Main
				case playermenu:
				{
					Menu::Title("Self Options");
					// Menu::Subtitle("Self Options");
					Menu::MenuOption("Player Movement", noclip);
					Menu::MenuOption("Player Animations", anim);
					Menu::MenuOption("Player Vision", visions);
					Menu::Toggle("Godmode", Features::playerGodMode, [] { Features::GodMode(Features::playerGodMode); });
					Menu::Toggle("Invisibility", Features::playerinvisibility, [] { Features::Invisibility(Features::playerinvisibility); });
					Menu::Toggle("Never Wanted", Features::NeverWanted, [] { Features::neverWanted(Features::NeverWanted); });
					if (Menu::Option("Commit Suicide")) { Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_ENTITY_HEALTH }, 0); }
					if (Menu::Int("Player Alpha", Features::player_alpha, 0, 255)) {
						ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_PED_ID(), Features::player_alpha, 0);

					}
				}  
					break;

				case sizze:
				{
					Menu::Title("~b~Credits");
					// Menu::Subtitle("SIZE CHANFER");


					Menu::Toggle("~HUD_COLOUR_GOLD~Ped Size Changer", Features::Pedscale, [] { Features::pedscale(Features::Pedscale); });
					if (Menu::Float("~HUD_COLOUR_GOLD~Ped Hight", Features::pedsizee, 0, 50))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::pedsizee = NumberKeyboard();
						}
					}
					if (Menu::Float("~HUD_COLOUR_GOLD~Ped With", Features::pedwithh, 0, 50))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::pedwithh = NumberKeyboard();
						}
					}
				}
				break;


				//Model Changer 
				case modelchanger:
				{
					Menu::Title("Model Changer");
					// Menu::Subtitle("MODEL CHANGER");

					for (int i = 0; i < ARRAYSIZE(pedModels); i++)
					{
						if (Menu::Option(pedModels[i]))
						{
							DWORD model = GAMEPLAY::GET_HASH_KEY(pedModels[i]);
							STREAMING::REQUEST_MODEL(model);
							while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
							PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
							PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
							WAIT(10);
							STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
							WAIT(10);
						}
					}
				}
				break;


				case exploitramp:
				{
					Menu::Title("MapMode");
					// Menu::Subtitle("MAP MODS");

					Menu::MenuOption("Maze Bank Small Ramp ~w~>", ramp1);
					Menu::MenuOption("Maze Bank Roof Ramp ~w~>", ramp2);
					Menu::MenuOption("Beach Ramp ~w~>", ramp3);
					Menu::MenuOption("Mount Chilliad Ramp ~w~>", ramp4);
					Menu::MenuOption("Airport Mini Ramp ~w~>", ramp5);
					Menu::MenuOption("Airport Gate Ramp ~w~>", ramp6);
					Menu::MenuOption("Space Tower ~w~>", ramp7);
					Menu::MenuOption("Exploit Quad Ramp ~w~>", ramp8);
					Menu::MenuOption("Exploit Fort ~w~>", ramp9);
					Menu::MenuOption("Halfpipe ~g~>", ramp10);
					Menu::MenuOption("Airport Loop Ramp ~w~>", ramp11);
					Menu::MenuOption("Exploit Mega Ramp ~w~>", ramp12);
				}
				break;
#pragma region mapmode
				case ramp1:
					Menu::Title("Maze Bank Demolition");
					// Menu::Subtitle("MAZE BANK DEMO");

					if (Menu::Option("Load")) {
						Features::PlaceObjectByHash(2475986526, -80.9087, -830.357, 325.097, -14.4264, -8.53774, 152.209, -1, 0);
						Features::PlaceObjectByHash(2475986526, -79.2316, -831.297, 325.108, -14.4054, 4.26887, 164.271, -1, 0);
						Features::PlaceObjectByHash(2475986526, -76.7563, -831.549, 325.123, -14.4263, -0, 171.818, -1, 0);
						Features::PlaceObjectByHash(2475986526, -74.2595, -831.691, 325.09, -14.2059, -1.06722, -176.517, -1, 0);
						Features::PlaceObjectByHash(2475986526, -71.9478, -831.257, 325.113, -14.4264, 2.13443, -166.006, -1, 0);
						Features::PlaceObjectByHash(2475986526, -69.5981, -830.542, 325.066, -14.5918, -4.26887, -155.474, -1, 0);
						Features::PlaceObjectByHash(2475986526, -67.4174, -829.035, 325.097, -14.4263, -4.26887, -140.651, -1, 0);
						Features::PlaceObjectByHash(2475986526, -65.7121, -827.409, 325.068, -14.3048, -1.70755, -130.667, -1, 0);
						Features::PlaceObjectByHash(2475986526, -64.2717, -825.422, 325.112, -14.4263, -0, -121.256, -1, 0);
						Features::PlaceObjectByHash(2475986526, -63.2876, -823.434, 325.114, -14.5345, -0, -111.446, -1, 0);
						Features::PlaceObjectByHash(2475986526, -62.4924, -821.128, 325.082, -14.5467, 2.13443, -102.385, -1, 0);
						Features::PlaceObjectByHash(2475986526, -62.233, -818.528, 325.065, -14.6184, -8.00413, -88.1861, -1, 0);
						Features::PlaceObjectByHash(2475986526, -62.8694, -815.926, 325.118, -14.4265, -6.4033, -76.5979, -1, 0);
						Features::PlaceObjectByHash(2475986526, -63.6142, -813.68, 325.112, -14.3655, 8.53774, -66.7885, -1, 0);
						Features::PlaceObjectByHash(2475986526, -64.9883, -811.449, 325.107, -14.4263, 1.28066, -52.8494, -1, 0);
						Features::PlaceObjectByHash(2475986526, -66.5913, -808.328, 325.238, -12.4517, -0, -40.3246, -1, 0);
						Features::PlaceObjectByHash(2475986526, -68.2603, -807.899, 325.336, -13.8689, -0, -33.062, -1, 0);
						Features::PlaceObjectByHash(2475986526, -71.1526, -807.598, 325.153, -12.0416, 4.26887, -28.0523, -1, 0);
						Features::PlaceObjectByHash(2475986526, -73.2853, -806.628, 325.151, -11.7962, -0, -19.1717, -1, 0);
						Features::PlaceObjectByHash(2475986526, -75.2243, -806.286, 325.164, -12.0419, -0, 1.55726, -1, 0);
						Features::PlaceObjectByHash(2475986526, -77.5757, -806.312, 325.088, -14.1843, -0, 12.6263, -1, 0);
						Features::PlaceObjectByHash(2475986526, -79.8704, -807.22, 325.143, -14.049, -4.26887, 21.4769, -1, 0);
						Features::PlaceObjectByHash(2475986526, -82.0222, -807.83, 325.036, -14.1422, -4.26887, 32.7605, -1, 0);
						Features::PlaceObjectByHash(2475986526, -83.8934, -809.424, 325.073, -14.5264, -8.53774, 46.5132, -1, 0);
						Features::PlaceObjectByHash(2475986526, -85.2523, -810.983, 325.043, -14.859, -0, 53.5324, -1, 0);
						Features::PlaceObjectByHash(2475986526, -86.5177, -813.202, 325.089, -14.5267, 4.26887, 64.6634, -1, 0);
						Features::PlaceObjectByHash(2475986526, -87.6645, -815.707, 325.059, -14.8589, 4.26887, 73.157, -1, 0);
						Features::PlaceObjectByHash(2475986526, -87.7973, -817.987, 325.119, -14.8468, -1.33402, 89.3982, -1, 0);
						Features::PlaceObjectByHash(2475986526, -87.5801, -821.034, 325.059, -14.8593, -0, 95.4435, -1, 0);
						Features::PlaceObjectByHash(2475986526, -87.2815, -822.239, 325.126, -15.6308, -4.26887, 100.311, -1, 0);
						Features::PlaceObjectByHash(2475986526, -86.7602, -824.03, 325.044, -15.9224, -0, 116.957, -1, 0);
						Features::PlaceObjectByHash(2475986526, -85.3743, -826.099, 325.136, -15.7025, 2.56132, 124.307, -1, 0);
						Features::PlaceObjectByHash(2475986526, -83.4737, -828.611, 325.076, -15.0688, -0, 132.538, -1, 0);
						Features::PlaceObjectByHash(2475986526, -87.9554, -832.877, 325.894, -14.1563, 4.26887, 132.995, -1, 0);
						Features::PlaceObjectByHash(2475986526, -89.3865, -831.322, 325.887, -14.1562, -0, 126.154, -1, 0);
						Features::PlaceObjectByHash(2475986526, -86.4247, -834.407, 325.915, -14.2701, 4.26887, 143.277, -1, 0);
						Features::PlaceObjectByHash(2475986526, -85.1736, -833.789, 325.653, -14.4072, -4.26887, 145.777, -1, 0);
						Features::PlaceObjectByHash(2475986526, -83.8118, -835.765, 326.063, -12.243, 4.26887, 151.527, -1, 0);
						Features::PlaceObjectByHash(2475986526, -80.7015, -837.145, 326.059, -12.3172, 2.13443, 162.332, -1, 0);
						Features::PlaceObjectByHash(2475986526, -77.6428, -837.649, 326.163, -10.8391, 3.20165, 171.297, -1, 0);
						Features::PlaceObjectByHash(2475986526, -75.479, -837.909, 326.025, -12.3172, -1.06722, 174.574, -1, 0);
						Features::PlaceObjectByHash(2475986526, -73.861, -837.826, 326.061, -12.3173, 5.33609, -176.632, -1, 0);
						Features::PlaceObjectByHash(2475986526, -70.4799, -837.265, 326.09, -12.3173, -0, -166.182, -1, 0);
						Features::PlaceObjectByHash(2475986526, -67.0415, -836.185, 326.018, -12.3171, -0, -156.039, -1, 0);
						Features::PlaceObjectByHash(2475986526, -64.8504, -834.996, 325.951, -11.5263, -0, -145.834, -1, 0);
						Features::PlaceObjectByHash(2475986526, -63.5702, -833.725, 326.1, -11.2947, -0, -140.961, -1, 0);
						Features::PlaceObjectByHash(2475986526, -60.9992, -831.419, 326.075, -11.5262, -4.26887, -130.963, -1, 0);
						Features::PlaceObjectByHash(2475986526, -58.9923, -828.729, 326.116, -11.5262, 4.26887, -121.973, -1, 0);
						Features::PlaceObjectByHash(2475986526, -57.5045, -825.626, 326.114, -11.5263, -0, -110.959, -1, 0);
						Features::PlaceObjectByHash(2475986526, -56.5533, -822.397, 326.08, -11.1311, -6.4033, -102, -1, 0);
						Features::PlaceObjectByHash(2475986526, -56.0911, -820.05, 326.049, -11.0325, 2.13443, -100.794, -1, 0);
						Features::PlaceObjectByHash(2475986526, -56.0681, -818.32, 326.087, -11.1312, -2.66804, -87.9469, -1, 0);
						Features::PlaceObjectByHash(2475986526, -56.2989, -816.237, 326.048, -11.0324, 2.13443, -83.2139, -1, 0);
						Features::PlaceObjectByHash(2475986526, -56.8952, -814.518, 326.142, -11.0324, -2.13443, -76.5476, -1, 0);
						Features::PlaceObjectByHash(2475986526, -58.1209, -811.23, 326.116, -10.9697, -0, -66.7674, -1, 0);
						Features::PlaceObjectByHash(2475986526, -59.0622, -809.17, 326.095, -11.0574, 4.26887, -62.782, -1, 0);
						Features::PlaceObjectByHash(2475986526, -60.096, -807.639, 326.119, -11.5544, -0, -52.7596, -1, 0);
						Features::PlaceObjectByHash(2475986526, -62.081, -805.317, 326.116, -11.1035, -0, -40.7682, -1, 0);
						Features::PlaceObjectByHash(2475986526, -64.1466, -804.55, 326.283, -11.1035, -0, -30.477, -1, 0);
						Features::PlaceObjectByHash(2475986526, -67.9795, -798.8, 326.717, -10.1561, -0, -29.3495, -1, 0);
						Features::PlaceObjectByHash(2475986526, -67.5734, -802.52, 326.262, -10.471, -8.53774, -31.2185, -1, 0);
						Features::PlaceObjectByHash(2475986526, -70.9341, -800.541, 326.198, -10.5317, -0, -20.0064, -1, 0);
						Features::PlaceObjectByHash(2475986526, -75.3309, -801.285, 325.849, -10.2407, -0, 1.58401, -1, 0);
						Features::PlaceObjectByHash(2475986526, -74.0222, -799.865, 326.177, -10.7327, -0, -5.98314, -1, 0);
						Features::PlaceObjectByHash(2475986526, -76.5167, -797.998, 326.32, -12.4969, -2.66804, 1.58883, -1, 0);
						Features::PlaceObjectByHash(2475986526, -79.2787, -800.531, 326.011, -12.9433, 4.26887, 13.0054, -1, 0);
						Features::PlaceObjectByHash(2475986526, -81.6721, -801.017, 325.9, -12.4601, 2.13443, 17.3792, -1, 0);
						Features::PlaceObjectByHash(2475986526, -83.6027, -801.744, 325.971, -12.9433, -0, 26.3052, -1, 0);
						Features::PlaceObjectByHash(2475986526, -85.6586, -802.789, 325.95, -12.8791, 1.28066, 32.5856, -1, 0);
						Features::PlaceObjectByHash(2475986526, -87.5086, -804.25, 325.978, -12.9432, 4.26887, 42.3279, -1, 0);
						Features::PlaceObjectByHash(2475986526, -88.9923, -805.73, 325.89, -11.9333, -4.26887, 46.0613, -1, 0);
						Features::PlaceObjectByHash(2475986526, -90.167, -807.318, 325.946, -13.0244, -0, 53.178, -1, 0);
						Features::PlaceObjectByHash(2475986526, -93.5987, -807.353, 326.343, -11.5713, 4.26887, 60.8753, -1, 0);
						Features::PlaceObjectByHash(2475986526, -93.5166, -813.963, 325.942, -13.4341, -4.26887, 73.0256, -1, 0);
						Features::PlaceObjectByHash(2475986526, -92.121, -810.584, 325.996, -13.4339, -4.26887, 64.9353, -1, 0);
						Features::PlaceObjectByHash(2475986526, -93.9931, -815.866, 325.924, -13.0519, -0, 79.5966, -1, 0);
						Features::PlaceObjectByHash(2475986526, -93.8716, -817.904, 325.988, -13.4339, -0, 88.8361, -1, 0);
						Features::PlaceObjectByHash(2475986526, -93.7912, -821.777, 325.946, -13.6946, -2.66804, 91.1427, -1, 0);
						Features::PlaceObjectByHash(2475986526, -93.2951, -823.554, 325.966, -13.157, -0, 101.424, -1, 0);
						Features::PlaceObjectByHash(2475986526, -92.5757, -827.033, 325.87, -13.5323, -0, 104.668, -1, 0);
						Features::PlaceObjectByHash(2475986526, -91.53, -828.342, 325.842, -14.1563, 4.26887, 120.328, -1, 0);
						Features::PlaceObjectByHash(2475986526, -90.5203, -829.611, 325.936, -14.1563, -0, 124.573, -1, 0);
						Features::PlaceObjectByHash(2475986526, -95.5355, -833.068, 327.049, -9.63525, 1.70755, 124.512, -1, 0);
						Features::PlaceObjectByHash(2475986526, -94.2445, -835.1, 326.976, -9.27617, -1.28066, 128.396, -1, 0);
						Features::PlaceObjectByHash(2475986526, -92.513, -837.087, 327.008, -9.63523, -4.26887, 132.871, -1, 0);
						Features::PlaceObjectByHash(2475986526, -90.07, -839.341, 327.025, -9.63574, 4.26887, 143.545, -1, 0);
						Features::PlaceObjectByHash(2475986526, -86.7336, -841.135, 327.284, -9.63566, -0, 150.983, -1, 0);
						Features::PlaceObjectByHash(2475986526, -84.8343, -842.167, 327.254, -9.36742, -4.26887, 152.377, -1, 0);
						Features::PlaceObjectByHash(2475986526, -90.0883, -842.661, 327.589, -7.98782, -8.53774, 146.409, -1, 0);
						Features::PlaceObjectByHash(2475986526, -82.595, -843.001, 327.277, -9.6352, -0, 161.654, -1, 0);
						Features::PlaceObjectByHash(2475986526, -80.8027, -843.618, 327.263, -9.36755, -2.13443, 165.215, -1, 0);
						Features::PlaceObjectByHash(2475986526, -78.5619, -843.703, 327.458, -9.63545, -2.13443, 171.015, -1, 0);
						Features::PlaceObjectByHash(2475986526, -76.2479, -844.026, 327.261, -9.36765, 1.06722, 175.986, -1, 0);
						Features::PlaceObjectByHash(2475986526, -73.5382, -843.999, 327.285, -9.6355, -0, -177.212, -1, 0);
						Features::PlaceObjectByHash(2475986526, -71.2047, -843.988, 327.3, -9.36764, -1.06722, -172.013, -1, 0);
						Features::PlaceObjectByHash(2475986526, -69.036, -843.266, 327.309, -9.63525, 4.26887, -166.686, -1, 0);
						Features::PlaceObjectByHash(2475986526, -67.2981, -840.996, 326.756, -9.37509, -2.13443, -159.014, -1, 0);
						Features::PlaceObjectByHash(2475986526, -66.7067, -842.714, 327.222, -9.37501, 2.13443, -159.27, -1, 0);
						Features::PlaceObjectByHash(2475986526, -64.5693, -841.792, 327.24, -9.63515, 4.26887, -156.16, -1, 0);
						Features::PlaceObjectByHash(2475986526, -61.8874, -840.436, 327.231, -9.37483, 4.26887, -146.534, -1, 0);
						Features::PlaceObjectByHash(2475986526, -59.7118, -838.501, 327.384, -9.63533, -0, -141.372, -1, 0);
						Features::PlaceObjectByHash(2475986526, -57.9491, -837.16, 327.309, -9.37471, 4.26887, -135.839, -1, 0);
						Features::PlaceObjectByHash(2475986526, -56.3494, -835.471, 327.34, -9.63578, 4.26887, -131.675, -1, 0);
						Features::PlaceObjectByHash(2475986526, -54.9387, -833.93, 327.334, -9.37482, -0, -127.887, -1, 0);
						Features::PlaceObjectByHash(2475986526, -53.727, -832.032, 327.367, -9.63521, -4.26887, -122.142, -1, 0);
						Features::PlaceObjectByHash(2475986526, -52.5928, -830.077, 327.332, -9.37496, -0, -116.843, -1, 0);
						Features::PlaceObjectByHash(2475986526, -51.7552, -827.819, 327.385, -9.63569, 6.4033, -111.077, -1, 0);
						Features::PlaceObjectByHash(2475986526, -51.0061, -825.839, 327.369, -9.37494, 4.26887, -107.054, -1, 0);
						Features::PlaceObjectByHash(2475986526, -50.5468, -823.622, 327.378, -9.63572, 4.26887, -101.598, -1, 0);
						Features::PlaceObjectByHash(2475986526, -50.0992, -820.896, 327.345, -9.47333, -1.06722, -95.7976, -1, 0);
						Features::PlaceObjectByHash(2475986526, -49.9295, -818.102, 327.381, -9.63531, -8.00413, -88.2146, -1, 0);
						Features::PlaceObjectByHash(2475986526, -50.1895, -815.816, 327.358, -9.4734, -0, -82.8649, -1, 0);
						Features::PlaceObjectByHash(2475986526, -50.9164, -813.132, 327.442, -9.63524, 2.13443, -76.865, -1, 0);
						Features::PlaceObjectByHash(2475986526, -51.1585, -811.568, 327.373, -9.58574, -0, -69.3402, -1, 0);
						Features::PlaceObjectByHash(2475986526, -52.0622, -809.533, 327.354, -9.63541, 2.13443, -65.7624, -1, 0);
						Features::PlaceObjectByHash(2475986526, -53.4048, -806.624, 327.376, -9.63526, 2.13443, -65.3971, -1, 0);
						Features::PlaceObjectByHash(2475986526, -55.2978, -803.815, 327.389, -9.63524, 4.26887, -52.2107, -1, 0);
						Features::PlaceObjectByHash(2475986526, -56.5179, -802.266, 327.366, -9.51013, 4.26887, -50.6537, -1, 0);
						Features::PlaceObjectByHash(2475986526, -57.9995, -800.68, 327.42, -9.6353, 1.28066, -41.7027, -1, 0);
						Features::PlaceObjectByHash(2475986526, -61.0278, -799.404, 327.549, -9.63516, 8.53774, -31.016, -1, 0);
						Features::PlaceObjectByHash(2475986526, -64.37, -797.284, 327.603, -9.6351, -0, -31.6732, -1, 0);
						Features::PlaceObjectByHash(2475986526, -66.3998, -795.965, 327.526, -9.42422, 8.53773, -29.018, -1, 0);
						Features::PlaceObjectByHash(2475986526, -68.8079, -794.744, 327.535, -9.63558, -2.13443, -20.0341, -1, 0);
						Features::PlaceObjectByHash(2475986526, -72.1225, -793.825, 327.497, -9.57894, -2.13443, -12.2336, -1, 0);
						Features::PlaceObjectByHash(2475986526, -75.6415, -795.169, 327.2, -9.63555, -1.60083, 2.8097, -1, 0);
						Features::PlaceObjectByHash(2475986526, -77.9613, -794.235, 327.223, -8.9769, -5.33608, 4.53814, -1, 0);
						Features::PlaceObjectByHash(2475986526, -75.3695, -789.507, 328.306, -8.84722, -8.33763, -0.0879073, -1, 0);
						Features::PlaceObjectByHash(2475986526, -80.6908, -794.505, 327.217, -9.63537, 4.26887, 13.0745, -1, 0);
						Features::PlaceObjectByHash(2475986526, -83.5673, -795.148, 327.101, -9.92985, 2.13443, 17.5819, -1, 0);
						Features::PlaceObjectByHash(2475986526, -86.3087, -796.203, 327.177, -9.63542, -4.26887, 25.9296, -1, 0);
						Features::PlaceObjectByHash(2475986526, -88.9655, -797.634, 327.118, -9.92994, -4.26887, 33.0571, -1, 0);
						Features::PlaceObjectByHash(2475986526, -91.6251, -799.702, 327.176, -9.63539, -0, 42.2513, -1, 0);
						Features::PlaceObjectByHash(2475986526, -93.414, -801.299, 327.124, -9.92995, -0, 48.7085, -1, 0);
						Features::PlaceObjectByHash(2475986526, -95.1453, -803.637, 327.147, -9.63537, -8.53774, 53.6544, -1, 0);
						Features::PlaceObjectByHash(2475986526, -96.5885, -805.701, 327.144, -9.8947, -0, 60.5096, -1, 0);
						Features::PlaceObjectByHash(2475986526, -97.6945, -807.971, 327.174, -9.63569, 4.26887, 64.7568, -1, 0);
						Features::PlaceObjectByHash(2475986526, -98.7075, -809.885, 327.026, -8.13758, -0, 67.8881, -1, 0);
						Features::PlaceObjectByHash(2475986526, -99.394, -812.176, 327.105, -9.63525, -4.26887, 73.0223, -1, 0);
						Features::PlaceObjectByHash(2475986526, -100.025, -814.868, 327.097, -9.97277, 2.13443, 83.1537, -1, 0);
						Features::PlaceObjectByHash(2475986526, -100.012, -817.789, 327.15, -9.63535, -1.33402, 88.8234, -1, 0);
						Features::PlaceObjectByHash(2475986526, -100.069, -819.76, 327.099, -9.95297, -1.33402, 90.8729, -1, 0);
						Features::PlaceObjectByHash(2475986526, -99.969, -821.91, 327.11, -9.63541, -2.66804, 91.5501, -1, 0);
						Features::PlaceObjectByHash(2475986526, -99.3358, -824.801, 327.138, -9.63539, 2.13443, 101.678, -1, 0);
						Features::PlaceObjectByHash(2475986526, -98.5443, -828.598, 327.033, -9.63553, -0, 104.64, -1, 0);
						Features::PlaceObjectByHash(2475986526, -97.0896, -831.054, 326.937, -10.0741, 4.26887, 118.72, -1, 0);
						Features::PlaceObjectByHash(2475986526, -102.435, -833.952, 328.506, -5.26399, -0, 118.502, -1, 0);
						Features::PlaceObjectByHash(2475986526, -103.536, -831.932, 328.513, -5.42142, 4.26887, 111.099, -1, 0);
						Features::PlaceObjectByHash(2475986526, -100.644, -836.571, 328.636, -5.26398, -0, 124.006, -1, 0);
						Features::PlaceObjectByHash(2475986526, -99.0448, -838.912, 328.589, -5.26395, -2.13443, 128.175, -1, 0);
						Features::PlaceObjectByHash(2475986526, -96.9401, -841.184, 328.589, -5.26384, -2.13443, 132.615, -1, 0);
						Features::PlaceObjectByHash(2475986526, -95.4409, -842.718, 328.551, -5.01006, -2.13443, 136.57, -1, 0);
						Features::PlaceObjectByHash(2475986526, -93.6584, -844.231, 328.606, -5.26388, -0, 143.429, -1, 0);
						Features::PlaceObjectByHash(2475986526, -92.1044, -845.82, 328.655, -5.01307, -2.13443, 147.428, -1, 0);
						Features::PlaceObjectByHash(2475986526, -89.6061, -846.328, 328.851, -5.26389, -0, 150.62, -1, 0);
						Features::PlaceObjectByHash(2475986526, -87.5884, -847.552, 328.829, -5.6777, -0, 153.36, -1, 0);
						Features::PlaceObjectByHash(2475986526, -84.5215, -848.802, 328.867, -5.26405, 5.33608, 161.164, -1, 0);
						Features::PlaceObjectByHash(2475986526, -81.9779, -849.605, 328.821, -5.67769, 1.06722, 166.961, -1, 0);
						Features::PlaceObjectByHash(2475986526, -79.5282, -849.717, 329.046, -5.26392, 1.06722, 170.517, -1, 0);
						Features::PlaceObjectByHash(2475986526, -76.7555, -850.113, 328.885, -4.93224, 2.66804, 175.995, -1, 0);
						Features::PlaceObjectByHash(2475986526, -73.2336, -850.06, 328.883, -5.26397, -0, -177.431, -1, 0);
						Features::PlaceObjectByHash(2475986526, -70.4067, -849.836, 328.854, -4.82287, -5.33608, -172.2, -1, 0);
						Features::PlaceObjectByHash(2475986526, -67.6252, -849.166, 328.911, -5.26394, -0, -166.741, -1, 0);
						Features::PlaceObjectByHash(2475986526, -64.6525, -848.331, 328.792, -4.82267, -2.13443, -160.74, -1, 0);
						Features::PlaceObjectByHash(2475986526, -62.1086, -847.355, 328.837, -5.26389, 2.13443, -156.346, -1, 0);
						Features::PlaceObjectByHash(2475986526, -60.2755, -846.895, 328.808, -5.97307, -2.13443, -151.031, -1, 0);
						Features::PlaceObjectByHash(2475986526, -58.5152, -845.543, 328.833, -5.26392, 1.06722, -147.129, -1, 0);
						Features::PlaceObjectByHash(2475986526, -55.9339, -843.258, 328.987, -5.26394, 2.13443, -141.8, -1, 0);
						Features::PlaceObjectByHash(2475986526, -53.6636, -841.564, 328.905, -5.18348, -0, -136.192, -1, 0);
						Features::PlaceObjectByHash(2475986526, -51.8013, -839.526, 328.926, -5.26393, -2.13443, -131.788, -1, 0);
						Features::PlaceObjectByHash(2475986526, -49.9112, -837.51, 328.916, -5.18352, -8.53774, -125.894, -1, 0);
						Features::PlaceObjectByHash(2475986526, -48.5833, -835.261, 328.968, -5.26388, 2.13443, -122.598, -1, 0);
						Features::PlaceObjectByHash(2475986526, -47.1369, -832.806, 328.936, -5.18352, -0, -117.146, -1, 0);
						Features::PlaceObjectByHash(2475986526, -46.1092, -830.019, 328.985, -5.26389, -0, -111.097, -1, 0);
						Features::PlaceObjectByHash(2475986526, -45.2549, -827.659, 328.957, -5.18353, -1.06722, -105.915, -1, 0);
						Features::PlaceObjectByHash(2475986526, -44.5598, -824.856, 328.973, -5.26387, -0, -101.582, -1, 0);
						Features::PlaceObjectByHash(2475986526, -44.0346, -821.522, 328.953, -5.26387, 5.33608, -95.978, -1, 0);
						Features::PlaceObjectByHash(2475986526, -43.8673, -817.92, 328.98, -5.26387, -4.00206, -88.1556, -1, 0);
						Features::PlaceObjectByHash(2475986526, -44.1983, -815.072, 328.956, -5.26387, -0, -82.8806, -1, 0);
						Features::PlaceObjectByHash(2475986526, -45.0463, -811.788, 329.021, -5.26392, -0, -77.2513, -1, 0);
						Features::PlaceObjectByHash(2475986526, -45.6154, -809.566, 328.95, -5.25705, -2.13443, -72.2094, -1, 0);
						Features::PlaceObjectByHash(2475986526, -46.5685, -807.149, 328.929, -5.26395, -2.13443, -66.9958, -1, 0);
						Features::PlaceObjectByHash(2475986526, -47.9752, -804.122, 328.959, -5.26398, -0, -65.1505, -1, 0);
						Features::PlaceObjectByHash(2475986526, -49.0785, -802.078, 328.914, -5.31539, 4.26887, -57.7224, -1, 0);
						Features::PlaceObjectByHash(2475986526, -50.5092, -800.141, 328.99, -5.26406, -0, -52.4683, -1, 0);
						Features::PlaceObjectByHash(2475986526, -52.041, -798.134, 329.001, -5.31536, -2.13443, -49.2493, -1, 0);
						Features::PlaceObjectByHash(2475986526, -53.8808, -796.134, 329.041, -5.26389, -0, -42.3308, -1, 0);
						Features::PlaceObjectByHash(2475986526, -55.4375, -794.682, 329.045, -5.32055, 2.13443, -37.3601, -1, 0);
						Features::PlaceObjectByHash(2475986526, -57.7537, -794.2, 329.16, -5.26393, 2.13443, -32.2267, -1, 0);
						Features::PlaceObjectByHash(2475986526, -61.0299, -792.042, 329.172, -5.26389, -2.13443, -32.1174, -1, 0);
						Features::PlaceObjectByHash(2475986526, -63.5163, -790.736, 329.085, -5.04535, -4.26887, -29.2933, -1, 0);
						Features::PlaceObjectByHash(2475986526, -64.7324, -789.882, 329.081, -4.987, -2.13443, -27.7917, -1, 0);
						Features::PlaceObjectByHash(2475986526, -66.7775, -788.94, 329.155, -5.04558, 1.06722, -19.5666, -1, 0);
						Features::PlaceObjectByHash(2475986526, -68.6555, -788.272, 329.103, -5.30654, 3.20165, -16.9146, -1, 0);
						Features::PlaceObjectByHash(2475986526, -70.8259, -787.837, 329.128, -5.04546, 1.06722, -12.2941, -1, 0);
						Features::PlaceObjectByHash(2475986526, -74.5572, -787.022, 329.08, -4.61724, 1.06722, -10.7316, -1, 0);
						Features::PlaceObjectByHash(2475986526, -75.8754, -788.646, 328.671, -6.78921, -0, 2.98721, -1, 0);
						Features::PlaceObjectByHash(2475986526, -78.4, -788.132, 328.83, -5.91899, 2.66804, 3.75875, -1, 0);
						Features::PlaceObjectByHash(2475986526, -80.5351, -788.179, 328.782, -5.80051, -0, 7.26539, -1, 0);
						Features::PlaceObjectByHash(2475986526, -82.1189, -788.558, 328.793, -5.9192, 1.06722, 12.7168, -1, 0);
						Features::PlaceObjectByHash(2475986526, -85.4054, -789.317, 328.666, -5.79433, -0, 17.1877, -1, 0);
						Features::PlaceObjectByHash(2475986526, -87.4651, -789.98, 328.647, -5.63204, -0, 20.2315, -1, 0);
						Features::PlaceObjectByHash(2475986526, -88.9795, -790.697, 328.76, -5.79416, -0, 25.9501, -1, 0);
						Features::PlaceObjectByHash(2475986526, -90.9922, -791.487, 328.684, -6.26149, -0, 27.0819, -1, 0);
						Features::PlaceObjectByHash(2475986526, -92.3298, -792.474, 328.677, -5.79412, -0, 33.3113, -1, 0);
						Features::PlaceObjectByHash(2475986526, -94.2322, -793.73, 328.669, -5.58479, -2.13443, 37.4974, -1, 0);
						Features::PlaceObjectByHash(2475986526, -95.7282, -795.2, 328.764, -5.79431, -0, 41.8672, -1, 0);
						Features::PlaceObjectByHash(2475986526, -97.9782, -797.316, 328.695, -5.58488, -0, 48.9171, -1, 0);
						Features::PlaceObjectByHash(2475986526, -100.042, -800.063, 328.731, -5.79425, 2.13443, 53.7039, -1, 0);
						Features::PlaceObjectByHash(2475986526, -101.884, -802.718, 328.706, -5.5848, 2.13443, 60.3613, -1, 0);
						Features::PlaceObjectByHash(2475986526, -103.09, -805.421, 328.718, -5.79425, -0, 64.506, -1, 0);
						Features::PlaceObjectByHash(2475986526, -104.284, -807.711, 328.691, -5.58488, -2.13443, 65.966, -1, 0);
						Features::PlaceObjectByHash(2475986526, -105.262, -810.369, 328.729, -5.26384, 1.06722, 73.2414, -1, 0);
						Features::PlaceObjectByHash(2475986526, -105.769, -812.146, 328.645, -5.25205, -1.06722, 75.8091, -1, 0);
						Features::PlaceObjectByHash(2475986526, -106.155, -814.128, 328.687, -5.26388, -1.06722, 82.8157, -1, 0);
						Features::PlaceObjectByHash(2475986526, -106.062, -817.685, 328.758, -5.26388, 2.66804, 88.7458, -1, 0);
						Features::PlaceObjectByHash(2475986526, -106.154, -819.723, 328.716, -5.25204, -0, 90.1628, -1, 0);
						Features::PlaceObjectByHash(2475986526, -106.082, -822.072, 328.729, -5.26387, -1.33402, 91.2972, -1, 0);
						Features::PlaceObjectByHash(2475986526, -105.911, -823.815, 328.7, -5.52135, 5.33608, 99.4393, -1, 0);
						Features::PlaceObjectByHash(2475986526, -105.28, -826.029, 328.734, -5.26391, 1.06722, 101.615, -1, 0);
						Features::PlaceObjectByHash(2475986526, -105.06, -827.904, 328.644, -5.29978, 1.06722, 102.515, -1, 0);
						Features::PlaceObjectByHash(2475986526, -104.327, -830.112, 328.614, -5.26391, -2.13443, 104.719, -1, 0);
						Features::PlaceObjectByHash(3291218330, -108.551, -853.416, 327.387, 2.94456, 89.1111, -166.155, -1, 0);
						Features::PlaceObjectByHash(3291218330, -80.2509, -866.418, 327.301, 3.7405, 89.3, 146.641, -1, 0);
						Features::PlaceObjectByHash(3291218330, -55.8513, -863.921, 327.333, 6.87468, 89.6184, 149.776, -1, 0);
						Features::PlaceObjectByHash(3291218330, -37.3907, -848.122, 327.717, 2.33633, 88.8797, -16.2595, -1, 0);
						Features::PlaceObjectByHash(3291218330, -26.1908, -818.332, 328.76, 0.490556, 84.6598, -18.107, -1, 0);
						Features::PlaceObjectByHash(3291218330, -37.891, -789.138, 328.134, 1.11673, 87.6571, 42.7186, -1, 0);
						Features::PlaceObjectByHash(3291218330, -63.492, -772.044, 327.866, 3.09962, 89.1556, 44.702, -1, 0);
						Features::PlaceObjectByHash(3291218330, -93.4916, -774.848, 327.398, 2.73771, 89.0443, 122.539, -1, 0);
						Features::PlaceObjectByHash(3291218330, -115.991, -795.259, 327.27, 3.28432, 89.2033, 123.086, -1, 0);
						Features::PlaceObjectByHash(3291218330, -122.551, -825.074, 327.213, 173.37, 89.6048, 4.27077, -1, 0);
						Features::PlaceObjectByHash(118627012, -74.8438, -819.617, 323.685, 0, 0, -3.37511, -1, 0);
						Features::PlaceObjectByHash(2475986526, -67.6253, -820.244, 323.793, -14.4263, -8.53774, -100.02, -1, 0);
					}
					if (Menu::Option("Teleport")) {
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
					}
					break;
#pragma region mapmode
				case ramp2:
					Menu::Title("Maze Bank Roof Ramp");
					// Menu::Subtitle("MAZE BANK ROOF RAMP");

					if (Menu::Option("Load")) {
						Features::PlaceObjectByHash(1600026313, -78.4864, -807.943, 323.202, 109.364, -89.9209, 0, -1, 1);
						Features::PlaceObjectByHash(1600026313, -79.2766, -805.701, 323.204, 109.364, -89.9209, 0, -1, 1);
						Features::PlaceObjectByHash(1600026313, -79.8373, -803.709, 323.205, 109.364, -89.9209, 0, -1, 1);
						Features::PlaceObjectByHash(1600026313, -80.4295, -801.947, 323.207, 109.364, -89.9209, 0, -1, 1);
						Features::PlaceObjectByHash(4143853297, -97.4731, -778.557, 308.877, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(1087520462, -84.2429, -793.182, 321.08, -63.5625, -0, -160.249, -1, 1);
						Features::PlaceObjectByHash(1087520462, -83.5429, -795.106, 322.073, -63.5625, -0, -160.249, -1, 1);
						Features::PlaceObjectByHash(1087520462, -84.9429, -791.108, 319.956, -62.6673, 8.53774e-007, -160.249, -1, 1);
						Features::PlaceObjectByHash(1087520462, -85.8122, -788.585, 318.638, -63.5625, -0, -160.249, -1, 1);
						Features::PlaceObjectByHash(1087520462, -89.1589, -779.487, 313.336, -59.5389, 0.0405551, -160.567, -1, 1);
						Features::PlaceObjectByHash(1087520462, -90.7065, -774.863, 310.09, -57.4959, 0.322988, -160.758, -1, 1);
						Features::PlaceObjectByHash(1087520462, -91.4887, -772.564, 308.403, -55.1692, 0.383369, -161.049, -1, 1);
						Features::PlaceObjectByHash(1087520462, -91.7565, -771.74, 307.844, -56.4466, 0.0442451, -160.565, -1, 1);
						Features::PlaceObjectByHash(1087520462, -93.6941, -766.245, 302.736, -45.9996, 0.0556114, -160.556, -1, 1);
						Features::PlaceObjectByHash(1087520462, -94.2969, -764.648, 301.067, -44.7623, -1.70755e-006, -159.354, -1, 1);
						Features::PlaceObjectByHash(1087520462, -94.2969, -764.648, 301.067, -44.7623, -1.70755e-006, -159.354, -1, 1);
						Features::PlaceObjectByHash(1087520462, -94.886, -762.996, 298.741, -36.7051, -0, -159.354, -1, 1);
						Features::PlaceObjectByHash(1087520462, -95.4855, -761.334, 296.406, -36.7051, -0, -159.354, -1, 1);
						Features::PlaceObjectByHash(1087520462, -95.4855, -761.334, 296.406, -36.7051, -0, -159.354, -1, 1);
						Features::PlaceObjectByHash(1087520462, -96.1606, -759.499, 294.259, -42.0766, -0, -159.354, -1, 1);
						Features::PlaceObjectByHash(1087520462, -96.0707, -759.689, 293.709, -36.7051, -0, -159.354, -1, 1);
						Features::PlaceObjectByHash(1087520462, -96.0707, -759.689, 293.709, -36.7051, -0, -159.354, -1, 1);
						Features::PlaceObjectByHash(1087520462, -96.0707, -759.689, 293.46, -36.7051, -0, -159.354, -1, 1);
						Features::PlaceObjectByHash(1087520462, -96.8807, -757.391, 292.506, -51.0291, -8.53774e-007, -159.354, -1, 1);
						Features::PlaceObjectByHash(1087520462, -96.8807, -757.391, 292.506, -51.0291, -8.53774e-007, -159.354, -1, 1);
						Features::PlaceObjectByHash(1087520462, -97.3203, -756.159, 291.688, -57.2958, -0, -159.354, -1, 1);
						Features::PlaceObjectByHash(1087520462, -97.9597, -754.358, 290.78, -62.6673, 8.53774e-007, -160.249, -1, 1);
						Features::PlaceObjectByHash(1087520462, -97.9597, -754.358, 290.78, -62.6673, 8.53774e-007, -160.249, -1, 1);
						Features::PlaceObjectByHash(1087520462, -98.7192, -752.356, 290.042, -69.9278, 3.20165e-005, -160.249, -1, 1);
						Features::PlaceObjectByHash(1087520462, -99.0244, -751.684, 290.499, -90, -8.46346e-007, -160.249, -1, 1);
						Features::PlaceObjectByHash(1087520462, -99.3223, -750.534, 290.479, -90, -8.46346e-007, -160.249, -1, 1);
						Features::PlaceObjectByHash(1087520462, -100.348, -747.881, 290.452, -89.5256, -1.33402e-008, -159.354, -1, 1);
						Features::PlaceObjectByHash(1087520462, -100.26, -748.154, 290.462, -76.096, 4.26887e-007, 19.6954, -1, 1);
						Features::PlaceObjectByHash(1087520462, -100.687, -747.053, 290.731, -62.6673, -8.53774e-007, 20.5907, -1, 1);
						Features::PlaceObjectByHash(1087520462, -101.346, -745.387, 291.611, -58.191, 1.70755e-006, 19.6954, -1, 1);
						Features::PlaceObjectByHash(1087520462, -102.234, -743.119, 293.091, -52.2249, 0.00051141, 21.3426, -1, 1);
						Features::PlaceObjectByHash(2475986526, -102.154, -739.285, 294.83, 9.80014, 0.295618, 18.7802, -1, 1);
						Features::PlaceObjectByHash(2475986526, -105.054, -740.282, 294.827, 9.80014, 0.295618, 18.7802, -1, 1);
						Features::PlaceObjectByHash(1087520462, -103.071, -741.047, 294.832, -48.0666, 0.000519094, 21.3419, -1, 1);
						Features::PlaceObjectByHash(1087520462, -103.75, -739.405, 296.413, -45.1472, 0.000547269, 21.3416, -1, 1);
						Features::PlaceObjectByHash(4143853297, -90.3515, -798.112, 319.893, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -93.2293, -790.348, 317.189, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -95.3479, -784.483, 313.696, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -100.01, -771.31, 304.367, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -101.829, -766.277, 299.666, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -103.318, -762.175, 293.966, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -104.948, -757.681, 288.866, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -108.146, -748.798, 288.866, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -108.146, -748.798, 295.608, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -108.225, -748.694, 302.608, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(3167053133, -103.451, -740.541, 307.317, -0.900199, -1.19985, 20.9076, -1, 1);
						Features::PlaceObjectByHash(2375650849, -102.454, -742.6, 309.309, 0, 0, 20.9393, -1, 1);
						Features::PlaceObjectByHash(4143853297, -101.483, -746.044, 305.602, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -94.7458, -743.402, 295.608, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -94.7566, -743.406, 288.866, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -94.7426, -743.595, 302.651, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(1157292806, -99.7732, -750.516, 309.575, 0, 0, 24.1761, -1, 1);
						Features::PlaceObjectByHash(4143853297, -89.9785, -756.476, 293.966, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -91.5378, -752.285, 288.866, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -87.9094, -762.07, 299.666, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -86.2094, -766.939, 304.367, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -84.0215, -772.971, 309.575, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -81.6733, -779.348, 313.696, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -79.5187, -785.083, 317.189, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(4143853297, -76.5616, -793.191, 319.493, 0, -0, -159.831, -1, 1);
						Features::PlaceObjectByHash(1998517203, -81.0993, -790.139, 326.57, 0, 0, -82.6177, -1, 1);
						Features::PlaceObjectByHash(1998517203, -88.8988, -792.911, 326.95, 0, 0, -82.6177, -1, 1);
						Features::PlaceObjectByHash(803874239, -88.3376, -794.173, 327.042, 0, 0, 31.5501, -1, 1);
						Features::PlaceObjectByHash(803874239, -90.0376, -795.174, 327.262, 0, 0, 31.5501, -1, 1);
						Features::PlaceObjectByHash(803874239, -91.6375, -796.175, 327.482, 0, 0, 31.5501, -1, 1);
						Features::PlaceObjectByHash(803874239, -79.0283, -791.31, 326.763, 0, -0, 100.953, -1, 1);
						Features::PlaceObjectByHash(803874239, -76.8377, -790.87, 326.823, 0, -0, 100.953, -1, 1);
						Features::PlaceObjectByHash(803874239, -81.0088, -791.22, 326.713, 0, -0, 100.953, -1, 1);
					}
					if (Menu::Option("Teleport")) {
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
					}
					break;
#pragma region mapmode
				case ramp3:
					Menu::Title("Beach Ferris-Ramp");
					// Menu::Subtitle("BEACH RAMP");

					if (Menu::Option("Load")) {
						Features::PlaceObjectByHash(1952396163, -1497.76, -1113.84, -3.08, -90, 6.14715e-007, 165.792, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1461.92, -1216.88, 2.5836, -2.3048, -0, -154.878, -1, 2);
						Features::PlaceObjectByHash(3291218330, -1465.62, -1217.64, 18, 166.516, -5.12264e-006, 24.1717, -1, 2);
						Features::PlaceObjectByHash(3291218330, -1458.89, -1214.4, 18, -38.4956, 8.53774e-007, -153.982, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1460.32, -1219.97, 4.3801, 12.6953, -0, -154.878, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1457, -1226.67, 11.8772, 31.7229, -0, -154.382, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1458.4, -1223.77, 7.9937, 23.6001, -0.0916355, -154.918, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1456.4, -1228.27, 14.9608, 48.674, -0, -153.982, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1456, -1229.07, 19.7441, 68.6628, -0, -153.982, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1456.2, -1228.47, 24.8276, 82.6252, 3.80938, -152.828, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1456.9, -1226.47, 28.9111, 108.498, -8.51368, -157.244, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1458.59, -1223.37, 31.5945, 130.616, -4.72983, -155.087, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1460.59, -1218.38, 33.5779, 143.744, -3.95611, -152.581, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1462.79, -1214.28, 34.161, 163.63, -2.68302, -155.763, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1465.3, -1209.78, 32.5228, -172.187, 4.69576e-006, -152.192, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1465.3, -1209.78, 32.5228, -172.187, 4.69576e-006, -152.192, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1466.9, -1205.68, 29.0062, -155.178, 9.47689e-005, -153.087, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1468.3, -1202.98, 24.1897, -131.11, 6.74481e-005, -153.088, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1468.59, -1202.68, 19.3732, -107.429, 3.07358e-005, -153.087, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1467.99, -1203.88, 13.5732, -89.6528, -0.153235, -155.853, -1, 2);
						Features::PlaceObjectByHash(2475986526, -1467.11, -1205.68, 10.7072, -63.5491, 8.53774e-007, -156.504, -1, 2);
						Features::PlaceObjectByHash(4109455646, -1465.05, -1210.03, 7.9503, 9.53319, 1.38057, 24.2606, -1, 2);
						Features::PlaceObjectByHash(2975320548, -1460.95, -1218.79, 7.66, -29.9323, -0.173323, 24.7221, -1, 2);
						Features::PlaceObjectByHash(2975320548, -1463.05, -1214.19, 6.7879, -6.50192, 1.391, 24.2651, -1, 2);
					}
					if (Menu::Option("Teleport")) {
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1513.0f, -1192.0f, 1.0f, 1, 0, 0, 1);
					}
					break;
#pragma region mapmode
				case ramp4:
					Menu::Title("Mount Chilliad Ramp");
					// Menu::Subtitle("MOUNT CHILLIAD RAMP");

					if (Menu::Option("Load")) {
						Features::PlaceObjectByHash(1952396163, -1497.76, -1113.84, -3.08, -90, -0, 165.792, 90, 3);
						Features::PlaceObjectByHash(2475986526, -1461.92, -1216.88, 2.5836, -2.3048, 0, -154.878, 205.14, 3);
						Features::PlaceObjectByHash(3291218330, -1458.89, -1214.4, 18, -38.4956, 0, -153.982, 211.95, 3);
						Features::PlaceObjectByHash(2475986526, -1460.32, -1219.97, 4.3801, 12.6953, 0, -154.878, 205.672, 3);
						Features::PlaceObjectByHash(2975320548, -1463.05, -1214.19, 6.7879, -6.5, -1.391, 24.2651, 24.4244, 3);
						Features::PlaceObjectByHash(3291218330, -1465.62, -1217.64, 18, 166.516, 180, 24.1717, 155.224, 3);
						Features::PlaceObjectByHash(4109455646, -1465.05, -1210.03, 7.9503, 9.5304, -1.3806, 24.2606, 24.5148, 3);
						Features::PlaceObjectByHash(2975320548, -1460.95, -1218.79, 7.66, -29.9322, 0.1733, 24.7221, 27.9617, 3);
						Features::PlaceObjectByHash(2475986526, -1458.4, -1223.77, 7.9937, 23.6001, 0.0916, -154.918, 207.065, 3);
						Features::PlaceObjectByHash(2475986526, -1467.11, -1205.68, 10.7072, -63.5491, 0, -156.505, 224.303, 3);
						Features::PlaceObjectByHash(2475986526, -1457, -1226.67, 11.8772, 31.7229, 0, -154.382, 209.411, 3);
						Features::PlaceObjectByHash(2475986526, -1456.4, -1228.27, 14.9608, 48.674, 0, -153.982, 216.471, 3);
						Features::PlaceObjectByHash(2475986526, -1456, -1229.07, 19.7441, 68.6628, 0, -153.982, 233.298, 3);
						Features::PlaceObjectByHash(2475986526, -1456.2, -1228.47, 24.8276, 81.7043, -3.8094, -152.828, 252.429, 3);
						Features::PlaceObjectByHash(2475986526, -1456.9, -1226.47, 28.9111, 110.301, 171.486, -157.244, 312.201, 3);
						Features::PlaceObjectByHash(2475986526, -1458.59, -1223.37, 31.5945, 130.843, 175.27, -155.087, 325.759, 3);
						Features::PlaceObjectByHash(2475986526, -1460.59, -1218.38, 33.5779, 143.844, 176.044, -152.581, 327.979, 3);
						Features::PlaceObjectByHash(2475986526, -1462.79, -1214.28, 34.161, 163.648, 177.317, -155.763, 335.024, 3);
						Features::PlaceObjectByHash(2475986526, -1465.3, -1209.78, 32.5228, -172.187, -180, -152.192, 331.971, 3);
						Features::PlaceObjectByHash(2475986526, -1466.9, -1205.68, 29.0062, -155.178, -180, -153.087, 330.783, 3);
						Features::PlaceObjectByHash(2475986526, -1468.3, -1202.98, 24.1897, -131.11, -180, -153.088, 322.332, 3);
						Features::PlaceObjectByHash(2475986526, -1468.59, -1202.68, 19.3732, -107.429, -180, -153.087, 300.544, 3);
						Features::PlaceObjectByHash(2475986526, -1467.99, -1203.88, 13.5732, -89.6205, 0.1532, -155.853, 269.072, 3);
						Features::PlaceObjectByHash(3966705493, 509.842, 5589.24, 791.066, 0.141, 0, 65.3998, 65.3999, 3);
						Features::PlaceObjectByHash(3966705493, 520.5, 5584.38, 790.503, 5.441, 0, 65.3998, 65.4976, 3);
						Features::PlaceObjectByHash(3966705493, 531.057, 5579.54, 788.691, 12.441, 0, 65.3998, 65.9111, 3);
						Features::PlaceObjectByHash(3966705493, 568.672, 5562.32, 767.428, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 576.972, 5558.53, 759.566, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 560.174, 5566.2, 774.698, 35.0403, 0, 65.3998, 69.4512, 3);
						Features::PlaceObjectByHash(3966705493, 541.325, 5574.84, 785.49, 19.4409, 0, 65.3998, 66.6484, 3);
						Features::PlaceObjectByHash(3966705493, 551.066, 5570.37, 780.799, 27.5407, 0, 65.3998, 67.9049, 3);
						Features::PlaceObjectByHash(3966705493, 585.249, 5554.75, 751.745, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 618.334, 5539.62, 720.386, 40.7936, 0, 65.3998, 70.8829, 3);
						Features::PlaceObjectByHash(3966705493, 626.602, 5535.85, 712.547, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 610.065, 5543.4, 728.217, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 601.777, 5547.19, 736.076, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 593.507, 5550.97, 743.917, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 634.862, 5532.07, 704.725, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 643.121, 5528.29, 696.894, 40.7936, 0, 65.3998, 70.8829, 3);
						Features::PlaceObjectByHash(3966705493, 651.391, 5524.51, 689.053, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 659.651, 5520.73, 681.221, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 667.911, 5516.94, 673.389, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 676.171, 5513.17, 665.558, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 684.431, 5509.38, 657.727, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 692.691, 5505.61, 649.905, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 700.95, 5501.83, 642.074, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 709.22, 5498.05, 634.243, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 717.46, 5494.28, 626.431, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 725.72, 5490.5, 618.6, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 733.98, 5486.72, 610.778, 40.7396, 0, 65.3998, 70.8685, 3);
						Features::PlaceObjectByHash(3966705493, 742.6, 5482.78, 603.167, 36.9395, 0, 65.3998, 69.9005, 3);
						Features::PlaceObjectByHash(3966705493, 751.83, 5478.55, 596.335, 31.0392, 0, 65.3998, 68.5807, 3);
						Features::PlaceObjectByHash(3966705493, 761.71, 5474.02, 590.613, 24.5989, 0, 65.3998, 67.3986, 3);
						Features::PlaceObjectByHash(3966705493, 772.07, 5469.28, 586.08, 18.9288, 0, 65.3998, 66.5835, 3);
						Features::PlaceObjectByHash(3966705493, 782.84, 5464.34, 582.86, 11.5788, 0, 65.3998, 65.8427, 3);
						Features::PlaceObjectByHash(3966705493, 793.89, 5459.28, 581.117, 5.0787, 0, 65.3998, 65.485, 3);
						Features::PlaceObjectByHash(3966705493, 805.1, 5454.15, 580.876, -2.5212, 0, 65.3998, 65.4208, 3);
						Features::PlaceObjectByHash(3966705493, 816.17, 5449.08, 581.975, -7.6213, 0, 65.3998, 65.5917, 3);
						Features::PlaceObjectByHash(3966705493, 827.191, 5444.04, 584.582, -16.6212, 0, 65.3998, 66.3125, 3);
						Features::PlaceObjectByHash(3966705493, 837.681, 5439.24, 588.899, -24.421, 0, 65.3998, 67.3698, 3);
						Features::PlaceObjectByHash(2580877897, 522.61, 5584.49, 779.214, 79.7153, -9.2252, 55.7018, 77.7612, 3);
						Features::PlaceObjectByHash(3862788492, 522.445, 5583.69, 779.551, -0.9197, -69.229, -167.468, 184.555, 3);
					}
					if (Menu::Option("Teleport")) {
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 500, 5593, 795, 1, 0, 0, 1);
					}

					break;
#pragma region mapmode
				case ramp5:
					Menu::Title("Airport Mini Ramp");
					// Menu::Subtitle("AIRPORT RAMP");

					if (Menu::Option("Load")) {
						Features::PlaceObjectByHash(2475986526, -1242.08, -2931.15, 12.9924, -0.1046, -3.33505e-009, 61.0607, -1, 4);
						Features::PlaceObjectByHash(2475986526, -1247.11, -2928.46, 15.013, -0.1046, -3.33505e-009, 61.0607, -1, 4);
						Features::PlaceObjectByHash(2475986526, -1251.58, -2926.05, 16.7865, -0.1046, -3.33505e-009, 61.0607, -1, 4);
						Features::PlaceObjectByHash(2475986526, -1254.69, -2924.35, 18.25, -0.1046, -3.33505e-009, 61.0607, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1276.69, -2912.99, 23.0019, 0, 0.05, 60.9705, -1, 4);
						Features::PlaceObjectByHash(2475986526, -1258.35, -2922.28, 20.2135, -0.1046, -3.33505e-009, 61.0607, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1270.89, -2916.22, 23.0123, 0, 0, 60.8909, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1270.25, -2914.99, 23.0137, 0, 0, 60.8909, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1274.87, -2909.4, 23.0049, 0, 0.05, 60.9705, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1269.01, -2912.64, 22.9993, 0, 0.05, 60.9705, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1267.87, -2915.44, 28.3632, 0, -0, 147.299, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1272.13, -2918.33, 28.4791, 0, 0.05, 60.9705, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1272.11, -2918.35, 25.6708, -0.48, 0.0499982, 60.9701, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1277.93, -2915.14, 25.604, 0, 0.05, 60.9705, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1279.69, -2909.85, 25.6358, 0, -0, -151.239, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1279.69, -2909.85, 28.4844, 0, -0, -151.239, -1, 4);
						Features::PlaceObjectByHash(2475986526, -1261.82, -2920.38, 21.767, -0.1046, -3.33505e-009, 61.0607, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1273.65, -2907.11, 22.9763, 0, 0.05, 60.9705, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1267.77, -2910.37, 22.9978, 0, 0.05, 60.9705, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1266.49, -2908.08, 22.9987, 0, -0, -119.462, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1265.15, -2905.8, 23.0042, 0, -0, -119.462, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1266.44, -2905.21, 25.6255, 0, -0, -118.761, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1265.66, -2911.99, 25.6968, 0, 0, -30.9603, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1264.88, -2910.66, 25.6982, 0, 0, -30.9603, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1264.84, -2905.14, 25.624, 0, -0, -118.761, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1272.37, -2900.96, 25.6199, 0, -0, -118.761, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1276.35, -2903.91, 25.6214, 0, -0, -151.239, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1276.35, -2903.91, 28.4329, 0, -0, -151.239, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1272.37, -2900.96, 28.4385, 0, -0, -118.761, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1266.44, -2905.21, 28.437, 0, -0, -118.761, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1265.17, -2905.14, 28.3426, 0, -0, -118.861, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1271.09, -2902.58, 23.0057, 0, -0, -119.462, -1, 4);
						Features::PlaceObjectByHash(3966705493, -1272.37, -2904.83, 22.9972, 0, -0, -119.462, -1, 4);
					}
					if (Menu::Option("Teleport")) {
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1208, -2950, 13, 1, 0, 0, 1);
					}

					break;
#pragma region mapmode
				case ramp6:
					Menu::Title("Airport Gate Ramp");
					// Menu::Subtitle("AIRPORT GATE RAMP");

					if (Menu::Option("Load")) {
						Features::PlaceObjectByHash(2475986526, -1098.36, -2631.17, 19, 0, -0, 152.671, -1, 5);
						Features::PlaceObjectByHash(2475986526, -1100.26, -2634.64, 21.1976, 16.2002, 0.192059, 150.427, -1, 5);
						Features::PlaceObjectByHash(2475986526, -1102.26, -2638.02, 25.01, 26.7003, 0.178675, 149.261, -1, 5);
						Features::PlaceObjectByHash(2475986526, -1103.96, -2640.91, 29.04, 28.3717, -0, 146.82, -1, 5);
						Features::PlaceObjectByHash(1952396163, -1119.61, -2670.96, -5.125, 0, -0, 150.514, -1, 5);
						Features::PlaceObjectByHash(1952396163, -1119.61, -2670.96, -5.125, 0, -0, 150.401, -1, 5);
						Features::PlaceObjectByHash(3137065507, -1044.69, -2530.08, 20.4011, 94.8962, 4.26887e-007, 147.716, -1, 5);
					}
					if (Menu::Option("Teleport")) {
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1046, -2538, 20, 1, 0, 0, 1);
					}

					break;
#pragma region mapmode
				case ramp7:
					Menu::Title("UFO Tower");
					// Menu::Subtitle("UFO TOWER");

					if (Menu::Option("Load")) {
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 654.365, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 646.186, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 638.008, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 629.829, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 621.65, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 613.471, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 605.292, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 597.114, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 588.935, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 580.756, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 572.577, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 564.399, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 556.22, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 662.544, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 548.041, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 539.862, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 531.683, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 523.505, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 515.326, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 507.147, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 498.968, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 490.79, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 482.611, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 474.432, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 466.253, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 458.074, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 449.896, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 441.717, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 433.538, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 425.359, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 417.18, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 409.001, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 400.823, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 392.644, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 384.465, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 376.286, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 368.107, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 359.929, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 351.75, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 343.571, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 335.392, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 327.213, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 319.035, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 310.856, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 302.677, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 294.498, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 286.319, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 278.141, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 269.962, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 261.783, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 253.604, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 245.425, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 237.247, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 229.068, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 220.889, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 212.71, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 204.531, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 196.353, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 188.174, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 179.995, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 171.816, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 163.637, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 155.459, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 147.28, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 139.101, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 130.922, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 122.743, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 114.565, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 106.386, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 98.207, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 90.0282, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 81.8494, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 73.6706, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 65.4918, 0.660085, -0.919939, -109.32, -1, 6);
						Features::PlaceObjectByHash(3026699584, 70.2592, -674.044, 57.313, 0.660085, -0.919939, -109.32, -1, 6);
					}
					if (Menu::Option("Teleport")) {
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 70, -674, 680, 1, 0, 0, 1);
					}
					break;
#pragma region mapmode
				case ramp8:
					Menu::Title("Maze Bank Quad Ramp");
					// Menu::Subtitle("MAZE BANK QUAD RAMP");

					if (Menu::Option("Load")) {
						Features::PlaceObjectByHash(3522933110, -81.3886, -814.648, 325.169, 0, -0, 180, -1, 7);
						Features::PlaceObjectByHash(3681122061, -81.7456, -809.064, 324.799, 0.500021, 2.66804, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -86.1333, -802.279, 321.92, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -89.7406, -796.701, 316.539, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -93.601, -790.725, 310.777, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -97.4741, -784.73, 304.997, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -101.373, -778.696, 299.179, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -105.233, -772.72, 293.417, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -109.106, -766.725, 287.637, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -112.954, -760.769, 281.894, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -116.827, -754.773, 276.113, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -120.687, -748.798, 270.352, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -124.518, -742.868, 264.636, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -128.358, -736.925, 258.909, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -132.22, -730.949, 253.151, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -136.081, -724.974, 247.394, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -139.943, -718.998, 241.636, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -143.826, -712.99, 235.846, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -147.667, -707.047, 230.12, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -151.508, -701.104, 224.394, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -155.369, -695.128, 218.636, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -159.252, -689.12, 212.846, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -163.072, -683.209, 207.152, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -166.976, -677.168, 201.331, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -170.838, -671.193, 195.573, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -174.7, -665.217, 189.815, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -178.583, -659.209, 184.026, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -182.444, -653.233, 178.268, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -186.327, -647.225, 172.479, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -190.189, -641.249, 166.721, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -194.03, -635.306, 160.994, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -197.871, -629.363, 155.268, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -201.711, -623.42, 149.542, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -205.552, -617.477, 143.815, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -209.393, -611.534, 138.089, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -213.255, -605.559, 132.331, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -217.095, -599.616, 126.605, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -220.957, -593.64, 120.847, -38.9999, -1.45141, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -222.245, -591.648, 118.928, -33.8999, 1.02453, 32.8807, -1, 7);
						Features::PlaceObjectByHash(3681122061, -223.349, -589.94, 117.561, -29.31, 1.79292, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -224.58, -588.036, 116.288, -26.25, 5.12264, 32.8807, -1, 7);
						Features::PlaceObjectByHash(3681122061, -225.869, -586.04, 115.116, -24.7199, -1.10991, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -227.127, -584.095, 114.05, -21.6599, 1.8783, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -228.615, -581.794, 112.961, -19.6199, 1.02453, 32.8807, -1, 7);
						Features::PlaceObjectByHash(3681122061, -230.201, -579.341, 111.92, -17.0699, -0, 32.8807, -1, 7);
						Features::PlaceObjectByHash(3681122061, -232.121, -576.369, 110.833, -12.9899, 4.26887, 32.8808, -1, 7);
						Features::PlaceObjectByHash(3681122061, -234.105, -573.302, 109.991, -9.9299, -2.98821, 32.8807, -1, 7);
						Features::PlaceObjectByHash(3681122061, -236.628, -569.396, 109.329, -7.3799, -4.26887, 32.8807, -1, 7);
						Features::PlaceObjectByHash(3681122061, -239.81, -564.475, 108.721, -4.3199, 1.28066, 32.8807, -1, 7);
						Features::PlaceObjectByHash(3681122061, -241.76, -561.459, 108.549, -0.7499, -1.12058, 32.8807, -1, 7);
						Features::PlaceObjectByHash(3681122061, -244.04, -557.932, 108.494, 2.82011, -2.77476, 32.8807, -1, 7);
						Features::PlaceObjectByHash(3681122061, -246.372, -554.326, 108.705, 5.8801, -2.77476, 32.8807, -1, 7);
						Features::PlaceObjectByHash(3681122061, -248.668, -550.777, 109.14, 10.4701, 8.96462, 32.8806, -1, 7);
						Features::PlaceObjectByHash(3681122061, -251.664, -546.138, 110.313, 13.5301, 1.15259, 32.8806, -1, 7);
						Features::PlaceObjectByHash(3681122061, -254.537, -541.694, 111.791, 16.5901, 4.26887, 32.8807, -1, 7);
						Features::PlaceObjectByHash(3681122061, -256.28, -538.999, 112.748, 19.6501, -1.19528, 32.8807, -1, 7);
						Features::PlaceObjectByHash(3681122061, -65.9078, -814.752, 326.106, 19.89, 4.26887, -53.8105, -1, 7);
						Features::PlaceObjectByHash(3681122061, -58.6541, -809.444, 327.336, -4.08004, -2.13443, -53.8103, -1, 7);
						Features::PlaceObjectByHash(3681122061, -52.4476, -804.909, 323.715, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, -47.2332, -801.09, 317.168, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, -42.0187, -797.272, 310.621, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, -36.8326, -793.474, 304.109, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, -31.5898, -789.635, 297.526, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, -26.4037, -785.838, 291.014, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, -21.1893, -782.019, 284.467, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, -15.9748, -778.201, 277.919, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, -10.7604, -774.383, 271.372, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, -5.57426, -770.585, 264.86, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, -0.359839, -766.767, 258.313, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, 4.82623, -762.969, 251.799, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, 10.0123, -759.171, 245.285, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, 15.2268, -755.353, 238.735, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, 20.4412, -751.535, 232.184, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, 25.6273, -747.737, 225.67, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, 30.8135, -743.939, 219.155, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, 36.0279, -740.121, 212.605, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, 41.214, -736.323, 206.091, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, 46.4285, -732.505, 199.54, -45.3899, 2.56132, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, 48.4122, -731.052, 197.049, -41.8198, 1.62217, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, 49.5549, -730.218, 195.782, -38.2499, 3.24434, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, 51.171, -729.035, 194.203, -36.2098, 2.39057, -53.81, -1, 7);
						Features::PlaceObjectByHash(3681122061, 52.8966, -727.773, 192.637, -33.1499, -6.83019, -53.8101, -1, 7);
						Features::PlaceObjectByHash(3681122061, 54.586, -726.537, 191.27, -30.0898, 8.70849, -53.8099, -1, 7);
						Features::PlaceObjectByHash(3681122061, 56.5413, -725.105, 189.866, -25.4998, 7.59859, -53.8099, -1, 7);
						Features::PlaceObjectByHash(3681122061, 58.8359, -723.425, 188.509, -22.4398, 4.26887, -53.81, -1, 7);
						Features::PlaceObjectByHash(3681122061, 60.738, -722.033, 187.536, -18.3599, 1.10991, -53.81, -1, 7);
						Features::PlaceObjectByHash(3681122061, 63.1509, -720.268, 186.544, -15.8098, 5.03727, -53.8099, -1, 7);
						Features::PlaceObjectByHash(3681122061, 65.131, -718.821, 185.849, -12.7498, 5.07995, -53.8099, -1, 7);
						Features::PlaceObjectByHash(3681122061, 67.1384, -717.352, 185.286, -9.17981, 4.78113, -53.81, -1, 7);
						Features::PlaceObjectByHash(3681122061, 69.2894, -715.776, 184.855, -4.5898, 4.18349, -53.8099, -1, 7);
						Features::PlaceObjectByHash(3681122061, 71.7831, -713.952, 184.607, 0.000193536, 4.16213, -53.8099, -1, 7);
						Features::PlaceObjectByHash(3681122061, 74.0832, -712.268, 184.607, 3.06019, 3.7566, -53.81, -1, 7);
						Features::PlaceObjectByHash(3681122061, 76.0175, -710.853, 184.736, 8.1602, 4.35424, -53.81, -1, 7);
						Features::PlaceObjectByHash(3681122061, 77.7752, -709.567, 185.048, 13.2602, 5.50684, -53.81, -1, 7);
						Features::PlaceObjectByHash(3681122061, 79.6997, -708.158, 185.61, 17.3402, 3.7566, -53.8099, -1, 7);
						Features::PlaceObjectByHash(3681122061, 81.3947, -706.918, 186.266, 21.9302, 4.26887, -53.81, -1, 7);
						Features::PlaceObjectByHash(3681122061, 83.3036, -705.52, 187.219, 26.0102, 9.39151, -53.8099, -1, 7);
						Features::PlaceObjectByHash(3681122061, 85.6244, -703.821, 188.622, 29.0702, 1.96368, -53.8099, -1, 7);
						Features::PlaceObjectByHash(3681122061, 87.3526, -702.556, 189.812, 33.1501, 2.90283, -53.8098, -1, 7);
						Features::PlaceObjectByHash(3681122061, 89.2107, -701.196, 191.316, 37.2301, 4.86651, -53.8098, -1, 7);
						Features::PlaceObjectByHash(3681122061, 90.8492, -699.998, 192.859, 41.82, -2.56132, -53.8099, -1, 7);
						Features::PlaceObjectByHash(3681122061, 92.6236, -698.701, 194.826, 46.41, 8.2816, -53.8099, -1, 7);
						Features::PlaceObjectByHash(3681122061, 94.2096, -697.539, 196.89, 52.0199, 6.57406, -53.8098, -1, 7);
						Features::PlaceObjectByHash(3681122061, 95.6251, -696.503, 199.137, 56.61, 9.22075, -53.8097, -1, 7);
						Features::PlaceObjectByHash(3681122061, 96.9799, -695.512, 201.683, 61.7098, 8.53774, -53.8097, -1, 7);
						Features::PlaceObjectByHash(3681122061, 98.1658, -694.646, 204.413, 65.7899, 5.03726, -53.8096, -1, 7);
						Features::PlaceObjectByHash(3681122061, -69.0186, -829.452, 324.775, 0, -0, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -65.276, -836.288, 321.491, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -62.2554, -842.061, 315, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -59.2515, -847.802, 308.544, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -56.2313, -853.574, 302.053, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -53.1945, -859.378, 295.526, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -50.2071, -865.088, 289.106, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -47.2032, -870.829, 282.65, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -44.1829, -876.602, 276.159, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -41.1626, -882.374, 269.667, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -38.1751, -888.084, 263.247, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -35.1713, -893.825, 256.791, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -32.1674, -899.566, 250.335, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -29.1635, -905.307, 243.879, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -26.1432, -911.079, 237.388, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -23.1393, -916.821, 230.932, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -20.119, -922.593, 224.44, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -17.1152, -928.334, 217.985, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -14.1112, -934.075, 211.529, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -11.1235, -939.785, 205.108, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -8.13589, -945.495, 198.687, -44.8796, 3.24434, -152.398, -1, 7);
						Features::PlaceObjectByHash(3681122061, -5.28891, -951.101, 192.102, -47.4298, -1.79292, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, -2.35757, -956.552, 185.364, -47.4298, -1.79292, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 0.589775, -962.033, 178.59, -47.4298, -1.79292, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 3.5211, -967.483, 171.852, -47.4298, -1.79292, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 9.3998, -978.414, 158.339, -47.4298, -1.79292, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 6.46847, -972.964, 165.077, -47.4298, -1.79292, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 12.3311, -983.865, 151.601, -47.4298, -1.79292, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 15.2944, -989.375, 144.789, -47.4298, -1.79292, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 21.1569, -1000.28, 131.313, -47.4298, -1.79292, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 18.2417, -994.856, 138.014, -47.4298, -1.79292, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 24.0722, -1005.7, 124.612, -47.4298, -1.79292, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 27.0355, -1011.21, 117.801, -47.4298, -1.79292, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 29.9828, -1016.69, 111.026, -47.4298, -1.79292, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 35.8294, -1027.56, 97.5867, -47.4298, -1.79292, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 37.2241, -1030.15, 94.4555, -44.3698, -1.70754, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 38.7475, -1032.99, 91.3086, -39.7798, -4.26887, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 39.7483, -1034.85, 89.5491, -36.7197, 3.4151, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 40.9818, -1037.14, 87.6062, -33.6597, -2.21981, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 42.1248, -1039.27, 85.999, -30.0898, -1.96368, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 32.9141, -1022.14, 104.288, -47.4298, -1.79292, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 43.3132, -1041.47, 84.5449, -26.5197, -1.79293, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 44.7115, -1044.08, 83.0715, -23.4597, -2.39056, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 45.9496, -1046.38, 81.937, -20.3997, -2.47594, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 47.0815, -1048.48, 81.0483, -17.3397, -2.09174, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 48.302, -1050.75, 80.2436, -14.7897, -8.96462, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 50.0647, -1054.03, 79.2608, -13.2597, -2.77476, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 52.0238, -1057.67, 78.2861, -11.7297, -1.45141, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 53.7395, -1060.86, 77.5341, -9.17973, -1.1099, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 55.7265, -1064.56, 76.8558, -6.11973, -6.61674, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 57.3746, -1067.62, 76.4825, -3.56972, -9.60496, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 59.3125, -1071.23, 76.2272, 0.000276446, -9.05818, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 61.112, -1074.58, 76.2272, 4.08028, -8.00412, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 62.529, -1077.21, 76.4405, 7.65027, -7.04364, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 64.0779, -1080.1, 76.8796, 10.7103, -1.28066, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 65.9388, -1083.55, 77.623, 14.2802, -1.70755, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 67.4076, -1086.29, 78.4126, 17.3403, -1.57948, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, 68.7639, -1088.81, 79.3066, 21.4202, 1.36604, -151.734, -1, 7);
						Features::PlaceObjectByHash(3681122061, -86.0915, -825.576, 324.775, 0, -0, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -99.1939, -833.684, 315.911, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -105.248, -837.511, 310.056, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -93.1729, -829.876, 321.734, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -111.268, -841.319, 304.233, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -123.245, -848.891, 292.651, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -147.333, -864.12, 269.359, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -141.278, -860.292, 275.213, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -135.256, -856.485, 281.036, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -129.266, -852.699, 286.828, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -117.224, -845.084, 298.474, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -165.367, -875.521, 251.921, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -213.415, -905.895, 205.464, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -207.426, -902.108, 211.255, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -201.403, -898.301, 217.078, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -195.414, -894.515, 222.87, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -183.434, -886.942, 234.452, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -177.445, -883.156, 240.244, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -171.422, -879.348, 246.067, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -159.378, -871.734, 257.713, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -153.355, -867.927, 263.536, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -189.424, -890.728, 228.661, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -231.449, -917.296, 188.027, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -225.46, -913.509, 193.818, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -219.47, -909.723, 199.609, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -237.439, -921.082, 182.235, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -284.806, -951.016, 167.673, 28.5601, -7.5132, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -289.048, -953.697, 170.578, 34.1701, -3.41509, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -290.727, -954.757, 171.926, 37.23, 3.41509, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -286.998, -952.399, 169.084, 31.62, -1.36604, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -282.375, -949.481, 166.27, 26.0101, 3.50047, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -280.014, -947.991, 165.174, 21.4201, -6.83019, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -277.4, -946.336, 164.178, 17.8501, -3.15896, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -270.266, -941.827, 162.896, 4.59013, -1.79292, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -266.683, -939.562, 163.103, -6.11989, -1.38738, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -259.328, -934.913, 165.339, -17.8499, -4.69576, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -253.478, -931.22, 168.474, -26.01, -4.18349, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -248.103, -927.823, 172.247, -33.66, -5.97642, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -243.429, -924.868, 176.444, -39.27, -2.30519, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -256.593, -933.187, 166.676, -22.4399, -5.97641, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -262.183, -936.72, 164.252, -14.2799, -3.20165, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -268.321, -940.597, 162.896, 0.000125527, -1.95033, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -272.668, -943.344, 163.123, 8.67012, -2.86014, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -275.091, -944.877, 163.561, 12.7501, -5.1226, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -249.757, -928.867, 170.944, -31.11, -6.0617, 122.286, -1, 7);
						Features::PlaceObjectByHash(3681122061, -251.566, -930.012, 169.653, -27.54, -3.58585, 122.286, -1, 7);
					}
					if (Menu::Option("Teleport")) {
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
					}

					break;
#pragma region mapmode
				case ramp9:
					Menu::Title("Fort Zancudo Motorcross");
					// Menu::Subtitle("FORT ZANCUDO MOTOCROSS");

					if (Menu::Option("Load")) {
						Features::PlaceObjectByHash(3213433054, -2661.22, 3209.43, 32.7118, 0, -0, -120.437, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2657.86, 3207.56, 32.7118, 0, 0, 59.6808, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2659.52, 3212.33, 32.7118, 0, -0, -120.437, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2656.2, 3210.41, 32.7118, 0, 0, 59.6808, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2654.54, 3213.26, 32.7118, 0, 0, 59.6808, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2657.84, 3215.18, 32.7118, 0, -0, -120.437, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2615.14, 3183, 32.8118, 0, -0, -120.45, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2611.82, 3181.02, 32.8118, 0, 0, 58.529, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2613.47, 3185.85, 32.8118, 0, -0, -120.45, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2610.11, 3183.91, 32.8118, 0, 0, 59.589, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2611.79, 3188.7, 32.8118, 0, -0, -120.45, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2608.46, 3186.71, 32.8118, 0, 0, 58.529, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2550.83, 3162.65, 32.7702, 0, -0, -117.989, -1, 8);
						Features::PlaceObjectByHash(4109455646, -2547.01, 3160.66, 34.9496, 11.66, -2.56132e-006, -118.95, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2476.76, 3120.72, 32.7718, 0, -0, -119.612, -1, 8);
						Features::PlaceObjectByHash(4109455646, -2473.51, 3118.83, 34.5672, 8.47412, -0.0223369, -120.965, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2442.43, 3105.7, 35.6224, -7.42001, -5.12265e-006, 150.074, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2443.67, 3101.83, 35.8732, -11.66, 3.84198e-006, 59.738, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2438.8, 3099, 36.0155, -11.66, -6.40331e-006, 59.7379, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2434.05, 3096.22, 36.6871, -22.26, -1.45141e-005, 59.7379, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2446.85, 3098.2, 35.6088, -7.42, 3.20165e-006, -31.8463, -1, 8);
						Features::PlaceObjectByHash(2402097066, -2448.77, 3097.65, 35.4732, 0, -0, -120.616, -1, 8);
						Features::PlaceObjectByHash(2402097066, -2442.95, 3108.08, 35.4832, 0, -0, -117.436, -1, 8);
						Features::PlaceObjectByHash(2402097066, -2442.95, 3108.08, 35.4832, 0, -0, -117.436, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2389.55, 3069.11, 36.5952, 179.801, -3.76861e-006, -117.806, -1, 8);
						Features::PlaceObjectByHash(1982829832, -2363.33, 3056.01, 31.8257, 0, -0, -119.219, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2389.55, 3069.11, 36.5952, 179.801, -3.76861e-006, -117.806, -1, 8);
						Features::PlaceObjectByHash(2609922146, -2358.79, 3060.59, 31.8217, 0, -0, -119.371, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2325.93, 3034.99, 33.3214, 19.8, 3.41509e-006, -120.09, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2321.78, 3032.58, 36.3899, 25.7399, -8.62311e-005, -120.09, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2317.79, 3030.29, 39.6222, 25.0799, -6.23256e-005, -120.09, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2313.74, 3027.94, 42.9228, 25.7399, -8.62311e-005, -120.09, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2309.83, 3025.69, 46.2289, 27.06, -8.2816e-005, -120.09, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2306.07, 3023.49, 49.5919, 29.0399, -0.000116113, -120.09, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2283.14, 3009.97, 44.7284, 14.12, -2.04906e-005, 60.0397, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2287.5, 3012.47, 46.9591, 13.6, 0.680011, 60.0397, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2302.26, 3021.28, 53.174, 29.6999, -0.000100745, -120.09, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2292.06, 3015.11, 49.2546, 13.6, 1.53679e-005, 60.0397, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2298.56, 3019.12, 56.7472, 30.36, -8.79386e-005, -120.09, -1, 8);
						Features::PlaceObjectByHash(2052512905, -2294.52, 3015.08, 58.6366, 82.6616, 0.00430302, -31.2919, -1, 8);
						Features::PlaceObjectByHash(2052512905, -2293.13, 3017.4, 58.6822, 80.9428, 0.00560716, 149.187, -1, 8);
						Features::PlaceObjectByHash(2787492567, -2293.66, 3016.58, 31.8318, -90, 0.0833042, 109.919, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2202.78, 2963.39, 32.8003, 0, -0, -120.04, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2199.53, 2961.53, 34.17, -40.5599, -2.56132e-006, 59.8803, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2137.1, 2904.97, 32.8327, 16.8, -1.10991e-005, -141.061, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2132.27, 2897.94, 34.4465, 16.8, -14, -141.061, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2127.12, 2890.88, 36.4432, 17.92, -29.68, -136.581, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2119.98, 2885.33, 38.8379, 17.92, -29.68, -136.581, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2113.02, 2880, 41.2705, 17.92, -29.68, -136.581, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2085.18, 2857.71, 49.9177, 19.04, -43.12, -136.581, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2078.1, 2852.44, 51.662, 19.0399, -50.4001, -136.581, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2092.05, 2863.54, 48.2285, 17.92, -34.16, -136.581, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2098.91, 2869.18, 46.2053, 17.92, -29.68, -136.581, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2105.97, 2874.59, 43.7379, 17.92, -29.68, -136.581, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2070.42, 2847.69, 53.5814, 19.0399, -50.4001, -136.581, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2062.85, 2843.01, 55.4739, 19.0399, -50.4001, -136.581, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2055.32, 2838.69, 56.5097, 17.7868, -43.8868, -131.905, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2047.61, 2834.88, 58.9097, 26.1867, -43.8868, -131.905, -1, 8);
						Features::PlaceObjectByHash(3681122061, -2039.74, 2832.2, 62.2769, 38.5067, -45.5668, -131.905, -1, 8);
						Features::PlaceObjectByHash(3681122061, -1996.98, 2830.2, 48.384, 0.202822, -14.4337, -105.503, -1, 8);
						Features::PlaceObjectByHash(3681122061, -1996.42, 2832.89, 59.0601, -179.433, 12.3451, 76.9258, -1, 8);
						Features::PlaceObjectByHash(3213433054, -1951.86, 2849.63, 34.5146, -47.5199, -7.59859e-005, 59.6261, -1, 8);
						Features::PlaceObjectByHash(3213433054, -1950.16, 2852.52, 34.5146, -47.5199, -7.59859e-005, 59.6261, -1, 8);
						Features::PlaceObjectByHash(3213433054, -1953.57, 2854.49, 32.8004, 0, -0, -120.091, -1, 8);
						Features::PlaceObjectByHash(3213433054, -1955.25, 2851.59, 32.8004, 0, -0, -120.091, -1, 8);
						Features::PlaceObjectByHash(4111834409, -1960.72, 2857.38, 31.7305, 0, -0, -118.505, -1, 8);
						Features::PlaceObjectByHash(4109455646, -2144, 2967.21, 36.0606, 9.35852, -0.00134085, 59.8371, -1, 8);
						Features::PlaceObjectByHash(4109455646, -2139.63, 2964.67, 33.9985, 5.84852, -0.0013321, 59.8371, -1, 8);
						Features::PlaceObjectByHash(4109455646, -2135.45, 2962.3, 32.4604, 0, 0, 60.4792, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2193.23, 2995.21, 35.0684, 11.6996, -0.00262322, -119.238, -1, 8);
						Features::PlaceObjectByHash(2975320548, -2197.74, 2997.74, 32.8074, 15.2099, 2.04906e-005, -119.328, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2246.82, 3026.19, 33.0318, 0.0331696, 0.0056356, 58.6423, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2256.38, 3032.02, 35.4343, 6.5707, 0.0279573, 58.7685, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2265.19, 3037.37, 38.408, 10.1262, 0.0254109, 58.7585, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2273.45, 3042.38, 40.214, 8.95404, -0.00182451, 58.7729, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2281.36, 3047.19, 42.7382, 8.89319, 0.151422, 58.8279, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2289.41, 3052.05, 46.2871, 13.2, 0.000150264, 58.7642, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2397.86, 3114.2, 32.8449, 0, 0, 60.2049, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2402.38, 3116.77, 34.7648, 0, 0, 60.2049, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2394.65, 3118.07, 32.5452, 0, 0, 56.6241, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2397.73, 3120.09, 34.1452, 2.04, -1.38738e-006, 56.6241, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2401.78, 3122.77, 36.6227, 8.16, 1.28066e-006, 56.6239, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2405.48, 3125.2, 39.5571, 14.28, 1.02453e-005, 56.6239, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2409.12, 3127.6, 43.2064, 20.4, -2.39057e-005, 56.6239, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2412.29, 3129.71, 46.9494, 24.4781, -1.44125, 56.2632, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2415.18, 3131.49, 51.529, 38.3931, -3.70399, 55.299, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2416.96, 3132.28, 56.2986, 54.0331, -3.70398, 53.2589, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2417.37, 3132.16, 61.6124, 73.753, -3.70394, 53.2588, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2416.48, 3131.04, 66.996, 90.9129, -3.70395, 53.2587, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2414.88, 3129.5, 70.998, 104.113, -3.70383, 50.6186, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2412.46, 3127.2, 74.61, 116.653, -3.70392, 50.6185, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2409.58, 3124.71, 77.6119, 121.273, -3.70395, 50.6185, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2406.75, 3122.18, 80.0586, 127.213, -3.70391, 50.6184, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2403.38, 3119.23, 82.2502, 135.793, -3.70396, 50.6185, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2369.71, 3092.81, 68.2807, -146.327, -3.7039, 50.6183, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2367.45, 3091.4, 63.3347, -134.447, -3.70392, 50.6182, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2366, 3090.66, 58.0814, -123.887, -3.7039, 50.6182, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2365.38, 3090.57, 53.1623, -112.007, -3.70391, 50.6182, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2365.62, 3091.18, 48.0172, -99.4666, -3.70393, 50.6181, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2366.77, 3092.54, 43.04, -86.2661, -3.70399, 50.6181, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2368.73, 3094.52, 38.5669, -74.386, -3.70392, 50.6181, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2371.25, 3096.8, 35.0692, -59.206, -3.70384, 55.2379, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2375.18, 3099.61, 32.3997, -42.0459, -3.70387, 57.2179, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2395.69, 3112.77, 84.6355, 152.292, -3.70389, 50.6184, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2391.54, 3109.37, 84.6603, 162.192, -3.70393, 50.6184, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2387.13, 3105.84, 83.6595, 172.752, -3.70391, 50.6184, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2382.97, 3102.56, 81.8101, -179.988, -3.70391, 50.6184, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2372.52, 3094.76, 72.6855, -154.907, -3.70391, 50.6183, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2379.11, 3099.59, 79.371, -172.728, -3.70391, 50.6183, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2375.46, 3096.85, 76.1692, -162.168, -3.70388, 50.6182, -1, 8);
						Features::PlaceObjectByHash(2475986526, -2399.8, 3116.19, 83.7512, 143.712, -3.70387, 50.6184, -1, 8);
						Features::PlaceObjectByHash(3213433054, -2510.73, 3180.4, 32.8111, 0, 0, 59.4291, -1, 8);
						Features::PlaceObjectByHash(209943352, -2302.92, 3059.95, 50.2208, 76.8397, -0.679965, -120.716, -1, 8);
						Features::PlaceObjectByHash(209943352, -2298.84, 3057.5, 48.7042, 71.3997, -0.679954, -120.716, -1, 8);
						Features::PlaceObjectByHash(209943352, -2290.6, 3052.58, 47.3498, 84.3198, -0.679946, -120.716, -1, 8);
						Features::PlaceObjectByHash(209943352, -2290.6, 3052.58, 47.3498, 84.3198, -0.679946, -120.716, -1, 8);
						Features::PlaceObjectByHash(209943352, -2294.73, 3055.05, 47.6692, 76.8398, -0.680059, -120.716, -1, 8);
						Features::PlaceObjectByHash(209943352, -2533.2, 3193.91, 37.3948, 0, -0, -120.716, -1, 8);
						Features::PlaceObjectByHash(209943352, -2533.2, 3193.91, 37.3948, 0, -0, -120.716, -1, 8);
						Features::PlaceObjectByHash(209943352, -2425.58, 3091.36, 36.493, 0, -0, -120.716, -1, 8);
						Features::PlaceObjectByHash(209943352, -2425.58, 3091.36, 36.493, 0, -0, -120.716, -1, 8);
						Features::PlaceObjectByHash(209943352, -2293.7, 3012.65, 55.3685, -89.7587, -0.659716, -30.2946, -1, 8);
						Features::PlaceObjectByHash(209943352, -2293.7, 3012.65, 55.3685, -89.7587, -0.659716, -30.2946, -1, 8);
					}
					if (Menu::Option("Teleport")) {
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -2731, 3259, 32, 1, 0, 0, 1);
					}

					break;
#pragma region mapmode
				case ramp10:
					Menu::Title("Halfpipe Fun Track");
					// Menu::Subtitle("HALFPIPE FUN TRACK");

					if (Menu::Option("Load")) {
						Features::PlaceObjectByHash(3681122061, -1018.78, -2937.26, 12.9646, 0, 0, -30.3132, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1023.38, -2945.17, 12.9646, 0, 0, -30.3132, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1028.02, -2953.13, 12.9646, 0, 0, -30.3132, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1032.66, -2961.06, 12.9646, 0, 0, -30.3132, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1037.32, -2969.04, 12.9646, 0, 0, -30.3132, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1041.95, -2976.96, 12.9646, 0, 0, -30.3132, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1046.18, -2984.19, 12.9646, 0, 0, -30.3132, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1050.78, -2992.12, 12.9646, 0, 0, -29.8732, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1053.22, -2998.13, 12.9646, 0, 0, -14.2534, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1054.14, -3005.28, 12.9646, 0, 0, -0.613478, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1053.45, -3012.85, 12.9646, 0, 0, 11.4866, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1051.19, -3020.08, 12.9646, 0, 0, 23.3667, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1047.43, -3026.73, 12.9646, 0, 0, 35.2469, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1042.42, -3032.37, 12.9646, 0, 0, 47.7871, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1037.1, -3038.16, 12.9646, 0, 0, 37.2273, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1033.11, -3044.75, 12.9646, 0, 0, 25.5675, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1030.43, -3052.11, 12.9646, 0, 0, 14.5676, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1029.18, -3059.85, 12.9646, 0, 0, 4.00757, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1029.37, -3067.7, 12.9646, 0, 0, -6.55247, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1031, -3075.33, 12.9646, 0, 0, -17.5525, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1034.09, -3082.35, 12.9646, 0, 0, -29.6525, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1038.6, -3088.77, 12.9646, 0, 0, -40.2127, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1044.19, -3094.15, 12.9646, 0, 0, -51.653, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1050.65, -3098.2, 12.9646, 0, 0, -63.7531, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1057.89, -3100.91, 12.9646, 0, 0, -75.1935, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1065.18, -3101.87, 12.9646, 0, 0, -89.7139, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1073.03, -3101.2, 12.9646, 0, -0, -100.054, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1080.63, -3099.11, 12.9646, 0, -0, -110.615, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1087.92, -3095.65, 12.9646, 0, -0, -119.855, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1095.95, -3091.03, 12.9646, 0, -0, -119.855, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1104.01, -3086.4, 12.9646, 0, -0, -119.855, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1112.04, -3081.79, 12.9646, 0, -0, -119.855, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1120.04, -3077.19, 12.9646, 0, -0, -119.855, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1128.1, -3072.56, 12.9646, 0, -0, -119.855, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1136.15, -3067.93, 12.9646, 0, -0, -119.855, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1144.2, -3063.31, 12.9646, 0, -0, -119.855, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1152.22, -3058.7, 12.9646, 0, -0, -119.855, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1160.24, -3054.09, 12.9646, 0, -0, -119.855, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1168.22, -3049.48, 12.9646, 0, -0, -120.295, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1176.21, -3044.8, 12.9646, 0, -0, -120.295, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1183.28, -3040.14, 12.9646, 0, -0, -126.455, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1189.23, -3034.89, 12.9646, 0, -0, -136.356, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1193.86, -3028.84, 12.9646, 0, -0, -148.677, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1197.2, -3021.86, 12.9646, 0, -0, -159.898, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1198.78, -3014.77, 12.9646, 0, -0, -174.639, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1198.72, -3007.04, 12.9646, 0, -0, 173.701, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1197, -2999.97, 12.9646, 0, -0, 158.962, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1193.5, -2993.3, 12.9646, 0, -0, 145.982, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1188.51, -2987.1, 12.9646, 0, -0, 136.083, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1182.5, -2981.85, 12.9646, 0, -0, 126.183, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1175.98, -2978.23, 12.9646, 0, -0, 112.104, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1168.67, -2976.15, 12.9646, 0, -0, 99.7843, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1160.82, -2975.53, 12.9646, 0, 0, 89.4449, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1152.93, -2976.29, 12.9646, 0, 0, 79.5455, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1145.21, -2978.39, 12.9646, 0, 0, 70.0859, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1138.14, -2981.75, 12.9646, 0, 0, 59.0863, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1130.27, -2986.43, 12.9646, 0, 0, 59.0863, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1122.46, -2991.09, 12.9646, 0, 0, 59.0863, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1115.12, -2994.75, 12.9646, 0, 0, 67.1435, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1107.63, -2997.13, 12.9646, 0, 0, 76.9913, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1099.8, -2998.14, 12.9646, 0, 0, 86.8389, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1091.94, -2997.76, 12.9646, 0, -0, 97.5819, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1084.47, -2995.95, 12.9646, 0, -0, 108.325, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1077.64, -2992.78, 12.9646, 0, -0, 119.963, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1077.64, -2992.78, 12.9646, 0, -0, 119.963, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1071.68, -2988.3, 12.9646, 0, -0, 132.496, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1066.33, -2982.53, 12.9646, 0, -0, 141.449, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1053.01, -2960.01, 12.9646, 0, 0, -28.5532, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1048.58, -2951.88, 12.9646, 0, 0, -28.5532, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1044.16, -2943.76, 12.9646, 0, 0, -28.5532, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1039.74, -2935.64, 12.9646, 0, 0, -28.5532, -1, 9);
						Features::PlaceObjectByHash(3681122061, -1035.5, -2927.86, 12.9646, 0, 0, -28.5532, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1063.23, -2993.67, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1067.37, -2998.06, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1063.7, -2994.67, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1064.21, -2995.73, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1064.71, -2996.8, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1065.21, -2997.84, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1067.1, -2999.45, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1065.43, -3000.24, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1068.29, -3000.06, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1065.92, -3001.18, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1066.44, -3002.28, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1065.35, -3002.77, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1065.6, -3003.96, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1066.11, -3005.04, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1064.21, -2999.56, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1069.53, -3000.82, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1070.75, -3001.52, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1068.76, -3002.46, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1069.29, -3003.54, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1068.44, -3005.23, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1071.58, -3003.74, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(2475986526, -1072.98, -3006.81, 16.0846, 0, 0, -26.0348, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1072.44, -3002.05, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1073.73, -3002.72, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(2475986526, -1076.54, -3005.07, 16.0846, 0, 0, -26.0348, -1, 9);
						Features::PlaceObjectByHash(2475986526, -1078.92, -3009.92, 13.7046, 0, 0, -26.0348, -1, 9);
						Features::PlaceObjectByHash(2475986526, -1075.31, -3011.69, 13.7046, 0, 0, -26.0348, -1, 9);
						Features::PlaceObjectByHash(2475986526, -1069.34, -3008.59, 16.0846, 0, 0, -26.0348, -1, 9);
						Features::PlaceObjectByHash(2475986526, -1071.71, -3013.45, 13.7046, 0, 0, -26.0348, -1, 9);
						Features::PlaceObjectByHash(2475986526, -1068.14, -3015.2, 13.7046, 0, 0, -26.0348, -1, 9);
						Features::PlaceObjectByHash(3608473212, -1065.36, -3006.66, 15.3449, 0, 0, -25.1145, -1, 9);
						Features::PlaceObjectByHash(2475986526, -1065.75, -3010.35, 16.0846, 0, 0, -26.0348, -1, 9);
					}
					if (Menu::Option("Teleport")) {
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1003, -2916, 14, 1, 0, 0, 1);
					}

					break;
#pragma region mapmode
				case ramp11:
					Menu::Title("Airport Loop");
					// Menu::Subtitle("AIRPORT LOOP");

					if (Menu::Option("Load")) {
						Features::PlaceObjectByHash(3966705493, -1041.89, -3219.51, 10.1797, -2.43331, 5.32208, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1037.79, -3221.47, 10.3641, -2.43331, 5.32208, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1034.16, -3223.3, 10.5366, -2.43331, 5.32208, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1036.76, -3219.45, 10.1526, -2.43331, 5.32208, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1033.12, -3221.28, 10.3251, -2.43331, 5.32208, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1029.37, -3225.6, 11.1956, -11.6033, 5.32207, 62.9335, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1028.33, -3223.58, 10.9842, -11.6033, 5.32207, 62.9335, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1024.27, -3225.54, 12.1104, -18.1533, 5.32205, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1025.44, -3227.83, 12.3497, -18.1533, 5.32205, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1020.36, -3230.06, 15.7972, -40.4234, 5.32214, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1019.22, -3227.83, 15.5634, -40.4234, 5.32214, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1014.85, -3229.56, 20.4393, -50.9034, 5.3221, 62.9337, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1016.07, -3231.95, 20.6898, -50.9034, 5.3221, 62.9337, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1012.88, -3232.96, 26.0664, -64.0034, 5.32209, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1011.63, -3230.51, 25.8104, -64.0034, 5.32209, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1009.27, -3231.06, 32.0819, -73.1735, 5.32204, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1010.52, -3233.51, 32.3379, -73.1735, 5.32214, 62.9337, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1009.36, -3233.48, 38.2311, -83.6535, 5.32208, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1008.09, -3230.98, 37.9695, -83.6535, 5.32208, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1007.71, -3230.43, 44.185, -92.8235, 6.63212, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1009.05, -3228.93, 49.9682, -119.024, 6.63217, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1008.93, -3232.81, 44.4969, -92.8235, 6.63212, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1010.27, -3231.31, 50.2801, -119.024, 6.63217, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1011.96, -3226.91, 54.0691, -142.604, 6.6321, 62.9337, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1013.1, -3229.14, 54.3602, -142.604, 6.6321, 62.9337, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1017.49, -3226.51, 57.2125, -159.634, 6.63211, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1022.14, -3223.91, 58.9186, -168.804, 6.63213, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1035.97, -3216.05, 58.7162, 155.826, 1.39214, 60.3137, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1031.37, -3218.71, 60.1775, 176.786, 6.63213, 60.3137, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1026.33, -3221.63, 59.8766, -168.804, 6.63212, 60.3136, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1020.98, -3221.63, 58.6206, -168.804, 6.63213, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1024.97, -3219.25, 59.5578, -168.804, 6.63212, 60.3136, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1016.33, -3224.24, 56.9145, -159.634, 6.63211, 62.9336, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1029.99, -3216.28, 59.8517, 176.786, 6.63213, 60.3137, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1029.99, -3216.28, 59.8517, 176.786, 6.63213, 60.3137, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1034.73, -3213.86, 58.655, 155.826, 1.39214, 60.3137, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1039.18, -3211.42, 55.2255, 138.796, 1.39206, 60.3137, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1039.18, -3211.42, 55.2255, 138.796, 1.39206, 60.3137, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1040.42, -3213.61, 55.2867, 138.796, 1.39206, 60.3137, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1044.34, -3211.51, 50.6082, 128.316, 1.39213, 60.3137, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1043.09, -3209.33, 50.547, 128.316, 1.39213, 60.3137, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1046.16, -3207.74, 45.1535, 117.837, 1.39215, 60.3137, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1048.17, -3206.74, 39.6252, 104.737, 1.39214, 60.3137, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1048.92, -3206.44, 33.1586, 87.6005, 0.0914728, 60.6227, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1048.18, -3206.88, 26.5446, 77.3408, 0.0913896, 60.6229, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1049.44, -3209.13, 26.5487, 77.3407, 0.0913427, 60.6228, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1047.3, -3210.37, 21.3947, 56.6411, 0.0914017, 58.823, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1047.3, -3210.37, 21.3947, 56.6411, 0.0914017, 58.823, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1045.93, -3208.12, 21.3905, 56.6411, 0.0914017, 58.823, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1042.61, -3210.12, 16.8766, 42.1517, 0.0913785, 58.8231, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1038.64, -3212.63, 13.6141, 28.2018, 0.0914187, 58.8231, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1039.97, -3214.83, 13.6182, 28.2018, 0.0914187, 58.8231, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1034.82, -3217.71, 11.1985, 16.4116, 0.0913871, 69.303, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1033.53, -3215.55, 11.1081, 16.4117, 0.0913619, 66.683, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1043.97, -3212.37, 16.8808, 42.1517, 0.0913785, 58.8231, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1050.19, -3208.69, 33.1627, 87.6005, 0.0914728, 60.6227, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1049.45, -3208.98, 39.6879, 104.737, 1.39214, 60.3137, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1047.44, -3209.98, 45.2161, 117.837, 1.39215, 60.3137, -1, 10);
						Features::PlaceObjectByHash(3966705493, -1047.44, -3209.98, 45.2161, 117.837, 1.39215, 60.3137, -1, 10);
					}
					if (Menu::Option("Teleport")) {
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1074, -3201, 13, 1, 0, 0, 1);
					}

					break;
#pragma region mapmode
				case ramp12:
					Menu::Title("Maze Bank Ramp");
					// Menu::Subtitle("MAZE BANK RAMP");

					if (Menu::Option("Load")) {
						Features::PlaceObjectByHash(3681122061, -82.9657, -818.944, 325.175, 0, -0, 91.03, -1, 11);
						Features::PlaceObjectByHash(3681122061, -91.0941, -819.089, 322.355, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -98.36, -819.224, 316.632, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -105.626, -819.358, 310.91, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -112.892, -819.492, 305.187, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -120.158, -819.626, 299.464, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -127.424, -819.761, 293.741, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -134.69, -819.895, 288.018, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -141.956, -820.029, 282.296, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -149.222, -820.163, 276.573, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -156.487, -820.298, 270.85, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -163.753, -820.432, 265.127, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -171.019, -820.566, 259.404, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -178.285, -820.701, 253.682, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -185.551, -820.835, 247.959, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -192.817, -820.969, 242.236, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -200.083, -821.103, 236.513, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -207.349, -821.238, 230.79, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -214.615, -821.372, 225.068, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -221.881, -821.506, 219.345, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -229.147, -821.641, 213.622, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -236.413, -821.775, 207.899, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -243.679, -821.909, 202.176, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -250.945, -822.043, 196.453, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -258.21, -822.178, 190.731, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -265.476, -822.312, 185.008, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -287.274, -822.715, 167.839, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -280.008, -822.58, 173.562, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -272.742, -822.446, 179.285, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -294.54, -822.849, 162.117, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -301.806, -822.983, 156.394, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -309.072, -823.118, 150.671, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -316.338, -823.252, 144.948, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -323.604, -823.386, 139.225, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -330.87, -823.52, 133.503, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -338.136, -823.655, 127.78, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -345.402, -823.789, 122.057, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -352.668, -823.923, 116.334, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -359.934, -824.057, 110.611, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -367.199, -824.192, 104.889, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -374.465, -824.326, 99.1657, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -381.731, -824.46, 93.4429, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -388.997, -824.595, 87.7201, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -396.263, -824.729, 81.9973, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -403.529, -824.863, 76.2745, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -411.479, -825.022, 68.7971, -19.78, -3.43377e-005, 91.1094, -1, 11);
						Features::PlaceObjectByHash(3681122061, -410.795, -824.997, 70.5517, -38.2199, 0.00787841, 91.0529, -1, 11);
						Features::PlaceObjectByHash(3681122061, -411.96, -825.029, 69.097, -27.6, 1.15259e-005, 91.1095, -1, 11);
						Features::PlaceObjectByHash(3681122061, -412.719, -825.046, 67.8516, -10.58, -2.92151e-006, 91.1095, -1, 11);
						Features::PlaceObjectByHash(3681122061, -413.903, -825.068, 67.2075, -3.21999, 5.66959e-007, 91.1095, -1, 11);
						Features::PlaceObjectByHash(3681122061, -415.378, -825.099, 66.7734, 3.68002, -4.58236e-006, 91.1095, -1, 11);
						Features::PlaceObjectByHash(3681122061, -416.883, -825.126, 66.57, 9.66002, -8.44435e-006, 91.1096, -1, 11);
						Features::PlaceObjectByHash(3681122061, -418.526, -825.157, 66.5571, 15.64, -1.80093e-005, 91.1095, -1, 11);
						Features::PlaceObjectByHash(3681122061, -419.945, -825.184, 66.6727, 20.7001, 8.69782e-006, 91.1094, -1, 11);
						Features::PlaceObjectByHash(3681122061, -421.727, -825.218, 67.0936, 25.7601, -2.09975e-005, 91.1095, -1, 11);
						Features::PlaceObjectByHash(3681122061, -422.006, -825.234, 66.966, 30.8199, 0.114757, 90.6829, -1, 11);
						Features::PlaceObjectByHash(3681122061, -429.913, -825.328, 71.6856, 30.8199, 0.114757, 90.6829, -1, 11);
					}
					if (Menu::Option("Teleport")) {
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
					}

					break;


					//Animations 
				case anim:
				{
					Menu::Title("Animations");
					// Menu::Subtitle("Player Animations");
					if (Menu::Option("Clear Animation")) { Features::clearanim(); }
					if (Menu::Option("Sex Receiver")) { Features::doAnimation("rcmpaparazzo_2", "shag_loop_poppy"); }
					if (Menu::Option("Sex Giver")) { Features::doAnimation("rcmpaparazzo_2", "shag_loop_a"); }
					if (Menu::Option("Stripper Dance")) { Features::doAnimation("mini@strip_club@private_dance@part1", "priv_dance_p1"); }
					if (Menu::Option("Pole Dance")) { Features::doAnimation("mini@strip_club@pole_dance@pole_dance1", "pd_dance_01"); }
					if (Menu::Option("Push Ups")) { Features::doAnimation("amb@world_human_push_ups@male@base", "base"); }
					if (Menu::Option("Sit Ups")) { Features::doAnimation("amb@world_human_sit_ups@male@base", "base"); }
					if (Menu::Option("Celebrate")) { Features::doAnimation("rcmfanatic1celebrate", "celebrate"); }
					if (Menu::Option("Electrocution")) { Features::doAnimation("ragdoll@human", "electrocute"); }
					if (Menu::Option("Suicide")) { Features::doAnimation("mp_suicide", "pistol"); }
					if (Menu::Option("Showering")) { Features::doAnimation("mp_safehouseshower@male@", "male_shower_idle_b"); }
				}
				break;


				//Scenarios Animtions 
				case senas:
				{
					Menu::Title("Scenarios");
					// Menu::Subtitle("SCENARIOS");

					if (Menu::Option("~r~Stop ~w~Animation")) AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
					if (Menu::Option("Paparizzi")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_PAPARAZZI", 0, true);
					if (Menu::Option("Drug Dealer")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_DRUG_DEALER_HARD", 0, true);
					if (Menu::Option("Drinking Coffee")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_AA_COFFEE", 0, true);
					if (Menu::Option("Playing Instruments")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSICIAN", 0, true);
					if (Menu::Option("Flexing")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSCLE_FLEX", 0, true);
					if (Menu::Option("Jogging")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_JOG_STANDING", 0, true);
					if (Menu::Option("Binoculars")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_BINOCULARS", 0, true);
					if (Menu::Option("Clipboard")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_CLIPBOARD", 0, true);
					if (Menu::Option("Bench Press")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS", 0, true);
					if (Menu::Option("Chin Ups")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_MUSCLE_CHIN_UPS", 0, true);
					if (Menu::Option("BBQ")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_BBQ", 0, true);
					if (Menu::Option("Superhero")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SUPERHERO", 0, true);
					if (Menu::Option("Fishing")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_STAND_FISHING", 0, true);
					if (Menu::Option("Security")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SECURITY_SHINE_TORCH", 0, true);
					if (Menu::Option("Leaf Blower")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GARDENER_LEAF_BLOWER", 0, true);
					if (Menu::Option("Film Shocking")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MOBILE_FILM_SHOCKING", 0, true);
					if (Menu::Option("Idle Cop")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_COP_IDLES", 0, true);
					if (Menu::Option("Drinking")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_DRINKING", 0, true);
					if (Menu::Option("Golf Player")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GOLF_PLAYER", 0, true);
					if (Menu::Option("Welding")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_WELDING", 0, true);
					if (Menu::Option("Smoking Pot")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SMOKING_POT", 0, true);
					if (Menu::Option("Hammering")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_HAMMERING", 0, true);
					if (Menu::Option("Tennis")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_TENNIS_PLAYER", 0, true);
					if (Menu::Option("Drilling")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_CONST_DRILL", 0, true);
				}
				break;

				case dropOnline222:
				{
					Menu::Title("Player List");
					// Menu::Subtitle("DROP CASH");

					Menu::Break("Cash Amount Options");

					if (Menu::Int("Amount Custom input", Features::DropAmount3, 1, 2500))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::DropAmount3 = NumberKeyboard();
						}
					}

					if (Menu::Int("Delay", Features::DropDelay, 50, 1000))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::DropDelay = NumberKeyboard();
						}
					}

					Menu::Toggle("Give Player MoneyGun", Features::moneyguntoggles[Features::Online::selectedPlayer], [] { Features::OtherPlayerMoneyGun(Features::moneyguntoggles[Features::Online::selectedPlayer]); });

					Menu::Break("Models");
					dropModelsSelect();
				}
				break;

				case cocplll:
				{
					Menu::Title("");
					// Menu::Subtitle("WARDROBE");

					Menu::Int("Outfit Slot", selectedOutfit, 0, 100);
					if (Menu::Option("Save")) {
						SaveOutfit();
					}
					if (Menu::Option("Load")) {
						LoadOutfit(); Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 0, outfit1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 1, mask1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 2, mask2, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 3, shirt1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 11, collars1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 8, Accessories1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 4, pants1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 5, hands1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 6, shoes1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 9, mission1, 0, 0);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 10, decals1, 0, 0);
					}
					if (Menu::Int("Face", outfit1, 0, 11)) {
						Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 0, outfit1, 0, -1);
					}
					if (Menu::Int("Mask", mask1, 0, 132)) {
						Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 1, mask1, 0, -1);
					}
					if (Menu::Int("Hair", mask2, 0, 73)) {
						Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 2, mask2, 0, -1);
					}
					if (Menu::Int("Gloves", shirt1, 0, 164)) {
						Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 3, shirt1, 0, -1);
					}
					if (Menu::Int("Top", collars1, 0, 254)) {
						Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 11, collars1, 0, -1);
					}
					if (Menu::Int("Collar", Accessories1, 0, 131)) {
						Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 8, Accessories1, 0, -1);
					}
					if (Menu::Int("Pants", pants1, 0, 99)) {
						Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 4, pants1, 0, -1);
					}
					if (Menu::Int("Accessories", hands1, 0, 69)) {
						Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 5, hands1, 0, -1);
					}
					if (Menu::Int("Shoes", shoes1, 0, 79)) {
						Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 6, shoes1, 0, -1);
					}
					if (Menu::Int("Mission Stuff", mission1, 0, 29)) {
						Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 9, mission1, 0, -1);
					}
					if (Menu::Int("Decals", decals1, 0, 28)) {
						Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						PED::SET_PED_COMPONENT_VARIATION(playerPed, 10, decals1, 0, -1);
					}
				}
				break;

				//Online Player List Code 
				case onlinemenu_playerlist:
				{
					Menu::Title("~w~Entinity ~w~VIP");
					// Menu::Subtitle("~w~Player List");
					for (int i = 0; i < 32; ++i) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
							Menu::MenuOption(PLAYER::GET_PLAYER_NAME(i), onlinemenu_selected) ? Features::Online::selectedPlayer = i : NULL;
						}
					}
				}
				break;

				case Remoteoptall:
				{
					Menu::Title("Player List");
					// Menu::Subtitle("REMOTE OPTIONS");

					Menu::Int("Hour", Menu::Settings::Hourfick, 0, 23);
					Menu::Int("Minute", Menu::Settings::Minufick, 0, 59);
					Menu::Int("Second", Menu::Settings::secfick, 0, 59);

					if (Menu::Option("Set Time"))
					{
						Features::set_session_time(Menu::Settings::Hourfick, Menu::Settings::Minufick, Menu::Settings::secfick);


					}

					Menu::Toggle("Show all players on radar", Features::isRevealPlayers, [] {Features::revealPlayers(Features::isRevealPlayers); });


					if (Menu::Option("~w~Clear Lobby")) {

						for (int x = 0; x < 32; x++)
						{
							if (x != PLAYER::PLAYER_ID() && ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(x)))
							{
								DWORD64 args[4] = { 994306218, x, 0, 0 };
								SCRIPT::eventur(1, args, 4, 1 << x);
							}
						}


					}

					if (Menu::Option("~w~Teleport All Player Eclipse Tower")) {

						for (int z = 0; z < 40; z++)
						{
							DWORD64 arguments[9] = { -328868154, z, 1, -1, 1, 1, 0,0,0 };
							SCRIPT::eventur(1, arguments, 9, 1 << z);
						}
					}

					Menu::Toggle("Crash Lobby", Features::cargopall, [] {Features::cargoPall(Features::cargopall); });



					Menu::Toggle("Transaction Error for all players", Features::sounderrorall, [] {Features::sound55errorall(Features::sounderrorall); });

					if (Menu::Option("~w~Remove Players Wanted Level")) {

						Player player = Features::Online::selectedPlayer;

						int handle = globalHandle(1624079).At(player, 558).At(491).As<int>();
						DWORD64 args[3] = { 1511476871, player, handle };
						SCRIPT::eventur(1, args, 3, 1 << player);


					}

					if (Menu::Option("~w~Remote Black Screen")) {


						DWORD64 args[9] = { 1000837481, Features::Online::selectedPlayer, 0, 0, 0, -1, 1, 1, 0 };
						SCRIPT::eventur(1, args, 9, 1 << Features::Online::selectedPlayer);

						notifyMap("~r~Player got a black screen");
					}
				}
				break;

				case Remoteoptalll:
				{
					Menu::Title("Player List");
					// Menu::Subtitle("REMOTE");


					Menu::Int("~w~Ammout", Menu::Settings::notoirff, 0, 400000000);

					if (Menu::Option("~w~Send Player disbursed Money Notification")) {

						Player player = Features::Online::selectedPlayer;

						DWORD64 args[14] = { 713068249, player, 2110027654, Menu::Settings::notoirff };
						SCRIPT::eventur(1, args, 14, 1 << player);
					}

					if (Menu::Option("~w~Send Player deposited Money Notification")) {

						Player  player = Features::Online::selectedPlayer;

						DWORD64 penis[15] = { 713068249, player, -1550586884, Menu::Settings::notoirff };
						SCRIPT::eventur(1, penis, 15, 1 << player);
					}

					if (Menu::Option("~w~Send Player Stolen Money Notification")) {

						Player  player = Features::Online::selectedPlayer;

						DWORD64 penis[15] = { 713068249, player, -1432462772, Menu::Settings::notoirff };
						SCRIPT::eventur(1, penis, 15, 1 << player);
					}


					if (Menu::Option("~w~Send APP - Activated Message to Player")) {

						Player  player = Features::Online::selectedPlayer;

						DWORD64 penis[15] = { 566035618, player, 1383721237, Menu::Settings::notoirff };
						SCRIPT::eventur(1, penis, 15, 1 << player);
					}


					if (Menu::Option("~w~Send APP - Disabled Message to Player")) {

						Player  player = Features::Online::selectedPlayer;

						DWORD64 penis[15] = { 713068249, player, 1254298341, Menu::Settings::notoirff };
						SCRIPT::eventur(1, penis, 15, 1 << player);
					}

				}
				break;

				case Remoteopt:
				{
					Menu::Title("Player List");
					// Menu::Subtitle("REMOTE");
					if (selecArrow) {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
						GRAPHICS::DRAW_MARKER(offradardpl, coords.x, coords.y, coords.z + 1.3f, 0, 0, 0, 0, 180, 0, 0.3, 0.3, 0.3, r1, g1, b1, 200, 1, 1, 1, 0, 0, 0, 0);
					}
					Menu::MenuOption("Custom Notify", Remoteoptalll);

					Menu::Toggle("~w~Remote Bribe Authorities", Features::progen, [] { Features::bribeAuthorities(Features::progen); });

					Menu::Toggle("Crash Player", Features::cargop[Features::Online::selectedPlayer], [] { Features::cargoP(Features::cargop[Features::Online::selectedPlayer]); });

					Menu::Toggle("Freeze", Features::freezed[Features::Online::selectedPlayer], [] { Features::Freezer(Features::freezed[Features::Online::selectedPlayer]); });

					Menu::Toggle("Off Radar", Features::orbooll, [] {Features::OffRadarr(Features::orbooll); });

					Menu::Toggle("Freeze Camera", Features::freezecamera, [] {Features::camerafreeze(Features::freezecamera); });

					if (Menu::Option("Remote Infinity Black Screen with Notify"))
					{
						Player player = Features::Online::selectedPlayer;
						DWORD64 args[9] = { 1000837481, player, 4, 4566469881341411328, 4528819783743622349, 0, 1, 1, 1062333317 };
						SCRIPT::eventur(1, args, 9, 1 << player);



					}

					if (Menu::Option("Send Player Police Attackers"))
					{

						Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(iPed, 0);
						if (!ENTITY::DOES_ENTITY_EXIST(iPed)) return;
						Hash guysex = GAMEPLAY::GET_HASH_KEY("s_m_y_cop_01");
						STREAMING::REQUEST_MODEL(guysex);
						while (!STREAMING::HAS_MODEL_LOADED(guysex))
							WAIT(0);
						int createdGuySex = PED::CREATE_PED(26, guysex, pCoords.x, pCoords.y, pCoords.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdGuySex, false);
						int vehmodel = GAMEPLAY::GET_HASH_KEY("POLICE3");
						STREAMING::REQUEST_MODEL(vehmodel);
						while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
						Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x, pCoords.y, pCoords.z, 0.0, 1, 1);
						VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL");
						WEAPON::GIVE_WEAPON_TO_PED(createdGuySex, railgun, railgun, 9999, 9999);
						PED::SET_PED_INTO_VEHICLE(createdGuySex, veh, -1);
						AI::TASK_COMBAT_PED(createdGuySex, iPed, 1, 1);
						ENTITY::SET_ENTITY_INVINCIBLE(createdGuySex, false);
						PED::SET_PED_COMBAT_ABILITY(createdGuySex, 100);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdGuySex, true);
						AI::TASK_COMBAT_PED(createdGuySex, iPed, 1, 1);
						PED::SET_PED_AS_ENEMY(createdGuySex, 1);
						PED::SET_PED_COMBAT_RANGE(createdGuySex, 1000);
						PED::SET_PED_KEEP_TASK(createdGuySex, true);
						PED::SET_PED_AS_COP(createdGuySex, 1000);
						PED::SET_PED_ALERTNESS(createdGuySex, 1000);


					}

					if (Menu::Option("~w~Remove Players Wanted Level")) {

						Player player = Features::Online::selectedPlayer;

						int handle = globalHandle(1625435).At(player, 560).At(491).As<int>();
						DWORD64 args[3] = { 1475266103, player, handle };
						SCRIPT::eventur(1, args, 3, 1 << player);


						notifyMap("~b~Wanted Level from Player Cleared!");


					}
					if (Menu::Option("~w~InsuranceMessage")) {

						DWORD64 args[3] = { 380155193, Features::Online::selectedPlayer, 1000000000 };

						SCRIPT::eventur(1, args, 3, 1 << Features::Online::selectedPlayer);
					}
					if (Menu::Option("~w~RemovedMoneyNotif")) {

						DWORD64 args[14] = { 713068249, Features::Online::selectedPlayer, 2110027654, 48932184 };

						SCRIPT::eventur(1, args, 14, 1 << Features::Online::selectedPlayer);
					}
					if (Menu::Option("~w~Remote Kick Player from Vehicle"))
					{

						Player player = Features::Online::selectedPlayer;


						int handle = globalHandle(2524719).At(player, 788).As<int>();
						uint64_t args[3] = { 325218053, 0, handle };
						SCRIPT::eventur(1, args, 3, 1 << player);
					}

					if (Menu::Option("~w~Non Host Kick")) {

						Player player = Features::Online::selectedPlayer;

						DWORD64 args[3] = { -120668417 , player, 48 };
						SCRIPT::eventur(1, args, 3, 1 << player);


					}
					if (Menu::Option("~w~Non Host Kick to Single Player")) {

						DWORD64 args[4] = { 769347061, Features::Online::selectedPlayer, 0, 0 };
						SCRIPT::eventur(1, args, 4, 1 << Features::Online::selectedPlayer);
					}

					if (Menu::Option("Server Remote Ban")) {
						for (int i = 0; i <= 32; i++)
						{
							Ped Ban = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
							AUDIO::PLAY_SOUND_FRONTEND(-1, "THERMAL_VISION_GOGGLES_ON_MASTER", 0, 1);
							AI::CLEAR_PED_TASKS_IMMEDIATELY(Ban);
							AI::CLEAR_PED_TASKS(Ban);
							AI::CLEAR_PED_SECONDARY_TASK(Ban);
							notifyBottom("ACCESS_994306218_THROUGH_NET_LAN");
							notifyMap("ACCESS_GRANDED_THROUGH_NET_LAN");
							if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) != PLAYER::PLAYER_PED_ID())
							{
								unsigned int playerBit = (1 << i);
								uint64_t args[4] = { 994306218, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0, 0 };
								SCRIPT::eventur(1, args, 4, playerBit);
								notifyBottom("~r~CUSTOM::BAN_THROUGH_BYBASS~w~(....)");
							}
						}
						notifyMap("~r~Terminated");
					}


					if (Menu::Option("Crash Player")) {

						DWORD64 args[4] = { 994306218, Features::Online::selectedPlayer, 0, 0 };
						SCRIPT::eventur(1, args, 4, 1 << Features::Online::selectedPlayer);

						notifyMap("Nano69: ~HUD_COLOUR_RED~ Player has been crashed successfully");

					}
					if (Menu::Option("Force Mission")) {

						DWORD64 args[2] = { -15432926, Features::Online::selectedPlayer };
						SCRIPT::eventur(1, args, 2, 1 << Features::Online::selectedPlayer);


					}

					if (Menu::Option("~w~Show GTAScreen ")) {


						DWORD64 args[4] = { -181444979, Features::Online::selectedPlayer, 0, 0 };
						SCRIPT::eventur(1, args, 4, 1 << Features::Online::selectedPlayer);


					}

					if (Menu::Option("~w~Send Banner ")) {


						uint64_t args[3] = { 713068249, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), 1009196241 };
						SCRIPT::eventur(1, args, 4, 1 << Features::Online::selectedPlayer);


					}

					if (Menu::Option("Force Mission Message")) {

						DWORD64 args[4] = { -1571039706, Features::Online::selectedPlayer, 0, 0 };
						SCRIPT::eventur(1, args, 4, 1 << Features::Online::selectedPlayer);


					}
					Menu::Toggle("~b~Remote Transaction Error Spam", Features::sounderror[Features::Online::selectedPlayer], [] { Features::sound55error(Features::sounderror[Features::Online::selectedPlayer]); });

					if (Menu::Option("~w~Spectating Message to Player")) {

						DWORD64 args[14] = { 713068249, Features::Online::selectedPlayer, 1583919327 };
						SCRIPT::eventur(1, args, 14, 1 << Features::Online::selectedPlayer);
					}
					if (Menu::Option("Infinity Loading Screen")) {
						DWORD64 args[3] = { INFINITY_LOADING, Features::Online::selectedPlayer, 1 };
						SCRIPT::eventur(1, args, 3, 1 << Features::Online::selectedPlayer);
					}
					if (Menu::Option("~y~CEO Kick Player")) {

						DWORD64 args[4] = { -1190833098, Features::Online::selectedPlayer, 0, 0 };
						SCRIPT::eventur(1, args, 4, 1 << Features::Online::selectedPlayer);
					}


					if (Menu::Option("~y~CEO Ban Player ")) {

						DWORD64 args[3] = { 360381720, Features::Online::selectedPlayer, 1 };
						SCRIPT::eventur(1, args, 3, 1 << Features::Online::selectedPlayer);
					}

					if (Menu::Option("~y~CEO Kick Player with Notification ")) {

						uint64_t args[4];
						args[0] = -1190833098;
						args[1] = Features::Online::selectedPlayer;
						args[2] = 1;
						args[3] = 5;
						SCRIPT::eventur(1, args, 4, 1 << Features::Online::selectedPlayer);

					}

					if (Menu::Option("~y~CEO Ban Player with Notification ")) {

						uint64_t args[4];
						args[0] = 360381720;
						args[1] = Features::Online::selectedPlayer;
						args[2] = 1;
						args[3] = 5;
						SCRIPT::eventur(1, args, 4, 1 << Features::Online::selectedPlayer);

					}

				}
				break;

				case trollo:
				{
					Menu::Title("Player List");
					// Menu::Subtitle("GRIEFING");
					if (selecArrow) {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
						GRAPHICS::DRAW_MARKER(offradardpl, coords.x, coords.y, coords.z + 1.3f, 0, 0, 0, 0, 180, 0, 0.3, 0.3, 0.3, r1, g1, b1, 200, 1, 1, 1, 0, 0, 0, 0);
					}
					if (Menu::Option("Valkyrie Cannon")) {
						Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
						FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z - 1, 38, 0.5f, true, false, 0.0f);
					}

					if (Menu::Int("~w~Bullet Type", Menu::Settings::bullet, 0, 38))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Menu::Settings::bullet = NumberKeyboard();
						}

					}

					if (Menu::Float("~w~Bullet Scale", Menu::Settings::bulletp, 0.0f, 100.0f));

					if (Menu::Option("~w~Bullet Cannon ~g~Visible")) {
						Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
						FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z - 1, Menu::Settings::bullet, Menu::Settings::bulletp, true, false, 0.0f);
					}

					if (Menu::Option("~w~Bullet Cannon ~r~Invisible")) {
						Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
						FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z - 1, Menu::Settings::bullet, Menu::Settings::bulletp, true, true, 0.0f);
					}
					if (Menu::Option("Blame Player"))
					{

						blame();

					}

					Menu::Toggle("Give Player MoneyGun", Features::moneyguntoggles[Features::Online::selectedPlayer], [] { Features::OtherPlayerMoneyGun(Features::moneyguntoggles[Features::Online::selectedPlayer]); });
					Menu::Toggle("Give Player Vehicle Gun", Features::VehgunP[Features::Online::selectedPlayer], [] { Features::vehgunp(Features::VehgunP[Features::Online::selectedPlayer]); });
					Menu::Toggle("Water Loop", Features::playerwaterloop[Features::Online::selectedPlayer], [] { Features::WaterLoop(Features::playerwaterloop[Features::Online::selectedPlayer]); });
					Menu::Toggle("Fire Loop", Features::playerfireloop[Features::Online::selectedPlayer], [] { Features::FireLoop(Features::playerfireloop[Features::Online::selectedPlayer]); });
					Menu::Toggle("Fuck Handling", Features::fuckedhandling[Features::Online::selectedPlayer], [] { Features::fuckhandling(Features::fuckedhandling[Features::Online::selectedPlayer]); });
					Menu::Toggle("Shake Cam", Features::camshaker[Features::Online::selectedPlayer], [] { Features::shakecam(Features::camshaker[Features::Online::selectedPlayer]); });
					if (Menu::Option("Send Player Police Attackers"))
					{

						Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(iPed, 0);
						if (!ENTITY::DOES_ENTITY_EXIST(iPed)) return;
						Hash guysex = GAMEPLAY::GET_HASH_KEY("s_m_y_cop_01");
						STREAMING::REQUEST_MODEL(guysex);
						while (!STREAMING::HAS_MODEL_LOADED(guysex))
							WAIT(0);
						int createdGuySex = PED::CREATE_PED(26, guysex, pCoords.x, pCoords.y, pCoords.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdGuySex, false);
						int vehmodel = GAMEPLAY::GET_HASH_KEY("POLICE3");
						STREAMING::REQUEST_MODEL(vehmodel);
						while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
						Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x, pCoords.y, pCoords.z, 0.0, 1, 1);
						VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL");
						WEAPON::GIVE_WEAPON_TO_PED(createdGuySex, railgun, railgun, 9999, 9999);
						PED::SET_PED_INTO_VEHICLE(createdGuySex, veh, -1);
						AI::TASK_COMBAT_PED(createdGuySex, iPed, 1, 1);
						ENTITY::SET_ENTITY_INVINCIBLE(createdGuySex, false);
						PED::SET_PED_COMBAT_ABILITY(createdGuySex, 100);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdGuySex, true);
						AI::TASK_COMBAT_PED(createdGuySex, iPed, 1, 1);
						PED::SET_PED_AS_ENEMY(createdGuySex, 1);
						PED::SET_PED_COMBAT_RANGE(createdGuySex, 1000);
						PED::SET_PED_KEEP_TASK(createdGuySex, true);
						PED::SET_PED_AS_COP(createdGuySex, 1000);
						PED::SET_PED_ALERTNESS(createdGuySex, 1000);


					}
					if (Menu::Option("~w~Polo Dance")) {

						const int ElementAmount = 10;
						const int ArrSize = ElementAmount * 2 + 2;
						Ped* peds = new Ped[ArrSize];
						peds[0] = ElementAmount;
						int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);
						for (int i = 0; i < PedFound; i++)
						{
							int OffsetID = i * 2 + 2;
							RequestControlOfEnt(peds[OffsetID]);
							if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
							{
								STREAMING::REQUEST_ANIM_DICT("mini@strip_club@pole_dance@pole_dance1");
								if (STREAMING::HAS_ANIM_DICT_LOADED(("mini@strip_club@pole_dance@pole_dance1")))
								{
									AI::TASK_PLAY_ANIM((peds[OffsetID]), "mini@strip_club@pole_dance@pole_dance1", "pd_dance_01", 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
								}
							}
						}

					}
					if (Menu::Option("Tp Player to apartment")) {
						DWORD64 args[9] = { 220529377, Features::Online::selectedPlayer, 1, -1, 1, 0, 0,0,0 };
						SCRIPT::eventur(1, args, 9, 1 << Features::Online::selectedPlayer);
					}
					Menu::Toggle("Explosion Loop", Features::exploder[Features::Online::selectedPlayer], [] { Features::explodeloop(Features::exploder[Features::Online::selectedPlayer]); });
					if (Features::Online::selectedPlayer != PLAYER::PLAYER_ID()) { Menu::Toggle("Spectate", Features::spectate[Features::Online::selectedPlayer], [] { Features::specter(Features::spectate[Features::Online::selectedPlayer]); }); }
					if (Menu::Option("Explode him")) {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
						FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 1000.f, true, false, 1000.f);
					}
					if (Menu::Option("Explode Car")) {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
						VEHICLE::EXPLODE_VEHICLE(coords.x, coords.y, coords.z);
					}
					if (Menu::Option("Delete Car")) {
						Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						if (PED::IS_PED_IN_ANY_VEHICLE(selectedplayer, false))
						{
							int Vehicle = PED::GET_VEHICLE_PED_IS_USING(selectedplayer);
							if (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Vehicle))
								while (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Vehicle));

							ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Vehicle, 1, 1);
							VEHICLE::DELETE_VEHICLE(&Vehicle);
						}
					}
					if (Menu::Option("Airstrike Player")) {
						Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
						Hash airStrike = GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET");
						WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
						while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike))
							WAIT(0);
						GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z + 50.f, coords.x, coords.y, coords.z, 250, 1, airStrike, playerPed, 1, 0, -1.0);
					}
					if (Menu::Option("Kick him out of Car")) {
						Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						RequestControlOfEnt(playerPed);
						AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed);
						AI::CLEAR_PED_TASKS(playerPed);
						AI::CLEAR_PED_SECONDARY_TASK(playerPed);
					}
					if (Menu::Option("Give Player T20"))
					{
						int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
						Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
						Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
						Vehicle zentorno = Features::SpawnVehicle("t20", Ocoords, 0, 0.0f);
						ENTITY::SET_ENTITY_INVINCIBLE(zentorno, 0);
					}
					if (Menu::Option("Give Player Monster"))
					{
						int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
						Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
						Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
						Vehicle zentorno = Features::SpawnVehicle("MONSTER", Ocoords, 0, 0.0f);
						ENTITY::SET_ENTITY_INVINCIBLE(zentorno, 0);
					}
					if (Menu::Option("Give Player Tank"))
					{
						int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
						Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
						Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
						Vehicle zentorno = Features::SpawnVehicle("RHINO", Ocoords, 0, 0.0f);
						ENTITY::SET_ENTITY_INVINCIBLE(zentorno, 0);
					}
					if (Menu::Option("Give Player Docker"))
					{
						int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
						Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
						Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
						Vehicle zentorno = Features::SpawnVehicle("DUNE2", Ocoords, 0, 0.0f);
						ENTITY::SET_ENTITY_INVINCIBLE(zentorno, 0);
					}
					if (Menu::Option("Ram Player")) {

						float offset;
						Hash vehmodel = GAMEPLAY::GET_HASH_KEY("SANDKING");
						STREAMING::REQUEST_MODEL(vehmodel);

						while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
						Vector3 pCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0.0, -10.0, 0.0);

						if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
						{
							Vector3 dim1, dim2;
							GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

							offset = dim2.y * 1.6;

							Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
							float rot = (ENTITY::GET_ENTITY_ROTATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0)).z;

							Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), pCoords.z, rot, 1, 1);

							VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
							ENTITY::SET_ENTITY_VISIBLE(veh, true, true);
							VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 700.0);
						}

					}
					if (Menu::Option("Semi God"))
					{
						Hash oball = GAMEPLAY::GET_HASH_KEY("prop_juicestand");
						STREAMING::REQUEST_MODEL(oball);
						while (!STREAMING::HAS_MODEL_LOADED(oball))
							WAIT(0);
						int orangeball = OBJECT::CREATE_OBJECT(oball, 0, 0, 0, true, 1, 0);
						RequestControlOfEnt(orangeball);
						ENTITY::SET_ENTITY_VISIBLE(orangeball, 0, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(orangeball, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);

					}
					if (Menu::Option("Slingshot Car")) {
						NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true));
						if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true)));
						{
							ENTITY::APPLY_FORCE_TO_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true), 1, 0, 0, 20, 0, 0, 0, 1, false, true, true, true, true);
						}
					}
					if (Menu::Option("Clone Player"))
					{
						PED::CLONE_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 1, 1, 1);
					}
					if (Menu::Option("Set Player into Vehicle"))
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 1, 1);
					}
					int clone[1000];
					int gcount = 1;
					if (Menu::Option("Spawn Bodyguard")) {
						Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
						Hash pedm = GAMEPLAY::GET_HASH_KEY("u_m_m_jesus_01");
						STREAMING::REQUEST_MODEL(pedm);
						while (!STREAMING::HAS_MODEL_LOADED(pedm))
							WAIT(0);
						int my_group = PLAYER::GET_PLAYER_GROUP(selectedplayer);
						clone[gcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
						PED::SET_PED_AS_GROUP_LEADER(selectedplayer, my_group);
						PED::SET_PED_AS_GROUP_MEMBER(clone[gcount], my_group);
						PED::SET_PED_NEVER_LEAVES_GROUP(clone[gcount], my_group);
						ENTITY::SET_ENTITY_INVINCIBLE(clone[gcount], false);
						PED::SET_PED_COMBAT_ABILITY(clone[gcount], 100);
						WEAPON::GIVE_WEAPON_TO_PED(clone[gcount], railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(clone[gcount], true);
						PED::SET_GROUP_FORMATION(my_group, 3);
						PED::SET_PED_MAX_HEALTH(clone[gcount], 5000);
						gcount++;
					}
					int eclone[1000];
					int egcount = 1;
					if (Menu::Option("Spawn Enemy")) {
						Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
						Hash pedm = GAMEPLAY::GET_HASH_KEY("u_m_m_jesus_01");
						STREAMING::REQUEST_MODEL(pedm);
						while (!STREAMING::HAS_MODEL_LOADED(pedm))
							WAIT(0);
						eclone[egcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
						ENTITY::SET_ENTITY_INVINCIBLE(eclone[egcount], false);
						PED::SET_PED_COMBAT_ABILITY(eclone[egcount], 100);
						WEAPON::GIVE_WEAPON_TO_PED(eclone[egcount], railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(eclone[egcount], true);
						AI::TASK_COMBAT_PED(eclone[egcount], selectedplayer, 1, 1);
						PED::SET_PED_ALERTNESS(eclone[egcount], 1000);
						PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
						egcount++;
					}
					if (Menu::Option("Attach")) {
						if (player != PLAYER::PLAYER_PED_ID())
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, true, true, false, true, 2, true);
						}
					}
					if (Menu::Option("Detach")) {
						ENTITY::DETACH_ENTITY(PLAYER::PLAYER_PED_ID(), true, true);
					}
					if (Menu::Option("Cage Player")) {
						Features::trapcage(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
					}
					if (Menu::Option("Stunt Player")) {
						Features::trapcagee(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
					}
					if (PLAYER::PLAYER_PED_ID() == NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0)) {
						if (Menu::Option("Ban from CEO")) {
							if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer)))
							{
								NETWORK::NETWORK_SESSION_KICK_PLAYER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
							}
						}
					}
					else {
						if (Menu::Option("Kick Player")) {
							if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer)))
							{
								NETWORK::NETWORK_SESSION_KICK_PLAYER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
							}
						}
					}
					if (Menu::Option("Give All Weapons")) {
						uint Weapons[] = { 0x92A27487, 0x958A4A8F, 0xF9E6AA4B, 0x84BD7BFD, 0xA2719263, 0x8BB05FD7, 0x440E4788, 0x4E875F73, 0xF9DCBF2D, 0xD8DF3C3C, 0x99B507EA, 0xDD5DF8D9, 0xDFE37640, 0x678B81B1, 0x19044EE0, 0xCD274149, 0x94117305, 0x3813FC08, // Melee
							0x1B06D571, 0xBFE256D4, 0x5EF9FEC4, 0x22D8FE39, 0x3656C8C1, 0x99AEEB3B, 0xBFD21232, 0x88374054, 0xD205520E, 0x83839C4, 0x47757124, 0xDC4DB296, 0xC1B3C3D1, 0xCB96392F, 0x97EA20B8, // Handguns
							0x13532244, 0x2BE6766B, 0x2BE6766B, 0xEFE7E2DF, 0x0A3D4D34, 0xDB1AA450, 0xBD248B55, // Submachine Guns
							0x1D073A89, 0x555AF99A, 0x7846A318, 0xE284C527, 0x9D61E50F, 0xA89CB99E, 0x3AABBBAA, 0xEF951FBB, 0x12E82D3D, // Shotguns
							0xBFEFFF6D, 0x394F415C, 0x83BF0278, 0xFAD1F1C9, 0xAF113F99, 0xC0A3098D, 0x969C3D67, 0x7F229F94, 0x84D6FAFD, 0x624FE830, // Assault Rifles
							0x9D07F764, 0x7FD62962, 0xDBBD7280, 0x61012683, // Light Machine Guns
							0x05FC3C11, 0x0C472FE2, 0xA914799, 0xC734385A, 0x6A6C02E0, // Sniper Rifles
							0xB1CA77B1, 0xA284510B, 0x4DD2DC56, 0x42BF8A85, 0x7F7497E5, 0x6D544C99, 0x63AB0442, 0x0781FE4A, // Heavy Weapons
							0x93E220BD, 0xA0973D5E, 0x24B17070, 0x2C3731D9, 0xAB564B93, 0x787F0BB, 0xBA45E8B8, 0x23C9F95C, 0xFDBC8A50, 0x497FACC3, // Throwables
							0x34A67B97, 0xFBAB5776, 0x060EC506 // Miscellaneous
						};
						for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
							WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), Weapons[i], 9999, 1);
							WAIT(10);
						}
					}
					if (Menu::Option("Take All Weapons")) {
						uint Weapons[] = { 0x92A27487, 0x958A4A8F, 0xF9E6AA4B, 0x84BD7BFD, 0xA2719263, 0x8BB05FD7, 0x440E4788, 0x4E875F73, 0xF9DCBF2D, 0xD8DF3C3C, 0x99B507EA, 0xDD5DF8D9, 0xDFE37640, 0x678B81B1, 0x19044EE0, 0xCD274149, 0x94117305, 0x3813FC08, // Melee
							0x1B06D571, 0xBFE256D4, 0x5EF9FEC4, 0x22D8FE39, 0x3656C8C1, 0x99AEEB3B, 0xBFD21232, 0x88374054, 0xD205520E, 0x83839C4, 0x47757124, 0xDC4DB296, 0xC1B3C3D1, 0xCB96392F, 0x97EA20B8, // Handguns
							0x13532244, 0x2BE6766B, 0x2BE6766B, 0xEFE7E2DF, 0x0A3D4D34, 0xDB1AA450, 0xBD248B55, // Submachine Guns
							0x1D073A89, 0x555AF99A, 0x7846A318, 0xE284C527, 0x9D61E50F, 0xA89CB99E, 0x3AABBBAA, 0xEF951FBB, 0x12E82D3D, // Shotguns
							0xBFEFFF6D, 0x394F415C, 0x83BF0278, 0xFAD1F1C9, 0xAF113F99, 0xC0A3098D, 0x969C3D67, 0x7F229F94, 0x84D6FAFD, 0x624FE830, // Assault Rifles
							0x9D07F764, 0x7FD62962, 0xDBBD7280, 0x61012683, // Light Machine Guns
							0x05FC3C11, 0x0C472FE2, 0xA914799, 0xC734385A, 0x6A6C02E0, // Sniper Rifles
							0xB1CA77B1, 0xA284510B, 0x4DD2DC56, 0x42BF8A85, 0x7F7497E5, 0x6D544C99, 0x63AB0442, 0x0781FE4A, // Heavy Weapons
							0x93E220BD, 0xA0973D5E, 0x24B17070, 0x2C3731D9, 0xAB564B93, 0x787F0BB, 0xBA45E8B8, 0x23C9F95C, 0xFDBC8A50, 0x497FACC3, // Throwables
							0x34A67B97, 0xFBAB5776, 0x060EC506 // Miscellaneous
						};
						for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
							WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true);					WAIT(10);
						}
					}
				}
				break;



				//Select Online Player Codes 
				case onlinemenu_selected:
				{
					/*if (selecArrow) {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
						GRAPHICS::DRAW_MARKER(offradardpl, coords.x, coords.y, coords.z + 1.3f, 0, 0, 0, 0, 180, 0, 0.3, 0.3, 0.3, r1, g1, b1, 200, 1, 1, 1, 0, 0, 0, 0);
					}*/
					//Features::LoadPlayerInfo(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer), Features::Online::selectedPlayer);
					Menu::Title("");
					// Menu::Subtitle(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer));

					if (Features::Online::selectedPlayer != PLAYER::PLAYER_ID()) { Menu::MenuOption("~o~Force Animation", forcean); }
					if (Features::Online::selectedPlayer != PLAYER::PLAYER_ID()) { Menu::MenuOption("~o~TP Options", tpother); }


					Menu::MenuOption("~r~Select Arrow Typ", arrowsdraw);
					Menu::MenuOption("Effects", onlineftp);
					Menu::MenuOption("Attach to Player", attachtp);
					Menu::MenuOption("Drop Options", dropoptions);
					Menu::MenuOption("MoneyDrop System", dropOnline);
					Menu::MenuOption("CircleDrop System", dropOnline22);
					Menu::MenuOption("Remote Options", Remoteopt);
					Menu::MenuOption("Troll Options", trollo);

					Menu::MenuOption("Outfit Changer for other Players", cocplll);


					//Menu::Toggle("Close vehicle doors permanently", Features::closedoors[Features::Online::selectedPlayer], [] { Features::doorsclose(Features::closedoors[Features::Online::selectedPlayer]); });

				}
				break;

				case arrowsdraw:
				{
					Menu::Title("~r~Drop Options");
					// Menu::Subtitle("ARROW DRAW");

					if (selecArrow) {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
						GRAPHICS::DRAW_MARKER(offradardpl, coords.x, coords.y, coords.z + 1.3f, 0, 0, 0, 0, 180, 0, 0.3, 0.3, 0.3, r1, g1, b1, 200, 1, 1, 1, 0, 0, 0, 0);
					}
					Menu::Int("~w~Select Arrow Typ", offradardpl, 0, 43);

					Menu::Int("~r~R", r1, 0, 255);
					Menu::Int("~g~G", g1, 0, 255);
					Menu::Int("~b~B", b1, 0, 255);
				}
				break;

				case dropoptions:
				{
					Menu::Title("~r~Drop Options");
					// Menu::Subtitle("DROP OPTIONS");

					if (selecArrow) {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
						GRAPHICS::DRAW_MARKER(29, coords.x, coords.y, coords.z + 1.3f, 0, 0, 0, 0, 180, 0, 1, 1, 1, 0, 255, 255, 200, 1, 1, 1, 0, 0, 0, 0);
					}
					//Menu::Toggle("8 Mil Drop", Features::delop, [] {Features::lolop(Features::delop); });
					Menu::Toggle("Drop Him 2k (Alien Egg)", Features::savenewdrop6, [] {Features::cashdrop6(Features::savenewdrop6); });
					Menu::Toggle("Drop Him 2k (Xmax Tree)", Features::savenewdrop7, [] {Features::cashdrop7(Features::savenewdrop7); });
					Menu::Toggle("Drop Him 2k (Guitar)", Features::savenewdrop31, [] {Features::cashdrop31(Features::savenewdrop31); });
					//Menu::Toggle("~b~Drop Him 2.5k", Features::cashdrop69Toggle[Features::Online::selectedPlayer]);
					Menu::Toggle("Rain 2.5k", Features::rainMoney[Features::Online::selectedPlayer]);

					if (Menu::Option("Drop Armor")) {
						Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
						OBJECT::pockup(1274757841, pos.x, pos.y, pos.z + 1.5, 0, 100000, 1, 0, 1);
					}
					if (Menu::Option("Drop Parachute")) {
						Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
						OBJECT::pockup(1735599485, pos.x, pos.y, pos.z + 1.5, 0, 100000, 1, 0, 1);
					}
					if (Menu::Option("Drop Snack")) {
						Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
						if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
						OBJECT::pockup(483577702, pos.x, pos.y, pos.z + 1.5, 0, 100000, 1, 0, 1);
					}
				}
				break;

				case cstut:
				{
					Menu::Title("~r~Recovery");
					// Menu::Subtitle("STATS");


					Menu::Break("Change Stats");

					if (Menu::Option("~w~Set Money earn in Jobs")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_TOTAL_EVC"), val, 1);
					}

					if (Menu::Option("~w~Set total earned money")) {
						int temp1 = 0;
						temp1 = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_TOTAL_EVC"), temp1, 1);
					}

					if (Menu::Option("~w~Set Report Strength")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_REPORT_STRENGTH"), val, 1);
					}

					if (Menu::Option("Custom Deaths")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_DEATHS_PLAYER"), val, 1);
					}


					if (Menu::Option("~w~Set Commend Strength")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_COMMEND_STRENGTH"), val, 1);
					}


					if (Menu::Option("~w~Set Friendly Stuff")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_FRIENDLY"), val, 1);
					}


					if (Menu::Option("~w~Set Helpfull Stuff")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_HELPFUL"), val, 1);
					}

					if (Menu::Option("~w~Set Griefing")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_GRIEFING"), val, 1);
					}


					if (Menu::Option("~w~Set Offensive Language")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_OFFENSIVE_LANGUAGE"), val, 1);
					}


					if (Menu::Option("~w~Set Offensive UGC")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_OFFENSIVE_UGC"), val, 1);
					}


					if (Menu::Option("~w~Set VC Hate")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_VC_HATE"), val, 1);
					}


					if (Menu::Option("~w~Set Gameplay Exploits")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_GAME_EXPLOITS"), val, 1);
					}


					if (Menu::Option("~w~Set Inspunished")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_ISPUNISHED"), val, 1);
					}


					if (Menu::Option("~w~Set Badsports")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_1ST_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_2ND_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_3RD_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_4TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_5TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_6TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_7TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_8TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_9TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_10TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_1ST_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_2ND_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_3RD_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_4TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_5TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_6TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_7TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_8TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_9TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_11TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_1ST_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_2ND_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_3RD_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_4TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_5TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_6TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_7TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_8TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_9TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_11TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_1ST_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_2ND_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_3RD_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_4TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_5TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_6TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_7TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_8TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_9TH_OFFENCE"), val, 1);
						STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_11TH_OFFENCE"), val, 1);
						STATS::STAT_SET_FLOAT($("BADSPORT_RESET_MINUTES"), val, 1);
						STATS::STAT_SET_FLOAT($("BADSPORT_RESET_MINUTES"), val, 1);
						STATS::STAT_SET_FLOAT($("MPPLY_OVERALL_BADSPORT"), val, 1);
						STATS::STAT_SET_BOOL($("MPPLY_CHAR_IS_BADSPORT"), val, 1);
						STATS::STAT_SET_INT($("MPPLY_BECAME_BADSPORT_NUM"), val, 1);
						STATS::STAT_SET_INT($("BAD_SPORT_BITSET"), val, 1);
						STATS::STAT_SET_INT($("CHEAT_BITSET"), val, 1);



					}



					if (Menu::Option("Set Kills")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_KILLS_PLAYERS"), val, 1);
					}

					if (Menu::Option("Set Won Races")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("AWD_RACES_WON"), val, 1);
						STATS::STAT_SET_INT($("AWD_FM_GTA_RACES_WON"), val, 1);
					}
					if (Menu::Option("Set Armwrestling Wins")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("AWD_NO_ARMWRESTLING_WINS"), val, 1);
					}
					if (Menu::Option("Set Deathmatch Wins")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("AWD_FM_DM_WINS"), val, 1);
						STATS::STAT_SET_INT($("AWD_FM_DM_WINS"), val, 1);
						STATS::STAT_SET_INT($("AWD_FM_TDM_WINS"), val, 1);
					}
					if (Menu::Option("Set Deathmatch Losses")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_TOTAL_DEATHMATCH_LOST"), val, 1);
					}
					if (Menu::Option("Set Death Match Kills")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("AWD_FM_DM_TOTALKILLS"), val, 1);
					}


					if (Menu::Option("Set Death Match Deaths")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_DM_TOTAL_DEATHS"), val, 1);
					}
					if (Menu::Option("Set Death Match Deaths")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("MPPLY_DM_TOTAL_DEATHS"), val, 1);
					}
					if (Menu::Option("Set Golf Wins")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("AWD_FM_GOLF_WON"), val, 1);
					}
					if (Menu::Option("Set Shooting Range Wins")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("AWD_FM_SHOOTRANG_TG_WON"), val, 1);
						STATS::STAT_SET_INT($("AWD_FM_SHOOTRANG_RT_WON"), val, 1);
						STATS::STAT_SET_INT($("AWD_FM_SHOOTRANG_CT_WON"), val, 1);
						STATS::STAT_SET_INT($("AWD_FM_SHOOTRANG_GRAN_WON"), val, 1);
					}
					if (Menu::Option("Set Tennis Wins")) {
						int val = NumberKeyboard();
						STATS::STAT_SET_INT($("AWD_FM_TENNIS_WON"), val, 1);
						STATS::STAT_SET_INT($("MPPLY_TENNIS_MATCHES_WON"), val, 1);
					}
					if (Menu::Option("Weapons")) {
						int val = NumberKeyboard();

						STATS::STAT_SET_INT($("MOLOTOV_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("CMBTPISTOL_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("PISTOL50_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("APPISTOL_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("MICROSMG_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("SMG_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("ASLTSMG_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("ASLTRIFLE_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("CRBNRIFLE_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("ADVRIFLE_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("MG_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("CMBTMG_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("ASLTMG_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("PUMP_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("SAWNOFF_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("BULLPUP_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("ASLTSHTGN_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("SNIPERRFL_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("HVYSNIPER_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("GRNLAUNCH_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("RPG_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("MINIGUNS_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("GRENADE_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("SMKGRENADE_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("STKYBMB_ENEMY_KILLS"), val, 1);
						STATS::STAT_SET_INT($("MOLOTOV_ENEMY_KILLS"), val, 1);
					}

				}
				break;

				case vstut:
				{
					Menu::Title("~r~Viw Stats");
					// Menu::Subtitle("STATS VIEWER");

					Menu::Break("View Stats");

					int reportkek;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), &reportkek, -1);
					const auto& reportstringkek = "Gameplay Exploits: "s + std::to_string(reportkek);
					Menu::Option(reportstringkek.c_str());

					int reportkek1;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), &reportkek1, -1);
					const auto& reportstringkek1 = "Report Strength: "s + std::to_string(reportkek1);
					Menu::Option(reportstringkek1.c_str());

					int reportkek2;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), &reportkek2, -1);
					const auto& reportstringkek2 = "Commend Strength: "s + std::to_string(reportkek2);
					Menu::Option(reportstringkek2.c_str());

					int reportkek3;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_FRIENDLY"), &reportkek3, -1);
					const auto& reportstringkek3 = "Friendly Stuff: "s + std::to_string(reportkek3);
					Menu::Option(reportstringkek3.c_str());

					int reportkek4;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_HELPFUL"), &reportkek4, -1);
					const auto& reportstringkek4 = "Helpfull Stuff: "s + std::to_string(reportkek4);
					Menu::Option(reportstringkek4.c_str());

					int reportkek5;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GRIEFING"), &reportkek5, -1);
					const auto& reportstringkek5 = "Griefing: "s + std::to_string(reportkek5);
					Menu::Option(reportstringkek5.c_str());

					int reportkek6;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), &reportkek6, -1);
					const auto& reportstringkek6 = "Offensive Language: "s + std::to_string(reportkek6);
					Menu::Option(reportstringkek6.c_str());

					int reportkek7;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), &reportkek7, -1);
					const auto& reportstringkek7 = "Offensive UGC: "s + std::to_string(reportkek7);
					Menu::Option(reportstringkek7.c_str());

					int reportkek8;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VC_HATE"), &reportkek8, -1);
					const auto& reportstringkek8 = "VC Hate: "s + std::to_string(reportkek8);
					Menu::Option(reportstringkek8.c_str());

					int reportkek9;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_ISPUNISHED"), &reportkek9, -1);
					const auto& reportstringkek9 = "Inspunished: "s + std::to_string(reportkek9);
					Menu::Option(reportstringkek9.c_str());

					int reportkek10;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_KILLS_PLAYERS"), &reportkek10, -1);
					const auto& reportstringkek10 = "Kills: "s + std::to_string(reportkek10);
					Menu::Option(reportstringkek10.c_str());

					int reportkek11;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("AWD_RACES_WON"), &reportkek11, -1);
					const auto& reportstringkek11 = "Won Races: "s + std::to_string(reportkek11);
					Menu::Option(reportstringkek11.c_str());

					int reportkek12;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("AWD_NO_ARMWRESTLING_WINS"), &reportkek12, -1);
					const auto& reportstringkek12 = "Armwrestling Wins: "s + std::to_string(reportkek12);
					Menu::Option(reportstringkek12.c_str());

					int reportkek13;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("AWD_FM_DM_WINS"), &reportkek13, -1);
					const auto& reportstringkek13 = "Deathmatch Wins: "s + std::to_string(reportkek13);
					Menu::Option(reportstringkek13.c_str());

					int reportkek14;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_TOTAL_DEATHMATCH_LOST"), &reportkek14, -1);
					const auto& reportstringkek14 = "Deathmatch Losses: "s + std::to_string(reportkek14);
					Menu::Option(reportstringkek14.c_str());


					int reportkek15;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("AWD_FM_DM_TOTALKILLS"), &reportkek15, -1);
					const auto& reportstringkek15 = "Death Match Kills: "s + std::to_string(reportkek15);
					Menu::Option(reportstringkek15.c_str());

					int reportkek16;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_DM_TOTAL_DEATHS"), &reportkek16, -1);
					const auto& reportstringkek16 = "Death Match Deaths: "s + std::to_string(reportkek16);
					Menu::Option(reportstringkek16.c_str());

					int reportkek17;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("AWD_FM_GOLF_WON"), &reportkek17, -1);
					const auto& reportstringkek17 = "Golf Wins: "s + std::to_string(reportkek17);
					Menu::Option(reportstringkek17.c_str());

					int reportkek18;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("AWD_FM_SHOOTRANG_TG_WON"), &reportkek18, -1);
					const auto& reportstringkek18 = "Range Wins: "s + std::to_string(reportkek18);
					Menu::Option(reportstringkek18.c_str());

					int reportkek19;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("AWD_FM_TENNIS_WON"), &reportkek19, -1);
					const auto& reportstringkek19 = "Tennis Wins: "s + std::to_string(reportkek19);
					Menu::Option(reportstringkek19.c_str());

					int reportkek20;
					STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("AWD_FM_TENNIS_WON"), &reportkek20, -1);
					const auto& reportstringkek20 = "Tennis Wins: "s + std::to_string(reportkek20);
					Menu::Option(reportstringkek20.c_str());

				}
				break;

				case stut:
				{
					Menu::Title("~r~Recovery");
					// Menu::Subtitle("RECOVERIES");

					Menu::MenuOption("Change Stats", cstut);
					Menu::MenuOption("View Stats", vstut);

				}
				break;


				case recover:
				{
					Menu::Title("~r~Recovery");
					// Menu::Subtitle("RECOVERY");

					if (Menu::Option("15 Million"))
					{
						globalHandle(4264465 + 1).As<int>() = 2147483646;
						globalHandle(4264465 + 7).As<int>() = 2147483647;
						globalHandle(4264465 + 6).As<int>() = 0;
						globalHandle(4264465 + 5).As<int>() = 0;
						globalHandle(4264465 + 3).As<int>() = -1586170317;
						globalHandle(4264465 + 2).As<int>() = 15000000;
						globalHandle(4264465 + 80).At(80).As<int>() = 1;
						globalHandle(4264465).As<int>() = 1;
					}

				}
				break;


				case unlockall: {
					Menu::Title("~w~UnlockAll");
					// Menu::Subtitle("UNLOCK ALL");

					if (Menu::Option("Enable Biker Club Clutter")) {
						Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("LIFETIME_BIKER_BUY_COMPLET"), 1200, 0);
						Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("LIFETIME_BIKER_BUY_COMPLET"), 1200, 0);
						Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("LIFETIME_BIKER_BUY_UNDERTA"), 1200, 0);
						Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("LIFETIME_BIKER_SELL_COMPLET"), 1200, 0);
						Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("LIFETIME_BIKER_SELL_UNDERTA"), 1200, 0);
						Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("LIFETIME_BKR_SELL_EARNINGS0"), 1200, 0);

					}

					if (Menu::Option("~w~Reset Mental State"))
					{

						resetMentalState();

						UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
						UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~Mental State restet");
						UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "~w~Nano69", "~w~Prime", 1, "UnlockAll", 9, 0);
						UI::_DRAW_NOTIFICATION(FALSE, FALSE);
					}

					if (Menu::Option("~w~Unlock Wire frame T-shirts"))
					{

						unlockWireframeTshirts();

						UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
						UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~Unlock Wire frame T-shirts successfully");
						UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "~w~Nano60", "~w~Prime", 1, "UnlockAll", 9, 0);
						UI::_DRAW_NOTIFICATION(FALSE, FALSE);
					}

					if (Menu::Option("~w~Unlock Heist Clothes"))
					{

						resetMentalState();

						UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
						UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~Unlock Heist Clothes successfully");
						UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "~w~Nano60", "~w~Prime", 1, "UnlockAll", 9, 0);
						UI::_DRAW_NOTIFICATION(FALSE, FALSE);
					}

					//if (Menu::Option("~w~All bunker extensions")) { // look i have globals off radar

					//	addBunkerBusinessProfit;

					//}

					if (Menu::Option("~w~Unlock Office Money")) { // look i have globals off radar

						Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_LIFETIME_BUY_COMPLETE"), 1223, 0);
						Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_LIFETIME_BUY_UNDERTAKEN"), 1223, 0);
						Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_LIFETIME_SELL_COMPLETE"), 434, 0);
						Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_LIFETIME_SELL_UNDERTAKEN"), 434, 0);
						Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_LIFETIME_CONTRA_EARNINGS"), 1220000000, 0);

						UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
						UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Office Money Unlocked!");
						UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_BUGSTARS", "CHAR_BUGSTARS", 1, 8, "Nano60", "Recovery", 1, "", 9, 0);

						UI::_DRAW_NOTIFICATION(FALSE, FALSE);

					}

					/*		if (Menu::Option("Max Night Club Popularity")) {
								char sbuf[50];
								int stat_r;
								STATS::STAT_GET_INT($("MPPLY_LAST_MP_CHAR"), &stat_r, 1);
								snprintf(sbuf, sizeof(sbuf), "MP%i%s", stat_r, "CLUB_POPULARITY");
								STATS::STAT_SET_INT($(sbuf), 1000, 1);
							}*/

					if (Menu::Option("Clear Reports")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, true);
							Hooking::stat_set_float(GAMEPLAY::GET_HASH_KEY("BADSPORT_RESET_MINUTES"), 1.0, true);
							Hooking::stat_set_float(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_RESET_MINUTES"), 1.0, true);
							Hooking::stat_set_float(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_RESET_MINUTES"), 1.0, true);
							Hooking::stat_set_float(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_RESET_MINUTES"), 1.0, true);
							Hooking::stat_set_float(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OVERALL_BADSPORT"), 0, true);
							Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_CHAR_IS_BADSPORT"), false, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_BECAME_BADSPORT_NUM"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BAD_SPORT_BITSET"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHEAT_BITSET"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_REPORT_STRENGTH"), 32, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_COMMEND_STRENGTH"), 100, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_FRIENDLY"), 100, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_HELPFUL"), 100, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_GRIEFING"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_LANGUAGE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_UGC"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_VC_HATE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_GAME_EXPLOITS"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_ISPUNISHED"), 0, true);
							Hooking::stat_set_float(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OVERALL_BADSPORT"), 0, true);
							Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_CHAR_IS_BADSPORT"), false, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_BECAME_BADSPORT_NUM"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BAD_SPORT_BITSET"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHEAT_BITSET"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_REPORT_STRENGTH"), 32, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_COMMEND_STRENGTH"), 100, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_FRIENDLY"), 100, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_HELPFUL"), 100, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_GRIEFING"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_LANGUAGE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_UGC"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_VC_HATE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_GAME_EXPLOITS"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_ISPUNISHED"), 0, true);
							Hooking::stat_set_float(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OVERALL_BADSPORT"), 0, true);
							Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_CHAR_IS_BADSPORT"), false, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_BECAME_BADSPORT_NUM"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BAD_SPORT_BITSET"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHEAT_BITSET"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_REPORT_STRENGTH"), 32, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_COMMEND_STRENGTH"), 100, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_FRIENDLY"), 100, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_HELPFUL"), 100, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_GRIEFING"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_LANGUAGE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_UGC"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_VC_HATE"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_GAME_EXPLOITS"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_ISPUNISHED"), 0, true);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_1ST_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_2ND_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_3RD_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_4TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_5TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_6TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_7TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_8TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_9TH_OFFENCE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_NUMDAYS_10TH_OFFENCE"), 0, 1);
							Hooking::stat_set_float(GAMEPLAY::GET_HASH_KEY("BADSPORT_RESET_MINUTES"), 1.0, 1);
							Hooking::stat_set_float(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_RESET_MINUTES"), 1.0, 1);
							Hooking::stat_set_float(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_RESET_MINUTES"), 1.0, 1);
							Hooking::stat_set_float(GAMEPLAY::GET_HASH_KEY("MP0_BADSPORT_RESET_MINUTES"), 1.0, 1);
							Hooking::stat_set_float(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OVERALL_BADSPORT"), 0, 1);
							Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_CHAR_IS_BADSPORT"), false, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_BECAME_BADSPORT_NUM"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BAD_SPORT_BITSET"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHEAT_BITSET"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_REPORT_STRENGTH"), 32, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_COMMEND_STRENGTH"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_FRIENDLY"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_HELPFUL"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_GRIEFING"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_UGC"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_VC_HATE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_GAME_EXPLOITS"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_ISPUNISHED"), 0, 1);
							Hooking::stat_set_float(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OVERALL_BADSPORT"), 0, 1);
							Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_CHAR_IS_BADSPORT"), false, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_BECAME_BADSPORT_NUM"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BAD_SPORT_BITSET"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHEAT_BITSET"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_REPORT_STRENGTH"), 32, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_COMMEND_STRENGTH"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_FRIENDLY"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_HELPFUL"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_GRIEFING"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_UGC"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_VC_HATE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_GAME_EXPLOITS"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_ISPUNISHED"), 0, 1);
							Hooking::stat_set_float(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OVERALL_BADSPORT"), 0, 1);
							Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_CHAR_IS_BADSPORT"), false, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_BECAME_BADSPORT_NUM"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BAD_SPORT_BITSET"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHEAT_BITSET"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_REPORT_STRENGTH"), 32, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_COMMEND_STRENGTH"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_FRIENDLY"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_HELPFUL"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_GRIEFING"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_UGC"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_VC_HATE"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_GAME_EXPLOITS"), 0, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_ISPUNISHED"), 0, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~Reports Removed!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "~w~Nano60", "~w~Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);
						}
					}

					if (Menu::Option("Clear Badsport Stats")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_float(GAMEPLAY::GET_HASH_KEY("MPPLY_OVERALL_BADSPORT"), 0.0f, TRUE);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MPPLY_DESTROYED_PVEHICLES"), 0, TRUE);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MPPLY_BADSPORT_MESSAGE"), 0, TRUE);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~Clear Badsport Stats Done!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "~w~Nano60", "~w~Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);
						}
					}
					if (Menu::Option("Set Max Skill")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STAM"), 100, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STRN"), 100, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_LUNG"), 100, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_DRIV"), 100, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_FLY"), 100, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_SHO"), 100, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STL"), 100, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_script_increase_stam"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_script_increase_strn"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_script_increase_lung"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_script_increase_driv"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_script_increase_fly"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_script_increase_sho"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_script_increase_stl"), 100, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~Set Max Skill Done!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "~w~Nano60", "~w~Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);
						}
					}
					if (Menu::Option("Unlock All Tattoos")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_8"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_9"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_10"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_11"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_12"), -1, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Unlock All Tattoos Done!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("Add Snacks")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_NO_BOUGHT_YUM_SNACKS"), 99999999, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_NO_BOUGHT_HEALTH_SNACKS"), 99999999, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_NO_BOUGHT_EPIC_SNACKS"), 99999999, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CIGARETTES_BOUGHT"), 99999999, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_NUMBER_OF_ORANGE_BOUGHT"), 99999999, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_NUMBER_OF_BOURGE_BOUGHT"), 99999999, 0);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Snacks Added!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("Unlock Weapon Skins")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV _ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CMBTPISTOL_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_PISTOL50_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_APPISTOL_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MICROSMG_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SMG_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSMG_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ASLTRIFLE_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CRBNRIFLE_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADVRIFLE_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MG_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CMBTMG_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ASLTMG_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_PUMP_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SAWNOFF_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BULLPUP_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSHTGN_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SNIPERRFL_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_HVYSNIPER_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_GRNLAUNCH_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_RPG_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MINIGUNS_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SMKGRENADE_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_STKYBMB_ENEMY_KILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("All Weapon Skins Unlocked!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("Purchase Clothing")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_8"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_9"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_10"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_OUTFIT"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_5"), -1, 1);;
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_6"), -1, 1);;
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_8"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_9"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_10"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_OUTFIT"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TORSO"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_DECL"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TORSO"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_DECL"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_0"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_8"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_9"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_10"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_11"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_12"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_13"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_14"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_15"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_16"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_17"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_18"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_19"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_21"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_22"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_23"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_25"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_26"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_27"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_28"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_29"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_30"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_31"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_32"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_33"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_34"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_35"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_36"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_37"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_38"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_39"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_40"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_8"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_9"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_13"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Clothing Unlocked!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("Unlock LSC")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_ENEMYDRIVEBYKILLS"), 600, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_USJS_FOUND"), 50, 0);
							Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINALLRACEMODES"), 1, 0);
							Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DB_PLAYER_KILLS"), 1000, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_KILLS_PLAYERS"), 1000, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMHORDWAVESSURVIVE"), 21, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 60, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_RACES_WON"), 101, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_NO_ARMWRESTLING_WINS"), 21, 0);
							Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMBBETWIN"), 50000, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 51, 0);
							Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_DM_TOTAL_DEATHS"), 412, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 623, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 63, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_WINS"), 13, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GTA_RACES_WON"), 12, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GOLF_WON"), 2, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_TG_WON"), 2, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_RT_WON"), 2, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_CT_WON"), 2, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 2, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TENNIS_WON"), 2, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TENNIS_MATCHES_WON"), 2, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_WON"), 101, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_LOST"), 36, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_25_KILLS_STICKYBOMBS"), 50, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_50_KILLS_GRENADES"), 50, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS "), 50, 0);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_20_KILLS_MELEE"), 50, 0);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Unlock ALC!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);
						}
					}
					if (Menu::Option("Unlock All Heist Vehicles")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_VEHICLE_1_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_VEHICLE_2_UNLCK"), -1, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Unlock All Heist Vehicles!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("2 Billion Snacks")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_NO_BOUGHT_YUM_SNACKS"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_NO_BOUGHT_HEALTH_SNACKS"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_NO_BOUGHT_EPIC_SNACKS"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_NUMBER_OF_ORANGE_BOUGHT"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CIGARETTES_BOUGHT"), 2000000000, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("2Billion Snacks!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("2 Billion Armour")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MP_CHAR_ARMOUR_1_COUNT"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MP_CHAR_ARMOUR_2_COUNT"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MP_CHAR_ARMOUR_3_COUNT"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MP_CHAR_ARMOUR_4_COUNT"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MP_CHAR_ARMOUR_5_COUNT"), 2000000000, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("2Billion Armour!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("2 Billion Firworks")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_1_WHITE"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_1_RED"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_1_BLUE"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_2_WHITE"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_2_RED"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_2_BLUE"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_3_WHITE"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_3_RED"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_3_BLUE"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_4_WHITE"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_4_RED"), 2000000000, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_4_BLUE"), 2000000000, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("2Billion Fireworks!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("Unlock All Camos and Parachutes")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_1_FM_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_2_FM_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_3_FM_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_4_FM_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_5_FM_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_6_FM_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_7_FM_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_8_FM_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_9_FM_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_10_FM_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_11_FM_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_12_FM_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE7"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE8"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE9"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE10"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE11"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE12"), -1, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Unlock All Camos and Parachutes!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("Unlock All Chrome Rims")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_WIN_CAPTURES"), 25, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_DROPOFF_CAP_PACKAGES"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_KILL_CARRIER_CAPTURE"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FINISH_HEISTS"), 50, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FINISH_HEIST_SETUP_JOB"), 50, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_WIN_LAST_TEAM_STANDINGS"), 50, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_ONLY_PLAYER_ALIVE_LTS"), 50, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Unlock All Chrome Rims!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("Unlock Exclusive T-Shirts")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMHORDWAVESSURVIVE"), 10, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMPICKUPDLCCRATE1ST"), 1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_WIN_CAPTURE_DONT_DYING"), 25, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_DO_HEIST_AS_MEMBER"), 25, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_PICKUP_CAP_PACKAGES"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FINISH_HEIST_NO_DAMAGE"), 1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_WIN_GOLD_MEDAL_HEISTS"), 25, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_KILL_TEAM_YOURSELF_LTS"), 25, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_KILL_PSYCHOPATHS"), 100, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_DO_HEIST_AS_THE_LEADER"), 25, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_STORE_20_CAR_IN_GARAGES"), 1, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Unlock Exclusive T-Shirts!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("Unlock All Vehicle Mods (LSC)")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_1_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_2_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_3_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_4_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_5_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_6_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_7_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRALLYWONDRIVE"), 1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRALLYWONNAV"), 1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINSEARACE"), 1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINAIRRACE"), 1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_NUMBER_TURBO_STARTS_IN_RACE"), 50, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_RACES_FASTEST_LAP"), 50, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_NUMBER_SLIPSTREAMS_IN_RACE"), 100, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Unlock All Vehicle Mods (LSC)!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);


						}
					}
					if (Menu::Option("Redesign Character Prompt")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_FM_CHANGECHAR_ASKED"), 0, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Redesign Character Prompt!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("Skip Tutorial")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_NO_MORE_TUTORIALS"), 1, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Skip Tutorial!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("Unlock All Heist' Trophies")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MPPLY_HEIST_ACH_TRACKER"), -1, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Unlock All Heist' Trophies!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("Unlock All Hairstyles")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Unlock All Hairstyles!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("Purchase All Weapons")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_WEAPON_GV_BS_1"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_WEAPON_GV_BS_2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_WEAPON_GV_BS_3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BOTTLE_IN_POSSESSION"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_UNLOCKED"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_UNLOCKED2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_WEAP_FM_PURCHASE"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_WEAP_FM_PURCHASE2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_1_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_2_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_3_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_4_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_5_UNLCK"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH2"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH3"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH4"), -1, 1);
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH5"), -1, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Purchase All Weapons!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "Nano60", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
					if (Menu::Option("Enable Roosevelt in Phone")) {
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
						{
							Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MPPLY_ICLE_ID_ADMIN_WEB"), 117401876, 1);
							UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
							UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Enable Roosevelt in Phone!");
							UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_LESTER_DEATHWISH", "CHAR_LESTER_DEATHWISH", 1, 8, "`", "Prime", 1, "UnlockAll", 9, 0);
							UI::_DRAW_NOTIFICATION(FALSE, FALSE);

						}
					}
				}
							  break;
				case mods:
				{
					// Menu::Subtitle("MODS");

					Menu::Title("MISCELLANOUS");
					Menu::MenuOption("Modded Vehicles", Ulti);
					Menu::MenuOption("Map Mods", exploitramp);
					Menu::MenuOption("Riding menu", ride);
					Menu::MenuOption("Object Spawner", objSpawner);
					Menu::MenuOption("Super Options", supermenu);
					Menu::MenuOption("Sounds", sounds);
				}
				break;

				case namechange:
				{
					// Menu::Subtitle("NAMECHANGER");

					Menu::Title("Change Name");

					Menu::Break("Change your Name");

					if (Menu::Option("~w~Name Changer")) {

						Features::NameChanger();
						notifyMap("Change Lobby To Apply Name");
					}

				}
				break;

				case Ulti:
				{
					Menu::Title("Custom Vehicles");
					// Menu::Subtitle("MODDED CARS");

					Menu::Break("Let your vehicle tow");


					if (Menu::ListVector("Choose Vehicle for FlatBed ", Superr1, soutprop32)) {
						Features::vf(Superr1[soutprop32]);
					};

					if (Menu::Option("Put Custom Vehicle")) {
						GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "", "", "", "", "", "", 100);
						while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
						Features::vf(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
					}

					Menu::Break(" Modded Vehicles");

					if (Menu::ListVector("custom vehicles", ini1, inipos))
						LoadPreset(ini1[inipos]);
					if (Menu::Option("6x6 War RC")) {
						int Handle = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("dune2");
						int hash2 = GAMEPLAY::GET_HASH_KEY("t20");
						int hash3 = GAMEPLAY::GET_HASH_KEY("dune2");
						int hash4 = GAMEPLAY::GET_HASH_KEY("dune2");
						int hash5 = GAMEPLAY::GET_HASH_KEY("monster");
						int hash6 = GAMEPLAY::GET_HASH_KEY("monster");


						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						STREAMING::REQUEST_MODEL(hash3);
						STREAMING::REQUEST_MODEL(hash4);
						STREAMING::REQUEST_MODEL(hash5);
						STREAMING::REQUEST_MODEL(hash6);


						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5) && STREAMING::HAS_MODEL_LOADED(hash6))
						{
							int Object1 = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object2 = VEHICLE::erstelle_fahr(hash3, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object3 = VEHICLE::erstelle_fahr(hash4, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object4 = VEHICLE::erstelle_fahr(hash5, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object5 = VEHICLE::erstelle_fahr(hash6, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);



							if (ENTITY::DOES_ENTITY_EXIST(Object1) && ENTITY::DOES_ENTITY_EXIST(Object2) && ENTITY::DOES_ENTITY_EXIST(Object3) && ENTITY::DOES_ENTITY_EXIST(Object4) && ENTITY::DOES_ENTITY_EXIST(Object5))
							{
								int Vehicle = VEHICLE::erstelle_fahr(hash2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
								if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
								{
									PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);

									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a.x - 0.1f, a.y, a.z, b.x, b.y + 41.1f, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object3, Vehicle, 0, a.x + 0.1f, a.y, a.z, b.x, b.y - 41.4f, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object4, Vehicle, 0, a.x + 1.41f, a.y, a.z - 0.2f, b.x - 179.99f, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object5, Vehicle, 0, a.x - 1.41f, a.y, a.z - 0.2f, b.x - 179.99f, b.y, b.z, 0, 1, 0, 0, 2, 1);

									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 255, 255, 255);
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 255, 255, 255);
									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object1, 255, 255, 255);
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object1, 255, 255, 255);
									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object4, 255, 255, 255);
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object4, 255, 255, 255);
									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object5, 255, 255, 255);
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object5, 255, 255, 255);
								}

							}

						}
					}
					if (Menu::Option("Speeder Prototype")) {
						int Handle = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("seashark");
						int hash1 = GAMEPLAY::GET_HASH_KEY("seashark");
						int hash2 = GAMEPLAY::GET_HASH_KEY("turismor");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash1);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash1) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Object = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object1 = VEHICLE::erstelle_fahr(hash1, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Object))
							{
								int Vehicle = VEHICLE::erstelle_fahr(hash2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
								if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
								{
									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 255, 0, 0);
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 255, 0, 0);
									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 255, 0, 0);
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 255, 0, 0);
									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object1, 255, 0, 0);
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object1, 255, 0, 0);
									PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y + 1.37f, a.z + 0.59f, b.x - 14.33f, b.y + 541.20f, b.z - 1.42f, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a.x, a.y - 0.79f, a.z + 0.83f, b.x + 9.72f, b.y + 539.03f, b.z - 0.16f, 0, 1, 0, 0, 2, 1);
								}
							}
						}
					}
					if (Menu::Option("Snow Scooter")) {
						int Handle = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("seashark");
						int hash2 = GAMEPLAY::GET_HASH_KEY("sanchez");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Object = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Object))
							{
								int Vehicle = VEHICLE::erstelle_fahr(hash2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
								if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
								{
									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 255, 0, 0);
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 255, 0, 0);
									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 255, 0, 0);
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 255, 0, 0);
									PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);

									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x - 0.02f, a.y - 0.08f, a.z - 0.36f, b.x - 0.21f, b.y + 1.83f, b.z - 0.21f, 0, 1, 0, 0, 2, 1);

								}
							}
						}
					}
					if (Menu::Option("Military Flightsquad")) {
						int Handle = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("hydra");
						int hash1 = GAMEPLAY::GET_HASH_KEY("hydra");
						int hash2 = GAMEPLAY::GET_HASH_KEY("hydra");
						int hash3 = GAMEPLAY::GET_HASH_KEY("hydra");
						int hash4 = GAMEPLAY::GET_HASH_KEY("hydra");
						int hash5 = GAMEPLAY::GET_HASH_KEY("hydra");
						int hash6 = GAMEPLAY::GET_HASH_KEY("hydra");
						int hash7 = GAMEPLAY::GET_HASH_KEY("hydra");
						int hash8 = GAMEPLAY::GET_HASH_KEY("hydra");

						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						STREAMING::REQUEST_MODEL(hash1);
						STREAMING::REQUEST_MODEL(hash3);
						STREAMING::REQUEST_MODEL(hash4);
						STREAMING::REQUEST_MODEL(hash5);
						STREAMING::REQUEST_MODEL(hash6);
						STREAMING::REQUEST_MODEL(hash7);
						STREAMING::REQUEST_MODEL(hash8);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash1) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5) && STREAMING::HAS_MODEL_LOADED(hash6) && STREAMING::HAS_MODEL_LOADED(hash7) && STREAMING::HAS_MODEL_LOADED(hash8))
						{
							int Object = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object1 = VEHICLE::erstelle_fahr(hash1, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object2 = VEHICLE::erstelle_fahr(hash3, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object3 = VEHICLE::erstelle_fahr(hash4, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object4 = VEHICLE::erstelle_fahr(hash5, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object5 = VEHICLE::erstelle_fahr(hash6, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object6 = VEHICLE::erstelle_fahr(hash7, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object7 = VEHICLE::erstelle_fahr(hash8, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Object))
							{
								int Vehicle = VEHICLE::erstelle_fahr(hash2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
								if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
								{

									PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);


									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y + 15.541162f, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a.x, a.y + 30.541162f, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a.x - 15.0f, a.y + 15.541162f, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object3, Vehicle, 0, a.x + 15.0f, a.y + 15.541162f, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object4, Vehicle, 0, a.x + 15.0f, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object5, Vehicle, 0, a.x + 30.0f, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object6, Vehicle, 0, a.x - 15.0f, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object7, Vehicle, 0, a.x - 30.0f, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);

								}
							}
						}
					}
					if (Menu::Option("Bike Robot")) {
						int Handle = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("bati");
						int hash1 = GAMEPLAY::GET_HASH_KEY("bati");
						int hash2 = GAMEPLAY::GET_HASH_KEY("bati");
						int hash3 = GAMEPLAY::GET_HASH_KEY("bati");
						int hash4 = GAMEPLAY::GET_HASH_KEY("bati");
						int hash5 = GAMEPLAY::GET_HASH_KEY("bati");
						int hash6 = GAMEPLAY::GET_HASH_KEY("bati");
						int hash7 = GAMEPLAY::GET_HASH_KEY("bati");
						int hash8 = GAMEPLAY::GET_HASH_KEY("bati");
						int hash9 = GAMEPLAY::GET_HASH_KEY("bati");
						int hash10 = GAMEPLAY::GET_HASH_KEY("bati");
						int hash11 = GAMEPLAY::GET_HASH_KEY("bati");
						int hash12 = GAMEPLAY::GET_HASH_KEY("bati");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash1);
						STREAMING::REQUEST_MODEL(hash2);
						STREAMING::REQUEST_MODEL(hash2);
						STREAMING::REQUEST_MODEL(hash3);
						STREAMING::REQUEST_MODEL(hash4);
						STREAMING::REQUEST_MODEL(hash5);
						STREAMING::REQUEST_MODEL(hash6);
						STREAMING::REQUEST_MODEL(hash7);
						STREAMING::REQUEST_MODEL(hash8);
						STREAMING::REQUEST_MODEL(hash9);
						STREAMING::REQUEST_MODEL(hash10);
						STREAMING::REQUEST_MODEL(hash11);
						STREAMING::REQUEST_MODEL(hash12);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash1) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5) && STREAMING::HAS_MODEL_LOADED(hash6) && STREAMING::HAS_MODEL_LOADED(hash7) && STREAMING::HAS_MODEL_LOADED(hash8) && STREAMING::HAS_MODEL_LOADED(hash9) && STREAMING::HAS_MODEL_LOADED(hash10) && STREAMING::HAS_MODEL_LOADED(hash11))
						{
							int Object = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object1 = VEHICLE::erstelle_fahr(hash1, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object2 = VEHICLE::erstelle_fahr(hash3, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object3 = VEHICLE::erstelle_fahr(hash4, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object4 = VEHICLE::erstelle_fahr(hash5, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object5 = VEHICLE::erstelle_fahr(hash6, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object6 = VEHICLE::erstelle_fahr(hash7, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object7 = VEHICLE::erstelle_fahr(hash8, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object8 = VEHICLE::erstelle_fahr(hash9, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object9 = VEHICLE::erstelle_fahr(hash10, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object10 = VEHICLE::erstelle_fahr(hash11, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Object11 = VEHICLE::erstelle_fahr(hash12, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Object))
							{
								int Vehicle = VEHICLE::erstelle_fahr(hash2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
								if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
								{
									PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);

									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z + 1.16f, b.x + 62.0f, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a.x + 2.5f, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object3, Vehicle, 0, a.x + 2.5f, a.y, a.z + 1.16f, b.x + 62.0f, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object4, Vehicle, 0, a.x + 0.5f, a.y + 0.5f, a.z + 2.27f, b.x + 50.0f, b.y - 70.0f, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object5, Vehicle, 0, a.x + 1.95f, a.y + 0.5f, a.z + 2.27f, b.x + 50.0f, b.y + 70.0f, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object6, Vehicle, 0, a.x + 1.24f, a.y + 0.8f, a.z + 5.0f, b.x + 90.0f, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object7, Vehicle, 0, a.x + 1.24f, a.y + 0.8f, a.z + 3.5f, b.x + 90.0f, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object8, Vehicle, 0, a.x + 1.24f, a.y + 0.8f, a.z + 6.0f, b.x - 15.0f, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object9, Vehicle, 0, a.x + 2.0f, a.y + 0.8f, a.z + 4.43f, b.x - 30.0f, b.y - 50.0f, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object10, Vehicle, 0, a.x + 0.6f, a.y + 0.8f, a.z + 4.43f, b.x - 30.0f, b.y + 50.0f, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a.x, a.y + 2.1f, a.z + 3.7f, b.x - 10.0f, b.y + 12.8f, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object11, Vehicle, 0, a.x + 2.8f, a.y + 1.9f, a.z + 3.7f, b.x - 10.0f, b.y - 13.6f, b.z, 0, 1, 0, 0, 2, 1);
								}
							}
						}
					}
					if (Menu::Option("Flying UFO")) {
						int Handle = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = -0.27, a.y = -0.24, a.z = 0.13f;
						Vector3 b; b.x = 0, b.y = 0, b.z = 180;
						int hash = GAMEPLAY::GET_HASH_KEY("skylift");
						int hash2 = GAMEPLAY::GET_HASH_KEY("p_spinning_anus_s");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, 1, 0, 1);
							if (ENTITY::DOES_ENTITY_EXIST(Object))
							{
								int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
								if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
								{
									PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);

									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);

									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 2, 153, 57);
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 2, 153, 57);
									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 2, 153, 57);
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 2, 153, 57);

								}
							}
						}
					}
					if (Menu::Option("Bumper Buggy")) {
						uint Handle = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = -0.34, a.y = 0.32, a.z = -0.25;
						Vector3 b; b.x = 0, b.y = 0, b.z = 180;
						Vector3 Tire; Tire.x = 0.0, Tire.y = 0.0; Tire.z = 0.0;//Right Front(inner tire)
						Vector3 TireA; TireA.x = 0.40, TireA.y = 1.0, TireA.z = -0.51;//X Coord - Y Coord - Z Coord
						Vector3 TireB; TireB.x = 0.0, TireB.y = 0.0, TireB.z = 88.0;//Pitch - Roll - Yaw
						Vector3 Tire01; Tire01.x = 0.0, Tire01.y = 0.0; Tire01.z = 0;//Right Front(outter tire)
						Vector3 TireC; TireC.x = 0.59, TireC.y = 1.0, TireC.z = -0.51;//X Coord - Y Coord - Z Coord
						Vector3 TireD; TireD.x = 0.0, TireD.y = 0.0, TireD.z = -90.0;//Pitch - Roll - Yaw
						Vector3 Tire02; Tire02.x = 0.0, Tire02.y = 0.0; Tire02.z = 0.0;//Left Front(inner tire)
						Vector3 TireE; TireE.x = -1.09, TireE.y = 1.0, TireE.z = -0.50;//X Coord - Y Coord - Z Coord
						Vector3 TireF; TireF.x = 0.0, TireF.y = 0.0, TireF.z = -88.0;//Pitch - Roll - Yaw
						Vector3 Tire03; Tire03.x = 0.0, Tire03.y = 0.0; Tire03.z = 0.0;//Left Front(outter tire)
						Vector3 TireG; TireG.x = -1.264, TireG.y = 1.0, TireG.z = -0.50;//X Coord - Y Coord - Z Coord
						Vector3 TireH; TireH.x = 0.0, TireH.y = 0.0, TireH.z = 92.0;//Pitch - Roll - Yaw
						Vector3 Engine1; Engine1.x = 0.0, Engine1.y = 0.0; Engine1.z = 0.0;//Engine
						Vector3 EngineA; EngineA.x = -0.39, EngineA.y = -1.60, EngineA.z = -0.70;//X Coord - Y Coord - Z Coord
						Vector3 EngineB; EngineB.x = 0.0, EngineB.y = 0.0, EngineB.z = 0.0;//Pitch - Roll - Yaw
						Vector3 Tire04; Tire04.x = 0.0, Tire04.y = 0.0; Tire04.z = 0.0;//Right Rear(inner tire)
						Vector3 TireI; TireI.x = 0.22, TireI.y = -1.40, TireI.z = -0.50;//X Coord - Y Coord - Z Coord
						Vector3 TireJ; TireJ.x = 0.0, TireJ.y = 0.0, TireJ.z = -88.0;//Pitch - Roll - Yaw
						Vector3 Tire05; Tire05.x = 0.0, Tire05.y = 0.0; Tire05.z = 0.0;//Right Rear(middle tire)
						Vector3 TireK; TireK.x = 0.42, TireK.y = -1.40, TireK.z = -0.50;//X Coord - Y Coord - Z Coord
						Vector3 TireL; TireL.x = 0.0, TireL.y = 0.0, TireL.z = 90.0;//Pitch - Roll - Yaw
						Vector3 Tire06; Tire06.x = 0.0, Tire06.y = 0.0; Tire06.z = 0.0;//Right Rear(outter tire)
						Vector3 TireM; TireM.x = 0.593, TireM.y = -1.40, TireM.z = -0.50;//X Coord - Y Coord - Z Coord
						Vector3 TireN; TireN.x = 0.0, TireN.y = 0.0, TireN.z = -89.0;//Pitch - Roll - Yaw
						Vector3 Tire07; Tire07.x = 0.0, Tire07.y = 0.0; Tire07.z = 0.0;//Left Rear(inner tire)
						Vector3 TireO; TireO.x = -0.81, TireO.y = -1.40, TireO.z = -0.50;//X Coord - Y Coord - Z Coord
						Vector3 TireP; TireP.x = 0.0, TireP.y = 0.0, TireP.z = 88.0;//Pitch - Roll - Yaw
						Vector3 Tire08; Tire08.x = 0.0, Tire08.y = 0.0; Tire08.z = 0.0;//Left Rear(middle tire)
						Vector3 TireQ; TireQ.x = -1.01, TireQ.y = -1.40, TireQ.z = -0.50;//X Coord - Y Coord - Z Coord
						Vector3 TireR; TireR.x = 0.0, TireR.y = 0.0, TireR.z = -91.0;//Pitch - Roll - Yaw
						Vector3 Tire09; Tire09.x = 0.0, Tire09.y = 0.0; Tire09.z = 0.0;//Left Rear(outter tire)
						Vector3 TireSs; TireSs.x = -1.184, TireSs.y = -1.40, TireSs.z = -0.50;//X Coord - Y Coord - Z Coord
						Vector3 TireT; TireT.x = 0.0, TireT.y = 0.0, TireT.z = 88.0;//Pitch - Roll - Yaw
						Vector3 Hood1; Hood1.x = 0, Hood1.y = 0; Hood1.z = 0;//Hood
						Vector3 HoodA; HoodA.x = -0.34, HoodA.y = 1.2, HoodA.z = -0.40;//X Coord - Y Coord - Z Coord
						Vector3 HoodB; HoodB.x = -24.0, HoodB.y = 0.0, HoodB.z = 0.0;//Pitch - Roll - Yaw
						Vector3 Battery1; Battery1.x = 0.0, Battery1.y = 0.0; Battery1.z = 0.0;//Battery
						Vector3 BatteryA; BatteryA.x = -0.34, BatteryA.y = 1.06, BatteryA.z = -0.06;//X Coord - Y Coord - Z Coord
						Vector3 BatteryB; BatteryB.x = -24.0, BatteryB.y = 0.0, BatteryB.z = 0.0;//Pitch - Roll - Yaw
						int hash = GAMEPLAY::GET_HASH_KEY("blista");
						int hash2 = GAMEPLAY::GET_HASH_KEY("prop_bumper_car_01");
						int Tires = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");
						int Engine = GAMEPLAY::GET_HASH_KEY("prop_car_engine_01");
						int Hood = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");
						int Battery = GAMEPLAY::GET_HASH_KEY("prop_power_cell");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						STREAMING::REQUEST_MODEL(Tires);
						STREAMING::REQUEST_MODEL(Engine);
						STREAMING::REQUEST_MODEL(Hood);
						STREAMING::REQUEST_MODEL(Battery);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(Tires) && STREAMING::HAS_MODEL_LOADED(Engine) && STREAMING::HAS_MODEL_LOADED(Hood) && STREAMING::HAS_MODEL_LOADED(Battery))
						{
							int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, 1, 0, 1);
							int Tire1 = OBJECT::CREATE_OBJECT(Tires, Tire.x, Tire.y, Tire.z, 1, 0, 1);//Right Front(inner tire)
							int Tire2 = OBJECT::CREATE_OBJECT(Tires, Tire01.x, Tire01.y, Tire01.z, 1, 0, 1);//right Front(outter tire)
							int Tire3 = OBJECT::CREATE_OBJECT(Tires, Tire02.x, Tire02.y, Tire02.z, 1, 0, 1);//Left Front(inner tire)
							int Tire4 = OBJECT::CREATE_OBJECT(Tires, Tire03.x, Tire03.y, Tire03.z, 1, 0, 1);//Left Front(outter tire)
							int Engine01 = OBJECT::CREATE_OBJECT(Engine, Engine1.x, Engine1.y, Engine1.z, 1, 0, 1);//Engine
							int Tire5 = OBJECT::CREATE_OBJECT(Tires, Tire04.x, Tire04.y, Tire04.z, 1, 0, 1);//Right Rear(inner tire)
							int Tire6 = OBJECT::CREATE_OBJECT(Tires, Tire05.x, Tire05.y, Tire05.z, 1, 0, 1);//Right Rear(middle tire)
							int Tire7 = OBJECT::CREATE_OBJECT(Tires, Tire06.x, Tire06.y, Tire06.z, 1, 0, 1);//Right Rear(outter tire)
							int Tire8 = OBJECT::CREATE_OBJECT(Tires, Tire07.x, Tire07.y, Tire07.z, 1, 0, 1);//Left Rear(inner tire)
							int Tire9 = OBJECT::CREATE_OBJECT(Tires, Tire08.x, Tire08.y, Tire08.z, 1, 0, 1);//Left Rear(middle tire)
							int Tire10 = OBJECT::CREATE_OBJECT(Tires, Tire09.x, Tire09.y, Tire09.z, 1, 0, 1);//Left Rear(outter tire)
							int Hood01 = OBJECT::CREATE_OBJECT(Hood, Hood1.x, Hood1.y, Hood1.z, 1, 0, 1);//Hood
							int Battery01 = OBJECT::CREATE_OBJECT(Battery, Battery1.x, Battery1.y, Battery1.z, 1, 0, 1);//Battery
							if (ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Tire1) && ENTITY::DOES_ENTITY_EXIST(Tire2) && ENTITY::DOES_ENTITY_EXIST(Tire3) && ENTITY::DOES_ENTITY_EXIST(Tire4) && ENTITY::DOES_ENTITY_EXIST(Engine01) && ENTITY::DOES_ENTITY_EXIST(Tire5) && ENTITY::DOES_ENTITY_EXIST(Tire6) && ENTITY::DOES_ENTITY_EXIST(Tire7) && ENTITY::DOES_ENTITY_EXIST(Tire8) && ENTITY::DOES_ENTITY_EXIST(Tire9) && ENTITY::DOES_ENTITY_EXIST(Tire10) && ENTITY::DOES_ENTITY_EXIST(Hood01) && ENTITY::DOES_ENTITY_EXIST(Battery01))
							{
								int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
								if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
								{
									PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
									STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
									ENTITY::SET_ENTITY_VISIBLE(Vehicle, false, true);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire1, Vehicle, 0, TireA.x, TireA.y, TireA.z, TireB.x, TireB.y, TireB.z, 0, 1, 0, 0, 2, 1);//Right Front(inner tire)
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire2, Vehicle, 0, TireC.x, TireC.y, TireC.z, TireD.x, TireD.y, TireD.z, 0, 1, 0, 0, 2, 1);//right Front(outter tire)
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire3, Vehicle, 0, TireE.x, TireE.y, TireE.z, TireF.x, TireF.y, TireF.z, 0, 1, 0, 0, 2, 1);//Left Front(inner tire)
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire4, Vehicle, 0, TireG.x, TireG.y, TireG.z, TireH.x, TireH.y, TireH.z, 0, 1, 0, 0, 2, 1);//Left Front(outter tire)
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Engine01, Vehicle, 0, EngineA.x, EngineA.y, EngineA.z, EngineB.x, EngineB.y, EngineB.z, 0, 1, 0, 0, 2, 1);//Engine
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire5, Vehicle, 0, TireI.x, TireI.y, TireI.z, TireJ.x, TireJ.y, TireJ.z, 0, 1, 0, 0, 2, 1);//Right Rear(inner tire)
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire6, Vehicle, 0, TireK.x, TireK.y, TireK.z, TireL.x, TireL.y, TireL.z, 0, 1, 0, 0, 2, 1);//Right Rear(middle tire)
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire7, Vehicle, 0, TireM.x, TireM.y, TireM.z, TireN.x, TireN.y, TireN.z, 0, 1, 0, 0, 2, 1);//Right Rear(outter tire)
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire8, Vehicle, 0, TireO.x, TireO.y, TireO.z, TireP.x, TireP.y, TireP.z, 0, 1, 0, 0, 2, 1);//Left Rear(inner tire)
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire9, Vehicle, 0, TireQ.x, TireQ.y, TireQ.z, TireR.x, TireR.y, TireR.z, 0, 1, 0, 0, 2, 1);//Left Rear(middle tire)
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire10, Vehicle, 0, TireSs.x, TireSs.y, TireSs.z, TireT.x, TireT.y, TireT.z, 0, 1, 0, 0, 2, 1);//Left Rear(outter tire)
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Hood01, Vehicle, 0, HoodA.x, HoodA.y, HoodA.z, HoodB.x, HoodB.y, HoodB.z, 0, 1, 0, 0, 2, 1);//Hood
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Battery01, Vehicle, 0, BatteryA.x, BatteryA.y, BatteryA.z, BatteryB.x, BatteryB.y, BatteryB.z, 0, 1, 0, 0, 2, 1);//Battery
									ENTITY::SET_ENTITY_VISIBLE(Handle, true, true);

								}

							}

						}

					}
					if (Menu::Option("Modded Carbon RS")) {
						uint Handle = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						//hash2_EMP
						Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
						Vector3 a; a.x = 0.0, a.y = 1.61, a.z = -0.12;//X Coord - Y Coord - Z Coord
						Vector3 b; b.x = -12.0, b.y = 0.0, b.z = 0.0;//Pitch - Roll - Yaw
																	 //hash3_MiniGun
						Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
						Vector3 a1; a1.x = -0.60, a1.y = 1.60, a1.z = 0.20;
						Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 88.0;
						//hash3_MiniGun2
						Vector3 null0; null0.x = 0.0, null0.y = 0.0; null0.z = 0.0;
						Vector3 a0; a0.x = 0.60, a0.y = 1.60, a0.z = 0.20;
						Vector3 b0; b0.x = 0.0, b0.y = 0.0, b0.z = 88.0;
						//hash4_FLWheel1
						Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
						Vector3 a2; a2.x = -0.94, a2.y = 1.32, a2.z = -0.25;
						Vector3 b2; b2.x = 9.0, b2.y = -28.0, b2.z = 87.0;
						//hash4_RLWheel1
						Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
						Vector3 a3; a3.x = -0.95, a3.y = -1.34, a3.z = -0.25f;
						Vector3 b3; b3.x = 9.0, b3.y = 38.0, b3.z = 87.0;
						//hash4_RFWheel1
						Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
						Vector3 a4; a4.x = 0.95, a4.y = 1.33, a4.z = -0.23;
						Vector3 b4; b4.x = 11.0, b4.y = 26.0, b4.z = -89.0;
						//hash4_RRWheel1
						Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
						Vector3 a5; a5.x = 0.96, a5.y = -1.31, a5.z = -0.23;
						Vector3 b5; b5.x = 10.0, b5.y = 20.0, b5.z = -92.0;

						int hash_T20 = GAMEPLAY::GET_HASH_KEY("t20");
						int hash2_EMP = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");
						int hash3_MiniGun = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
						int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");

						STREAMING::REQUEST_MODEL(hash_T20);
						STREAMING::REQUEST_MODEL(hash2_EMP);
						STREAMING::REQUEST_MODEL(hash3_MiniGun);
						STREAMING::REQUEST_MODEL(hash4_Wheel);

						if (STREAMING::HAS_MODEL_LOADED(hash_T20) && STREAMING::HAS_MODEL_LOADED(hash2_EMP) && STREAMING::HAS_MODEL_LOADED(hash3_MiniGun) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel))
						{
							int EMP = OBJECT::CREATE_OBJECT(hash2_EMP, null.x, null.y, null.z, 1, 0, 1);
							int MiniGun = OBJECT::CREATE_OBJECT(hash3_MiniGun, null1.x, null1.y, null1.z, 1, 0, 1);
							int MiniGun2 = OBJECT::CREATE_OBJECT(hash3_MiniGun, null0.x, null0.y, null0.z, 1, 0, 1);
							int FLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null2.x, null2.y, null2.z, 1, 0, 1);
							int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null3.x, null3.y, null3.z, 1, 0, 1);
							int RFWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null4.x, null4.y, null4.z, 1, 0, 1);
							int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);

							if (ENTITY::DOES_ENTITY_EXIST(EMP) && ENTITY::DOES_ENTITY_EXIST(MiniGun) && ENTITY::DOES_ENTITY_EXIST(MiniGun2) && ENTITY::DOES_ENTITY_EXIST(FLWheel1) && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(RFWheel1) && ENTITY::DOES_ENTITY_EXIST(RRWheel1))
							{
								int Vehicle = VEHICLE::erstelle_fahr(hash_T20, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

								if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
								{
									PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
									STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_T20);
									ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
									ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, true);

									ENTITY::ATTACH_ENTITY_TO_ENTITY(EMP, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun2, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(FLWheel1, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RFWheel1, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);

								}

							}

						}

					}
					if (Menu::Option("Modded T20")) {
						uint Handle = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						//hash2_EMP
						Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
						Vector3 a; a.x = 0.0, a.y = 1.61, a.z = -0.12;//X Coord - Y Coord - Z Coord
						Vector3 b; b.x = -12.0, b.y = 0.0, b.z = 0.0;//Pitch - Roll - Yaw
																	 //hash3_MiniGun
						Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
						Vector3 a1; a1.x = -0.60, a1.y = 1.60, a1.z = 0.20;
						Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 88.0;
						//hash3_MiniGun2
						Vector3 null0; null0.x = 0.0, null0.y = 0.0; null0.z = 0.0;
						Vector3 a0; a0.x = 0.60, a0.y = 1.60, a0.z = 0.20;
						Vector3 b0; b0.x = 0.0, b0.y = 0.0, b0.z = 88.0;
						//hash4_FLWheel1
						Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
						Vector3 a2; a2.x = -0.94, a2.y = 1.32, a2.z = -0.25;
						Vector3 b2; b2.x = 9.0, b2.y = -28.0, b2.z = 87.0;
						//hash4_RLWheel1
						Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
						Vector3 a3; a3.x = -0.95, a3.y = -1.34, a3.z = -0.25f;
						Vector3 b3; b3.x = 9.0, b3.y = 38.0, b3.z = 87.0;
						//hash4_RFWheel1
						Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
						Vector3 a4; a4.x = 0.95, a4.y = 1.33, a4.z = -0.23;
						Vector3 b4; b4.x = 11.0, b4.y = 26.0, b4.z = -89.0;
						//hash4_RRWheel1
						Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
						Vector3 a5; a5.x = 0.96, a5.y = -1.31, a5.z = -0.23;
						Vector3 b5; b5.x = 10.0, b5.y = 20.0, b5.z = -92.0;

						int hash_T20 = GAMEPLAY::GET_HASH_KEY("t20");
						int hash2_EMP = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");
						int hash3_MiniGun = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
						int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");

						STREAMING::REQUEST_MODEL(hash_T20);
						STREAMING::REQUEST_MODEL(hash2_EMP);
						STREAMING::REQUEST_MODEL(hash3_MiniGun);
						STREAMING::REQUEST_MODEL(hash4_Wheel);

						if (STREAMING::HAS_MODEL_LOADED(hash_T20) && STREAMING::HAS_MODEL_LOADED(hash2_EMP) && STREAMING::HAS_MODEL_LOADED(hash3_MiniGun) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel))
						{
							int EMP = OBJECT::CREATE_OBJECT(hash2_EMP, null.x, null.y, null.z, 1, 0, 1);
							int MiniGun = OBJECT::CREATE_OBJECT(hash3_MiniGun, null1.x, null1.y, null1.z, 1, 0, 1);
							int MiniGun2 = OBJECT::CREATE_OBJECT(hash3_MiniGun, null0.x, null0.y, null0.z, 1, 0, 1);
							int FLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null2.x, null2.y, null2.z, 1, 0, 1);
							int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null3.x, null3.y, null3.z, 1, 0, 1);
							int RFWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null4.x, null4.y, null4.z, 1, 0, 1);
							int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);

							if (ENTITY::DOES_ENTITY_EXIST(EMP) && ENTITY::DOES_ENTITY_EXIST(MiniGun) && ENTITY::DOES_ENTITY_EXIST(MiniGun2) && ENTITY::DOES_ENTITY_EXIST(FLWheel1) && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(RFWheel1) && ENTITY::DOES_ENTITY_EXIST(RRWheel1))
							{
								int Vehicle = VEHICLE::erstelle_fahr(hash_T20, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

								if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
								{
									PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
									STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_T20);
									ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
									ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, true);

									ENTITY::ATTACH_ENTITY_TO_ENTITY(EMP, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun2, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(FLWheel1, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RFWheel1, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);

								}

							}

						}

					}
					if (Menu::Option("Roller Coaster Car")) {
						uint Handle = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						//hash2_RollerCar
						Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
						Vector3 a; a.x = 0.0, a.y = 0.0, a.z = -0.5;//X Coord - Y Coord - Z Coord
						Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 180.0;//Pitch - Roll - Yaw
																	 //hash3_Seats
						Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
						Vector3 a1; a1.x = 0.0, a1.y = 0.0, a1.z = 0.0;
						Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 0.0;
						//hash3_FLWheel1
						Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
						Vector3 a2; a2.x = -0.97, a2.y = 1.0, a2.z = -0.25;
						Vector3 b2; b2.x = 0.0, b2.y = 0.0, b2.z = -89.0;
						//hash3_RLWheel1
						Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
						Vector3 a3; a3.x = -1.00, a3.y = -1.10, a3.z = -0.24;
						Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = -89.0;
						//hash3_RFWheel1
						Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
						Vector3 a4; a4.x = 0.97, a4.y = 1.00, a4.z = -0.24;
						Vector3 b4; b4.x = 0.0, b4.y = 0.0, b4.z = 89.0;
						//hash3_RRWheel1
						Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
						Vector3 a5; a5.x = 1.00, a5.y = -1.10, a5.z = -0.24;
						Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = 89.0;
						int hash_T20 = GAMEPLAY::GET_HASH_KEY("t20");
						int hash2_RollerCar = GAMEPLAY::GET_HASH_KEY("ind_prop_dlc_roller_car");
						int hash3_Seats = GAMEPLAY::GET_HASH_KEY("prop_hd_seats_01");
						int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");
						STREAMING::REQUEST_MODEL(hash_T20);
						STREAMING::REQUEST_MODEL(hash2_RollerCar);
						STREAMING::REQUEST_MODEL(hash3_Seats);
						STREAMING::REQUEST_MODEL(hash4_Wheel);
						if (STREAMING::HAS_MODEL_LOADED(hash_T20) && STREAMING::HAS_MODEL_LOADED(hash2_RollerCar) && STREAMING::HAS_MODEL_LOADED(hash3_Seats) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel))
						{
							int RollerCar = OBJECT::CREATE_OBJECT(hash2_RollerCar, null.x, null.y, null.z, 1, 0, 1);
							int Seats = OBJECT::CREATE_OBJECT(hash3_Seats, null1.x, null1.y, null1.z, 1, 0, 1);
							int FLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null2.x, null2.y, null2.z, 1, 0, 1);
							int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null3.x, null3.y, null3.z, 1, 0, 1);
							int RFWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null4.x, null4.y, null4.z, 1, 0, 1);
							int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);
							if (ENTITY::DOES_ENTITY_EXIST(RollerCar) && ENTITY::DOES_ENTITY_EXIST(Seats) && ENTITY::DOES_ENTITY_EXIST(FLWheel1) && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(RFWheel1) && ENTITY::DOES_ENTITY_EXIST(RRWheel1))
							{
								int Vehicle = VEHICLE::erstelle_fahr(hash_T20, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
								if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
								{
									PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
									STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_T20);
									ENTITY::SET_ENTITY_VISIBLE(Vehicle, false, true);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RollerCar, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Seats, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(FLWheel1, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RFWheel1, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
									ENTITY::SET_ENTITY_VISIBLE(Handle, true, true);

								}

							}

						}

					}
					if (Menu::Option("Boat And Trailer")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = -0.61, a.z = 0.28;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("boattrailer");
						int hash2 = GAMEPLAY::GET_HASH_KEY("suntrap");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
							{
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
								ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);

							}

						}

					}
					if (Menu::Option("FlatBed And T20")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = -2.0, a.z = 1.1;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						Vector3 null1; null1.x = 0, null1.y = 0; null1.z = 0;
						Vector3 a1; a1.x = -1.06, a1.y = -0.1, a1.z = 0.46;
						Vector3 b1; b1.x = 91.0, b1.y = 0, b1.z = 0;
						Vector3 null2; null2.x = 0, null2.y = 0; null2.z = 0;
						Vector3 a2; a2.x = -0.9, a2.y = 0.61, a2.z = 0.62;
						Vector3 b2; b2.x = 0.0, b2.y = 100.0, b2.z = 0;
						Vector3 null3; null3.x = 0, null3.y = 0; null3.z = 0;
						Vector3 a3; a3.x = 0.9, a3.y = 0.8, a3.z = 0.41;
						Vector3 b3; b3.x = -25.0, b3.y = 0, b3.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("flatbed");
						int hash2 = GAMEPLAY::GET_HASH_KEY("t20");
						int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_broom");
						int hash4 = GAMEPLAY::GET_HASH_KEY("prop_roadcone01a");
						int hash5 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_02");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						STREAMING::REQUEST_MODEL(hash3);
						STREAMING::REQUEST_MODEL(hash4);
						STREAMING::REQUEST_MODEL(hash5);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Broom = OBJECT::CREATE_OBJECT(hash3, null1.x, null1.y, null1.z, 1, 0, 1);
							int Cone = OBJECT::CREATE_OBJECT(hash4, null2.x, null2.y, null2.z, 1, 0, 1);
							int Tool = OBJECT::CREATE_OBJECT(hash5, null3.x, null3.y, null3.z, 1, 0, 1);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Broom) && ENTITY::DOES_ENTITY_EXIST(Cone) && ENTITY::DOES_ENTITY_EXIST(Tool))
							{
								PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
								VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
								VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "Solitary");
								VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Broom, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Cone, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Tool, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, false, 0, 0, 2, true);
								ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);

							}

						}

					}
					if (Menu::Option("JetSki And Trailer")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0.;
						Vector3 a; a.x = -0.625, a.y = -1.9, a.z = -0.09;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						Vector3 a1; a1.x = 0.625, a1.y = -1.9, a1.z = -0.09;
						Vector3 b1; b1.x = 0, b1.y = 0, b1.z = 0;

						Vector3 a2; a2.x = 0.0, a2.y = 0.9, a2.z = -0.45;
						Vector3 b2; b2.x = 0, b2.y = 0, b2.z = 180.0;

						int hash = GAMEPLAY::GET_HASH_KEY("boattrailer");
						int hash2 = GAMEPLAY::GET_HASH_KEY("seashark");
						int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_05");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						STREAMING::REQUEST_MODEL(hash3);

						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object1 = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object2 = OBJECT::CREATE_OBJECT(hash3, null.x, null.y, null.z, 1, 0, 1);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Object1) && ENTITY::DOES_ENTITY_EXIST(Object2))
							{
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
								ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);
								ENTITY::SET_ENTITY_COLLISION(Object1, 1, 0);

							}

						}

					}
					if (Menu::Option("Ramp Truck")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 10.0, a.z = -0.3;
						Vector3 b; b.x = 0, b.y = -147.0, b.z = 90.0;
						int hash = GAMEPLAY::GET_HASH_KEY("phantom");
						int hash2 = GAMEPLAY::GET_HASH_KEY("prop_lev_des_barge_01");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
							{
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
								ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);

							}

						}

					}
					if (Menu::Option("Monster Swat")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 0, a.z = 0;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("monster");
						int hash2 = GAMEPLAY::GET_HASH_KEY("riot");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
							{
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
								VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

							}

						}

					}
					if (Menu::Option("Buffulo Police")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 0, a.z = 0;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("police2");
						int hash2 = GAMEPLAY::GET_HASH_KEY("buffalo2");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
							{
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
								VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
								VEHICLE::SET_VEHICLE_WINDOW_TINT(Vehicle, 5);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
								VEHICLE::SET_VEHICLE_EXTRA_COLOURS(Object, 0, 0);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

							}

						}

					}
					if (Menu::Option("Insurgent 3")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 0, a.z = 0;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("insurgent");
						int hash2 = GAMEPLAY::GET_HASH_KEY("insurgent2");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
							{
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
								VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

							}

						}

					}
					if (Menu::Option("Super 1")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 0, a.z = -0.25;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("t20");
						int hash2 = GAMEPLAY::GET_HASH_KEY("cheetah");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
							{
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
								VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

							}

						}

					}
					if (Menu::Option("Super 2")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 0, a.z = 0;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("feltzer2");
						int hash2 = GAMEPLAY::GET_HASH_KEY("rapidgt");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
							{
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
								VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

							}

						}

					}
					if (Menu::Option("Muscle 1")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 0, a.z = -0.2;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("hotknife");
						int hash2 = GAMEPLAY::GET_HASH_KEY("jb700");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
							{
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
								VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

							}

						}

					}
					if (Menu::Option("Muscle 2")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 0, a.z = 2.0;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("coquette2");
						int hash2 = GAMEPLAY::GET_HASH_KEY("hotknife");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
							{
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
								VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

							}

						}

					}
					if (Menu::Option("Special")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 0, a.z = 0;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("zentorno");
						int hash2 = GAMEPLAY::GET_HASH_KEY("kuruma2");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
							{
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
								VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "Solitary");
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

							}

						}

					}
					if (Menu::Option("Sub Copter")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 1, a.z = 0.8;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("buzzard");
						int hash2 = GAMEPLAY::GET_HASH_KEY("submersible");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
							{
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
								VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 255, 149, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

							}

						}

					}
					if (Menu::Option("SlamVan")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = -2.0, a.z = 1.1;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						Vector3 null1; null1.x = 0, null1.y = 0; null1.z = 0;
						Vector3 a1; a1.x = -1.06, a1.y = -0.1, a1.z = 0.46;
						Vector3 b1; b1.x = 91.0, b1.y = 0, b1.z = 0;
						Vector3 null2; null2.x = 0, null2.y = 0; null2.z = 0;
						Vector3 a2; a2.x = -0.9, a2.y = 0.61, a2.z = 0.62;
						Vector3 b2; b2.x = 0.0, b2.y = 100.0, b2.z = 0;
						Vector3 null3; null3.x = 0, null3.y = 0; null3.z = 0;
						Vector3 a3; a3.x = 0.9, a3.y = 0.8, a3.z = 0.41;
						Vector3 b3; b3.x = -25.0, b3.y = 0, b3.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("flatbed");
						int hash2 = GAMEPLAY::GET_HASH_KEY("slamvan2");
						int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_broom");
						int hash4 = GAMEPLAY::GET_HASH_KEY("prop_roadcone01a");
						int hash5 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_02");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						STREAMING::REQUEST_MODEL(hash3);
						STREAMING::REQUEST_MODEL(hash4);
						STREAMING::REQUEST_MODEL(hash5);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Broom = OBJECT::CREATE_OBJECT(hash3, null1.x, null1.y, null1.z, 1, 0, 1);
							int Cone = OBJECT::CREATE_OBJECT(hash4, null2.x, null2.y, null2.z, 1, 0, 1);
							int Tool = OBJECT::CREATE_OBJECT(hash5, null3.x, null3.y, null3.z, 1, 0, 1);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Broom) && ENTITY::DOES_ENTITY_EXIST(Cone) && ENTITY::DOES_ENTITY_EXIST(Tool))
							{
								PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
								VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 8, 17, 30);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 30, 1);
								VEHICLE::SET_VEHICLE_EXTRA_COLOURS(Object, 92, 0);
								VEHICLE::SET_VEHICLE_COLOURS(Object, 12, 53);
								VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, " Solitary");
								VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Object, 1);
								VEHICLE::TOGGLE_VEHICLE_MOD(Object, 18, 1);
								VEHICLE::TOGGLE_VEHICLE_MOD(Object, 22, 1);
								VEHICLE::SET_VEHICLE_MOD(Object, 11, 3, 0);
								VEHICLE::SET_VEHICLE_MOD(Object, 14, 14, 0);
								VEHICLE::SET_VEHICLE_MOD(Object, 15, 3, 0);
								VEHICLE::SET_VEHICLE_MOD(Object, 13, 2, 0);
								VEHICLE::SET_VEHICLE_WHEEL_TYPE(Object, 6);
								VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
								VEHICLE::SET_VEHICLE_MOD(Object, 23, 18, 1);
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Broom, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Cone, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Tool, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, false, 0, 0, 2, true);

							}

						}

					}
					if (Menu::Option("Flying 5 Seater")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0.;

						Vector3 a; a.x = 0.0, a.y = 0.0, a.z = 0.6;		// seashark 1 - 0.7 worked just hard to get on .. infront and behind wings only way to get on the sharks ...
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;

						Vector3 a1; a1.x = 0.0, a1.y = -4.0, a1.z = 0.6;  // seashark 2
						Vector3 b1; b1.x = 0, b1.y = 0, b1.z = 0;


						Vector3 a2; a2.x = 0.0, a2.y = 0.9, a2.z = -0.45;
						Vector3 b2; b2.x = 0, b2.y = 0, b2.z = 180.0;

						int hash = GAMEPLAY::GET_HASH_KEY("hydra");
						int hash2 = GAMEPLAY::GET_HASH_KEY("seashark");
						int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_05"); // turn this into something usefull maybe another sea shark ...
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						STREAMING::REQUEST_MODEL(hash3);

						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object1 = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object2 = OBJECT::CREATE_OBJECT(hash3, null.x, null.y, null.z, 1, 0, 1);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Object1) && ENTITY::DOES_ENTITY_EXIST(Object2))
							{
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
								ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);
								ENTITY::SET_ENTITY_COLLISION(Object1, 1, 0);

							}

						}

					}
					if (Menu::Option("Panto/HotKnife")) {
						uint Handle = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						//hash2_PANTO
						Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
						Vector3 a; a.x = 0.0, a.y = 0.0, a.z = -0.2;//X Coord - Y Coord - Z Coord
						Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 0.0;//Pitch - Roll - Yaw
																   //hash3_MiniGun
						Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
						Vector3 a1; a1.x = -0.60, a1.y = 1.60, a1.z = 0.20;
						Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 88.0;
						//hash3_MiniGun2
						Vector3 null0; null0.x = 0.0, null0.y = 0.0; null0.z = 0.0;
						Vector3 a0; a0.x = 0.60, a0.y = 1.60, a0.z = 0.20;
						Vector3 b0; b0.x = 0.0, b0.y = 0.0, b0.z = 88.0;
						//hash4_WindScreen _ VANISHED NEEDS FIXING
						Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
						Vector3 a2; a2.x = 0.3, a2.y = 0.41, a2.z = 0.50;
						Vector3 b2; b2.x = -45.3, b2.y = 0.0, b2.z = -179.0;//87
																			//hash4_RLWheel1
						Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
						Vector3 a3; a3.x = -0.90, a3.y = -1.2, a3.z = 0.0; // -0.23
						Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = 86.0;
						//hash4_RFWindScreen 
						Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
						Vector3 a4; a4.x = -0.3, a4.y = 0.41, a4.z = 0.5;
						Vector3 b4; b4.x = -45.3, b4.y = 0.0, b4.z = -179.0;
						//hash4_RRWheel1
						Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
						Vector3 a5; a5.x = 0.92, a5.y = -1.2, a5.z = 0.01;
						Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = -92.0;
						//PUNTO -- FUCK UP NEEDS FIXING 
						Vector3 null6; null6.x = 0, null6.y = 0; null6.z = 0;
						Vector3 a6; a6.x = 0.0, a6.y = 0.0, a6.z = -0.2;
						Vector3 b6; b6.x = 0.0, b6.y = 0.0, b6.z = 0.0;
						//SIDES LEFT
						Vector3 null7; null7.x = 0, null7.y = 0; null7.z = 0;
						Vector3 a7; a7.x = -0.75, a7.y = 0.7, a7.z = -0.3;
						Vector3 b7; b7.x = 90.0, b7.y = 0.0, b7.z = 0.0;
						//SIDES RIGHT
						Vector3 null8; null8.x = 0, null8.y = 0; null8.z = 0;
						Vector3 a8; a8.x = 0.75, a8.y = 0.7, a8.z = -0.3;
						Vector3 b8; b8.x = 90.0, b8.y = 0.0, b8.z = 0.0;

						int hash = GAMEPLAY::GET_HASH_KEY("hotknife");
						int hash2_EMP = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");
						int hash3_MiniGun = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
						int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");
						int hash2 = GAMEPLAY::GET_HASH_KEY("panto");
						int hashWindow = GAMEPLAY::GET_HASH_KEY("prop_ballistic_shield");
						int hashSides = GAMEPLAY::GET_HASH_KEY("prop_cons_plank");




						STREAMING::REQUEST_MODEL(hashWindow);// WINDOW
						STREAMING::REQUEST_MODEL(hash2_EMP); // PANTO
						STREAMING::REQUEST_MODEL(hash3_MiniGun); // GUNS
						STREAMING::REQUEST_MODEL(hash4_Wheel); // back wheels
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						STREAMING::REQUEST_MODEL(hashSides); // SIDE SKIRTS

						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hashSides) && STREAMING::HAS_MODEL_LOADED(hashWindow) && STREAMING::HAS_MODEL_LOADED(hash2_EMP) && STREAMING::HAS_MODEL_LOADED(hash3_MiniGun) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel))
						{
							int EMP = OBJECT::CREATE_OBJECT(hash2_EMP, null.x, null.y, null.z, 1, 0, 1);
							int MiniGun = OBJECT::CREATE_OBJECT(hash3_MiniGun, null1.x, null1.y, null1.z, 1, 0, 1);
							int MiniGun2 = OBJECT::CREATE_OBJECT(hash3_MiniGun, null0.x, null0.y, null0.z, 1, 0, 1);
							int WINDOW_1 = OBJECT::CREATE_OBJECT(hashWindow, null2.x, null2.y, null2.z, 1, 0, 1);
							int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null3.x, null3.y, null3.z, 1, 0, 1);
							int WINDOW_2 = OBJECT::CREATE_OBJECT(hashWindow, null4.x, null4.y, null4.z, 1, 0, 1);
							int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int LeftSide = OBJECT::CREATE_OBJECT(hashSides, null7.x, null7.y, null7.z, 1, 0, 1);
							int RightSide = OBJECT::CREATE_OBJECT(hashSides, null8.x, null8.y, null8.z, 1, 0, 1);


							if (ENTITY::DOES_ENTITY_EXIST(EMP) && ENTITY::DOES_ENTITY_EXIST(LeftSide) && ENTITY::DOES_ENTITY_EXIST(RightSide) && ENTITY::DOES_ENTITY_EXIST(MiniGun) && ENTITY::DOES_ENTITY_EXIST(MiniGun2) && ENTITY::DOES_ENTITY_EXIST(WINDOW_1) && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(WINDOW_2) && ENTITY::DOES_ENTITY_EXIST(RRWheel1))
							{
								int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

								if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
								{
									PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
									STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
									ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
									ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, true);
									STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
									PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
									ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
									VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
									VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
									VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Vehicle, "sm");
									VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "sm");
									VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Vehicle, 1);
									VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Object, 1);

									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(EMP, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun2, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(WINDOW_1, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(WINDOW_2, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(LeftSide, Vehicle, 0, a7.x, a7.y, a7.z, b7.x, b7.y, b7.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RightSide, Vehicle, 0, a8.x, a8.y, a8.z, b8.x, b8.y, b8.z, 0, 1, 0, 0, 2, 1);


								}

							}

						}

					}
					if (Menu::Option("Monster Digger")) {
						uint Handle = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						//hash2_Dozer
						Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
						Vector3 a; a.x = 0.0, a.y = 0.0, a.z = -0.4;   //X Coord - Y Coord - Z Coord
						Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 0.0;   //Pitch - Roll - Yaw
																	  //hash3_MiniGun LEFT
						Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
						Vector3 a1; a1.x = -0.70, a1.y = 1.80, a1.z = 0.98;
						Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 88.0;
						//hash3_MiniGun2 RIGHT
						Vector3 null0; null0.x = 0.0, null0.y = 0.0; null0.z = 0.0;
						Vector3 a0; a0.x = 0.70, a0.y = 1.80, a0.z = 0.98;
						Vector3 b0; b0.x = 0.0, b0.y = 0.0, b0.z = 88.0;
						//hash4_Left BLUE left
						Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
						Vector3 a2; a2.x = -0.31, a2.y = 2.51, a2.z = 0.55;
						Vector3 b2; b2.x = 0.0, b2.y = 0.0, b2.z = -175.0;//87 - 179
																		  //hash4_NIONS LEFT/back
						Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
						Vector3 a3; a3.x = 0.5, a3.y = -3.0, a3.z = -0.36; // -0.23
						Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = 86.0;
						//hash4_Right BLUE LIGHT
						Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
						Vector3 a4; a4.x = 0.31, a4.y = 2.51, a4.z = 0.55;
						Vector3 b4; b4.x = 0.0, b4.y = 0.0, b4.z = -175.0;
						//hash4_NIONS RIGHT
						Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
						Vector3 a5; a5.x = 0.92, a5.y = -2.0, a5.z = 0.01;
						Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = 89.0;
						//ENGINE
						Vector3 null6; null6.x = 0, null6.y = 0; null6.z = 0;
						Vector3 a6; a6.x = 0.0, a6.y = 1.76, a6.z = 0.86;
						Vector3 b6; b6.x = -0.0, b6.y = 0.0, b6.z = 0.0;
						//SIDES LEFT EMP
						Vector3 null7; null7.x = 0, null7.y = 0; null7.z = 0;
						Vector3 a7; a7.x = -0.88, a7.y = -1.8, a7.z = 1.0;
						Vector3 b7; b7.x = 0.0, b7.y = -51.9, b7.z = 0.0;
						//SIDES RIGHT EMP
						Vector3 null8; null8.x = 0, null8.y = 0; null8.z = 0;
						Vector3 a8; a8.x = 0.88, a8.y = -1.8, a8.z = 1.0;
						Vector3 b8; b8.x = 0.0, b8.y = 51.9, b8.z = 0.0;
						//BEAR
						Vector3 null9; null9.x = 0, null9.y = 0; null9.z = 0;
						Vector3 a9; a9.x = -1.0, a9.y = 2.7, a9.z = -0.4;
						Vector3 b9; b9.x = 0.0, b9.y = 0.0, b9.z = 156.5;
						//SPIKES
						Vector3 null10; null10.x = 0, null10.y = 0; null10.z = 0;
						Vector3 a10; a10.x = -0.12, a10.y = 0.59, a10.z = 1.9;
						Vector3 b10; b10.x = 0.0, b10.y = 0.0, b10.z = 0.0;

						int hash = GAMEPLAY::GET_HASH_KEY("monster");				// Monster Truck
						int hash1 = GAMEPLAY::GET_HASH_KEY("prop_car_engine_01");	// Car Engine
						int hash2 = GAMEPLAY::GET_HASH_KEY("bulldozer");			// Dozer
						int hash3 = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");		// Mini GUn 
						int hash4 = GAMEPLAY::GET_HASH_KEY("v_ilev_uvcheetah");		// Nion Lights <-- needs changing
						int hash5 = GAMEPLAY::GET_HASH_KEY("prop_air_lights_05a");	// Blue Lights	
						int hash6 = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");	// Emp Lights	
						int hash7 = GAMEPLAY::GET_HASH_KEY("prop_mem_teddy_02");	// Large Teddy	
						int hash8 = GAMEPLAY::GET_HASH_KEY("p_stinger_04");			// Stinger Spikes

						STREAMING::REQUEST_MODEL(hash); 	// MONSTER
						STREAMING::REQUEST_MODEL(hash1); 	// Car Engine
						STREAMING::REQUEST_MODEL(hash2); 	// DOZER
						STREAMING::REQUEST_MODEL(hash3); 	// GUNS
						STREAMING::REQUEST_MODEL(hash4); 	// Nion Lights
						STREAMING::REQUEST_MODEL(hash5);	// Blue Lights
						STREAMING::REQUEST_MODEL(hash6); 	// Emp Lights
						STREAMING::REQUEST_MODEL(hash7); 	// Large Teddy
						STREAMING::REQUEST_MODEL(hash8); 	// SPIKES

						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash1) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5) && STREAMING::HAS_MODEL_LOADED(hash6) && STREAMING::HAS_MODEL_LOADED(hash7) && STREAMING::HAS_MODEL_LOADED(hash8))
						{
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
							int Ebox = OBJECT::CREATE_OBJECT(hash1, null.x, null.y, null.z, 1, 0, 1);
							int GunL = OBJECT::CREATE_OBJECT(hash3, null1.x, null1.y, null1.z, 1, 0, 1);
							int GunR = OBJECT::CREATE_OBJECT(hash3, null0.x, null0.y, null0.z, 1, 0, 1);
							int LSign = OBJECT::CREATE_OBJECT(hash4, null3.x, null3.y, null3.z, 1, 0, 1);
							int RSign = OBJECT::CREATE_OBJECT(hash4, null5.x, null5.y, null5.z, 1, 0, 1);
							int LBlight = OBJECT::CREATE_OBJECT(hash5, null2.x, null2.y, null2.z, 1, 0, 1);
							int RBlight = OBJECT::CREATE_OBJECT(hash5, null4.x, null4.y, null4.z, 1, 0, 1);
							int LeftEmp = OBJECT::CREATE_OBJECT(hash6, null7.x, null7.y, null7.z, 1, 0, 1);
							int RightEmp = OBJECT::CREATE_OBJECT(hash6, null8.x, null8.y, null8.z, 1, 0, 1);
							int Teddy = OBJECT::CREATE_OBJECT(hash7, null9.x, null9.y, null9.z, 1, 0, 1);
							int Spikes = OBJECT::CREATE_OBJECT(hash8, null10.x, null10.y, null10.z, 1, 0, 1);

							if (ENTITY::DOES_ENTITY_EXIST(Ebox) && ENTITY::DOES_ENTITY_EXIST(GunL) && ENTITY::DOES_ENTITY_EXIST(GunR) && ENTITY::DOES_ENTITY_EXIST(LSign) && ENTITY::DOES_ENTITY_EXIST(RSign) && ENTITY::DOES_ENTITY_EXIST(LBlight) && ENTITY::DOES_ENTITY_EXIST(RBlight) && ENTITY::DOES_ENTITY_EXIST(LeftEmp) && ENTITY::DOES_ENTITY_EXIST(RightEmp) && ENTITY::DOES_ENTITY_EXIST(Teddy) && ENTITY::DOES_ENTITY_EXIST(Spikes))
							{
								int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

								if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
								{
									PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
									STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
									ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
									ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, true);
									VEHICLE::SET_VEHICLE_MOD_KIT(Vehicle, 5);
									VEHICLE::SET_VEHICLE_WINDOW_TINT(Vehicle, 5);
									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);

									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Ebox, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(GunL, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(GunR, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(LBlight, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RBlight, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(LSign, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RSign, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(LeftEmp, Vehicle, 0, a7.x, a7.y, a7.z, b7.x, b7.y, b7.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(RightEmp, Vehicle, 0, a8.x, a8.y, a8.z, b8.x, b8.y, b8.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Teddy, Vehicle, 0, a9.x, a9.y, a9.z, b9.x, b9.y, b9.z, 0, 1, 0, 0, 2, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Spikes, Vehicle, 0, a10.x, a10.y, a10.z, b10.x, b10.y, b10.z, 0, 1, 0, 0, 2, 1);
								}

							}

						}

					}
					if (Menu::Option("Train")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 0, a.z = 0;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("massacro2");
						int hash2 = GAMEPLAY::GET_HASH_KEY("freight");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
							{
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
								ENTITY::SET_ENTITY_VISIBLE(Object, true, true);
								VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
								VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "sm");
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

							}

						}

					}
					if (Menu::Option("Classic Car Mix")) {
						uint Me = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = 0, a.z = 0;
						Vector3 b; b.x = 0, b.y = 0, b.z = 0;
						int hash = GAMEPLAY::GET_HASH_KEY("ztype");
						int hash2 = GAMEPLAY::GET_HASH_KEY("btype");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
							{
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
								PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
								ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
								VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
								VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
								VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Vehicle, "Solitary");
								VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "Solitary");
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

							}

						}

					}
					if (Menu::Option("Cup Car")) {

					}
				}
				break;
				case visions:
				{
					Menu::Title("vision effects");
					// Menu::Subtitle("VISION");

					Menu::MenuOption("Scenarios", senas);
					Menu::MenuOption("Model Changer", modelchanger);
					Menu::MenuOption("Effects ~v~", PTFX);
					Menu::MenuOption("PTFX Man", ptfxpp);
					Menu::MenuOption("Walking Styles", Walking);
					Menu::MenuOption("Wardrobe", outfitss);
					Features::ClearVisions("Set To Default", "Set To Default");
					Features::addVisOption("Bank_HLWD", "Bank_HLWD", "Chnaged To: Bank_HLWD");
					Features::addVisOption("Barry1_Stoned", "Barry1_Stoned", "Chnaged To: Barry1_Stoned");
					Features::addVisOption("BarryFadeOut", "BarryFadeOut", "Chnaged To: BarryFadeOut");
					Features::addVisOption("baseTONEMAPPING", "baseTONEMAPPING", "Chnaged To: baseTONEMAPPING");
					Features::addVisOption("Bikers", "Bikers", "Chnaged To: Bikers");
					Features::addVisOption("BikersSPLASH", "BikersSPLASH", "Chnaged To: BikersSPLASH");
					Features::addVisOption("blackNwhite", "blackNwhite", "Chnaged To: blackNwhite");
					Features::addVisOption("BlackOut", "BlackOut", "Chnaged To: BlackOut");
					Features::addVisOption("Bloom", "Bloom", "Chnaged To: Bloom");
					Features::addVisOption("BloomLight", "BloomLight", "Chnaged To: BloomLight");
					Features::addVisOption("buildingTOP", "buildingTOP", "Chnaged To: buildingTOP");
					Features::addVisOption("BulletTimeDark", "BulletTimeDark", "Chnaged To: BulletTimeDark");
					Features::addVisOption("BulletTimeLight", "BulletTimeLight", "Chnaged To: BulletTimeLight");
					Features::addVisOption("CAMERA_BW", "CAMERA_BW", "Chnaged To: CAMERA_BW");
					Features::addVisOption("CAMERA_secuirity", "CAMERA_secuirity", "Chnaged To: CAMERA_secuirity");
					Features::addVisOption("CAMERA_secuirity_FUZZ", "CAMERA_secuirity_FUZZ", "Chnaged To: CAMERA_secuirity_FUZZ");
					Features::addVisOption("canyon_mission", "canyon_mission", "Chnaged To: canyon_mission");
					Features::addVisOption("carMOD_underpass", "carMOD_underpass", "Chnaged To: carMOD_underpass");
					Features::addVisOption("carpark", "carpark", "Chnaged To: carpark");
					Features::addVisOption("carpark_dt1_02", "carpark_dt1_02", "Chnaged To: carpark_dt1_02");
					Features::addVisOption("carpark_dt1_03", "carpark_dt1_03", "Chnaged To: carpark_dt1_03");
					Features::addVisOption("cashdepot", "cashdepot", "Chnaged To: cashdepot");
					Features::addVisOption("cashdepotEMERGENCY", "cashdepotEMERGENCY", "Chnaged To: cashdepotEMERGENCY");
					Features::addVisOption("cBank_back", "cBank_back", "Chnaged To: cBank_back");
					Features::addVisOption("cBank_front", "cBank_front", "Chnaged To: cBank_front");
					Features::addVisOption("ch2_tunnel_whitelight", "ch2_tunnel_whitelight", "Chnaged To: ch2_tunnel_whitelight");
					Features::addVisOption("CH3_06_water", "CH3_06_water", "Chnaged To: CH3_06_water");
					Features::addVisOption("CHOP", "CHOP", "Chnaged To: CHOP");
					Features::addVisOption("cinema", "cinema", "Chnaged To: cinema");
					Features::addVisOption("cinema_001", "cinema_001", "Chnaged To: cinema_001");
					Features::addVisOption("cops", "cops", "Chnaged To: cops");
					Features::addVisOption("CopsSPLASH", "CopsSPLASH", "Chnaged To: CopsSPLASH");
					Features::addVisOption("crane_cam", "crane_cam", "Chnaged To: crane_cam");
					Features::addVisOption("crane_cam_cinematic", "crane_cam_cinematic", "Chnaged To: crane_cam_cinematic");
					Features::addVisOption("CS1_railwayB_tunnel", "CS1_railwayB_tunnel", "Chnaged To: CS1_railwayB_tunnel");
					Features::addVisOption("CS3_rail_tunnel", "CS3_rail_tunnel", "Chnaged To: CS3_rail_tunnel");
					Features::addVisOption("CUSTOM_streetlight", "custreetlight", "Chnaged To: CUSTOM_streetlight");
					Features::addVisOption("damage", "damage", "Chnaged To: damage");
					Features::addVisOption("death", "death", "Chnaged To: death");
					Features::addVisOption("DEFAULT", "DEFAULT", "Chnaged To: DEFAULT");
					Features::addVisOption("DefaultColorCode", "DefaultColorCode", "Chnaged To: DefaultColorCode");
					Features::addVisOption("DONT_overide_sunpos", "DONT_overide_sunpos", "Chnaged To: DONT_overide_sunpos");
					Features::addVisOption("Dont_tazeme_bro", "Dont_tazeme_bro", "Chnaged To: Dont_tazeme_bro");
					Features::addVisOption("dont_tazeme_bro_b", "dont_tazeme_bro_b", "Chnaged To: dont_tazeme_bro_b");
					Features::addVisOption("downtown_FIB_cascades_opt", "downtown_FIB_cascades_opt", "Chnaged To: downtown_FIB_cascades_opt");
					Features::addVisOption("DrivingFocusDark", "DrivingFocusDark", "Chnaged To: DrivingFocusDark");
					Features::addVisOption("DrivingFocusLight", "DrivingFocusLight", "Chnaged To: DrivingFocusLight");
					Features::addVisOption("DRUG_2_drive", "DRUG_2_drive", "Chnaged To: DRUG_2_drive");
					Features::addVisOption("Drug_deadman", "Drug_deadman", "Chnaged To: Drug_deadman");
					Features::addVisOption("Drug_deadman_blend", "Drug_deadman_blend", "Chnaged To: Drug_deadman_blend");
					Features::addVisOption("drug_drive_blend01", "drug_drive_blend01", "Chnaged To: drug_drive_blend01");
					Features::addVisOption("drug_drive_blend02", "drug_drive_blend02", "Chnaged To: drug_drive_blend02");
					Features::addVisOption("drug_flying_01", "drug_flying_01", "Chnaged To: drug_flying_01");
					Features::addVisOption("drug_flying_02", "drug_flying_02", "Chnaged To: drug_flying_02");
					Features::addVisOption("drug_flying_base", "drug_flying_base", "Chnaged To: drug_flying_base");
					Features::addVisOption("DRUG_gas_huffin", "DRUG_gas_huffin", "Chnaged To: DRUG_gas_huffin");
					Features::addVisOption("drug_wobbly", "drug_wobbly", "Chnaged To: drug_wobbly");
					Features::addVisOption("Drunk", "Drunk", "Chnaged To: Drunk");
					Features::addVisOption("dying", "dying", "Chnaged To: dying");
					Features::addVisOption("eatra_bouncelight_beach", "eatra_bouncelight_beach", "Chnaged To: eatra_bouncelight_beach");
					Features::addVisOption("epsilion", "epsilion", "Chnaged To: epsilion");
					Features::addVisOption("exile1_exit", "exile1_exit", "Chnaged To: exile1_exit");
					Features::addVisOption("exile1_plane", "exile1_plane", "Chnaged To: exile1_plane");
					Features::addVisOption("ExplosionJosh", "ExplosionJosh", "Chnaged To: ExplosionJosh");
					Features::addVisOption("ext_int_extlight_large", "ext_int_extlight_large", "Chnaged To: ext_int_extlight_large");
					Features::addVisOption("EXTRA_bouncelight", "EXTRA_bouncelight", "Chnaged To: EXTRA_bouncelight");
					Features::addVisOption("eyeINtheSKY", "eyeINtheSKY", "Chnaged To: eyeINtheSKY");
					Features::addVisOption("Facebook_NEW", "Facebook_NEW", "Chnaged To: Facebook_NEW");
					Features::addVisOption("facebook_serveroom", "facebook_serveroom", "Chnaged To: facebook_serveroom");
					Features::addVisOption("FIB_5", "FIB_5", "Chnaged To: FIB_5");
					Features::addVisOption("FIB_6", "FIB_6", "Chnaged To: FIB_6");
					Features::addVisOption("FIB_A", "FIB_A", "Chnaged To: FIB_A");
					Features::addVisOption("FIB_B", "FIB_B", "Chnaged To: FIB_B");
					Features::addVisOption("FIB_interview", "FIB_interview", "Chnaged To: FIB_interview");
					Features::addVisOption("FIB_interview_optimise", "FIB_interview_optimise", "Chnaged To: FIB_interview_optimise");
					Features::addVisOption("FinaleBank", "FinaleBank", "Chnaged To: FinaleBank");
					Features::addVisOption("FinaleBankexit", "FinaleBankexit", "Chnaged To: FinaleBankexit");
					Features::addVisOption("FinaleBankMid", "FinaleBankMid", "Chnaged To: FinaleBankMid");
					Features::addVisOption("fireDEPT", "fireDEPT", "Chnaged To: fireDEPT");
					Features::addVisOption("FORdoron_delete", "FORdoron_delete", "Chnaged To: FORdoron_delete");
					Features::addVisOption("Forest", "Forest", "Chnaged To: Forest");
					Features::addVisOption("FrankilinsHOUSEhills", "FrankilinsHOUSEhills", "Chnaged To: FrankilinsHOUSEhills");
					Features::addVisOption("frankilnsAUNTS_new", "frankilnsAUNTS_new", "Chnaged To: frankilnsAUNTS_new");
					Features::addVisOption("frankilnsAUNTS_SUNdir", "frankilnsAUNTS_SUNdir", "Chnaged To: frankilnsAUNTS_SUNdir");
					Features::addVisOption("FRANKLIN", "FRANKLIN", "Chnaged To: FRANKLIN");
					Features::addVisOption("FranklinColorCode", "FranklinColorCode", "Chnaged To: FranklinColorCode");
					Features::addVisOption("FranklinColorCodeBasic", "FranklinColorCodeBasic", "Chnaged To: FranklinColorCodeBasic");
					Features::addVisOption("FullAmbientmult_interior", "FullAmbientmult_interior", "Chnaged To: FullAmbientmult_interior");
					Features::addVisOption("gallery_refmod", "gallery_refmod", "Chnaged To: gallery_refmod");
					Features::addVisOption("garage", "garage", "Chnaged To: garage");
					Features::addVisOption("gorge_reflection_gpu", "gorge_reflection_gpu", "Chnaged To: gorge_reflection_gpu");
					Features::addVisOption("gorge_reflectionoffset", "gorge_reflectionoffset", "Chnaged To: gorge_reflectionoffset");
					Features::addVisOption("gorge_reflectionoffset2", "gorge_reflectionoffset2", "Chnaged To: gorge_reflectionoffset2");
					Features::addVisOption("graveyard_shootout", "graveyard_shootout", "Chnaged To: graveyard_shootout");
					Features::addVisOption("gunclub", "gunclub", "Chnaged To: gunclub");
					Features::addVisOption("gunclubrange", "gunclubrange", "Chnaged To: gunclubrange");
					Features::addVisOption("gunshop", "gunshop", "Chnaged To: gunshop");
					Features::addVisOption("gunstore", "gunstore", "Chnaged To: gunstore");
					Features::addVisOption("half_direct", "half_direct", "Chnaged To: half_direct");
					Features::addVisOption("hangar_lightsmod", "hangar_lightsmod", "Chnaged To: hangar_lightsmod");
					Features::addVisOption("Hanger_INTmods", "Hanger_INTmods", "Chnaged To: Hanger_INTmods");
					Features::addVisOption("heathaze", "heathaze", "Chnaged To: heathaze");
					Features::addVisOption("helicamfirst", "helicamfirst", "Chnaged To: helicamfirst");
					Features::addVisOption("Hicksbar", "Hicksbar", "Chnaged To: Hicksbar");
					Features::addVisOption("HicksbarNEW", "HicksbarNEW", "Chnaged To: HicksbarNEW");
					Features::addVisOption("hillstunnel", "hillstunnel", "Chnaged To: hillstunnel");
					Features::addVisOption("Hint_cam", "Hint_cam", "Chnaged To: Hint_cam");
					Features::addVisOption("hitped", "hitped", "Chnaged To: hitped");
					Features::addVisOption("hud_def_blur", "hud_def_blur", "Chnaged To: hud_def_blur");
					Features::addVisOption("hud_def_colorgrade", "hud_def_colorgrade", "Chnaged To: hud_def_colorgrade");
					Features::addVisOption("hud_def_desat_cold", "hud_def_desat_cold", "Chnaged To: hud_def_desat_cold");
					Features::addVisOption("hud_def_desat_cold_kill", "hud_def_desat_cold_kill", "Chnaged To: hud_def_desat_cold_kill");
					Features::addVisOption("hud_def_desat_Franklin", "hud_def_desat_Franklin", "Chnaged To: hud_def_desat_Franklin");
					Features::addVisOption("hud_def_desat_Michael", "hud_def_desat_Michael", "Chnaged To: hud_def_desat_Michael");
					Features::addVisOption("hud_def_desat_Neutral", "hud_def_desat_Neutral", "Chnaged To: hud_def_desat_Neutral");
					Features::addVisOption("hud_def_desat_switch", "hud_def_desat_switch", "Chnaged To: hud_def_desat_switch");
					Features::addVisOption("hud_def_desat_Trevor", "hud_def_desat_Trevor", "Chnaged To: hud_def_desat_Trevor");
					Features::addVisOption("hud_def_desatcrunch", "hud_def_desatcrunch", "Chnaged To: hud_def_desatcrunch");
					Features::addVisOption("hud_def_flash", "hud_def_flash", "Chnaged To: hud_def_flash");
					Features::addVisOption("hud_def_focus", "hud_def_focus", "Chnaged To: hud_def_focus");
					Features::addVisOption("hud_def_Franklin", "hud_def_Franklin", "Chnaged To: hud_def_Franklin");
					Features::addVisOption("hud_def_lensdistortion", "hud_def_lensdistortion", "Chnaged To: hud_def_lensdistortion");
					Features::addVisOption("hud_def_Michael", "hud_def_Michael", "Chnaged To: hud_def_Michael");
					Features::addVisOption("hud_def_Trevor", "hud_def_Trevor", "Chnaged To: hud_def_Trevor");
					Features::addVisOption("id1_11_tunnel", "id1_11_tunnel", "Chnaged To: id1_11_tunnel");
					Features::addVisOption("int_amb_mult_large", "int_amb_mult_large", "Chnaged To: int_amb_mult_large");
					Features::addVisOption("int_Barber1", "int_Barber1", "Chnaged To: int_Barber1");
					Features::addVisOption("int_carmod_small", "int_carmod_small", "Chnaged To: int_carmod_small");
					Features::addVisOption("int_carshowroom", "int_carshowroom", "Chnaged To: int_carshowroom");
					Features::addVisOption("int_chopshop", "int_chopshop", "Chnaged To: int_chopshop");
					Features::addVisOption("int_clean_extlight_large", "int_clean_extlight_large", "Chnaged To: int_clean_extlight_large");
					Features::addVisOption("int_clean_extlight_none", "int_clean_extlight_none", "Chnaged To: int_clean_extlight_none");
					Features::addVisOption("int_clean_extlight_small", "int_clean_extlight_small", "Chnaged To: int_clean_extlight_small");
					Features::addVisOption("int_ClothesHi", "int_ClothesHi", "Chnaged To: int_ClothesHi");
					Features::addVisOption("int_clotheslow_large", "int_clotheslow_large", "Chnaged To: int_clotheslow_large");
					Features::addVisOption("int_cluckinfactory_none", "int_cluckinfactory_none", "Chnaged To: int_cluckinfactory_none");
					Features::addVisOption("int_cluckinfactory_small", "int_cluckinfactory_small", "Chnaged To: int_cluckinfactory_small");
					Features::addVisOption("int_ControlTower_none", "int_ControlTower_none", "Chnaged To: int_ControlTower_none");
					Features::addVisOption("int_ControlTower_small", "int_ControlTower_small", "Chnaged To: int_ControlTower_small");
					Features::addVisOption("int_dockcontrol_small", "int_dockcontrol_small", "Chnaged To: int_dockcontrol_small");
					Features::addVisOption("int_extlght_sm_cntrst", "int_extlght_sm_cntrst", "Chnaged To: int_extlght_sm_cntrst");
					Features::addVisOption("int_extlight_large", "int_extlight_large", "Chnaged To: int_extlight_large");
					Features::addVisOption("int_extlight_large_fog", "int_extlight_large_fog", "Chnaged To: int_extlight_large_fog");
					Features::addVisOption("int_extlight_none", "int_extlight_none", "Chnaged To: int_extlight_none");
					Features::addVisOption("int_extlight_none_dark", "int_extlight_none_dark", "Chnaged To: int_extlight_none_dark");
					Features::addVisOption("int_extlight_none_dark_fog", "int_extlight_none_dark_fog", "Chnaged To: int_extlight_none_dark_fog");
					Features::addVisOption("int_extlight_none_fog", "int_extlight_none_fog", "Chnaged To: int_extlight_none_fog");
					Features::addVisOption("int_extlight_small", "int_extlight_small", "Chnaged To: int_extlight_small");
					Features::addVisOption("int_extlight_small_clipped", "int_extlight_small_clipped", "Chnaged To: int_extlight_small_clipped");
					Features::addVisOption("int_extlight_small_fog", "int_extlight_small_fog", "Chnaged To: int_extlight_small_fog");
					Features::addVisOption("int_Farmhouse_none", "int_Farmhouse_none", "Chnaged To: int_Farmhouse_none");
					Features::addVisOption("int_Farmhouse_small", "int_Farmhouse_small", "Chnaged To: int_Farmhouse_small");
					Features::addVisOption("int_FranklinAunt_small", "int_FranklinAunt_small", "Chnaged To: int_FranklinAunt_small");
					Features::addVisOption("INT_FullAmbientmult", "INT_FullAmbientmult", "Chnaged To: INT_FullAmbientmult");
					Features::addVisOption("INT_FULLAmbientmult_art", "INT_FULLAmbientmult_art", "Chnaged To: INT_FULLAmbientmult_art");
					Features::addVisOption("INT_FULLAmbientmult_both", "INT_FULLAmbientmult_both", "Chnaged To: INT_FULLAmbientmult_both");
					Features::addVisOption("INT_garage", "INT_garage", "Chnaged To: INT_garage");
					Features::addVisOption("int_GasStation", "int_GasStation", "Chnaged To: int_GasStation");
					Features::addVisOption("int_hanger_none", "int_hanger_none", "Chnaged To: int_hanger_none");
					Features::addVisOption("int_hanger_small", "int_hanger_small", "Chnaged To: int_hanger_small");
					Features::addVisOption("int_Hospital2_DM", "int_Hospital2_DM", "Chnaged To: int_Hospital2_DM");
					Features::addVisOption("int_Hospital_Blue", "int_Hospital_Blue", "Chnaged To: int_Hospital_Blue");
					Features::addVisOption("int_Hospital_BlueB", "int_Hospital_BlueB", "Chnaged To: int_Hospital_BlueB");
					Features::addVisOption("int_Hospital_DM", "int_Hospital_DM", "Chnaged To: int_Hospital_DM");
					Features::addVisOption("int_lesters", "int_lesters", "Chnaged To: int_lesters");
					Features::addVisOption("int_Lost_none", "int_Lost_none", "Chnaged To: int_Lost_none");
					Features::addVisOption("int_Lost_small", "int_Lost_small", "Chnaged To: int_Lost_small");
					Features::addVisOption("int_methlab_small", "int_methlab_small", "Chnaged To: int_methlab_small");
					Features::addVisOption("int_motelroom", "int_motelroom", "Chnaged To: int_motelroom");
					Features::addVisOption("INT_NO_fogALPHA", "INT_NO_fogALPHA", "Chnaged To: INT_NO_fogALPHA");
					Features::addVisOption("INT_NoAmbientmult", "INT_NoAmbientmult", "Chnaged To: INT_NoAmbientmult");
					Features::addVisOption("INT_NoAmbientmult_art", "INT_NoAmbientmult_art", "Chnaged To: INT_NoAmbientmult_art");
					Features::addVisOption("INT_NoAmbientmult_both", "INT_NoAmbientmult_both", "Chnaged To: INT_NoAmbientmult_both");
					Features::addVisOption("INT_NOdirectLight", "INT_NOdirectLight", "Chnaged To: INT_NOdirectLight");
					Features::addVisOption("INT_nowaterREF", "INT_nowaterREF", "Chnaged To: INT_nowaterREF");
					Features::addVisOption("int_office_Lobby", "int_office_Lobby", "Chnaged To: int_office_Lobby");
					Features::addVisOption("int_office_LobbyHall", "int_office_LobbyHall", "Chnaged To: int_office_LobbyHall");
					Features::addVisOption("INT_posh_hairdresser", "INT_posh_hairdresser", "Chnaged To: INT_posh_hairdresser");
					Features::addVisOption("INT_streetlighting", "INT_streetlighting", "Chnaged To: INT_streetlighting");
					Features::addVisOption("int_tattoo", "int_tattoo", "Chnaged To: int_tattoo");
					Features::addVisOption("int_tattoo_B", "int_tattoo_B", "Chnaged To: int_tattoo_B");
					Features::addVisOption("int_tunnel_none_dark", "int_tunnel_none_dark", "Chnaged To: int_tunnel_none_dark");
					Features::addVisOption("interior_WATER_lighting", "interior_WATER_lighting", "Chnaged To: interior_WATER_lighting");
					Features::addVisOption("introblue", "introblue", "Chnaged To: introblue");
					Features::addVisOption("jewel_gas", "jewel_gas", "Chnaged To: jewel_gas");
					Features::addVisOption("jewel_optim", "jewel_optim", "Chnaged To: jewel_optim");
					Features::addVisOption("jewelry_entrance", "jewelry_entrance", "Chnaged To: jewelry_entrance");
					Features::addVisOption("jewelry_entrance_INT", "jewelry_entrance_INT", "Chnaged To: jewelry_entrance_INT");
					Features::addVisOption("jewelry_entrance_INT_fog", "jewelry_entrance_INT_fog", "Chnaged To: jewelry_entrance_INT_fog");
					Features::addVisOption("KT_underpass", "KT_underpass", "Chnaged To: KT_underpass");
					Features::addVisOption("lab_none", "lab_none", "Chnaged To: lab_none");
					Features::addVisOption("lab_none_dark", "lab_none_dark", "Chnaged To: lab_none_dark");
					Features::addVisOption("lab_none_dark_fog", "lab_none_dark_fog", "Chnaged To: lab_none_dark_fog");
					Features::addVisOption("lab_none_exit", "lab_none_exit", "Chnaged To: lab_none_exit");
					Features::addVisOption("LifeInvaderLOD", "LifeInvaderLOD", "Chnaged To: LifeInvaderLOD");
					Features::addVisOption("lightning", "lightning", "Chnaged To: lightning");
					Features::addVisOption("lightning_cloud", "lightning_cloud", "Chnaged To: lightning_cloud");
					Features::addVisOption("lightning_strong", "lightning_strong", "Chnaged To: lightning_strong");
					Features::addVisOption("lightning_weak", "lightning_weak", "Chnaged To: lightning_weak");
					Features::addVisOption("LightPollutionHills", "LightPollutionHills", "Chnaged To: LightPollutionHills");
					Features::addVisOption("lightpolution", "lightpolution", "Chnaged To: lightpolution");
					Features::addVisOption("LIGHTSreduceFALLOFF", "LIGHTSreduceFALLOFF", "Chnaged To: LIGHTSreduceFALLOFF");
					Features::addVisOption("LODmult_global_reduce", "LODmult_global_reduce", "Chnaged To: LODmult_global_reduce");
					Features::addVisOption("LODmult_global_reduce_NOHD", "LODmult_global_reduce_NOHD", "Chnaged To: LODmult_global_reduce_NOHD");
					Features::addVisOption("LODmult_HD_orphan_LOD_reduce", "LODmult_HD_orphan_LOD_reduce", "Chnaged To: LODmult_HD_orphan_LOD_reduce");
					Features::addVisOption("LODmult_HD_orphan_reduce", "LODmult_HD_orphan_reduce", "Chnaged To: LODmult_HD_orphan_reduce");
					Features::addVisOption("LODmult_LOD_reduce", "LODmult_LOD_reduce", "Chnaged To: LODmult_LOD_reduce");
					Features::addVisOption("LODmult_SLOD1_reduce", "LODmult_SLOD1_reduce", "Chnaged To: LODmult_SLOD1_reduce");
					Features::addVisOption("LODmult_SLOD2_reduce", "LODmult_SLOD2_reduce", "Chnaged To: LODmult_SLOD2_reduce");
					Features::addVisOption("LODmult_SLOD3_reduce", "LODmult_SLOD3_reduce", "Chnaged To: LODmult_SLOD3_reduce");
					Features::addVisOption("metro", "metro", "Chnaged To: metro");
					Features::addVisOption("METRO_platform", "METRO_platform", "Chnaged To: METRO_platform");
					Features::addVisOption("METRO_Tunnels", "METRO_Tunnels", "Chnaged To: METRO_Tunnels");
					Features::addVisOption("METRO_Tunnels_entrance", "METRO_Tunnels_entrance", "Chnaged To: METRO_Tunnels_entrance");
					Features::addVisOption("MichaelColorCode", "MichaelColorCode", "Chnaged To: MichaelColorCode");
					Features::addVisOption("MichaelColorCodeBasic", "MichaelColorCodeBasic", "Chnaged To: MichaelColorCodeBasic");
					Features::addVisOption("MichaelsDarkroom", "MichaelsDarkroom", "Chnaged To: MichaelsDarkroom");
					Features::addVisOption("MichaelsDirectional", "MichaelsDirectional", "Chnaged To: MichaelsDirectional");
					Features::addVisOption("MichaelsNODirectional", "MichaelsNODirectional", "Chnaged To: MichaelsNODirectional");
					Features::addVisOption("micheal", "micheal", "Chnaged To: micheal");
					Features::addVisOption("micheals_lightsOFF", "micheals_lightsOFF", "Chnaged To: micheals_lightsOFF");
					Features::addVisOption("michealspliff", "michealspliff", "Chnaged To: michealspliff");
					Features::addVisOption("michealspliff_blend", "michealspliff_blend", "Chnaged To: michealspliff_blend");
					Features::addVisOption("michealspliff_blend02", "michealspliff_blend02", "Chnaged To: michealspliff_blend02");
					Features::addVisOption("militarybase_nightlight", "militarybase_nightlight", "Chnaged To: militarybase_nightlight");
					Features::addVisOption("morebloomnumMods=3", "morebloomnumMods=3", "Chnaged To: morebloomnumMods=3");
					Features::addVisOption("morgue_dark", "morgue_dark", "Chnaged To: morgue_dark");
					Features::addVisOption("Mp_apart_mid", "Mp_apart_mid", "Chnaged To: Mp_apart_mid");
					Features::addVisOption("MP_Bull_tost", "MP_Bull_tost", "Chnaged To: MP_Bull_tost");
					Features::addVisOption("MP_Bull_tost_blend", "MP_Bull_tost_blend", "Chnaged To: MP_Bull_tost_blend");
					Features::addVisOption("MP_corona_switch", "MP_corona_switch", "Chnaged To: MP_corona_switch");
					Features::addVisOption("MP_death_grade", "MP_death_grade", "Chnaged To: MP_death_grade");
					Features::addVisOption("MP_death_grade_blend01", "MP_death_grade_blend01", "Chnaged To: MP_death_grade_blend01");
					Features::addVisOption("MP_death_grade_blend02", "MP_death_grade_blend02", "Chnaged To: MP_death_grade_blend02");
					Features::addVisOption("MP_Garage_L", "MP_Garage_L", "Chnaged To: MP_Garage_L");
					Features::addVisOption("MP_heli_cam", "MP_heli_cam", "Chnaged To: MP_heli_cam");
					Features::addVisOption("MP_intro_logo", "MP_intro_logo", "Chnaged To: MP_intro_logo");
					Features::addVisOption("MP_job_load", "MP_job_load", "Chnaged To: MP_job_load");
					Features::addVisOption("MP_job_lose", "MP_job_lose", "Chnaged To: MP_job_lose");
					Features::addVisOption("MP_job_win", "MP_job_win", "Chnaged To: MP_job_win");
					Features::addVisOption("MP_Killstreak", "MP_Killstreak", "Chnaged To: MP_Killstreak");
					Features::addVisOption("MP_Killstreak_blend", "MP_Killstreak_blend", "Chnaged To: MP_Killstreak_blend");
					Features::addVisOption("MP_Loser", "MP_Loser", "Chnaged To: MP_Loser");
					Features::addVisOption("MP_Loser_blend", "MP_Loser_blend", "Chnaged To: MP_Loser_blend");
					Features::addVisOption("MP_lowgarage", "MP_lowgarage", "Chnaged To: MP_lowgarage");
					Features::addVisOption("MP_MedGarage", "MP_MedGarage", "Chnaged To: MP_MedGarage");
					Features::addVisOption("MP_Powerplay", "MP_Powerplay", "Chnaged To: MP_Powerplay");
					Features::addVisOption("MP_Powerplay_blend", "MP_Powerplay_blend", "Chnaged To: MP_Powerplay_blend");
					Features::addVisOption("MP_race_finish", "MP_race_finish", "Chnaged To: MP_race_finish");
					Features::addVisOption("MP_select", "MP_select", "Chnaged To: MP_select");
					Features::addVisOption("MP_Studio_Lo", "MP_Studio_Lo", "Chnaged To: MP_Studio_Lo");
					Features::addVisOption("MPApartHigh", "MPApartHigh", "Chnaged To: MPApartHigh");
					Features::addVisOption("Multipayer_spectatorCam", "Multipayer_spectatorCam", "Chnaged To: Multipayer_spectatorCam");
					Features::addVisOption("multiplayer_ped_fight", "multiplayer_ped_fight", "Chnaged To: multiplayer_ped_fight");
					Features::addVisOption("nervousRON_fog", "nervousRON_fog", "Chnaged To: nervousRON_fog");
					Features::addVisOption("NeutralColorCode", "NeutralColorCode", "Chnaged To: NeutralColorCode");
					Features::addVisOption("NeutralColorCodeBasic", "NeutralColorCodeBasic", "Chnaged To: NeutralColorCodeBasic");
					Features::addVisOption("NeutralColorCodeLight", "NeutralColorCodeLight", "Chnaged To: NeutralColorCodeLight");
					Features::addVisOption("NEW_abattoir", "NEW_abattoir", "Chnaged To: NEW_abattoir");
					Features::addVisOption("new_bank", "new_bank", "Chnaged To: new_bank");
					Features::addVisOption("NEW_jewel", "NEW_jewel", "Chnaged To: NEW_jewel");
					Features::addVisOption("NEW_jewel_EXIT", "NEW_jewel_EXIT", "Chnaged To: NEW_jewel_EXIT");
					Features::addVisOption("NEW_lesters", "NEW_lesters", "Chnaged To: NEW_lesters");
					Features::addVisOption("NEW_ornate_bank", "NEW_ornate_bank", "Chnaged To: NEW_ornate_bank");
					Features::addVisOption("NEW_ornate_bank_entrance", "NEW_ornate_bank_entrance", "Chnaged To: NEW_ornate_bank_entrance");
					Features::addVisOption("NEW_ornate_bank_office", "NEW_ornate_bank_office", "Chnaged To: NEW_ornate_bank_office");
					Features::addVisOption("NEW_ornate_bank_safe", "NEW_ornate_bank_safe", "Chnaged To: NEW_ornate_bank_safe");
					Features::addVisOption("New_sewers", "New_sewers", "Chnaged To: New_sewers");
					Features::addVisOption("NEW_shrinksOffice", "NEW_shrinksOffice", "Chnaged To: NEW_shrinksOffice");
					Features::addVisOption("NEW_station_unfinished", "NEW_station_unfinished", "Chnaged To: NEW_station_unfinished");
					Features::addVisOption("new_stripper_changing", "new_stripper_changing", "Chnaged To: new_stripper_changing");
					Features::addVisOption("NEW_trevorstrailer", "NEW_trevorstrailer", "Chnaged To: NEW_trevorstrailer");
					Features::addVisOption("NEW_tunnels", "NEW_tunnels", "Chnaged To: NEW_tunnels");
					Features::addVisOption("NEW_tunnels_ditch", "NEW_tunnels_ditch", "Chnaged To: NEW_tunnels_ditch");
					Features::addVisOption("new_tunnels_entrance", "new_tunnels_entrance", "Chnaged To: new_tunnels_entrance");
					Features::addVisOption("NEW_tunnels_hole", "NEW_tunnels_hole", "Chnaged To: NEW_tunnels_hole");
					Features::addVisOption("NEW_yellowtunnels", "NEW_yellowtunnels", "Chnaged To: NEW_yellowtunnels");
					Features::addVisOption("NewMicheal", "NewMicheal", "Chnaged To: NewMicheal");
					Features::addVisOption("NewMicheal_night", "NewMicheal_night", "Chnaged To: NewMicheal_night");
					Features::addVisOption("NewMicheal_upstairs", "NewMicheal_upstairs", "Chnaged To: NewMicheal_upstairs");
					Features::addVisOption("NewMichealgirly", "NewMichealgirly", "Chnaged To: NewMichealgirly");
					Features::addVisOption("NewMichealstoilet", "NewMichealstoilet", "Chnaged To: NewMichealstoilet");
					Features::addVisOption("NewMichealupstairs", "NewMichealupstairs", "Chnaged To: NewMichealupstairs");
					Features::addVisOption("NewMod", "NewMod", "Chnaged To: NewMod");
					Features::addVisOption("nextgen", "nextgen", "Chnaged To: nextgen");
					Features::addVisOption("NO_coronas", "NO_coronas", "Chnaged To: NO_coronas");
					Features::addVisOption("NO_fog_alpha", "NO_fog_alpha", "Chnaged To: NO_fog_alpha");
					Features::addVisOption("NO_streetAmbient", "NO_streetAmbient", "Chnaged To: NO_streetAmbient");
					Features::addVisOption("NO_weather", "NO_weather", "Chnaged To: NO_weather");
					Features::addVisOption("NoAmbientmult", "NoAmbientmult", "Chnaged To: NoAmbientmult");
					Features::addVisOption("NoAmbientmult_interior", "NoAmbientmult_interior", "Chnaged To: NoAmbientmult_interior");
					Features::addVisOption("NOdirectLight", "NOdirectLight", "Chnaged To: NOdirectLight");
					Features::addVisOption("NOrain", "NOrain", "Chnaged To: NOrain");
					Features::addVisOption("overwater", "overwater", "Chnaged To: overwater");
					Features::addVisOption("Paleto", "Paleto", "Chnaged To: Paleto");
					Features::addVisOption("paleto_nightlight", "paleto_nightlight", "Chnaged To: paleto_nightlight");
					Features::addVisOption("paleto_opt", "paleto_opt", "Chnaged To: paleto_opt");
					Features::addVisOption("PERSHING_water_reflect", "PERSHING_water_reflect", "Chnaged To: PERSHING_water_reflect");
					Features::addVisOption("phone_cam", "phone_cam", "Chnaged To: phone_cam");
					Features::addVisOption("phone_cam1", "phone_cam1", "Chnaged To: phone_cam1");
					Features::addVisOption("phone_cam10", "phone_cam10", "Chnaged To: phone_cam10");
					Features::addVisOption("phone_cam11", "phone_cam11", "Chnaged To: phone_cam11");
					Features::addVisOption("phone_cam12", "phone_cam12", "Chnaged To: phone_cam12");
					Features::addVisOption("phone_cam13", "phone_cam13", "Chnaged To: phone_cam13");
					Features::addVisOption("phone_cam2", "phone_cam2", "Chnaged To: phone_cam2");
					Features::addVisOption("phone_cam3", "phone_cam3", "Chnaged To: phone_cam3");
					Features::addVisOption("phone_cam4", "phone_cam4", "Chnaged To: phone_cam4");
					Features::addVisOption("phone_cam5", "phone_cam5", "Chnaged To: phone_cam5");
					Features::addVisOption("phone_cam6", "phone_cam6", "Chnaged To: phone_cam6");
					Features::addVisOption("phone_cam7", "phone_cam7", "Chnaged To: phone_cam7");
					Features::addVisOption("phone_cam9", "phone_cam9", "Chnaged To: phone_cam9");
					Features::addVisOption("plane_inside_mode", "plane_inside_mode", "Chnaged To: plane_inside_mode");
					Features::addVisOption("player_transition", "player_transition", "Chnaged To: player_transition");
					Features::addVisOption("player_transition_no_scanlines", "player_transition_no_scanlines", "Chnaged To: player_transition_no_scanlines");
					Features::addVisOption("player_transition_scanlines", "player_transition_scanlines", "Chnaged To: player_transition_scanlines");
					Features::addVisOption("PlayerSwitchNeutralFlash", "PlayerSwitchNeutralFlash", "Chnaged To: PlayerSwitchNeutralFlash");
					Features::addVisOption("PlayerSwitchPulse", "PlayerSwitchPulse", "Chnaged To: PlayerSwitchPulse");
					Features::addVisOption("PoliceStation", "PoliceStation", "Chnaged To: PoliceStation");
					Features::addVisOption("PoliceStationDark", "PoliceStationDark", "Chnaged To: PoliceStationDark");
					Features::addVisOption("polluted", "polluted", "Chnaged To: polluted");
					Features::addVisOption("poolsidewaterreflection2", "poolsidewaterreflection2", "Chnaged To: poolsidewaterreflection2");
					Features::addVisOption("PORT_heist_underwater", "PORT_heist_underwater", "Chnaged To: PORT_heist_underwater");
					Features::addVisOption("powerplant_nightlight", "powerplant_nightlight", "Chnaged To: powerplant_nightlight");
					Features::addVisOption("powerstation", "powerstation", "Chnaged To: powerstation");
					Features::addVisOption("prison_nightlight", "prison_nightlight", "Chnaged To: prison_nightlight");
					Features::addVisOption("projector", "projector", "Chnaged To: projector");
					Features::addVisOption("prologue", "prologue", "Chnaged To: prologue");
					Features::addVisOption("prologue_ending_fog", "prologue_ending_fog", "Chnaged To: prologue_ending_fog");
					Features::addVisOption("prologue_ext_art_amb", "prologue_ext_art_amb", "Chnaged To: prologue_ext_art_amb");
					Features::addVisOption("prologue_reflection_opt", "prologue_reflection_opt", "Chnaged To: prologue_reflection_opt");
					Features::addVisOption("prologue_shootout", "prologue_shootout", "Chnaged To: prologue_shootout");
					Features::addVisOption("Prologue_shootout_opt", "Prologue_shootout_opt", "Chnaged To: Prologue_shootout_opt");
					Features::addVisOption("pulse", "pulse", "Chnaged To: pulse");
					Features::addVisOption("RaceTurboDark", "RaceTurboDark", "Chnaged To: RaceTurboDark");
					Features::addVisOption("RaceTurboFlash", "RaceTurboFlash", "Chnaged To: RaceTurboFlash");
					Features::addVisOption("RaceTurboLight", "RaceTurboLight", "Chnaged To: RaceTurboLight");
					Features::addVisOption("ranch", "ranch", "Chnaged To: ranch");
					Features::addVisOption("REDMIST", "REDMIST", "Chnaged To: REDMIST");
					Features::addVisOption("REDMIST_blend", "REDMIST_blend", "Chnaged To: REDMIST_blend");
					Features::addVisOption("ReduceDrawDistance", "ReduceDrawDistance", "Chnaged To: ReduceDrawDistance");
					Features::addVisOption("ReduceDrawDistanceMAP", "ReduceDrawDistanceMAP", "Chnaged To: ReduceDrawDistanceMAP");
					Features::addVisOption("ReduceDrawDistanceMission", "ReduceDrawDistanceMission", "Chnaged To: ReduceDrawDistanceMission");
					Features::addVisOption("reducelightingcost", "reducelightingcost", "Chnaged To: reducelightingcost");
					Features::addVisOption("ReduceSSAO", "ReduceSSAO", "Chnaged To: ReduceSSAO");
					Features::addVisOption("reducewaterREF", "reducewaterREF", "Chnaged To: reducewaterREF");
					Features::addVisOption("refit", "refit", "Chnaged To: refit");
					Features::addVisOption("reflection_correct_ambient", "reflection_correct_ambient", "Chnaged To: reflection_correct_ambient");
					Features::addVisOption("RemoteSniper", "RemoteSniper", "Chnaged To: RemoteSniper");
					Features::addVisOption("resvoire_reflection", "resvoire_reflection", "Chnaged To: resvoire_reflection");
					Features::addVisOption("SALTONSEA", "SALTONSEA", "Chnaged To: SALTONSEA");
					Features::addVisOption("sandyshore_nightlight", "sandyshore_nightlight", "Chnaged To: sandyshore_nightlight");
					Features::addVisOption("SAWMILL", "SAWMILL", "Chnaged To: SAWMILL");
					Features::addVisOption("scanline_cam", "scanline_cam", "Chnaged To: scanline_cam");
					Features::addVisOption("scanline_cam_cheap", "scanline_cam_cheap", "Chnaged To: scanline_cam_cheap");
					Features::addVisOption("scope_zoom_in", "scope_zoom_in", "Chnaged To: scope_zoom_in");
					Features::addVisOption("scope_zoom_out", "scope_zoom_out", "Chnaged To: scope_zoom_out");
					Features::addVisOption("secret_camera", "secret_camera", "Chnaged To: secret_camera");
					Features::addVisOption("services_nightlight", "services_nightlight", "Chnaged To: services_nightlight");
					Features::addVisOption("shades_pink", "shades_pink", "Chnaged To: shades_pink");
					Features::addVisOption("shades_yellow", "shades_yellow", "Chnaged To: shades_yellow");
					Features::addVisOption("SheriffStation", "SheriffStation", "Chnaged To: SheriffStation");
					Features::addVisOption("ship_explosion_underwater", "ship_explosion_underwater", "Chnaged To: ship_explosion_underwater");
					Features::addVisOption("ship_lighting", "ship_lighting", "Chnaged To: ship_lighting");
					Features::addVisOption("Shop247", "Shop247", "Chnaged To: Shop247");
					Features::addVisOption("Shop247_none", "Shop247_none", "Chnaged To: Shop247_none");
					Features::addVisOption("sleeping", "sleeping", "Chnaged To: sleeping");
					Features::addVisOption("SnipernumMods=7", "SnipernumMods=7", "Chnaged To: SnipernumMods=7");
					Features::addVisOption("SP1_03_drawDistance", "SP1_03_drawDistance", "Chnaged To: SP1_03_drawDistance");
					Features::addVisOption("spectator1", "spectator1", "Chnaged To: spectator1");
					Features::addVisOption("spectator10", "spectator10", "Chnaged To: spectator10");
					Features::addVisOption("spectator2", "spectator2", "Chnaged To: spectator2");
					Features::addVisOption("spectator3", "spectator3", "Chnaged To: spectator3");
					Features::addVisOption("spectator4", "spectator4", "Chnaged To: spectator4");
					Features::addVisOption("spectator5", "spectator5", "Chnaged To: spectator5");
					Features::addVisOption("spectator6", "spectator6", "Chnaged To: spectator6");
					Features::addVisOption("spectator7", "spectator7", "Chnaged To: spectator7");
					Features::addVisOption("spectator8", "spectator8", "Chnaged To: spectator8");
					Features::addVisOption("spectator9", "spectator9", "Chnaged To: spectator9");
					Features::addVisOption("StadLobby", "StadLobby", "Chnaged To: StadLobby");
					Features::addVisOption("stc_coroners", "stc_coroners", "Chnaged To: stc_coroners");
					Features::addVisOption("stc_deviant_bedroom", "stc_deviant_bedroom", "Chnaged To: stc_deviant_bedroom");
					Features::addVisOption("stc_deviant_lounge", "stc_deviant_lounge", "Chnaged To: stc_deviant_lounge");
					Features::addVisOption("stc_franklinsHouse", "stc_franklinsHouse", "Chnaged To: stc_franklinsHouse");
					Features::addVisOption("stc_trevors", "stc_trevors", "Chnaged To: stc_trevors");
					Features::addVisOption("stoned", "stoned", "Chnaged To: stoned");
					Features::addVisOption("stoned_aliens", "stoned_aliens", "Chnaged To: stoned_aliens");
					Features::addVisOption("stoned_cutscene", "stoned_cutscene", "Chnaged To: stoned_cutscene");
					Features::addVisOption("stoned_monkeys", "stoned_monkeys", "Chnaged To: stoned_monkeys");
					Features::addVisOption("StreetLightingJunction", "StreetLightingJunction", "Chnaged To: StreetLightingJunction");
					Features::addVisOption("StreetLightingtraffic", "StreetLightingtraffic", "Chnaged To: StreetLightingtraffic");
					Features::addVisOption("STRIP_changing", "STRIP_changing", "Chnaged To: STRIP_changing");
					Features::addVisOption("STRIP_nofog", "STRIP_nofog", "Chnaged To: STRIP_nofog");
					Features::addVisOption("STRIP_office", "STRIP_office", "Chnaged To: STRIP_office");
					Features::addVisOption("STRIP_stage", "STRIP_stage", "Chnaged To: STRIP_stage");
					Features::addVisOption("subBASE_water_ref", "subBASE_water_ref", "Chnaged To: subBASE_water_ref");
					Features::addVisOption("sunglasses", "sunglasses", "Chnaged To: sunglasses");
					Features::addVisOption("superDARK", "superDARK", "Chnaged To: superDARK");
					Features::addVisOption("switch_cam_1", "switch_cam_1", "Chnaged To: switch_cam_1");
					Features::addVisOption("switch_cam_2", "switch_cam_2", "Chnaged To: switch_cam_2");
					Features::addVisOption("telescope", "telescope", "Chnaged To: telescope");
					Features::addVisOption("torpedo", "torpedo", "Chnaged To: torpedo");
					Features::addVisOption("traffic_skycam", "traffic_skycam", "Chnaged To: traffic_skycam");
					Features::addVisOption("trailer_explosion_optimise", "trailer_explosion_optimise", "Chnaged To: trailer_explosion_optimise");
					Features::addVisOption("TREVOR", "TREVOR", "Chnaged To: TREVOR");
					Features::addVisOption("TrevorColorCode", "TrevorColorCode", "Chnaged To: TrevorColorCode");
					Features::addVisOption("TrevorColorCodeBasic", "TrevorColorCodeBasic", "Chnaged To: TrevorColorCodeBasic");
					Features::addVisOption("Trevors_room", "Trevors_room", "Chnaged To: Trevors_room");
					Features::addVisOption("trevorspliff", "trevorspliff", "Chnaged To: trevorspliff");
					Features::addVisOption("trevorspliff_blend", "trevorspliff_blend", "Chnaged To: trevorspliff_blend");
					Features::addVisOption("trevorspliff_blend02", "trevorspliff_blend02", "Chnaged To: trevorspliff_blend02");
					Features::addVisOption("Tunnel", "Tunnel", "Chnaged To: Tunnel");
					Features::addVisOption("tunnel_entrance", "tunnel_entrance", "Chnaged To: tunnel_entrance");
					Features::addVisOption("tunnel_entrance_INT", "tunnel_entrance_INT", "Chnaged To: tunnel_entrance_INT");
					Features::addVisOption("TUNNEL_green", "TUNNEL_green", "Chnaged To: TUNNEL_green");
					Features::addVisOption("Tunnel_green1", "Tunnel_green1", "Chnaged To: Tunnel_green1");
					Features::addVisOption("TUNNEL_green_ext", "TUNNEL_green_ext", "Chnaged To: TUNNEL_green_ext");
					Features::addVisOption("TUNNEL_orange", "TUNNEL_orange", "Chnaged To: TUNNEL_orange");
					Features::addVisOption("TUNNEL_orange_exterior", "TUNNEL_orange_exterior", "Chnaged To: TUNNEL_orange_exterior");
					Features::addVisOption("TUNNEL_white", "TUNNEL_white", "Chnaged To: TUNNEL_white");
					Features::addVisOption("TUNNEL_yellow", "TUNNEL_yellow", "Chnaged To: TUNNEL_yellow");
					Features::addVisOption("TUNNEL_yellow_ext", "TUNNEL_yellow_ext", "Chnaged To: TUNNEL_yellow_ext");
					Features::addVisOption("ufo", "ufo", "Chnaged To: ufo");
					Features::addVisOption("ufo_deathray", "ufo_deathray", "Chnaged To: ufo_deathray");
					Features::addVisOption("underwater", "underwater", "Chnaged To: underwater");
					Features::addVisOption("underwater_deep", "underwater_deep", "Chnaged To: underwater_deep");
					Features::addVisOption("underwater_deep_clear", "underwater_deep_clear", "Chnaged To: underwater_deep_clear");
					Features::addVisOption("v_abattoir", "v_abattoir", "Chnaged To: v_abattoir");
					Features::addVisOption("V_Abattoir_Cold", "V_Abattoir_Cold", "Chnaged To: V_Abattoir_Cold");
					Features::addVisOption("v_bahama", "v_bahama", "Chnaged To: v_bahama");
					Features::addVisOption("v_cashdepot", "v_cashdepot", "Chnaged To: v_cashdepot");
					Features::addVisOption("V_FIB_IT3", "V_FIB_IT3", "Chnaged To: V_FIB_IT3");
					Features::addVisOption("V_FIB_IT3_alt", "V_FIB_IT3_alt", "Chnaged To: V_FIB_IT3_alt");
					Features::addVisOption("V_FIB_IT3_alt5", "V_FIB_IT3_alt5", "Chnaged To: V_FIB_IT3_alt5");
					Features::addVisOption("V_FIB_stairs", "V_FIB_stairs", "Chnaged To: V_FIB_stairs");
					Features::addVisOption("v_foundry", "v_foundry", "Chnaged To: v_foundry");
					Features::addVisOption("v_janitor", "v_janitor", "Chnaged To: v_janitor");
					Features::addVisOption("v_jewel2", "v_jewel2", "Chnaged To: v_jewel2");
					Features::addVisOption("v_metro", "v_metro", "Chnaged To: v_metro");
					Features::addVisOption("V_Metro2", "V_Metro2", "Chnaged To: V_Metro2");
					Features::addVisOption("V_Metro_station", "V_Metro_station", "Chnaged To: V_Metro_station");
					Features::addVisOption("v_michael", "v_michael", "Chnaged To: v_michael");
					Features::addVisOption("v_michael_lounge", "v_michael_lounge", "Chnaged To: v_michael_lounge");
					Features::addVisOption("V_Office_smoke", "V_Office_smoke", "Chnaged To: V_Office_smoke");
					Features::addVisOption("V_Office_smoke_ext", "V_Office_smoke_ext", "Chnaged To: V_Office_smoke_ext");
					Features::addVisOption("V_Office_smoke_Fire", "V_Office_smoke_Fire", "Chnaged To: V_Office_smoke_Fire");
					Features::addVisOption("v_recycle", "v_recycle", "Chnaged To: v_recycle");
					Features::addVisOption("V_recycle_dark", "V_recycle_dark", "Chnaged To: V_recycle_dark");
					Features::addVisOption("V_recycle_light", "V_recycle_light", "Chnaged To: V_recycle_light");
					Features::addVisOption("V_recycle_mainroom", "V_recycle_mainroom", "Chnaged To: V_recycle_mainroom");
					Features::addVisOption("v_rockclub", "v_rockclub", "Chnaged To: v_rockclub");
					Features::addVisOption("V_Solomons", "V_Solomons", "Chnaged To: V_Solomons");
					Features::addVisOption("v_strip3", "v_strip3", "Chnaged To: v_strip3");
					Features::addVisOption("V_strip_nofog", "V_strip_nofog", "Chnaged To: V_strip_nofog");
					Features::addVisOption("V_strip_office", "V_strip_office", "Chnaged To: V_strip_office");
					Features::addVisOption("v_strpchangerm", "v_strpchangerm", "Chnaged To: v_strpchangerm");
					Features::addVisOption("v_sweat", "v_sweat", "Chnaged To: v_sweat");
					Features::addVisOption("v_sweat_entrance", "v_sweat_entrance", "Chnaged To: v_sweat_entrance");
					Features::addVisOption("v_sweat_NoDirLight", "v_sweat_NoDirLight", "Chnaged To: v_sweat_NoDirLight");
					Features::addVisOption("v_torture", "v_torture", "Chnaged To: v_torture");
					Features::addVisOption("Vagos", "Vagos", "Chnaged To: Vagos");
					Features::addVisOption("vagos_extlight_small", "vagos_extlight_small", "Chnaged To: vagos_extlight_small");
					Features::addVisOption("VAGOS_new_garage", "VAGOS_new_garage", "Chnaged To: VAGOS_new_garage");
					Features::addVisOption("VAGOS_new_hangout", "VAGOS_new_hangout", "Chnaged To: VAGOS_new_hangout");
					Features::addVisOption("VagosSPLASH", "VagosSPLASH", "Chnaged To: VagosSPLASH");
					Features::addVisOption("VC_tunnel_entrance", "VC_tunnel_entrance", "Chnaged To: VC_tunnel_entrance");
					Features::addVisOption("venice_canal_tunnel", "venice_canal_tunnel", "Chnaged To: venice_canal_tunnel");
					Features::addVisOption("vespucci_garage", "vespucci_garage", "Chnaged To: vespucci_garage");
					Features::addVisOption("warehouse", "warehouse", "Chnaged To: warehouse");
					Features::addVisOption("WATER_hills", "WATER_hills", "Chnaged To: WATER_hills");
					Features::addVisOption("WATER_lab", "WATER_lab", "Chnaged To: WATER_lab");
					Features::addVisOption("WATER_lab_cooling", "WATER_lab_cooling", "Chnaged To: WATER_lab_cooling");
					Features::addVisOption("WATER_militaryPOOP", "WATER_militaryPOOP", "Chnaged To: WATER_militaryPOOP");
					Features::addVisOption("WATER_muddy", "WATER_muddy", "Chnaged To: WATER_muddy");
					Features::addVisOption("WATER_port", "WATER_port", "Chnaged To: WATER_port");
					Features::addVisOption("WATER_REF_malibu", "WATER_REF_malibu", "Chnaged To: WATER_REF_malibu");
					Features::addVisOption("WATER_refmap_high", "WATER_refmap_high", "Chnaged To: WATER_refmap_high");
					Features::addVisOption("WATER_refmap_hollywoodlake", "WATER_refmap_hollywoodlake", "Chnaged To: WATER_refmap_hollywoodlake");
					Features::addVisOption("WATER_refmap_low", "WATER_refmap_low", "Chnaged To: WATER_refmap_low");
					Features::addVisOption("WATER_refmap_med", "WATER_refmap_med", "Chnaged To: WATER_refmap_med");
					Features::addVisOption("WATER_refmap_off", "WATER_refmap_off", "Chnaged To: WATER_refmap_off");
					Features::addVisOption("WATER_refmap_poolside", "WATER_refmap_poolside", "Chnaged To: WATER_refmap_poolside");
					Features::addVisOption("WATER_refmap_silverlake", "WATER_refmap_silverlake", "Chnaged To: WATER_refmap_silverlake");
					Features::addVisOption("WATER_refmap_venice", "WATER_refmap_venice", "Chnaged To: WATER_refmap_venice");
					Features::addVisOption("WATER_refmap_verylow", "WATER_refmap_verylow", "Chnaged To: WATER_refmap_verylow");
					Features::addVisOption("WATER_resevoir", "WATER_resevoir", "Chnaged To: WATER_resevoir");
					Features::addVisOption("WATER_river", "WATER_river", "Chnaged To: WATER_river");
					Features::addVisOption("WATER_salton", "WATER_salton", "Chnaged To: WATER_salton");
					Features::addVisOption("WATER_salton_bottom", "WATER_salton_bottom", "Chnaged To: WATER_salton_bottom");
					Features::addVisOption("WATER_shore", "WATER_shore", "Chnaged To: WATER_shore");
					Features::addVisOption("WATER_silty", "WATER_silty", "Chnaged To: WATER_silty");
					Features::addVisOption("WATER_silverlake", "WATER_silverlake", "Chnaged To: WATER_silverlake");
					Features::addVisOption("whitenightlighting", "whitenightlighting", "Chnaged To: whitenightlighting");
					Features::addVisOption("WhiteOut", "WhiteOut", "Chnaged To: WhiteOut");
					Features::addVisOption("yell_tunnel_nodirect", "yell_tunnel_nodirect", "Chnaged To: yell_tunnel_nodirect");
				}
				break;
#pragma region ride
				case ride:
				{
					Menu::Title("Ride Bitch");
					// Menu::Subtitle("RIDE");

					if (Menu::Option("Stop Ride")) {
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						ENTITY::DETACH_ENTITY(playerPed, 1, 1);
						AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed);
					}
					if (Menu::Option("Ride Deer")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("a_c_deer");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
						//				SET_ENTITY_HEADING(createdPED, 180.0f);

						ENTITY::ATTACH_ENTITY_TO_ENTITY(playerPed, createdPED, -1, 0.0f, 0.35f, 0.72f, 0.0f, 0.0f, 0.0f, 1, 0, 0, 2, 1, 1);

						//deer animation
						char* anim = "creatures@deer@move";
						char* animID = "trot";

						STREAMING::REQUEST_ANIM_DICT(anim);
						while (!STREAMING::HAS_ANIM_DICT_LOADED(anim))
							WAIT(0);

						AI::TASK_PLAY_ANIM(createdPED, anim, animID, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);

						//charPose
						char* anim2 = "mp_safehouselost_table@";
						char* animID2 = "lost_table_negative_a";

						STREAMING::REQUEST_ANIM_DICT(anim2);
						while (!STREAMING::HAS_ANIM_DICT_LOADED(anim2))
							WAIT(0);

						AI::TASK_PLAY_ANIM(playerPed, anim2, animID2, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);

					}
					if (Menu::Option("Sit On Deer")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("a_c_deer");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
						//				SET_ENTITY_HEADING(createdPED, 180.0f);

						ENTITY::ATTACH_ENTITY_TO_ENTITY(playerPed, createdPED, -1, 0.0f, 0.35f, 0.72f, 0.0f, 0.0f, 0.0f, 1, 0, 0, 2, 1, 1);

						//charPose
						char* anim2 = "mp_safehouselost_table@";
						char* animID2 = "lost_table_negative_a";

						STREAMING::REQUEST_ANIM_DICT(anim2);
						while (!STREAMING::HAS_ANIM_DICT_LOADED(anim2))
							WAIT(0);

						AI::TASK_PLAY_ANIM(playerPed, anim2, animID2, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
					}
					if (Menu::Option("Ride Walking Deer")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("a_c_deer");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
						//				SET_ENTITY_HEADING(createdPED, 180.0f);

						ENTITY::ATTACH_ENTITY_TO_ENTITY(playerPed, createdPED, -1, 0.0f, 0.35f, 0.72f, 0.0f, 0.0f, 0.0f, 1, 0, 0, 2, 1, 1);

						//deer animation
						char* anim = "creatures@deer@move";
						char* animID = "walk";

						STREAMING::REQUEST_ANIM_DICT(anim);
						while (!STREAMING::HAS_ANIM_DICT_LOADED(anim))
							WAIT(0);

						AI::TASK_PLAY_ANIM(createdPED, anim, animID, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);

						//charPose
						char* anim2 = "mp_safehouselost_table@";
						char* animID2 = "lost_table_negative_a";

						STREAMING::REQUEST_ANIM_DICT(anim2);
						while (!STREAMING::HAS_ANIM_DICT_LOADED(anim2))
							WAIT(0);

						AI::TASK_PLAY_ANIM(playerPed, anim2, animID2, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
					}
					if (Menu::Option("Ride Cow")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("a_c_cow");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
						//				SET_ENTITY_HEADING(createdPED, 180.0f);

						ENTITY::ATTACH_ENTITY_TO_ENTITY(playerPed, createdPED, -1, 0.0f, 0.35f, 0.72f, 0.0f, 0.0f, 0.0f, 1, 0, 0, 2, 1, 1);

						//charPose
						char* anim2 = "mp_safehouselost_table@";
						char* animID2 = "lost_table_negative_a";

						STREAMING::REQUEST_ANIM_DICT(anim2);
						while (!STREAMING::HAS_ANIM_DICT_LOADED(anim2))
							WAIT(0);

						AI::TASK_PLAY_ANIM(playerPed, anim2, animID2, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
					}
				}
				break;

				case stealtremove:
				{
					Menu::Title("~w~Delete Noney");
					// Menu::Subtitle("DELETE MONEY");
					if (Menu::Int("Amount", Features::amount5, 0, 2147483647, 1000000))
					{

						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::amount5 = NumberKeyboard();
						}

					}

					if (Menu::Int("~w~Delay", Features::stealthDelaydel, 50, 1000))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::stealthDelaydel = NumberKeyboard();
						}
					}

					Menu::Toggle("Remove Money Bank", Features::sagtdegeiligeaufiwtion, [] { Features::weißernigger(Features::sagtdegeiligeaufiwtion); });

					Menu::Toggle("Remove Money Wallet", Features::etiennejoelsex, [] { Features::weißernigger(Features::etiennejoelsex); });



				}
				break;

				case SystemDrop:
				{
					Menu::Title("Money Stealth");
					// Menu::Subtitle("STEALTH CASH");

					Menu::Toggle("~w~Cash Drop", Features::MYDROP, [] { Features::mydrop(Features::MYDROP); });
					if (Menu::Int("Amount", Features::DropAmount, 1, 2500))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::DropAmount = NumberKeyboard();
						}
					}


					if (Menu::Int("Height", Features::DropHeight, 1, 50))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::DropHeight = NumberKeyboard();
						}
					}


					if (Menu::Int("Delay", Features::DropDelay, 50, 1000))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::DropDelay = NumberKeyboard();
						}
					}

					Menu::Int("Bags", Features::Bags, 0, 20);

					Menu::Break("Models");
					dropModelsSelect();
				}
				break;

				case stealth:
				{
					Menu::Title("Money Stealth");
					// Menu::Subtitle("STEALTH");

					Menu::MenuOption("Delete Money", stealtremove);
					Menu::MenuOption("Drop System", SystemDrop);

					Menu::Break(" Keyboard Method");

					Menu::Option("Press F9 for 15 Mil");

					Menu::Break(" Additional Stealth");

					Menu::Toggle("Add 2 Billion", Features::editmoney, [] { Features::MoneyEdit(Features::editmoney); });

					Menu::Toggle("Random Money", Features::randommon, [] { Features::randommonnn(Features::randommon); });


					Menu::Toggle("Add In Walllet", Features::geiletitte, [] { Features::weißernigger(Features::geiletitte); });

					Menu::Break(" Old School Stealth Method");

					Menu::Toggle("10Mil Stealth Loop", Features::stealthh, [] { Features::Stealthh(Features::stealthh); });
					Menu::Toggle("15Mil Stealth Loop", Features::toBank22, [] {(Features::StealthDropintee22); });

					Menu::Break(" Drop Method");

					Menu::Toggle("10K Ped Dropper", Features::ichwichsedireintommy, [] {Features::weißernigger(Features::ichwichsedireintommy); });
					Menu::Toggle("8 Mil Drop", Features::delop, [] {Features::lolop(Features::delop); });
					Menu::Toggle("2.5k Circle Drop", Features::dropme2, [] {Features::cashdrop23(Features::dropme2); });
					Menu::Toggle("Drop 2k alien Egg", Features::savenewdrop112, [] {Features::cashdrop112(Features::savenewdrop112); });
					Menu::Int("Bags", Features::Bags, 0, 20);
					Menu::Toggle("Money Self Drop 2k", Features::savenewdrop, [] {Features::cashdrop(Features::savenewdrop); });
					Menu::Toggle("Money Self Drop 2.5k", Features::savenewdrop3, [] {Features::cashdrop3(Features::savenewdrop3); });
					Menu::Toggle("Rain 2.5k", Features::rainMoney[Features::Online::selectedPlayer]);



				}
				break;

				case header:
				{
					Menu::Title("~w~Header");
					// Menu::Subtitle("HEADER");

					Menu::Int("Header Texture", Menu::Settings::titleRectTexture, 0, 6);

					if (Menu::Int("GIF Banner Delay", Features::bandelay, 1, 1000))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::bandelay = NumberKeyboard();
						}
					}
				}
				if (Menu::Option("Lifix Default")) {
					Menu::Settings::scrollerr = { 255, 255, 255, 255 };
					Menu::Settings::optionRect = { 0, 0, 0, 200 };
					Menu::Settings::scroller = { 255, 255, 255, 255 };
					Menu::Settings::titleEnd = { 0, 0, 0, 255 };
					Menu::Settings::Endrectlol = { 0, 0, 0, 255 };
					Menu::Settings::titleRectTexture = 0;
				}

				Menu::Settings::menuX = (float)menyooX / 100;
				Menu::Settings::menuWidth = (float)widthkek / 100;
				Menu::Settings::scrollbarWidthIndex = (float)(Menu::Settings::menuWidth / 2) + 0.01f;
				break;

				case hotti:
				{
					Menu::Title("~w~Header");
					// Menu::Subtitle("TELEPORTS");

					Menu::Option("Teleport Waypoint (F5)");

				}
				break;

				//Settings  Menu 
				case settingsmenu:
				{
					Menu::Title("~w~Settings");
					// Menu::Subtitle("SETTINGS");
					Menu::Option("Time Built : "  __TIMESTAMP__ );
					Menu::MenuOption("Header", header);
					Menu::Toggle("Toggle Center Text", nigger);
					Menu::Int("Move Menu X Position", menyooX, 15, 87);
					Menu::Int("Move Menu Y Position", menyooY, 0, 24);
					Menu::Int("Menu Width", widthkek, 11, 30);
					Menu::Toggle("Toggle Globe Header", Menu::Settings::GlareOnOff);
					Menu::Toggle("Toggle Controller Input", pickdick);
					if (Menu::Option("~r~Close GTA 5")) { exit(0); }
					if (Menu::Option("Enable DiscordRPC")) { DiscordMain(); }
					if (Menu::Option("Disable DiscordRPC")) { Shutdown(); }
					Menu::Settings::menuX = (float)menyooX / 100;
					Menu::Settings::menuY = (float)menyooY / 100;
					Menu::Settings::menuWidth = (float)widthkek / 100;
					Menu::Settings::scrollbarWidthIndex = (float)(Menu::Settings::menuWidth / 2) + 0.01f;
				}
				break;
				case settingstheme:
				{
					Menu::Title("Colors");
					// Menu::Subtitle("UI SETTINGS");

					Menu::Toggle("Display FPS", Features::DisplayFPS, [] { Features::featureDisplayFPS(Features::DisplayFPS); });
					Menu::MenuOption("Header", settingstitlerect);
					Menu::MenuOption("Infobar", settingstitleEnd);
					Menu::MenuOption("Footer", settingsfooterarroww);
					Menu::MenuOption("Scroller", settingsscroller);
					Menu::MenuOption("Option Background", settingsoptionrect);
					Menu::MenuOption("HUD Color", sex);
					if (Menu::Int("Scroll Delay", Menu::Settings::keyPressDelay2, 1, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::keyPressDelay2 = NumberKeyboard();
						}
					}
					if (Menu::Int("Int Delay", Menu::Settings::keyPressDelay3, 1, 200))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::keyPressDelay3 = NumberKeyboard();
						}
					}
					Menu::Toggle("Rainbow Menu", Features::rainbowmenu, [] { Features::Rainbowmenu(Features::rainbowmenu); });
					Menu::Settings::menuX = (float)menyooX / 100;
					Menu::Settings::menuWidth = (float)widthkek / 100;
					Menu::Settings::scrollbarWidthIndex = (float)(Menu::Settings::menuWidth / 2) + 0.01f;



				}
				break;
				case settingsoptionrect:
				{
					Menu::Title("Title Rect");
					// Menu::Subtitle("OPTION RECT");

					if (Menu::Int("Red", Menu::Settings::optionRect.r, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::optionRect.r = NumberKeyboard();
						}
					}
					if (Menu::Int("Green", Menu::Settings::optionRect.g, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::optionRect.g = NumberKeyboard();
						}
					}
					if (Menu::Int("Blue", Menu::Settings::optionRect.b, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::optionRect.b = NumberKeyboard();
						}
					}
					if (Menu::Int("Opacity", Menu::Settings::optionRect.a, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::optionRect.a = NumberKeyboard();
						}
					}
				}
				break;
				case settingstitlerect:
				{
					Menu::Title("Title Rect");
					// Menu::Subtitle("TITLE RECT");

					if (Menu::Int("Red", Menu::Settings::titleRect.r, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::titleRect.r = NumberKeyboard();
						}
					}
					if (Menu::Int("Green", Menu::Settings::titleRect.g, 255, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::titleRect.g = NumberKeyboard();
						}
					}
					if (Menu::Int("Blue", Menu::Settings::titleRect.b, 255, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::titleRect.b = NumberKeyboard();
						}
					}
					if (Menu::Int("Opacity", Menu::Settings::titleRect.a, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::titleRect.a = NumberKeyboard();
						}
					}
				}
				break;
				case sex:
				{
					Menu::Title("~w~GuardCheats ~w~VIP");
					// Menu::Subtitle("HUD CHANGER");





					Menu::Break("HUD_COLOUR_PAUSE_BG");
					if (Menu::Int("R", HUD_COLOUR_PAUSE_BGR, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_PAUSE_BGR = NumberKeyboard();
						}
					}
					if (Menu::Int("G", HUD_COLOUR_PAUSE_BGG, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_PAUSE_BGG = NumberKeyboard();
						}
					}
					if (Menu::Int("B", HUD_COLOUR_PAUSE_BGB, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_PAUSE_BGB = NumberKeyboard();
						}
					}
					if (Menu::Int("A", HUD_COLOUR_PAUSE_BGA, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_PAUSE_BGA = NumberKeyboard();
						}
					}
					if (Menu::Option("Set")) {
						UI::_SET_HUD_COLOUR(HUD_COLOUR_PAUSE_BG, HUD_COLOUR_PAUSE_BGR, HUD_COLOUR_PAUSE_BGG, HUD_COLOUR_PAUSE_BGB, HUD_COLOUR_PAUSE_BGA);
					}
					Menu::Break("HUD_COLOUR_WAYPOINT");
					if (Menu::Int("R", HUD_COLOUR_WAYPOINTR, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_WAYPOINTR = NumberKeyboard();
						}
					}
					if (Menu::Int("G", HUD_COLOUR_WAYPOINTG, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_WAYPOINTG = NumberKeyboard();
						}
					}
					if (Menu::Int("B", HUD_COLOUR_WAYPOINTB, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_WAYPOINTB = NumberKeyboard();
						}
					}
					if (Menu::Int("A", HUD_COLOUR_WAYPOINTA, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_WAYPOINTA = NumberKeyboard();
						}
					}
					if (Menu::Option("Set")) {
						UI::_SET_HUD_COLOUR(HUD_COLOUR_WAYPOINT, HUD_COLOUR_WAYPOINTR, HUD_COLOUR_WAYPOINTG, HUD_COLOUR_WAYPOINTB, HUD_COLOUR_WAYPOINTA);
					}
					Menu::Break("HUD_COLOUR_MICHAEL");
					if (Menu::Int("R", HUD_COLOUR_MICHAELR, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_MICHAELR = NumberKeyboard();
						}
					}
					if (Menu::Int("G", HUD_COLOUR_MICHAELG, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_MICHAELG = NumberKeyboard();
						}
					}
					if (Menu::Int("B", HUD_COLOUR_MICHAELB, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_MICHAELB = NumberKeyboard();
						}
					}
					if (Menu::Int("A", HUD_COLOUR_MICHAELA, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_MICHAELA = NumberKeyboard();
						}
					}
					if (Menu::Option("Set")) {
						UI::_SET_HUD_COLOUR(HUD_COLOUR_MICHAEL, HUD_COLOUR_MICHAELR, HUD_COLOUR_MICHAELG, HUD_COLOUR_MICHAELB, HUD_COLOUR_MICHAELA);
					}
					Menu::Break("HUD_COLOUR_FRANKLIN");
					if (Menu::Int("R", HUD_COLOUR_FRANKLINR, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_FRANKLINR = NumberKeyboard();
						}
					}
					if (Menu::Int("G", HUD_COLOUR_FRANKLING, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_FRANKLING = NumberKeyboard();
						}
					}
					if (Menu::Int("B", HUD_COLOUR_FRANKLINB, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_FRANKLINB = NumberKeyboard();
						}
					}
					if (Menu::Int("A", HUD_COLOUR_FRANKLINA, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_FRANKLINA = NumberKeyboard();
						}
					}
					if (Menu::Option("Set")) {
						UI::_SET_HUD_COLOUR(HUD_COLOUR_FRANKLIN, HUD_COLOUR_FRANKLINR, HUD_COLOUR_FRANKLING, HUD_COLOUR_FRANKLINB, HUD_COLOUR_FRANKLINA);
					}
					Menu::Break("HUD_COLOUR_TREVOR");
					if (Menu::Int("R", HUD_COLOUR_TREVORR, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_TREVORR = NumberKeyboard();
						}
					}
					if (Menu::Int("G", HUD_COLOUR_TREVORG, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_TREVORG = NumberKeyboard();
						}
					}
					if (Menu::Int("B", HUD_COLOUR_TREVORB, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_TREVORB = NumberKeyboard();
						}
					}
					if (Menu::Int("A", HUD_COLOUR_TREVORA, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_TREVORA = NumberKeyboard();
						}
					}
					if (Menu::Option("Set")) {
						UI::_SET_HUD_COLOUR(HUD_COLOUR_TREVOR, HUD_COLOUR_TREVORR, HUD_COLOUR_TREVORG, HUD_COLOUR_TREVORB, HUD_COLOUR_TREVORA);
					}
					Menu::Break("HUD_COLOUR_FREEMODE");
					if (Menu::Int("R", HUD_COLOUR_FREEMODER, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_FREEMODER = NumberKeyboard();
						}
					}
					if (Menu::Int("G", HUD_COLOUR_FREEMODEG, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_FREEMODEG = NumberKeyboard();
						}
					}
					if (Menu::Int("B", HUD_COLOUR_FREEMODEB, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_FREEMODEB = NumberKeyboard();
						}
					}
					if (Menu::Int("A", HUD_COLOUR_FREEMODEA, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							HUD_COLOUR_FREEMODEA = NumberKeyboard();
						}
					}
					if (Menu::Option("Set")) {
						UI::_SET_HUD_COLOUR(HUD_COLOUR_FREEMODE, HUD_COLOUR_FREEMODER, HUD_COLOUR_FREEMODEG, HUD_COLOUR_FREEMODEB, HUD_COLOUR_FREEMODEA);
					}


				}
				break;

				case settingsoptiontext:
				{
					Menu::Title("Option Text");
					// Menu::Subtitle("OPTION TEXT");

					if (Menu::Int("Red", Menu::Settings::optionText.r, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::optionText.r = NumberKeyboard();
						}
					}
					if (Menu::Int("Green", Menu::Settings::optionText.g, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::optionText.g = NumberKeyboard();
						}
					}
					if (Menu::Int("Blue", Menu::Settings::optionText.b, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::optionText.b = NumberKeyboard();
						}
					}
					if (Menu::Int("Opacity", Menu::Settings::optionText.a, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::optionText.a = NumberKeyboard();
						}
					}
					Menu::MenuOption("Font", font);
				}
				break;
				case font:
				{
					Menu::Title("Font");
					// Menu::Subtitle("FONTS");

					if (Menu::Option("Chalet London")) { Menu::Settings::optionText.f = 0; }
					if (Menu::Option("House Script")) { Menu::Settings::optionText.f = 1; }
					if (Menu::Option("Monospace")) { Menu::Settings::optionText.f = 2; }
					if (Menu::Option("Wing Dings")) { Menu::Settings::optionText.f = 3; }
					if (Menu::Option("Chalet Comprime Cologne")) { Menu::Settings::optionText.f = 4; }
					if (Menu::Option("Pricedown")) { Menu::Settings::optionText.f = 7; }
				}
				break;
				case settingsscroller:
				{
					Menu::Title("Scroller");
					// Menu::Subtitle("SCROLLER");

					if (Menu::Int("Red", Menu::Settings::scroller.r, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::scroller.r = NumberKeyboard();
						}
					}
					if (Menu::Int("Green", Menu::Settings::scroller.g, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::scroller.g = NumberKeyboard();
						}
					}
					if (Menu::Int("Blue", Menu::Settings::scroller.b, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::scroller.b = NumberKeyboard();
						}
					}
					if (Menu::Int("Opacity", Menu::Settings::scroller.a, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Menu::Settings::scroller.a = NumberKeyboard();
						}
					}
				}
				break;

				//Protections 
				case protection:
				{

					Menu::Title("Protection Option");
					// Menu::Subtitle("PROTECTIONS");
					Menu::Toggle("Anti AFK", Features::isAntiAFK, [] { Features::antiAFK(Features::isAntiAFK); });
					Menu::Toggle("Change Session Weather Protection", md22, [] {
						Hooking::defuseEvent(RockstarEvent::GAME_CLOCK_EVENT, md22);
						Hooking::defuseEvent(RockstarEvent::GAME_WEATHER_EVENT, md22);
						});
					Menu::Toggle("Anti bounty", Features::Bounty, [] { Features::Bountyy(Features::Bounty); });
					Menu::Toggle("Anti Sound Spam", Features::SoundSpamProtection, [] { Features::Spamp(Features::SoundSpamProtection); });
					Menu::Toggle("Anti Send Job", Features::SendToJobProtection, [] { Features::STJp(Features::SendToJobProtection); });
					Menu::Toggle("Anti Teleport", Features::tpp, [] { Features::Teleportprotec(Features::tpp); });
					Menu::Toggle("Anti Ceo Ban", Features::CeoBanProtection, [] { Features::CEOBanp(Features::CeoBanProtection); });
					Menu::Toggle("Anti Ceo Kick", Features::CEOKickProtection, [] { Features::CEOKickp(Features::CEOKickProtection); });
					Menu::Toggle("Anti Transaction Spam", Features::trns, [] { Features::remore(Features::trns); });
					Menu::Toggle("Anti Kick", Features::kickp, [] { Features::Kickprotec(Features::kickp); });
					Menu::Toggle("Anti Rotate cam", Features::new1, [] { Features::new11(Features::new1); });
					Menu::Toggle("Anti kick from car", Features::new2, [] { Features::new22(Features::new2); });
					Menu::Toggle("Anti Notification", Features::new3, [] { Features::new33(Features::new3); });
					Menu::Toggle("Anti Money Drop", Features::moneyDropProtection);
					/*Menu::Toggle("Anti Freeze", antiFreeze, [] { Hooking::defuseEvent(RockstarEvent::NETWORK_CLEAR_PED_TASKS_EVENT, antiFreeze); });
					Menu::Toggle("Anti Explosion", ev, [] { Hooking::defuseEvent(RockstarEvent::EXPLOSION_EVENT, ev); });
					Menu::Toggle("Anti Pickup", rpe, [] { Hooking::defuseEvent(RockstarEvent::REQUEST_PICKUP_EVENT, rpe); });
					Menu::Toggle("Fire Protection ", fe, [] { Hooking::defuseEvent(RockstarEvent::EXPLOSION_EVENT, fe); });
					Menu::Toggle("Anti Kick", ak, [] { Hooking::defuseEvent(RockstarEvent::KICK_VOTES_EVENT, ak); });
					Menu::Toggle("Anti Kick 2", AntiKick2, [] { Hooking::defuseEvent(REMOTE_SCRIPT_LEAVE_EVENT, AntiKick2); });
					Menu::Toggle("Anti Ragdoll", protecc3, [] { Hooking::defuseEvent(RockstarEvent::RAGDOLL_REQUEST_EVENT, protecc3); });
					Menu::Toggle("Anti PTFX", protecc2, [] { Hooking::defuseEvent(RockstarEvent::NETWORK_PTFX_EVENT, protecc2); });
					Menu::Toggle("Anti Remove Weapons", noRemoveWeps, [] { Hooking::defuseEvent(RockstarEvent::REMOVE_ALL_WEAPONS_EVENT, noRemoveWeps); });
					Menu::Toggle("Anti Give Weapons", noGiveWeps, [] { Hooking::defuseEvent(RockstarEvent::GIVE_WEAPON_EVENT, noGiveWeps); });
					Menu::Toggle("Report Money Drop Event", md, [] { Hooking::defuseEvent(RockstarEvent::REPORT_CASH_SPAWN_EVENT, md); });*/
				}
				break;



				//Settings Menu 2 
				case settingsmenu_theme:
				{
					Menu::Title("Menu Desgin");
					// Menu::Subtitle("MENU DESIGIN");


					Menu::MenuOption("Title Text", settingsmenu_theme_titletext);
					Menu::MenuOption("Title Rect", settingsmenu_theme_titlerect);
					Menu::MenuOption("Option Text", settingsmenu_theme_optiontext);
					Menu::MenuOption("Option Rect", settingsmenu_theme_optionrect);
					Menu::MenuOption("Scroller", settingsmenu_theme_scroller);
				}
				break;
				case acrobatic:
				{
					Menu::Title("Vehicle Acrobatic");
					// Menu::Subtitle("ACROBATICS");

					if (Menu::Option("Front Flip")) {
						int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
						ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 6.0f, 0, -2.0f, 0, true, true, true, true, false, true);
					}
					if (Menu::Option("Back Flip")) {
						int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
						ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 6.0f, 0, 2.0f, 0, true, true, true, true, false, true);
					}
					if (Menu::Option("Kick Flip")) {
						int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
						ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 5.0f, 2.0f, 0, 0, true, true, true, true, false, true);
					}
					if (Menu::Option("Heel Flip")) {
						int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
						ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 5.0f, -2.0f, 0, 0, true, true, true, true, false, true);
					}
					if (Menu::Option("Bunny Hop")) {
						int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
						ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 7.0f, 0, 0, 0, true, true, true, true, false, true);
					}
					if (Menu::Option("Launch Up")) {
						int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
						ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 40.0f, 0, 0, 0, true, true, true, true, false, true);
					}
					if (Menu::Option("Crush Vehicle")) {
						int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
						ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, -40.0f, 0, 0, 0, true, true, true, true, false, true);
					}

				}
				break;

				case windowsceh:
				{
					Menu::Title("Window Options");
					// Menu::Subtitle("WINDOW OPTIONS");

					if (Menu::Option("Remove Vehicle Windows"))
					{
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
						VEHICLE::REMOVE_VEHICLE_WINDOW(veh, false);
					}

					Menu::Break(" Roll Windows");

					if (Menu::Option("Roll down Window"))
					{
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
						VEHICLE::ROLL_DOWN_WINDOW(veh, false);
					}
					if (Menu::Option("Roll up Window"))
					{
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
						VEHICLE::ROLL_UP_WINDOW(veh, false);
					}
				}
				break;

				case cargoop:
				{
					Menu::Title("helicopter bombers");
					// Menu::Subtitle("CARGOBOB");

					Menu::Toggle("~g~Activate ~w~cargobob tightening", Features::magnetbool, [] { Features::magnetActive(Features::magnetbool); });

					for (auto car : CARGOBOB) { Menu::Option(car, [car] { Features::autovehi(car); }); }


					if (Menu::Option("~b~Create ~w~Magnet"))
					{
						Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
						Hash vehHash = ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
						if (vehHash == 0xFCFCB68B || vehHash == 4244420235 || vehHash == -50547061) {
							Vehicle cargobob = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
							VEHICLE::CREATE_PICK_UP_ROPE_FOR_CARGOBOB(cargobob, 1);
							VEHICLE::_SET_CARGOBOB_PICKUP_MAGNET_STRENGTH(cargobob, 999.0f);
						}
						else {
							notifyBottom("~r~You're not in a Cargobob.");

						}
					}

					if (Menu::Option("~r~Remove ~w~Magnet"))
					{
						VEHICLE::REMOVE_PICK_UP_ROPE_FOR_CARGOBOB(0);


					}

					/*if (Menu::Option("--"))
					{
						Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
						Hash vehHash = ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
						if (vehHash == 0xFCFCB68B || vehHash == 4244420235 || vehHash == -50547061) {
							Vehicle cargobob = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
							VEHICLE::CREATE_PICK_UP_ROPE_FOR_CARGOBOB(cargobob, 0);
						}
						else {
							notifyMap("You're not in a Cargobob.");
						}
					}*/

				}
				break;

				case bomber:
				{
					Menu::Title("helicopter bombers");
					// Menu::Subtitle("HELICOPTER BOMBER");

					Menu::Toggle("Activate bombers", Features::bomber, [] { Features::bomber_mode(Features::bomber); });


					if (Menu::Int("~r~Red", Features::rt, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::rt = NumberKeyboard();
						}
					}

					if (Menu::Int("~g~Green", Features::rrt, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::rrt = NumberKeyboard();
						}
					}

					if (Menu::Int("~b~Blue", Features::rrrt, 0, 255))
					{
						if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
							Features::rrrt = NumberKeyboard();
						}
					}



					if (Menu::Int("Typ", Features::Explosionfickk, 1, 38))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::Explosionfickk = NumberKeyboard();
						}
					}


					if (Menu::Int("Size", Features::ficksizee, 1, 10))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::ficksizee = NumberKeyboard();
						}
					}

					if (Menu::ListVector("Helicopters", Helicopters1, soutprop12)) {
						Features::autovehi(Helicopters1[soutprop12]);
					}

				}
				break;

				case movementveh:
				{
					Menu::Title("Vehicle Options");
					// Menu::Subtitle("MOVEMENT");
					Menu::Toggle("Backboost ", Features::Backboost, [] { Features::backboost(Features::Backboost); });
					Menu::Toggle("Vehicle Fly ", Features::vehicleflybool, [] { Features::vehiclefly(Features::vehicleflybool); });
					Menu::MenuOption("PTFX Vehicle", ptfxveh);
					Menu::MenuOption("Weapons", VehWeapon);
					if (Menu::Int("Delay", Features::Horndelay, 50, 1000))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::Horndelay = NumberKeyboard();
						}
					}
				}
				break;
				case vehicle:
				{
					Menu::Title("Vehicle Options");
					// Menu::Subtitle("Vehicle Options");
					Menu::MenuOption("Vehicle LSC", lsc1);
					Menu::MenuOption("Vehicle Handling", movementveh);
					Menu::MenuOption("Vehicle Acrobatics", acrobatic);
					if (Menu::Toggle("Vehicle Godmode", Features::cargodmodebool)) { Features::cargodmode(); }
					Menu::Toggle("Horn Boost", Features::boostbool, [] { Features::carboost(Features::boostbool); });
					Menu::Toggle("No Bike Fall", Features::bikeNoFall);
					Menu::Toggle("Speedo", Features::Speedometerbool, [] { Features::Speedometer(Features::Speedometerbool); });
					if (Menu::Option("Fix Vehicle")) {
						uint Vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
						VEHICLE::SET_VEHICLE_FIXED(Vehicle);
						VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(Vehicle);
						VEHICLE::SET_VEHICLE_DIRT_LEVEL(Vehicle, 0);
					}
					if (Menu::Option("Flip")) {
						Features::flipup();
					}
					if (Menu::Option("Fully Tune")) {
						Features::maxvehicle();
					}
					Menu::Toggle("Fade Rainbow", Features::rlbool, [] { Features::HasPaintLoop(Features::rlbool); });
					if (Menu::Option("~w~Vehicle Jump [Press]")) {
						if ((VK_SPACE) && PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
							Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
							ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0 + ENTITY::GET_ENTITY_FORWARD_X(veh), 0 + ENTITY::GET_ENTITY_FORWARD_Y(veh), 7, 0, 0, 0, 1, 0, 1, 1, 1, 1);
						}
					}
					Menu::Toggle("Drive on Water", Features::dowbool, [] { Features::DriveOnWater(Features::dowbool); });


					if (Menu::Option("~w~Custom Plate")) {
						Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						RequestControlOfEnt(veh);
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, CharKeyboard());
					}
					if (Menu::Int("Alpha", Menu::Settings::alpha, 0, 255))
					{
						int VehicleID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true);
						ENTITY::SET_ENTITY_ALPHA(VehicleID, Menu::Settings::alpha, false);
					}
				}
				break;


				case FeaturesS: {
					{
						Menu::Title("~w~Special Fetaures");
						// Menu::Subtitle("SPECIAL");

						Menu::Toggle("Rockstars RP Bonus", globalHandle(0x40001 + 0x1284).As<bool>());
						Menu::Toggle("SP Bypass", globalHandle(4266905).As<bool>());
						Menu::Toggle("Snow", globalHandle(0x40001 + 0x1271).As<bool>());
						Menu::Toggle("Xmas Content", globalHandle(0x40001 + 0x127C).As<bool>());

						Menu::Toggle("Valentine 2016 Clothing", globalHandle(0x40001 + 0x2FD9).As<bool>());
						Menu::Toggle("Valentine 2016 Vehicle", globalHandle(0x40001 + 0x2FDA).As<bool>());
						Menu::Toggle("Valentine Weapon", globalHandle(0x40001 + 0x2A90).As<bool>());
						Menu::Toggle("Valentine Vehicle", globalHandle(0x40001 + 0x2A91).As<bool>());
						Menu::Toggle("Valentine Masks", globalHandle(0x40001 + 0x2A92).As<bool>());
						Menu::Toggle("Valentine Hair", globalHandle(0x40001 + 0x2A93).As<bool>());
						Menu::Toggle("Valentine Clothing", globalHandle(0x40001 + 0x2A94).As<bool>());
						Menu::Toggle("Be My Valentine", globalHandle(0x40001 + 0x300D).As<bool>());
						Menu::Toggle("Valentine Event", globalHandle(0x40001 + 0x1766).As<bool>());

						Menu::Toggle("Halloween Sounds", globalHandle(0x40001 + 0x2D2F).As<bool>());
						Menu::Toggle("Halloween Anims", globalHandle(0x40001 + 0x2AAD).As<bool>());
						Menu::Toggle("Halloween Weapons", globalHandle(0x40001 + 0x2AA6).As<bool>());

					}
					break;

					//Spawn Vehicle 
				case vehspawnerr: {
					Menu::Title("~w~Vehicle Spawner for All");
					// Menu::Subtitle("");

					Menu::Toggle("Spawn in Car", Features::spawnincar);
					Menu::Toggle("Spawn Maxed", Features::spawnmaxed);

					Menu::Toggle("SP Bypass", globalHandle(4266905).As<bool>());

					if (Menu::Option("Spawn Ramp Truck")) {

						int Handle = PLAYER::PLAYER_PED_ID();
						Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(Handle, 1);
						Vector3 null; null.x = 0, null.y = 0; null.z = 0;
						Vector3 a; a.x = 0, a.y = -0.4f, a.z = 0.1f;
						Vector3 b; b.x = 0, b.y = 0, b.z = 180;
						int hash = GAMEPLAY::GET_HASH_KEY("monster");
						int hash2 = GAMEPLAY::GET_HASH_KEY("prop_jetski_ramp_01");
						STREAMING::REQUEST_MODEL(hash);
						STREAMING::REQUEST_MODEL(hash2);
						if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
						{
							int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, 1, 1, 1);
							if (ENTITY::DOES_ENTITY_EXIST(Object))
							{
								int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
								if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
								{
									PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
									STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
									ENTITY::SET_ENTITY_VISIBLE(Vehicle, 1, 1);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, 4.5, 0.1, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
									ENTITY::SET_ENTITY_VISIBLE(Object, true, false);
									ENTITY::SET_ENTITY_COLLISION(Object, true, false);

								}

							}

						}

					}
				}
								break;
				case dlc_summerspecial2020:
					Menu::Title("SUMMER SPECIAL");
					// Menu::Subtitle(".");
					for (auto car : summerspecial) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Doomsdayy:
					Menu::Title("Doomsday");
					// Menu::Subtitle(".");
					for (auto car : Doomsday1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case SuperSportss:
					Menu::Title("SOUTHERNSAN");
					// Menu::Subtitle(".");
					//for (auto car : SOUTHERNSAN) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Superr:
					Menu::Title("Super");
					// Menu::Subtitle(".");
					for (auto car : Super1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Sportss:
					Menu::Title("Sports");
					// Menu::Subtitle(".");
					for (auto car : Sports1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case SportClassicc:
					Menu::Title("Sports Classic");
					// Menu::Subtitle(".");
					for (auto car : SportsClassics1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Offroadd:
					Menu::Title("Offroad");
					// Menu::Subtitle(".");
					for (auto car : OffRoad1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Sedanss:
					Menu::Title("Sedans");
					// Menu::Subtitle(".");
					for (auto car : Sedans1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Coupess:
					Menu::Title("Coupes");
					// Menu::Subtitle(".");
					for (auto car : Coupes1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Musclee:
					Menu::Title("Muscle");
					// Menu::Subtitle(".");
					for (auto car : Muscle1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Boatss:
					Menu::Title("Boats");
					// Menu::Subtitle(".");
					for (auto car : Boats1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Commerciall:
					Menu::Title("Commercial");
					// Menu::Subtitle(".");
					for (auto car : Commercial1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Compactss:
					Menu::Title("Compacts");
					// Menu::Subtitle(".");
					for (auto car : Compacts1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Cycless:
					Menu::Title("Cycles");
					// Menu::Subtitle(".");
					for (auto car : Cycles1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Emergencyy:
					Menu::Title("Emergency");
					// Menu::Subtitle("~w~Build: 2.6        ~HUD_COLOUR_GOLD~PRIME           ");
					for (auto car : Emergency1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Helicopterss:
					Menu::Title("Helicopters");
					// Menu::Subtitle(".");
					for (auto car : Helicopters1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Industriall:
					Menu::Title("Industrial");
					// Menu::Subtitle(".");
					for (auto car : Industrial1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Militaryy:
					Menu::Title("Military");
					// Menu::Subtitle(".");
					for (auto car : Military1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Motorcycless:
					Menu::Title("Motorcycles");
					// Menu::Subtitle(".");
					for (auto car : Motorcycles1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Planess:
					Menu::Title("Planes");
					// Menu::Subtitle(".");
					for (auto car : Planes1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
					/*case Servicee:
						Menu::Title("Service");
						// Menu::Subtitle(".");
						for (auto car : Service1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
						break;*/
				case SUVv:
					Menu::Title("SUV");
					// Menu::Subtitle(".");
					for (auto car : SUVs1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Trailerr:
					Menu::Title("Trailer");
					// Menu::Subtitle(".");
					for (auto car : Trailer1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Trainss:
					Menu::Title("Trains");
					// Menu::Subtitle(".");
					for (auto car : Trains1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Utilityy:
					Menu::Title("Utility");
					// Menu::Subtitle(".");
					for (auto car : Utility1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				case Vanss:
					Menu::Title("Vans");
					// Menu::Subtitle(".");
					for (auto car : Vans1) { Menu::Option(car, [car] { Features::autovehi22(car); }); }
					break;
				}
							  break;




							  //Spawn Vehicle 
				case vehspawner: {
					Menu::Title("~w~Vehicle Spawner");
					// Menu::Subtitle("SPAWNER");

					Menu::Toggle("Spawn in Car", Features::spawnincar);
					Menu::Toggle("Spawn Maxed", Features::spawnmaxed);
					Menu::Toggle("SP Bypass", globalHandle(4266905).As<bool>());
					if (Menu::Option("Input name")) {
						GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "", "", "", "", "", "", 100);
						while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
						Features::autovehi(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
					}
					if (Menu::Option("Delete Last Vehicle"))
					{
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false))
						{
							int Vehicle = PED::GET_VEHICLE_PED_IS_USING(playerPed);
							if (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Vehicle))
								while (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Vehicle));

							ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Vehicle, 1, 1);
							VEHICLE::DELETE_VEHICLE(&Vehicle);
						}
					}

					if (Menu::Option("Teleport In Last Car")) {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYERS_LAST_VEHICLE(), -1);
						Features::PTFXCALL("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears");

					}
					if (Menu::Option("Teleport Personal Vehicle to me")) {
						Vector3 CoordBlip = UI::GET_BLIP_INFO_ID_COORD(UI::GET_FIRST_BLIP_INFO_ID(225));
						int VehicleHandle = VEHICLE::GET_CLOSEST_VEHICLE(CoordBlip.x, CoordBlip.y, CoordBlip.z, 1, 0, 71);
						if (VehicleHandle == 0) {
							Vector3 CoordBlipMoto = UI::GET_BLIP_INFO_ID_COORD(UI::GET_FIRST_BLIP_INFO_ID(226));
							int VehicleHandleMoto = VEHICLE::GET_CLOSEST_VEHICLE(CoordBlip.x, CoordBlip.y, CoordBlip.z, 1, 0, 71);
							if (VehicleHandleMoto == 0) {
								notifyMap("Could not find personal vehicle.");
							}
							else {
								Vector3 me = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
								ENTITY::SET_ENTITY_COORDS(VehicleHandleMoto, me.x, me.y + 2, me.z, 1, 1, 1, 1);
							}
						}
						else {
							Vector3 me = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
							ENTITY::SET_ENTITY_COORDS(VehicleHandle, me.x, me.y + 2, me.z, 1, 1, 1, 1);
						}
						Features::PTFXCALL("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears");

					}
					if (Menu::StringVector("Summer special", summerspecial, soutprop70)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(summerspecial[soutprop70]);
					}
					if (Menu::StringVector("ArenaWars", Arenawars, soutprop34)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Arenawars[soutprop34]);
					}
					if (Menu::StringVector("Afterhours", Afterhours1, soutprop30)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Afterhours1[soutprop30]);
					}

					if (Menu::StringVector("Southersan", SOUTHERNSAN, soutprop)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(SOUTHERNSAN[soutprop]);
					}

					if (Menu::StringVector("Smugglers", SMUGLERSRUN1, soutprop2)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(SMUGLERSRUN1[soutprop2]);
					}

					if (Menu::StringVector("Doomsday", Doomsday1, soutprop29)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Doomsday1[soutprop29]);
					}

					if (Menu::StringVector("Super", Super1, soutprop23)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Super1[soutprop23]);
					}

					if (Menu::StringVector("Sports", Sports1, soutprop21)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Sports1[soutprop21]);
					}

					if (Menu::StringVector("Sport Classic", SportsClassics1, soutprop22)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(SportsClassics1[soutprop22]);
					}

					if (Menu::StringVector("Offroad", OffRoad1, soutprop17)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(OffRoad1[soutprop17]);
					}

					if (Menu::StringVector("Sedans", Sedans1, soutprop19)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Sedans1[soutprop19]);
					}

					if (Menu::StringVector("Coupes", Coupes1, soutprop9)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Coupes1[soutprop9]);
					}

					if (Menu::StringVector("Muscle", Muscle1, soutprop16)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Muscle1[soutprop16]);
					}

					if (Menu::StringVector("Boats", Boats1, soutprop6)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Boats1[soutprop6]);
					}

					if (Menu::StringVector("Commercial", Commercial1, soutprop7)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Commercial1[soutprop7]);
					}

					if (Menu::StringVector("Compacts", Compacts1, soutprop6)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Compacts1[soutprop6]);
					}

					if (Menu::StringVector("Cycles", Cycles1, soutprop10)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Cycles1[soutprop10]);
					}

					if (Menu::StringVector("Emergency", Emergency1, soutprop11)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Emergency1[soutprop11]);
					}

					if (Menu::StringVector("Helicopters", Helicopters1, soutprop12)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Helicopters1[soutprop12]);
					}

					if (Menu::StringVector("Industrial", Industrial1, soutprop13)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Industrial1[soutprop13]);
					}

					if (Menu::StringVector("Military", Military1, soutprop14)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Military1[soutprop14]);
					}

					if (Menu::StringVector("Motorcycles", Motorcycles1, soutprop15)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Motorcycles1[soutprop15]);
					}

					if (Menu::StringVector("Planes", Planes1, soutprop18)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Planes1[soutprop18]);
					}

					if (Menu::StringVector("Service", Service1, soutprop20)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Service1[soutprop20]);
					}

					if (Menu::StringVector("SUV", SUVs1, soutprop24)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(SUVs1[soutprop24]);
					}

					if (Menu::StringVector("Trailer", Trailer1, soutprop25)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Trailer1[soutprop25]);
					}

					if (Menu::StringVector("Trains", Trains1, soutprop26)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Trains1[soutprop26]);
					}

					if (Menu::StringVector("Utility", Utility1, soutprop27)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Utility1[soutprop27]);
					}

					if (Menu::StringVector("Vans", Vans1, soutprop28)) {
						if (GetAsyncKeyState(VK_RETURN))
							Features::autovehi(Vans1[soutprop28]);
					}
					// 10 done xd
					if (Menu::Settings::currentOption == 9)
						Menu::Vehicle(stream_AfterHours[soutprop30], AfterHours[soutprop30]);

					if (Menu::Settings::currentOption == 11)
						Menu::Vehicle(stream_Assault[soutprop], Assault[soutprop]);

					if (Menu::Settings::currentOption == 11)
						Menu::Vehicle(stream_Smugglers[soutprop2], Smugglers[soutprop2]);

					if (Menu::Settings::currentOption == 14)
						Menu::Vehicle(stream_Supper[soutprop23], Super1[soutprop23]);

					if (Menu::Settings::currentOption == 30)
						Menu::Vehicle(stream_Service[soutprop20], Service1[soutprop20]);

					if (Menu::Settings::currentOption == 14)
						Menu::Vehicle(stream_Sports[soutprop20], Sports1[soutprop21]);

					if (Menu::Settings::currentOption == 27)
						Menu::Vehicle(stream_Militär[soutprop14], Military1[soutprop14]);

					/*Menu::MenuOption("Afterhours", after);
					Menu::MenuOption("Southersan", SuperSports);
					Menu::MenuOption("Doomsday ~v~", Doomsday);
					Menu::MenuOption("Super", Super);
					Menu::MenuOption("Sports", Sports);
					Menu::MenuOption("Sport Classic", SportClassic);
					Menu::MenuOption("Offroad", Offroad);
					Menu::MenuOption("Sedans", Sedans);
					Menu::MenuOption("Coupes", Coupes);
					Menu::MenuOption("Muscle", Muscle);
					Menu::MenuOption("Boats", Boats);
					Menu::MenuOption("Commercial", Commercial);
					Menu::MenuOption("Compacts", Compacts);
					Menu::MenuOption("Cycles", Cycles);
					Menu::MenuOption("Emergency", Emergency);
					Menu::MenuOption("Helicopters", Helicopters);
					Menu::MenuOption("Industrial", Industrial);
					Menu::MenuOption("Military", Military);
					Menu::MenuOption("Motorcycles", Motorcycles);
					Menu::MenuOption("Planes", Planes);
					Menu::MenuOption("Service", Service);
					Menu::MenuOption("SUV", SUV);
					Menu::MenuOption("Trailer", Trailer);
					Menu::MenuOption("Trains", Trains);
					Menu::MenuOption("Utility", Utility);
					Menu::MenuOption("Vans", Vans);*/



					break;
				case Doomsday:
					Menu::Title("~w~Doomsday");
					// Menu::Subtitle(".");
					for (auto car : Doomsday1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case TAXI:
					Menu::Title("~w~Rocket Vehicle");
					// Menu::Subtitle(".");
					for (auto car : Taxi1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Rocketss:
					Menu::Title("~w~Taxi");
					// Menu::Subtitle(".");
					for (auto car : Rockets1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case SuperSports:
					Menu::Title("~w~SOUTHERNSAN");
					// Menu::Subtitle(".");
					//for (auto car : SOUTHERNSAN) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
					/*case Super:
						Menu::Title("~w~Super");
						// Menu::Subtitle(".");
						for (auto car : Super1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
						break;*/
						/*case Sports:
							Menu::Title("~w~Sports");
							// Menu::Subtitle(".");
							for (auto car : Sports1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
							break;*/
				case SportClassic:
					Menu::Title("~w~Sports Classic");
					// Menu::Subtitle(".");
					for (auto car : SportsClassics1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Offroad:
					Menu::Title("~w~Offroad");
					// Menu::Subtitle(".");
					for (auto car : OffRoad1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Sedans:
					Menu::Title("~w~Sedans");
					// Menu::Subtitle(".");
					for (auto car : Sedans1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Coupes:
					Menu::Title("~w~Coupes");
					// Menu::Subtitle(".");
					for (auto car : Coupes1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Muscle:
					Menu::Title("~w~Muscle");
					// Menu::Subtitle(".");
					for (auto car : Muscle1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Boats:
					Menu::Title("~w~Boats");
					// Menu::Subtitle(".");
					for (auto car : Boats1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Commercial:
					Menu::Title("~w~Commercial");
					// Menu::Subtitle(".");
					for (auto car : Commercial1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Compacts:
					Menu::Title("~w~Compacts");
					// Menu::Subtitle(".");
					for (auto car : Compacts1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Cycles:
					Menu::Title("~w~Cycles");
					// Menu::Subtitle(".");
					for (auto car : Cycles1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Emergency:
					Menu::Title("~w~Emergency");
					// Menu::Subtitle(".");
					for (auto car : Emergency1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Helicopters:
					Menu::Title("~w~Helicopters");
					// Menu::Subtitle(".");
					for (auto car : Helicopters1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Industrial:
					Menu::Title("~w~Industrial");
					// Menu::Subtitle(".");
					for (auto car : Industrial1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Military:
					Menu::Title("~w~Military");
					// Menu::Subtitle(".");
					for (auto car : Military1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Motorcycles:
					Menu::Title("~w~Motorcycles");
					// Menu::Subtitle(".");
					for (auto car : Motorcycles1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Planes:
					Menu::Title("~w~Planes");
					// Menu::Subtitle(".");
					for (auto car : Planes1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
					/*case Service:
						Menu::Title("~w~Service");
						// Menu::Subtitle(".");
						for (auto car : Service1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
						break;*/
				case SUV:
					Menu::Title("~w~SUV");
					// Menu::Subtitle(".");
					for (auto car : SUVs1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Trailer:
					Menu::Title("~w~Trailer");
					// Menu::Subtitle(".");
					for (auto car : Trailer1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Trains:
					Menu::Title("~w~Trains");
					// Menu::Subtitle(".");
					for (auto car : Trains1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Utility:
					Menu::Title("~w~Utility");
					// Menu::Subtitle(".");
					for (auto car : Utility1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Vans:
					Menu::Title("~w~Vans");
					// Menu::Subtitle(".");
					for (auto car : Vans1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case after:
					Menu::Title("~w~Afterhours");
					// Menu::Subtitle(".");
					for (auto car : Afterhours1) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				case Arena:
					Menu::Title("~w~ArenaWars");
					// Menu::Subtitle(".");
					for (auto car : Arenawars) { Menu::Option(car, [car] { Features::autovehi(car); }); }
					break;
				}
							   break;

				case Zombie:
				{
					Menu::Title("Zombie");
					// Menu::Subtitle("ZOMBIE");

					if (Menu::Option("RAILGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("U_M_Y_Zombie_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("PISTOL")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("U_M_Y_Zombie_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("GRENADELAUNCHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("U_M_Y_Zombie_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MINIGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("U_M_Y_Zombie_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MINIGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FIREEXTINGUISHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("U_M_Y_Zombie_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FIREEXTINGUISHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("STUNGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("U_M_Y_Zombie_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_STUNGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MICROSMG")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("U_M_Y_Zombie_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MICROSMG");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FLAREGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("U_M_Y_Zombie_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FLAREGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}




				}
				break;

				case justin:
				{
					Menu::Title("Stripper");
					// Menu::Subtitle("JUSTIN");

					if (Menu::Option("RAILGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("u_m_y_justin");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("PISTOL")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("u_m_y_justin");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("GRENADELAUNCHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("u_m_y_justin");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MINIGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("u_m_y_justin");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MINIGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FIREEXTINGUISHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("u_m_y_justin");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FIREEXTINGUISHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("STUNGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("u_m_y_justin");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_STUNGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MICROSMG")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("u_m_y_justin");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MICROSMG");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FLAREGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("u_m_y_justin");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FLAREGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}




				}
				break;

				case swat:
				{
					Menu::Title("Stripper");
					// Menu::Subtitle("SWAT");

					if (Menu::Option("RAILGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Swat_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("PISTOL")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Swat_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("GRENADELAUNCHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Swat_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MINIGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Swat_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MINIGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FIREEXTINGUISHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Swat_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FIREEXTINGUISHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("STUNGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Swat_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_STUNGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MICROSMG")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Swat_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MICROSMG");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FLAREGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Swat_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FLAREGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}




				}
				break;

				case striper:
				{
					Menu::Title("Stripper");
					// Menu::Subtitle("STRIPER");

					if (Menu::Option("RAILGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("s_f_y_stripper_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("PISTOL")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("s_f_y_stripper_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("GRENADELAUNCHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("s_f_y_stripper_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MINIGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("s_f_y_stripper_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MINIGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FIREEXTINGUISHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("s_f_y_stripper_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FIREEXTINGUISHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("STUNGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("s_f_y_stripper_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_STUNGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MICROSMG")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("s_f_y_stripper_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MICROSMG");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FLAREGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("s_f_y_stripper_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FLAREGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}




				}
				break;

				case homeless:
				{
					Menu::Title("homeless");
					// Menu::Subtitle("HOMELESS");

					if (Menu::Option("RAILGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_M_TrampBeac_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("PISTOL")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_M_TrampBeac_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("GRENADELAUNCHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_M_TrampBeac_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MINIGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_M_TrampBeac_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MINIGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FIREEXTINGUISHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_M_TrampBeac_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FIREEXTINGUISHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("STUNGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_M_TrampBeac_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_STUNGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MICROSMG")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_M_TrampBeac_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MICROSMG");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FLAREGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_M_TrampBeac_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FLAREGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}




				}
				break;

				case Driver:
				{
					Menu::Title("Motocross-Driver");
					// Menu::Subtitle("MOTOCROSS DRIVER");

					if (Menu::Option("RAILGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_Y_DHill_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("PISTOL")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_Y_DHill_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("GRENADELAUNCHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_Y_DHill_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MINIGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_Y_DHill_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MINIGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FIREEXTINGUISHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_Y_DHill_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FIREEXTINGUISHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("STUNGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_Y_DHill_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_STUNGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MICROSMG")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_Y_DHill_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MICROSMG");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FLAREGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("A_M_Y_DHill_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FLAREGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}




				}
				break;

				case soldier:
				{
					Menu::Title("Soldier");
					// Menu::Subtitle("SOLDIER");

					if (Menu::Option("RAILGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("PISTOL")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("GRENADELAUNCHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MINIGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MINIGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FIREEXTINGUISHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FIREEXTINGUISHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("STUNGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_STUNGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MICROSMG")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MICROSMG");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FLAREGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FLAREGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}




				}
				break;

				case officer:
				{
					Menu::Title("Soldier");
					// Menu::Subtitle("OFFICER");

					if (Menu::Option("RAILGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_02");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("PISTOL")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_02");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("GRENADELAUNCHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_02");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MINIGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_02");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MINIGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FIREEXTINGUISHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_02");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FIREEXTINGUISHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("STUNGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_02");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_STUNGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MICROSMG")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_02");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MICROSMG");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FLAREGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_Marine_02");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FLAREGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}




				}
				break;

				case extraterrestrial:
				{
					Menu::Title("Soldier");
					// Menu::Subtitle("");

					if (Menu::Option("RAILGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_MovAlien_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("PISTOL")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_MovAlien_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("GRENADELAUNCHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_MovAlien_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MINIGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_MovAlien_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MINIGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FIREEXTINGUISHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_MovAlien_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FIREEXTINGUISHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("STUNGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_MovAlien_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_STUNGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MICROSMG")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_MovAlien_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MICROSMG");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FLAREGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_M_MovAlien_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FLAREGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}




				}
				break;

				case LSPD:
				{
					Menu::Title("Soldier");
					// Menu::Subtitle("LSPD");

					if (Menu::Option("RAILGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Cop_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("PISTOL")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Cop_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("GRENADELAUNCHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Cop_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MINIGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Cop_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MINIGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FIREEXTINGUISHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Cop_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FIREEXTINGUISHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("STUNGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Cop_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_STUNGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MICROSMG")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Cop_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MICROSMG");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FLAREGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Cop_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FLAREGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}




				}
				break;

				case firefighter:
				{
					Menu::Title("Soldier");
					// Menu::Subtitle("FIRE FIGHTER");

					if (Menu::Option("RAILGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Fireman_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("PISTOL")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Fireman_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("GRENADELAUNCHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Fireman_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MINIGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Fireman_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MINIGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FIREEXTINGUISHER")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Fireman_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FIREEXTINGUISHER");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("STUNGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Fireman_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_STUNGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("MICROSMG")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Fireman_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_MICROSMG");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}

					if (Menu::Option("FLAREGUN")) {
						Player player = PLAYER::PLAYER_ID();
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						Hash stripper = GAMEPLAY::GET_HASH_KEY("S_M_Y_Fireman_01");
						Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_FLAREGUN");
						STREAMING::REQUEST_MODEL(stripper);
						while (!STREAMING::HAS_MODEL_LOADED(stripper))
							WAIT(0);

						int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
						ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
						PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
						WEAPON::GIVE_WEAPON_TO_PED(createdPED, railgun, railgun, 9999, 9999);
						PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
					}




				}
				break;

				case Pedss:
				{
					Menu::Title("Ped / Weapon Changer");
					// Menu::Subtitle("BODYGUARDS");

					Menu::MenuOption("Stripper ~y~>", striper);
					Menu::MenuOption("Swat ~y~>", swat);
					Menu::MenuOption("Justin ~y~>", justin);
					Menu::MenuOption("Zombie ~y~>", Zombie);
					Menu::MenuOption("Motocross-Driver ~y~>", Driver);
					Menu::MenuOption("Homeless ~y~>", homeless);
					Menu::MenuOption("Soldier ~y~>", soldier);
					Menu::MenuOption("Officer ~y~>", officer);
					Menu::MenuOption("LSPD police officer ~y~>", LSPD);
					Menu::MenuOption("Firefighter ~y~>", firefighter);
					Menu::MenuOption("Extraterrestrial ~y~>", extraterrestrial);

				}
				break;



				case pet:
				{
					Menu::Title("Spawn Buddie");
					// Menu::Subtitle("PET");

					Menu::MenuOption("Ped / Weapon Changer", Pedss);

					Menu::Break(" Choose a pet");

					if (Menu::ListVector("Ped", namedPedList, namedPedListPos)) {
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						DWORD model = GAMEPLAY::GET_HASH_KEY(namedPedList[namedPedListPos]);
						STREAMING::REQUEST_MODEL(model);
						while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
						latestObj = latestObj = PED::CREATE_PED(0, GAMEPLAY::GET_HASH_KEY(namedPedList[namedPedListPos]), pos.x, pos.y, pos.z, 0.f, 1, 1);
					}
				}
				break;

				//Force Animation
				case forcean:
				{
					Menu::Title("Force Animation");
					// Menu::Subtitle("ANIMATIONS");

					if (Menu::Option("Stop Animation")) { AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer)); }
					if (Menu::Option("Sex Receiver")) { Features::animatePlayer(Features::Online::selectedPlayer, "rcmpaparazzo_2", "shag_loop_poppy"); }
					if (Menu::Option("Sex Giver")) { Features::animatePlayer(Features::Online::selectedPlayer, "rcmpaparazzo_2", "shag_loop_a"); }
					if (Menu::Option("Stripper Dance")) { Features::animatePlayer(Features::Online::selectedPlayer, "mini@strip_club@private_dance@part1", "priv_dance_p1"); }
					if (Menu::Option("Pole Dance")) { Features::animatePlayer(Features::Online::selectedPlayer, "mini@strip_club@pole_dance@pole_dance1", "pd_dance_01"); }
					if (Menu::Option("Push Ups")) { Features::animatePlayer(Features::Online::selectedPlayer, "amb@world_human_push_ups@male@base", "base"); }
					if (Menu::Option("Sit Ups")) { Features::animatePlayer(Features::Online::selectedPlayer, "amb@world_human_sit_ups@male@base", "base"); }
					if (Menu::Option("Celebrate")) { Features::animatePlayer(Features::Online::selectedPlayer, "rcmfanatic1celebrate", "celebrate"); }
					if (Menu::Option("Electrocution")) { Features::animatePlayer(Features::Online::selectedPlayer, "ragdoll@human", "electrocute"); }
					if (Menu::Option("Suicide")) { Features::animatePlayer(Features::Online::selectedPlayer, "mp_suicide", "pistol"); }
					if (Menu::Option("Showering")) { Features::animatePlayer(Features::Online::selectedPlayer, "mp_safehouseshower@male@", "male_shower_idle_b"); }

				}
				break;



				//PTFX 
				case PTFX:
				{
					Menu::Title("Effects");
					// Menu::Subtitle("PTFX");

					if (Menu::Option("Clown Appears"))Features::PTFXCALL("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears");
					if (Menu::Option("Firework 1"))Features::PTFXCALL("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst");
					if (Menu::Option("Firework 2"))Features::PTFXCALL("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_burst_rgw");
					if (Menu::Option("Firework 3"))Features::PTFXCALL("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_spiral_burst_rgw");
					if (Menu::Option("Banknotes"))Features::PTFXCALL("scr_ornate_heist", "scr_ornate_heist", "scr_heist_ornate_banknotes");
					if (Menu::Option("Truck Crash"))Features::PTFXCALL("scr_fbi4", "scr_fbi4", "scr_fbi4_trucks_crash");
					if (Menu::Option("Alien 1"))Features::PTFXCALL("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate");
					if (Menu::Option("Alien 2"))Features::PTFXCALL("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport");
					if (Menu::Option("Electric Box"))Features::PTFXCALL("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box");
					if (Menu::Option("Water Splash"))Features::PTFXCALL("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash");
					if (Menu::Option("Bubbles"))Features::PTFXCALL("scr_fbi5a", "scr_fbi5a", "water_splash_ped_bubbles");
					if (Menu::Option("Sniper Impact"))Features::PTFXCALL("scr_martin1", "scr_martin1", "scr_sol1_sniper_impact");
					if (Menu::Option("Dirt Throw"))Features::PTFXCALL("core_snow", "core_snow", "cs_mich1_spade_dirt_throw");
					if (Menu::Option("Blood Stab"))Features::PTFXCALL("scr_michael2", "scr_michael2", "scr_mich2_blood_stab");
					if (Menu::Option("Ped Sliced"))Features::PTFXCALL("scr_michael2", "scr_michael2", "scr_abattoir_ped_sliced");
					if (Menu::Option("Camera"))Features::PTFXCALL("scr_rcpaparazzo1", "scr_rcpaparazzo1", "scr_rcpap1_camera");
					if (Menu::Option("Meth Smoke"))Features::PTFXCALL("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke");
					if (Menu::Option("Burial Dirt"))Features::PTFXCALL("scr_reburials", "scr_reburials", "scr_burial_dirt");

				}
				break;


				//onlineftp
				case onlineftp:
				{
					Menu::Title("Effects to Player");
					// Menu::Subtitle("EFFECTS");

					if (selecArrow) {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
						GRAPHICS::DRAW_MARKER(offradardpl, coords.x, coords.y, coords.z + 1.3f, 0, 0, 0, 0, 180, 0, 0.3, 0.3, 0.3, r1, g1, b1, 200, 1, 1, 1, 0, 0, 0, 0);
					}
					if (Menu::Option("Clown Appears"))Features::PTFXPLAYER("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", Features::Online::selectedPlayer);
					if (Menu::Option("Firework 1"))Features::PTFXPLAYER("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst", Features::Online::selectedPlayer);
					if (Menu::Option("Firework 2"))Features::PTFXPLAYER("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_burst_rgw", Features::Online::selectedPlayer);
					if (Menu::Option("Firework 3"))Features::PTFXPLAYER("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_spiral_burst_rgw", Features::Online::selectedPlayer);
					if (Menu::Option("Banknotes"))Features::PTFXPLAYER("scr_ornate_heist", "scr_ornate_heist", "scr_heist_ornate_banknotes", Features::Online::selectedPlayer);
					if (Menu::Option("Truck Crash"))Features::PTFXPLAYER("scr_fbi4", "scr_fbi4", "scr_fbi4_trucks_crash", Features::Online::selectedPlayer);
					if (Menu::Option("Alien 1"))Features::PTFXPLAYER("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate", Features::Online::selectedPlayer);
					if (Menu::Option("Alien 2"))Features::PTFXPLAYER("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport", Features::Online::selectedPlayer);
					if (Menu::Option("Electric Box"))Features::PTFXPLAYER("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box", Features::Online::selectedPlayer);
					if (Menu::Option("Water Splash"))Features::PTFXPLAYER("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash", Features::Online::selectedPlayer);
					if (Menu::Option("Bubbles"))Features::PTFXPLAYER("scr_fbi5a", "scr_fbi5a", "water_splash_ped_bubbles", Features::Online::selectedPlayer);
					if (Menu::Option("Blood Entry"))Features::PTFXPLAYER("scr_finalec2", "scr_finalec2", "scr_finale2_blood_entry", Features::Online::selectedPlayer);
					if (Menu::Option("Sniper Impact"))Features::PTFXPLAYER("scr_martin1", "scr_martin1", "scr_sol1_sniper_impact", Features::Online::selectedPlayer);
					if (Menu::Option("Dirt Throw"))Features::PTFXPLAYER("core_snow", "core_snow", "cs_mich1_spade_dirt_throw", Features::Online::selectedPlayer);
					if (Menu::Option("Blood Stab"))Features::PTFXPLAYER("scr_michael2", "scr_michael2", "scr_mich2_blood_stab", Features::Online::selectedPlayer);
					if (Menu::Option("Ped Sliced"))Features::PTFXPLAYER("scr_michael2", "scr_michael2", "scr_abattoir_ped_sliced", Features::Online::selectedPlayer);
					if (Menu::Option("Camera"))Features::PTFXPLAYER("scr_rcpaparazzo1", "scr_rcpaparazzo1", "scr_rcpap1_camera", Features::Online::selectedPlayer);
					if (Menu::Option("Meth Smoke"))Features::PTFXPLAYER("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke", Features::Online::selectedPlayer);
					if (Menu::Option("Burial Dirt"))Features::PTFXPLAYER("scr_reburials", "scr_reburials", "scr_burial_dirt", Features::Online::selectedPlayer);

				}
				break;


				case attachvehicle:
				{
					Menu::Title("~r~Attach Vehicle to Player");
					// Menu::Subtitle("ATTACH VEH");

					/*if (Menu::ListVector("SOUTHERNSAN", SOUTHERNSAN, soutprop)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (SOUTHERNSAN[soutprop]));
					};

					if (Menu::ListVector("SMUGLERSRUN", SMUGLERSRUN1, soutprop2)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (SMUGLERSRUN1[soutprop2]));
					};*/

					if (Menu::ListVector("GUNRUNNING", GUNRUNNING1, soutprop3)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (GUNRUNNING1[soutprop3]));
					};

					if (Menu::ListVector("CUNNINGSTUNTS", CUNNINGSTUNTS1, soutprop4)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (CUNNINGSTUNTS1[soutprop4]));
					};

					/*if (Menu::ListVector("IMPORTEXPORT", IMPORTEXPORT1, soutprop5)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (IMPORTEXPORT1[soutprop5]));
					};*/

					if (Menu::ListVector(" Commercial", Compacts1, soutprop6)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Commercial1[soutprop6]));
					};

					if (Menu::ListVector(" Commercial", Commercial1, soutprop7)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Commercial1[soutprop7]));
					};

					if (Menu::ListVector("Compacts", Compacts1, soutprop8)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Compacts1[soutprop8]));
					};

					if (Menu::ListVector("Coupes", Coupes1, soutprop9)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Coupes1[soutprop9]));
					};

					if (Menu::ListVector("Cycles", Cycles1, soutprop10)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Cycles1[soutprop10]));
					};

					if (Menu::ListVector("Emergency", Emergency1, soutprop11)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Emergency1[soutprop11]));
					};

					if (Menu::ListVector("Helicopters", Helicopters1, soutprop12)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Helicopters1[soutprop12]));
					};

					if (Menu::ListVector("Industrial", Industrial1, soutprop13)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Industrial1[soutprop13]));
					};

					if (Menu::ListVector("Military", Military1, soutprop14)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Military1[soutprop14]));
					};

					if (Menu::ListVector("Motorcycles", Motorcycles1, soutprop15)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Motorcycles1[soutprop15]));
					};

					if (Menu::ListVector("Muscle", Muscle1, soutprop16)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Muscle1[soutprop16]));
					};

					if (Menu::ListVector("OffRoad", OffRoad1, soutprop17)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (OffRoad1[soutprop17]));
					};

					if (Menu::ListVector("Planes", Planes1, soutprop18)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Planes1[soutprop18]));
					};

					if (Menu::ListVector("Sedans", Sedans1, soutprop19)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Sedans1[soutprop19]));
					};

					if (Menu::ListVector("Service", Service1, soutprop20)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Service1[soutprop20]));
					};

					if (Menu::ListVector("Sports", Sports1, soutprop21)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Sports1[soutprop21]));
					};

					if (Menu::ListVector("SportsClassics", SportsClassics1, soutprop22)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (SportsClassics1[soutprop22]));
					};

					if (Menu::ListVector("Super", Super1, soutprop23)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Super1[soutprop23]));
					};

					if (Menu::ListVector("SUVs", SUVs1, soutprop24)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (SUVs1[soutprop24]));
					};

					if (Menu::ListVector("Trailer", Trailer1, soutprop25)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Trailer1[soutprop25]));
					};

					if (Menu::ListVector("Trains", Trains1, soutprop26)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Trains1[soutprop26]));
					};

					if (Menu::ListVector("Utility", Utility1, soutprop27)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Utility1[soutprop27]));
					};

					if (Menu::ListVector("Vans", Vans1, soutprop28)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Utility1[soutprop28]));
					};

					if (Menu::ListVector("Doomsday", Doomsday1, soutprop29)) {

						KEEEk(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), (Utility1[soutprop29]));
					};

				}
				break;



				//atachtp 			
				case attachtp:
				{
					Menu::Title("~r~Attach to Player");
					// Menu::Subtitle("ATTACHMENTS");

					Menu::MenuOption("Attach Vehicle to Player", attachvehicle);
					if (selecArrow) {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
						GRAPHICS::DRAW_MARKER(offradardpl, coords.x, coords.y, coords.z + 1.3f, 0, 0, 0, 0, 180, 0, 0.3, 0.3, 0.3, r1, g1, b1, 200, 1, 1, 1, 0, 0, 0, 0);
					}
					if (Menu::ListVector("All Props", propList, propListPos)) {
						Vector3 Pos = ENTITY::GET_ENTITY_COORDS(Features::Online::selectedPlayer, 1);
						Features::attachobjects2(propList[propListPos]);
					}
					Menu::Title("Attach To Players");
					if (Menu::Option("~r~Beach Fire")) { Features::attachobjects2("prop_beach_fire"); }
					if (Menu::Option("Plate")) { Features::attachobjects2("p_oil_slick_01"); }
					if (Menu::Option("EMP")) { Features::attachobjects2("hei_prop_heist_emp"); }
					if (Menu::Option("Orange Ball")) { Features::attachobjects2("prop_juicestand"); }
					if (Menu::Option("Weed")) { Features::attachobjects2("prop_weed_01"); }
					if (Menu::Option("Safe")) { Features::attachobjects2("p_v_43_safe_s"); }
					if (Menu::Option("Ufo")) { Features::attachobjects2("p_spinning_anus_s"); }
					if (Menu::Option("Toilet")) { Features::attachobjects2("prop_ld_toilet_01"); }
					if (Menu::Option("Christmas Tree")) { Features::attachobjects2("prop_xmas_tree_int"); }
					if (Menu::Option("Windmill")) { Features::attachobjects2("prop_windmill_01"); }
					if (Menu::Option("Radar")) { Features::attachobjects2("prop_air_bigradar"); }
					if (Menu::Option("Ramp")) { Features::attachobjects2("PROP_MP_RAMP_01"); }
					if (Menu::Option("Plane")) { Features::attachobjects2("prop_dummy_plane"); }
					if (Menu::Option("Astreod")) { Features::attachobjects2("prop_asteroid_01"); }
					if (Menu::Option("Alien Egg")) { Features::attachobjects2("prop_alien_egg_01"); }
					if (Menu::Option("Gravestone")) { Features::attachobjects2("prop_gravestones_02a"); }
					if (Menu::Option("Money Bag")) { Features::attachobjects2("prop_money_bag_01"); }
					if (Menu::Option("Microwave")) { Features::attachobjects2("prop_microwave_1"); }
					if (Menu::Option("Big Shit")) { Features::attachobjects2("prop_big_shit_02"); }
					if (Menu::Option("Barbell 80kg")) { Features::attachobjects2("prop_barbell_80kg"); }
					if (Menu::Option("Beach Ring")) { Features::attachobjects2("prop_beach_rings_01"); }
					if (Menu::Option("Punchbag")) { Features::attachobjects2("prop_beach_punchbag"); }
					if (Menu::Option("Vending")) { Features::attachobjects2("prop_vend_snak_01"); }
					if (Menu::Option("Beggar Sign")) { Features::attachobjects2("prop_beggers_sign_02"); }
					char* objects[136] = { "prop_bskball_01", "PROP_MP_RAMP_03", "PROP_MP_RAMP_02", "PROP_MP_RAMP_01", "PROP_JETSKI_RAMP_01", "PROP_WATER_RAMP_03", "PROP_VEND_SNAK_01", "PROP_TRI_START_BANNER", "PROP_TRI_FINISH_BANNER", "PROP_TEMP_BLOCK_BLOCKER", "PROP_SLUICEGATEL", "PROP_SKIP_08A", "PROP_SAM_01", "PROP_RUB_CONT_01B", "PROP_ROADCONE01A", "PROP_MP_ARROW_BARRIER_01", "PROP_HOTEL_CLOCK_01", "PROP_LIFEBLURB_02", "PROP_COFFIN_02B", "PROP_MP_NUM_1", "PROP_MP_NUM_2", "PROP_MP_NUM_3", "PROP_MP_NUM_4", "PROP_MP_NUM_5", "PROP_MP_NUM_6", "PROP_MP_NUM_7", "PROP_MP_NUM_8", "PROP_MP_NUM_9", "prop_xmas_tree_int", "prop_bumper_car_01", "prop_beer_neon_01", "prop_space_rifle", "prop_dummy_01", "prop_rub_trolley01a", "prop_wheelchair_01_s", "PROP_CS_KATANA_01", "PROP_CS_DILDO_01", "prop_armchair_01", "prop_bin_04a", "prop_chair_01a", "prop_dog_cage_01", "prop_dummy_plane", "prop_golf_bag_01", "prop_arcade_01", "hei_prop_heist_emp", "prop_alien_egg_01", "prop_air_towbar_01", "hei_prop_heist_tug", "prop_air_luggtrolley", "PROP_CUP_SAUCER_01", "prop_wheelchair_01", "prop_ld_toilet_01", "prop_acc_guitar_01", "prop_bank_vaultdoor", "p_v_43_safe_s", "p_spinning_anus_s", "prop_can_canoe", "prop_air_woodsteps", "Prop_weed_01", "prop_a_trailer_door_01", "prop_apple_box_01", "prop_air_fueltrail1", "prop_barrel_02a", "prop_barrel_float_1", "prop_barrier_wat_03b", "prop_air_fueltrail2", "prop_air_propeller01", "prop_windmill_01", "prop_Ld_ferris_wheel", "p_tram_crash_s", "p_oil_slick_01", "p_ld_stinger_s", "p_ld_soc_ball_01", "prop_juicestand", "p_oil_pjack_01_s", "prop_barbell_01", "prop_barbell_100kg", "p_parachute1_s", "p_cablecar_s", "prop_beach_fire", "prop_lev_des_barge_02", "prop_lev_des_barge_01", "prop_a_base_bars_01", "prop_beach_bars_01", "prop_air_bigradar", "prop_weed_pallet", "prop_artifact_01", "prop_attache_case_01", "prop_large_gold", "prop_roller_car_01", "prop_water_corpse_01", "prop_water_corpse_02", "prop_dummy_01", "prop_atm_01", "hei_prop_carrier_docklight_01", "hei_prop_carrier_liferafts", "hei_prop_carrier_ord_03", "hei_prop_carrier_defense_02", "hei_prop_carrier_defense_01", "hei_prop_carrier_radar_1", "hei_prop_carrier_radar_2", "hei_prop_hei_bust_01", "hei_prop_wall_alarm_on", "hei_prop_wall_light_10a_cr", "prop_afsign_amun", "prop_afsign_vbike", "prop_aircon_l_01", "prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_airhockey_01", "prop_air_bagloader", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_cargo_01a", "prop_air_chock_01", "prop_air_chock_03", "prop_air_gasbogey_01", "prop_air_generator_03", "prop_air_stair_02", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_donut", "prop_amb_handbag_01", "prop_amp_01", "prop_anim_cash_pile_02", "prop_asteroid_01", "prop_arm_wrestle_01", "prop_ballistic_shield", "prop_bank_shutter", "prop_barier_conc_02b", "prop_barier_conc_05a", "prop_barrel_01a", "prop_bar_stool_01", "prop_basejump_target_01" };

					if (Menu::Option("Delete All Objects")) {
						for (int i = 0; i < 5; i++) {
							Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 1);
							GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
							GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
							GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0);
							for (int i = 0; i < 136; i++) {
								Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, GAMEPLAY::GET_HASH_KEY(objects[i]), 0, 0, 1);

								if (ENTITY::DOES_ENTITY_EXIST(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer))) {
									RequestControlOfEnt(obj);
									int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj);
									NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
									Features::RequestControlOfid(netID);
									ENTITY::DETACH_ENTITY(obj, 1, 1);
									if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(obj)) {
										ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, 1, 1);
										ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&obj);
										ENTITY::DELETE_ENTITY(&obj);
									}
								}
							}
						}
					}
				}
				break;

				case attachtpall:
				{
					Menu::Title("~r~Attach to All Player");
					// Menu::Subtitle("ATTACHMENTS");

					if (Menu::Option("Plate")) { Features::attachobjects222("p_oil_slick_01"); }
					if (Menu::Option("EMP")) { Features::attachobjects222("hei_prop_heist_emp"); }
					if (Menu::Option("Orange Ball")) { Features::attachobjects222("prop_juicestand"); }
					if (Menu::Option("Weed")) { Features::attachobjects222("prop_weed_01"); }
					if (Menu::Option("Safe")) { Features::attachobjects222("p_v_43_safe_s"); }
					if (Menu::Option("Ufo")) { Features::attachobjects222("p_spinning_anus_s"); }
					if (Menu::Option("Toilet")) { Features::attachobjects222("prop_ld_toilet_01"); }
					if (Menu::Option("Christmas Tree")) { Features::attachobjects222("prop_xmas_tree_int"); }
					if (Menu::Option("Windmill")) { Features::attachobjects222("prop_windmill_01"); }
					if (Menu::Option("Radar")) { Features::attachobjects222("prop_air_bigradar"); }
					if (Menu::Option("Alien Egg")) { Features::attachobjects222("prop_alien_egg_01"); }
					if (Menu::Option("Beggers Sign")) { Features::attachobjects222("prop_beggers_sign_01"); }
					if (Menu::Option("Tramp Sign")) { Features::attachobjects222("prop_beggers_sign_02"); }
					if (Menu::Option("Egg Clock")) { Features::attachobjects222("prop_egg_clock_01"); }
					if (Menu::Option("Guitar")) { Features::attachobjects222("prop_acc_guitar_01_d1"); }
					if (Menu::Option("Duffel")) { Features::attachobjects222("prop_cs_duffel_01b"); }
					if (Menu::Option("Vending Dispenser")) { Features::attachobjects222("prop_juice_dispenser"); }
					if (Menu::Option("Boxing")) { Features::attachobjects222("prop_boxing_glove_01"); }
					if (Menu::Option("Dingy")) { Features::attachobjects222("prop_byard_dingy"); }
					if (Menu::Option("Dildo")) { Features::attachobjects222("prop_cs_dildo_01"); }
					if (Menu::Option("Dumpster")) { Features::attachobjects222("prop_cs_dumpster_01a"); }
					if (Menu::Option("vDJ")) { Features::attachobjects222("prop_dj_deck_02"); }
					if (Menu::Option("Plane")) { Features::attachobjects222("prop_dummy_plane"); }
					if (Menu::Option("Ramp")) { Features::attachobjects222("PROP_MP_RAMP_03"); }
					if (Menu::Option("Ramp2")) { Features::attachobjects222("PROP_MP_RAMP_02"); }
					if (Menu::Option("Ramp3")) { Features::attachobjects222("PROP_MP_RAMP_01"); }
					if (Menu::Option("Skip")) { Features::attachobjects222("PROP_SKIP_08A"); }
					if (Menu::Option("Beer Neon")) { Features::attachobjects222("prop_beer_neon_01"); }
					if (Menu::Option("Dummy Plane")) { Features::attachobjects222("prop_dummy_plane"); }
					if (Menu::Option("Cash Pile")) { Features::attachobjects222("prop_anim_cash_pile_02"); }
					if (Menu::Option("Asteroid")) { Features::attachobjects222("prop_asteroid_01"); }
					if (Menu::Option("Weed Palet")) { Features::attachobjects222("prop_weed_pallet"); }
					if (Menu::Option("Ferris Wheel")) { Features::attachobjects222("prop_Ld_ferris_wheel"); }
					if (Menu::Option("Donut")) { Features::attachobjects222("prop_amb_donut"); }
					if (Menu::Option("Basejump")) { Features::attachobjects222("prop_basejump_target_01"); }
					if (Menu::Option("Handbag")) { Features::attachobjects222("prop_amb_handbag_01"); }
					if (Menu::Option("Cargo")) { Features::attachobjects222("prop_air_cargo_01a"); }
					if (Menu::Option("Stunt Ramp BIG")) { Features::attachobjects222("stt_prop_ramp_multi_loop_rb"); }
					if (Menu::Option("Crashed Heli")) { Features::attachobjects222("prop_crashed_heli"); }
					if (Menu::Option("Crashed Heli 2")) { Features::attachobjects222("prop_crashed_heli_s"); }
					if (Menu::Option("Train")) { Features::attachobjects222("prop_rail_boxcar3"); }
					if (Menu::Option("Roller")) { Features::attachobjects222("prop_roller_car_02"); }
					if (Menu::Option("Para")) { Features::attachobjects222("p_cargo_chute_s"); }
					if (Menu::Option("Katana")) { Features::attachobjects222("prop_cs_katana_01"); }
					if (Menu::Option("Boxing Glove")) { Features::attachobjects222("prop_boxing_glove_01"); }
				}
				break;


				case tpother:
				{
					Menu::Title("~b~Teleport Options");
					// Menu::Subtitle("");
					if (selecArrow) {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
						GRAPHICS::DRAW_MARKER(29, coords.x, coords.y, coords.z + 1.3f, 0, 0, 0, 0, 180, 0, 1, 1, 1, 0, 255, 255, 200, 1, 1, 1, 0, 0, 0, 0);
					}
					if (Menu::Option("Teleport Into Car")) {
						Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
						for (int i = -1; i < 16; i++)
						{
							if (VEHICLE::IS_VEHICLE_SEAT_FREE(veh, i))
							{
								PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, i);
							}
						}
					}
					Menu::Option("Teleport To Player", [] {Features::Online::TeleportToPlayer(Features::Online::selectedPlayer); });

				}
				break;


				case outfits:
				{
					Menu::Title("~r~Clothing");
					// Menu::Subtitle("OUTFITS");


					if (Menu::Option("Black Christmas")) {
						Swat();
					}
					if (Menu::Option("Rockstar Logo")) {
						rlogo();
					}
					if (Menu::Option("Outfit 1")) {
						ghost();
					}
					if (Menu::Option("Heist Ready")) {
						Splinter();
					}
					if (Menu::Option("Mullet Gang")) {
						Pilot();
					}
					if (Menu::Option("Checkerboard")) {
						Balla();
					}
					if (Menu::Option("Sexy Elf")) {
						Elf();
					}
					if (Menu::Option("Mrs Stubby")) {
						Thug();
					}
					if (Menu::Option("Mrs Claus")) {
						Santa();
					}
				}


				break;


				case objSpawner:
				{


					Menu::Title("");
					// Menu::Subtitle("Object Spawner");
					//UI::Break("Prop Spawner");
					if (Menu::ListVector("Prop List", propList, propListPos)) {
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						latestObj = SpawnObject(propList[propListPos], pos);
					}
					if (Menu::ListVector("Stunt Props", Stuntlist, StuntlistPos)) {
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						latestObj = SpawnObject(Stuntlist[StuntlistPos], pos);
					}
					if (Menu::ListVector("NPC's", namedPedList, namedPedListPos)) {
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						DWORD model = GAMEPLAY::GET_HASH_KEY(namedPedList[namedPedListPos]);
						STREAMING::REQUEST_MODEL(model);
						while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
						latestObj = latestObj = PED::CREATE_PED(0, GAMEPLAY::GET_HASH_KEY(namedPedList[namedPedListPos]), pos.x, pos.y, pos.z, 0.f, 1, 1);
					}
					if (Menu::Option("Input Object")) {
						Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
						latestObj = SpawnObject(CharKeyboard(), pos);
					}
					Menu::Toggle("Freeze On Spawn", freezeSpawn);
					for (int i = 0; i < spwnObjC; i++)
					{
						if (ENTITY::DOES_ENTITY_EXIST(spwndObjects[i])) {
							if (Menu::MenuOption(spwndObjectsNames[i], editObj))
							{
								latestObj = spwndObjects[i];
								selecObj = i;
								Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
								Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
								MoveX = objCoords.x;
								MoveY = objCoords.y;
								MoveZ = objCoords.z;
								roll1 = objRot.y;
								yaw1 = objRot.z;
								pitch1 = objRot.x;
							}
						}
					}
				}
				break;

				case Neons: {
					Menu::Title("Neons");
					// Menu::Subtitle("NEONS OPTIONS");

					Menu::Toggle("Rainbow Neons", Features::Rneon, [] { Features::RainbowNeon(Features::Rneon); });

					if (Menu::Option("Enable Xenon")) {
						int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
						Features::ToggleXenon(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
					}
					if (Menu::Option("Enable Neons")) {
						int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 0, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 1, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 2, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 3, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 4, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 5, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 6, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(VehID, 7, 1);
					}
					if (Menu::Option("Red")) {
						int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 1);
						VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 255, 0, 0);
					}
					if (Menu::Option("Green")) {
						int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
						VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 0, 255, 0);
					}
					if (Menu::Option("Blue")) {
						int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
						VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 0, 0, 255);
					}
					if (Menu::Option("Hot Pink")) {
						int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
						VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 226, 35, 157);
					}
					if (Menu::Option("Yellow")) {
						int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
						VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 247, 244, 0);
					}
					if (Menu::Option("Orange")) {
						int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
						VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 247, 91, 0);
					}
					if (Menu::Option("Aqua")) {
						int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
						VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 40, 255, 255);
					}
					if (Menu::Option("White")) {
						int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
						VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 255, 255, 255);
					}
					if (Menu::Option("Magenta")) {
						int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
						VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 102, 0, 35);
					}
					if (Menu::Option("Purple")) {
						int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
						VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 53, 0, 83);
					}
					if (Menu::Option("Dark Green")) {
						int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
						VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 0, 118, 0);
					}
					if (Menu::Option("Rose Red")) {
						int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
						VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(VehID, 8);
						VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(VehID, 161, 0, 0);
					}
				}
						  break;

				case sounds:
				{
					Menu::Title(" ");
					// Menu::Subtitle("SOUNDS");
					// Menu::Subtitle("Sounds");
					if (Menu::Option("BACK"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "BACK", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
					if (Menu::Option("SELECT"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "SELECT", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
					if (Menu::Option("NAV_UP_DOWN"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
					if (Menu::Option("QUIT"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "QUIT", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
					if (Menu::Option("NO"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "NO", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
					if (Menu::Option("YES"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "YES", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
					if (Menu::Option("CONTINUE"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "CONTINUE", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
					if (Menu::Option("SELECT 2"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "SELECT", "HUD_FRONTEND_MP_SOUNDSET", 0);
					}
					if (Menu::Option("LOSER"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "LOSER", "HUD_AWARDS", 0);
					}
					if (Menu::Option("PROPERTY_PURCHASE"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "PROPERTY_PURCHASE", "HUD_AWARDS", 0);
					}
					if (Menu::Option("RACE_PLACED"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "RACE_PLACED", "HUD_AWARDS", 0);
					}
					if (Menu::Option("OTHER_TEXT"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "OTHER_TEXT", "HUD_AWARDS", 0);
					}
					if (Menu::Option("TENNIS_POINT_WON"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "TENNIS_POINT_WON", "HUD_AWARDS", 0);
					}
					if (Menu::Option("COLLECTED"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "COLLECTED", "HUD_AWARDS", 0);
					}
					if (Menu::Option("SHOOTING_RANGE_ROUND_OVER"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "SHOOTING_RANGE_ROUND_OVER", "HUD_AWARDS", 0);
					}
					if (Menu::Option("MEDAL_GOLD"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "MEDAL_GOLD", "HUD_AWARDS", 0);
					}
					if (Menu::Option("MEDAL_SILVER"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "MEDAL_SILVER", "HUD_AWARDS", 0);
					}
					if (Menu::Option("MEDAL_BRONZE"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "MEDAL_BRONZE", "HUD_AWARDS", 0);
					}
					if (Menu::Option("FLIGHT_SCHOOL_LESSON_PASSED"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "FLIGHT_SCHOOL_LESSON_PASSED", "HUD_AWARDS", 0);
					}
					if (Menu::Option("Phone_Generic_Key_01"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "Phone_Generic_Key_01", "HUD_MINIGAME_SOUNDSET", 0);
					}
					if (Menu::Option("Phone_Generic_Key_02"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "Phone_Generic_Key_02", "HUD_MINIGAME_SOUNDSET", 0);
					}
					if (Menu::Option("Phone_Generic_Key_03"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "Phone_Generic_Key_03", "HUD_MINIGAME_SOUNDSET", 0);
					}
					if (Menu::Option("ScreenFlash"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "ScreenFlash", "MissionFailedSounds", 0);
					}
					if (Menu::Option("TIME_LAPSE_MASTER"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "TIME_LAPSE_MASTER", "0", 0);
					}
					if (Menu::Option("DRUG_TRAFFIC_AIR_SCREAMS"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "DRUG_TRAFFIC_AIR_SCREAMS", "0", 0);
					}
					if (Menu::Option("DRUG_TRAFFIC_AIR_BOMB_DROP_ERROR_MASTER"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "DRUG_TRAFFIC_AIR_BOMB_DROP_ERROR_MASTER", "0", 0);
					}
					if (Menu::Option("Trevor_4_747_TV"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "Trevor_4_747_TV", "0", 0);
					}
					if (Menu::Option("Altitude_Warning"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "Altitude_Warning", "EXILE_1", 0);
					}
					if (Menu::Option("Falling_Crates"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "Falling_Crates", "EXILE_1", 0);
					}
					if (Menu::Option("FocusOut"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "FocusOut", "HintCamSounds", 0);
					}
					if (Menu::Option("FocusIn"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "FocusIn", "HintCamSounds", 0);
					}
					if (Menu::Option("ScreenFlash"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "ScreenFlash", "WastedSounds", 0);
					}
					if (Menu::Option("Bed"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "Bed", "WastedSounds", 0);
					}
					if (Menu::Option("TextHit"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "TextHit", "WastedSounds", 0);
					}
					if (Menu::Option("MP_Flash"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "MP_Flash", "WastedSounds", 0);
					}
					if (Menu::Option("MP_Impact"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "MP_Impact", "WastedSounds", 0);
					}
					if (Menu::Option("SwitchRedWarning"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "SwitchRedWarning", "SPECIAL_ABILITY_SOUNDSET", 0);
					}
					if (Menu::Option("SwitchWhiteWarning"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "SwitchWhiteWarning", "SPECIAL_ABILITY_SOUNDSET", 0);
					}
					if (Menu::Option("Barge_Door"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "Barge_Door", "Prologue_Sounds", 0);
					}
					if (Menu::Option("Guard_Headshot"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "Guard_Headshot", "Prologue_Sounds", 0);
					}
					if (Menu::Option("Security_Door_Alarm"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "Security_Door_Alarm", "Prologue_Sounds", 0);
					}
					if (Menu::Option("COPS_ARRIVE"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "COPS_ARRIVE", "Prologue_Sounds", 0);
					}
					if (Menu::Option("Security_Door_Bomb_Bleeps"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "Security_Door_Bomb_Bleeps", "Prologue_Sounds", 0);
					}
					if (Menu::Option("Train_Horn"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "Train_Horn", "Prologue_Sounds", 0);
					}
					if (Menu::Option("Train_Bell"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "Train_Bell", "Prologue_Sounds", 0);
					}
					if (Menu::Option("Cops_Arrive_2"))
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "Cops_Arrive_2", "Prologue_Sounds", 0);
					}
				}break;

				case editObj:
				{


					Menu::Title("");
					// Menu::Subtitle("Edit Object");
					// Menu::Subtitle(spwndObjectsNames[selecObj]);
					if (Menu::Option("Delete")) {
						RequestControlOfEnt(latestObj);
						ENTITY::DELETE_ENTITY(&latestObj);
						spwndObjectsNames[selecObj] = NULL;
						spwndObjects[selecObj] = NULL;
						MapModObjs.pop_back();
						Menu::MenuLevelHandler::BackMenu();
					}
					if (Menu::Toggle("Freeze", freezeObj)) {
						ENTITY::FREEZE_ENTITY_POSITION(latestObj, freezeObj);
					}
					if (Menu::Toggle("Collision", collisionObj)) {
						ENTITY::SET_ENTITY_COLLISION(latestObj, collisionObj, true);
					}
					if (Menu::Float("X", MoveX, -80000000.f, 80000000.f, .5f)) {
						RequestControlOfEnt(latestObj);
						Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
						Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
						ENTITY::SET_ENTITY_COORDS(latestObj, MoveX, objCoords.y, objCoords.z, objRot.x, objRot.y, objRot.z, false);
					}
					if (Menu::Float("Y", MoveY, -80000000.f, 80000000.f, .5f)) {
						RequestControlOfEnt(latestObj);
						Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
						Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
						ENTITY::SET_ENTITY_COORDS(latestObj, objCoords.x, MoveY, objCoords.z, objRot.x, objRot.y, objRot.z, false);
					}
					if (Menu::Float("Z", MoveZ, -80000000.f, 80000000.f, .5f)) {
						RequestControlOfEnt(latestObj);
						Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
						Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
						ENTITY::SET_ENTITY_COORDS(latestObj, objCoords.x, objCoords.y, MoveZ, objRot.x, objRot.y, objRot.z, false);
					}
					if (Menu::Float("Roll", roll1, 0.f, 360, 2.f)) {
						RequestControlOfEnt(latestObj);
						Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
						Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
						ENTITY::SET_ENTITY_ROTATION(latestObj, objRot.x, roll1, objRot.z, 1, true);
					}
					if (Menu::Float("Yaw", yaw1, 0.f, 360, 2.f)) {
						RequestControlOfEnt(latestObj);
						Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
						Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
						ENTITY::SET_ENTITY_ROTATION(latestObj, objRot.x, objRot.y, yaw1, 1, true);
					}
					if (Menu::Float("Pitch", pitch1, 0.f, 360, 2.f)) {
						RequestControlOfEnt(latestObj);
						Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
						Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
						ENTITY::SET_ENTITY_ROTATION(latestObj, pitch1, objRot.y, objRot.z, 1, true);
					}
				}
				break;

				case editObjj:
				{
					Menu::Title(spwndObjectsNames[selecObjj]);
					// Menu::Subtitle("EDIT OBJECT");

					if (Menu::Option("Delete")) {
						RequestControlOfEnt(latestObjj);
						ENTITY::DELETE_ENTITY(&latestObjj);
						spwndObjectsNames[selecObjj] = NULL;
						spwndObjects[selecObjj] = NULL;
						MapModObjs.pop_back();
						Menu::MenuLevelHandler::BackMenu();
					}
					if (Menu::Toggle("Freeze", freezeObjj)) {
						ENTITY::FREEZE_ENTITY_POSITION(latestObj, freezeObjj);
					}
					if (Menu::Toggle("Collision", collisionObjj)) {
						ENTITY::SET_ENTITY_COLLISION(latestObjj, collisionObjj, true);
					}
					if (Menu::Float("X", MoveX, 0.f, 100000000.f, .5f)) {
						RequestControlOfEnt(latestObj);
						Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
						Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
						ENTITY::SET_ENTITY_COORDS(latestObj, MoveX, objCoords.y, objCoords.z, objRot.x, objRot.y, objRot.z, true);
					}
					if (Menu::Float("Y", MoveY, 0.f, 100000000.f, .5f)) {
						RequestControlOfEnt(latestObj);
						Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
						Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
						ENTITY::SET_ENTITY_COORDS(latestObj, objCoords.x, MoveY, objCoords.z, objRot.x, objRot.y, objRot.z, true);
					}
					if (Menu::Float("Z", MoveZ, 0.f, 100000000.f, .5f)) {
						RequestControlOfEnt(latestObj);
						Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
						Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObj, 0);
						ENTITY::SET_ENTITY_COORDS(latestObj, objCoords.x, objCoords.y, MoveZ, objRot.x, objRot.y, objRot.z, true);
					}
					if (Menu::Float("Roll", roll1, 0.f, 360, 2.f)) {
						RequestControlOfEnt(latestObjj);
						Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObjj, 1);
						Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObjj, 0);
						ENTITY::SET_ENTITY_ROTATION(latestObjj, objRot.x, roll1, objRot.z, 1, true);
					}
					if (Menu::Float("Yaw", yaw1, 0.f, 360, 2.f)) {
						RequestControlOfEnt(latestObjj);
						Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObjj, 1);
						Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObjj, 0);
						ENTITY::SET_ENTITY_ROTATION(latestObjj, objRot.x, objRot.y, yaw1, 1, true);
					}
					if (Menu::Float("Pitch", pitch1, 0.f, 360, 2.f)) {
						RequestControlOfEnt(latestObjj);
						Vector3 objCoords = ENTITY::GET_ENTITY_COORDS(latestObjj, 1);
						Vector3 objRot = ENTITY::GET_ENTITY_ROTATION(latestObjj, 0);
						ENTITY::SET_ENTITY_ROTATION(latestObjj, pitch1, objRot.y, objRot.z, 1, true);
					}
				}
				break;

				case dropOnlineall:
				{
					Menu::Title("Drop Player");
					// Menu::Subtitle("DROP PLAYER");


					Menu::Toggle("~w~Cash Drop", Features::alldrop, [] { Features::AllDrop(Features::alldrop); });
					if (Menu::Int("Amount", Features::DropAmount, 1, 2500))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::DropAmount = NumberKeyboard();
						}
					}


					if (Menu::Int("Height", Features::DropHeight, 1, 50))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::DropHeight = NumberKeyboard();
						}
					}


					if (Menu::Int("Delay", Features::DropDelay, 50, 1000))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::DropDelay = NumberKeyboard();
						}
					}

					Menu::Int("Bags", Features::Bags, 0, 20);

					Menu::Break("Models");
					dropModelsSelect();
				}
				break;

				case dropOnline:
				{
					Menu::Title("Drop Player");
					// Menu::Subtitle("DROP MONEY");

					if (selecArrow) {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
						GRAPHICS::DRAW_MARKER(29, coords.x, coords.y, coords.z + 1.3f, 0, 0, 0, 0, 180, 0, 1, 1, 1, 0, 255, 255, 200, 1, 1, 1, 0, 0, 0, 0);
					}
					Menu::Toggle("Drop", Features::cashdrop69Toggle[Features::Online::selectedPlayer]);
					if (Menu::Int("Amount", Features::DropAmount, 1, 2500))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::DropAmount = NumberKeyboard();
						}
					}


					if (Menu::Int("Height", Features::DropHeight, 1, 50))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::DropHeight = NumberKeyboard();
						}
					}


					if (Menu::Int("Delay", Features::DropDelay, 50, 1000))
					{
						if (IsKeyPressed(VK_NUMPAD5)) {
							Features::DropDelay = NumberKeyboard();
						}
					}

					Menu::Int("Bags", Features::Bags, 0, 20);

					Menu::Break("Models");
					dropModelsSelect();
				}
				break;
				}
				Menu::End(0);
				WAIT(0);
				}
				}
			}
		}

		void ScriptMain() {
			srand(GetTickCount());
			Features::TimePD = timeGetTime();
			Features::TimePD1 = timeGetTime();
			Features::TimePD2 = timeGetTime();
			Features::TimePD3 = timeGetTime();
			Features::TimePD4 = timeGetTime();
			Features::TimePD5 = timeGetTime();
			Features::TimePD6 = timeGetTime();
			Features::TimePD7 = timeGetTime();
			Features::TimePD8 = timeGetTime();
			main();
			//BannerShowing();
		}

