/*
 * collision.c
 *
 *  Created on: 2023. máj. 14.
 *      Author: plasz
 */
#include "collision.h"


CollisionType DetectCollision(){

	if(car.independent)
	{
		car.collision = NoCollision;
		return car.collision;
	}

	bool changed_and_not_first = hasCarParametersChanged();
	if(first)
		changed_and_not_first = true;

	if(!changed_and_not_first && car.direction == GOFORWARD &&
			isRPMDrop(Encoder_left) && isRPMDrop(Encoder_right))
		car.collision = FrontalCollision;

	else if(!changed_and_not_first &&  car.direction == GOBACKWARD &&
			isRPMDrop(Encoder_left) && isRPMDrop(Encoder_right))
		car.collision = RearCollision;

	else if( !changed_and_not_first && car.direction == TURNRIGHTSTATIONARY &&
			(isRPMDrop(Encoder_left) || isRPMDrop(Encoder_right)))
			car.collision = RightCollision;

	else if(!changed_and_not_first && car.direction == TURNRIGHT &&
			(isRPMDrop(Encoder_left) || isRPMDrop(Encoder_right)))
			car.collision = RightCollision;

	else if(!changed_and_not_first && car.direction == TURNLEFT &&
			(isRPMDrop(Encoder_left) || isRPMDrop(Encoder_right)))
			car.collision = LeftCollision;

	else if(!changed_and_not_first && car.direction == TURNLEFTSTATIONARY &&
			(isRPMDrop(Encoder_left) || isRPMDrop(Encoder_right)))
			car.collision = LeftCollision;

	return car.collision;
}
bool hasCarParametersChanged(){
	return (!((car.direction == car_prev.direction && !first) && ((car.tempomat && car.speed == car_prev.speed) )));
}

bool isRPMDrop(Encoder encoder)
{
	//return ((abs(encoder.RPM -encoder.RPM_prev)/encoder.RPM_prev) > 0.5);
}
