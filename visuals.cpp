#include "stdafx.h"

void CG_DrawFriendlyBox(int client, vec4_t color)
{
	if (!CG_IsEntityFriendlyNotEnemy(cgGlob->localIndex, &centity[client]))
		return;

	Material* white_material = Material_RegisterHandle("white", 7, true, -1);
	vec3_t feet_origin = centity[client].origin;
	vec3_t head_origin;
	AimTarget_GetTagPos(&centity[client], SL_GetString("j_head", 0), &head_origin);
	feet_origin.z -= 5;
	head_origin.z += 10;
	vec2_t feet_location, head_location;
	WorldPosToScreenPos(cgGlob->localIndex, &head_origin, &head_location);
	WorldPosToScreenPos(cgGlob->localIndex, &feet_origin, &feet_location);

	float width;
	float height = feet_location[1] - head_location[1];
	if (centity[client].flags & 0x8)
		width = height / 0.9f;
	else
		width = height / 1.95;

	R_AddCmdDrawStretchPicInternal(feet_location[0] - width / 2, feet_location[1] - height, width / 4, 1, 0, 0, 1, 1, color, white_material);
	R_AddCmdDrawStretchPicInternal(feet_location[0] - width / 2, feet_location[1], width / 4, 1, 0, 0, 1, 1, color, white_material);
	R_AddCmdDrawStretchPicInternal(feet_location[0] - width / 2, feet_location[1] - height, 1, width / 4, 0, 0, 1, 1, color, white_material);
	R_AddCmdDrawStretchPicInternal(feet_location[0] + width / 2, feet_location[1] - height, 1, width / 4, 0, 0, 1, 1, color, white_material);

	R_AddCmdDrawStretchPicInternal(feet_location[0] + width / 2 - width / 4, feet_location[1] - height, width / 4, 1, 0, 0, 1, 1, color, white_material);
	R_AddCmdDrawStretchPicInternal(feet_location[0] + width / 2 - width / 4, feet_location[1], width / 4 + 1, 1, 0, 0, 1, 1, color, white_material);
	R_AddCmdDrawStretchPicInternal(feet_location[0] - width / 2, feet_location[1] - width / 4, 1, width / 4, 0, 0, 1, 1, color, white_material);
	R_AddCmdDrawStretchPicInternal(feet_location[0] + width / 2, feet_location[1] - width / 4, 1, width / 4, 0, 0, 1, 1, color, white_material);
}

void CG_DrawVisuals(LocalClientNum_t localClientNum)
{
	for(int i = 0; i < 12; i++)
	{
		if (i == localClientNum || !(centity[i].alive & 64)) continue;

		CG_DrawFriendlyBox(i, vec4_t(0, 1, 1, 1));
	}
}
