/*
 * ultrasonic.h
 *
 *  Created on: 2023. márc. 4.
 *      Author: plasz
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "pin_mux.h"
#include "fsl_gpio.h"
#include <stdint.h>
#include <stdbool.h>
#include "sys.h"
#include "SysTimer.h"
#include "fsl_debug_console.h"
#include <stdio.h>

//speed of sound in cm/usec
#define SpeedOfSound 0.0343
#define UltrasonicTreshold 30

typedef enum Status_UltraSonic
{
	START,
	TRIG,
	WAITFIRSTIT,
	WAITSECONDIT
}UltraSonicStatus;

typedef struct UltraSonicMeasurement
{
	float distance_in_cm;
	bool is_valid;
	UltraSonicStatus status;
}UltraSonicMeasurement;

extern volatile UltraSonicMeasurement ultrasonic_measurement;

void InitUltrasonicMeasurement(volatile UltraSonicMeasurement* ultrasonic_measurement);
void UltrasonicMeasure();
void TriggerUltrasonicSensor();
void EndTriggerUltrasonicSensor();
void Ultrasonic_Callback(uint32_t flags);
void InvalidateMeasurement();

#endif /* ULTRASONIC_H_ */