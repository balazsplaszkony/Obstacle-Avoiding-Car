#include "direction.h"

/*determines where can the car go based on the sensor data and the bluetooth prompts*/
void UpdateDirection(){

		if((car.direction == car_prev.direction && (!isObstacleDetected() || !car.obstacle_avoidance) && car.independent == car_prev.independent)&&!first)
			return;
		if(car.collision != NoCollision && ! first)
			return;

		switch(car.direction)
		{
		case GOFORWARD: if((!car.obstacle_avoidance) || (ultrasonic_measurement.distance_in_cm > UltrasonicTreshold
							 && ultrasonic_measurement.is_valid))
							GoForward();
						else{
							StopCar();
							car.is_obstacle_in_the_way = true;
						}
			 	 	 	break;

		case GOBACKWARD: if((!car.obstacle_avoidance) || (optic_measurement.back_left < OpticTreshold &&
				  	  	  	optic_measurement.back_right < OpticTreshold))
						 GoBackward();
						else{
							StopCar();
							car.is_obstacle_in_the_way = true;
						}
						break;

		case TURNRIGHT: if((!car.obstacle_avoidance) || optic_measurement.front_right < OpticTreshold)
							TurnRight();
						else{
							StopCar();
							car.is_obstacle_in_the_way = true;
						}
						break;
		case TURNLEFT: if((!car.obstacle_avoidance) || optic_measurement.front_left < OpticTreshold)
						    TurnLeft();
					   else{
						   	StopCar();
							car.is_obstacle_in_the_way = true;
					   	   }
					   break;
		case STOPCAR: StopCar();break;
//		case INDEPENDENT: if(ultrasonic_measurement.distance_in_cm > UltrasonicTreshold)
//								GoForward();
//						  else
//						  {
//							  	StopCar();
//								car.is_obstacle_in_the_way = true;
//						  }

		default: break;
		}
		if(first)
			first = false;

}
void FindClearRouteIndependent()
{
	if(car.independent)
	{
		if(optic_measurement.front_right> optic_measurement.front_left)
		{
			car.direction = TURNRIGHTSTATIONARY;
			TurnRightStationary();
		}
		else
		{
			car.direction = TURNLEFTSTATIONARY;
			TurnLeftStationary();
		}
		if(ultrasonic_measurement.distance_in_cm > UltrasonicTreshold &&
		   ultrasonic_measurement.is_valid)
		{
			SCTIMER_UpdatePwmDutycycle(SCT0, 0U, 50, SCT0_pwmEvent[0]);
			SCTIMER_UpdatePwmDutycycle(SCT0, 1U, 50, SCT0_pwmEvent[1]);
			car.direction = GOFORWARD;
			GoForward();
			car.is_obstacle_in_the_way = false;
			car.collision = NoCollision;
		}

	}
}
void FindClearRoute(){
	if(car.independent)
	{	FindClearRouteIndependent();
		return;
	}

	if(isRoadBlockedinEveryDirection())
	{
		car.is_car_blocked = true;
		car.direction = STOPCAR;
		StopCar();
		return;
	}
	if(car.collision == NoCollision)
		FindClearRouteNoCollision();

	else
		FindClearRouteCollision();

	return;
}

void FindClearRouteNoCollision()
{
	if(car.direction == GOFORWARD){
		if(optic_measurement.front_right> optic_measurement.front_left)
		{
			car.direction = TURNRIGHTSTATIONARY;
			TurnRightStationary();
		}
		else
		{
			car.direction = TURNLEFTSTATIONARY;
			TurnLeftStationary();
		}
		if(ultrasonic_measurement.distance_in_cm > UltrasonicTreshold &&
		   ultrasonic_measurement.is_valid)
		{
			SCTIMER_UpdatePwmDutycycle(SCT0, 0U, 50, SCT0_pwmEvent[0]);
			SCTIMER_UpdatePwmDutycycle(SCT0, 1U, 50, SCT0_pwmEvent[1]);
			car.direction = GOFORWARD;
			GoForward();
			car.is_obstacle_in_the_way = false;
		}
		return;
	}
	else if(car.direction == TURNRIGHT ||car.direction == TURNLEFT){
		if((ultrasonic_measurement.distance_in_cm > UltrasonicTreshold
			&& ultrasonic_measurement.is_valid))
		{
			car.direction = GOFORWARD;
			GoForward();
			car.is_obstacle_in_the_way = false;
		}
		else if((optic_measurement.back_left < OpticTreshold &&
	  	  	  	optic_measurement.back_right < OpticTreshold))
		{
			car.direction = GOBACKWARD;
			GoBackward();
			car.is_obstacle_in_the_way = false;
		}
	else if(car.direction == GOBACKWARD)
	{
		if((ultrasonic_measurement.distance_in_cm > UltrasonicTreshold
			&& ultrasonic_measurement.is_valid))
		{
			car.direction = GOFORWARD;
			GoForward();
			car.is_obstacle_in_the_way = false;
		}
	}
	}
}
void FindClearRouteCollision()
{
	switch(car.collision)
	{
	case FrontalCollision: break;


	case RearCollision: break;


	case RightCollision: break;


	case LeftCollision: break;

	default: break;

	}




}

