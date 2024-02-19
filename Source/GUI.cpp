#include "stdafx.h"

Player playerr = PLAYER::PLAYER_ID();


void Menu::Drawing::Text(const char * text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center)
{
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_COLOUR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
	UI::SET_TEXT_FONT(rgbaf.f);
	UI::SET_TEXT_SCALE(size.w, size.h);
	/*UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
	UI::SET_TEXT_EDGE(1, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
	*/UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(position.x, position.y);
}

void Menu::Drawing::Text(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center, bool rightAlign, bool outline)
{
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_COLOUR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
	UI::SET_TEXT_FONT(rgbaf.f);
	UI::SET_TEXT_SCALE(size.w, size.h);
	/*if (outline) {
		UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
		UI::SET_TEXT_EDGE(1, 0, 0, 0, 0);
		UI::SET_TEXT_OUTLINE();
	}*/
	if (rightAlign) {
		UI::SET_TEXT_RIGHT_JUSTIFY(TRUE);
		UI::SET_TEXT_WRAP(Menu::Settings::menuX, Menu::Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f));
	}
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(position.x, position.y);
}

void Menu::Drawing::Text(const char * text, RGBAF rgbaf, VECTOR2 position, float size) {
	UI::SET_TEXT_COLOUR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
	UI::SET_TEXT_FONT(rgbaf.f);
	UI::SET_TEXT_SCALE(size, size);
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(position.x, position.y);
}

bool Menu::Settings::schwesselfick = true;
bool Menu::Settings::schwesselfickk = false;


void Menu::Drawing::Spriter(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
	}
	else
	{
		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x, y, width, height, rotation, r, g, b, a);
	}
}
void Menu::Drawing::Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size)
{
	GRAPHICS::DRAW_RECT(position.x, position.y, size.w, size.h, rgba.r, rgba.g, rgba.b, rgba.a);
}

static fpFileRegister file_register = (fpFileRegister)(Memory::pattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 7C 24 ? 41 54 41 56 41 57 48 83 EC 50 48 8B EA 4C 8B FA 48 8B D9 4D 85 C9").count(1).get(0).get<decltype(file_register)>());

bool FileExists(const std::string& fileName)
{
	struct stat buffer;
	return (stat(fileName.c_str(), &buffer) == 0);
}

bool Menu::Settings::Virustroll = true;
bool Menu::Settings::Authcheck = true;
bool Menu::Settings::Authcheckder2 = true;
float glareX = (Menu::Settings::menuX - 0.17f) + 0.5050f; //Esquerda


void Menu::Drawing::YTD()
{
	const char* file = "Nano69.ytd";
	std::ostringstream m_FilePath; m_FilePath << "C:\\Nano69\\" << file;

	int textureID;
	if (FileExists(m_FilePath.str().c_str()))
		file_register(&textureID, m_FilePath.str().c_str(), true, file, false);

	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("Nano69", false); //Image name need to be Header.png/jpg
}

int Menu::Settings::titleRectTexture = 0;
void Menu::Drawing::Title(const char * text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center)
{
	Menu::Drawing::YTD();
	Drawing::Rect(Settings::line, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + 0.08f }, { 0.002f, 0.09f });
	Drawing::Rect(Settings::line, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + 0.08f }, { 0.002f, 0.09f });
	if (Menu::Settings::titleRectTexture == 0) 
		Drawing::Spriter("nano6", "nano", Settings::menuX, Settings::menuY + 0.0800f, Settings::menuWidth, 0.090f, 0, Menu::Settings::titleRect.r, Menu::Settings::titleRect.g, Menu::Settings::titleRect.b, Menu::Settings::titleRect.a);
	if (Menu::Settings::titleRectTexture == 1) 
		Drawing::Spriter("nano69", "nano", Settings::menuX, Settings::menuY + 0.0800f, Settings::menuWidth, 0.090f, 0, Menu::Settings::titleRect.r, Menu::Settings::titleRect.g, Menu::Settings::titleRect.b, Menu::Settings::titleRect.a);

	float Glare_X = 0.356000f;
	float Glare_Y = 0.4954f;
	float Glare_W = 1.0480f;
	float Glare_H = 1.0215f;

	if (Menu::Settings::GlareOnOff == true) {
		DrawGlare(((Menu::Settings::menuX - 0.17f) + 0.5050f) + (Settings::scrollbarWidthIndex - 0.11f/*0.465f*/)/* + Glare_X*/, Settings::menuY + Glare_Y, Glare_W, Glare_H, 255, 255, 255, 255);
	}

	Drawing::Rect(Settings::line, { Settings::menuX, Menu::Settings::menuY + 0.036f }, { Settings::menuWidth, 0.003f });

	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_COLOUR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
	UI::SET_TEXT_FONT(rgbaf.f);
	UI::SET_TEXT_SCALE(size.w, size.h);
	UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
	UI::SET_TEXT_EDGE(1, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(position.x, position.y);
}


int Menu::Settings::offradard = 0;
int Menu::Settings::bullet = 0;
int Menu::Settings::notoirff = 0;
bool Menu::Settings::DrawTextOutline = false;
bool Menu::Settings::displayEnd = true;
bool Menu::Settings::GlareOnOff = true;
float Menu::Settings::menuX = 0.17f;
float Menu::Settings::menuY = 0.0f;
bool Menu::Settings::selectPressed = false;
bool Menu::Settings::leftPressed = false;
float Menu::Settings::bulletp;
float Menu::Settings::camerra;

float Menu::Settings::bulletppp;
int Menu::Settings::Minufick = 0;
int Menu::Settings::secfick = 0;
int Menu::Settings::Hourfick = 0;

int Menu::Settings::alpha = 0;
int Menu::Settings::LVL = 8000;
bool Menu::Settings::rightPressed = false;
int Menu::Settings::maxVisOptions = 16;
int Menu::Settings::currentOption = 0;
int Menu::Settings::optionCount = 0;
int Menu::Settings::breakCount = 0;
int Menu::Settings::setspoofrankpl = 0;
int Menu::Settings::alpha2 = 0;
SubMenus Menu::Settings::currentMenu;
int Menu::Settings::menuLevel = 0;
int Menu::Settings::optionsArray[1000];
SubMenus Menu::Settings::menusArray[1000];
int Menu::Settings::gayStealth = 10000000;

float Menu::Settings::menuWidth = 0.23f;
float Menu::Settings::scrollbarWidthIndex = 0.13f;
int Menu::Settings::run = 2;
float Menu::Settings::GlareXPos = 0.285f;
bool Menu::Settings::DrawGradientRect = false;


RGBAF Menu::Settings::PremiumTitle{ 255, 255, 0, 255, 1 }; 
RGBAF Menu::Settings::titleText{ 255, 255, 255, 255, 7 };
RGBAF Menu::Settings::titleText3{ 239, 255, 255, 255, 6 };
RGBAF Menu::Settings::titleText2{ 255, 255, 255, 255, 1 };
RGBA Menu::Settings::titleRect{ 255, 255, 255, 255 };
RGBAF Menu::Settings::integre{ 255, 255, 255, 255, 6 };
RGBAF Menu::Settings::integre2{ 255, 255, 255, 130, 2 };
RGBAF Menu::Settings::SelectedText{ 0, 0, 0, 255, 0 };
RGBAF Menu::Settings::count{ 255, 255, 255, 255, 6 };
RGBAF Menu::Settings::arrow{ 0, 0, 0, 255 };
RGBAF Menu::Settings::arrowww{ 0, 0, 0, 255, 3 };
RGBAF Menu::Settings::OnThisDick{ 255, 255, 255, 255, 0 };
RGBAF Menu::Settings::NotOnThisDick{ 0, 0, 0, 255, 0 };
RGBAF Menu::Settings::OnThisArrow{ 0, 0, 0, 255, 3 };
RGBAF Menu::Settings::NotOnThisArrow{ 255, 255, 255, 255, 3 };
RGBAF Menu::Settings::arrow2{ 0, 180, 255, 255, 3 };
RGBAF Menu::Settings::breakText{ 255, 255, 255, 255, 1 };
RGBA Menu::Settings::titleEnd{ 0, 0, 0, 255 };
RGBA Menu::Settings::text{ 255, 255, 255, 255 };
RGBA Menu::Settings::title_sprite{ 255,255,255,255 };
RGBA Menu::Settings::title_sprite2{ 255,255,255,255 };
RGBA Menu::Settings::scrollerr{ 255,200,200,0 };
RGBAF Menu::Settings::title_end{ 255,255,255,255,4 };
RGBAF Menu::Settings::optionText{ 255, 255, 255, 255, 0 };
RGBAF Menu::Settings::subtitleText{ 255, 255, 255, 255, 0 };
RGBAF Menu::Settings::optionTextt{ 255, 255, 255, 180, 0 };
RGBAF Menu::Settings::Spawnerrect{ 255, 255, 255, 255, 0 };
RGBAF Menu::Settings::Spawnerrect2{ 0, 0, 0, 255, 0 };
RGBAF Menu::Settings::NumberOption{ 255, 255, 255, 255, 2 };
RGBA Menu::Settings::optionRect{ 0, 0, 0, 160 };
RGBA Menu::Settings::optionRectSmooth{ 0, 0, 0, 160 };
RGBA Menu::Settings::scroller{ 255, 255, 255, 200 };
RGBA Menu::Settings::line{ 84, 0, 255, 255 };
RGBA Menu::Settings::Endrect{ 0,0,0,255 };

RGBA Menu::Settings::linego{ 255,255,255,255 };
RGBA Menu::Settings::primary{ 255, 255, 0, 100 };
RGBA Menu::Settings::secondary{ 255,255,255,255 };
RGBA Menu::Settings::Endrectlol{ 0, 0, 0, 255 };
RGBA Menu::Settings::Endrectloll{ 255, 255, 255, 255 };



