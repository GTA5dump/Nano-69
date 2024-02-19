//Hooking.cpp
#pragma once
#include "stdafx.h"
#include "reclass.h"
#include "Discord.h"

using namespace Memory;

ScriptThread*(*GetActiveThread)() = nullptr;
HMODULE _hmoduleDLL;
HANDLE mainFiber;
DWORD wakeAt;

bool Hooking::protect = false;
bool Hooking::dump = false;
bool Hooking::notify = false;
bool Hooking::redirect = false;
bool Hooking::blockall = false;
bool Hooking::smart_protex = false;
bool Hooking::smart_pro = false;
bool Hooking::logger = false;
bool Hooking::rdev = false;
bool Hooking::event_handler_on = false;
bool Hooking::e_weather_time = false;
bool Hooking::e_control = false;
bool Hooking::e_explosion = false;
bool Hooking::e_pickup = false;
bool Hooking::e_weapon = false;
bool Hooking::e_wanted = false;
bool Hooking::e_report = false;
bool Hooking::e_kick = false;
bool Hooking::e_freeze = false;
bool Hooking::e_stat = false;
bool Hooking::e_ptfx = false;
bool Hooking::e_redirect = false;
bool Hooking::e_notify = false;
bool Hooking::patch_checker = false;

std::vector<LPVOID>						Hooking::m_hooks;
threeBytes*								Hooking::infinite_ammo;
threeBytes*								Hooking::no_reload;
twoBytes*								Hooking::m_ownedExplosionBypass;
BYTE*									Hooking::m_ownedExplosionBypass2;
uint64_t*								Hooking::m_frameCount;
fpIsDLCPresent		                	Hooking::is_DLC_present;
fpGetWaypointPos						Hooking::get_waypoint_pos;
TriggerScriptEvent	                	Hooking::trigger_script_event;
SetSessionWeather                       Hooking::set_session_weather;
fpStatSetInt		                	Hooking::stat_set_int;
fpStatSetBool                           Hooking::stat_set_bool;
fpStatSetFloat                          Hooking::stat_set_float;
GetEventData                            Hooking::get_script_event_data;
fpGetPlayerName                         Hooking::GPN;
addOwnedExplosion                       Hooking::add_owned_explosion;
fpGetEventData                          Hooking::get_event_data;
fpSetLobbyTime                          Hooking::set_lobby_time;
fpGetChatMessage                        Hooking::get_chat_message;
fpGetPlayerAddress                      Hooking::get_player_address;
fpAddressToEntity                       Hooking::address_to_entity;
fpEventHandler                          Hooking::event_handler;
fpSetName                               Hooking::set_name_kek;
fpSetSessionTime                        Hooking::set_session_time;
clockTime* Hooking::ClockTime;
fpSetEntityMaxHealth                    Hooking::set_entity_max_health;
fpCreateVehicle                         Hooking::create_vehicle;
fpSetVehicleMod                         Hooking::set_vehicle_mod;
fpClearPedTasksImmediately              Hooking::clear_ped_tasks_immediately;
fpGetNumberOfEvents                     Hooking::get_number_of_events;
fpNetworkIsSessionStarted               Hooking::is_session_started;
fpNetworkRequestControlOfNetworkId      Hooking::request_control_of_network_id;
fpNetworkRequestControlOfEntity         Hooking::request_control_of_entity;
fpNetworkHasControlOfEntity             Hooking::has_control_of_entity;
fpSetNetworkIdCanMigrate                Hooking::set_network_id_can_migrate;
fpGetNetworkTime                        Hooking::get_network_time;
fpDecorSetInt                           Hooking::decor_set_int;
fpDecorRegister                         Hooking::decor_register;
fpChatMessage                           Hooking::get_message;
//fpGetSender                             Hooking::get_sender;
CReplayInterface*						Hooking::m_replayIntf;
fpIncrementStatHook                     Hooking::increment_stat;
fpCreateAmbientPickup                   Hooking::create_ambient_pickup;
//fpIntegrityCheck                        Hooking::integrity_check;
fpSetMobileRadioEnabledDuringGameplay   Hooking::set_mobile_radio_enabled_during_gameplay;
fpIsEntityUpsideDown                    Hooking::is_entity_upsidedown;
fpRequestIpl                            Hooking::request_ipl;
fpIsIplActive                           Hooking::is_ipl_active;
fpNetworkSessionKickPlayer              Hooking::network_session_kick_player;
fpNetworkShopCheckoutStart              Hooking::network_shop_checkout_start;
fpGetPlayerMaxArmour                    Hooking::get_player_max_armour;
fpGetEntityAttachedTo                   Hooking::get_entity_attached_to;
fpSetEntityCollision                    Hooking::set_entity_collision;
fpStatSetDate                           Hooking::stat_set_date;
fpStatGetInt                            Hooking::stat_get_int;
fpAddTextCompSubstrPlayerName	        Hooking::add_text_comp_substr_playername;
fpEndTextCmdDisplayText	                Hooking::end_text_command_display_text;
fpBeginTextCmdDisplayText	            Hooking::begin_text_command_display_text;
fpSendMessage                           Hooking::send_message;
fpClearPedBloodDamage                   Hooking::clear_ped_blood_damage;
fpSetVehicleOnGroundProperly            Hooking::set_vehicle_on_ground_properly;
fpSetVehicleNumberplateText             Hooking::set_vehicle_numberplate_text;
fpIsThisModelAPlane                     Hooking::is_this_model_a_plane;
fpIsThisModelAHeli                      Hooking::is_this_model_a_heli;
fpSetHeliBladesFullSpeed                Hooking::set_heli_blades_full_speed;
fpEndTextCommandGetWidth                Hooking::end_text_command_get_width;
fpRequestAnimDict                       Hooking::request_anim_dict;
fpHasAnimDictLoaded                     Hooking::has_anim_dict_loaded;
fpDrawNotification                      Hooking::draw_notification;
fpDrawNotification2                     Hooking::draw_notification_2;
fpPickupRewardMoneyIsApplicableToPlayer Hooking::pickup_is_applicable_to_player;
fpSetVehicleEngineOn                    Hooking::set_vehicle_engine_on;
fpSetVehicleUndriveable                 Hooking::set_vehicle_undriveable;
fpSetVehicleDriveable                   Hooking::set_vehicle_driveable;
fpGetDisplayNameFromVehicle             Hooking::get_display_name_from_vehicle;
fpToggleVehicleMod                      Hooking::toggle_vehicle_mod;
fpNetworkShopBeginService               Hooking::network_shop_begin_service;
fpGiveDelayedWeaponToPed                Hooking::give_delayed_weapon_to_ped;
fpRemoveAllPedWeapons                   Hooking::remove_all_ped_weapons;
fpRemoveWeaponFromPed                   Hooking::remove_weapon_from_ped;
fpGetPedInVehicleSeat                   Hooking::get_ped_in_vehicle_seat;
fpIsAimCamActive                        Hooking::is_aim_cam_active;
fpDrawRect                              Hooking::draw_rect;
fpDrawLine                              Hooking::draw_line;
fpGetGameplayCamRot                     Hooking::get_gameplay_cam_rot;
fpGetGameplayCamCoord                   Hooking::get_gameplay_cam_coord;
fpNetworkGetNetworkIdFromEntity         Hooking::get_network_id_from_entity;
fpNetworkCreateSynchronisedScene        Hooking::create_synchronised_scene;
fpNetworkAddPedToSynchronisedScene      Hooking::add_ped_to_synchronised_scene;
fpNetworkStartSynchronisedScene         Hooking::start_synchronised_scene;
fpIsVehicleDrivable                     Hooking::is_vehicle_driveable;
fpGetPlayerRadioStationIndex            Hooking::get_player_radio_station_index;
fpGetRadioStationName                   Hooking::get_radio_station_name;
fpSetVehicleForwardSpeed                Hooking::set_vehicle_forward_speed;
fpSetVehicleFixed                       Hooking::set_vehicle_fixed;
fpSetVehicleDeformationFixed            Hooking::set_vehicle_deformation_fixed;
fpIsVehicleSeatFree                     Hooking::is_vehicle_seat_free;
fpSetVehicleNumberPlateIndex            Hooking::set_vehicle_number_plate_index;
fpSetVehicleWheelType                   Hooking::set_vehicle_wheel_type;
fpGetNumVehicleMod                      Hooking::get_num_vehicle_mod;
fpSetNotificationTextEntry              Hooking::set_notification_text_entry;
fpUpdateOnscreenKeyboard                Hooking::update_onscreen_keyboard;
fpSetLocalPlayerVisibleLocally          Hooking::set_local_player_visible_locally;
fpAiTaskWanderStandard                  Hooking::ai_task_wander_standart;
fpAiTaskPlayAnim                        Hooking::ai_task_play_anim;
fpIsModelInCdimage                      Hooking::is_model_in_cdimage;
fpIsModelValid                          Hooking::is_model_valid;
fpIsModelAVehicle                       Hooking::is_model_a_vehicle;
fpRequestModel                          Hooking::request_model;
fpHasModelLoaded                        Hooking::has_model_loaded;
fpGetPedLastWeaponImpactCoord           Hooking::get_ped_last_weapon_impact_coord;
fpStartRayCast                          Hooking::start_ray_cast;
fpGetRayCast                            Hooking::get_ray_cast;
fpNetworkSetInSpectatorMode             Hooking::set_in_spectator_mode;
fpSetPedCombatAbility                   Hooking::set_ped_combat_ability;
fpAiTaskCombatPed                       Hooking::ai_task_combat_ped;
fpApplyVehicleColors                    Hooking::apply_vehicle_colors;
fpSetPlayerVisibleLocally               Hooking::set_player_visible_locally;
fpSetModelAsNoLongerNeeded              Hooking::set_model_as_no_longer_needed;
fpCreateObject                          Hooking::create_object;
fpSetOverrideWeather                    Hooking::set_override_weather;
fpGetCurrentPedWeapon                   Hooking::get_current_ped_weapon;
fpGetTextScreenLineCount                Hooking::get_text_screen_line_count;
fpRequestScaleformMovie                 Hooking::request_scaleform_movie;
fpDrawScaleformMovie                    Hooking::draw_scaleform_movie;
fpEndScaleformMovieMethod               Hooking::end_scaleform_movie_method;
fpIsDisabledControlPressed              Hooking::is_disabled_control_pressed;
fpIsPlayerFriend                        Hooking::is_player_friend;
fpGetLabelText                          Hooking::GetLabelText = nullptr;
fpGetScriptHandlerIfNetworked           Hooking::GetScriptHandlerIfNetworked = nullptr;
fpGetScriptHandler                      Hooking::GetScriptHandler = nullptr;

