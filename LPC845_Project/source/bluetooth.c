///*
// * bluetooth.c
// *
// *  Created on: 2023. márc. 9.
// *      Author: plasz
// */
//
//
//#include "bluetooth.h"
//volatile UsartBuffer buffer;
//
//
////volatile uint8_t *data = NULL ;
////volatile uint32_t receivedBytes = 0;
//
///*
//void USART1_IRQHandler(void)
//{
//
//    // Check if the RX interrupt flag is set
//	if (USART_GetStatusFlags(USART1_PERIPHERAL) & kUSART_RxReady)
//	{
//
//        // Call the transfer handle IRQ function to process the received data
//        USART_TransferHandleIRQ(USART1_PERIPHERAL, &USART1_handle);
//    }
//}
///*
//void BluetoothCallBack(USART_Type *base, usart_handle_t *handle, status_t status, void *userData)
//{
//	PRINTF("cb");
//
//    if (status == kStatus_USART_RxIdle)
//    {
//    	//NVIC_DisableIRQ(USART1_IRQn);
//
//        // Get the number of bytes received
//        USART_TransferGetReceiveCount(base, handle, &receivedBytes);
//
//        // Copy the received bytes from the buffer to your own data structure
//        memcpy(data, USART1_rxBuffer, receivedBytes);
//        data[receivedBytes] = '\0';
//
//
//        // Reset the receive transfer to start receiving more data
//        USART_TransferReceiveNonBlocking(base, handle, &USART1_rxTransfer, &receivedBytes);
//		USART_ClearStatusFlags(USART1_PERIPHERAL, kUSART_RxReady);
//    	//NVIC_EnableIRQ(USART1_IRQn);
//
//    }
//}
//
//bool hasNewData()
//{
//        return (receivedBytes != 0);
//}*/
//
///*void BluetoothCallBack(USART_Type *base, usart_handle_t *handle, status_t status, void *userData)
//{
//    if (status == kStatus_USART_RxIdle)
//    {
//    	uint16_t tailIndex = handle->rxRingBufferHead;
//    	uint16_t headIndex = handle->rxRingBufferHead;
//        data = (uint8_t *)userData;
//        if (headIndex >= tailIndex)
//        {
//            receivedBytes = headIndex - tailIndex;
//        }
//        else
//        {
//            receivedBytes = handle->rxRingBufferSize - (tailIndex - headIndex);
//        }
//        // Do whatever you need to do with the received data
//        // For example, you can copy it to another buffer, process it, etc.
//        // Here, we will just print it to the console
//        //printf("Received data: %s\n", data);
//    }
//}*/
//
///*returns the state of usartflag*/
//bool hasNewPrompt()
//{
//	return buffer.usartflag;
//}
//
///*copies the uartbuffer to a local buffer*/
//void CopyMessage(volatile UsartBuffer *local_buffer)
//{
//	memcpy(local_buffer->buff, buffer.buff, BUFFER_SIZE);
//	local_buffer->received_bytes = buffer.received_bytes;
//}
//
///*initializes buffer with starting values*/
//void UsartBufferInit()
//{
//	buffer.received_bytes = 0;
//	buffer.usartflag = false;
//	for(int i = 0; i < BUFFER_SIZE; i++)
//		buffer.buff[i] = 0;
//}
//
//
//void ClearBuffer()
//{
//	//NVIC_DisableIRQ(USART1_IRQn);
//	buffer.received_bytes = 0;
//	buffer.usartflag = false;
//    //NVIC_EnableIRQ(USART1_IRQn);
//
//}
//
//void USART1_sendByte(uint8_t byte)
//{
//    USART_WriteByte(USART1_PERIPHERAL, byte);
//}
//
//void USART1_IRQHandler(void)
//{
//	if (USART_GetStatusFlags(USART1_PERIPHERAL) & kUSART_RxReady)
//	{
//		USART_ClearStatusFlags(USART1_PERIPHERAL, kUSART_RxReady);
//		buffer.usartflag = true;
//		buffer.buff[buffer.received_bytes] = USART1->RXDAT;
//		buffer.received_bytes++;
//	}
//
//    if (USART_GetStatusFlags(USART1_PERIPHERAL) & kUSART_TxReady)
//    {
//        /* Clear the TX ready flag */
//        USART_ClearStatusFlags(USART1_PERIPHERAL, kUSART_TxReady);
//    }
//}