bool bannernoti2 = true;
float xxxxx = 0.1415f;
bool percenttononpercent = false;
void scrollbar() {
	using namespace Menu;
	int curopt = Settings::currentOption;
	int optcnt = Settings::optionCount;
	int maxopt = Settings::maxVisOptions;
	if (bannernoti2)
	{
		std::string SocialClubNick = ((SOCIALCLUB::_SC_GET_NICKNAME()));
		std::string WelcomeNotification = "~w~Welcome, ~s~" + SocialClubNick + "~w~, to ~s~Nano69~w~!";
		int32_t handle = 0;
		handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_BIG_MESSAGE_FREEMODE");
		GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(handle, Settings::arrowww.r, Settings::arrowww.g, Settings::arrowww.b, 255, 0);
		GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "SHOW_SHARD_WASTED_MP_MESSAGE");
		GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
		GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(handle, "SHOW_SHARD_WASTED_MP_MESSAGE");
		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING("~p~Nano69");
		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING(WelcomeNotification.c_str());
		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(5);
		GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
		Menu::ScriptEventLog(Menu::Tools::StringToChar("Welcome to ~c~Nano69, ~g~" + (std::string)PLAYER::GET_PLAYER_NAME(0))); //notification saying welcome
	}
	if (Settings::menuLevel > 0) {
		bannernoti2 = 0;
		if (optcnt > maxopt) {
			percenttononpercent = false;
			GRAPHICS::DRAW_RECT(Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + 0.437f, 0.01f, (maxopt * 0.035f + 0.035f), Settings::optionRectSmooth.r, Settings::optionRectSmooth.g, Settings::optionRectSmooth.b, Settings::optionRectSmooth.a);
			GRAPHICS::DRAW_RECT(Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + ((((curopt * ((maxopt * 0.035f) - 0.012f)) / optcnt))) + 0.167f, 0.008f, 0.035f, 3, 97, 164, Settings::scroller.a);
		}
		else
		{
			percenttononpercent = true;
			GRAPHICS::DRAW_RECT(Settings::menuX - Settings::scrollbarWidthIndex, Settings::menuY + ((((curopt * (optcnt * 0.035f)) / optcnt))) + 0.14f, 0.008f, 0.035f, 3, 97, 164, Settings::scroller.a);
		}
	}
}






namespace Globe
{
	int gGlareHandle; // int
	float gGlareDir;

	// Function(s)
	float conv360(float base, float min, float max) {
		float fVar0;
		if (min == max) return min;
		fVar0 = max - min;

		if (base < min) base += fVar0;
		return base;
	}
	void drawGlare(float pX, float pY, float sX = 1, float sY = 1, int r = 255, int g = 255, int b = 255) {

		gGlareHandle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_MENU_GLARE");

		Vector3 rot = CAM::_GET_GAMEPLAY_CAM_ROT(2);

		float dir = conv360(rot.z, 0, 360);

		if ((gGlareDir == 0 || gGlareDir - dir > 0.5) || gGlareDir - dir < -0.5) {

			gGlareDir = dir;

			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(gGlareHandle, "SET_DATA_SLOT");

			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_FLOAT(gGlareDir);

			GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
		}

		GRAPHICS::DRAW_SCALEFORM_MOVIE(gGlareHandle, pX, pY, sX, sY, r, g, b, Menu::Settings::ArrowAlpha, 0);

	}
};



void Menu::PremiumTitle(const char * title)
{
	Drawing::Title("Version: 1.0", Settings::titleText, { Settings::menuX, 0.100f }, { 0.40f, 0.40f }, true);
}
void Menu::DRAW_TEXTURE(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
	}
	else
	{
		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x, y, width, height, rotation, r, g, b, a);
	}
}



float gGlareDir;
float conv360(float base, float min, float max)
{
	float fVar0;
	if (min == max) return min;
	fVar0 = max - min;
	base -= SYSTEM::ROUND(base - min / fVar0) * fVar0;
	if (base < min) base += fVar0;
	return base;
}

void Menu::DrawGlare(float pX, float pY, float scaleX, float scaleY, int red, int green, int blue, int alpha)
{
	int gGlareHandle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_MENU_GLARE");
	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(2);
	float dir = conv360(rot.z, 0, 360);
	if ((gGlareDir == 0 || gGlareDir - dir > 0.5) || gGlareDir - dir < -0.5)
	{
		gGlareDir = dir;
		GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(gGlareHandle, "SET_DATA_SLOT");
		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_FLOAT(gGlareDir);
		GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
	}
	GRAPHICS::DRAW_SCALEFORM_MOVIE(gGlareHandle, pX, pY, scaleX, scaleY, red, green, blue, alpha, 0);
}


void Menu::render_globe(const float x, const float y, const float sx, const float sy, const int r, const int g,

	const int b)

{

	float g_glare_dir = 0;

	auto g_glare_handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE(static_cast<char*>("MP_MENU_GLARE"));

	const auto rot = CAM::_GET_GAMEPLAY_CAM_ROT(2);

	const auto dir = conv360(rot.z, 0, 360);

	if ((g_glare_dir == 0 || g_glare_dir - dir > 0.5) || g_glare_dir - dir < -0.5)

	{

		g_glare_dir = dir;

		GRAPHICS::CALL_SCALEFORM_MOVIE_METHOD(g_glare_handle, static_cast<char*>("SET_DATA_SLOT"));

		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_FLOAT(g_glare_dir);

		GRAPHICS::END_SCALEFORM_MOVIE_METHOD();

	}

	GRAPHICS::DRAW_SCALEFORM_MOVIE(g_glare_handle, x, y, sx, sy, r, g, b, 20, 0);

	GRAPHICS::_SCREEN_DRAW_POSITION_END();

}

int prevOption = 0;
float prevf;
float ScrollerSpeed = 0.003f;
const auto animscroll = [](int* prev, const int cur) {
	if (prevf == NULL)
		prevf = *prev * 0.035f + 0.1415f;
	const auto curf = cur * 0.035f + 0.1415f;
	if (Menu::Settings::currentOption <= Menu::Settings::maxVisOptions && Menu::Settings::optionCount <= Menu::Settings::maxVisOptions) {
		if (*prev != cur)
		{
			if (prevf < curf)
			{
				if (prevf + ScrollerSpeed > curf)
					prevf = prevf + (curf - prevf);
				else
					prevf = prevf + ScrollerSpeed;
				GRAPHICS::DRAW_SPRITE("Lifix", "scroll", Menu::Settings::menuX, Menu::Settings::menuY + prevf, Menu::Settings::menuWidth, 0.035f, 0, 255, 255, 255, Menu::Settings::scroller.a);
				//GRAPHICS::DRAW_RECT(Menu::Settings::menuX, prevf, Menu::Settings::menuWidth, 0.035f, Menu::Settings::scroller.r, Menu::Settings::scroller.g, Menu::Settings::scroller.b, Menu::Settings::scroller.a);
				if (prevf >= curf)
				{
					prevf = curf;
					*prev = cur;
				}
			}
			if (prevf > curf)
			{
				if (prevf - ScrollerSpeed < curf)
					prevf = prevf - (prevf - curf);
				prevf = prevf - ScrollerSpeed;
				GRAPHICS::DRAW_SPRITE("Lifix", "scroll", Menu::Settings::menuX, Menu::Settings::menuY + prevf, Menu::Settings::menuWidth, 0.035f, 0, 255, 255, 255, Menu::Settings::scroller.a);
				//GRAPHICS::DRAW_RECT(Menu::Settings::menuX, prevf, Menu::Settings::menuWidth, 0.035f, Menu::Settings::scroller.r, Menu::Settings::scroller.g, Menu::Settings::scroller.b, Menu::Settings::scroller.a);
				if (prevf <= curf)
				{
					prevf = curf;
					*prev = cur;
				}
			}
		}
		else
		{
			*prev = cur;
			GRAPHICS::DRAW_SPRITE("Lifix", "scroll", Menu::Settings::menuX, Menu::Settings::menuY + (cur * 0.035f + 0.1415f), Menu::Settings::menuWidth, 0.035f, 0, 255, 255, 255, Menu::Settings::scroller.a);
			//GRAPHICS::DRAW_RECT(Menu::Settings::menuX, cur * 0.035f + 0.1415f, Menu::Settings::menuWidth, 0.035f, Menu::Settings::scroller.r, Menu::Settings::scroller.g, Menu::Settings::scroller.b, Menu::Settings::scroller.a);
		}
	}
	else if ((Menu::Settings::optionCount > (Menu::Settings::currentOption - Menu::Settings::maxVisOptions)) && Menu::Settings::optionCount <= Menu::Settings::currentOption) {
		GRAPHICS::DRAW_SPRITE("Lifix", "scroll", Menu::Settings::menuX, Menu::Settings::menuY + ((Menu::Settings::optionCount - (Menu::Settings::currentOption - Menu::Settings::maxVisOptions)) * 0.035f + 0.1415f), Menu::Settings::menuWidth, 0.035f, 0, 255, 255, 255, Menu::Settings::scroller.a);
		//	GRAPHICS::DRAW_RECT(Menu::Settings::menuX, ((Menu::Settings::optionCount - (Menu::Settings::currentOption - Menu::Settings::maxVisOptions)) * 0.035f + 0.1415f), Menu::Settings::menuWidth, 0.035f, Menu::Settings::scroller.r, Menu::Settings::scroller.g, Menu::Settings::scroller.b, Menu::Settings::scroller.a);
	}
}; 

