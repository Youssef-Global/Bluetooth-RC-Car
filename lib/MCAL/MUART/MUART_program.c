/*
 * MUART_program.c
 *
 *  Created on: Sep 15, 2022
 *      Author: Global
 */


#include "../../LIB/LIB_STD_TYPES.h"
#include "../../LIB/LIB_BIT_MATH.h"

#include "MUART_private.h"
#include "MUART_interface.h"

void MUART_voidInit(void)
{

	/* Configure Baud Rate
	 * BaudRate -> 9600/8MhZ*/ 	// UBBR = ((F_OSC / (u32)(16 * BAUD_RATE)) - 1)
	UBRRL = 51;

	// Enable RX
	SET_BIT(UCSRB, RXEN);

	/* Enable UART Interrupt receive*/
	SET_BIT(UCSRB, RXCIE);
	
	/*Configure Frame Format
	* 8 data bits, 1 stop bit, No Parity*/
	UCSRC |= (UCSRC << URSEL) | (UCSRC << UCSZ0)| (UCSRC << UCSZ1); //0x86;

	UCSRA = 0x00;
}

void MUART_voidSendChar(u8 Copy_u8Data)
{

	while(0 == GET_BIT(UCSRA,UDRE))
	{
		// Wait until transmission Register Empty
		// UDRE = 1 USART Data Register Empty and ready to be written
	}
	// write data to Data Register
	UDR = Copy_u8Data;
}

u8 MUART_u8ReceiveChar(void)
{
	while(GET_BIT(UCSRA,RXC)==0)
	{
		// Wait until Reception Complete
	}

	return UDR;
}
