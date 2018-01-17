/*
 * display.c
 *
 *  Created on: 13 janv. 2018
 *      Author: Cmdu76
 */
 
#include <msp430.h>
#include "display.h"

void dis_send(unsigned char c)
{
	P1OUT &= ~BIT4;
    UCB0TXBUF = c;
    while (!(IFG2 & UCB0TXIFG));
    P1OUT |= BIT4;
}

void dis_init()
{
	IUCB0CTL1 = UCSWRST;
    P1DIR |= BIT4;
    P1OUT |= BIT4;
    P1SEL |= BIT7 + BIT5;
    P1SEL2 |= BIT7 + BIT5;
    UCB0CTL0 |= UCCKPH + UCMSB + UCMST + UCSYNC;
    UCB0CTL1 |= UCSSEL_2;
    UCB0CTL1 &= ~UCSWRST;
	
	dis_clear();
	dis_send('8');
	dis_send('8');
	dis_send('8');
	dis_send('8');
	dis_send(0x77);
	dis_send(0x3F);
	dis_send(0x7A);
	dis_send(255);
	__delay_cycles(1000000);
	dis_clear();
}

void dis_clear()
{
	dis_send(0x76);
	dis_send(0x77);
	dis_send(0x00);
}

void dis_print(int value)
{
	int digit1, digit2, digit3, digit4;
	unsigned char v[4];
	digit4 = (c & (0x000F));
	digit3 = (c & (0x00F0))>>0x04;
	digit2 = (c & (0x0F00))>>0x08;
	digit1 = (c & (0xF000))>>0x0C;
	v[3] = (digit4);
	v[2] = (digit3);
	v[1] = (digit2);
	v[0] = (digit1);
	dis_send(v[3]);
	dis_send(v[2]);
	dis_send(v[1]);
	dis_send(v[0]);
}


