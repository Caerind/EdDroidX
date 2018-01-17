/*
 * movement.h
 *
 *  Created on: 13 janv. 2018
 *      Author: Cmdu76
 */

#ifndef MOVEMENT_H_
#define MOVEMENT_H_

void move(unsigned int ms, unsigned int speed);
void right(unsigned int robotId);
void left(unsigned int robotId);
void delay(unsigned int ms);
void stop();

#endif /* MOVEMENT_H_ */
