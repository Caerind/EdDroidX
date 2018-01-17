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

void li_init()
{
	P1SEL &= ~(BIT2);
	P1SEL2 &= ~(BIT2);
	P1DIR &= ~(BIT2);
	ADC10AE0 |= (BIT2);
}

int li_detect()
{
	const int rightThreshold = 800;
	int rightValue;
	rightValue = adc_get(2);
	return (rightValue >= rightThreshold) ? 1 : 0;
}