float titlebox = 0.17f;
void Menu::Title(const char * title)
{
	Drawing::Rect({ 0, 0, 0, Settings::ArrowAlpha }, { Settings::menuX - Settings::scrollbarWidthIndex, Menu::Settings::menuY + 0.17f + -0.020f }, { 0.01f, 0.019f });
	Drawing::Text("3", { 255, 255, 255, Settings::ArrowAlpha, 3 }, { Settings::menuX - (Settings::scrollbarWidthIndex + 0.005f), Menu::Settings::menuY + 0.17f + -0.033f }, 0.30f);
    Drawing::Title("", Settings::titleText, { Settings::menuX, 0.060f }, { 0.85f, 0.85f }, true);


	UI::HIDE_HELP_TEXT_THIS_FRAME();
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_CHARACTER_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_LIGHT, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_HEAVY, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MULTIPLAYER_INFO, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_ALTERNATE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_CIN_CAM, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MAP_POI, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_RADIO_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_HEADLIGHT, true);
}
void Menu::Subtitle(const char * title)
{
	Drawing::Spriter("CommonMenu", "interaction_bgd", Settings::menuX, Menu::Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1065f, Menu::Settings::menuWidth, 0.035f, 180, Settings::titleEnd.r, Settings::titleEnd.g, Settings::titleEnd.b, Settings::titleEnd.a);
	Drawing::Text(title, Settings::subtitleText, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + 0.128f }, { 0.32f, 0.32f }, false);
	Drawing::Rect(Settings::line, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + ((Settings::optionCount + 1) * 0.035f + 0.1065f) }, { 0.002f, 0.035f });
	Drawing::Rect(Settings::line, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + ((Settings::optionCount + 1) * 0.035f + 0.1065f) }, { 0.002f, 0.035f });


	Drawing::Rect(Settings::line, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1235f }, { Settings::menuWidth, 0.003f });//top

}
bool Menu::Option(const char * option)
{
	Settings::optionCount++;
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
	{
		Drawing::Text(option, onThis ? Settings::SelectedText : Settings::optionText, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + ((Settings::optionCount)*0.035f + 0.128f) }, { 0.20f, 0.32f }, false);
		Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX, Menu::Settings::menuY + ((Settings::optionCount) * 0.035f + 0.1415f) }, { Settings::menuWidth, 0.035f });
		if (percenttononpercent)
		{
			Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX - Settings::scrollbarWidthIndex, Menu::Settings::menuY + ((Settings::optionCount) * 0.035f + 0.1415f) }, { 0.01f, 0.035f });
			onThis ? Drawing::Rect({ 3, 97, 164, Settings::ArrowAlpha }, { Settings::menuX - Settings::scrollbarWidthIndex, Menu::Settings::menuY + ((Settings::optionCount) * 0.035f + 0.1415f) }, { 0.008f, 0.035f }) : NULL;
		}
		Drawing::Spriter("frontend", "gradient_background", Settings::menuX, Menu::Settings::menuY + ((Settings::optionCount)*0.035f + 0.1415f), Settings::menuWidth, 0.035f, 180, Settings::optionRectSmooth.r, Settings::optionRectSmooth.g, Settings::optionRectSmooth.b, Settings::optionRectSmooth.a);
		onThis ? Drawing::Rect(Settings::scrollerr, { Settings::menuX, Menu::Settings::menuY + ((Settings::optionCount)*0.035f + 0.1415f) }, { Settings::menuWidth, 0.035f }) : NULL;
		Drawing::Rect(Settings::line, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + ((Settings::optionCount) * 0.035f + 0.1415f) }, { 0.002f, 0.035f });
		Drawing::Rect(Settings::line, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + ((Settings::optionCount) * 0.035f + 0.1415f) }, { 0.002f, 0.035f });
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		Drawing::Text(option, onThis ? Settings::SelectedText : Settings::optionText, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.128f }, { 0.20f, 0.32f }, false);
		Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { Settings::menuWidth, 0.035f });
		Drawing::Spriter("frontend", "gradient_background", Settings::menuX, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f, Settings::menuWidth, 0.035f, 180, Settings::optionRectSmooth.r, Settings::optionRectSmooth.g, Settings::optionRectSmooth.b, Settings::optionRectSmooth.a);
		onThis ? Drawing::Rect(Settings::scrollerr, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { Settings::menuWidth, 0.035f }) : NULL;
		Drawing::Rect(Settings::line, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.002f, 0.035f });
		Drawing::Rect(Settings::line, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.002f, 0.035f });
	}
	if (onThis)
		animscroll(&prevOption, Settings::currentOption);
	if (Settings::currentOption == Settings::optionCount)
	{
		if (Settings::selectPressed)
		{
			return true;
		}
	}
	return false;
}

bool Menu::FontOption(const char* option, int f)
{
	using namespace Menu;
	RGBAF font = { Settings::optionText.r, Settings::optionText.g, Settings::optionText.b, Settings::optionText.a, f };
	Settings::optionCount++;
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
	{
		Drawing::Text(option, font, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.019f), Menu::Settings::menuY + (Settings::optionCount) * 0.035f + 0.128f }, { 0.20f, 0.32f }, false);
		Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount) * 0.035f + 0.1415f }, { Settings::menuWidth, 0.035f });
		if (percenttononpercent)
		{
			Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX - Settings::scrollbarWidthIndex, Menu::Settings::menuY + (Settings::optionCount) * 0.035f + 0.1415f }, { 0.01f, 0.035f });
			onThis ? Drawing::Rect({ 3, 97, 164, Settings::ArrowAlpha }, { Settings::menuX - Settings::scrollbarWidthIndex, Menu::Settings::menuY + (Settings::optionCount) * 0.035f + 0.1415f }, { 0.008f, 0.035f }) : NULL;
		}
		Drawing::Spriter("frontend", "gradient_background", Settings::menuX, Menu::Settings::menuY + (Settings::optionCount) * 0.035f + 0.1415f, Settings::menuWidth, 0.035f, 180, Settings::optionRectSmooth.r, Settings::optionRectSmooth.g, Settings::optionRectSmooth.b, Settings::optionRectSmooth.a);
		onThis ? Drawing::Rect(Settings::scrollerr, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount) * 0.035f + 0.1415f }, { Settings::menuWidth, 0.035f }) : NULL;
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		Drawing::Text(option, font, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.019f), Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.128f }, { 0.20f, 0.32f }, false);
		Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { Settings::menuWidth, 0.035f });
		Drawing::Spriter("frontend", "gradient_background", Settings::menuX, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f, Settings::menuWidth, 0.035f, 180, Settings::optionRectSmooth.r, Settings::optionRectSmooth.g, Settings::optionRectSmooth.b, Settings::optionRectSmooth.a);
		onThis ? Drawing::Rect(Settings::scrollerr, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { Settings::menuWidth, 0.035f }) : NULL;
	}
	if (onThis)
		animscroll(&prevOption, Settings::currentOption);
	if (Settings::currentOption == Settings::optionCount)
	{
		if (Settings::selectPressed)
		{
			return true;
		}
	}
	return false;
}

bool Menu::Optionn(const char * option)
{
	Settings::optionCount++;
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
	{
		Drawing::Text(option, onThis ? Settings::SelectedText : Settings::optionTextt, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.019f), (Settings::optionCount)*0.035f + 0.128f }, { 0.20f, 0.32f }, false);
		Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { Settings::menuWidth, 0.035f });
		Drawing::Spriter("frontend", "gradient_background", Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f, Settings::menuWidth, 0.035f, 180, Settings::optionRectSmooth.r, Settings::optionRectSmooth.g, Settings::optionRectSmooth.b, Settings::optionRectSmooth.a);
		onThis ? Drawing::Rect(Settings::scrollerr, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { Settings::menuWidth, 0.035f }) : NULL;
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		Drawing::Text(option, onThis ? Settings::SelectedText : Settings::optionTextt, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.019f), (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.128f }, { 0.20f, 0.32f }, false);
		Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { Settings::menuWidth, 0.035f });
		Drawing::Spriter("frontend", "gradient_background", Settings::menuX, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f, Settings::menuWidth, 0.035f, 180, Settings::optionRectSmooth.r, Settings::optionRectSmooth.g, Settings::optionRectSmooth.b, Settings::optionRectSmooth.a);
		onThis ? Drawing::Rect(Settings::scrollerr, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { Settings::menuWidth, 0.035f }) : NULL;
	}
	if (onThis)
		animscroll(&prevOption, Settings::currentOption);
	if (Settings::currentOption == Settings::optionCount)
	{
		if (Settings::selectPressed)
		{
			return true;
		}
	}
	return false;
}

bool Menu::MenuPlayer(const char * option, std::string headShot, SubMenus newSub, int player)
{
	Option(option);
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions) {
		Drawing::Spriter(headShot, headShot, Settings::menuX + 0.090f, (Settings::optionCount * 0.035f + 0.141f), 0.02f, 0.03f, 0, 255, 255, 255, 255);
		Drawing::Text("", onThis ? Settings::arrow2 : Settings::arrow, { Settings::menuX + 0.090f, Settings::optionCount * 0.035f + 0.141f }, { 0.4f, 0.4f }, true);
	}
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption) {
		Drawing::Spriter(headShot, headShot, Settings::menuX + 0.090f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.02f, 0.03f, 0, 255, 255, 255, 255);
		Drawing::Text("", onThis ? Settings::arrow2 : Settings::arrow, { Settings::menuX + 0.090f, (Settings::optionCount - (Settings::currentOption - 16))* 0.035f + 0.90f }, { 0.4f, 0.4f }, true);

	}

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		MenuLevelHandler::MoveMenu(newSub);
		return true;
	}
	return false;
}

bool Menu::MenuPlayer(const char * option, std::string headShot, SubMenus newSub, int player, std::function<void()> function)
{
	MenuPlayer(option, headShot, newSub, player);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}

