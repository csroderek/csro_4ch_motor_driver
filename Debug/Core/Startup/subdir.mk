################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f103c8tx.s 

OBJS += \
./Core/Startup/startup_stm32f103c8tx.o 

S_DEPS += \
./Core/Startup/startup_stm32f103c8tx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -DDEBUG -c -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Modbus_RTU" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_com" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_eeprom" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_input" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_output" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/motor_function_ert_rtw" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/motor_param_persist_ert_rtw" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/_sharedutils" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/change_monitor" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/motor_channel" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/motor_function" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/motor_param_persist" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f103c8tx.d ./Core/Startup/startup_stm32f103c8tx.o

.PHONY: clean-Core-2f-Startup

