/*
 * chassis.h
 *
 *  Created on: 13 janv. 2018
 *      Author: Cmdu76
 */

#ifndef CHASSIS_H_
#define CHASSIS_H_

void ch_init();

void ch_move(int speed);
void ch_moveMax();

void ch_rotate(int angle);
void ch_rotateRight();
void ch_rotateLeft();

void ch_stop();

#endif /* CHASSIS_H_ */
