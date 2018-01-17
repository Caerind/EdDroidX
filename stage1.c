#include <msp430.h>
#include "movement.h"
#include "stage1.h"

void stage1_init()
{
	ut_init(); // Init UTILS
	ch_init(); // Init CHASSIS
	adc_init(); // Init ADC (?)
}

void stage1()
{
	stage1_init();
	
	delay(1000);
	move(3000, 40);
	stop();
}
