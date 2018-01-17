#include <msp430.h>
#include "utils.h"
#include "chassis.h"
#include "sensorInfrared.h"
#include "movement.h"
#include "homologation.h"

void homologation_init()
{
	ut_init(); // Init UTILS
	ch_init(); // Init CHASSIS
	ir_init(); // Init IR
}

#pragma vector=PORT1_VECTOR
__interrupt void stopInterrupt(void)
{
	stop();
	
	ut_end();
}

void homologation_easy()
{
	homologation_init();
	while (1)
	{
		move(500, 40);
		right(2);
		move(400, 40);
		left(2);
		move(1000, 40);
	}
}

int homologation_go(unsigned int ms, unsigned int speed)
{
	if (ir_detect() == 0)
	{
		move(ms, speed);
		return 1;
	}
	else
	{
		ut_delay(ms);
		return 0;
	}
}

void homologation()
{
	float time = 0.0f;
	int distance = 0;
	int step = 0;
	
	homologation_init();
	
	ut_delay(500); 
	time += 600.0f;
	
	while (time < 20.0f)
	{
		if (step == 0)
		{
			if (homologation_go(10, 40))
			{
				distance++;
			}
			time += 0.01f;
			
			if (distance >= 50)
			{
				right(25, 560);
				time += 0.56f;
				distance = 0;
				step++;
			}
		}
		else if (step == 1)
		{
			if (homologation_go(10, 40))
			{
				distance++;
			}
			time += 0.01f;
			
			if (distance >= 40)
			{
				left(25, 560);
				time += 0.56f;
				distance = 0;
				step++;
			}
		}
		else if (step == 2)
		{
			if (homologation_go(10, 40))
			{
				distance++;
			}
			time += 0.01f;
			
			if (distance >= 100)
			{
				ch_stop();
				ut_led1(1);
				step++; // Stay in while loop, but do nothing until the end of the 20s
			}
		}
	}
	
	stop();
	
	ut_end();
}
