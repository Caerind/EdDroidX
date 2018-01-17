/*
 * utils.h
 *
 *  Created on: 13 janv. 2018
 *      Author: Cmdu76
 */

#ifndef UTILS_H_
#define UTILS_H_

void ut_init();

void ut_initInput(int port, int input);
void ut_initOutput(int port, int output);

void ut_delay(unsigned int ms);

void ut_led1(unsigned int on);
void ut_led2(unsigned int on);

void ut_end();

#endif /* UTILS_H_ */
