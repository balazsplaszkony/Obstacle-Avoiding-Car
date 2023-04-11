/*
 * encoder.h
 *
 *  Created on: 2023. márc. 23.
 *      Author: plasz
 */

#ifndef ENCODER_H_
#define ENCODER_H_
#include <stdbool.h>
#include <stdint.h>
#include <string.h>


#include "peripherals.h"
#include "fsl_debug_console.h"

#define MicroSecondsInMinute 60000000
#define Resolution 20
#define RPMCONST MicroSecondsInMinute * Resolution

extern volatile double RPM_right;
extern volatile double RPM_left;




void EncoderRightCallback(uint32_t flags);
void EncoderLeftCallback(uint32_t flags);

#endif /* ENCODER_H_ */