#include <msp430.h>
#include "utils.h"
#include "chassis.h"
#include "adc.h"
#include "sensorInfrared.h"
#include "movement.h"
#include "homologation.h"

void homologation()
{
	float time = 0.0f;
	int distance = 0;
	int step = 0;
	
	ut_init(); // Init UTILS
	ch_init(); // Init CHASSIS
	adc_init();// Init ADC
	ir_init(4); // Init IR : Pin 4

	ut_delay(500); 
	time += 0.6f;

	while (time < 20.0f)
	{
		if (step == 0)
		{
			if (ir_detect(4) == 0) // Pin 4
			{
				move(72, 80);
				distance++;
			}
			else
			{
				move(72, 80);
				distance++;
				//ut_delay(72);
			}
			time += 0.072f;
			
			if (distance >= 50)
			{
				right(25, 560);
				time += 0.56f;
				distance = 0;
				step++;
				ut_led1(0);
				ut_led2(1);
			}
		}
		else if (step == 1)
		{
			if (ir_detect(4) == 0) // Pin 4
			{
				move(72, 80);
				distance++;
			}
			else
			{
				move(72, 80);
				distance++;
				//ut_delay(72);
			}
			time += 0.072f;
			
			if (distance >= 40)
			{
				left(25, 560);
				time += 0.56f;
				distance = 0;
				step++;
				ut_led1(1);
				ut_led2(0);
			}
		}
		else if (step == 2)
		{
			if (ir_detect(4) == 0) // Pin 4
			{
				move(72, 80);
				distance++;
			}
			else
			{
				move(72, 80);
				distance++;
				//ut_delay(72);
			}
			time += 0.072f;
			
			if (distance >= 100)
			{
				ch_stop();
				ut_led1(1);
				ut_led2(1);
				step++; // Stay in while loop, but do nothing until the end of the 20s
			}
		}
	}
	
	ut_end();
}
