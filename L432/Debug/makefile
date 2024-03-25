################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/lib/Cube_L432k/USB_DEVICE/Target/subdir.mk
-include src/lib/Cube_L432k/USB_DEVICE/App/subdir.mk
-include src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
-include src/lib/Cube_L432k/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/subdir.mk
-include src/lib/Cube_L432k/Drivers/STM32L4xx_HAL_Driver/Src/subdir.mk
-include src/lib/Cube_L432k/Debug/Drivers/STM32L4xx_HAL_Driver/Src/subdir.mk
-include src/lib/Cube_L432k/Debug/Core/Startup/subdir.mk
-include src/lib/Cube_L432k/Debug/Core/Src/subdir.mk
-include src/lib/Cube_L432k/Debug/subdir.mk
-include src/hw/driver/subdir.mk
-include src/hw/subdir.mk
-include src/bsp/startup/subdir.mk
-include src/bsp/subdir.mk
-include src/ap/subdir.mk
-include src/subdir.mk
-include .metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := L432
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
L432.elf \

MAP_FILES += \
L432.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
L432.list \


# All Target
all: main-build

# Main-build Target
main-build: L432.elf secondary-outputs

# Tool invocations
L432.elf L432.map: $(OBJS) $(USER_OBJS) C:\capstone\L432\src\bsp\ldscripit\STM32L432KCUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "L432.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\capstone\L432\src\bsp\ldscripit\STM32L432KCUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="L432.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

L432.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "L432.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) L432.elf L432.list L432.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
