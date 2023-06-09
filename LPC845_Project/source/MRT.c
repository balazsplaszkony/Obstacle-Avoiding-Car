/*
 * MRT.c
 *
 *  Created on: 2023. ápr. 1.
 *      Author: plasz
 */
#include "optic.h"
#include "PID.h"
#include "encoder.h"
#include "fsl_debug_console.h"
#include "car.h"

/* MRT0_IRQn interrupt handler */
void MRT0_IRQHANDLER(void) {
  /*  Place your code here */
    if (MRT_GetStatusFlags(MRT0, kMRT_Channel_0)) {

         ADCTIMERHandler();
         MRT_ClearStatusFlags(MRT0, kMRT_Channel_0, kMRT_TimerInterruptFlag);

    }
     if (MRT_GetStatusFlags(MRT0, kMRT_Channel_1)) {

    	PIDTIMERHandler();
        MRT_ClearStatusFlags(MRT0, kMRT_Channel_1, kMRT_TimerInterruptFlag);

    }
     if (MRT_GetStatusFlags(MRT0, kMRT_Channel_2)) {
    	//EncoderTIMERHandler();
        MRT_ClearStatusFlags(MRT0, kMRT_Channel_2, kMRT_TimerInterruptFlag);

        }
     if (MRT_GetStatusFlags(MRT0, kMRT_Channel_3)) {
    	__disable_irq();
    	int data = Encoder_right.RPM;
    	__enable_irq();
    		PRINTF("%d,\n",data);
             MRT_ClearStatusFlags(MRT0, kMRT_Channel_3, kMRT_TimerInterruptFlag);

        }
  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}
