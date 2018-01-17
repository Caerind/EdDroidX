#include <msp430.h>

#include "utils.h"
#include "chassis.h"
#include "adc.h"
#include "sensorInfrared.h"
#include "sensorLine.h"
#include "movement.h"

void testIR()
{
	ir__init();
	
	ut_initOutput(1, 6);
	ut_initOutput(1, 0);

	while (1)
	{
		if (ir_detect() == 1)
		{
			P1OUT |= BIT6;
			P1OUT &= ~(BIT0);
		}
		else
		{
			P1OUT &= ~(BIT6);
			P1OUT |= BIT0;
		}

		delay(50);
	}
}

void testLINE()
{
	li_init();
	
	ut_initOutput(1, 6);
	ut_initOutput(1, 0);

	while (1)
	{
		if (li_detect() == 1)
		{
			P1OUT |= BIT6;
			P1OUT &= ~(BIT0);
		}
		else
		{
			P1OUT &= ~(BIT6);
			P1OUT |= BIT0;
		}

		delay(50);
	}
}

void main()
{
	ut_init();
	ch_init();
	adc_init();
	
	testIR();
	
	//testLINE();
}
