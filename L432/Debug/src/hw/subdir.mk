################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hw/hw.c 

OBJS += \
./src/hw/hw.o 

C_DEPS += \
./src/hw/hw.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw/%.o src/hw/%.su src/hw/%.cyclo: ../src/hw/%.c src/hw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32L432xx -c -I"C:/Capstone/L432/src" -I"C:/Capstone/L432/src/ap" -I"C:/Capstone/L432/src/bsp" -I"C:/Capstone/L432/src/common" -I"C:/Capstone/L432/src/hw" -I"C:/Capstone/L432/src/lib" -I"C:/Capstone/L432/src/lib/Cube_L432k/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Capstone/L432/src/lib/Cube_L432k/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Capstone/L432/src/lib/Cube_L432k/Drivers/CMSIS/Include" -I"C:/Capstone/L432/src/common/hw/include" -I"C:/Capstone/L432/src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/Capstone/L432/src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Capstone/L432/src/lib/Cube_L432k/USB_DEVICE/App" -I"C:/Capstone/L432/src/lib/Cube_L432k/USB_DEVICE/Target" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-hw

clean-src-2f-hw:
	-$(RM) ./src/hw/hw.cyclo ./src/hw/hw.d ./src/hw/hw.o ./src/hw/hw.su

.PHONY: clean-src-2f-hw

