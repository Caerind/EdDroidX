/*
 * chassis.c
 *
 *  Created on: 13 janv. 2018
 *      Author: Cmdu76
 */

#include <msp430.h>
#include "utils.h"
#include "chassis.h"

void ch_init()
{
    // init PWM
    TA1CTL = TASSEL_2 | MC_0 | ID_1;
    TA1CCTL1 |= OUTMOD_7;
    TA1CCTL2 |= OUTMOD_7;
    TA1CCR0 = 100;

    ch_stop();

    // init Engine Left
    ut_initOutput(2, BIT2);
    P2SEL |= BIT2;
    P2SEL2 &= ~(BIT2);
    ut_initOutput(2, BIT1);
    P2OUT &= ~(BIT1);

    // init Engine Right
    ut_initOutput(2, BIT4);
    P2SEL |= BIT4;
    P2SEL2 &= ~(BIT4);
    ut_initOutput(2, BIT5);
    P2OUT &= ~(BIT5);
}

void ch_move(int speed)
{
    P2OUT &= ~(BIT1); // Forward Engine Left
    P2OUT |= (BIT5); // Forward Engine Right
    TA1CCR1 = speed; // Speed Engine Left
    TA1CCR2 = speed; // Speed Engine Right
    TA1CTL |= MC_1;
}

void ch_rotate(int angle)
{
    volatile float avgSpeed = (TA1CCR1 + TA1CCR2) / 128.f;

    if (angle >= -127 && angle <= -63)
    {
        P2OUT |= BIT1; // Backward Engine Left
        P2OUT |= BIT5; // Forward Engine Right
        TA1CCR1 = (int)(avgSpeed * (-63 - angle));
        TA1CCR2 = (int)(avgSpeed * (190 + angle));
    }
    else if (angle > -63 && angle < 63)
    {
        P2OUT &= ~(BIT1); // Forward Engine Left
        P2OUT |= BIT5; // Forward Engine Right
        TA1CCR1 = (int)(avgSpeed * (64 + angle));
        TA1CCR2 = (int)(avgSpeed * (64 - angle));
    }
    else if (angle >= 63 && angle <= 127)
    {
        P2OUT &= ~(BIT1); // Forward Engine Left
        P2OUT &= ~(BIT5); // Backward Engine Right
        TA1CCR1 = (int)(avgSpeed * (190 - angle));
        TA1CCR2 = (int)(avgSpeed * (angle - 64));
    }
}

void ch_rotateRight()
{
    ch_rotate(-127);
}

void ch_rotateLeft()
{
    ch_rotate(127);
}

void ch_stop()
{
    TA1CCR1 = 0;
    TA1CCR2 = 0;
}
