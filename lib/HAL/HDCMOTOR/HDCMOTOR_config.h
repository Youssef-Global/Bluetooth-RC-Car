/*
 * HDCMOTOR_config.h
 *
 *  Created on: May 11, 2023
 *      Author: Global
 */

#ifndef HAL_HDCMOTOR_HDCMOTOR_CONFIG_H_
#define HAL_HDCMOTOR_HDCMOTOR_CONFIG_H_

#define MOTOR_PORT	MDIO_PORTA

#define FLp		MDIO_PIN0
#define FLn		MDIO_PIN1
#define FRp		MDIO_PIN2
#define FRn		MDIO_PIN3
#define BLp		MDIO_PIN4
#define BLn		MDIO_PIN5
#define BRp		MDIO_PIN6
#define BRn		MDIO_PIN7

#define Forward		MDIO_PIN_HIGH
#define Backward	MDIO_PIN_LOW


#endif /* HAL_HDCMOTOR_HDCMOTOR_CONFIG_H_ */
