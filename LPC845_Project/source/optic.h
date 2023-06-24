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

#define OpticTreshold  700
#define OpticTresholdHysteresis   500

#define MOVING_AVERAGE_FILTER_SIZE 3

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
	int16_t back;
	int16_t measurement[3][MOVING_AVERAGE_FILTER_SIZE];
	OpticStatus status;
}OpticMeasurement;

extern volatile OpticMeasurement optic_measurement;

extern volatile int16_t front_right_first;
extern volatile int16_t front_left_first;
extern volatile int16_t back_first;

extern volatile int16_t front_right_second;
extern volatile int16_t front_left_second;
extern volatile int16_t back_second;


void InitOpticMeasurement(volatile OpticMeasurement* optic_measurement);
void OpticMeasure();
void MoveToNextState();
void StartConversion();
void SET_IR_LED();
void RESET_IR_LED();
void ADCTIMERHandler();
int16_t AveragingMeasurements(uint8_t sensor);

#endif /* OPTIC_H_ */