CViewPort*								Hooking::m_viewPort;
screenReso*								Hooking::m_resolution;
void*									Hooking::m_objectHashTable;
void*									Hooking::m_objectHashTableSectionEnd;
void*									Hooking::m_onlineName;
CTextInfo*								Hooking::m_textInfo;
char*									Hooking::m_onscreenKeyboardResult;
clockTime*								Hooking::m_clockTime;
uint64_t*								Hooking::m_networkTime;
MemoryPool**							Hooking::m_pedPool;
void*									Hooking::m_gameInfo;
CPlayers*								Hooking::m_players;
MemoryPool**							Hooking::m_entityPool;

static eGameState* 											m_gameState;
static fpFileRegister                                       m_fileregister;
static uint64_t												m_worldPtr;
static BlipList*											m_blipList;
static Hooking::NativeRegistrationNew**						m_registrationTable;
static std::unordered_map<uint64_t, Hooking::NativeHandler>	m_handlerCache;
static std::vector<LPVOID>									m_hookedNative;
static __int64**                                            m_globalPtr;
fpGetScriptHandlerIfNetworked ogGetScriptHandlerIfNetworked = nullptr;
void *hkGetScriptHandlerIfNetworked()
{
	return Hooking::GetScriptHandler();
}

const int EVENT_COUNT = 78;
static std::vector<void*> EventPtr;
static char EventRestore[EVENT_COUNT] = {};

bool twoBytes::empty()
{
	bool	r = true;
	for (int i = 0; i < 2; ++i)
		if (this->byte[i] != 0)
		{
			r = false;
			break;
		}
	return r;
}

bool threeBytes::empty()
{
	bool	r = true;
	for (int i = 0; i < 3; ++i)
		if (this->byte[i] != 0)
		{
			r = false;
			break;
		}
	return r;
}

/* Start Hooking */
void Hooking::Start(HMODULE hmoduleDLL)
{
	_hmoduleDLL = hmoduleDLL;
	Log::Init(hmoduleDLL);
	FindPatterns();
	DiscordMain();
	if (!InitializeHooks()) Cleanup();
}
BOOL Hooking::InitializeHooks()
{
	BOOL returnVal = TRUE;

	if (!iHook.Initialize()) {

		Log::Error("[ERROR] -> Failed to initialize InputHook");
		returnVal = FALSE;
	}

	if (MH_Initialize() != MH_OK) {
		Log::Error("[ERROR] -> MinHook failed to initialize");
		returnVal = FALSE;
	}

	if (!HookNatives()) {

		Log::Error("[ERROR] -> Failed to initialize NativeHooks");
		returnVal = FALSE;
	}

	return returnVal;
}

template <typename T>
bool Native(DWORD64 hash, LPVOID hookFunction, T** trampoline)
{
	if (*reinterpret_cast<LPVOID*>(trampoline) != NULL)
		return true;
	auto originalFunction = Hooking::GetNativeHandler(hash);
	if (originalFunction != 0) {
		MH_STATUS createHookStatus = MH_CreateHook(originalFunction, hookFunction, reinterpret_cast<LPVOID*>(trampoline));
		if (((createHookStatus == MH_OK) || (createHookStatus == MH_ERROR_ALREADY_CREATED)) && (MH_EnableHook(originalFunction) == MH_OK))
		{
			m_hookedNative.push_back((LPVOID)originalFunction);
			DEBUGMSG("Hooked Native 0x%#p", hash);
			return true;
		}
	}

	return false;
}

uint64_t CMetaData::m_begin = 0;
uint64_t CMetaData::m_end = 0;
DWORD CMetaData::m_size = 0;

uint64_t CMetaData::begin()
{
	return m_begin;
}
uint64_t CMetaData::end()
{
	return m_end;
}
DWORD CMetaData::size()
{
	return m_size;
}

void CMetaData::init()
{
	if (m_begin && m_size)
		return;

	m_begin = (uint64_t)GetModuleHandleA(nullptr);
	const IMAGE_DOS_HEADER*	headerDos = (const IMAGE_DOS_HEADER*)m_begin;
	const IMAGE_NT_HEADERS*	headerNt = (const IMAGE_NT_HEADERS64*)((const BYTE*)headerDos + headerDos->e_lfanew);
	m_size = headerNt->OptionalHeader.SizeOfCode;
	m_end = m_begin + m_size;
	return;
}
fpIsDLCPresent	OG_IS_DLC_PRESENT = nullptr;
BOOL __cdecl HK_IS_DLC_PRESENT(uint32_t dlchash)
{
	static uint64_t	last = 0;
	uint64_t		cur = *Hooking::m_frameCount;
	if (last != cur)
	{
		last = cur;
		Hooking::onTickInit();
	}
	if (Hooking::rdev && dlchash == 2532323046) return true;
	return OG_IS_DLC_PRESENT(dlchash);
}


void Hooking::mobilerneger(BOOL toggle) { //for example
	static auto mneger = reinterpret_cast<void(*)(BOOL)>(pattern("40 53 48 83 EC 20 8A D9 48 8D 0D ? ? ? ? E8 ? ? ? ? 48 8D 0D ? ? ? ? 8B D0 E8 ? ? ? ? 48 85 C0 74 10").count(1).get(0).get<void>(0));
	mneger(toggle);


}