bool Menu::Break(const char * option)
{
	Settings::optionCount++;
	int DownPress = VK_DOWN;
	int NumDown = VK_NUMPAD2;
	int UpPress = VK_UP;
	int NumUp = VK_NUMPAD8;
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
	{
		Drawing::Text(option, Settings::breakText, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount)*0.035f + 0.125f }, { 0.45f, 0.45f }, true);
		Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount)*0.035f + 0.1415f }, { Settings::menuWidth, 0.035f });
		if (percenttononpercent)
		{
			Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX - Settings::scrollbarWidthIndex, Menu::Settings::menuY + (Settings::optionCount) * 0.035f + 0.1415f }, { 0.01f, 0.035f });
			onThis ? Drawing::Rect({ 3, 97, 164, Settings::ArrowAlpha }, { Settings::menuX - Settings::scrollbarWidthIndex, Menu::Settings::menuY + (Settings::optionCount) * 0.035f + 0.1415f }, { 0.008f, 0.035f }) : NULL;
		}
		if (onThis && GetAsyncKeyState(UpPress))
		{
			Settings::currentOption--;
		}
		if (onThis && GetAsyncKeyState(DownPress))
		{
			Settings::currentOption++;
		}
		if (onThis && GetAsyncKeyState(NumUp))
		{
			Settings::currentOption--;
		}
		if (onThis && GetAsyncKeyState(NumDown))
		{
			Settings::currentOption++;
		}
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		Drawing::Text(option, Settings::breakText, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.125f }, { 0.45f, 0.45f }, true);
		Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { Settings::menuWidth, 0.035f });
		if (onThis && GetAsyncKeyState(UpPress))
		{
			Settings::currentOption--;
		}
		if (onThis && GetAsyncKeyState(DownPress))
		{
			Settings::currentOption++;
		}
		if (onThis && GetAsyncKeyState(NumUp))
		{
			Settings::currentOption--;
		}
		if (onThis && GetAsyncKeyState(NumDown))
		{
			Settings::currentOption++;
		}
	}
	return false;
}
bool Menu::Option(const char * option, std::function<void()> function)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::MenuOptionn(const char * option, SubMenus newSub)
{
	Optionn(option);

	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text("~w~2~r~2", onThis ? Settings::arrow2 : Settings::arrow2, { Settings::menuX + 0.105f, Settings::optionCount * 0.035f + 0.128f }, { 0.22f, 0.22f }, true);


	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text("~r~2~r~2", onThis ? Settings::arrowww : Settings::arrowww, { Settings::menuX + 0.105f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.22f, 0.22f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		MenuLevelHandler::MoveMenu(newSub);
		return true;
	}
	return false;
}
bool Menu::MenuOptionn(const char * option, SubMenus newSub, std::function<void()> function)
{
	MenuOptionn(option, newSub);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}
bool AnimArrows = true;
int ArrowPos;
std::string Arrow = "2";
/*void AnimArrowYe(int delay)
{
	if (AnimArrows)
	{
		static int i = 0;
		if (i % delay == 0) { if (ArrowPos < 3) { ArrowPos++; } else { ArrowPos = 1; } }
		i++;
		if (ArrowPos == 1) { Arrow = "~r~2~s~2"; }
		if (ArrowPos == 2) { Arrow = "~r~2~s~2"; }
		if (ArrowPos == 3) { Arrow = "~s~2~r~2"; }
	}
}*/
int Menu::Settings::ArrowAlpha = 0;
bool Menu::MenuOption(const char * option, SubMenus newSub)
{
    Option(option);
	RGBAF penis{ 0, 0, 0, 255, 0 };
	RGBA Colour{ 255, 255, 255, 255 };

    bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (onThis)
	{
		Colour = { 0, 0, 0, Settings::ArrowAlpha };
	}
	else
	{
		Colour = { 255, 255, 255, Settings::ArrowAlpha };
	}
    if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
    	//Drawing::Text("~r~>>", penis, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.03f), Settings::optionCount * 0.035f + 0.128f }, { 0.22f, 0.22f }, true);
		Drawing::Spriter("Lifix","notonthisarrow", Settings::menuX + (Settings::scrollbarWidthIndex - 0.025f), Menu::Settings::menuY + (Settings::optionCount * 0.035f + 0.142f), 0.015f, 0.027f, 0, Colour.r, Colour.g, Colour.b, Colour.a);
    else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		//Drawing::Text("~r~>>", penis, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.03f), (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.12f }, { 0.22f, 0.22f }, true);
		Drawing::Spriter("Lifix","notonthisarrow", Settings::menuX + (Settings::scrollbarWidthIndex - 0.025f), Menu::Settings::menuY + (Settings::optionCount * 0.035f + 0.142f), 0.015f, 0.027f, 0, Colour.r, Colour.g, Colour.b, Colour.a);
    if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
        MenuLevelHandler::MoveMenu(newSub);
        return true;
    }
    return false;
}
bool Menu::MenuOption(const char * option, SubMenus newSub, std::function<void()> function)
{
	MenuOption(option, newSub);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}
void Menu::Info(const char* InfoText, int option)
{
	using namespace Menu;
	{
		int opcount = Settings::optionCount;
		int currop = Settings::currentOption;
		int visoptcnt = Settings::optionCount - Settings::breakCount;
		if (opcount >= 16) {
			if (currop == option)
			{
				Drawing::Text(InfoText, Settings::optionText, { Settings::menuX, Menu::Settings::menuY + (18 * 0.035f) + 0.129f }, { 0.3f, 0.3f }, true);
				Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX, Menu::Settings::menuY + 18 * 0.035f + 0.1415f }, { Settings::menuWidth, 0.035f });
				Drawing::Rect(Settings::line, { Settings::menuX, Menu::Settings::menuY + 18 * 0.035f + 0.1235f }, { Settings::menuWidth, 0.003f });
				Drawing::Rect(Settings::line, { Settings::menuX, Menu::Settings::menuY + 18 * 0.035f + 0.1580f }, { Settings::menuWidth, 0.003f });
				Drawing::Rect(Settings::line, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + 18 * 0.035f + 0.1415f }, { 0.002f, 0.035f });
				Drawing::Rect(Settings::line, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + 18 * 0.035f + 0.1415f }, { 0.002f, 0.035f });
			}
		}
		else if (opcount > 0) {
			if (currop == option)
			{
				Drawing::Text(InfoText, Settings::optionText, { Settings::menuX, Menu::Settings::menuY + (opcount + 2) * 0.035f + 0.129f }, { 0.3f, 0.3f }, true);
				Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount + 2) * 0.035f + 0.1415f }, { Settings::menuWidth, 0.035f });
				Drawing::Rect(Settings::line, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + (Settings::optionCount + 2) * 0.035f + 0.1415f }, { 0.002f, 0.035f });
				Drawing::Rect(Settings::line, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + (Settings::optionCount + 2) * 0.035f + 0.1415f }, { 0.002f, 0.035f });
				Drawing::Rect(Settings::line, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount + 2) * 0.035f + 0.1235f }, { Settings::menuWidth, 0.003f });
				Drawing::Rect(Settings::line, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount + 2) * 0.035f + 0.1580f }, { Settings::menuWidth, 0.003f });
			}
		}
	}
}
bool Menu::Toggle(const char * option, bool & b00l)
{
	bool onThis = Settings::currentOption == Settings::optionCount + 1 ? true : false;
	Option(option);
	if (b00l)
	{
		if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		{
			Drawing::Spriter(
				"commonmenu", 
				onThis ? "shop_box_tickb" : "shop_box_tick",
				Settings::menuX + (Settings::scrollbarWidthIndex - 0.019f),
				Menu::Settings::menuY + (Settings::optionCount * 0.035f + 0.141f),
				0.027f, 
				0.047f, 
				0,
				255, 255, 255, 255);
		}
		else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		{
			Drawing::Spriter(
				"commonmenu",
				onThis ? "shop_box_tickb" : "shop_box_tick", 
				Settings::menuX + (Settings::scrollbarWidthIndex - 0.019f),
				Menu::Settings::menuY + ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f),
				0.027f, 
				0.047f, 
				0,
				255, 255, 255, 255);
		}
	}
	else
	{
		if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		{
			Drawing::Spriter(
				"commonmenu",
				onThis ? "shop_box_blankb" : "shop_box_blank",
				Settings::menuX + (Settings::scrollbarWidthIndex - 0.019f),
				Menu::Settings::menuY + (Settings::optionCount * 0.035f + 0.141f),
				0.027f,
				0.047f,
				0,
				255, 255, 255, 255);
		}
		else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		{
			Drawing::Spriter(
				"commonmenu",
				onThis ? "shop_box_blankb" : "shop_box_blank",
				Settings::menuX + (Settings::scrollbarWidthIndex - 0.019f),
				Menu::Settings::menuY + ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f),
				0.027f,
				0.047f,
				0,
				255, 255, 255, 255);
		}
	}
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		b00l ^= 1;
		return true;
	}
	return false;
}
bool Menu::Toggle(const char * option, bool & b00l, std::function<void()> function)
{
	Toggle(option, b00l);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::Int(const char * option, int & _int, int min, int max)
{
	Option(option);
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_int < max ? _int++ : _int = min;
		}
		if (Settings::rightPressed) {
			_int >= min ? _int-- : _int = max;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
	{
		Drawing::Text(Tools::StringToChar("~p~[ ~s~" + std::to_string(_int) + " / " + std::to_string(max) + " ~p~]"), onThis ? Settings::NotOnThisDick : Settings::OnThisDick, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + Settings::optionCount * 0.035f + 0.130f }, { 0.3f, 0.3f }, false, true, true);
	}
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
	{
		Drawing::Text(Tools::StringToChar("~p~[ ~s~" + std::to_string(_int) + " / " + std::to_string(max) + " ~p~]"), onThis ? Settings::NotOnThisDick : Settings::OnThisDick, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.130f }, { 0.3f, 0.3f }, false, true, true);
	}

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::Int(const char * option, int & _int, int min, int max, int step)
{
	Option(option);

	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_int < max ? _int += step : _int = min;
		}
		if (Settings::rightPressed) {
			_int >= min ? _int -= step : _int = max;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
	{
		Drawing::Text(Tools::StringToChar("~p~[ ~s~" + std::to_string(_int) + " / " + std::to_string(max) + " ~p~]"), onThis ? Settings::NotOnThisDick : Settings::OnThisDick, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + Settings::optionCount * 0.035f + 0.130f }, { 0.3f, 0.3f }, false, true, true);
	}
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
	{
		Drawing::Text(Tools::StringToChar("~p~[ ~s~" + std::to_string(_int) + " / " + std::to_string(max) + " ~p~]"), onThis ? Settings::NotOnThisDick : Settings::OnThisDick, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.130f }, { 0.3f, 0.3f }, false, true, true);
	}

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::Int(const char * option, int & _int, int min, int max, std::function<void()> function)
{
	Int(option, _int, min, max);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::Int(const char * option, int & _int, int min, int max, int step, std::function<void()> function)
{
	Int(option, _int, min, max, step);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
//speedometer 
void Menu::AddSmallInfo2(char* text, short line)
{
	if (line == 1) {
		Drawing::Rect(Settings::optionRectSmooth, { 0.815f, 0.875f }, { 0.115f, 13 * 0.035f + -0.193f });
	}
	Drawing::Text(text, Settings::count, { 0.815f, 0.870f }, { 0.75f, 0.75f }, false);

}
#pragma warning(disable: 4244)
bool Menu::Float(const char * option, float & _float, int min, int max)
{
	bool onThis = Settings::currentOption == Settings::optionCount + 1 ? true : false;
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::rightPressed) {
			_float <= min ? _float = max : _float -= 0.1f;
		}
		if (Settings::leftPressed) {
			_float >= max ? _float = min : _float += 0.1f;
		}
		_float < min ? _float = max : _float > max ? _float = min : NULL;
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions) {
		std::string currStr = std::to_string(_float);
		std::string currStr2(currStr.begin(), std::find(currStr.begin(), currStr.end(), '.'));
		if (_float == min)
		{
			Drawing::Text(Tools::StringToChar(currStr.substr(0, (currStr2.length() + 6)) + ">"), Menu::Settings::NumberOption, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + Settings::optionCount * 0.035f + 0.13f }, { 0.3f, 0.3f }, false, true, true);
		}
		else if (_float == max)
		{
			Drawing::Text(Tools::StringToChar("<" + currStr.substr(0, (currStr2.length() + 6))), Menu::Settings::NumberOption, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + Settings::optionCount * 0.035f + 0.13f }, { 0.3f, 0.3f }, false, true, true);
		}
		else
		{
			Drawing::Text(Tools::StringToChar("<" + currStr.substr(0, (currStr2.length() + 6)) + ">"), Menu::Settings::NumberOption, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + Settings::optionCount * 0.035f + 0.13f }, { 0.3f, 0.3f }, false, true, true);
		}
	}
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption) {
		std::string currStr = std::to_string(_float);
		std::string currStr2(currStr.begin(), std::find(currStr.begin(), currStr.end(), '.'));
		if (_float == min)
		{
			Drawing::Text(Tools::StringToChar(currStr.substr(0, (currStr2.length() + 6)) + ">"), Menu::Settings::NumberOption, { Settings::menuX + 0.073f, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 10)) * 0.035f + 0.13f }, { 0.3f, 0.3f }, false, true, true);
		}
		else if (_float == max)
		{
			Drawing::Text(Tools::StringToChar("<" + currStr.substr(0, (currStr2.length() + 6))), Menu::Settings::NumberOption, { Settings::menuX + 0.073f, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 10)) * 0.035f + 0.13f }, { 0.3f, 0.3f }, false, true, true);
		}
		else
		{
			Drawing::Text(Tools::StringToChar("<" + currStr.substr(0, (currStr2.length() + 6)) + ">"), Menu::Settings::NumberOption, { Settings::menuX + 0.073f, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 10)) * 0.035f + 0.13f }, { 0.3f, 0.3f }, false, true, true);
		}
	}

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}

