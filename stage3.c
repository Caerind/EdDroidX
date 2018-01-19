#include <msp430.h>
#include "utils.h"
#include "chassis.h"
#include "adc.h"
#include "sensorInfrared.h"
#include "movement.h"
#include "stage3.h"

void stage3()
{
	ut_init(); // Init UTILS
	ch_init(); // Init CHASSIS
	adc_init(); // Init ADC
	ir_init(1); // Init IR
	
	while (1)
	{
		leftRobot(2);
		delay(1000);
	}
}
