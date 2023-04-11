/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "fsl_common.h"
#include "fsl_usart.h"
#include "fsl_clock.h"
#include "fsl_ctimer.h"
#include "fsl_adc.h"
#include "fsl_sctimer.h"
#include "fsl_mrt.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/
/* Definitions for BOARD_InitPeripherals functional group */
/* BOARD_InitPeripherals defines for USART1 */
/* Definition of peripheral ID */
#define USART1_PERIPHERAL ((USART_Type *)USART1)
/* Definition of the clock source frequency */
#define USART1_CLOCK_SOURCE 15000000UL
/* USART1 interrupt vector ID (number). */
#define USART1_USART_IRQN USART1_IRQn
/* USART1 interrupt handler identifier. */
#define USART1_USART_IRQHANDLER USART1_IRQHandler
/* Definition of peripheral ID */
#define CTIMER0_PERIPHERAL CTIMER0
/* Timer tick frequency in Hz (input frequency of the timer) */
#define CTIMER0_TICK_FREQ 1000000UL
/* Timer tick period in ns (input period of the timer) */
#define CTIMER0_TICK_PERIOD 1000UL
/* Definition of PWM period channel. */
#define CTIMER0_PWM_PERIOD_CH kCTIMER_Match_0
/* Definition of channel 0 ID */
#define CTIMER0_CAPTURE_0_CHANNEL kCTIMER_Capture_0
/* Definition of channel 1 ID */
#define CTIMER0_CAPTURE_1_CHANNEL kCTIMER_Capture_1
/* Definition of channel 2 ID */
#define CTIMER0_CAPTURE_2_CHANNEL kCTIMER_Capture_2
/* CTIMER0 interrupt vector ID (number). */
#define CTIMER0_TIMER_IRQN CTIMER0_IRQn
/* CTIMER0 interrupt vector priority. */
#define CTIMER0_TIMER_IRQ_PRIORITY 0
/* BOARD_InitPeripherals defines for USART0 */
/* Definition of peripheral ID */
#define USART0_PERIPHERAL ((USART_Type *)USART0)
/* Definition of the clock source frequency */
#define USART0_CLOCK_SOURCE 15000000UL
/* Alias for ADC0 peripheral */
#define ADC0_PERIPHERAL ADC0
/* Definition of the clock source frequency. */
#define ADC0_CLK_FREQ 30000000UL
/* ADC0 interrupt vector ID (number). */
#define ADC0_ADC_SEQ_A_IRQN ADC0_SEQA_IRQn
/* ADC0 interrupt vector priority. */
#define ADC0_ADC_SEQ_A_IRQ_PRIORITY 1
/* ADC0 interrupt handler identifier. */
#define ADC0_ADC_SEQ_A_IRQHANDLER ADC0_SEQA_IRQHandler
/* BOARD_InitPeripherals defines for SCT0 */
/* Definition of peripheral ID */
#define SCT0_PERIPHERAL SCT0
/* Definition of clock source frequency */
#define SCT0_CLOCK_FREQ 30000000UL
/* SCT0 interrupt vector ID (number). */
#define SCT0_IRQN SCT0_IRQn
/* SCT0 interrupt handler identifier. */
#define SCT0_IRQHANDLER SCT0_IRQHandler
/* Definition of peripheral ID */
#define MRT0_PERIPHERAL MRT0
/* Definition of channel 0 ID */
#define MRT0_CHANNEL_0 kMRT_Channel_0
/* Definition of channel 0 mode */
#define MRT0_CHANNEL_0_MODE kMRT_RepeatMode
/* Definition of channel 0 timer in ticks */
#define MRT0_CHANNEL_0_TICKS 7500000U
/* Definition of channel 1 ID */
#define MRT0_CHANNEL_1 kMRT_Channel_1
/* Definition of channel 1 mode */
#define MRT0_CHANNEL_1_MODE kMRT_RepeatMode
/* Definition of channel 1 timer in ticks */
#define MRT0_CHANNEL_1_TICKS 3000000U
/* Definition of channel 2 ID */
#define MRT0_CHANNEL_2 kMRT_Channel_2
/* Definition of channel 2 mode */
#define MRT0_CHANNEL_2_MODE kMRT_RepeatMode
/* Definition of channel 2 timer in ticks */
#define MRT0_CHANNEL_2_TICKS 1500000U
/* Definition of channel 3 ID */
#define MRT0_CHANNEL_3 kMRT_Channel_3
/* Definition of channel 3 mode */
#define MRT0_CHANNEL_3_MODE kMRT_RepeatMode
/* Definition of channel 3 timer in ticks */
#define MRT0_CHANNEL_3_TICKS 45000U
/* MRT0 interrupt vector ID (number). */
#define MRT0_IRQN MRT0_IRQn
/* MRT0 interrupt vector priority. */
#define MRT0_IRQ_PRIORITY 0
/* MRT0 interrupt handler identifier. */
#define MRT0_IRQHANDLER MRT0_IRQHandler

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/
extern const usart_config_t USART1_config;
extern const ctimer_config_t CTIMER0_config;
extern const usart_config_t USART0_config;
extern const adc_config_t ADC0configStruct;
extern const adc_conv_seq_config_t ADC0ConvSeqAConfigStruct;
extern const sctimer_config_t SCT0_initConfig;
extern const sctimer_pwm_signal_param_t SCT0_pwmSignalsConfig[2];
extern uint32_t SCT0_pwmEvent[2];
extern const mrt_config_t MRT0_config;

/***********************************************************************************************************************
 * Callback functions
 **********************************************************************************************************************/
/* Multiple callback functions declaration */
extern void Ultrasonic_Callback(uint32_t flags);
extern void EncoderRightCallback(uint32_t flags);
extern void EncoderLeftCallback(uint32_t flags);
extern ctimer_callback_t CTIMER0_callback[];

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/

void BOARD_InitPeripherals(void);

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void);

#if defined(__cplusplus)
}
#endif

#endif /* _PERIPHERALS_H_ */