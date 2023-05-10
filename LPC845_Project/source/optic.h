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
#define OpticTreshold  3000 //ki kell még méregetni

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
	uint32_t front_right;
	uint32_t front_left;
	uint32_t back_right;
	uint32_t back_left;
	//bool is_valid;
	OpticStatus status;
}OpticMeasurement;

extern volatile OpticMeasurement optic_measurement;
extern volatile uint32_t potmeter;

extern volatile uint32_t front_right_first;
extern volatile uint32_t front_left_first;
extern volatile uint32_t back_right_first;
extern volatile uint32_t back_left_first;

extern volatile uint32_t front_right_second;
extern volatile uint32_t front_left_second;
extern volatile uint32_t back_right_second;
extern volatile uint32_t back_left_second;


void InitOpticMeasurement(volatile OpticMeasurement* optic_measurement);
void OpticMeasure();
void MoveToNextState();
void StartConversion();
void SET_IR_LED();
void RESET_IR_LED();
void ADCTIMERHandler();

#endif /* OPTIC_H_ */
