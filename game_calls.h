#pragma once

static libpsutil::symbol<void(float x, float y, float w, float h, float s0, float t0, float s1, float t1, const float* color, Material* material)>R_AddCmdDrawStretchPicInternal{ 0x076A3E8 };
static libpsutil::symbol<void(const char* text, int maxChars, Font_s* font, float x, float y, float yScale, float xScale, float rotation, const float* color, int style)>R_AddCmdDrawTextInternal{ 0x76A910 };
static libpsutil::symbol<void(ScreenPlacement* scrPlaceview, float x, float y, float width, float height, float angle, const float* color, Material* material)>CG_DrawRotatedPicPhysical{ 0x0456F8 };
static libpsutil::symbol<int(const char* str, unsigned int user)>SL_GetString{ 0x48ED68 };
static libpsutil::symbol<bool(LocalClientNum_t localClientNum, centity_t* targetEnt)>AimTarget_isTargetVisible{ 0x15988 };
static libpsutil::symbol<bool(LocalClientNum_t localClientNum, centity_t* cent)>CG_IsEntityFriendlyNotEnemy{ 0x049720 };
static libpsutil::symbol<Material*(const char* name, int imageTrack, bool errorIfMissing, int waitTime)>Material_RegisterHandle{ 0x763220 };
static libpsutil::symbol<Font_s*(const char* name, int imageTrack)>R_RegisterFont{ 0x75A2C0 };
static libpsutil::symbol<bool(LocalClientNum_t localClientNum, vec3_t* worldPos, vec2_t* outScreenPos)>WorldPosToScreenPos{ 0x05A480 };
static libpsutil::symbol<bool(centity_t* ent, unsigned int tagName, vec3_t* pos)>AimTarget_GetTagPos{ 0x015708 };
static libpsutil::symbol<void(vec3_t* vec, vec3_t* angles)>vectoangles{ 0x3CAB90 };