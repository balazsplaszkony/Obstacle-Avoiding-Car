/*
 * car.h
 *
 *  Created on: 2023. márc. 28.
 *      Author: plasz
 */

#ifndef CAR_H_
#define CAR_H_


#include "motor.h"
#include "encoder.h"
#include "direction.h"
#include "PID.h"
#include "bluetooth.h"
#include "ultrasonic.h"
#include "optic.h"
#include <stdbool.h>

#define MinimalSpeed  1
#define MaximumSpeed  9

extern volatile UsartBuffer bluetooth_prompts;

typedef enum Direction{
	GOFORWARD,
	GOBACKWARD,
	TURNRIGHT,
	TURNLEFT,
	STOPCAR
}Direction;

typedef struct Car{
	//ide belerakhatnám az összes érzékelőt?

	Direction direction;
	bool tempomat;
	bool obstacle_avoidance;
	uint32_t speed;

}Car;

extern Car car;
extern Car car_prev;


void InitComponents();
void InitCar();
bool isObstacleDetected();
void ProcessPrompts();
void UpdateDirection();
void GoForward();
void GoBackward();
void TurnRight();
void TurnLeft();
void StopCar();


#endif /* CAR_H_ */
