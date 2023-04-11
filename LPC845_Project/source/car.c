/*
 * car.c
 *
 *  Created on: 2023. márc. 28.
 *      Author: plasz
 */


#include "car.h"
volatile UsartBuffer bluetooth_prompts;
Car car;
Car car_prev;

void InitComponents()
{
	InitUltrasonicMeasurement(&ultrasonic_measurement);
	InitOpticMeasurement(&optic_measurement);
	InitMotors();
	UsartBufferInit();
}

void InitCar()
{
	car.direction = STOPCAR;
	car.obstacle_avoidance = true;
	car.tempomat = false;
	car.speed = MinimalSpeed;
	car.is_obstacle_in_the_way = false;

	car_prev.direction = STOPCAR;
	car_prev.obstacle_avoidance = true;
	car_prev.tempomat = false;
	car_prev.speed = MinimalSpeed;
	car_prev.is_obstacle_in_the_way = false;

}

void ProcessPrompts()
{

	Car car_new = car;

	for(int i = 0; bluetooth_prompts.received_bytes > 0; i++, bluetooth_prompts.received_bytes--){
	switch(bluetooth_prompts.buff[i])
		{
		case FORWARD: car_new.direction = GOFORWARD; break;

		case BACKWARD: car_new.direction = GOBACKWARD; break;

		case RIGHT:  car_new.direction = TURNRIGHT; break;

		case LEFT:   car_new.direction = TURNLEFT; break;

		case STOP: car_new.direction = STOPCAR; break;

		case TOGGLE_TEMPOMAT: car_new.tempomat = (!car_new.tempomat); break;

		case SLOWDOWN: if(car_new.speed > MinimalSpeed) car_new.speed--; break;

		case SPEEDUP: if(car_new.speed < MaximumSpeed) car_new.speed++; break;

		case TOGGLE_OBSTACLE_AVOIDANCE: car_new.obstacle_avoidance = (!car_new.obstacle_avoidance); break;
		}
}
	car_prev = car;
	car = car_new;


}
void GoForward()
{
	RotateForward(&motor_right); RotateForward(&motor_left);
}
void GoBackward()
{
	RotateBackward(&motor_right); RotateBackward(&motor_left);
}

void TurnRight()
{
	RotateForward(&motor_right); RotateBackward(&motor_left);
}

void TurnLeft()
{
	RotateBackward(&motor_right); RotateForward(&motor_left);
}

void StopCar()
{
	StopMotors(&motor_right); StopMotors(&motor_left);
}

bool isObstacleDetected(){
	return((ultrasonic_measurement.distance_in_cm > UltrasonicTreshold && ultrasonic_measurement.is_valid)
			|| optic_measurement.back_left < OpticTreshold
			|| optic_measurement.back_right < OpticTreshold
			|| optic_measurement.front_left < OpticTreshold
			|| optic_measurement.front_right < OpticTreshold
			);
}
void UpdateDirection(){

		if(car.direction == car_prev.direction && (!isObstacleDetected() || !car.obstacle_avoidance))
			return;
		switch(car.direction)
		{
		case GOFORWARD: if((!car.obstacle_avoidance) || (ultrasonic_measurement.distance_in_cm > UltrasonicTreshold
							 && ultrasonic_measurement.is_valid))
							GoForward();
						else{
							//car.direction = STOPCAR;
							StopCar();
							car.is_obstacle_in_the_way = true;
						}
			 	 	 	break;

		case GOBACKWARD: if((!car.obstacle_avoidance) || (optic_measurement.back_left < OpticTreshold &&
				  	  	  	optic_measurement.back_right < OpticTreshold))
						 GoBackward();
						else{
							//car.direction = STOPCAR;
							StopCar();
							car.is_obstacle_in_the_way = true;
						}
						break;

		case TURNRIGHT: if((!car.obstacle_avoidance) || optic_measurement.front_right < OpticTreshold)
							TurnRight();
						else{
							//car.direction = STOPCAR;
							StopCar();
							car.is_obstacle_in_the_way = true;
						}
						break;
		case TURNLEFT: if((!car.obstacle_avoidance) || optic_measurement.front_left < OpticTreshold)
						    TurnLeft();
					   else{
						   	//car.direction = STOPCAR;
						   	StopCar();
							car.is_obstacle_in_the_way = true;
					   	   }
					   break;
		case STOPCAR: StopCar();break;
		default: break;
		}

}
void FindClearRoute(){

	// Ez az egész még nem jó, ez csak egy vázlat
	// Ez most blokkoló, ez így valszeg nem lesz jó
	// Először jobbra néz aztán balra, és amelyik irányba messzebb vann akadály
	// az UH mérés szerint, arra megy tovább

	if(car.direction == GOFORWARD){
			LookToTheRight();
			while(!servo_turn_finished);
			servo_turn_finished = false;
			uint32_t distance_to_right = ultrasonic_measurement.distance_in_cm;

			LookToTheLeft();
			while(!servo_turn_finished);
			servo_turn_finished = false;
			uint32_t distance_to_left = ultrasonic_measurement.distance_in_cm;

			LookStraight();

			if(distance_to_right > distance_to_left)
			{
				car.direction = TURNRIGHT;
				TurnRight();
			}
			else
			{
				car.direction = TURNLEFT;
				TurnLeft();
			}
			car.is_obstacle_in_the_way = false;

	}


}


