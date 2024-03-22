################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/USB_DEVICE/Target/usbd_conf.c 

OBJS += \
./src/lib/USB_DEVICE/Target/usbd_conf.o 

C_DEPS += \
./src/lib/USB_DEVICE/Target/usbd_conf.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/USB_DEVICE/Target/%.o src/lib/USB_DEVICE/Target/%.su src/lib/USB_DEVICE/Target/%.cyclo: ../src/lib/USB_DEVICE/Target/%.c src/lib/USB_DEVICE/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -c -I"C:/capstone/F103_0315/src" -I"C:/capstone/F103_0315/src/ap" -I"C:/capstone/F103_0315/src/bsp" -I"C:/capstone/F103_0315/src/common" -I"C:/capstone/F103_0315/src/hw" -I"C:/capstone/F103_0315/src/lib" -I"C:/capstone/F103_0315/src/lib/Core/Inc" -I"C:/capstone/F103_0315/src/lib/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/capstone/F103_0315/src/lib/Drivers/CMSIS/Include" -I"C:/capstone/F103_0315/src/lib/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/capstone/F103_0315/src/lib/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/capstone/F103_0315/src/lib/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/capstone/F103_0315/src/lib/USB_DEVICE/App" -I"C:/capstone/F103_0315/src/lib/USB_DEVICE/Target" -I"C:/capstone/F103_0315/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-src-2f-lib-2f-USB_DEVICE-2f-Target

clean-src-2f-lib-2f-USB_DEVICE-2f-Target:
	-$(RM) ./src/lib/USB_DEVICE/Target/usbd_conf.cyclo ./src/lib/USB_DEVICE/Target/usbd_conf.d ./src/lib/USB_DEVICE/Target/usbd_conf.o ./src/lib/USB_DEVICE/Target/usbd_conf.su

.PHONY: clean-src-2f-lib-2f-USB_DEVICE-2f-Target

