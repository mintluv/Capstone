################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../src/bsp/startup/startup_stm32f103cbtx.s 

OBJS += \
./src/bsp/startup/startup_stm32f103cbtx.o 

S_DEPS += \
./src/bsp/startup/startup_stm32f103cbtx.d 


# Each subdirectory must supply rules for building sources it contributes
src/bsp/startup/%.o: ../src/bsp/startup/%.s src/bsp/startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-src-2f-bsp-2f-startup

clean-src-2f-bsp-2f-startup:
	-$(RM) ./src/bsp/startup/startup_stm32f103cbtx.d ./src/bsp/startup/startup_stm32f103cbtx.o

.PHONY: clean-src-2f-bsp-2f-startup

