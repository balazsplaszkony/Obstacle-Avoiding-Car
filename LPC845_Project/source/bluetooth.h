/*
 * bluetooth.h
 *
 *  Created on: 2023. márc. 9.
 *      Author: plasz
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_
#include "LPC845.h"
#include <stdbool.h>
#include "peripherals.h"

#include "fsl_debug_console.h"
//extern volatile uint8_t *data ;
//extern volatile uint32_t receivedBytes;

//extern void * buff;
#define BUFFER_SIZE 16

typedef enum ControlPrompt{
	FORWARD = '0',
	BACKWARD = '1',
	RIGHT = '2',
	LEFT = '3',
	STOP = '4',
	SLOWDOWN = '5',
	SPEEDUP = '6',
	TOGGLE_OBSTACLE_AVOIDANCE= '7',
	TOGGLE_TEMPOMAT = '8', //?

}ControlPrompt;

typedef struct UsartBuffer{
	volatile ControlPrompt buff[BUFFER_SIZE];
	volatile bool usartflag;
	volatile uint8_t received_bytes;
}UsartBuffer;

extern volatile UsartBuffer buffer;


//void USART1_USART_IRQ_HANDLER(void);
//void BluetoothCallBack(USART_Type *base, usart_handle_t *handle, status_t status, void *userData);



bool hasNewPrompt();
void UsartBufferInit();
void USART1_IRQHandler();
void CopyMessage(volatile UsartBuffer *local_buffer);
void ClearBuffer();
void USART1_sendByte(uint8_t byte);


#endif /* BLUETOOTH_H_ */
