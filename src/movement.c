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

void move(unsigned int time, unsigned int speed)
{
	ch_move(speed);
	ut_delay(time);
	ch_stop();
}

void right(unsigned int time, unsigned int speed)
{
	ch_move(speed);
	ch_rotateRight();
	ut_delay(time);
	ch_stop();
}

void rightRobot(unsigned int robotId)
{
	if (robotId == 1) // Fastest robot
	{
		right(25, 264);
	}
	else
	{
		right(25, 560);
	}
}

void left(unsigned int time, unsigned int speed)
{
	ch_move(speed);
	ch_rotateLeft();
	ut_delay(time);
	ch_stop();
}

void leftRobot(unsigned int robotId)
{
	if (robotId == 1) // Fastest robot
	{
		left(25, 264);
	}
	else
	{
		left(25, 560);
	}
}

void delay(unsigned int ms)
{
	ut_delay(ms);
}

void stop()
{
	ch_stop();
}
