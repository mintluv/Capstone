################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ap/ap.c 

OBJS += \
./src/ap/ap.o 

C_DEPS += \
./src/ap/ap.d 


# Each subdirectory must supply rules for building sources it contributes
src/ap/%.o src/ap/%.su src/ap/%.cyclo: ../src/ap/%.c src/ap/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32L432xx -c -I"C:/capstone/L432/src" -I"C:/capstone/L432/src/ap" -I"C:/capstone/L432/src/bsp" -I"C:/capstone/L432/src/common" -I"C:/capstone/L432/src/hw" -I"C:/capstone/L432/src/lib" -I"C:/capstone/L432/src/lib/Cube_L432k/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/capstone/L432/src/lib/Cube_L432k/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/capstone/L432/src/lib/Cube_L432k/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-ap

clean-src-2f-ap:
	-$(RM) ./src/ap/ap.cyclo ./src/ap/ap.d ./src/ap/ap.o ./src/ap/ap.su

.PHONY: clean-src-2f-ap

