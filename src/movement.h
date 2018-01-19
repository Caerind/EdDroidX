/*
 * movement.h
 *
 *  Created on: 13 janv. 2018
 *      Author: Cmdu76
 */

#ifndef MOVEMENT_H_
#define MOVEMENT_H_

///////////////////////////////////////////////////////////////
// Avance avec une vitesse et un temps donn�s                //
///////////////////////////////////////////////////////////////
void move(unsigned int ms, unsigned int speed);

///////////////////////////////////////////////////////////////
// Avance d'une certaine distance en centim�tre              //
///////////////////////////////////////////////////////////////
void moveDistance(unsigned int robotId, unsigned int cm);

///////////////////////////////////////////////////////////////
// Tourne vers la droite avec une vitesse et un temps donn�s //
///////////////////////////////////////////////////////////////
void right(unsigned int ms, unsigned int speed);

///////////////////////////////////////////////////////////////
// 90� vers la droite avec le robot sp�cifi�                 //
///////////////////////////////////////////////////////////////
void rightRobot(unsigned int robotId);

///////////////////////////////////////////////////////////////
// Tourne vers la gauche avec une vitesse et un temps donn�s //
///////////////////////////////////////////////////////////////
void left(unsigned int ms, unsigned int speed);

///////////////////////////////////////////////////////////////
// 90� vers la gauche avec le robot sp�cifi�                 //
///////////////////////////////////////////////////////////////
void leftRobot(unsigned int robotId);

///////////////////////////////////////////////////////////////
// Attends une certain nombre de millisecondes               //
///////////////////////////////////////////////////////////////
void delay(unsigned int ms);

///////////////////////////////////////////////////////////////
// Arr�te les moteurs                                        //
///////////////////////////////////////////////////////////////
void stop();

#endif /* MOVEMENT_H_ */
