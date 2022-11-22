#include "stdafx.h"

bool cl_ingame()
{
	return *reinterpret_cast<bool*>(0x01cb68d8) == true && (*reinterpret_cast<int*>(0xE22F18) > 0 && *reinterpret_cast<int*>(0xE22F20) && *reinterpret_cast<int*>(0xD689D8) > 0);
}

char ClampChar_r(const int i)
{
	if (i < -128) 
		return -128;
	if (i > 127)
		return 127;
	return i;
}

float DEG2RAD(float DEG)
{
	return DEG * M_PI / 180;
}

void correct_movement(usercmd_s* cmd, float current_angle, float old_angle, float forward, float sidemove)
{
	float deltaView = current_angle - old_angle, f1, f2;

	if (old_angle < 0.f)
		f1 = 360.0f + old_angle;
	else
		f1 = old_angle;

	if (current_angle < 0.0f)
		f2 = 360.0f + current_angle;
	else
		f2 = current_angle;

	if (f2 < f1)
		deltaView = abs(f2 - f1);
	else
		deltaView = 360.0f - abs(f1 - f2);
	deltaView = 360.0f - deltaView;

	cmd->forwardmove = ClampChar_r((int)(cosf(DEG2RAD(deltaView)) * forward + cosf(DEG2RAD(deltaView + 90.f)) * sidemove));
	cmd->sidemove = ClampChar_r((int)(sinf(DEG2RAD(deltaView)) * forward + sinf(DEG2RAD(deltaView + 90.f)) * sidemove));
}