/*
 * Copyright 2016-2023 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    main.c
 * @brief   Application entry point.
 */
#include <motor.h>
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC845.h"
#include "fsl_debug_console.h"

/* TODO: insert other include files here. */
#include "fsl_power.h"
#include "stdbool.h"
#include "distance.h"
#include "ultrasonic.h"
#include "bluetooth.h"
#include "encoder.h"
#include "PID.h"
#include "direction.h"
#include "car.h"


/* TODO: insert other definitions and declarations here. */

//extern bool BluetoothFlag;
//UsartBuffer bluetooth_prompts;

/*
 * TODO
 * Initialize motor encoders
   Set target speed for the car
 *
 */
/*
 * @brief   Application entry point.
 */

int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();

    // initializes the starting state of the car
    InitCar();
    // initializes the components of the car
    InitComponents();

    POWER_DisablePD(kPDRUNCFG_PD_ADC0);
    BOARD_InitBootPeripherals();


    NVIC_EnableIRQ(USART1_IRQn);
    EnableIRQ(USART1_IRQn);
//    /* Enable RX interrupt */
    USART_EnableInterrupts(USART1_PERIPHERAL, kUSART_RxReadyInterruptEnable );

    /* Start receiving data */
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
    PRINTF("Hello world");
#endif
    if (SysTick_Config(SystemCoreClock / 1000U))
    {
    while (1){} //hibás osztás érték esetén végtelen ciklus
    }

    while(true){

    	//if new bluetooth prompts have been received store them in local buffer
    	if(hasNewPrompt())
    	{
    		CopyMessage(&bluetooth_prompts);
    		ClearBuffer();
    		for(int i = 0; i < bluetooth_prompts.received_bytes; i++)
    		{
    			PRINTF("%d\n", bluetooth_prompts.buff[i]);
    			//USART1_sendByte(bluetooth_prompts.buff[i]);
    		}
    		//PRINTF("vege");
    	}
    	if(bluetooth_prompts.received_bytes)
    	{
    		ProcessPrompts();
    	}

    	//Calling the state machine of the optic and ultrasonic distance measurements

// for debugging
//  	  	if(ultrasonic_measurement.status == START && ultrasonic_measurement.is_valid)
//  	  	{
//  	  		char str_uh[16];
//  	  		snprintf(str_uh, sizeof(str_uh), "%d", (int)ultrasonic_measurement.distance_in_cm);
//  	  		PRINTF("%s cm\n", str_uh);
//  	  	}
      	SenseDistance();

// for debugging
//  	  	if(optic_measurement.status == StartConversion && optic_measurement.is_valid)
//  	  	{
//  	  	optic_measurement.status =WaitForConversion;
//  	  		char str_bl[16];
//  	  		snprintf(str_bl, sizeof(str_bl), "%d", optic_measurement.back_left_val);
//  	   		PRINTF("BH: %s\n", str_bl);
//
//  	  		//char str_rl[16];
//  	  		//snprintf(str_rl, sizeof(str_rl), "%d", optic_measurement.back_right_distance_in_cm);
//  	   		//PRINTF("JH: %s\n", str_rl);
//
//  	   		//char str_bf[16];
//  	  		//snprintf(str_bf, sizeof(str_bf), "%d", optic_measurement.front_left_val);
//  	   		//PRINTF("BE: %s\n", str_bf);
//
//  	  		//char str_je[16];
//  	  		//snprintf(str_je, sizeof(str_je), "%d", optic_measurement.front_right_distance_in_cm);
//  	   		//PRINTF("JE: %s\n", str_je);
//  	  	}


      	UpdateDirection();

      	//ezt talán inkább timer interruptból kéne ütemezni az integráló tag miatt
//      	float pwm_right = PIDContollerUpdate(&pid_right, RPM_right);
//      	float pwm_left = PIDContollerUpdate(&pid_left, RPM_left);


      	//calculate duty
      	//for test duty = 60, motor1: forward
//      	uint8_t duty = 60;
//
//      	if(isPIDUpdated() || hasNewPrompt() )
//      	{
//      		SetPWM_right(duty);
//          	SetPWM_left(duty);
//      	}


    }
    return 0;

}
