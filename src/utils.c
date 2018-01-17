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
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer to prevent time out reset
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
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

