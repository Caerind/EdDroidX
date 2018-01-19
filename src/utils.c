/*
 * utils.c
 *
 *  Created on: 13 janv. 2018
 *      Author: Cmdu76
 */

#include <msp430.h>
#include "utils.h"

///////////////////////////////////////////////////////////////
// Initialise les clocks, les leds et le bouton interruption //
///////////////////////////////////////////////////////////////
void ut_init()
{
	// Clocks and WatchDog
    WDTCTL = WDTPW | WDTHOLD;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
	
	// LED 1 & 2
    P1DIR |= (BIT0 | BIT6);
	P1OUT &= ~(BIT0 | BIT6);
	
	// Button S2
	P1IE |= (BIT3);
    P1IES |= (BIT3);
    P1IFG &= ~(BIT3);
    __enable_interrupt();
}

///////////////////////////////////////////////////////////////
// Initialise une entrée directement                         //
///////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////
// Initialise une sortie directement                         //
///////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////
// Attends un certain nombre de millisecondes                //
///////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////
// Allume ou éteint la led 1 (1 = on, 0 = off)               //
///////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////
// Allume ou éteint la led 2 (1 = on, 0 = off)               //
///////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////
// Arrête le programme et joue une animation avec les leds   //
///////////////////////////////////////////////////////////////
void ut_end()
{
	TA1CCR1 = 0;
	TA1CCR2 = 0;
	P1OUT |= BIT0;
	P1OUT &= ~BIT6;
	while (1)
	{
		P1OUT ^= BIT0;
		P1OUT ^= BIT6;
		ut_delay(70);
	}
}

///////////////////////////////////////////////////////////////
// Convertit une pin désirée en un BITX pour les registres   //
///////////////////////////////////////////////////////////////
unsigned int ut_pinToBit(unsigned int pin)
{
	if (pin == 0) return BIT0;
	if (pin == 1) return BIT1;
	if (pin == 2) return BIT2;
	if (pin == 3) return BIT3;
	if (pin == 4) return BIT4;
	if (pin == 5) return BIT5;
	if (pin == 6) return BIT6;
	if (pin == 7) return BIT7;
	return pin;
}

///////////////////////////////////////////////////////////////
// Interruption                                              //
///////////////////////////////////////////////////////////////
#pragma vector=PORT1_VECTOR
__interrupt void stopInterrupt(void)
{
	ut_end();
}