bool Menu::Float(const char * option, float & _float, int min, int max, int step)
{
	bool onThis = Settings::currentOption == Settings::optionCount + 1 ? true : false;
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::rightPressed) {
			_float <= min ? _float = max : _float -= step;
		}
		if (Settings::leftPressed) {
			_float >= max ? _float = min : _float += step;
		}
		_float < min ? _float = max : _float > max ? _float = min : NULL;
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions) {
		std::string currStr = std::to_string(_float);
		std::string currStr2(currStr.begin(), std::find(currStr.begin(), currStr.end(), '.'));
		if (_float == min)
		{
			Drawing::Text(Tools::StringToChar(currStr.substr(0, (currStr2.length() + 6)) + ">"), Menu::Settings::NumberOption, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + Settings::optionCount * 0.035f + 0.13f }, { 0.3f, 0.3f }, false, true, true);
		}
		else if (_float == max)
		{
			Drawing::Text(Tools::StringToChar("<" + currStr.substr(0, (currStr2.length() + 6))), Menu::Settings::NumberOption, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + Settings::optionCount * 0.035f + 0.13f }, { 0.3f, 0.3f }, false, true, true);
		}
		else
		{
			Drawing::Text(Tools::StringToChar("<" + currStr.substr(0, (currStr2.length() + 6)) + ">"), Menu::Settings::NumberOption, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + Settings::optionCount * 0.035f + 0.13f }, { 0.3f, 0.3f }, false, true, true);
		}
	}
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption) {
		std::string currStr = std::to_string(_float);
		std::string currStr2(currStr.begin(), std::find(currStr.begin(), currStr.end(), '.'));
		if (_float == min)
		{
			Drawing::Text(Tools::StringToChar(currStr.substr(0, (currStr2.length() + 6)) + ">"), Menu::Settings::NumberOption, { Settings::menuX + 0.073f, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 10)) * 0.035f + 0.13f }, { 0.3f, 0.3f }, false, true, true);
		}
		else if (_float == max)
		{
			Drawing::Text(Tools::StringToChar("<" + currStr.substr(0, (currStr2.length() + 6))), Menu::Settings::NumberOption, { Settings::menuX + 0.073f, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 10)) * 0.035f + 0.13f }, { 0.3f, 0.3f }, false, true, true);
		}
		else
		{
			Drawing::Text(Tools::StringToChar("<" + currStr.substr(0, (currStr2.length() + 6)) + ">"), Menu::Settings::NumberOption, { Settings::menuX + 0.073f, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 10))*0.035f + 0.13f }, { 0.3f, 0.3f }, false, true, true);
		}
	}

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
#pragma warning(default: 4244)

bool Menu::Float(const char * option, float & _float, int min, int max, std::function<void()> function)
{
	Float(option, _float, min, max);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}

bool Menu::Float(const char * option, float & _float, int min, int max, int step, std::function<void()> function)
{
	Float(option, _float, min, max, step);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}

#pragma warning(disable: 4267)
bool Menu::IntVector(const char * option, std::vector<int> Vector, int & position)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		int max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Menu::Settings::menuY + Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}

bool Menu::IntVector(const char * option, std::vector<int> Vector, int & position, std::function<void()> function)
{
	IntVector(option, Vector, position);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}

bool Menu::FloatVector(const char * option, std::vector<float> Vector, int & position)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Menu::Settings::menuY + Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}

bool Menu::FloatVector(const char * option, std::vector<float> Vector, int & position, std::function<void()> function)
{
	FloatVector(option, Vector, position);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}

void Menu::info(const char * info)
{
	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
	{
		if (bool onThis = true) {
			Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, Menu::Settings::menuY + (17 * 0.035f + 0.1600f) }, { 0.25f, 0.25f }, false), Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX, 17 * 0.035f + 0.1820f }, { 0.21f, 0.045f });
		}
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		if (bool onThis = true) {
			Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1300f }, { 0.25f, 0.25f }, false), Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX, (Settings::optionCount + 1) * 0.035f + 0.1820f }, { 0.21f, 0.045f });
		}
	}
}
bool Menu::StringVector(const char * option, std::vector<std::string> Vector, int & position)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::rightPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::leftPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar((Vector[position])), Settings::optionText, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + Settings::optionCount * 0.035f + 0.13f }, { 0.5f, 0.5f }, false, true, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar((Vector[position])), Settings::optionText, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.13f }, { 0.5f, 0.5f }, false, true, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::StringVector(const char * option, std::vector<std::string> Vector, int & position, std::function<void()> function)
{
	StringVector(option, Vector, position);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::StringVector(const char * option, std::vector<char*> Vector, int & position)
{
	bool onThis = Settings::currentOption == Settings::optionCount + 1 ? true : false;
	constexpr static const VECTOR2_2 textSize = { 0.36f, 0.35f };
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::rightPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::leftPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions) {
		std::string SelectedChar
			= UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Vector[position])));

		UI::SET_TEXT_COLOUR(onThis ? 0 : Settings::integre.r, onThis ? 0 : Settings::integre.g, onThis ? 0 : Settings::integre.b, Settings::integre.a);
		UI::SET_TEXT_FONT(Settings::integre.f);
		UI::SET_TEXT_SCALE(textSize.w, textSize.h);
		UI::SET_TEXT_RIGHT_JUSTIFY(TRUE);
		UI::SET_TEXT_WRAP(Settings::menuX, Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f));
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Tools::StringToChar(SelectedChar + " ~c~[ " + std::to_string(position + 1) + " / " + std::to_string(Vector.size()) + " ]"));
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(Settings::menuX + 0.082f, Menu::Settings::menuY + (Settings::optionCount * 0.035f + 0.129f));
	}
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption) {
		std::string SelectedChar
			= UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Vector[position])));

		UI::SET_TEXT_COLOUR(onThis ? 0 : Settings::integre.r, onThis ? 0 : Settings::integre.g, onThis ? 0 : Settings::integre.b, Settings::integre.a);
		UI::SET_TEXT_FONT(Settings::integre.f);
		UI::SET_TEXT_SCALE(textSize.w, textSize.h);
		UI::SET_TEXT_RIGHT_JUSTIFY(TRUE);
		UI::SET_TEXT_WRAP(Settings::menuX, Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f));
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Tools::StringToChar(SelectedChar + " ~c~[ " + std::to_string(position + 1) + " / " + std::to_string(Vector.size()) + " ]"));
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(Settings::menuX + 0.060f, Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - Settings::maxVisOptions))*0.035f + 0.129f);
	}

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}

