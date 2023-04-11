/*
 * speedcontrol.c
 *
 *  Created on: 2023. márc. 8.
 *      Author: plasz
 */

#include "motor.h"

Motor motor_left;
Motor motor_right;

void InitMotors(){

	//ennek igy lehet nem sok értelme van és máshogy kéne
	//motor_right.direction = STOP_M;
	motor_right.pwm_pin = BOARD_INITPINS_Motor1EN_PIN;
	motor_right.Input1 = BOARD_INITPINS_Motor1IN1_PIN;
	motor_right.Input2 = BOARD_INITPINS_Motor1IN2_PIN;

	//motor_left.direction = STOP_M;
	motor_left.pwm_pin = BOARD_INITPINS_Motor2EN_PIN;
	motor_left.Input1 = BOARD_INITPINS_Motor2IN1_PIN;
	motor_left.Input2 = BOARD_INITPINS_Motor2IN2_PIN;
}

void SetPWM_right(uint8_t duty){
	if(duty > MaximumDutyCycle)
		duty = MaximumDutyCycle;
	SCTIMER_UpdatePwmDutycycle(SCT0, 0U, duty, SCT0_pwmEvent[0]);
}


void SetPWM_left(uint8_t duty){
	if(duty > MaximumDutyCycle)
		duty = MaximumDutyCycle;
	SCTIMER_UpdatePwmDutycycle(SCT0, 1U, duty, SCT0_pwmEvent[0]);
}

void SetRPM(Motor* motor)
{
	//TODO
	;
}
void RotateForward(Motor* motor)
{
	  GPIO_PinWrite(GPIO, 0, motor->Input1, 1);
	  GPIO_PinWrite(GPIO, 0, motor->Input2, 0);

}
void RotateBackward(Motor* motor)
{
	  GPIO_PinWrite(GPIO, 0, motor->Input1, 0);
	  GPIO_PinWrite(GPIO, 0, motor->Input2, 1);
}

void StopMotors(Motor* motor)
{
	  GPIO_PinWrite(GPIO, 0, motor->Input1, 0);
	  GPIO_PinWrite(GPIO, 0, motor->Input2, 0);
}


