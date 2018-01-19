/*
 * utils.h
 *
 *  Created on: 13 janv. 2018
 *      Author: Cmdu76
 */

#ifndef UTILS_H_
#define UTILS_H_

///////////////////////////////////////////////////////////////
// Initialise les clocks, les leds et le bouton interruption //
///////////////////////////////////////////////////////////////
void ut_init();

///////////////////////////////////////////////////////////////
// Initialise une entr�e directement                         //
///////////////////////////////////////////////////////////////
void ut_initInput(int port, int input);

///////////////////////////////////////////////////////////////
// Initialise une sortie directement                         //
///////////////////////////////////////////////////////////////
void ut_initOutput(int port, int output);

///////////////////////////////////////////////////////////////
// Attends un certain nombre de millisecondes                //
///////////////////////////////////////////////////////////////
void ut_delay(unsigned int ms);

///////////////////////////////////////////////////////////////
// Allume ou �teint la led 1 (1 = on, 0 = off)               //
///////////////////////////////////////////////////////////////
void ut_led1(unsigned int on);

///////////////////////////////////////////////////////////////
// Allume ou �teint la led 2 (1 = on, 0 = off)               //
///////////////////////////////////////////////////////////////
void ut_led2(unsigned int on);

///////////////////////////////////////////////////////////////
// Arr�te le programme et joue une animation avec les leds   //
///////////////////////////////////////////////////////////////
void ut_end();

///////////////////////////////////////////////////////////////
// Convertit une pin d�sir�e en un BITX pour les registres   //
///////////////////////////////////////////////////////////////
unsigned int ut_pinToBit(unsigned int pin);

#endif /* UTILS_H_ */
