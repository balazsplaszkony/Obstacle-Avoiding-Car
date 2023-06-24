/*
 * optic.c
 *
 *  Created on: 2023. márc. 8.
 *      Author: plasz
 */

#include "optic.h"
volatile int16_t front_right_first = 0;
volatile int16_t front_left_first = 0;
volatile int16_t back_first = 0;

volatile int16_t front_right_second = 0;
volatile int16_t front_left_second = 0;
volatile int16_t back_second = 0;


volatile OpticMeasurement optic_measurement;

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
	optic_measurement->back = 0;
	optic_measurement->front_left = 0;
	optic_measurement->front_right = 0;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < MOVING_AVERAGE_FILTER_SIZE; j++)
			optic_measurement->measurement[i][j] = 0;
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



		front_right_first = (ADC0->DAT[1] & ADC_DAT_RESULT_MASK)>> ADC_DAT_RESULT_SHIFT;
					front_left_first  = (ADC0->DAT[2] & ADC_DAT_RESULT_MASK)>> ADC_DAT_RESULT_SHIFT;
					back_first   = (ADC0->DAT[5] & ADC_DAT_RESULT_MASK)>> ADC_DAT_RESULT_SHIFT;


	}
	if(optic_measurement.status == WaitForSecondConversion){


			front_right_second = (ADC0->DAT[1] & ADC_DAT_RESULT_MASK)>> ADC_DAT_RESULT_SHIFT;
			front_left_second  = (ADC0->DAT[2] & ADC_DAT_RESULT_MASK)>> ADC_DAT_RESULT_SHIFT;
			back_second   = (ADC0->DAT[5] & ADC_DAT_RESULT_MASK)>> ADC_DAT_RESULT_SHIFT;


			optic_measurement.measurement[0][counter] =  (front_right_second - front_right_first >0 ) ?
					(front_right_second - front_right_first) : 0;


			optic_measurement.measurement[1][counter] = (front_left_second - front_left_first >0 ) ?
					(front_left_second - front_left_first) : 0;


			optic_measurement.measurement[2][counter] = (back_second - back_first >0 ) ?
					(back_second - back_first) : 0;


			optic_measurement.front_right = AveragingMeasurements(0);
			optic_measurement.front_left = AveragingMeasurements(1);
			optic_measurement.back = AveragingMeasurements(2);

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
