/*
 * MUART_interface.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Global
 */

#ifndef MCAL_MUART_MUART_INTERFACE_H_
#define MCAL_MUART_MUART_INTERFACE_H_

void MUART_voidInit(void);

void MUART_voidSendChar(u8 Copy_u8Data);

u8 MUART_u8ReceiveChar(void);

#endif /* MCAL_MUART_MUART_INTERFACE_H_ */
