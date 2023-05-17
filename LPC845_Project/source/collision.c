/*
 * collision.c
 *
 *  Created on: 2023. máj. 14.
 *      Author: plasz
 */
#include "collision.h"


CollisionType DetectCollision(){
	if(hasCarParametersChanged() == false)
		return car.collision;

	if(car.direction == GOFORWARD &&
			isRPMDrop(Encoder_left) && isRPMDrop(Encoder_right))
		car.collision = FrontalCollision;

	else if( car.direction == GOBACKWARD &&
			isRPMDrop(Encoder_left) && isRPMDrop(Encoder_right))
		car.collision = RearCollision;

	else if( car.direction == TURNRIGHTSTATIONARY &&
			(isRPMDrop(Encoder_left) || isRPMDrop(Encoder_right)))
			car.collision = RightCollision;

	else if( car.direction == TURNRIGHT &&
			(isRPMDrop(Encoder_left) || isRPMDrop(Encoder_right)))
			car.collision = RightCollision;

	else if( car.direction == TURNLEFT &&
			(isRPMDrop(Encoder_left) || isRPMDrop(Encoder_right)))
			car.collision = LeftCollision;

	else if( car.direction == TURNLEFTSTATIONARY &&
			(isRPMDrop(Encoder_left) || isRPMDrop(Encoder_right)))
			car.collision = LeftCollision;

	return car.collision;
}
bool hasCarParametersChanged(){
	return (!((car.direction == car_prev.direction && !first) && ((car.tempomat && car.speed == car_prev.speed) ||
			(!car.tempomat && car.duty == car_prev.duty))));
}

bool isRPMDrop(Encoder encoder)
{
	return ((abs(encoder.RPM -encoder.RPM_prev)/encoder.RPM_prev) > 0.5);
}
