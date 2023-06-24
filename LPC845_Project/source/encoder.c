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

void InitEncoder(volatile Encoder* encoder) {
    encoder->RPM = 0.0f;
    encoder->RPM_prev = 0.0f;
    encoder->updated = false;
}

void EncoderRightCallback(uint32_t flags) {
    static float measurement = 0;
    static bool transient = false;

    Encoder_right.RPM_prev = Encoder_right.RPM;
    captured_time_right_prev = captured_time_right;
    captured_time_right = CTIMER0->CR[1];

    if (captured_time_right_prev) {
        microseconds_elapsed_right = captured_time_right - captured_time_right_prev;
        measurement = (1.0 / (microseconds_elapsed_right / (60.0 * 1000000.0))) * (1.0 / Resolution);
    }

    if(measurement > 200)
    {
    	measurement = 200;

    }

    if(!transient)
            {
                if((measurement - Encoder_right.RPM ) < 0.2* Encoder_right.RPM)
                	Encoder_right.RPM = measurement;
                else
                {
                	transient = true;
                    Encoder_right.updated = true;
                	return;
                }
            }

    if(transient)
    {
       	if(measurement < 190)
    	{
    		Encoder_right.RPM = measurement;
    		transient = false;
    	}

    }

    Encoder_right.updated = true;
}


void EncoderLeftCallback(uint32_t flags) {
    static float measurement = 0;
        static bool transient = false;

    Encoder_left.RPM_prev = Encoder_left.RPM;
    captured_time_left_prev = captured_time_left;
    captured_time_left = CTIMER0->CR[2];

    if (captured_time_left_prev) {
        microseconds_elapsed_left = captured_time_left - captured_time_left_prev;
        measurement = (1.0 / (microseconds_elapsed_left / (60.0 * 1000000.0))) * (1.0 / Resolution);
    }

    if(measurement > 200)
    {
    	measurement = 200;

    }
    if(!transient)
        	        {
        	            if((measurement - Encoder_left.RPM) < 0.2* Encoder_left.RPM)
        	            	Encoder_left.RPM = measurement;
        	            else
        	            {
        	            	transient = true;
        	            	Encoder_left.updated = true;
        	            	return;
        	            }
        	        }

        if(transient)
        {
           	if(measurement < 190)
            {
            	Encoder_left.RPM = measurement;
            	transient = false;
            }
        }


    Encoder_left.updated = true;
}

void HandleNoEncoderSignal(volatile Encoder* encoder)
{
	 // Reset RPM values to 0
	    encoder->RPM = 0.0f;
	    encoder->RPM_prev = 0.0f;

}
