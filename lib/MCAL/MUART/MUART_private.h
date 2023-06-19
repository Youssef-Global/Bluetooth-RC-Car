/*
 * MUART_private.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Global
 */

#ifndef MCAL_MUART_MUART_PRIVATE_H_
#define MCAL_MUART_MUART_PRIVATE_H_

#define UDR     (*(volatile u8 *)0x2C)
#define UCSRA   (*(volatile u8 *)0x2B)
#define UCSRB   (*(volatile u8 *)0x2A)
#define UCSRC   (*(volatile u8 *)0x40)
#define UBRRH   (*(volatile u8 *)0x40)
#define UBRRL   (*(volatile u8 *)0x29)


// UCSRB - UART Control and Status Register B
#define RXEN    4
#define TXEN    3
#define RXCIE   7
#define TXCIE   6

// UCSRC - UART Control and Status Register C
#define URSEL   7
#define UCSZ0   2
#define UCSZ1   1

// UCSRA - UART Control and Status Register A
#define UDRE    5
#define RXC     7
#define TXC     8

#endif /* MCAL_MUART_MUART_PRIVATE_H_ */
