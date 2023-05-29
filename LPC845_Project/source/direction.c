#include "direction.h"

/*determines where can the car go based on the sensor data and the bluetooth prompts*/
void UpdateDirection(){

	//if((car.direction == car_prev.direction && (!isObstacleDetected() || !car.obstacle_avoidance) && car.independent == car_prev.independent)&&!first)
		if((car.direction == car_prev.direction && (!isObstacleDetected() || !car.obstacle_avoidance) && car.independent == car_prev.independent)&&!first)
			return;
		if(car.collision != NoCollision && ! first)
			return;
		//PRINTF("dirb: %d", car.direction);

		switch(car.direction)
		{
		case GOFORWARD: if(canGoForward())
							GoForward();
						else{
							StopCar();
							ResetController(); //?
							car.is_obstacle_in_the_way = true;
						}
			 	 	 	break;

		case GOBACKWARD: if(canGoBackward())
						 GoBackward();
						else{
							StopCar();
							ResetController(); //?
							car.is_obstacle_in_the_way = true;
						}
						break;

		case TURNRIGHT: if(canGoForward())
							TurnRight();
						else{
							StopCar();
							ResetController(); //?
							car.is_obstacle_in_the_way = true;
							}
	 					break;
		case TURNLEFT: if(canGoForward())
							TurnLeft();
						else{
							StopCar();
							ResetController(); //?
							car.is_obstacle_in_the_way = true;
						}
						break;
		case STOPCAR: StopCar();break;


		default: break;
		}
		if(first)
			first = false;
		//PRINTF("dira: %d\n", car.direction);

}
bool canGoForward(){

	if(car.is_obstacle_in_the_way == false)
	return (ultrasonic_measurement.distance_in_cm > GetUltrasonicTreshold()
			&& optic_measurement.front_left < OpticTreshold && optic_measurement.front_right < OpticTreshold);
	else
		return (ultrasonic_measurement.distance_in_cm > GetUltrasonicTreshold()
					&& optic_measurement.front_left < (OpticTreshold - OpticTresholdHysteresis)
					&& optic_measurement.front_right < (OpticTreshold - OpticTresholdHysteresis));
}
bool canGoBackward(){
	if(car.is_obstacle_in_the_way == false)
		return ( optic_measurement.back_left < OpticTreshold && optic_measurement.back_right < OpticTreshold);

	else
	return ( optic_measurement.back_left < (OpticTreshold - OpticTresholdHysteresis)
			&& optic_measurement.back_right < (OpticTreshold - OpticTresholdHysteresis));

}

void FindClearRouteFordward()
{
	static bool state = false;
	if(state == false)
	{
		if(car.direction == GOFORWARD)
		{

			if(optic_measurement.front_right> optic_measurement.front_left)
			{
				//car.direction = TURNRIGHTSTATIONARY;
				TurnRightStationary();
			}
			else
			{
				//car.direction = TURNLEFTSTATIONARY;
				TurnLeftStationary();
			}
		}
		if(car.direction == TURNLEFT)
			TurnRightStationary();

		if(car.direction == TURNRIGHT)
			TurnLeftStationary();

		pid_right.setpoint = CalculateRPMfromSpeed(15);
		pid_left.setpoint = CalculateRPMfromSpeed(15);
		state = true;
		return;
	}
	if(state == true)
	{
		if(canGoForward())
			//ultrasonic_measurement.is_valid)
			{
				car.direction = GOFORWARD;
				pid_right.setpoint = CalculateRPMfromSpeed(car.speed);
				pid_left.setpoint = CalculateRPMfromSpeed(car.speed);
				ResetController(); //?
				GoForward();
				car.is_obstacle_in_the_way = false;
				//car.collision = NoCollision;
				state = false;
			}
	}
}
void FindClearRouteBackward()
{
	if(canGoForward())
		{
			ResetController();
			car.direction = GOFORWARD;
			GoForward();
			car.is_obstacle_in_the_way = false;
		}
}
void FindClearRoute(){
//	if(car.independent)
//	{
//		FindClearRouteFordward();
//		return;
//	}

	if(isRoadBlockedinEveryDirection())
	{
		car.is_car_blocked = true;
		//car.direction = STOPCAR;
		StopCar();
		return;
	}
	if(car.collision == NoCollision)
		FindClearRouteNoCollision();

	return;
}

void FindClearRouteNoCollision()
{

	if(car.direction == GOFORWARD || car.direction == TURNRIGHT || car.direction == TURNLEFT)
		FindClearRouteFordward();

	else if(car.direction == GOBACKWARD)
		FindClearRouteBackward();
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

