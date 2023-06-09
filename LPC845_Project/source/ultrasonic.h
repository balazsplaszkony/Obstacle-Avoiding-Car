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
#include "car.h"

//speed of sound in cm/usec
#define SpeedOfSound 0.0343
#define UltrasonicTreshold 20
#define DistanceMax 400

typedef enum Status_UltraSonic
{
	START,
	TRIG,
	WAITFIRSTIT,
	WAITSECONDIT
}UltraSonicStatus;

typedef struct UltraSonicMeasurement
{
	uint16_t distance_in_cm;
	uint16_t distance_in_cm_prev;
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
uint8_t GetUltrasonicTreshold();

#endif /* ULTRASONIC_H_ */
