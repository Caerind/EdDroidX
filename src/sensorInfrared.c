/*
 * sensorInfrared.c
 *
 *  Created on: 13 janv. 2018
 *      Author: Cmdu76
 */

#include <msp430.h>
#include "utils.h"
#include "adc.h"
#include "sensorInfrared.h"

void ir_init()
{
    P1SEL &= ~(BIT5);
    P1SEL2 &= ~(BIT5);
    P1DIR &= ~(BIT5);
    ADC10AE0 |= (BIT5);
}

int ir_detect()
{
    const int irThreshold = 130;
    int irValue;
    irValue = adc_get(5);
    return (irValue >= irThreshold) ? 1 : 0;
}

