#include "direction.h"

/*determines where can the car go based on the sensor data and the bluetooth prompts*/
void UpdateDirection(){

		if(car.direction == car_prev.direction && (!isObstacleDetected() || !car.obstacle_avoidance))
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
		default: break;
		}

}
void FindClearRoute(){

	// Amikor előrefelé akad el és a szervot használnám,
	// az a rész még nem teljesen jó, csak egy vázlat
	// Meg kell mérni mennyi ideig tart a szervonak körbe nézni
	//,és aszerint átírni, illetve ez most még blokkoló
	// Először jobbra néz aztán balra, és amelyik irányba messzebb vann akadály
	// az UH mérés szerint, arra megy tovább
	//ez is tul hosszú függvény, még refaktorálom

	if(isRoadBlockedinEveryDirection())
	{
		car.is_car_blocked = true;
		car.direction = STOPCAR;
		StopCar();
	}
	if(car.direction == GOFORWARD){
//			LookToTheRight();
//			while(!servo_turn_finished);
//			servo_turn_finished = false;
//			uint32_t distance_to_right = ultrasonic_measurement.distance_in_cm;
//
//			LookToTheLeft();
//			while(!servo_turn_finished);
//			servo_turn_finished = false;
//			uint32_t distance_to_left = ultrasonic_measurement.distance_in_cm;
//
//			LookStraight();
//
//			if(distance_to_right > distance_to_left)
//			{
//				car.direction = TURNRIGHT;
//				TurnRight();
//			}
//			else
//			{
//				car.direction = TURNLEFT;
//				TurnLeft();
//			}
//			car.is_obstacle_in_the_way = false;
		TurnRightStationary();
		if(ultrasonic_measurement.distance_in_cm > UltrasonicTreshold &&
		   ultrasonic_measurement.is_valid)
		{
//			SCTIMER_UpdatePwmDutycycle(SCT0, 0U, 50, SCT0_pwmEvent[0]);
//			SCTIMER_UpdatePwmDutycycle(SCT0, 1U, 50, SCT0_pwmEvent[0]);
			car.direction = GOFORWARD;
			GoForward();
			car.is_obstacle_in_the_way = false;
		}
		return;
	}
	if(car.direction == TURNRIGHT ||car.direction == TURNLEFT){
		if((ultrasonic_measurement.distance_in_cm > UltrasonicTreshold
			&& ultrasonic_measurement.is_valid))
		{
			car.direction = GOFORWARD;
			GoForward();
		}
		else if((optic_measurement.back_left < OpticTreshold &&
	  	  	  	optic_measurement.back_right < OpticTreshold))
		{
			car.direction = GOBACKWARD;
			GoBackward();
		}
	if(car.direction == GOBACKWARD)
	{
		if((ultrasonic_measurement.distance_in_cm > UltrasonicTreshold
			&& ultrasonic_measurement.is_valid))
		{
			car.direction = GOFORWARD;
			GoForward();
		}
	}
	}
}
