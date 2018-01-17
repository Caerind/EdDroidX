#include <msp430.h>
#include "utils.h"
#include "chassis.h"
#include "adc.h"
#include "sensorLine.h"
#include "movement.h"
#include "stage2.h"

void stage2_init()
{
	ut_init(); // Init UTILS
	ch_init(); // Init CHASSIS
	adc_init(); // Init ADC
	li_init(); // Init LINE
}

void stage2()
{
	int i;
	
	stage2_init();
	
	delay(1000);
	for (i = 8; i > 0; i--)
	{
		move(400, 25);
		left(1);
		delay(500);
	}
    stop();
}
