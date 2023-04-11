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
	motor_right.pwm_channel = 0U;;
	motor_right.Input1 = BOARD_INITPINS_Motor1IN1_PIN;
	motor_right.Input2 = BOARD_INITPINS_Motor1IN2_PIN;

	//motor_left.direction = STOP_M;
	motor_left.pwm_channel = 1U;
	motor_left.Input1 = BOARD_INITPINS_Motor2IN1_PIN;
	motor_left.Input2 = BOARD_INITPINS_Motor2IN2_PIN;
}

void SetPWM(uint16_t duty_scaled_up, Motor motor){
	if(duty_scaled_up > 800)
		duty_scaled_up = 800;
	UpdatePwmDutycycleScaledUp(SCT0, motor.pwm_channel, duty_scaled_up, SCT0_pwmEvent[0]);
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

/* Modified version of the SCTIMER_UpdatePwmDutycycle function
 * For finer resolution takes the duty cycle value scaled up by a factor of 10 as the input
 */
void UpdatePwmDutycycleScaledUp(SCT_Type *base, sctimer_out_t output, uint16_t scaledUpDutyCyclePercent, uint32_t event)

{
    assert(scaledUpDutyCyclePercent <= 800U);
    assert((uint32_t)output < (uint32_t)FSL_FEATURE_SCT_NUMBER_OF_OUTPUTS);
    assert(1U == (base->CONFIG & SCT_CONFIG_UNIFY_MASK));

    uint32_t periodMatchReg, pulseMatchReg;
    uint32_t pulsePeriod = 0, period;

    /* Retrieve the match register number for the PWM period */
    periodMatchReg = base->EV[event].CTRL & SCT_EV_CTRL_MATCHSEL_MASK;

    /* Retrieve the match register number for the PWM pulse period */
    pulseMatchReg = base->EV[event + 1U].CTRL & SCT_EV_CTRL_MATCHSEL_MASK;

    period = base->MATCH[periodMatchReg];

    /* Stop the counter before updating match register */
    SCTIMER_StopTimer(base, (uint32_t)kSCTIMER_Counter_U);

    pulsePeriod = (uint32_t)(((uint64_t)period * scaledUpDutyCyclePercent) / 1000U);

    /* Update dutycycle */
    base->MATCH[pulseMatchReg]    = pulsePeriod;
    base->MATCHREL[pulseMatchReg] = pulsePeriod;

    /* Restart the counter */
    SCTIMER_StartTimer(base, (uint32_t)kSCTIMER_Counter_U);
}

