/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v13.0
processor: LPC845
package_id: LPC845M301JBD48
mcu_data: ksdk2_0
processor_version: 13.0.1
board: LPC845BREAKOUT
external_user_signals: {}
pin_labels:
- {pin_num: '2', pin_signal: PIO0_13/ADC_10, label: 'CN1[26]/PIO0_13/ADC_10', identifier: UltraSonicTrig}
- {pin_num: '7', pin_signal: PIO0_28/WKTCLKIN, label: 'CN1[14]/PIO0_28/WKTCLKIN', identifier: Servo}
- {pin_num: '12', pin_signal: PIO0_11/I2C0_SDA, label: 'CN1[24]/PIO0_11/I2C0_SDA', identifier: Encoder;Encoder2;Encoder1}
- {pin_num: '13', pin_signal: PIO0_10/I2C0_SCL, label: 'CN1[23]/PIO0_10/I2C0_SCL', identifier: Motor1IN2;Motor2IN2}
- {pin_num: '15', pin_signal: PIO0_16, label: 'CN1[1]/PIO0_16', identifier: Motor2PWM;Motor1PWM;Motor1EN}
- {pin_num: '17', pin_signal: PIO0_27, label: 'CN1[13]/PIO0_27', identifier: Bluetooth_Tx}
- {pin_num: '18', pin_signal: PIO0_26, label: 'CN1[12]/PIO0_26', identifier: Bluetooth_Rx}
- {pin_num: '22', pin_signal: PIO0_15, label: 'CN1[28]/PIO0_15', identifier: HC05_Rising;Hc05_Falling;Ultrasonic_Rising;Ultrasonic_Falling;Ultrasonic_Echo;UltraSonicEcho}
- {pin_num: '25', pin_signal: PIO0_9/XTALOUT, label: 'CN1[18]/CN1[22]/PIO0_9/XTALOUT', identifier: Motor2PWM;Motor2EN}
- {pin_num: '26', pin_signal: PIO0_8/XTALIN, label: 'CN1[19]/CN1[21]/PIO0_8/XTALIN', identifier: Motor2Dir;Motor2IN1}
- {pin_num: '33', pin_signal: PIO0_7/ADC_0, label: 'CN1[32]/RV1/PIO0_7/ADC_0', identifier: OpticSensor1;OpticSensor0;potmeter}
- {pin_num: '34', pin_signal: PIO0_6/ADC_1/ACMPVREF, label: 'CN1[33]/PIO0_6/ADC_1/ACMPVREF', identifier: OpticSensor1;OpticSensor0}
- {pin_num: '36', pin_signal: PIO0_0/ACMP_I1, label: 'CN1[39]/PIO0_0/ACMP_I1/TDO', identifier: IR_LED_EN}
- {pin_num: '37', pin_signal: PIO0_14/ACMP_I3/ADC_2, label: 'CN1[27]/PIO0_14/ACMP_I3/ADC_2', identifier: UltraSonicTrig;OpticSensor3;OpticSensor2;OpticSensor1}
- {pin_num: '38', pin_signal: PIO0_29/DACOUT_1, label: 'CN1[15]/PIO0_29/DACOUT_1', identifier: Encoder1}
- {pin_num: '39', pin_signal: PIO0_23/ADC_3/ACMP_I4, label: 'CN1[8]/PIO0_23/ADC_3/ACMP_I4', identifier: OpticSensor3;OpticSensor2}
- {pin_num: '43', pin_signal: PIO0_22/ADC_4, label: 'CN1[7]/PIO0_22/ADC_4', identifier: Encoder2}
- {pin_num: '44', pin_signal: PIO0_21/ADC_5, label: 'CN1[6]/PIO0_21/ADC_5', identifier: OpticSensor3}
- {pin_num: '47', pin_signal: PIO0_18/ADC_8, label: 'CN1[3]/PIO0_18/ADC_8', identifier: Motor1IN3;Motor1IN2}
- {pin_num: '48', pin_signal: PIO0_17/ADC_9/DACOUT_0, label: 'CN1[2]/PIO0_17/ADC_9/DACOUT_0', identifier: Motor1Dir;Motor1IN1}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_gpio.h"
#include "fsl_iocon.h"
#include "fsl_swm.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
    BOARD_InitLEDsPins();
    BOARD_InitDEBUG_UARTPins();
    BOARD_InitSWD_DEBUGPins();
    BOARD_InitBUTTONsPins();
    BOARD_InitCAPTPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '18', peripheral: USART1, signal: RXD, pin_signal: PIO0_26}
  - {pin_num: '17', peripheral: USART1, signal: TXD, pin_signal: PIO0_27}
  - {pin_num: '22', peripheral: CTIMER0, signal: 'CAPTURE, 0', pin_signal: PIO0_15, identifier: UltraSonicEcho}
  - {pin_num: '33', peripheral: ADC0, signal: 'CH, 0', pin_signal: PIO0_7/ADC_0, identifier: potmeter}
  - {pin_num: '34', peripheral: ADC0, signal: 'CH, 1', pin_signal: PIO0_6/ADC_1/ACMPVREF, identifier: OpticSensor0}
  - {pin_num: '37', peripheral: ADC0, signal: 'CH, 2', pin_signal: PIO0_14/ACMP_I3/ADC_2, identifier: OpticSensor1}
  - {pin_num: '39', peripheral: ADC0, signal: 'CH, 3', pin_signal: PIO0_23/ADC_3/ACMP_I4, identifier: OpticSensor2}
  - {pin_num: '2', peripheral: GPIO, signal: 'PIO0, 13', pin_signal: PIO0_13/ADC_10, direction: OUTPUT}
  - {pin_num: '15', peripheral: SCT0, signal: 'OUT, 0', pin_signal: PIO0_16, identifier: Motor1EN}
  - {pin_num: '25', peripheral: SCT0, signal: 'OUT, 1', pin_signal: PIO0_9/XTALOUT, identifier: Motor2EN}
  - {pin_num: '48', peripheral: GPIO, signal: 'PIO0, 17', pin_signal: PIO0_17/ADC_9/DACOUT_0, identifier: Motor1IN1, direction: OUTPUT}
  - {pin_num: '47', peripheral: GPIO, signal: 'PIO0, 18', pin_signal: PIO0_18/ADC_8, identifier: Motor1IN2, direction: OUTPUT}
  - {pin_num: '26', peripheral: GPIO, signal: 'PIO0, 8', pin_signal: PIO0_8/XTALIN, identifier: Motor2IN1, direction: OUTPUT}
  - {pin_num: '13', peripheral: GPIO, signal: 'PIO0, 10', pin_signal: PIO0_10/I2C0_SCL, identifier: Motor2IN2, direction: OUTPUT}
  - {pin_num: '12', peripheral: CTIMER0, signal: 'CAPTURE, 1', pin_signal: PIO0_11/I2C0_SDA, identifier: Encoder1}
  - {pin_num: '43', peripheral: CTIMER0, signal: 'CAPTURE, 2', pin_signal: PIO0_22/ADC_4}
  - {pin_num: '44', peripheral: ADC0, signal: 'CH, 5', pin_signal: PIO0_21/ADC_5, mode: pullUp}
  - {pin_num: '36', peripheral: GPIO, signal: 'PIO0, 0', pin_signal: PIO0_0/ACMP_I1, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitPins(void)
{
    /* Enables clock for IOCON.: enable */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables clock for switch matrix.: enable */
    CLOCK_EnableClock(kCLOCK_Swm);
    /* Enables the clock for the GPIO0 module */
    CLOCK_EnableClock(kCLOCK_Gpio0);

    gpio_pin_config_t gpio0_pin0_0 = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_0 (pin )  */
    GPIO_PinInit(GPIO, 0U, 0U, &gpio0_pin0_0);

    gpio_pin_config_t gpio0_pin0_8 = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_8 (pin )  */
    GPIO_PinInit(GPIO, 0U, 8U, &gpio0_pin0_8);

    gpio_pin_config_t gpio0_pin0_10 = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_10 (pin )  */
    GPIO_PinInit(GPIO, 0U, 10U, &gpio0_pin0_10);

    gpio_pin_config_t UltraSonicTrig_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_13 (pin 2)  */
    GPIO_PinInit(BOARD_INITPINS_UltraSonicTrig_GPIO, BOARD_INITPINS_UltraSonicTrig_PORT, BOARD_INITPINS_UltraSonicTrig_PIN, &UltraSonicTrig_config);

    gpio_pin_config_t gpio0_pin0_17 = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_17 (pin )  */
    GPIO_PinInit(GPIO, 0U, 17U, &gpio0_pin0_17);

    gpio_pin_config_t gpio0_pin0_18 = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_18 (pin )  */
    GPIO_PinInit(GPIO, 0U, 18U, &gpio0_pin0_18);

    IOCON->PIO[27] = ((IOCON->PIO[27] &
                       /* Mask bits to zero which are setting */
                       (~(IOCON_PIO_MODE_MASK)))

                      /* Selects function mode (on-chip pull-up/pull-down resistor control).: Pull-up. Pull-up resistor
                       * enabled. */
                      | IOCON_PIO_MODE(PIO0_21_MODE_PULL_UP));

    /* USART1_TXD connect to P0_27 */
    SWM_SetMovablePinSelect(SWM0, kSWM_USART1_TXD, kSWM_PortPin_P0_27);

    /* USART1_RXD connect to P0_26 */
    SWM_SetMovablePinSelect(SWM0, kSWM_USART1_RXD, kSWM_PortPin_P0_26);

    /* TimerCaptureChannel0 connect to P0_15 */
    SWM_SetMovablePinSelect(SWM0, kSWM_T0_CAP_CHN0, kSWM_PortPin_P0_15);

    /* TimerCaptureChannel1 connect to P0_11 */
    SWM_SetMovablePinSelect(SWM0, kSWM_T0_CAP_CHN1, kSWM_PortPin_P0_11);

    /* TimerCaptureChannel2 connect to P0_22 */
    SWM_SetMovablePinSelect(SWM0, kSWM_T0_CAP_CHN2, kSWM_PortPin_P0_22);

    /* SCT_OUT0 connect to P0_16 */
    SWM_SetMovablePinSelect(SWM0, kSWM_SCT_OUT0, kSWM_PortPin_P0_16);

    /* SCT_OUT1 connect to P0_9 */
    SWM_SetMovablePinSelect(SWM0, kSWM_SCT_OUT1, kSWM_PortPin_P0_9);

    /* ADC_CHN0 connect to P0_7 */
    SWM_SetFixedPinSelect(SWM0, kSWM_ADC_CHN0, true);

    /* ADC_CHN1 connect to P0_6 */
    SWM_SetFixedPinSelect(SWM0, kSWM_ADC_CHN1, true);

    /* ADC_CHN2 connect to P0_14 */
    SWM_SetFixedPinSelect(SWM0, kSWM_ADC_CHN2, true);

    /* ADC_CHN3 connect to P0_23 */
    SWM_SetFixedPinSelect(SWM0, kSWM_ADC_CHN3, true);

    /* ADC_CHN5 connect to P0_21 */
    SWM_SetFixedPinSelect(SWM0, kSWM_ADC_CHN5, true);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitLEDsPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '11', peripheral: GPIO, signal: 'PIO1, 0', pin_signal: PIO1_0/CAPT_X1, direction: OUTPUT, gpio_init_state: 'true', mode: inactive, invert: disabled,
    hysteresis: enabled, opendrain: disabled, smode: bypass, clkdiv: div0}
  - {pin_num: '14', peripheral: GPIO, signal: 'PIO1, 1', pin_signal: PIO1_1/CAPT_X2, direction: OUTPUT, gpio_init_state: 'true', mode: inactive, invert: disabled,
    hysteresis: enabled, opendrain: disabled, smode: bypass, clkdiv: div0}
  - {pin_num: '16', peripheral: GPIO, signal: 'PIO1, 2', pin_signal: PIO1_2/CAPT_X3, direction: OUTPUT, gpio_init_state: 'true', mode: inactive, invert: disabled,
    hysteresis: enabled, opendrain: disabled, smode: bypass, clkdiv: div0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitLEDsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitLEDsPins(void)
{
    /* Enables clock for IOCON.: enable */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables the clock for the GPIO1 module */
    CLOCK_EnableClock(kCLOCK_Gpio1);

    gpio_pin_config_t LED_GREEN_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U,
    };
    /* Initialize GPIO functionality on pin PIO1_0 (pin 11)  */
    GPIO_PinInit(BOARD_INITLEDSPINS_LED_GREEN_GPIO, BOARD_INITLEDSPINS_LED_GREEN_PORT, BOARD_INITLEDSPINS_LED_GREEN_PIN, &LED_GREEN_config);

    gpio_pin_config_t LED_BLUE_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U,
    };
    /* Initialize GPIO functionality on pin PIO1_1 (pin 14)  */
    GPIO_PinInit(BOARD_INITLEDSPINS_LED_BLUE_GPIO, BOARD_INITLEDSPINS_LED_BLUE_PORT, BOARD_INITLEDSPINS_LED_BLUE_PIN, &LED_BLUE_config);

    gpio_pin_config_t LED_RED_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U,
    };
    /* Initialize GPIO functionality on pin PIO1_2 (pin 16)  */
    GPIO_PinInit(BOARD_INITLEDSPINS_LED_RED_GPIO, BOARD_INITLEDSPINS_LED_RED_PORT, BOARD_INITLEDSPINS_LED_RED_PIN, &LED_RED_config);

    const uint32_t LED_GREEN = (/* No addition pin function */
                                IOCON_PIO_MODE_INACT |
                                /* Enable hysteresis */
                                IOCON_PIO_HYS_EN |
                                /* Input not invert */
                                IOCON_PIO_INV_DI |
                                /* Disables Open-drain function */
                                IOCON_PIO_OD_DI |
                                /* Bypass input filter */
                                IOCON_PIO_SMODE_BYPASS |
                                /* IOCONCLKDIV0 */
                                IOCON_PIO_CLKDIV0);
    /* PIO1 PIN0 (coords: 11) is configured as GPIO, PIO1, 0. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO1_0, LED_GREEN);

    const uint32_t LED_BLUE = (/* No addition pin function */
                               IOCON_PIO_MODE_INACT |
                               /* Enable hysteresis */
                               IOCON_PIO_HYS_EN |
                               /* Input not invert */
                               IOCON_PIO_INV_DI |
                               /* Disables Open-drain function */
                               IOCON_PIO_OD_DI |
                               /* Bypass input filter */
                               IOCON_PIO_SMODE_BYPASS |
                               /* IOCONCLKDIV0 */
                               IOCON_PIO_CLKDIV0);
    /* PIO1 PIN1 (coords: 14) is configured as GPIO, PIO1, 1. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO1_1, LED_BLUE);

    const uint32_t LED_RED = (/* No addition pin function */
                              IOCON_PIO_MODE_INACT |
                              /* Enable hysteresis */
                              IOCON_PIO_HYS_EN |
                              /* Input not invert */
                              IOCON_PIO_INV_DI |
                              /* Disables Open-drain function */
                              IOCON_PIO_OD_DI |
                              /* Bypass input filter */
                              IOCON_PIO_SMODE_BYPASS |
                              /* IOCONCLKDIV0 */
                              IOCON_PIO_CLKDIV0);
    /* PIO1 PIN2 (coords: 16) is configured as GPIO, PIO1, 2. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO1_2, LED_RED);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitDEBUG_UARTPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '19', peripheral: USART0, signal: TXD, pin_signal: PIO0_25, mode: pullUp, invert: disabled, hysteresis: enabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
  - {pin_num: '20', peripheral: USART0, signal: RXD, pin_signal: PIO0_24, mode: pullUp, invert: disabled, hysteresis: enabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitDEBUG_UARTPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitDEBUG_UARTPins(void)
{
    /* Enables clock for IOCON.: enable */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables clock for switch matrix.: enable */
    CLOCK_EnableClock(kCLOCK_Swm);

    const uint32_t DEBUG_UART_RX = (/* Selects pull-up function */
                                    IOCON_PIO_MODE_PULLUP |
                                    /* Enable hysteresis */
                                    IOCON_PIO_HYS_EN |
                                    /* Input not invert */
                                    IOCON_PIO_INV_DI |
                                    /* Disables Open-drain function */
                                    IOCON_PIO_OD_DI |
                                    /* Bypass input filter */
                                    IOCON_PIO_SMODE_BYPASS |
                                    /* IOCONCLKDIV0 */
                                    IOCON_PIO_CLKDIV0);
    /* PIO0 PIN24 (coords: 20) is configured as USART0, RXD. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_24, DEBUG_UART_RX);

    const uint32_t DEBUG_UART_TX = (/* Selects pull-up function */
                                    IOCON_PIO_MODE_PULLUP |
                                    /* Enable hysteresis */
                                    IOCON_PIO_HYS_EN |
                                    /* Input not invert */
                                    IOCON_PIO_INV_DI |
                                    /* Disables Open-drain function */
                                    IOCON_PIO_OD_DI |
                                    /* Bypass input filter */
                                    IOCON_PIO_SMODE_BYPASS |
                                    /* IOCONCLKDIV0 */
                                    IOCON_PIO_CLKDIV0);
    /* PIO0 PIN25 (coords: 19) is configured as USART0, TXD. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_25, DEBUG_UART_TX);

    /* USART0_TXD connect to P0_25 */
    SWM_SetMovablePinSelect(SWM0, kSWM_USART0_TXD, kSWM_PortPin_P0_25);

    /* USART0_RXD connect to P0_24 */
    SWM_SetMovablePinSelect(SWM0, kSWM_USART0_RXD, kSWM_PortPin_P0_24);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitSWD_DEBUGPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '10', peripheral: SWD, signal: SWDIO, pin_signal: SWDIO/PIO0_2, mode: pullUp, invert: disabled, hysteresis: enabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
  - {pin_num: '8', peripheral: SWD, signal: SWCLK, pin_signal: SWCLK/PIO0_3, mode: pullUp, invert: disabled, hysteresis: enabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
  - {pin_num: '5', peripheral: SYSCON, signal: RESETN, pin_signal: RESETN/PIO0_5, mode: pullUp, invert: disabled, hysteresis: enabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitSWD_DEBUGPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitSWD_DEBUGPins(void)
{
    /* Enables clock for IOCON.: enable */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables clock for switch matrix.: enable */
    CLOCK_EnableClock(kCLOCK_Swm);

    const uint32_t IOCON_INDEX_PIO0_2_config = (/* Selects pull-up function */
                                                IOCON_PIO_MODE_PULLUP |
                                                /* Enable hysteresis */
                                                IOCON_PIO_HYS_EN |
                                                /* Input not invert */
                                                IOCON_PIO_INV_DI |
                                                /* Disables Open-drain function */
                                                IOCON_PIO_OD_DI |
                                                /* Bypass input filter */
                                                IOCON_PIO_SMODE_BYPASS |
                                                /* IOCONCLKDIV0 */
                                                IOCON_PIO_CLKDIV0);
    /* PIO0 PIN2 (coords: 10) is configured as SWD, SWDIO. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_2, IOCON_INDEX_PIO0_2_config);

    const uint32_t IOCON_INDEX_PIO0_3_config = (/* Selects pull-up function */
                                                IOCON_PIO_MODE_PULLUP |
                                                /* Enable hysteresis */
                                                IOCON_PIO_HYS_EN |
                                                /* Input not invert */
                                                IOCON_PIO_INV_DI |
                                                /* Disables Open-drain function */
                                                IOCON_PIO_OD_DI |
                                                /* Bypass input filter */
                                                IOCON_PIO_SMODE_BYPASS |
                                                /* IOCONCLKDIV0 */
                                                IOCON_PIO_CLKDIV0);
    /* PIO0 PIN3 (coords: 8) is configured as SWD, SWCLK. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_3, IOCON_INDEX_PIO0_3_config);

    const uint32_t K2 = (/* Selects pull-up function */
                         IOCON_PIO_MODE_PULLUP |
                         /* Enable hysteresis */
                         IOCON_PIO_HYS_EN |
                         /* Input not invert */
                         IOCON_PIO_INV_DI |
                         /* Disables Open-drain function */
                         IOCON_PIO_OD_DI |
                         /* Bypass input filter */
                         IOCON_PIO_SMODE_BYPASS |
                         /* IOCONCLKDIV0 */
                         IOCON_PIO_CLKDIV0);
    /* PIO0 PIN5 (coords: 5) is configured as SYSCON, RESETN. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_5, K2);

    /* SWCLK connect to P0_3 */
    SWM_SetFixedPinSelect(SWM0, kSWM_SWCLK, true);

    /* SWDIO connect to P0_2 */
    SWM_SetFixedPinSelect(SWM0, kSWM_SWDIO, true);

    /* RESETN connect to P0_5 */
    SWM_SetFixedPinSelect(SWM0, kSWM_RESETN, true);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitBUTTONsPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '6', peripheral: GPIO, signal: 'PIO0, 4', pin_signal: PIO0_4/ADC_11, direction: INPUT, mode: pullUp, invert: disabled, hysteresis: enabled, opendrain: disabled,
    smode: bypass, clkdiv: div0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBUTTONsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitBUTTONsPins(void)
{
    /* Enables clock for IOCON.: enable */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables the clock for the GPIO0 module */
    CLOCK_EnableClock(kCLOCK_Gpio0);

    gpio_pin_config_t K3_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_4 (pin 6)  */
    GPIO_PinInit(BOARD_INITBUTTONSPINS_K3_GPIO, BOARD_INITBUTTONSPINS_K3_PORT, BOARD_INITBUTTONSPINS_K3_PIN, &K3_config);

    const uint32_t K3 = (/* Selects pull-up function */
                         IOCON_PIO_MODE_PULLUP |
                         /* Enable hysteresis */
                         IOCON_PIO_HYS_EN |
                         /* Input not invert */
                         IOCON_PIO_INV_DI |
                         /* Disables Open-drain function */
                         IOCON_PIO_OD_DI |
                         /* Bypass input filter */
                         IOCON_PIO_SMODE_BYPASS |
                         /* IOCONCLKDIV0 */
                         IOCON_PIO_CLKDIV0);
    /* PIO0 PIN4 (coords: 6) is configured as GPIO, PIO0, 4. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_4, K3);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitCAPTPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '1', peripheral: CAPT, signal: CAPTYL, pin_signal: PIO1_8/CAPT_YL, mode: inactive, invert: disabled, hysteresis: enabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
  - {pin_num: '3', peripheral: CAPT, signal: CAPTYH, pin_signal: PIO1_9/CAPT_YH, mode: inactive, invert: disabled, hysteresis: enabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
  - {pin_num: '9', peripheral: CAPT, signal: 'CAPTX, 0', pin_signal: PIO0_31/CAPT_X0, mode: inactive, invert: disabled, hysteresis: enabled, opendrain: disabled,
    smode: bypass, clkdiv: div0}
  - {pin_num: '42', peripheral: ACMP, signal: ACMP_IN5, pin_signal: PIO0_30/ACMP_I5, mode: inactive, invert: disabled, hysteresis: enabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitCAPTPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitCAPTPins(void)
{
    /* Enables clock for IOCON.: enable */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables clock for switch matrix.: enable */
    CLOCK_EnableClock(kCLOCK_Swm);

    const uint32_t CAPY_R = (/* No addition pin function */
                             IOCON_PIO_MODE_INACT |
                             /* Enable hysteresis */
                             IOCON_PIO_HYS_EN |
                             /* Input not invert */
                             IOCON_PIO_INV_DI |
                             /* Disables Open-drain function */
                             IOCON_PIO_OD_DI |
                             /* Bypass input filter */
                             IOCON_PIO_SMODE_BYPASS |
                             /* IOCONCLKDIV0 */
                             IOCON_PIO_CLKDIV0);
    /* PIO0 PIN30 (coords: 42) is configured as ACMP, ACMP_IN5. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_30, CAPY_R);

    const uint32_t CAPX = (/* No addition pin function */
                           IOCON_PIO_MODE_INACT |
                           /* Enable hysteresis */
                           IOCON_PIO_HYS_EN |
                           /* Input not invert */
                           IOCON_PIO_INV_DI |
                           /* Disables Open-drain function */
                           IOCON_PIO_OD_DI |
                           /* Bypass input filter */
                           IOCON_PIO_SMODE_BYPASS |
                           /* IOCONCLKDIV0 */
                           IOCON_PIO_CLKDIV0);
    /* PIO0 PIN31 (coords: 9) is configured as CAPT, CAPTX, 0. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_31, CAPX);

    const uint32_t CAPY_LOW = (/* No addition pin function */
                               IOCON_PIO_MODE_INACT |
                               /* Enable hysteresis */
                               IOCON_PIO_HYS_EN |
                               /* Input not invert */
                               IOCON_PIO_INV_DI |
                               /* Disables Open-drain function */
                               IOCON_PIO_OD_DI |
                               /* Bypass input filter */
                               IOCON_PIO_SMODE_BYPASS |
                               /* IOCONCLKDIV0 */
                               IOCON_PIO_CLKDIV0);
    /* PIO1 PIN8 (coords: 1) is configured as CAPT, CAPTYL. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO1_8, CAPY_LOW);

    const uint32_t CAPY_HIGH = (/* No addition pin function */
                                IOCON_PIO_MODE_INACT |
                                /* Enable hysteresis */
                                IOCON_PIO_HYS_EN |
                                /* Input not invert */
                                IOCON_PIO_INV_DI |
                                /* Disables Open-drain function */
                                IOCON_PIO_OD_DI |
                                /* Bypass input filter */
                                IOCON_PIO_SMODE_BYPASS |
                                /* IOCONCLKDIV0 */
                                IOCON_PIO_CLKDIV0);
    /* PIO1 PIN9 (coords: 3) is configured as CAPT, CAPTYH. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO1_9, CAPY_HIGH);

    /* ACMP_INPUT5 connect to P0_30 */
    SWM_SetFixedPinSelect(SWM0, kSWM_ACMP_INPUT5, true);

    /* CAPT_X0 connect to P0_31 */
    SWM_SetFixedPinSelect(SWM0, kSWM_CAPT_X0, true);

    /* CAPT_YL connect to P1_8 */
    SWM_SetFixedPinSelect(SWM0, kSWM_CAPT_YL, true);

    /* CAPT_YH connect to P1_9 */
    SWM_SetFixedPinSelect(SWM0, kSWM_CAPT_YH, true);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
