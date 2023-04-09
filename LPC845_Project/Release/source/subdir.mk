################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/MRT.c \
../source/PID.c \
../source/SysTimer.c \
../source/bluetooth.c \
../source/car.c \
../source/direction.c \
../source/distance.c \
../source/encoder.c \
../source/main.c \
../source/motor.c \
../source/mtb.c \
../source/optic.c \
../source/semihost_hardfault.c \
../source/state.c \
../source/sys.c \
../source/ultrasonic.c 

C_DEPS += \
./source/MRT.d \
./source/PID.d \
./source/SysTimer.d \
./source/bluetooth.d \
./source/car.d \
./source/direction.d \
./source/distance.d \
./source/encoder.d \
./source/main.d \
./source/motor.d \
./source/mtb.d \
./source/optic.d \
./source/semihost_hardfault.d \
./source/state.d \
./source/sys.d \
./source/ultrasonic.d 

OBJS += \
./source/MRT.o \
./source/PID.o \
./source/SysTimer.o \
./source/bluetooth.o \
./source/car.o \
./source/direction.o \
./source/distance.o \
./source/encoder.o \
./source/main.o \
./source/motor.o \
./source/mtb.o \
./source/optic.o \
./source/semihost_hardfault.o \
./source/state.o \
./source/sys.o \
./source/ultrasonic.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_LPC845M301JBD48 -DCPU_LPC845M301JBD48_cm0plus -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -D__REDLIB__ -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\drivers" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\CMSIS" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\device" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\component\uart" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\utilities" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\board" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\drivers" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\CMSIS" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\device" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\component\uart" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\utilities" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\board" -I"C:\Users\plasz\Documents\MCUXpressoIDE_11.7.0_9198\workspace\onlab\LPC845_Project\source" -Os -fno-common -g -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/MRT.d ./source/MRT.o ./source/PID.d ./source/PID.o ./source/SysTimer.d ./source/SysTimer.o ./source/bluetooth.d ./source/bluetooth.o ./source/car.d ./source/car.o ./source/direction.d ./source/direction.o ./source/distance.d ./source/distance.o ./source/encoder.d ./source/encoder.o ./source/main.d ./source/main.o ./source/motor.d ./source/motor.o ./source/mtb.d ./source/mtb.o ./source/optic.d ./source/optic.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o ./source/state.d ./source/state.o ./source/sys.d ./source/sys.o ./source/ultrasonic.d ./source/ultrasonic.o

.PHONY: clean-source

