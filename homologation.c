#include <msp430.h>
#include "utils.h"
#include "chassis.h"
#include "movement.h"
#include "homologation.h"

void homologation_init()
{
	ut_init(); // Init UTILS
	ch_init(); // Init CHASSIS
}

void homologation()
{
	homologation_init();
	
	
}
