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
#define pi 3.14159
#define WheelDiameter 6 //cm
#define WheelRadius (WheelDiameter / 2)
#define WheelCircumference (pi * 2* WheelRadius)


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
	bool is_car_blocked;
	uint8_t speed; // cm/s
	uint8_t duty;

}Car;

extern Car car;
extern Car car_prev;


void InitComponents();
void InitCar();
bool isObstacleDetected();
bool isRoadBlockedinEveryDirection();
bool DetectCollision();
void ProcessPrompt();
void UpdateDirection();
void GoForward();
void GoBackward();
void TurnRight();
void TurnLeft();
void TurnRightStationary();
void TurnLeftStationary();
void StopCar();
void SetSpeed();
float CalculateSpeedfromRPM(float rpm);
float CalculateRPMfromSpeed(float speed);





#endif /* CAR_H_ */
