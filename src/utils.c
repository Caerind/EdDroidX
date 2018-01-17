/*
 * utils.c
 *
 *  Created on: 13 janv. 2018
 *      Author: Cmdu76
 */

#include <msp430.h>
#include "utils.h"

void ut_init()
{
	// Clocks and WatchDog
    WDTCTL = WDTPW | WDTHOLD;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
	
	// LED 1 & 2
	ut_initOutput(1, 0);
	ut_initOutput(1, 6);
	P1OUT &= ~(BIT0 | BIT6);
	
	// Button S2
	P1IE |= (BIT3);
    P1IES |= (BIT3);
    P1IFG &= ~(BIT3);
    __enable_interrupt();
}

void ut_initInput(int port, int input)
{
    if (port == 1)
    {
        P1SEL &= ~(input);
        P1SEL2 &= ~(input);
        P1DIR &= ~(input);
        P1REN |= (input);
        P1OUT |= (input);
    }
    else if (port == 2)
    {
        P2SEL &= ~(input);
        P2SEL2 &= ~(input);
        P2DIR &= ~(input);
        P2REN |= (input);
        P2OUT |= (input);
    }
}

void ut_initOutput(int port, int output)
{
    if (port == 1)
    {
        P1SEL &= ~(output);
        P1SEL2 &= ~(output);
        P1DIR |= (output);
    }
    else if (port == 2)
    {
        P2SEL &= ~(output);
        P2SEL2 &= ~(output);
        P2DIR |= (output);
    }
}

void ut_delay(unsigned int ms)
{
    volatile unsigned int i = ms;
    volatile unsigned int t;
    while (i--)
    {
        t = 100;
        while (t--);
    }
}

void ut_led1(unsigned int on)
{
	if (on == 1)
	{
		P1OUT |= BIT0;
	}
	else
	{
		P1OUT &= ~(BIT0);
	}
}

void ut_led2(unsigned int on)
{
	if (on == 1)
	{
		P1OUT |= BIT6;
	}
	else
	{
		P1OUT &= ~(BIT6);
	}
}
