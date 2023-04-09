################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/startup_lpc845.c 

C_DEPS += \
./startup/startup_lpc845.d 

OBJS += \
./startup/startup_lpc845.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_LPC845M301JBD48 -DCPU_LPC845M301JBD48_cm0plus -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -D__REDLIB__ -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\drivers" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\CMSIS" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\device" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\component\uart" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\utilities" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\board" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\drivers" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\CMSIS" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\device" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\component\uart" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\utilities" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\board" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\source" -Os -fno-common -g -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_lpc845.d ./startup/startup_lpc845.o

.PHONY: clean-startup

