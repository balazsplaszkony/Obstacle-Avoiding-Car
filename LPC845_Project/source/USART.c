/*
 * USART.c
 *
 *  Created on: Apr 14, 2023
 *      Author: benes
 */
#include "peripherals.h"
#include "fsl_usart.h"
#include "string.h"
#include "USART.h"

 /*
  The above struct and functions used by USART:
struct _usart_handle
{
    const uint8_t *volatile txData; /!< Address of remaining data to send. /
    volatile size_t txDataSize;     /!< Size of the remaining data to send./
    size_t txDataSizeAll;           /!< Size of the data to send out.  /
    uint8_t *volatile rxData;       /!< Address of remaining data to receive. /
    volatile size_t rxDataSize;     /!< Size of the remaining data to receive. /
    size_t rxDataSizeAll;           /!< Size of the data to receive. /

    uint8_t *rxRingBuffer;              /!< Start address of the receiver ring buffer. /
    size_t rxRingBufferSize;            /!< Size of the ring buffer. /
    volatile uint16_t rxRingBufferHead; /!< Index for the driver to store received data into ring buffer. /
    volatile uint16_t rxRingBufferTail; /!< Index for the user to get data from the ring buffer. /
    usart_transfer_callback_t callback; /!< Callback function. /
    void *userData;                     /!< USART callback function parameter./

    volatile uint8_t txState; /!< TX transfer state. /
    volatile uint8_t rxState; /!< RX transfer state /
}


typedef struct _usart_transfer
{
     // Use separate TX and RX data pointer, because TX data is const data.
     // The member data is kept for backward compatibility.
     //
    union
    {
        uint8_t *data;         /!< The buffer of data to be transfer./
        uint8_t *rxData;       /!< The buffer to receive data. /
        const uint8_t *txData; /!< The buffer of data to be sent. /
    };
    size_t dataSize; /!< The byte count to be transfer. /
} usart_transfer_t;
*/

//status_t USART_TransferSendNonBlocking(USART_Type *base, usart_handle_t *handle, usart_transfer_t *xfer);
/*
void USART_TransferStartRingBuffer(USART_Type *base,
                                   usart_handle_t *handle,
                                   uint8_t *ringBuffer,
                                   size_t ringBufferSize);
*/

UsartBuffer buffer;

void INIT_USART(void)
{
	USART_TransferStartRingBuffer(USART1, &USART1_handle, &USART1_rxBuffer[0], USART1_RX_BUFFER_SIZE);
}
void UsartBufferInit()
{
	for(int i = 0; i < rx_buffer_size; i++)
		buffer.prompt[i] = 0;
	buffer.parameter = 0.0;
}

void PrintUSART1_NB(char * str)
{
	uint32_t count;
	status_t status;
	do{
		status = USART_TransferGetSendCount(USART1, &USART1_handle, &count);
	}while(!(status == kStatus_NoTransferInProgress)&(status == kStatus_Success));
	//}while(!((status == kStatus_Success) | (status == kStatus_NoTransferInProgress)));
    strcpy(USART1_txTransfer.txData,str);
    USART1_txTransfer.dataSize = strlen(str);
    USART_TransferSendNonBlocking(USART1, &USART1_handle, &USART1_txTransfer);
}

uint8_t GetUSART(uint8_t *data)
{
    USART_DisableInterrupts(USART1, (uint32_t)kUSART_RxReadyInterruptEnable |
                                      (uint32_t)kUSART_HardwareOverRunInterruptEnable);
	uint8_t retval = 0;
	if(USART_TransferGetRxRingBufferLength(&USART1_handle) > 0)
	{
		*data = USART1_handle.rxRingBuffer[USART1_handle.rxRingBufferTail];
		USART1_handle.rxRingBufferTail = (USART1_handle.rxRingBufferTail + 1) % USART1_handle.rxRingBufferSize;
		if(USART1_handle.rxDataSize > 0) USART1_handle.rxDataSize = USART1_handle.rxDataSize - 1;
		retval = 1;
	}
    USART_EnableInterrupts(USART1,
                           (uint32_t)kUSART_RxReadyInterruptEnable | (uint32_t)kUSART_HardwareOverRunInterruptEnable);
	return(retval);
}

bool GetUSARTMessage()
{
	static int reset = 1;
	int retval = 0;
	if(reset)
	{
		GetString_TillEndChar(buffer.prompt, ',', rx_buffer_size, 1);
		reset = 0;
	}
	else
	{
		if(GetString_TillEndChar(buffer.prompt, ',', rx_buffer_size, 0))
		{
			reset = 1;
			retval = 1;
		}
	}
	return retval;
	}

void ParsePrompt()
{
	char* colonPtr = strchr(buffer.prompt, ':');  // Find the first occurrence of ":"

	    if (colonPtr != NULL) {
	        *colonPtr = '\0';  // Truncate the string at ":"
	        char* numberString = colonPtr + 1;
	        buffer.parameter = atof(numberString);
	    }
}

void ClearBuffer()
{
	buffer.parameter = 0;
	for(int i = 0; i < rx_buffer_size; i++)
		buffer.prompt[i] = '\0';
}


uint8_t GetString_TillEndChar(char *str, uint8_t End_Char, uint8_t LenMax, uint8_t reset)
{
#define RESET_state		1
#define COLLECT_state	2
#define CR_State		3
#define END_State		4

	static uint8_t GstrState, i, data, ret_val = 0;
	if(reset)
	{
		GstrState = RESET_state;
	}

	switch(GstrState)
	{
	case RESET_state:
		i = 0;
		ret_val = 0;
		GstrState = COLLECT_state;
		break;
	case COLLECT_state:
		if(GetUSART(&data))
		{
			if(data == esc)
			{
				GstrState = RESET_state;
			}
			else
				if(data == End_Char)
				{
					*(str + i) = 0;
					GstrState = END_State;
					ret_val = 1;
				}
				else
				{
					*(str + i) = data;
					if(i < LenMax-1)
					{
						i++;
					}
					else
					{
						*(str + i) = 0;
						GstrState = END_State;
						ret_val = 2;
					}
				}
		}
		break;
	case END_State:
		break;
	}
	return(ret_val);
}










