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
#include "USART.h"
#include "ultrasonic.h"
#include "optic.h"
#include <stdbool.h>
#include "servo.h"


#define MinimalSpeed  1
#define MaximumSpeed  9
#define MinimalDuty 40
#define MaximumDuty 80
#define DutyInterval (MaximumDuty - MinimalDuty)
#define deltaDuty  DutyInterval/(MaximumSpeed - MinimalSpeed)


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
	bool is_obstacle_in_the_way;
	bool tempomat;
	bool obstacle_avoidance;
	uint32_t speed;
	bool is_car_blocked;

}Car;

extern Car car;
extern Car car_prev;


void InitComponents();
void InitCar();
bool isObstacleDetected();
bool isRoadBlockedinEveryDirection();
void ProcessPrompts();
void UpdateDirection();
void GoForward();
void GoBackward();
void TurnRight();
void TurnLeft();
void TurnRightStationary();
void TurnLeftStationary();
void StopCar();
void SetSpeed();



#endif /* CAR_H_ */
