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

         MRT_ClearStatusFlags(MRT0, kMRT_Channel_0, kMRT_TimerInterruptFlag);
         ADCTIMERHandler();
    }
    if (MRT_GetStatusFlags(MRT0, kMRT_Channel_1)) {
        MRT_ClearStatusFlags(MRT0, kMRT_Channel_1, kMRT_TimerInterruptFlag);
    		PIDTIMERHandler();
    }
    if (MRT_GetStatusFlags(MRT0, kMRT_Channel_2)) {

             MRT_ClearStatusFlags(MRT0, kMRT_Channel_2, kMRT_TimerInterruptFlag);
             MRT_StopTimer(MRT0_PERIPHERAL, MRT0_CHANNEL_2);
             servo_turn_finished = true;

        }
    if (MRT_GetStatusFlags(MRT0, kMRT_Channel_3)) {

             MRT_ClearStatusFlags(MRT0, kMRT_Channel_3, kMRT_TimerInterruptFlag);
          	 MRT_StopTimer(MRT0_PERIPHERAL, MRT0_CHANNEL_3);
          	 GPIO_PinWrite(GPIO, 0U, BOARD_INITPINS_Servo_PIN, 0);

        }
  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}
