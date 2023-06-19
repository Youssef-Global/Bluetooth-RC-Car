/* MGIE_Program.c */


#include "../../LIB/LIB_STD_TYPES.h"
#include "../../LIB/LIB_BIT_MATH.h"
#include "MGIE_config.h"
#include "MGIE_interface.h"

void MGIE_voidGlobalEnable(void)
{
	SET_BIT(SREG,SREG_EXT_EN);

}

void MGIE_voidGlobalDisable(void)
{
	CLR_BIT(SREG,SREG_EXT_EN);

}
