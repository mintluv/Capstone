################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/Cube_L432k/USB_DEVICE/Target/usbd_conf.c 

OBJS += \
./src/lib/Cube_L432k/USB_DEVICE/Target/usbd_conf.o 

C_DEPS += \
./src/lib/Cube_L432k/USB_DEVICE/Target/usbd_conf.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/Cube_L432k/USB_DEVICE/Target/%.o src/lib/Cube_L432k/USB_DEVICE/Target/%.su src/lib/Cube_L432k/USB_DEVICE/Target/%.cyclo: ../src/lib/Cube_L432k/USB_DEVICE/Target/%.c src/lib/Cube_L432k/USB_DEVICE/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32L432xx -c -I"C:/capstone/L432/src" -I"C:/capstone/L432/src/ap" -I"C:/capstone/L432/src/bsp" -I"C:/capstone/L432/src/common" -I"C:/capstone/L432/src/hw" -I"C:/capstone/L432/src/lib" -I"C:/capstone/L432/src/lib/Cube_L432k/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/capstone/L432/src/lib/Cube_L432k/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/capstone/L432/src/lib/Cube_L432k/Drivers/CMSIS/Include" -I"C:/capstone/L432/src/common/hw/include" -I"C:/capstone/L432/src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/capstone/L432/src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/capstone/L432/src/lib/Cube_L432k/USB_DEVICE/App" -I"C:/capstone/L432/src/lib/Cube_L432k/USB_DEVICE/Target" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-lib-2f-Cube_L432k-2f-USB_DEVICE-2f-Target

clean-src-2f-lib-2f-Cube_L432k-2f-USB_DEVICE-2f-Target:
	-$(RM) ./src/lib/Cube_L432k/USB_DEVICE/Target/usbd_conf.cyclo ./src/lib/Cube_L432k/USB_DEVICE/Target/usbd_conf.d ./src/lib/Cube_L432k/USB_DEVICE/Target/usbd_conf.o ./src/lib/Cube_L432k/USB_DEVICE/Target/usbd_conf.su

.PHONY: clean-src-2f-lib-2f-Cube_L432k-2f-USB_DEVICE-2f-Target
