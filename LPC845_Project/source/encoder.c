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


volatile float Encoder_RPM_right = 0.0;
volatile float Encoder_RPM_left = 0.0;
char str_right[16];
char str_left[16];


void EncoderRightCallback(uint32_t flags) {

	captured_time_right_prev = captured_time_right;
	captured_time_right = CTIMER0->CR[1];
	if(captured_time_right_prev)
	{
		microseconds_elapsed_right = captured_time_right - captured_time_right_prev;
//		double a = microseconds_elapsed_right / RPMCONST;
//		RPM_right = 1/a;
		Encoder_RPM_right = 1.0/(microseconds_elapsed_right / RPMCONST);
	}

	  	  		//snprintf(str_right, sizeof(str_right), "%d", Encoder_RPM_right);
	  	  		PRINTF("%d\n", (int)Encoder_RPM_right);

}

void EncoderLeftCallback(uint32_t flags) {
	captured_time_left_prev = captured_time_left;
	captured_time_left = CTIMER0->CR[2];
	if(captured_time_left_prev)
	{
		microseconds_elapsed_left = captured_time_left - captured_time_left_prev;
		Encoder_RPM_left = 1 / (microseconds_elapsed_left / RPMCONST);
	}
		snprintf(str_left, sizeof(str_left), "%d", Encoder_RPM_left);
		PRINTF("%s\n", str_left);

}
