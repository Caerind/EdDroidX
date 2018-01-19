/*
 * sensorLine.c
 *
 *  Created on: 17 janv. 2018
 *      Author: c.mailly.14
 */

#include <msp430.h>
#include "utils.h"
#include "adc.h"
#include "sensorLine.h"

///////////////////////////////////////////////////////////////
// Initialise un capteur ligne sur un port donné             //
///////////////////////////////////////////////////////////////
void li_init(unsigned int pin)
{
	unsigned int bit = ut_pinToBit(pin);
	P1SEL &= ~(bit);
	P1SEL2 &= ~(bit);
	P1DIR &= ~(bit);
	ADC10AE0 |= (bit);
}

///////////////////////////////////////////////////////////////
// Le capteur donné capte-t-il la ligne ?                    //
///////////////////////////////////////////////////////////////
int li_detect(unsigned int pin)
{
	const int rightThreshold = 800;
	int rightValue;
	rightValue = adc_get(pin);
	return (rightValue >= rightThreshold) ? 1 : 0;
}
