#pragma once

#define	ANGLE2SHORT(x)	(((int)((x) * 65536.0f / 360.0f)) & 65535)
#define	SHORT2ANGLE(x)	((x) * (360.0/65536.0f))

void AimAssist_ApplyLockOn(LocalClientNum_t localClientNum);
void AimAssist_ApplySilent(LocalClientNum_t localClientNum, usercmd_s* old_cmd);
void AimAssist_ShouldAutoShoot(LocalClientNum_t localClientNum, usercmd_s* cmd, usercmd_s* old_cmd);