/*
 * movement.c
 *
 *  Created on: 13 janv. 2018
 *      Author: Cmdu76
 */

#include <msp430.h>
#include "utils.h"
#include "chassis.h"
#include "movement.h"

void move(unsigned int time, unsigned speed)
{
	ch_move(speed);
	ut_delay(time);
	ch_stop();
}

void right(unsigned int robotId)
{
	ch_move(25);
	ch_rotateRight();
	if (robot == 1)
	{
		ut_delay(264);
	}
	else
	{
		ut_delay(560);
	}
	ch_stop();
}

void left()
{
	ch_move(25);
	ch_rotateLeft();
	if (robot == 1)
	{
		ut_delay(264);
	}
	else
	{
		ut_delay(560);
	}
	ch_stop();
}

void delay(unsigned int ms)
{
	ut_delay(ms);
}

void stop()
{
	ch_stop();
}
