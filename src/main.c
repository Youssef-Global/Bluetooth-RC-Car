/*
 * main.c
 *
 *  Created on: May 4, 2023
 *      Author: Global
 */

#define F_CPU 8000000L

#define Natural     'F'
#define Reverse     'B'
#define TurnLeft    'L'
#define TurnRight   'R'
#define Brake       'S'

#include "../lib/LIB/LIB_STD_TYPES.h"
#include "../lib/LIB/LIB_BIT_MATH.h"

#include "../lib/MCAL/MDIO/MDIO_interface.h"
#include "../lib/MCAL/MGIE/MGIE_interface.h"
#include "../lib/MCAL/MUART/MUART_interface.h"
#include "../lib/HAL/HDCMOTOR/HDCMOTOR_interface.h"

volatile u8 button = Natural;

int main ()
{

	MDIO_voidInit();
	MGIE_voidGlobalEnable();
	HDCMOTOR_voidInit();
	MUART_voidInit();

	while (1)
	{
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
		button= MUART_u8ReceiveChar();
	}
}