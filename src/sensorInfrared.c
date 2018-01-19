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

///////////////////////////////////////////////////////////////
// Initialise un capteur IR sur un port donné                //
///////////////////////////////////////////////////////////////
void ir_init(unsigned int pin)
{
	unsigned int bit = ut_pinToBit(pin);
    P1SEL &= ~(bit);
    P1SEL2 &= ~(bit);
    P1DIR &= ~(bit);
    ADC10AE0 |= (bit);
}

///////////////////////////////////////////////////////////////
// Le capteur donné capte-t-il un obstacle ?                 //
///////////////////////////////////////////////////////////////
int ir_detect(unsigned int pin)
{
    int irValue = adc_get(pin);
    return (irValue >= 158) ? 1 : 0;
}

///////////////////////////////////////////////////////////////
// Le capteur donné capte-t-il un obstacle ? (Seuil en param)//
///////////////////////////////////////////////////////////////
int ir_detectThreshold(unsigned int pin, unsigned int threshold)
{
	int irValue = adc_get(pin);
	return (irValue >= threshold) ? 1 : 0;
}