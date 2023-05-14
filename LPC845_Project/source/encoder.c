/*
 * encoder.c
 *
 *  Created on: 2023. márc. 23.
 *      Author: plasz
 */

#include "encoder.h"

volatile uint32_t captured_time_right = 0;
volatile uint32_t captured_time_left = 0;
volatile uint32_t captured_time_right_prev = 0;
volatile uint32_t captured_time_left_prev = 0;
volatile double  microseconds_elapsed_right = 0;
volatile double microseconds_elapsed_left = 0;



volatile Encoder Encoder_right;
volatile Encoder Encoder_left;

void InitEncoders()
{
	Encoder_right.RPM = 0.0;
	Encoder_right.RPM_prev = 0.0;

	Encoder_left.RPM = 0.0;
	Encoder_left.RPM_prev = 0.0;
}


void EncoderRightCallback(uint32_t flags) {

	Encoder_right.RPM_prev= Encoder_right.RPM;
	captured_time_right_prev = captured_time_right;
	captured_time_right = CTIMER0->CR[1];
	if(captured_time_right_prev)
	{
		microseconds_elapsed_right = captured_time_right - captured_time_right_prev;
		Encoder_right.RPM = 1.0/(microseconds_elapsed_right / RPMCONST);
	}

	PRINTF("%d\n", (int)Encoder_right.RPM);
}

void EncoderLeftCallback(uint32_t flags) {
	Encoder_left.RPM_prev= Encoder_left.RPM;

	captured_time_left_prev = captured_time_left;
	captured_time_left = CTIMER0->CR[2];
	if(captured_time_left_prev)
	{
		microseconds_elapsed_left = captured_time_left - captured_time_left_prev;
		Encoder_left.RPM = 1 / (microseconds_elapsed_left / RPMCONST);
	}
	PRINTF("%d\n", (int)Encoder_left.RPM);
}
