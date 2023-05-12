/*
 * HDCMOTOR_interface.h
 *
 *  Created on: May 11, 2023
 *      Author: Global
 */

#ifndef HAL_HDCMOTOR_HDCMOTOR_INTERFACE_H_
#define HAL_HDCMOTOR_HDCMOTOR_INTERFACE_H_

void HDCMOTOR_voidInit();

void HDCMOTOR_voidStop(u8 Copy_u8MotorPostive, u8 Copy_u8MotorNegative);
void HDCMOTOR_voidClk(u8 Copy_u8MotorPostive, u8 Copy_u8MotorNegative);
void HDCMOTOR_voidUClk(u8 Copy_u8MotorPostive, u8 Copy_u8MotorNegative);

void HDCMOTOR_voidNatural();
void HDCMOTOR_voidReverse();
void HDCMOTOR_voidTurnLeft();
void HDCMOTOR_voidTurnRight();
void HDCMOTOR_voidBrake();

#endif /* HAL_HDCMOTOR_HDCMOTOR_INTERFACE_H_ */
