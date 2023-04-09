################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/dsfsdfa.c \
../source/mtb.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/dsfsdfa.d \
./source/mtb.d \
./source/semihost_hardfault.d 

OBJS += \
./source/dsfsdfa.o \
./source/mtb.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC845M301JBD48 -DCPU_LPC845M301JBD48_cm0plus -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\dsfsdfa\board" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\dsfsdfa\source" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\dsfsdfa\drivers" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\dsfsdfa\CMSIS" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\dsfsdfa\device" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\dsfsdfa\component\uart" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\dsfsdfa\utilities" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/dsfsdfa.d ./source/dsfsdfa.o ./source/mtb.d ./source/mtb.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

