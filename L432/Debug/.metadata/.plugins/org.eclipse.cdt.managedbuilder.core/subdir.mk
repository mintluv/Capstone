################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.c 

OBJS += \
./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.o 

C_DEPS += \
./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.d 


# Each subdirectory must supply rules for building sources it contributes
.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/%.o .metadata/.plugins/org.eclipse.cdt.managedbuilder.core/%.su .metadata/.plugins/org.eclipse.cdt.managedbuilder.core/%.cyclo: ../.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/%.c .metadata/.plugins/org.eclipse.cdt.managedbuilder.core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32L432xx -c -I"C:/capstone/L432/src" -I"C:/capstone/L432/src/ap" -I"C:/capstone/L432/src/bsp" -I"C:/capstone/L432/src/common" -I"C:/capstone/L432/src/hw" -I"C:/capstone/L432/src/lib" -I"C:/capstone/L432/src/lib/Cube_L432k/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/capstone/L432/src/lib/Cube_L432k/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/capstone/L432/src/lib/Cube_L432k/Drivers/CMSIS/Include" -I"C:/capstone/L432/src/common/hw/include" -I"C:/capstone/L432/src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/capstone/L432/src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/capstone/L432/src/lib/Cube_L432k/USB_DEVICE/App" -I"C:/capstone/L432/src/lib/Cube_L432k/USB_DEVICE/Target" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-managedbuilder-2e-core

clean--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-managedbuilder-2e-core:
	-$(RM) ./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.cyclo ./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.d ./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.o ./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.su

.PHONY: clean--2e-metadata-2f--2e-plugins-2f-org-2e-eclipse-2e-cdt-2e-managedbuilder-2e-core

