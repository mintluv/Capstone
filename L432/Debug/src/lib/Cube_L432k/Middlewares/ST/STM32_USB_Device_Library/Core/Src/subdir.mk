################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
../src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
../src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c 

OBJS += \
./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.o \
./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.o \
./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.o 

C_DEPS += \
./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.d \
./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.d \
./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.o src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.su src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.cyclo: ../src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.c src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32L432xx -c -I"C:/Capstone/L432/src" -I"C:/Capstone/L432/src/ap" -I"C:/Capstone/L432/src/bsp" -I"C:/Capstone/L432/src/common" -I"C:/Capstone/L432/src/hw" -I"C:/Capstone/L432/src/lib" -I"C:/Capstone/L432/src/lib/Cube_L432k/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Capstone/L432/src/lib/Cube_L432k/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Capstone/L432/src/lib/Cube_L432k/Drivers/CMSIS/Include" -I"C:/Capstone/L432/src/common/hw/include" -I"C:/Capstone/L432/src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/Capstone/L432/src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Capstone/L432/src/lib/Cube_L432k/USB_DEVICE/App" -I"C:/Capstone/L432/src/lib/Cube_L432k/USB_DEVICE/Target" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-lib-2f-Cube_L432k-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Core-2f-Src

clean-src-2f-lib-2f-Cube_L432k-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Core-2f-Src:
	-$(RM) ./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.cyclo ./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.d ./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.o ./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.su ./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.cyclo ./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.d ./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.o ./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.su ./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.cyclo ./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.d ./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.o ./src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.su

.PHONY: clean-src-2f-lib-2f-Cube_L432k-2f-Middlewares-2f-ST-2f-STM32_USB_Device_Library-2f-Core-2f-Src

