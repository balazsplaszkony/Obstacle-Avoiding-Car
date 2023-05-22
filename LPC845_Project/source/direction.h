/*
 * direction.h
 *
 *  Created on: 2023. márc. 27.
 *      Author: plasz
 */

#ifndef DIRECTION_H_
#define DIRECTION_H_
#include "ultrasonic.h"
#include "optic.h"


typedef enum Direction{
	GOFORWARD,
	GOBACKWARD,
	TURNRIGHT,
	TURNLEFT,
	TURNRIGHTSTATIONARY,
	TURNLEFTSTATIONARY,
	STOPCAR,
	INDEPENDENT,
}Direction;

#include "car.h"


void FindClearRoute();
void FindClearRouteFordward();
void UpdateDirection();
void FindClearRouteNoCollision();
void FindClearRouteCollision();



#endif /* DIRECTION_H_ */
