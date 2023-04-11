/*
 * speedcontrol.h
 *
 *  Created on: 2023. márc. 8.
 *      Author: plasz
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "ultrasonic.h"
#include "optic.h"
//#include "bluetooth.h"
#include "pin_mux.h"
#include "LPC845.h"
#include "peripherals.h"

#define MinimumDutyCycle 40
#define MaximumDutyCycle 80


typedef struct Motor{
	uint8_t pwm_channel;
	uint8_t Input1;
	uint8_t Input2;
}Motor;

extern Motor motor_right;
extern Motor motor_left;

void InitMotors();
void SetPWM(uint16_t duty_scaled_up, Motor motor);
void SetRPM(Motor* motor);
void RotateForward(Motor* motor);
void RotateBackward(Motor* motor);
void StopMotors(Motor* motor);
void ControlMotors();
void UpdatePwmDutycycleScaledUp(SCT_Type *base, sctimer_out_t output, uint16_t scaledUpDutyCyclePercent, uint32_t event);

#endif /* MOTOR_H_ */