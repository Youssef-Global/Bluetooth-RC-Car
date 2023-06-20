/*
 * MUART_program.c
 *
 *  Created on: Sep 15, 2022
 *      Author: Global
 */


#include "../../LIB/LIB_STD_TYPES.h"
#include "../../LIB/LIB_BIT_MATH.h"

#include "MUART_private.h"
//#include "MUART_interface.h"	
#include <avr/io.h>

void MUART_voidInit(void)
{

	UCSRB |= (1 << RXEN);								/* Enable USART transmitter and receiver */
	UCSRC |= (1 << URSEL)| (1 << UCSZ0) | (1 << UCSZ1);	/* Write USCRC for 8 bit data and 1 stop bit */ 
	UBRRL = 51;											/* Load UBRRL with lower 8 bit of prescale value */
	UBRRH = (51>>8);									/* Load UBRRH with upper 8 bit of prescale value */
}

void MUART_voidSendChar(u8 Copy_u8Data)
{
	UDR = Copy_u8Data;								/* Write data to be transmitting in UDR */
	while (!(UCSRA & (1<<UDRE)));					/* Wait until data transmit and buffer get empty */
}

u8 MUART_u8ReceiveChar(void)
{
	while (!(UCSRA & (1 << RXC)));				/* Wait until new data receive */
	return UDR;									/* Get and return received data */ 
}
