#pragma once

bool cl_ingame();
void correct_movement(usercmd_s* cmd, float current_angle, float old_angle, float forward, float sidemove);