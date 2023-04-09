/*
 * distance.h
 *
 *  Created on: 2023. márc. 8.
 *      Author: plasz
 */

#ifndef DISTANCE_H_
#define DISTANCE_H_
#include "ultrasonic.h"
#include "optic.h"


typedef struct DistanceMeasurement{
	UltraSonicMeasurement ultrasonic_measurement;
	OpticMeasurement optic_measurement;
}DistanceMeasurement;

extern volatile DistanceMeasurement distance_measurement;


void SenseDistance();




#endif /* DISTANCE_H_ */