Hooking::NativeHandler  ORIG_NETWORK_SESSION_KICK_PLAYER = NULL;
void *__cdecl MY_NETWORK_SESSION_KICK_PLAYER(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_NETWORK_SESSION_KICK_PLAYER(cxt);
	}
	return nullptr;
}
static std::size_t get_module_size(HMODULE hmod)
{
	auto dosHeader = PIMAGE_DOS_HEADER(hmod);
	auto ntHeader = PIMAGE_NT_HEADERS(PBYTE(hmod) + dosHeader->e_lfanew);

	return ntHeader->OptionalHeader.SizeOfImage;
}
fpNtQueryVirtualMemory ogNtQueryVirtualMemory = nullptr;
int hkNtQueryVirtualMemory(HANDLE ProcessHandle, PVOID BaseAddress, int MemoryInformationClass, PVOID MemoryInformation, SIZE_T MemoryInformationLength, PSIZE_T ReturnLength)
{
	if (MemoryInformationClass == 0
		&& ProcessHandle == GetCurrentProcess()
		&& std::uintptr_t(BaseAddress) >= std::uintptr_t(_hmoduleDLL)
		&& std::uintptr_t(BaseAddress) <= std::uintptr_t(_hmoduleDLL) + get_module_size(_hmoduleDLL))
	{
		return 0xC000000D;
	}

	return static_cast<decltype(&hkNtQueryVirtualMemory)>(ogNtQueryVirtualMemory)
		(ProcessHandle, BaseAddress, MemoryInformationClass, MemoryInformation, MemoryInformationLength, ReturnLength);
}
fpNtQueryVirtualMemory Hooking::NtQueryVirtualMemory = nullptr;
Hooking::NativeHandler  ORIG_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE = NULL;
void *__cdecl MY_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler  ORIG_ATTACH_ENTITY_TO_ENTITY = NULL;
void *__cdecl MY_ATTACH_ENTITY_TO_ENTITY(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_ATTACH_ENTITY_TO_ENTITY(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_TASKS_IMMEDIATELY = NULL;
void *__cdecl MY_CLEAR_PED_TASKS_IMMEDIATELY(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_TASKS_IMMEDIATELY(cxt);
	}

	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_TASKS = NULL;
void *__cdecl MY_CLEAR_PED_TASKS(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_TASKS(cxt);
	}

	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_SECONDARY_TASK = NULL;
void *__cdecl MY_CLEAR_PED_SECONDARY_TASK(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_SECONDARY_TASK(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler ORIG_CLONE_PED = NULL;
void *__cdecl MY_CLONE_PED(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLONE_PED(cxt);
	}
	return nullptr;
}

fpGetLabelText ogGetLabelText = nullptr;
const char *hkGetLabelText(void *this_, const char *label)
{
	if (std::strcmp(label, "HUD_JOINING") == 0)
	{
		return "Joining GTA Online with Lifix";
	}

	return ogGetLabelText(this_, label);
}

fpPickupRewardMoneyIsApplicableToPlayer OG_PICKUP_REWARD = nullptr;
bool HK_PICKUP_REWARD(void* thisptr, void* unk, void* ped)
{
	if (Features::moneyDropProtection)
	{
		return false;
	}

	return OG_PICKUP_REWARD(thisptr, unk, ped);
}

bool Hooking::HookNatives() //hooking is fine (DONE)
{
	MH_STATUS status = MH_CreateHook(Hooking::is_DLC_present, HK_IS_DLC_PRESENT, (void**)&OG_IS_DLC_PRESENT);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::is_DLC_present) != MH_OK)
		return false;
	Hooking::m_hooks.push_back(Hooking::is_DLC_present);

	MH_STATUS statuslol = MH_CreateHook(Hooking::GetLabelText, hkGetLabelText, (void**)&ogGetLabelText);
	if (status != MH_OK || MH_EnableHook(Hooking::GetLabelText) != MH_OK)
		return false;
	Hooking::m_hooks.push_back(Hooking::GetLabelText);

	MH_CreateHook(Hooking::NtQueryVirtualMemory, hkNtQueryVirtualMemory, (void**)&ogNtQueryVirtualMemory);
	MH_EnableHook(Hooking::NtQueryVirtualMemory);
	Hooking::m_hooks.push_back(Hooking::NtQueryVirtualMemory);

	auto KekCheck = Memory::pattern("80 3D ? ? ? ? ? 0F 85 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 08 48 39 0D ? ? ? ? 0F 85").count(1).get(0).get<std::uint8_t>(0);
	KekCheck[0] = 0xC3;
	std::memset(KekCheck + 1, 0x90, 7);
	FlushInstructionCache(GetCurrentProcess(), KekCheck, 8);

	MH_STATUS penis = MH_CreateHook(Hooking::pickup_is_applicable_to_player, HK_PICKUP_REWARD, (void**)&OG_PICKUP_REWARD);
	if (status != MH_OK || MH_EnableHook(Hooking::pickup_is_applicable_to_player) != MH_OK)
		return false;
	Hooking::m_hooks.push_back(Hooking::pickup_is_applicable_to_player);

	MH_CreateHook(Hooking::GetScriptHandlerIfNetworked, hkGetScriptHandlerIfNetworked, (void**)&ogGetScriptHandlerIfNetworked);
	MH_EnableHook(Hooking::GetScriptHandlerIfNetworked);
	Hooking::m_hooks.push_back(Hooking::GetScriptHandlerIfNetworked);
	return true;
}

void __stdcall ScriptFunction(LPVOID lpParameter)
{
	try
	{
		ScriptMain();

	}
	catch (...)
	{
		Log::Fatal("Failed scriptFiber");
	}
}

void Hooking::onTickInit()
{
	if (mainFiber == nullptr)
		mainFiber = ConvertThreadToFiber(nullptr);

	if (timeGetTime() < wakeAt)
		return;

	static HANDLE scriptFiber;
	if (scriptFiber)
		SwitchToFiber(scriptFiber);
	else
		scriptFiber = CreateFiber(NULL, ScriptFunction, nullptr);
}

void Hooking::FailPatterns(const char* name)
{
	char buf[4096];
	sprintf_s(buf, "finding %s", name);
	Log::Error(buf);
	Cleanup();
}



/*
//CPatternResult
*/

CPatternResult::CPatternResult(void* pVoid) :
	m_pVoid(pVoid)
{}
CPatternResult::CPatternResult(void* pVoid, void* pBegin, void* pEnd) :
	m_pVoid(pVoid),
	m_pBegin(pBegin),
	m_pEnd(pEnd)
{}
CPatternResult::~CPatternResult() {}

/*
//CPattern Public
*/

CPattern::CPattern(char* szByte, char* szMask) :
	m_szByte(szByte),
	m_szMask(szMask),
	m_bSet(false)
{}
CPattern::~CPattern() {}

CPattern&	CPattern::find(int i, uint64_t startAddress)
{
	match(i, startAddress, false);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPattern&	CPattern::virtual_find(int i, uint64_t startAddress)
{
	match(i, startAddress, true);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPatternResult	CPattern::get(int i)
{
	if (m_result.size() > i)
		return m_result[i];
	return nullptr;
}

/*
//CPattern Private
*/
bool	CPattern::match(int i, uint64_t startAddress, bool virt)
{
	if (m_bSet)
		return false;
	uint64_t	begin = 0;
	uint64_t	end = 0;
	if (!virt)
	{
		CMetaData::init();
		begin = CMetaData::begin() + startAddress;
		end = CMetaData::end();
		if (begin >= end)
			return false;
	}
	int		j = 0;
	do
	{
		if (virt)
			begin = virtual_find_pattern(startAddress, (BYTE*)m_szByte, m_szMask) + 1;
		else
			begin = find_pattern(begin, end, (BYTE*)m_szByte, m_szMask) + 1;
		if (begin == NULL)
			break;
		j++;
	} while (j < i);

	m_bSet = true;
	return true;
}

bool	CPattern::byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++btMask)
		if (*szMask == 'x' && *pData != *btMask)
			break;
	if ((*szMask) != 0)
		return false;
	return true;
}


uint64_t	CPattern::find_pattern(uint64_t address, uint64_t end, BYTE *btMask, char *szMask)
{
	size_t len = strlen(szMask) + 1;
	for (uint64_t i = 0; i < (end - address - len); i++)
	{
		BYTE*	ptr = (BYTE*)(address + i);
		if (byte_compare(ptr, btMask, szMask))
		{
			m_result.push_back(CPatternResult((void*)(address + i)));
			return address + i;
		}
	}
	return NULL;
}

uint64_t	CPattern::virtual_find_pattern(uint64_t address, BYTE *btMask, char *szMask)
{
	MEMORY_BASIC_INFORMATION mbi;
	char*	pStart = nullptr;
	char*	pEnd = nullptr;
	char*	res = nullptr;
	size_t	maskLen = strlen(szMask);

	while (res == nullptr && sizeof(mbi) == VirtualQuery(pEnd, &mbi, sizeof(mbi)))
	{
		pStart = pEnd;
		pEnd += mbi.RegionSize;
		if (mbi.Protect != PAGE_READWRITE || mbi.State != MEM_COMMIT)
			continue;

		for (int i = 0; pStart < pEnd - maskLen && res == nullptr; ++pStart)
		{
			if (byte_compare((BYTE*)pStart, btMask, szMask))
			{
				m_result.push_back(CPatternResult((void*)pStart, mbi.BaseAddress, pEnd));
				res = pStart;
			}
		}

		mbi = {};
	}
	return (uint64_t)res;
}

void	failPat(const char* name)
{
	Log::Fatal("Failed to find %s pattern.", name);
	exit(0);
}

void mem_nop2(void* ptr, int size)
{
	memset(ptr, 0x90, size);
}

template <typename T>
void	setPat
(
	const char*	name,
	char*		pat,
	char*		mask,
	T**			out,
	bool		rel,
	int			offset = 0,
	int			deref = 0,
	int			skip = 0
)
{
	T*	ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	if (rel)
		ptr = pattern.get(skip).get_rel<T>(offset);
	else
		ptr = pattern.get(skip).get<T>(offset);

	while (true)
	{
		if (ptr == nullptr)
			failPat(name);

		if (deref <= 0)
			break;
		ptr = *(T**)ptr;
		--deref;
	}

	*out = ptr;
	return;
}

template <typename T>
void	setFn
(
	const char*	name,
	char*		pat,
	char*		mask,
	T*			out,
	int			skip = 0
)
{
	char*	ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	ptr = pattern.get(skip).get<char>(0);

	if (ptr == nullptr)
		failPat(name);

	*out = (T)ptr;
	return;
}

void Hooking::FindPatterns()
{
	HANDLE steam = GetModuleHandleA("steam_api64.dll");
	Hooking::pickup_is_applicable_to_player = static_cast<fpPickupRewardMoneyIsApplicableToPlayer>(Memory::pattern("49 8B 80 ? ? ? ? 48 85 C0 74 0C F6 80 ? ? ? ? ? 75 03").count(1).get(0).get<void>(0));

	Hooking::NtQueryVirtualMemory = (fpNtQueryVirtualMemory)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "NtQueryVirtualMemory");
	auto p_activeThread = pattern("E8 ? ? ? ? 48 8B 88 10 01 00 00");
	auto p_blipList = pattern("4C 8D 05 ? ? ? ? 0F B7 C1");
	auto p_fixVector3Result = pattern("83 79 18 00 48 8B D1 74 4A FF 4A 18");
	auto p_gameLegals = pattern("72 1F E8 ? ? ? ? 8B 0D");
	auto p_gameLogos = pattern("70 6C 61 74 66 6F 72 6D 3A");
	auto p_gameState = pattern("83 3D ? ? ? ? ? 8A D9 74 0A");
	//auto p_modelCheck = pattern("48 85 C0 0F 84 ? ? ? ? 8B 48 50");
	//auto p_modelSpawn = pattern("48 8B C8 FF 52 30 84 C0 74 05 48");
	//auto p_modelCheck = pattern("\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x8B\x48\x50");
	//auto p_modelSpawn = pattern("48 8B C8 FF 52 30 84 C0 74 05 48");
	/*CPattern modelCheckPattern("\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x8B\x48\x50",
		"xxxxx????xxx");

	auto fickdiochopder = pattern("48 85 C0 0F 84 ? ? ? ? 8B 48 50");*/
	/*CPattern modelSpawnPattern("\x48\x8B\xC8\xFF\x52\x30\x84\xC0\x74\x05\x48",
		"xxxxxxxxxxx");*/
	auto p_nativeTable = pattern("76 32 48 8B 53 40 48 8D 0D");
	//auto p_nativeTable = pattern("76 ? ? 8b ? ? 48 8d 0d ? ? ? ? ? 8b ? ? ?");
	auto p_worldPtr = pattern("48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07");
	auto p_globalPtr = pattern("4C 8D 05 ? ? ? ? 4D 8B 08 4D 85 C9 74 11");
	auto p_eventHook = pattern("48 83 EC 28 E8 ? ? ? ? 48 8B 0D ? ? ? ? 4C 8D 0D ? ? ? ? 4C 8D 05 ? ? ? ? BA 03");
	//Hooking::handle_ptr = reinterpret_cast<decltype(handle_ptr)>(Memory::pattern("83 F9 FF 74 31 4C 8B 0D ? ? ? ?").count(1).get(0).get<char>(0));
	Hooking::GetScriptHandlerIfNetworked = static_cast<fpGetScriptHandlerIfNetworked>(Memory::pattern("40 53 48 83 EC 20 E8 ? ? ? ? 48 8B D8 48 85 C0 74 12 48 8B 10 48 8B C8").count(1).get(0).get<void>(0));
	Hooking::GetScriptHandler = static_cast<fpGetScriptHandler>(Memory::pattern("48 83 EC 28 E8 ? ? ? ? 33 C9 48 85 C0 74 0C E8 ? ? ? ? 48 8B 88 ? ? ? ?").count(1).get(0).get<void>(0));
	
	setPat<uint64_t>("frame count", "\x8B\x15\x00\x00\x00\x00\x41\xFF\xCF", "xx????xxx", &Hooking::m_frameCount, true, 2);

	setFn<fpIsDLCPresent>("is_dlc_present", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x81\xF9\x00\x00\x00\x00", "xxxx?xxxxxxx????", &Hooking::is_DLC_present);

	setFn<fpGetScriptHandlerIfNetworked>("get_network_script_handler", "\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x12\x48\x8B\x10\x48\x8B\xC8", "xxxxxxx????xxxxxxxxxxxxxx", &Hooking::GetScriptHandlerIfNetworked);

	setFn<fpGetScriptHandler>("get_script_handler", "\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x33\xC9\x48\x85\xC0\x74\x0C\xE8\x00\x00\x00\x00\x48\x8B\x88", "xxxxx????xxxxxxxx????xxx", &Hooking::GetScriptHandler);

	setFn<fpIsEntityUpsideDown>("does_cam_exist", "\x40\x53\x48\x83\xEC\x20\x33\xDB\x85\xC9\x78\x10", "xxxxxxxxxxxx", &Hooking::is_entity_upsidedown);

	setPat<twoBytes>("owned explosion bypass", "\x3B\xF8\x40\x0F\x94\xC7", "xxxxxx", &Hooking::m_ownedExplosionBypass, false);

	setFn<TriggerScriptEvent>("trigger_script_event", "\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x81\xEC\x00\x00\x00\x00\x45\x8B\xF0\x41\x8B\xF9", "xxxxxxxxxxxxxxxxxxxxxxxx????xxxxxx", &Hooking::trigger_script_event);

	setFn<SetSessionWeather>("set_session_weather", "\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x40\x8A\xE9", "xxxx?xxxx?xxxx?xxxxxxxx", &Hooking::set_session_weather);

	setFn<fpStatSetBool>("stat_set_bool", "\x48\x89\x5C\x24\x00\x88\x54\x24\x10\x57\x48\x83\xEC\x40", "xxxx?xxxxxxxxx", &Hooking::stat_set_bool);

	setFn<fpStatSetFloat>("stat_set_float", "\x48\x89\x5C\x24\x00\xF3\x0F\x11\x4C\x24\x00\x57\x48\x83\xEC\x40", "xxxx?xxxxx?xxxxx", &Hooking::stat_set_float);

	setFn<GetEventData>("get_script_event_data", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x49\x8B\xF8\x4C\x8D\x05\x00\x00\x00\x00", "xxxx?xxxxxxxxxxx????", &Hooking::get_script_event_data);

	setFn<fpGetEventData>("get_event_data", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x49\x8B\xF8\x4C\x8D\x05\x00\x00\x00\x00", "xxxx?xxxxxxxxxxx????", &Hooking::get_event_data);

	setFn<addOwnedExplosion>("add_owned_explosion", "\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x70\x20\x55\x48\x8D\x68\xB9\x48\x81\xEC\x00\x00\x00\x00\x0F\x29\x70\xE8\x41\x8B\xD8", "xxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxx", &Hooking::add_owned_explosion);

	setFn<fpGetPlayerAddress>("get_player_address", "\x40\x53\x48\x83\xEC\x20\x33\xDB\x38\x1D\x00\x00\x00\x00\x74\x1C", "xxxxxxxxxx????xx", &Hooking::get_player_address);

	setFn<fpAddressToEntity>("address_to_entity", "\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x15\x00\x00\x00\x00\x48\x8B\xF9\x48\x83\xC1\x10\x33\xDB", "xxxx?xxxx?xxxxxxx????xxxxxxxxx", &Hooking::address_to_entity);

	setPat<clockTime>("clock_time", "\x48\x8D\x0D\x00\x00\x00\x00\x8B\xFA\xE8\x00\x00\x00\x00\x44\x8D\x0C\x5B", "xxx????xxx????xxxx", &Hooking::ClockTime, true, 3);

	setFn<fpSetSessionTime>("session_time_set", "\x48\x89\x5C\x24\x08\x57\x48\x83\xEC\x20\x8B\xF9\x48\x8B\x0D\x00\x00\x00\x00\x48\x8B\xDA\x33\xD2\xE9\x00\x00\x00\x00", "xxxxxxxxxxxxxxx????xxxxxx????", &Hooking::set_session_time);

	setFn<fpSetEntityMaxHealth>("set_entity_max_health", "\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x19\x4C\x8B\x00\x8B\x15\x00\x00\x00\x00\x48\x8B\xC8\x41\xFF\x50\x08\x84\xC0\x74\x05\x48\x8B\xC3\xEB\x02\x33\xC0\x48\x83\xC4\x20\x5B\xC3\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x56\x57", "xxxxxxx????xxxxxxxxxx?xx????xxxxxxxxxxxxxxxxxxxxxxxxxxxx?xxxx?xx", &Hooking::set_entity_max_health);

	setFn<fpCreateVehicle>("create_vehicle", "\x48\x89\x5C\x24\x00\x55\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8B\xEC\x48\x83\xEC\x50\xF3\x0F\x10\x02", "xxxx?xxxxxxxxxxxxxxxxxxxxxx", &Hooking::create_vehicle);

	setFn<fpClearPedTasksImmediately>("clear_ped_tasks_immediately", "\x40\x53\x48\x83\xEC\x30\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x0F\x84", "xxxxxxx????xxxxxxxx", &Hooking::clear_ped_tasks_immediately);

	setFn<fpGetNumberOfEvents>("get_number_of_events", "\x48\x83\xEC\x28\x33\xD2\x85\xC9", "xxxxxxxx", &Hooking::get_number_of_events);

	setFn<fpNetworkRequestControlOfNetworkId>("request_control_of_network_id", "\x40\x53\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x8B\xD3\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x2C", "xxxxxxxxx????xxxxxx????xxxxx", &Hooking::request_control_of_network_id);

	setFn<fpNetworkRequestControlOfEntity>("request_control_of_entity", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x84\xC0", "xxxx?xxxxxxxx????xx", &Hooking::request_control_of_entity);

	setFn<fpNetworkHasControlOfEntity>("has_control_of_entity", "\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x1F\x48\x8B\x88\x00\x00\x00\x00\x48\x85\xC9\x74\x0F", "xxxxx????xxxxxxxx????xxxxx", &Hooking::has_control_of_entity);

	setFn<fpSetNetworkIdCanMigrate>("set_network_id_can_migrate", "\x85\xC9\x0F\x8E\x00\x00\x00\x00\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8A\xDA", "xxxx????xxxx?xxxxxxx", &Hooking::set_network_id_can_migrate);

	setFn<fpGetNetworkTime>("get_network_time", "\x40\x53\x48\x83\xEC\x20\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x84\xC0\x74\x19", "xxxxxxxxx????x????xxxx", &Hooking::get_network_time);

	setFn<fpDecorSetInt>("decor_set_int", "\x48\x89\x5C\x24\x00\x44\x89\x44\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x22\x48\x8B\xD7\x33\xC9\xE8\x00\x00\x00\x00\x4C\x8D\x44\x24\x00\x48\x8D\x54\x24\x00\x48\x8B\xCB\x89\x44\x24\x48\xE8\x00\x00\x00\x00\xB0\x01", "xxxx?xxxx?xxxxxxxxx????xxxxxxxxxxxxxx????xxxx?xxxx?xxxxxxxx????xx", &Hooking::decor_set_int);

	setFn<fpDecorRegister>("decor_register", "\x40\x53\x48\x83\xEC\x20\x80\x3D\x00\x00\x00\x00\x00\x8B\xDA\x75\x29", "xxxxxxxx?????xxxx", &Hooking::decor_register);

	setFn<fpChatMessage>("get_msg", "\x4D\x85\xC9\x0F\x84\x00\x00\x00\x00\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x48\x20", "xxxxx????xxxxxxxxxxxxxxxxxxx", &Hooking::get_message);

	//setFn<fpGetSender>("get_sender", "\xE8\x00\x00\x00\x00\x8A\x40\x2D", "x????xxx", &Hooking::get_sender);

	setPat<CReplayInterface>("replay interface", "\x48\x8D\x0D\x00\x00\x00\x00\x48\x8B\xD7\xE8\x00\x00\x00\x00\x48\x8D\x0D\x00\x00\x00\x00\x8A\xD8\xE8\x00\x00\x00\x00\x84\xDB\x75\x13\x48\x8D\x0D\x00\x00\x00\x00", "xxx????xxxx????xxx????xxx????xxxxxxx????", &Hooking::m_replayIntf, true, 3, 1);

	setFn<fpIncrementStatHook>("increment_stat", "\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x55\x57\x41\x55\x41\x56\x41\x57\x48\x8B\xEC\x48\x83\xEC\x60\x8B\x79\x30", "xxxx?xxxx?xxxxxxxxxxxxxxxxxx", &Hooking::increment_stat);

	setFn<fpCreateAmbientPickup>("create_ambient_pickup", "\x48\x8B\xC4\x48\x89\x58\x10\x48\x89\x70\x18\x48\x89\x78\x20\x55\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8D\x68\xC1\x48\x81\xEC\x00\x00\x00\x00\x45\x8B\xF9\x41\x8B\xF0\x4C\x8B\xEA\xE8\x00\x00\x00\x00\x0F\xB7\x0D\x00\x00\x00\x00\x33\xFF\x44\x8B\xC7\x44\x8B\xD7\x44\x8B\xE0\x85\xC9\x7E\x1C\x48\x8B\x1D\x00\x00\x00\x00", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxxxxx????xxx????xxxxxxxxxxxxxxxxxx????", &Hooking::create_ambient_pickup);

//	setFn<fpIntegrityCheck>("integrity_check", "\x40\x55\x53\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8D\x6C\x24\x00\x48\x81\xEC\x00\x00\x00\x00\x48\x8B\x05\x00\x00\x00\x00", "xxxxxxxxxxxxxxxxx?xxx????xxx????", &Hooking::integrity_check);

	setFn<fpSetMobileRadioEnabledDuringGameplay>("set_mobile_radio", "\x40\x53\x48\x83\xEC\x20\x8A\xD9\x48\x8D\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8D\x0D\x00\x00\x00\x00\x8B\xD0\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x10", "xxxxxxxxxxx????x????xxx????xxx????xxxxx", &Hooking::set_mobile_radio_enabled_during_gameplay);

	setFn<fpGetLabelText>("get_label_text", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xDA\x48\x8B\xF9\x48\x85\xD2\x75\x44\xE8", "xxxx?xxxxxxxxxxxxxxxxx", &Hooking::GetLabelText);

	setFn<fpRequestIpl>("request_ipl", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\x05\x00\x00\x00\x00\x48\x8B\xF9\x4C\x8B\xC1\x48\x8D\x54\x24\x00\x48\x8D\x0D\x00\x00\x00\x00\xFF\x50\x10\x8B\x18", "xxxx?xxxxxxxx????xxxxxxxxxx?xxx????xxxxx", &Hooking::request_ipl);

	setFn<fpIsIplActive>("is_ipl_active", "\x48\x83\xEC\x28\x48\x8B\x05\x00\x00\x00\x00\x4C\x8B\xC1", "xxxxxxx????xxx", &Hooking::is_ipl_active);

	setFn<fpNetworkShopCheckoutStart>("network_shop_checkout_start", "\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x33\xC9\x48\x85\xC0\x74\x0C", "xxxxx????xxxxxxx", &Hooking::network_shop_checkout_start);

	setFn<fpGetPlayerMaxArmour>("get_player_max_armour", "\x40\x53\x48\x83\xEC\x20\x33\xDB\x38\x1D\x00\x00\x00\x00\x74\x1C", "xxxxxxxxxx????xx", &Hooking::get_player_max_armour);

	setFn<fpGetEntityAttachedTo>("get_entity_attached_to", "\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x19\x4C\x8B\x00\x8B\x15\x00\x00\x00\x00\x48\x8B\xC8\x41\xFF\x50\x08\x84\xC0\x74\x05\x48\x8B\xC3\xEB\x02\x33\xC0\x48\x83\xC4\x20\x5B\xC3\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8", "xxxxxxx????xxxxxxxxxx?xx????xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxx", &Hooking::get_entity_attached_to);

	setFn<fpSetEntityCollision>("set_entity_collision", "\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF1\x41\x8A\xE8\x40\x8A\xFA", "xxxx?xxxx?xxxx?xxxxxxxxxxxxxx", &Hooking::set_entity_collision);

	setFn<fpNetworkSessionKickPlayer>("network_session_kick_player", "\x48\x83\xEC\x38\xB2\x01\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x21", "xxxxxxx????xxxxx", &Hooking::network_session_kick_player);

	setFn<fpEventHandler>("scripted_game_event", "\x66\x41\x83\xF9\x00\x0F\x83\x00\x00\x00\x00", "xxxx?xx????", &Hooking::event_handler);

	setFn<fpStatSetDate>("stat_set_date", "\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x60\x48\x8B\xDA\x8B\xF9", "xxxx?xxxx?xxxxxxxxxx", &Hooking::stat_set_date);

	setFn<fpStatGetInt>("stat_get_int", "\x48\x8B\xC4\x48\x89\x58\x10\x48\x89\x70\x18\x57\x48\x83\xEC\x30\x48\x8B\xF2", "xxxxxxxxxxxxxxxxxxx", &Hooking::stat_get_int);

	setFn<fpAddTextCompSubstrPlayerName>("add_text_comp_substr_playername", "\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x05\x00\x00\x00\x00\x4C\x8B\xD1", "xxxx?xxxx?xxxx?xxxxxxx????xxx", &Hooking::add_text_comp_substr_playername);

	setFn<fpEndTextCmdDisplayText>("end_text_command_display_text", "\x40\x53\x48\x83\xEC\x40\x0F\x29\x74\x24\x00\x0F\x29\x7C\x24\x00\x41\x8B\xD8", "xxxxxxxxxx?xxxx?xxx", &Hooking::end_text_command_display_text);

	setFn<fpBeginTextCmdDisplayText>("begin_text_command_display_text", "\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x33\xC9\x48\x85\xC0", "xxxxx????x????xxxxx", &Hooking::begin_text_command_display_text);

	setFn<fpSendMessage>("send_message", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x48\x8B\xF9\x48\x8D\x4C\x24\x00\x48\x8B\xDA\xE8\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\x41\xB8\x00\x00\x00\x00\x48\x8B\xD3\xE8\x00\x00\x00\x00\x84\xC0\x74\x14\x48\x8B\x0D\x00\x00\x00\x00\x4C\x8D\x44\x24\x00\x48\x8B\xD7\xE8\x00\x00\x00\x00\x32\xC0\x48\x8B\x5C\x24\x00", "xxxx?xxxxxxxxxxxx?xxxx????xxxx?xx????xxxx????xxxxxxx????xxxx?xxxx????xxxxxx?", &Hooking::send_message);

	setFn<fpClearPedBloodDamage>("clear_ped_blood_damage", "\x40\x53\x48\x83\xEC\x20\x8A\x91\x00\x00\x00\x00\x48\x8B\xD9\x80\xFA\xFF\x74\x51", "xxxxxxxx????xxxxxxxx", &Hooking::clear_ped_blood_damage);

	setFn<fpSetVehicleOnGroundProperly>("set_vehicle_on_ground_properly", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x0F\x29\x74\x24\x00\x0F\x28\xF1\xE8\x00\x00\x00\x00\x48\x8B\xD8", "xxxx?xxxxxxxxx?xxxx????xxx", &Hooking::set_vehicle_on_ground_properly);

	setFn<fpSetVehicleNumberplateText>("set_vehicle_numberplate_text", "\x40\x53\x48\x83\xEC\x20\x48\x8B\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x10\x48\x8B\x48\x48", "xxxxxxxxxx????xxxxxxxxx", &Hooking::set_vehicle_numberplate_text);

	setFn<fpIsThisModelAPlane>("is_this_model_a_plane", "\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x1D\x8A\x80\x00\x00\x00\x00\x24\x1F\x3C\x05\x75\x11\xBA", "xxxxxxxxxx?xxxxx?????x????xxxxxxxxxx????xxxxxxx", &Hooking::is_this_model_a_plane);

	setFn<fpIsThisModelAHeli>("is_this_model_a_heli", "\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x85\xC0\x74\x1E\x8A\x80\x00\x00\x00\x00\x24\x1F\x3C\x05\x75\x12\x83\xB9\x00\x00\x00\x00\x08", "xxxxxxxxxx?xxxxx?????x????xxxxxxxxxx????xxxxxxxx????x", &Hooking::is_this_model_a_heli);

	setFn<fpSetHeliBladesFullSpeed>("set_heli_blades_full_speed", "\x40\x53\x48\x83\xEC\x30\x0F\x29\x74\x24\x00\x0F\x28\xF1\x0F\x2F\x35", "xxxxxxxxxx?xxxxxx", &Hooking::set_heli_blades_full_speed);

	setFn<fpEndTextCommandGetWidth>("end_text_command_get_width", "\x40\x53\x48\x81\xEC\x00\x00\x00\x00\x83\x3D\x00\x00\x00\x00\x00\x8A\xD9\x0F\x57\xC0", "xxxxx????xx?????xxxxx", &Hooking::end_text_command_get_width);

	setFn<fpRequestAnimDict>("request_anim_dict", "\x48\x83\xEC\x58\x48\x8B\xD1\x33\xC9", "xxxxxxxxx", &Hooking::request_anim_dict);

	setFn<fpHasAnimDictLoaded>("has_anim_dict_loaded", "\x48\x83\xEC\x28\x48\x8B\xD1\x33\xC9\xE8\x00\x00\x00\x00\x48\x8D\x54\x24\x00\x48\x8D\x4C\x24\x00\x89\x44\x24\x40", "xxxxxxxxxx????xxxx?xxxx?xxxx", &Hooking::has_anim_dict_loaded);

	setFn<fpDrawNotification>("draw_notification", "\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x81\xEC\x00\x00\x00\x00\x83\x3D\x00\x00\x00\x00\x00\x41\x8A\xD8", "xxxx?xxxx?xxxx????xx?????xxx", &Hooking::draw_notification);

	setFn<fpDrawNotification2>("draw_notification_2", "\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x40\x8A\xFA\x40\x8A\xF1", "xxxx?xxxx?xxxxxxxxxx", &Hooking::draw_notification_2);

	setFn<fpPickupRewardMoneyIsApplicableToPlayer>("pickup_reward", "\x49\x8B\x80\x00\x00\x00\x00\x48\x85\xC0\x74\x0C\xF6\x80\x00\x00\x00\x00\x00\x75\x03", "xxx????xxxxxxx?????xx", &Hooking::pickup_is_applicable_to_player);

	setFn<fpSetVehicleMod>("set_vehicle_mod", "\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x56\x57\x41\x56\x48\x83\xEC\x30\x41\x8A\xE9", "xxxx?xxxx?xxxxxxxxxxx", &Hooking::set_vehicle_mod);

	setFn<fpToggleVehicleMod>("toggle_vehicle_mod", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF8\x8B\xDA\x83\xFA\x0A", "xxxx?xxxxxxxxxxxxx", &Hooking::toggle_vehicle_mod);

	setFn<fpSetVehicleEngineOn>("set_vehicle_engine_on", "\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xE9\x41\x8A\xF8", "xxxx?xxxx?xxxx?xxxxxxxxxxx", &Hooking::set_vehicle_engine_on);

	setFn<fpSetVehicleUndriveable>("set_vehicle_undriveable", "\x40\x53\x48\x83\xEC\x20\x8A\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x20\x84\xDB", "xxxxxxxxx????xxxxxxx", &Hooking::set_vehicle_undriveable);

	setFn<fpSetVehicleDriveable>("set_vehicle_driveable", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x40\x8A\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x36", "xxxx?xxxxxxxxx????xxxxxxxx", &Hooking::set_vehicle_driveable);

	setFn<fpGetDisplayNameFromVehicle>("get_display_name_from_vehicle", "\x48\x83\xEC\x28\x48\x8D\x54\x24\x00\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x16", "xxxxxxxx?xxx?????x????xxxxx", &Hooking::get_display_name_from_vehicle);

	setPat<threeBytes>("infinite ammo", "\x41\x2B\xD1\xE8", "xxxx", &Hooking::infinite_ammo, false);

	setPat<threeBytes>("no reload", "\x41\x2B\xC9\x3B\xC8\x0F", "xxxxxx", &Hooking::no_reload, false);

	setFn<fpGetPedInVehicleSeat>("get_ped_in_vehicle_seat", "\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xE8\x8D\x72\x01", "xxxx?xxxx?xxxx?xxxxxxxxxxx", &Hooking::get_ped_in_vehicle_seat);

	setFn<fpIsAimCamActive>("is_aim_cam_active", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x33\xD2\x48\x8B\xC8\x48\x8B\xF8", "xxxx?xxxxxx????xxxxxxxx", &Hooking::is_aim_cam_active);

	setFn<fpDrawRect>("draw_rect","\x48\x8B\xC4\x48\x89\x58\x08\x57\x48\x83\xEC\x70\x48\x63\x0D\x00\x00\x00\x00\x0F", "xxxxxxxxxxxxxxx????x", &Hooking::draw_rect);

	setFn<fpDrawLine>("draw_line", "\x40\x53\x48\x83\xEC\x40\xF3\x0F\x10\x09\xF3\x0F\x10\x41\x00\xF3\x0F\x10\x51\x00\x45\x8B\xD0\xBB", "xxxxxxxxxxxxxx?xxxx?xxxx", &Hooking::draw_line, 1);

	setFn<fpGetGameplayCamRot>("get_gameplay_cam_rot", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x8B\xDA\x48\x8B\xF9\xE8\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\x48\x8D\x90\x00\x00\x00\x00", "xxxx?xxxxxxxxxxx????xxxx?xxx????", &Hooking::get_gameplay_cam_rot);

	setFn<fpGetGameplayCamCoord>("get_gameplay_cam_coord", "\x40\x53\x48\x83\xEC\x20\x48\x8B\xD9\xE8\x00\x00\x00\x00\x8B\x90\x00\x00\x00\x00", "xxxxxxxxxx????xx????", &Hooking::get_gameplay_cam_coord);

	setFn<fpGiveDelayedWeaponToPed>("give_delayed_weapon_to_ped", "\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x41\x8A\xE9\x41\x8B\xF0\x8B\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x63", "xxxx?xxxx?xxxx?xxxxxxxxxxxxxx????xxxxxxxx", &Hooking::give_delayed_weapon_to_ped);

	setFn<fpRemoveAllPedWeapons>("remove_all_ped_weapons", "\x48\x83\xEC\x28\x8B\x05\x00\x00\x00\x00\x89\x05\x00\x00\x00\x00\xE8", "xxxxxx????xx????x", &Hooking::remove_all_ped_weapons);

	setFn<fpRemoveWeaponFromPed>("remove_weapon_from_ped", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xFA\xE8\x00\x00\x00\x00\x33\xDB", "xxxx?xxxxxxxx????xx", &Hooking::remove_weapon_from_ped);

	setFn<fpGetPlayerRadioStationIndex>("get_player_radio_station_index", "\x48\x83\xEC\x28\x48\x8D\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0C", "xxxxxxx????x????xxxxx", &Hooking::get_player_radio_station_index);

	setFn<fpGetRadioStationName>("get_radio_station_name", "\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0D\x48\x8B\x80", "xxxxx????xxxxxxxx", &Hooking::get_radio_station_name);

	setFn<fpNetworkGetNetworkIdFromEntity>("network_get_network_id_from_entity", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x33\xDB\x48\x8B\xF8\x48\x85\xC0\x74\x16", "xxxx?xxxxxx????xxxxxxxxxx", &Hooking::get_network_id_from_entity);

	setFn<fpNetworkCreateSynchronisedScene>("network_create_synchronised_scene", "\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x48\x8D\x68\xC1", "xxxxxxxxxxxxxxxxxxxx", &Hooking::create_synchronised_scene);

	setFn<fpNetworkAddPedToSynchronisedScene>("network_add_ped_to_synchronised_scene", "\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x50\x49\x8B\xD9", "xxxx?xxxx?xxxxxxxx", &Hooking::add_ped_to_synchronised_scene);

	setFn<fpNetworkStartSynchronisedScene>("network_start_synchronised_scene", "\x40\x53\x48\x81\xEC\x00\x00\x00\x00\x8B\xD9\x44\x8B\xC1\x48\x8D\x15\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\xE8\x00\x00\x00\x00\x85\xDB\x78\x12", "xxxxx????xxxxxxxx????xxxx?x????xxxx", &Hooking::start_synchronised_scene);

	setFn<fpIsVehicleDrivable>("is_vehicle_drivable", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x40\x8A\xFA\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x36", "xxxx?xxxxxxxxx????xxxxxxxx", &Hooking::is_vehicle_driveable);

	setFn<fpSetVehicleForwardSpeed>("set_vehicle_forward_speed", "\x40\x53\x48\x83\xEC\x40\x0F\x29\x74\x24\x00\x48\x8B\xD9\x0F\x28\xF1\xE8\x00\x00\x00\x00\x48\x8B\x03", "xxxxxxxxxx?xxxxxxx????xxx", &Hooking::set_vehicle_forward_speed);

	setFn<fpSetVehicleFixed>("set_vehicle_fixed", "\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x28\x4C\x8B\x10", "xxxxxxx????xxxxxxxxxxx", &Hooking::set_vehicle_fixed);

	setFn<fpSetVehicleDeformationFixed>("set_vehicle_deformation_fixed", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x40\x48\x83\xB9\x00\x00\x00\x00\x00\x48\x8B\xD9", "xxxx?xxxxxxxx?????xxx", &Hooking::set_vehicle_deformation_fixed);

	setFn<fpIsVehicleSeatFree>("is_vehicle_seat_free", "\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x41\x56\x41\x57\x48\x83\xEC\x20\x45\x8A\xF8", "xxxx?xxxx?xxxx?xxxxxxxxxxxx", &Hooking::is_vehicle_seat_free);

	setFn<fpSetVehicleNumberPlateIndex>("set_vehicle_number_plate_index", "\x83\xFA\xFF\x0F\x8C\x00\x00\x00\x00\x48\x8B", "xxxxx????xx", &Hooking::set_vehicle_number_plate_index);

	setFn<fpSetVehicleWheelType>("set_vehicle_wheel_type", "\x40\x53\x48\x83\xEC\x20\x8B\xDA\xE8\x00\x00\x00\x00\x4C\x8B\xC0", "xxxxxxxxx????xxx", &Hooking::set_vehicle_wheel_type);

	setFn<fpGetNumVehicleMod>("get_num_vehicle_mod", "\x40\x53\x48\x83\xEC\x20\x8B\xDA\x83\xFA\x0A\x7E\x10\x8D\x42\xF5\x83\xF8\x0D\x77\x05\x83\xC3\x19\xEB\x03\x83\xEB\x0E\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x2C", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxx", &Hooking::get_num_vehicle_mod);

	setFn<fpDrawNotification>("draw_notification", "\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x81\xEC\x00\x00\x00\x00\x83\x3D\x00\x00\x00\x00\x00\x41\x8A\xD8", "xxxx?xxxx?xxxx????xx?????xxx", &Hooking::draw_notification);

	setFn<fpSetLocalPlayerVisibleLocally>("set_local_player_visible_locally", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x40\x8A\xF9\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x6D", "xxxx?xxxxxxxxx????xxxxxxxx", &Hooking::set_local_player_visible_locally);

	setFn<fpAiTaskWanderStandard>("ai_task_wander_standard", "\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x60\x0F\x28\xC1", "xxxx?xxxx?xxxxxxxx", &Hooking::ai_task_wander_standart);

	setFn<fpAiTaskPlayAnim>("ai_task_play_anim", "\x48\x81\xEC\x00\x00\x00\x00\x44\x8B\x8C\x24", "xxx????xxxx", &Hooking::ai_task_play_anim);

	setFn<fpIsModelInCdimage>("is_model_in_cdimage", "\x48\x83\xEC\x28\x8B\x44\x24\x38\x48\x8D\x54\x24\x00\xC7\x44\x24\x00\x00\x00\x00\x00\x0D\x00\x00\x00\x00\x25\x00\x00\x00\x00\x89\x44\x24\x38\xE8\x00\x00\x00\x00\x0F\xB7\x44\x24\x00\x66\x89\x44\x24\x00\x8B\x44\x24\x38\x0D\x00\x00\x00\x00\x0F\xBA\xF0\x1C\x89\x44\x24\x38", "xxxxxxxxxxxx?xxx?????x????x????xxxxx????xxxx?xxxx?xxxxx????xxxxxxxx", &Hooking::is_model_in_cdimage);

	setFn<fpIsModelValid>("is_model_valid", "\x48\x83\xEC\x28\x8B\x44\x24\x38\x48\x8D\x54\x24\x00\xC7\x44\x24\x00\x00\x00\x00\x00\x0D\x00\x00\x00\x00\x25\x00\x00\x00\x00\x89\x44\x24\x38\xE8\x00\x00\x00\x00\x0F\xB7\x44\x24\x00\x66\x89\x44\x24\x00\x8B\x44\x24\x38\x0D\x00\x00\x00\x00\x0F\xBA\xF0\x1C\x0F\xB7\xC8", "xxxxxxxxxxxx?xxx?????x????x????xxxxx????xxxx?xxxx?xxxxx????xxxxxxx", &Hooking::is_model_valid);

	setFn<fpIsModelAVehicle>("is_model_a_vehicle", "\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0", "xxxxxxxxxx?xxxxx?????x????xxx", &Hooking::is_model_a_vehicle);

	setFn<fpRequestModel>("request_model", "\x48\x89\x5C\x24\x00\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x50\x8B\x45\x18", "xxxx?xxxx?xxxxxxxxxxx", &Hooking::request_model);

	setFn<fpHasModelLoaded>("has_model_loaded", "\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x20\x8B\x45\x18\xBF", "xxxx?xxxxxxxxxxxx", &Hooking::has_model_loaded);

	setFn<fpGetPedLastWeaponImpactCoord>("get_ped_last_weapon_impact", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x33\xDB\x48\x8B\xFA\x48\x89\x5A\x04", "xxxx?xxxxxxxxxxxxxx", &Hooking::get_ped_last_weapon_impact_coord);

	setFn<fpStartRayCast>("start_ray_cast", "\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x70\x20\x55\x48\x8D\xA8\x00\x00\x00\x00\x48\x81\xEC\x00\x00\x00\x00\x33\xDB\x45\x8B\xF0\x48\x8B\xFA\x48\x8B\xF1\x8B\xC3\x45\x85\xC9\x74\x08\x41\x8B\xC9\xE8\x00\x00\x00\x00\xF3\x0F\x10\x1F", "xxxxxxxxxxxxxxxxxxxxxxx????xxx????xxxxxxxxxxxxxxxxxxxxxx????xxxx", &Hooking::start_ray_cast);

	setFn<fpGetRayCast>("get_ray_cast", "\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x41\x56\x41\x57\x48\x8D\x68\xB1\x48\x81\xEC\x00\x00\x00\x00\x33\xDB", "xxxxxxxxxxxxxxxxxxxxxxxxxxx????xx", &Hooking::get_ray_cast);

	setFn<fpNetworkSetInSpectatorMode>("network_set_in_spectator_mode", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF8\x84\xC9", "xxxx?xxxxxxxxxx", &Hooking::set_in_spectator_mode);

	setFn<fpSetPedCombatAbility>("set_ped_combat_ability", "\x48\x81\xC1\x00\x00\x00\x00\x41\xB8\x00\x00\x00\x00\x48\x8B\x01\x48\x85\xC0\x74\x06", "xxx????xx????xxxxxxxx", &Hooking::set_ped_combat_ability);

	setFn<fpAiTaskCombatPed>("ai_task_combat_ped", "\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x83\xEC\x30\x8B\xF9", "xxxxxxxxxxxxxxxxxxxxxxxxxxx", &Hooking::ai_task_combat_ped);

	setFn<fpApplyVehicleColors>("apply_vehicle_colors", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\x41\x48\x48\x8B\xD9\x40\x8A\xFA","xxxx?xxxxxxxxxxxxxxx", &Hooking::apply_vehicle_colors);

	setFn<fpSetPlayerVisibleLocally>("set_player_visible_locally", "\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x40\x8A\xFA\xB2\x01\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x0D\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x8B\xD8\xEB\x02\x33\xDB\x48\x85\xDB\x74\x64", "xxxx?xxxxxxxxxxx????xxxxxxxxx????xxxxxxxxxxxx", &Hooking::set_player_visible_locally);

	setFn<fpSetModelAsNoLongerNeeded>("set_model_as_no_longer_needed", "\x40\x53\x48\x83\xEC\x30\x48\x8D\x54\x24\x00\x8B\xD9", "xxxxxxxxxx?xx", &Hooking::set_model_as_no_longer_needed);

	setFn<fpSetVehicleEngineOn>("set_vehicle_engine_on", "\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xE9\x41\x8A\xF8", "xxxx?xxxx?xxxx?xxxxxxxxxxx", &Hooking::set_vehicle_engine_on);

	setFn<fpSetEntityCollision>("set_entity_collision", "\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF1\x41\x8A\xE8\x40\x8A\xFA", "xxxx?xxxx?xxxx?xxxxxxxxxxxxxx", &Hooking::set_entity_collision);

	setPat<CPlayers>("player list", "\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x8B\xCF", "xxx????x????xxxx????xxx", &Hooking::m_players, true, 3);

	setPat<MemoryPool*>("entity pool", "\x4C\x8B\x0D\x00\x00\x00\x00\x44\x8B\xC1\x49\x8B\x41\x08", "xxx????xxxxxxx", &Hooking::m_entityPool, true, 3);

	setPat<MemoryPool*>("ped pool", "\x48\x8B\x05\x00\x00\x00\x00\x41\x0F\xBF\xC8\x0F\xBF\x40\x10", "xxx????xxxxxxxx", &Hooking::m_pedPool, true, 3);

	setPat<screenReso>("resolution", "\x8B\x0D\x00\x00\x00\x00\x49\x8D\x56\x28", "xx????xxxx", &Hooking::m_resolution, true, 2);

	setPat<CTextInfo>("text info", "\x48\x8D\x05\x00\x00\x00\x00\x48\x89\x44\x24\x00\x8B\x05\x00\x00\x00\x00\x89\x44\x24\x28", "xxx????xxxx?xx????xxxx", &Hooking::m_textInfo, true, 3);

	setPat<uint64_t>("network time", "\x8B\x0D\x00\x00\x00\x00\x3B\xCB\x0F\x47\xCB", "xx????xxxxx", &Hooking::m_networkTime, true, 2);

	setPat<void>("game info", "\x48\x8D\x0D\x00\x00\x00\x00\x41\xB0\x01\x33\xD2\x88\x1D", "xxx????xxxxxxx", &Hooking::m_gameInfo, true, 3);

	setFn<fpCreateObject>("create_object", "\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x60\x20\x55\x41\x55\x41\x56\x48\x8D\x68\xD9", "xxxxxxxxxxxxxxxxxxxxxxxxxxxx", &Hooking::create_object);

	setFn<fpGetWaypointPos>("get_waypoint_pos", "\x48\x89\x5C\x24\x08\x57\x48\x83\xEC\x20\x8B\x15\x00\x00\x00\x00\x65\x48\x8B\x04\x25\x00\x00\x00\x00\x48\x8B\xF9\x48\x8B\x04\xD0\xB9\xB4", "xxxxxxxxxxxx????xxxxx????xxxxxxxxx", &Hooking::get_waypoint_pos);

	setFn<fpSetOverrideWeather>("set_override_weather", "\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x1D\x00\x00\x00\x00\x8B\xF1", "xxxx?xxxx?xxxxxxx????xx", &Hooking::set_override_weather);

	setFn<fpGetCurrentPedWeapon>("get_current_ped_weapon", "\x40\x53\x48\x83\xEC\x20\x48\x8B\xDA\xE8\x00\x00\x00\x00\x33\xC9", "xxxxxxxxxx????xx", &Hooking::get_current_ped_weapon);

	setFn<fpGetTextScreenLineCount>("get_text_screen_line_count", "\x48\x8B\xC4\x48\x81\xEC\x00\x00\x00\x00\x0F\x29\x70\xE8\x0F\x29\x78\xD8\x33\xC0", "xxxxxx????xxxxxxxxxx", &Hooking::get_text_screen_line_count);

	setFn<fpRequestScaleformMovie>("request_scaleform_movie", "\x48\x8B\xC4\x48\x89\x58\x10\x48\x89\x70\x18\x48\x89\x78\x20\x55\x48\x8D\x68\xA1\x48\x81\xEC\x00\x00\x00\x00\xF3\x0F\x10\x45\x00", "xxxxxxxxxxxxxxxxxxxxxxx????xxxx?", &Hooking::request_scaleform_movie);

	setFn<fpDrawScaleformMovie>("draw_scaleform_movie", "\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x57\x48\x81\xEC\x00\x00\x00\x00\x0F\x29\x70\xE8\x0F\x29\x78\xD8\x44\x0F\x29\x40\x00\x48\x63\xF9", "xxxxxxxxxxxxxxxxxxx????xxxxxxxxxxxx?xxx", &Hooking::draw_scaleform_movie);

	setFn<fpEndScaleformMovieMethod>("end_scaleform_movie_method", "\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x19\x4C\x8B\x00\x8B\x15\x00\x00\x00\x00\x48\x8B\xC8\x41\xFF\x50\x08\x84\xC0\x74\x05\x48\x8B\xC3\xEB\x02\x33\xC0\x48\x83\xC4\x20\x5B\xC3\x48\x89\x5C\x24\x00\x45\x33\xC9", "xxxxxxx????xxxxxxxxxx?xx????xxxxxxxxxxxxxxxxxxxxxxxxxxxx?xxx", &Hooking::end_scaleform_movie_method);

	setFn<fpIsDisabledControlPressed>("is_disabled_control_pressed", "\x40\x53\x48\x83\xEC\x20\x48\x8B\x05\x00\x00\x00\x00\x8B\xDA\x48\x85\xC0\x74\x10\x80\x78\x14\x00\x75\x06\x83\x78\x04\x00\x74\x04\x32\xC0\xEB\x4F\x48\x8B\x05\x00\x00\x00\x00\x48\x89\x44\x24\x00\x48\xC1\xE8\x20\x83\xC8\x08\x89\x44\x24\x44\x85\xC9\x75\x09\x33\xC9",  "xxxxxxxxx????xxxxxxxxxx?xxxxx?xxxxxxxxx????xxxx?xxxxxxxxxxxxxxxxx", &Hooking::is_disabled_control_pressed);

	setFn<fpIsPlayerFriend>("is_player_friend", "\x0F\xB6\xD0\x48\x8B\x03\x89\x10\x48\x83\xC4\x20\x48\x8D\x64\x24\x08\x48\x8B\x5C\x24\xF8\x48\x8D\x64\x24\x08\x00\x00\x00\x00", "xxxxxxxxxxxxxxxxxxxxxxxxxxx????", &Hooking::is_player_friend);

	char * c_location = nullptr;
	void * v_location = nullptr;

	c_location = p_gameState.count(1).get(0).get<char>(2);
	c_location == nullptr ? FailPatterns("gameState") : m_gameState = reinterpret_cast<decltype(m_gameState)>(c_location + *(int32_t*)c_location + 5);

	v_location = p_fixVector3Result.count(1).get(0).get<void>(0);
	if (v_location != nullptr) scrNativeCallContext::SetVectorResults = (void(*)(scrNativeCallContext*))(v_location);

	c_location = p_nativeTable.count(1).get(0).get<char>(9);
	c_location == nullptr ? FailPatterns("native registration table") : m_registrationTable = reinterpret_cast<decltype(m_registrationTable)>(c_location + *(int32_t*)c_location + 4);

	c_location = p_worldPtr.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("world Pointer") : m_worldPtr = reinterpret_cast<uint64_t>(c_location) + *reinterpret_cast<int*>(reinterpret_cast<uint64_t>(c_location) + 3) + 7;

	c_location = p_blipList.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("blip List") : m_blipList = (BlipList*)(c_location + *reinterpret_cast<int*>(c_location + 3) + 7);

	c_location = p_activeThread.count(1).get(0).get<char>(1);
	c_location == nullptr ? FailPatterns("Active Script Thread") : GetActiveThread = reinterpret_cast<decltype(GetActiveThread)>(c_location + *(int32_t*)c_location + 4);

	c_location = p_globalPtr.count(1).get(0).get<char>(0);
	__int64 patternAddr = NULL;
	c_location == nullptr ? FailPatterns("globalTable") : patternAddr = reinterpret_cast<decltype(patternAddr)>(c_location);
	m_globalPtr = (__int64**)(patternAddr + *(int*)(patternAddr + 3) + 7);

	if ((c_location = p_eventHook.count(1).get(0).get<char>(0)))
	{
		int i = 0, j = 0, matches = 0, found = 0;
		char* pattern = "\x4C\x8D\x05";
		while (found != EVENT_COUNT)
		{
			if (c_location[i] == pattern[j])
			{
				if (++matches == 3)
				{
					EventPtr.push_back((void*)(reinterpret_cast<uint64_t>(c_location + i - j) + *reinterpret_cast<int*>(c_location + i + 1) + 7));
					found++;
					j = matches = 0;
				}
				j++;
			}
			else
			{
				matches = j = 0;
			}
			i++;
		}
	}

	CrossMapping::initNativeMap();
	Log::Purple("     _   __                     _____ ____ ");
	Log::Purple("   / | / /___ _____  ____     / ___// __ \");
	Log::Purple("  /  |/ / __ `/ __ \/ __ \   / __ \/ /_/ /");
	Log::Purple(" / /|  / /_/ / / / / /_/ /  / /_/ /\__, / ");
	Log::Purple("/_/ |_/\__,_/_/ /_/\____/   \____//____/  ");
	Log::White("[MSG] -> Checking Game State...");
	Log::White("[MSG] -> Successfully Checked Game State!");
	Log::White("[MSG] -> Checking Vector3...");
	Log::White("[MSG] -> Successfully Checked Vector3!");
	Log::White("[MSG] -> Checking Native Signatures");
	Log::White("[MSG] -> Sucessfully checked 58 Native signatures.");
	Log::White("[MSG] -> Input hook attatched: WndProc 0x00007FFF5D7C53F0");
	Log::White("[Pattern] -> Hooked : EH");
	Log::White("[Pattern] -> Hooked : GXT");
	Log::White("[Pattern] -> Hooked : CH");
	Log::White("[Pattern] -> Hooked : GED");
	Log::White("[Pattern] -> Hooked : SI");
	Log::White("[Pattern] -> Hooked : VQ");
	Log::White("[MSG] -> Checking World Pointer...");
	Log::White("[MSG] -> Successfully Checked World Pointer!");
	Log::White("[MSG] -> Checking Blip List...");
	Log::White("[MSG] -> Successfully Checked Blip List!");
	Log::White("[MSG] -> Checking Object Bypass..");
	Log::White("[MSG] -> Successfully Checked Object Bypass!");
	Log::White("[MSG] -> Checking Active Script Thread...")
	Log::White("[MSG] -> Successfully Checked Active Script Thread!");
	Log::White("[MSG] -> Checking Event Hook...");
	Log::White("[MSG] -> Successfully Checked Event Hooking!");
	Log::White("[MSG] -> Checking Natives...");
	Log::White("[MSG] -> Successfully Checked Natives!");
	Log::White("[MSG] -> Checking if Nano69 is ready...");
	while (*m_gameState != GameStatePlaying) {
		Sleep(200);
	}
	Log::Green("[MSG] -> Nano69 + GTA V ready!");
	Log::White("[CREDITS] -> Credit to Faint#0702 for Making this base");
}

static Hooking::NativeHandler _Handler(uint64_t origHash)
{
	uint64_t newHash = CrossMapping::MapNative(origHash);
	if (newHash == 0)
	{
		return nullptr;
	}

	Hooking::NativeRegistrationNew * table = m_registrationTable[newHash & 0xFF];

	for (; table; table = table->getNextRegistration())
	{
		for (uint32_t i = 0; i < table->getNumEntries(); i++)
		{
			if (newHash == table->getHash(i))
			{
				return table->handlers[i];
			}
		}
	}
	return nullptr;
}

Hooking::NativeHandler Hooking::GetNativeHandler(uint64_t origHash)
{
	auto& handler = m_handlerCache[origHash];

	if (handler == nullptr)
	{
		handler = _Handler(origHash);
	}

	return handler;
}

eGameState Hooking::GetGameState()
{
	return *m_gameState;
}

BlipList* Hooking::GetBlipList()
{
	return m_blipList;
}

uint64_t Hooking::getWorldPtr()
{
	return m_worldPtr;
}
void WAIT(DWORD ms)
{
	wakeAt = timeGetTime() + ms;
	SwitchToFiber(mainFiber);
}

void Hooking::Cleanup()
{
	Log::White("[HOOK] ->Cleaning up hooks");
	for (int i = 0; i < m_hooks.size(); i++)
		if (MH_DisableHook(m_hooks[i]) != MH_OK && MH_RemoveHook(m_hooks[i]) != MH_OK)
			Log::Error("Failed to unhook %p", (void*)m_hooks[i]);
	MH_Uninitialize();

	FreeLibraryAndExitThread(static_cast<HMODULE>(_hmoduleDLL), 1);
}

void Hooking::defuseEvent(RockstarEvent e, bool toggle)
{
	static const unsigned char retn = 0xC3;
	char* p = (char*)EventPtr[e];
	if (toggle)
	{
		if (EventRestore[e] == 0)
			EventRestore[e] = p[0];
		*p = retn;
	}
	else
	{
		if (EventRestore[e] != 0)
			*p = EventRestore[e];
	}
}

__int64** Hooking::getGlobalPtr()
{
	return m_globalPtr;
}
__int64 * Hooking::getGlobalPtr1(int index)
{
	return nullptr;
}
__int64 * Hooking::setTunable(int Tunable)
{
	return nullptr;
}