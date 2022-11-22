#include "stdafx.h"

SYS_MODULE_INFO(BO2Plugin, 0, 1, 1);
SYS_MODULE_START(BO2Plugin_entry);
SYS_MODULE_STOP(BO2Plugin_exit);

/*
 * Credits:
 * gopro_2027 for structures
 *
 */

detour* menu_paintall;
detour* cl_writepacket;

void Menu_PaintAll(LocalClientNum_t localClientNum, int* dc)
{
	cgGlob = *reinterpret_cast<cg_t**>(0xE22F18);
	clientActive = *reinterpret_cast<Client**>(0xD689D8);
	centity = *reinterpret_cast<centity_t**>(0xE22F20);

	//if(cl_ingame())
		//AimAssist_ApplyLockOn(cgGlob->localIndex);

	CG_DrawVisuals(cgGlob->localIndex);

	menu_paintall->invoke<void>(localClientNum, dc);
}

int CL_WritePacket(LocalClientNum_t localClientNum)
{
	cgGlob = *reinterpret_cast<cg_t**>(0xE22F18);
	clientActive = *reinterpret_cast<Client**>(0xD689D8);
	centity = *reinterpret_cast<centity_t**>(0xE22F20);

	if(!cl_ingame())
		return cl_writepacket->invoke<int>(localClientNum);

	usercmd_s* cmd = &clientActive->cmds[clientActive->cmdNumber & 0x7F];
	usercmd_s* old_cmd = &clientActive->cmds[clientActive->cmdNumber - 1 & 0x7F];
	memcpy(old_cmd, cmd, sizeof(usercmd_s));
	old_cmd->time -= 1;

	AimAssist_ApplySilent(localClientNum, old_cmd);
	AimAssist_ShouldAutoShoot(localClientNum, cmd, old_cmd);

	return cl_writepacket->invoke<int>(localClientNum);
}

extern "C"
{
	int BO2Plugin_entry(void)
	{
		menu_paintall = new detour(0x3971A0, Menu_PaintAll);
		cl_writepacket = new detour(0x116524, CL_WritePacket);
		return SYS_PRX_RESIDENT;
	}

	int BO2Plugin_exit(void)
	{
		delete menu_paintall;
		delete cl_writepacket;
		return SYS_PRX_RESIDENT;
	}
}