void Menu::End(const char * title)
{
	Menu::Drawing::YTD();
	int opcount = Settings::optionCount;
    int currop = Settings::currentOption;
	int visoptcnt = Settings::optionCount - Settings::breakCount;
    if (opcount >= 16) {
		Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount) + " | Beta 1.0"), Settings::count, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + (17 * 0.035f + 0.129f) }, { 0.35f, 0.35f }, false, true, false);
		Drawing::Text("https://discord.io/LifixMenu", Settings::count, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + (17 * 0.035f) + 0.129f }, { 0.35f, 0.35f }, false);
        Drawing::Rect(Settings::Endrectlol, { Settings::menuX, Menu::Settings::menuY + 17 * 0.035f + 0.1415f }, { Settings::menuWidth, 0.035f });
		Drawing::Rect(Settings::line, { Settings::menuX, Menu::Settings::menuY + 17 * 0.035f + 0.1235f }, { Settings::menuWidth, 0.003f });//top
		Drawing::Rect(Settings::line, { Settings::menuX, Menu::Settings::menuY + 17 * 0.035f + 0.1580f }, { Settings::menuWidth, 0.003f });//bottom
		Drawing::Rect(Settings::line, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + 17 * 0.035f + 0.1415f }, { 0.002f, 0.035f });
		Drawing::Rect(Settings::line, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + 17 * 0.035f + 0.1415f }, { 0.002f, 0.035f });

		Drawing::Rect({ 0, 0, 0, Settings::ArrowAlpha }, { Settings::menuX - Settings::scrollbarWidthIndex, Menu::Settings::menuY + 0.17f + 17 * 0.035f + -0.037f }, { 0.01f, 0.018f });
		Drawing::Text("4", { 255, 255, 255, Settings::ArrowAlpha, 3 }, { Settings::menuX - (Settings::scrollbarWidthIndex + 0.005f), Menu::Settings::menuY + 0.17f + 17 * 0.035f + -0.055f }, 0.30f);
		if (currop == 1)
		{
			Drawing::Spriter("Lifix", "top", Settings::menuX, Menu::Settings::menuY + ((16 + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 0, Settings::linego.r, Settings::linego.g, Settings::linego.b, Settings::linego.a);
		}
		else if (currop == opcount)
		{
			Drawing::Spriter("Lifix", "bottom", Settings::menuX, Menu::Settings::menuY + ((16 + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 0, Settings::linego.r, Settings::linego.g, Settings::linego.b, Settings::linego.a);
		}
		else
		{
			Drawing::Spriter("Lifix", "topandbottom", Settings::menuX, Menu::Settings::menuY + ((16 + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 0, Settings::linego.r, Settings::linego.g, Settings::linego.b, Settings::linego.a);
		}
    }
    else if (opcount > 0) {
		Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount) + " | Beta 1.0"), Settings::count, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.129f }, { 0.35f, 0.35f }, false, true, false);
		Drawing::Text("Nano69", Settings::count, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.015f), Menu::Settings::menuY + (opcount + 1) * 0.035f + 0.129f }, { 0.35f, 0.35f }, false);
        Drawing::Rect(Settings::Endrectlol, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1415f }, { Settings::menuWidth, 0.035f });
		Drawing::Rect(Settings::line, { Settings::menuX - (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1415f }, { 0.002f, 0.035f });
		Drawing::Rect(Settings::line, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.009f), Menu::Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1415f }, { 0.002f, 0.035f });
		
		Drawing::Rect({ 0, 0, 0, Settings::ArrowAlpha }, { Settings::menuX - Settings::scrollbarWidthIndex, Menu::Settings::menuY + 0.17f + (Settings::optionCount + 1) * 0.035f + -0.037f }, { 0.01f, 0.019f });
		Drawing::Text("4", { 255, 255, 255, Settings::ArrowAlpha, 3 }, { Settings::menuX - (Settings::scrollbarWidthIndex + 0.005f), Menu::Settings::menuY + 0.17f + (Settings::optionCount + 1) * 0.035f + -0.055f }, 0.30f);

		
		Drawing::Rect(Settings::line, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1235f }, { Settings::menuWidth, 0.003f });//top
		Drawing::Rect(Settings::line, { Settings::menuX, Menu::Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1580f }, { Settings::menuWidth, 0.003f });//bottom


		if (currop == 1)
		{
			Drawing::Spriter("Lifix", "top", Settings::menuX, Menu::Settings::menuY + ((Settings::optionCount + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 0, Settings::linego.r, Settings::linego.g, Settings::linego.b, Settings::linego.a);
		}
		else if (currop == opcount)
		{
			Drawing::Spriter("Lifix", "bottom", Settings::menuX, Menu::Settings::menuY + ((Settings::optionCount + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 0, Settings::linego.r, Settings::linego.g, Settings::linego.b, Settings::linego.a);
		}
		else
		{
			Drawing::Spriter("Lifix", "topandbottom", Settings::menuX, Menu::Settings::menuY + ((Settings::optionCount + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 0, Settings::linego.r, Settings::linego.g, Settings::linego.b, Settings::linego.a);
		}
    }
	 // lol, fixed, now i need to go, 
}



bool Menu::ListVector(const char * option, std::vector<char*> Vector, int & position)
{
	bool onThis = Settings::currentOption == Settings::optionCount + 1 ? true : false;

	constexpr static const VECTOR2_2 textSize = { 0.32f, 0.32f };
	Option(option);
	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;

		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
	  Drawing::Text(Tools::StringToChar(Vector[position]), onThis ? Settings::NotOnThisDick : Settings::OnThisDick, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.019f), Menu::Settings::menuY + Settings::optionCount * 0.035f + 0.13f }, textSize, false, true, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(Vector[position]), onThis ? Settings::NotOnThisDick : Settings::OnThisDick, { Settings::menuX + (Settings::scrollbarWidthIndex - 0.019f), Menu::Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.13f }, textSize, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else 
		return false;
}

int IconNotification(char *text, char *text2, char *Subject)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	return UI::_DRAW_NOTIFICATION(1, 1);
}
void PlaySoundFrontend_default(char* sound_name)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound_name, "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
}
void PlaySoundFrontend_default2(char* sound_name)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound_name, "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS", 0);
}
char * Menu::Tools::StringToChar(std::string string)
{
	return _strdup(string.c_str());
}

int Menu::Settings::keyPressDelay = 200;
int Menu::Settings::keyPressPreviousTick = GetTickCount();
int Menu::Settings::keyPressDelay2 = 150;
int Menu::Settings::keyPressPreviousTick2 = GetTickCount();
int Menu::Settings::keyPressDelay3 = 140;
int Menu::Settings::keyPressPreviousTick3 = GetTickCount();

#pragma warning(disable: 4018)
bool firstopen = true;
void Menu::Checks::Keys()
{
	Settings::selectPressed = false;
	Settings::leftPressed = false;
	Settings::rightPressed = false;
	if (GetTickCount() - Settings::keyPressPreviousTick > Settings::keyPressDelay) {
		if (GetTickCount() - Settings::keyPressPreviousTick2 > Settings::keyPressDelay2) {
			if (GetTickCount() - Settings::keyPressPreviousTick3 > Settings::keyPressDelay3) {
				if (IsKeyPressed(VK_F4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlScriptRB) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight)) {
					Settings::menuLevel == 0 ? MenuLevelHandler::MoveMenu(SubMenus::mainmenu) : Settings::menuLevel == 1 ? MenuLevelHandler::BackMenu() : NULL;
					if (firstopen) {
						PlaySoundFrontend_default2("Hack_Success");
						prevOption = 1;
						firstopen = false;
					}

					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD0) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel)) {
					Settings::menuLevel > 0 ? MenuLevelHandler::BackMenu() : NULL;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("BACK");
					prevOption = 1;
					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp)) {
					Settings::currentOption > 1 ? Settings::currentOption-- : Settings::currentOption = Settings::optionCount;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("Security_Door_Alarm");

					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown)) {
					Settings::currentOption < Settings::optionCount ? Settings::currentOption++ : Settings::currentOption = 1;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("Security_Door_Alarm");

					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight)) {
					Settings::leftPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("Security_Door_Alarm");

					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneLeft)) {
					Settings::rightPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("Security_Door_Alarm");

					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Settings::selectPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("SELECT");

					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_BACK) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel)) {
					Settings::menuLevel > 0 ? MenuLevelHandler::BackMenu() : NULL;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("BACK");

					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_UP) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp)) {
					Settings::currentOption > 1 ? Settings::currentOption-- : Settings::currentOption = Settings::optionCount;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("Security_Door_Alarm");

					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_DOWN) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown)) {
					Settings::currentOption < Settings::optionCount ? Settings::currentOption++ : Settings::currentOption = 1;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("Security_Door_Alarm");

					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_LEFT) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneLeft)) {
					Settings::leftPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("Security_Door_Alarm");

					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_RIGHT) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight)) {
					Settings::rightPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("Security_Door_Alarm");

					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_RETURN) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Settings::selectPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("SELECT");

					Settings::keyPressPreviousTick = GetTickCount();
				}

				//Increase wanted level.
				if (KeyJustUp(VK_ADD))
				{
					if (PLAYER::GET_PLAYER_WANTED_LEVEL(playerr) < 5)
					{
						PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(playerr, PLAYER::GET_PLAYER_WANTED_LEVEL(playerr) + 1, FALSE);
						PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(playerr, FALSE);


					}
				}
				if (KeyJustUp(VK_F8))
				{
					if (PLAYER::GET_PLAYER_WANTED_LEVEL(playerr) < 0)
					{
						PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(playerr, PLAYER::GET_PLAYER_WANTED_LEVEL(playerr) - 1, FALSE);
						PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(playerr, FALSE);
					}
				}
				//Decrease wanted level.
				if (KeyJustUp(VK_MULTIPLY))
				{
					if (PLAYER::GET_PLAYER_WANTED_LEVEL(playerr) < 0)
					{
						PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(playerr, PLAYER::GET_PLAYER_WANTED_LEVEL(playerr) - 1, FALSE);
						PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(playerr, FALSE);
					}
				}

				//Teleport to waypoint.
				if (KeyJustUp(VK_F5))
				{
					teleport_to_marker();
				}

				//Teleport to Mission Objective
				if (KeyJustUp(VK_F7))
				{
					//teleport_to_objective();

				}

				//Spawn Vehicle
				if (KeyJustUp(VK_F6))
				{
					//request_vehicle();
				}
			}
		}
	}
	Settings::optionCount = 0;
}

