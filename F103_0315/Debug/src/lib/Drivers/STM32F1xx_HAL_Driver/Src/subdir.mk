################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.c \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.c \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.c \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.c \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pcd.c \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pcd_ex.c \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.c \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.c \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.c \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.c \
../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_ll_usb.c 

OBJS += \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.o \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.o \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.o \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.o \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.o \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.o \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.o \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.o \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pcd.o \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pcd_ex.o \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.o \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.o \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.o \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.o \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.o \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_ll_usb.o 

C_DEPS += \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.d \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.d \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.d \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.d \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.d \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.d \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.d \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.d \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pcd.d \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pcd_ex.d \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.d \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.d \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.d \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.d \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.d \
./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_ll_usb.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/Drivers/STM32F1xx_HAL_Driver/Src/%.o src/lib/Drivers/STM32F1xx_HAL_Driver/Src/%.su src/lib/Drivers/STM32F1xx_HAL_Driver/Src/%.cyclo: ../src/lib/Drivers/STM32F1xx_HAL_Driver/Src/%.c src/lib/Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -c -I"C:/capstone/F103_0315/src" -I"C:/capstone/F103_0315/src/ap" -I"C:/capstone/F103_0315/src/bsp" -I"C:/capstone/F103_0315/src/common" -I"C:/capstone/F103_0315/src/hw" -I"C:/capstone/F103_0315/src/lib" -I"C:/capstone/F103_0315/src/lib/Core/Inc" -I"C:/capstone/F103_0315/src/lib/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/capstone/F103_0315/src/lib/Drivers/CMSIS/Include" -I"C:/capstone/F103_0315/src/lib/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/capstone/F103_0315/src/lib/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/capstone/F103_0315/src/lib/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/capstone/F103_0315/src/lib/USB_DEVICE/App" -I"C:/capstone/F103_0315/src/lib/USB_DEVICE/Target" -I"C:/capstone/F103_0315/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-src-2f-lib-2f-Drivers-2f-STM32F1xx_HAL_Driver-2f-Src

clean-src-2f-lib-2f-Drivers-2f-STM32F1xx_HAL_Driver-2f-Src:
	-$(RM) ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.su ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.su ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.su ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_exti.su ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash.su ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_flash_ex.su ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.su ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio_ex.su ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pcd.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pcd.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pcd.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pcd.su ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pcd_ex.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pcd_ex.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pcd_ex.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pcd_ex.su ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.su ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.su ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.su ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim.su ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_tim_ex.su ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_ll_usb.cyclo ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_ll_usb.d ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_ll_usb.o ./src/lib/Drivers/STM32F1xx_HAL_Driver/Src/stm32f1xx_ll_usb.su

.PHONY: clean-src-2f-lib-2f-Drivers-2f-STM32F1xx_HAL_Driver-2f-Src

