/*
 * main.c
 *
 *  Created on: May 4, 2023
 *      Author: Global
 */

#define F_CPU 8000000L

#define Natural     1
#define Reverse     2
#define TurnLeft    3
#define TurnRight   4
#define Brake       5

#include "../lib/LIB/LIB_STD_TYPES.h"
#include "../lib/LIB/LIB_BIT_MATH.h"

#include "../lib/MCAL/MDIO/MDIO_interface.h"
#include "../lib/MCAL/MUART/MUART_interface.h"
#include "../lib/HAL/HDCMOTOR/HDCMOTOR_interface.h"
#include <util/delay.h>


int main ()
{

	MDIO_voidInit();
	HDCMOTOR_voidInit();
	MUART_voidInit();
	u8 button = Brake;

	while (1)
	{

	button = MUART_u8GetChar();
	
	switch (button)
	{
	case Natural:
		HDCMOTOR_voidNatural();
		break;
	case Reverse:
		HDCMOTOR_voidReverse();
		break;
	case TurnLeft:
		HDCMOTOR_voidTurnLeft();
		break;
	case TurnRight:
		HDCMOTOR_voidTurnRight();
		break;
	case Brake:
		HDCMOTOR_voidBrake();
		break;
	default:
		break;
	}

	}
}

