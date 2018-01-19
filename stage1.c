#include <msp430.h>
#include "utils.h"
#include "chassis.h"
#include "adc.h"
#include "movement.h"
#include "stage1.h"

void stage1()
{
	ut_init(); // Init UTILS
	ch_init(); // Init CHASSIS
	
	delay(1000);
	move(3000, 40);
	stop();
}
