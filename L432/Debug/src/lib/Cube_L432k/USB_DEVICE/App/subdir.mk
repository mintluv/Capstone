################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/Cube_L432k/USB_DEVICE/App/usb_device.c \
../src/lib/Cube_L432k/USB_DEVICE/App/usbd_cdc_if.c \
../src/lib/Cube_L432k/USB_DEVICE/App/usbd_desc.c 

OBJS += \
./src/lib/Cube_L432k/USB_DEVICE/App/usb_device.o \
./src/lib/Cube_L432k/USB_DEVICE/App/usbd_cdc_if.o \
./src/lib/Cube_L432k/USB_DEVICE/App/usbd_desc.o 

C_DEPS += \
./src/lib/Cube_L432k/USB_DEVICE/App/usb_device.d \
./src/lib/Cube_L432k/USB_DEVICE/App/usbd_cdc_if.d \
./src/lib/Cube_L432k/USB_DEVICE/App/usbd_desc.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/Cube_L432k/USB_DEVICE/App/%.o src/lib/Cube_L432k/USB_DEVICE/App/%.su src/lib/Cube_L432k/USB_DEVICE/App/%.cyclo: ../src/lib/Cube_L432k/USB_DEVICE/App/%.c src/lib/Cube_L432k/USB_DEVICE/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32L432xx -c -I"C:/Capstone/L432/src" -I"C:/Capstone/L432/src/ap" -I"C:/Capstone/L432/src/bsp" -I"C:/Capstone/L432/src/common" -I"C:/Capstone/L432/src/hw" -I"C:/Capstone/L432/src/lib" -I"C:/Capstone/L432/src/lib/Cube_L432k/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Capstone/L432/src/lib/Cube_L432k/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Capstone/L432/src/lib/Cube_L432k/Drivers/CMSIS/Include" -I"C:/Capstone/L432/src/common/hw/include" -I"C:/Capstone/L432/src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/Capstone/L432/src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Capstone/L432/src/lib/Cube_L432k/USB_DEVICE/App" -I"C:/Capstone/L432/src/lib/Cube_L432k/USB_DEVICE/Target" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-lib-2f-Cube_L432k-2f-USB_DEVICE-2f-App

clean-src-2f-lib-2f-Cube_L432k-2f-USB_DEVICE-2f-App:
	-$(RM) ./src/lib/Cube_L432k/USB_DEVICE/App/usb_device.cyclo ./src/lib/Cube_L432k/USB_DEVICE/App/usb_device.d ./src/lib/Cube_L432k/USB_DEVICE/App/usb_device.o ./src/lib/Cube_L432k/USB_DEVICE/App/usb_device.su ./src/lib/Cube_L432k/USB_DEVICE/App/usbd_cdc_if.cyclo ./src/lib/Cube_L432k/USB_DEVICE/App/usbd_cdc_if.d ./src/lib/Cube_L432k/USB_DEVICE/App/usbd_cdc_if.o ./src/lib/Cube_L432k/USB_DEVICE/App/usbd_cdc_if.su ./src/lib/Cube_L432k/USB_DEVICE/App/usbd_desc.cyclo ./src/lib/Cube_L432k/USB_DEVICE/App/usbd_desc.d ./src/lib/Cube_L432k/USB_DEVICE/App/usbd_desc.o ./src/lib/Cube_L432k/USB_DEVICE/App/usbd_desc.su

.PHONY: clean-src-2f-lib-2f-Cube_L432k-2f-USB_DEVICE-2f-App

