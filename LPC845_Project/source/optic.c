/*
 * optic.c
 *
 *  Created on: 2023. márc. 8.
 *      Author: plasz
 */

#include "optic.h"
volatile uint32_t front_right_first = 0;
volatile uint32_t front_left_first = 0;
volatile uint32_t back_right_first = 0;
volatile uint32_t back_left_first = 0;

volatile uint32_t front_right_second = 0;
volatile uint32_t front_left_second = 0;
volatile uint32_t back_right_second = 0;
volatile uint32_t back_left_second = 0;


volatile OpticMeasurement optic_measurement; //= {0, 0, 0, 0,} ;//false, StartConversion};
//volatile uint32_t potmeter = 0;
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

	if(optic_measurement.status == WaitForFirstConversion){
		PRINTF("1\n");
		front_right_first = ADC0->DAT[1] & ADC_RESULT_MASK;
		front_left_first  = ADC0->DAT[2] & ADC_RESULT_MASK;
		back_right_first  = ADC0->DAT[3] & ADC_RESULT_MASK;
		back_left_first   = ADC0->DAT[5] & ADC_RESULT_MASK;
	}
	if(optic_measurement.status == WaitForSecondConversion){
		PRINTF("2\n");
			front_right_second = ADC0->DAT[1] & ADC_RESULT_MASK;
			front_left_second  = ADC0->DAT[2] & ADC_RESULT_MASK;
			back_right_second  = ADC0->DAT[3] & ADC_RESULT_MASK;
			back_left_second   = ADC0->DAT[5] & ADC_RESULT_MASK;

			optic_measurement.front_right = front_right_second - front_right_second;
			optic_measurement.front_left = front_left_second - front_left_first;
			optic_measurement.back_right = back_right_second - back_right_first;
			optic_measurement.back_left = back_left_second - back_left_first;
			PRINTF("%d - %d = %d\n",back_left_second, back_left_first, optic_measurement.back_left);
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
