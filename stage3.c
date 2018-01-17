#include <msp430.h>
#include "utils.h"
#include "chassis.h"
#include "adc.h"
#include "sensorInfrared.h"
#include "movement.h"
#include "stage3.h"

void stage3_init()
{
	ut_init(); // Init UTILS
	ch_init(); // Init CHASSIS
	adc_init(); // Init ADC
	ir_init(); // Init IR
}

void stage3()
{
	stage3_init();
	
	while (1)
	{
		left(2);
		delay(1000);
	}
}
