#pragma once

#pragma region enums
enum LocalClientNum_t
{
	INVALID_LOCAL_CLIENT = 0xFFFFFFFF,
	LOCAL_CLIENT_FIRST = 0x0,
	LOCAL_CLIENT_0 = 0x0,
	ONLY_LOCAL_CLIENT = 0x0,
	LOCAL_CLIENT_COUNT = 0x1,
};

#pragma endregion

#pragma region Material/Font_s
struct MaterialInfo
{
	const char* name;
};

struct Material
{
	MaterialInfo info;
};

struct Glyph
{
	uint16_t letter;
	char x0;
	char y0;
	char dx;
	char pixelWidth;
	char pixelHeight;
	float s0;
	float t0;
	float s1;
	float t1;
};

struct Font_s
{
	const char* fontName;
	int pixelHeight;
	int glyphCount;
	Material* material;
	Material* glowMaterial;
	Glyph* glyphs;
};
#pragma endregion

#pragma region UiContext
struct UiContext {
	int x;
	int y;
	int frameTime;
	int realTime;
	char padding[0xC];
	int width;
	int height;
	float aspect;
	float fps;
};

extern UiContext* cgDc;
#pragma endregion

#pragma region cg_t
typedef struct
{
	int x;						// 0x0
	int y;						// 0x4
	int width;					// 0x8
	int height;					// 0xC
	char padding000[0x14];		// 0x10
	float fovx;					// 0x24
	float fovy;					// 0x28
	float fovz;					// 0x2C
	char padding001[0x4];		// 0x30
	float fov;					// 0x34
	vec3_t viewOrigin;			// 0x38
	char padding002[0x4];		// 0x44
	vec3_t axis[3];				// 0x48
	// 0x6C
} RefDef;

typedef struct
{
	char padding000[0x2B4];		// 0x0
	int identifierThing;		// 0x2B4
	// 0x2B8
} WeaponInfoThing;

typedef struct
{
	char padding000[0xC];		// 0x0
	char name[0x20];			// 0xC
	int team;					// 0x2C
	char padding001[0x7D8];		// 0x30
	// 0x808
} ClientInfor;


typedef struct
{
	LocalClientNum_t localIndex;					// 0x0
	char padding000[0x244];			// 0x4
	int weaponData;					// 0x248
	char padding001[0x24];			// 0x24C
	float zoomAmount;				// 0x270
	char padding002[0x4832C];		// 0x274
	float refdefViewAngles[3];		// 0x485A0
	char padding003[0x2810];		// 0x485AC
	WeaponInfoThing weaponThing;	// 0x4ADBC
	char padding004[0x2B1C];		// 0x4B074
	RefDef refdef;					// 0x4DB90
	char padding005[0x1C1A4];		// 0x4DBFC
	ClientInfor clientInfosZ[16];	// 0x69DA0
	char padding006[0xF070];		// 0x71E20
	float spreadMult;				// 0x80E90
} cg_t;

extern cg_t* cgGlob;
#pragma endregion

#pragma region clientActive
typedef struct
{
	int time;		// 0x00-0x04
	int buttons;		// 0x04-0x08
	int Buf8;			// 0x08-0x0C
	int viewAngles[3];		// 0x0C-0x18
	int weapon;			// 0x18-0x1C
	int offHandIndex;	// 0x1C-0x20
	int Buf20;			// 0x20-0x24
	char forwardmove;	// 0x24-0x25
	char sidemove;		// 0x25-0x26
	char Buf[0x16];		// 0x26-0x3C
} usercmd_s;

typedef struct
{
	char padding00[0x44];
	bool usingAds;
	char padding01[0xC3];
	vec3_t delta_angles;
	char padding02[0x2B80];
	vec3_t viewangles;
	char padding03[0x40010];
	usercmd_s cmds[128];
	int cmdNumber;
} Client;

extern Client* clientActive;
#pragma endregion

#pragma region ScreenPlacement
struct ScreenPlacement
{
	vec2_t scaleVirtualToReal;
	vec2_t scaleVirtualToFull;
	vec2_t scaleRealToVirtual;
	vec2_t virtualViewableMin;
	vec2_t virtualViewableMax;
	vec2_t virtualTweakableMin;
	vec2_t virtualTweakableMax;
	vec2_t realViewportBase;
	vec2_t realViewportSize;
	vec2_t realViewportMid;
	vec2_t realViewableMin;
	vec2_t realViewableMax;
	vec2_t realTweakableMin;
	vec2_t realTweakableMax;
	vec2_t subScreen;
	float hudSplitscreenScale;
};

extern ScreenPlacement* scrPlaceView;
#pragma endregion

#pragma region centity
struct centity_t {
	char padding[3];
	char type;
	char padding2[40];
	vec3_t origin;
	vec3_t angles;
	char padding3[268];
	int isAlive2;
	int flags;
	char padding4[84];
	int teamDog;
	int weaponId;
	int secondaryWeaponId;
	char padding5[0x18];
	int handle;
	char padding6[0x74];
	short teamRCXD_Dog_Heli;
	short teamTurret;
	char padding7[92];
	short eType;
	char padding8[13];
	char weaponNum;
	char padding9[0xB];
	char clientNum;
	char padding10[168];
	char alive;
	char padding12[4];
};
extern centity_t* centity;
#pragma endregion