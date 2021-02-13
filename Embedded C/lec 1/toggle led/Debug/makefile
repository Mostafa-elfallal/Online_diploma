################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
toggle\ led.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
toggle\ led.list \

OBJCOPY_HEX += \
toggle\ led.hex \

OBJCOPY_BIN += \
toggle\ led.bin \


# All Target
all: toggle\ led.elf secondary-outputs

# Tool invocations
toggle\ led.elf: $(OBJS) $(USER_OBJS) F:\diploma\ playground\stmIDE\toggle\ led\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "toggle led.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"F:\diploma playground\stmIDE\toggle led\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="toggle led.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

toggle\ led.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "toggle led.list"
	@echo 'Finished building: $@'
	@echo ' '

toggle\ led.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "toggle led.hex"
	@echo 'Finished building: $@'
	@echo ' '

toggle\ led.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "toggle led.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