#pragma warning(default : 4018)

void Menu::MenuLevelHandler::MoveMenu(SubMenus menu)
{
	Settings::menusArray[Settings::menuLevel] = Settings::currentMenu;
	Settings::optionsArray[Settings::menuLevel] = Settings::currentOption;
	Settings::menuLevel++;
	Settings::currentMenu = menu;
	Settings::currentOption = 1;
}

void Menu::MenuLevelHandler::BackMenu()
{
	Settings::menuLevel--;
	Settings::currentMenu = Settings::menusArray[Settings::menuLevel];
	Settings::currentOption = Settings::optionsArray[Settings::menuLevel];
}
void Menu::Files::WriteStringToIni(std::string string, std::string file, std::string app, std::string key)
{
	WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), file.c_str());
}
std::string Menu::Files::ReadStringFromIni(std::string file, std::string app, std::string key)
{
	char buf[100];
	GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, file.c_str());
	return (std::string)buf;
}

void Menu::Files::WriteIntToIni(int intValue, std::string file, std::string app, std::string key)
{
	WriteStringToIni(std::to_string(intValue), file, app, key);
}

int Menu::Files::ReadIntFromIni(std::string file, std::string app, std::string key)
{
	return std::stoi(ReadStringFromIni(file, app, key));
}

void Menu::Files::WriteFloatToIni(float floatValue, std::string file, std::string app, std::string key)
{
	WriteStringToIni((std::to_string(floatValue)), file, app, key);
}

float Menu::Files::ReadFloatFromIni(std::string file, std::string app, std::string key)
{
	return std::stof(ReadStringFromIni(file, app, key));
}

void Menu::Files::WriteBoolToIni(bool b00l, std::string file, std::string app, std::string key)
{
	WriteStringToIni(b00l ? "true" : "false", file, app, key);
}

bool Menu::Files::ReadBoolFromIni(std::string file, std::string app, std::string key)
{
	return ReadStringFromIni(file, app, key) == "true" ? true : false;
}
//------Colorbox----------------
void Menu::Colorbox2(std::string texture1, std::string texture2, int r, int g, int b, int a)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (Menu::Settings::optionCount == Menu::Settings::currentOption) { Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX + 0.21f, 0.2f, 0.11f, 0.11f, 0, r, g, b, a); }
	}
	else { if (Menu::Settings::optionCount == Menu::Settings::currentOption) { Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX - 0.21f, 0.2f, 0.11f, 0.11f, 0, r, g, b, a); } }
}
void Menu::Colorbox(std::string texture1, std::string texture2, RGBA rgba)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (Menu::Settings::optionCount == Menu::Settings::currentOption) { Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX + 0.21f, 0.2f, 0.11f, 0.11f, 0, rgba.r, rgba.g, rgba.b, rgba.a); }
	}
	else { if (Menu::Settings::optionCount == Menu::Settings::currentOption) { Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX - 0.21f, 0.2f, 0.11f, 0.11f, 0, rgba.r, rgba.g, rgba.b, rgba.a); } }
}
//---------Vehicle----------------
void Menu::Vehicle(std::string texture1, std::string texture2)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text("Vehicle Pictures", Settings::titleText2, { Settings::menuX + 0.240f, Menu::Settings::menuY + 0.145f }, { 0.425f, 0.425f }, true);

		Menu::Drawing::Spriter("CommonMenu", "interaction_bgd", Menu::Settings::menuX + 0.21f, Menu::Settings::menuY + 0.1f, 0.13f, 0.13f, 0, 255, 0, 0, 255);

		Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX + 0.21f, Menu::Settings::menuY + 0.1f, 0.11f, 0.11f, 0, 255, 255, 255, 255);
	}
	else
	{
		Drawing::Text("Vehicle Pictures", Settings::titleText2, { Settings::menuX + 0.240f, Menu::Settings::menuY + 0.145f }, { 0.425f, 0.425f }, true);

		Menu::Drawing::Spriter("CommonMenu", "interaction_bgd", Menu::Settings::menuX + 0.21f, Menu::Settings::menuY + 0.1f, 0.13f, 0.13f, 0, 255, 0, 0, 255);
		Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX - 0.21f, Menu::Settings::menuY + 0.1f, 0.11f, 0.11f, 0, 255, 255, 255, 255);
		//}
	}
}
void Menu::Vehicle2(std::string texture1, std::string texture2)
{
	if (Menu::Settings::optionCount == Menu::Settings::currentOption) { Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX - 0.21f, 0.362f, 0.15f, 0.18f, 0, 255, 255, 255, 255); }
}
//-----------Player Info-----------
void Menu::AddSmallTitle(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(text, Settings::titleText2, { Settings::menuX + 0.200f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("nano69", "Playerinfo", Settings::menuX + 0.200f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Menu::Settings::titleRect.r, Menu::Settings::titleRect.g, Menu::Settings::titleRect.b, Menu::Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText2, { Settings::menuX + 0.200f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("nano69", "Playerinfo", Settings::menuX + 0.200f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Menu::Settings::titleRect.r, Menu::Settings::titleRect.g, Menu::Settings::titleRect.b, Menu::Settings::titleRect.a);
	}
}
void Menu::AddSmallInfo(char* text, short line)
{
    const __int8 maxSize = 32;
    if (Menu::Settings::menuX < 0.78f)
    {
        if (line == 1) {
            Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX + 0.200f, ((static_cast<int>(23) * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, static_cast<int>(23) * 0.035f + -0.193f });
        }
        Drawing::Text(text, Settings::title_end, { Settings::menuX + 0.145f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
    }
    else
    {
        if (line == 1) {
            Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX - 0.200f, ((static_cast<int>(23) * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, static_cast<int>(23) * 0.035f + -0.193f });
        }
        Drawing::Text(text, Settings::title_end, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
    }
}
void Menu::AddSmallTitle2(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.200f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "header_gradient_script", Settings::menuX + 0.200f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.200f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "header_gradient_script", Settings::menuX - 0.200f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}

bool Menu::Settings::controllerinput = true;
void Menu::Checks::Controlls()
{
	Settings::selectPressed = false;
	Settings::leftPressed = false;
	Settings::rightPressed = false;
	if (GetTickCount() - Settings::keyPressPreviousTick > Settings::keyPressDelay) {
		if (GetTickCount() - Settings::keyPressPreviousTick2 > Settings::keyPressDelay2) {
			if (GetTickCount() - Settings::keyPressPreviousTick3 > Settings::keyPressDelay3) {
				if (IsKeyPressed(VK_F8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlScriptRB) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput) {
					Settings::menuLevel == 0 ? MenuLevelHandler::MoveMenu(SubMenus::mainmenu) : Settings::menuLevel == 1 ? MenuLevelHandler::BackMenu() : NULL;
					Settings::keyPressPreviousTick = GetTickCount();
					AUDIO::PLAY_SOUND_FRONTEND(-1, "ScreenFlash", "MissionFailedSounds", 0);
				}
				else if (IsKeyPressed(VK_NUMPAD0) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel) && Settings::controllerinput) {
					Settings::menuLevel > 0 ? MenuLevelHandler::BackMenu() : NULL;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("BACK");

					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp) && Settings::controllerinput) {
					Settings::currentOption > 1 ? Settings::currentOption-- : Settings::currentOption = Settings::optionCount;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick2 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown) && Settings::controllerinput) {
					Settings::currentOption < Settings::optionCount ? Settings::currentOption++ : Settings::currentOption = 1;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick2 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput) {
					Settings::leftPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick3 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneLeft) && Settings::controllerinput) {
					Settings::rightPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick3 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept) && Settings::controllerinput) {
					Settings::selectPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("SELECT");

					Settings::keyPressPreviousTick = GetTickCount();
				}
			}
		}
	}
	Settings::optionCount = 0;
}

void Menu::PlayerInfoTitle(char* text)
{
	//Drawing::Rect(Settings::titleRect, { Settings::menuX + 0.230f,  0.1250f }, { 0.165f, 0.045f });
	Drawing::Spriter("nano69", "playerinfo", Settings::menuX + 0.230f, 0.1250f, 0.165f, 0.045f, 180, Settings::line.r, Settings::line.g, Settings::line.b, Settings::line.a);

	Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.230f, 0.1097f }, { 0.425f, 0.425f }, true);
}

void Menu::PlayerInfoLine(char* text, short line)
{
	if (line == 1) {
		//Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.230f, 0.3335f }, { 0.165f, 13 * 0.045f + -0.213f });
		Drawing::Spriter("nano69", "playerinfo", Settings::menuX + 0.1385f, 0.2520f, 0.019f, 0.085f, 180, Settings::line.r, Settings::line.g, Settings::line.b, Settings::line.a);
		//Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.1385f, 0.2520f }, { 0.019f, 0.085f });
	}
	Drawing::Text(text, Settings::optionText, { Settings::menuX + 0.250f, (line * 0.030f) + 0.155f }, { 0.35f, 0.35f }, true);
}

