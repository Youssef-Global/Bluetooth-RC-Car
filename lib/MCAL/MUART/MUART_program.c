/*
 * MUART_program.c
 *
 *  Created on: Sep 15, 2022
 *      Author: Global
 */

#include "MUART_private.h"
#include "MUART_interface.h"	

void UART_init(const UART_ConfigType* Config_Ptr)
{
	unsigned short ubrr_value = 0;

	/* U2X = 1 for double transmission speed */
	UCSRA = (1<<U2X);

	UCSRB = (1<<RXEN) | (1<<TXEN);
	
	SET_BIT(UCSRA,URSEL);
	UCSRC = (UCSRC & 0xCF) | ((Config_Ptr -> en_parity & 0x03) << 4); /* Select the type of parity bit */
	UCSRC = (UCSRC & 0xF7) | ((Config_Ptr -> en_stop   & 0x01) << 3); /* Select number of stop bits */
	UCSRC = (UCSRC & 0xF8) | (Config_Ptr -> en_data    & 0x07);       /* Select number of data bits */
	
	/* Calculate the UBRR register value */
	ubrr_value = (unsigned short)(((1000000UL / (Config_Ptr -> baudRate * 8UL))) - 1);

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = ubrr_value>>8;
	UBRRL = ubrr_value;
}

void UART_sendByte(const unsigned char data)
{
	/*
	 * UDRE flag is set when the Tx buffer (UDR) is empty and ready for
	 * transmitting a new byte so wait until this flag is set to one
	 */
	while(!GET_BIT(UCSRA,UDRE)){}

	/*
	 * Put the required data in the UDR register and it also clear the UDRE flag as
	 * the UDR register is not empty now
	 */
	UDR = data;

}

unsigned char UART_recieveByte(void)
{
	/* RXC flag is set when the UART receive data so wait until this flag is set to one */
	while(!GET_BIT(UCSRA,RXC)){}

	/*
	 * Read the received data from the Rx buffer (UDR)
	 * The RXC flag will be cleared after read the data
	 */
    return UDR;		
}
