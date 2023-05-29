/*
 * optic.h
 *
 *  Created on: 2023. márc. 8.
 *      Author: plasz
 */
#ifndef OPTIC_H_
#define OPTIC_H_

#include <stdbool.h>
#include "peripherals.h"
#include "fsl_gpio.h"

#include "fsl_debug_console.h"

#define ADC_RESULT_MASK 0xFFF
#define OpticTreshold  2000 //ki kell még méregetni
#define OpticTresholdHysteresis   1500 //ki kell még méregetni

#define MOVING_AVERAGE_FILTER_SIZE 5

typedef enum Status_Optic
{
	StartFirstConversion,
	WaitForFirstConversion,
	StartSecondConversion,
	WaitForSecondConversion,

} OpticStatus;

typedef struct OpticMeasurement
{
	volatile bool optic_flag;
	int16_t front_right;
	int16_t front_left;
	int16_t back_right;
	int16_t back_left;
	int16_t measurement[4][MOVING_AVERAGE_FILTER_SIZE];

	//bool is_valid;
	OpticStatus status;
}OpticMeasurement;

extern volatile OpticMeasurement optic_measurement;

extern volatile int16_t front_right_first;
extern volatile int16_t front_left_first;
extern volatile int16_t back_right_first;
extern volatile int16_t back_left_first;

extern volatile int16_t front_right_second;
extern volatile int16_t front_left_second;
extern volatile int16_t back_right_second;
extern volatile int16_t back_left_second;


void InitOpticMeasurement(volatile OpticMeasurement* optic_measurement);
void OpticMeasure();
void MoveToNextState();
void StartConversion();
void SET_IR_LED();
void RESET_IR_LED();
void ADCTIMERHandler();
int16_t AveragingMeasurements(uint8_t sensor);

#endif /* OPTIC_H_ */