void Menu::AddSmallInfo3(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX + 0.250f, ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
			//Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });

		}
		Drawing::Text(text, Settings::title_end, { Settings::menuX + 0.145f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRectSmooth, { Settings::menuX - 0.250f, ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::title_end, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}
class Ini
{
private:
	std::string inifile;
public:
	Ini(std::string file)
	{
		this->inifile = file;
	}

	void WriteString(std::string string, std::string app, std::string key)
	{
		WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), this->inifile.c_str());
	}
	std::string GetString(std::string app, std::string key)
	{
		char buf[100];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, this->inifile.c_str());
		return (std::string)buf;
	}

	void WriteInt(int value, std::string app, std::string key)
	{
		WriteString(std::to_string(value), app, key);
	}
	int GetInt(std::string app, std::string key)
	{
		return std::stoi(GetString(app, key));
	}

	void WriteFloat(float value, std::string app, std::string key)
	{
		WriteString(std::to_string(value), app, key);
	}
	float GetFloat(std::string app, std::string key)
	{
		return std::stof(GetString(app, key));
	}
};
std::string MenuStyleFile = ".\\ThemeMenu\\MenuStyle.ini";
void Menu::Files::StyleSaver::SaveStyles()
{
	// Title Text
	WriteIntToIni(Settings::titleText.r, MenuStyleFile, "Title Text", "Red");
	WriteIntToIni(Settings::titleText.g, MenuStyleFile, "Title Text", "Green");
	WriteIntToIni(Settings::titleText.b, MenuStyleFile, "Title Text", "Blue");
	WriteIntToIni(Settings::titleText.a, MenuStyleFile, "Title Text", "Alpha");
	WriteIntToIni(Settings::titleText.f, MenuStyleFile, "Title Text", "Font");

	// Title Rect
	WriteIntToIni(Settings::titleRect.r, MenuStyleFile, "Title Rect", "Red");
	WriteIntToIni(Settings::titleRect.g, MenuStyleFile, "Title Rect", "Green");
	WriteIntToIni(Settings::titleRect.b, MenuStyleFile, "Title Rect", "Blue");
	WriteIntToIni(Settings::titleRect.a, MenuStyleFile, "Title Rect", "Alpha");

	// Option Text
	WriteIntToIni(Settings::optionText.r, MenuStyleFile, "Option Text", "Red");
	WriteIntToIni(Settings::optionText.g, MenuStyleFile, "Option Text", "Green");
	WriteIntToIni(Settings::optionText.b, MenuStyleFile, "Option Text", "Blue");
	WriteIntToIni(Settings::optionText.a, MenuStyleFile, "Option Text", "Alpha");
	WriteIntToIni(Settings::optionText.f, MenuStyleFile, "Option Text", "Font");

	// Option Rect
	WriteIntToIni(Settings::optionRectSmooth.r, MenuStyleFile, "Option Rect", "Red");
	WriteIntToIni(Settings::optionRectSmooth.g, MenuStyleFile, "Option Rect", "Green");
	WriteIntToIni(Settings::optionRectSmooth.b, MenuStyleFile, "Option Rect", "Blue");
	WriteIntToIni(Settings::optionRect.a, MenuStyleFile, "Option Rect", "Alpha");

	// Scroller
	WriteIntToIni(Settings::scroller.r, MenuStyleFile, "Scroller", "Red");
	WriteIntToIni(Settings::scroller.g, MenuStyleFile, "Scroller", "Green");
	WriteIntToIni(Settings::scroller.b, MenuStyleFile, "Scroller", "Blue");
	WriteIntToIni(Settings::scroller.a, MenuStyleFile, "Scroller", "Alpha");
}

void Menu::Files::StyleSaver::LoadStyles()
{
	// Title Text
	Settings::titleText.r = ReadIntFromIni(MenuStyleFile, "Title Text", "Red");
	Settings::titleText.g = ReadIntFromIni(MenuStyleFile, "Title Text", "Green");
	Settings::titleText.b = ReadIntFromIni(MenuStyleFile, "Title Text", "Blue");
	Settings::titleText.a = ReadIntFromIni(MenuStyleFile, "Title Text", "Alpha");
	Settings::titleText.f = ReadIntFromIni(MenuStyleFile, "Title Text", "Font");

	// Title Rect
	Settings::titleRect.r = ReadIntFromIni(MenuStyleFile, "Title Rect", "Red");
	Settings::titleRect.g = ReadIntFromIni(MenuStyleFile, "Title Rect", "Green");
	Settings::titleRect.b = ReadIntFromIni(MenuStyleFile, "Title Rect", "Blue");
	Settings::titleRect.a = ReadIntFromIni(MenuStyleFile, "Title Rect", "Alpha");

	// Option Text
	Settings::optionText.r = ReadIntFromIni(MenuStyleFile, "Option Text", "Red");
	Settings::optionText.g = ReadIntFromIni(MenuStyleFile, "Option Text", "Green");
	Settings::optionText.b = ReadIntFromIni(MenuStyleFile, "Option Text", "Blue");
	Settings::optionText.a = ReadIntFromIni(MenuStyleFile, "Option Text", "Alpha");
	Settings::optionText.f = ReadIntFromIni(MenuStyleFile, "Option Text", "Font");

	// Option Rect
	Settings::optionRectSmooth.r = ReadIntFromIni(MenuStyleFile, "Option Rect", "Red");
	Settings::optionRectSmooth.g = ReadIntFromIni(MenuStyleFile, "Option Rect", "Green");
	Settings::optionRectSmooth.b = ReadIntFromIni(MenuStyleFile, "Option Rect", "Blue");
	Settings::optionRect.a = ReadIntFromIni(MenuStyleFile, "Option Rect", "Alpha");

	// Scroller
	Settings::scroller.r = ReadIntFromIni(MenuStyleFile, "Scroller", "Red");
	Settings::scroller.g = ReadIntFromIni(MenuStyleFile, "Scroller", "Green");
	Settings::scroller.b = ReadIntFromIni(MenuStyleFile, "Scroller", "Blue");
	Settings::scroller.a = ReadIntFromIni(MenuStyleFile, "Scroller", "Alpha");
}

/*int Menu::Settings::infobox = 0;
void Menu::GAYBOY(const char* infotext)
{
	//INFOBOX
	if (Menu::Settings::infobox == 0) {
		Drawing::Rect(Settings::optionRect, { 0.50f, 0.9010f }, { Menu::Settings::menuXscale, 0.085f });
		Drawing::Spriter("Lifix", "box", 0.50f, 0.8370f, Menu::Settings::menuXscale, 0.050f, 0, 255, 255, 255, 255);
	}
	if (Menu::Settings::infobox == 1) {
		Drawing::Rect(Settings::optionRect, { 0.50f, 0.9010f }, { Menu::Settings::menuXscale, 0.085f });
		Drawing::Spriter("Lifix", "box2", 0.50f, 0.8370f, Menu::Settings::menuXscale, 0.050f, 0, 255, 255, 255, 255);
	}
	if (Menu::Settings::infobox == 2) {
		Drawing::Rect(Settings::optionRect, { 0.50f, 0.9010f }, { Menu::Settings::menuXscale, 0.085f });
		Drawing::Spriter("Lifix", "box3", 0.50f, 0.8370f, Menu::Settings::menuXscale, 0.050f, 0, 255, 255, 255, 255);
	}
	//Drawing::Rect(Settings::optionRect, { 0.50f, 0.9010f }, { Menu::Settings::menuXscale, 0.085f } );
	Menu::Drawing::Text(infotext, Menu::Settings::TextgayBoy, { 0.39f, 0.8620f }, { 0.32f, 0.32f }, false);
	Drawing::Rect(Settings::linebox, { 0.50f,  0.8600f }, { 0.23f, 0.002f });//top
	Drawing::Rect(Settings::linebox, { 0.50f,  0.9450f }, { 0.23f, 0.002f });//bottum
}*/

int VAR_INSTRUCTIONAL_CONTAINER;
int VAR_INSTRUCTIONAL_COUNT;
void InstructionsInit() {
	VAR_INSTRUCTIONAL_COUNT = 0;
	VAR_INSTRUCTIONAL_CONTAINER = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");
	GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(VAR_INSTRUCTIONAL_CONTAINER, 255, 255, 255, 0, 0);
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(VAR_INSTRUCTIONAL_CONTAINER, "CLEAR_ALL");
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(VAR_INSTRUCTIONAL_CONTAINER, "SET_CLEAR_SPACE");
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(200);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void InstructionsAdd(char *text, int button) {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(VAR_INSTRUCTIONAL_CONTAINER, "SET_DATA_SLOT");
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(VAR_INSTRUCTIONAL_COUNT);
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(button);
	GRAPHICS::BEGIN_TEXT_COMMAND_SCALEFORM_STRING("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	GRAPHICS::END_TEXT_COMMAND_SCALEFORM_STRING();
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
	VAR_INSTRUCTIONAL_COUNT++;
}
void InstructionsEnd() {
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(VAR_INSTRUCTIONAL_CONTAINER, "DRAW_INSTRUCTIONAL_BUTTONS");
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(VAR_INSTRUCTIONAL_CONTAINER, "SET_BACKGROUND_COLOUR");
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(0);
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(0);
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(0);
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(80);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}

void Menu::drawInstructions() {
	InstructionsInit();
	std::string SCN(SOCIALCLUB::_SC_GET_NICKNAME());
	std::string IWN = "Current User: " + SCN;
	InstructionsAdd((char*)IWN.c_str(), 53);
	//InstructionsAdd("Open", 177);
	if (Menu::Settings::menuLevel > 0)
	{
		if (Menu::Settings::currentMenu == mainmenu)
		{
			InstructionsAdd("/ Backspace", 53);
			InstructionsAdd("/", 136);
			InstructionsAdd("Close", 177);
		}
		else
		{
			InstructionsAdd("/ Backspace", 53);
			InstructionsAdd("Back", 136);
		}
	}
	else
	{
		InstructionsAdd("Open", 177);
	}
	InstructionsEnd();
}

