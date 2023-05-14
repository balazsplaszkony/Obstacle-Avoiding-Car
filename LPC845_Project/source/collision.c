/*
 * collision.c
 *
 *  Created on: 2023. máj. 14.
 *      Author: plasz
 */
#include "collision.h"


CollisionType DetectCollision(){
	if( hasCarParametersChanged() && car.direction == GOFORWARD &&
			isRPMDrop(Encoder_left) && isRPMDrop(Encoder_right))
		car.collision = FrontalCollision;

	else if( hasCarParametersChanged() && car.direction == GOBACKWARD &&
			isRPMDrop(Encoder_left) && isRPMDrop(Encoder_right))
		car.collision = RearCollision;

	else if( hasCarParametersChanged() && car.direction == TURNRIGHTSTATIONARY &&
			(isRPMDrop(Encoder_left) || isRPMDrop(Encoder_right)))
			car.collision = RightCollision;

	else if( hasCarParametersChanged() && car.direction == TURNRIGHT &&
			(isRPMDrop(Encoder_left) || isRPMDrop(Encoder_right)))
			car.collision = RightCollision;

	else if( hasCarParametersChanged() && car.direction == TURNLEFT &&
			(isRPMDrop(Encoder_left) || isRPMDrop(Encoder_right)))
			car.collision = LeftCollision;

	else if( hasCarParametersChanged() && car.direction == TURNLEFTSTATIONARY &&
			(isRPMDrop(Encoder_left) || isRPMDrop(Encoder_right)))
			car.collision = LeftCollision;

	return car.collision;
}
bool hasCarParametersChanged(){
	return (!((car.direction == car_prev.direction) && ((car.tempomat && car.speed == car_prev.speed) ||
			(!car.tempomat && car.duty == car_prev.duty))));
}

bool isRPMDrop(Encoder encoder)
{
	return ((abs(encoder.RPM -encoder.RPM_prev)/encoder.RPM_prev) > 0.5);
}
