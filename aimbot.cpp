#include "stdafx.h"

int AimAssist_GetBestTarget(LocalClientNum_t localClientNum)
{
	int closest = -1;
	float maxDistance = FLT_MAX;

	for (int i = 0; i < 18; i++)
	{
		if(i == localClientNum || !(centity[i].alive & 64)) // self and alive check
			continue;
		if (CG_IsEntityFriendlyNotEnemy(localClientNum, &centity[i]) || !AimTarget_isTargetVisible(LOCAL_CLIENT_0, &centity[i])) // team and visible check
			continue;

		float distance = centity[localClientNum].origin.distance(centity[i].origin); // distance between you and enemy
		if (distance < maxDistance)
		{
			maxDistance = distance;
			closest = i;
		}
	}

	return closest;
}

vec3_t final_angles;
void AimAssist_ApplyLockOn(LocalClientNum_t localClientNum)
{
	int closest = AimAssist_GetBestTarget(localClientNum);

	if (closest == -1) return;

	vec3_t position, view_angles;
	AimTarget_GetTagPos(&centity[closest], SL_GetString("j_head", 0), &position);
	vec3_t angles = position - cgGlob->refdef.viewOrigin;
	vectoangles(&angles, &view_angles);
	final_angles = view_angles - clientActive->delta_angles;

	clientActive->viewangles = final_angles;
}

void AimAssist_ApplySilent(LocalClientNum_t localClientNum, usercmd_s* old_cmd)
{
	int closest = AimAssist_GetBestTarget(localClientNum);

	if (closest == -1) return;

	vec3_t position, view_angles;
	AimTarget_GetTagPos(&centity[closest], SL_GetString("j_head", 0), &position);
	vec3_t angles = position - cgGlob->refdef.viewOrigin;
	vectoangles(&angles, &view_angles);
	final_angles = view_angles -clientActive->delta_angles;

	float old_angle = SHORT2ANGLE(old_cmd->viewAngles[1]);
	old_cmd->viewAngles[0] = ANGLE2SHORT(final_angles[0]);
	old_cmd->viewAngles[1] = ANGLE2SHORT(final_angles[1]);
	correct_movement(old_cmd, SHORT2ANGLE(old_cmd->viewAngles[1]), old_angle, old_cmd->forwardmove, old_cmd->sidemove);
}

void AimAssist_ShouldAutoShoot(LocalClientNum_t localClientNum, usercmd_s* cmd, usercmd_s* old_cmd)
{
	int closest = AimAssist_GetBestTarget(localClientNum);

	if (closest == -1) return;

	cmd->buttons |= 0x80000000;
	cmd->buttons |= (1 << 31);

}
