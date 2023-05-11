/*
 * optic.c
 *
 *  Created on: 2023. márc. 8.
 *      Author: plasz
 */

#include "optic.h"
volatile int16_t front_right_first = 0;
volatile int16_t front_left_first = 0;
volatile int16_t back_right_first = 0;
volatile int16_t back_left_first = 0;

volatile int16_t front_right_second = 0;
volatile int16_t front_left_second = 0;
volatile int16_t back_right_second = 0;
volatile int16_t back_left_second = 0;


volatile OpticMeasurement optic_measurement; //= {0, 0, 0, 0,} ;//false, StartConversion};

void OpticMeasure()
{
	if(optic_measurement.optic_flag)
	{
		switch(optic_measurement.status){
			case StartFirstConversion: StartConversion(); break;
			case WaitForFirstConversion: SET_IR_LED(); break;
			case StartSecondConversion: StartConversion(); break;
			case WaitForSecondConversion: RESET_IR_LED(); break;
			default: break;
		}
		MoveToNextState();
	}
}

void MoveToNextState()
{
	optic_measurement.status = (optic_measurement.status +1) % 4;
	optic_measurement.optic_flag = false;
}

void InitOpticMeasurement(volatile OpticMeasurement* optic_measurement)
{
	optic_measurement->status = StartFirstConversion;
	optic_measurement->optic_flag = false;
	optic_measurement->back_left = 0;
	optic_measurement->back_right = 0;
	optic_measurement->front_left = 0;
	optic_measurement->front_right = 0;

}

void StartConversion()
{
	ADC_EnableInterrupts(ADC0_PERIPHERAL, kADC_ConvSeqAInterruptEnable);
	EnableIRQ(ADC0_ADC_SEQ_A_IRQN);
	ADC_DoSoftwareTriggerConvSeqA(ADC0_PERIPHERAL);
}


void ADC0_SEQA_IRQHandler(void)
{
	optic_measurement.optic_flag = true;
	static uint8_t counter = 0;
	if(optic_measurement.status == WaitForFirstConversion){
		front_right_first = ADC0->DAT[1] & ADC_RESULT_MASK;
		front_left_first  = ADC0->DAT[2] & ADC_RESULT_MASK;
		back_right_first  = ADC0->DAT[3] & ADC_RESULT_MASK;
		back_left_first   = ADC0->DAT[5] & ADC_RESULT_MASK;
	}
	if(optic_measurement.status == WaitForSecondConversion){
			front_right_second = ADC0->DAT[1] & ADC_RESULT_MASK;
			front_left_second  = ADC0->DAT[2] & ADC_RESULT_MASK;
			back_right_second  = ADC0->DAT[3] & ADC_RESULT_MASK;
			back_left_second   = ADC0->DAT[5] & ADC_RESULT_MASK;

			optic_measurement.measurement[0][counter] =  (front_right_second - front_right_second >0 ) ?
					(front_right_second - front_right_second) : 0;


			optic_measurement.measurement[1][counter] = (front_left_second - front_left_first >0 ) ?
					(front_left_second - front_left_first) : 0;


			optic_measurement.measurement[2][counter] = (back_right_second - back_right_first >0 ) ?
					(back_right_second - back_right_first) : 0;


			optic_measurement.measurement[3][counter] = (back_left_second - back_left_first >0 ) ?
					(back_left_second - back_left_first) : 0;

			optic_measurement.front_right = AveragingMeasurements(0);
			optic_measurement.front_left = AveragingMeasurements(1);
			optic_measurement.back_right = AveragingMeasurements(2);
			optic_measurement.back_left = AveragingMeasurements(3);

			counter++;
			counter = counter % MOVING_AVERAGE_FILTER_SIZE;
		}

    ADC_ClearStatusFlags(ADC0_PERIPHERAL, kADC_ConvSeqAInterruptFlag);
}

void SET_IR_LED()
{
	GPIO_PinWrite(GPIO, 0U, 0U, 1);
}


void RESET_IR_LED()
{
	GPIO_PinWrite(GPIO, 0U, 0U, 0);
}
void ADCTIMERHandler(){
    optic_measurement.optic_flag = true;
}

int16_t AveragingMeasurements(uint8_t sensor)
{
	int sensor_data = 0;
	for(int i = 0; i < MOVING_AVERAGE_FILTER_SIZE; i++)
		sensor_data += optic_measurement.measurement[sensor][i];
	return sensor_data / MOVING_AVERAGE_FILTER_SIZE;
}


// for debugging
//  	  	if(optic_measurement.status == StartConversion && optic_measurement.is_valid)
//  	  	{
//  	  	optic_measurement.status =WaitForConversion;
//  	  		char str_bl[16];
//  	  		snprintf(str_bl, sizeof(str_bl), "%d", optic_measurement.back_left_val);
//  	   		PRINTF("BH: %s\n", str_bl);
//
//  	  		//char str_rl[16];
//  	  		//snprintf(str_rl, sizeof(str_rl), "%d", optic_measurement.back_right_distance_in_cm);
//  	   		//PRINTF("JH: %s\n", str_rl);
//
//  	   		//char str_bf[16];
//  	  		//snprintf(str_bf, sizeof(str_bf), "%d", optic_measurement.front_left_val);
//  	   		//PRINTF("BE: %s\n", str_bf);
//
//  	  		//char str_je[16];
//  	  		//snprintf(str_je, sizeof(str_je), "%d", optic_measurement.front_right_distance_in_cm);
//  	   		//PRINTF("JE: %s\n", str_je);
//  	  	}
