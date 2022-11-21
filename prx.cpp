#include "stdafx.h"

SYS_MODULE_INFO(BO2Plugin, 0, 1, 1);
SYS_MODULE_START(BO2Plugin_entry);
SYS_MODULE_STOP(BO2Plugin_exit);

extern "C" int BO2Plugin_entry(void)
{
	return SYS_PRX_RESIDENT;
}

extern "C" int BO2Plugin_exit(void)
{
	return SYS_PRX_RESIDENT;
}
