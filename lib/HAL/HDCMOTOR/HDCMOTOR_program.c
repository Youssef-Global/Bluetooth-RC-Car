/*
 * HDCMOTOR_program.c
 *
 *  Created on: May 11, 2023
 *      Author: Global
 */


#include "../../LIB/LIB_STD_TYPES.h"
#include "../../MCAL/MDIO/MDIO_interface.h"
#include "HDCMOTOR_interface.h"
#include "HDCMOTOR_config.h"


void HDCMOTOR_voidInit(){
	MDIO_voidSetPinDirection(MOTOR_PORT,FLp,MDIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection(MOTOR_PORT,FLn,MDIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection(MOTOR_PORT,FRp,MDIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection(MOTOR_PORT,FRn,MDIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection(MOTOR_PORT,BLp,MDIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection(MOTOR_PORT,BLn,MDIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection(MOTOR_PORT,BRp,MDIO_PIN_OUTPUT);
	MDIO_voidSetPinDirection(MOTOR_PORT,BRn,MDIO_PIN_OUTPUT);
}

void HDCMOTOR_voidStop(u8 Copy_u8MotorPostive, u8 Copy_u8MotorNegative){
	MDIO_voidSetPinValue(MOTOR_PORT,Copy_u8MotorPostive,MDIO_PIN_LOW);
	MDIO_voidSetPinValue(MOTOR_PORT,Copy_u8MotorNegative,MDIO_PIN_LOW);
}
void HDCMOTOR_voidClk(u8 Copy_u8MotorPostive, u8 Copy_u8MotorNegative){
	MDIO_voidSetPinValue(MOTOR_PORT,Copy_u8MotorPostive,MDIO_PIN_HIGH);
	MDIO_voidSetPinValue(MOTOR_PORT,Copy_u8MotorNegative,MDIO_PIN_LOW);
}
void HDCMOTOR_voidUClk(u8 Copy_u8MotorPostive, u8 Copy_u8MotorNegative){
	MDIO_voidSetPinValue(MOTOR_PORT,Copy_u8MotorPostive,MDIO_PIN_LOW);
	MDIO_voidSetPinValue(MOTOR_PORT,Copy_u8MotorNegative,MDIO_PIN_HIGH);
}

void HDCMOTOR_voidNatural(){
	HDCMOTOR_voidClk(FLp, FLn);
	HDCMOTOR_voidClk(BLp, BLn);
	HDCMOTOR_voidClk(FRp, FRn);
	HDCMOTOR_voidClk(BRp, BRn);
}

void HDCMOTOR_voidReverse(){
	HDCMOTOR_voidUClk(FLp, FLn);
	HDCMOTOR_voidUClk(BLp, BLn);
	HDCMOTOR_voidUClk(FRp, FRn);
	HDCMOTOR_voidUClk(BRp, BRn);
}

void HDCMOTOR_voidTurnLeft(){
	HDCMOTOR_voidUClk(FLp, FLn);
	HDCMOTOR_voidUClk(BLp, BLn);
	HDCMOTOR_voidClk(FRp, FRn);
	HDCMOTOR_voidClk(BRp, BRn);
}


void HDCMOTOR_voidTurnRight(){
	HDCMOTOR_voidClk(FLp, FLn);
	HDCMOTOR_voidClk(BLp, BLn);
	HDCMOTOR_voidUClk(FRp, FRn);
	HDCMOTOR_voidUClk(BRp, BRn);
}

void HDCMOTOR_voidBrake(){
	HDCMOTOR_voidStop(FLp, FLn);
	HDCMOTOR_voidStop(BLp, BLn);
	HDCMOTOR_voidStop(FRp, FRn);
	HDCMOTOR_voidStop(BRp, BRn);
}
