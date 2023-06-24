/*
 * direction.h
 *
 *  Created on: 2023. márc. 27.
 *      Author: plasz
 */

#ifndef DIRECTION_H_
#define DIRECTION_H_
#include <stdbool.h>

typedef enum Direction{
	GOFORWARD,
	GOBACKWARD,
	TURNRIGHT,
	TURNLEFT,
	TURNRIGHTSTATIONARY,
	TURNLEFTSTATIONARY,
	STOPCAR,
}Direction;
#include "car.h"



void FindClearRoute();
void FindClearRouteFordward();
bool canGoForward();
bool canGoBackward();
void UpdateDirection();
void FindClearRouteNoCollision();



#endif /* DIRECTION_H_ */
