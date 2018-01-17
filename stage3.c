#include <msp430.h>
}
#include "movement.h"
#include "stage2.h"

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
		rotateRight(2);
		delay(1000);
	}
}
