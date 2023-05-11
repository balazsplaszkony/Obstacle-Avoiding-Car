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
#define RPMCONST (MicroSecondsInMinute * Resolution)
#define Maximum_Tolerated_RPM_Drop 50


typedef struct Encoder{
	volatile float RPM;
	volatile float RPM_prev;

}Encoder;

extern volatile Encoder Encoder_right;
extern volatile Encoder Encoder_left;

void InitEncoders();
void EncoderRightCallback(uint32_t flags);
void EncoderLeftCallback(uint32_t flags);

#endif /* ENCODER_H_ */
