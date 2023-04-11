/*
 * servo.h
 *
 *  Created on: 2023. ápr. 11.
 *      Author: plasz
 */

#ifndef SERVO_H_
#define SERVO_H_

#include "car.h"

#define ServoLeft 30000
#define Servo Straight 45000
#define ServoRigth 60000

extern volatile bool servo_turn_finished;

void LookToTheRight();
void LookToTheLeft();
void LookStraight();

#endif /* SERVO_H_ */
