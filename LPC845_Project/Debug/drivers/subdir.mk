################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_adc.c \
../drivers/fsl_capt.c \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_common_arm.c \
../drivers/fsl_ctimer.c \
../drivers/fsl_gpio.c \
../drivers/fsl_mrt.c \
../drivers/fsl_power.c \
../drivers/fsl_reset.c \
../drivers/fsl_sctimer.c \
../drivers/fsl_swm.c \
../drivers/fsl_usart.c 

C_DEPS += \
./drivers/fsl_adc.d \
./drivers/fsl_capt.d \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_common_arm.d \
./drivers/fsl_ctimer.d \
./drivers/fsl_gpio.d \
./drivers/fsl_mrt.d \
./drivers/fsl_power.d \
./drivers/fsl_reset.d \
./drivers/fsl_sctimer.d \
./drivers/fsl_swm.d \
./drivers/fsl_usart.d 

OBJS += \
./drivers/fsl_adc.o \
./drivers/fsl_capt.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_common_arm.o \
./drivers/fsl_ctimer.o \
./drivers/fsl_gpio.o \
./drivers/fsl_mrt.o \
./drivers/fsl_power.o \
./drivers/fsl_reset.o \
./drivers/fsl_sctimer.o \
./drivers/fsl_swm.o \
./drivers/fsl_usart.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC845M301JBD48 -DCPU_LPC845M301JBD48_cm0plus -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\drivers" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\CMSIS" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\device" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\component\uart" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\utilities" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\board" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\drivers" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\CMSIS" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\device" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\component\uart" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\utilities" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\board" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\source" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/fsl_adc.d ./drivers/fsl_adc.o ./drivers/fsl_capt.d ./drivers/fsl_capt.o ./drivers/fsl_clock.d ./drivers/fsl_clock.o ./drivers/fsl_common.d ./drivers/fsl_common.o ./drivers/fsl_common_arm.d ./drivers/fsl_common_arm.o ./drivers/fsl_ctimer.d ./drivers/fsl_ctimer.o ./drivers/fsl_gpio.d ./drivers/fsl_gpio.o ./drivers/fsl_mrt.d ./drivers/fsl_mrt.o ./drivers/fsl_power.d ./drivers/fsl_power.o ./drivers/fsl_reset.d ./drivers/fsl_reset.o ./drivers/fsl_sctimer.d ./drivers/fsl_sctimer.o ./drivers/fsl_swm.d ./drivers/fsl_swm.o ./drivers/fsl_usart.d ./drivers/fsl_usart.o

.PHONY: clean-drivers

