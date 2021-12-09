################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Csro/fnd_input/fnd_input.c \
../Csro/fnd_input/fnd_input_gpio.c \
../Csro/fnd_input/fnd_input_remote.c 

OBJS += \
./Csro/fnd_input/fnd_input.o \
./Csro/fnd_input/fnd_input_gpio.o \
./Csro/fnd_input/fnd_input_remote.o 

C_DEPS += \
./Csro/fnd_input/fnd_input.d \
./Csro/fnd_input/fnd_input_gpio.d \
./Csro/fnd_input/fnd_input_remote.d 


# Each subdirectory must supply rules for building sources it contributes
Csro/fnd_input/%.o: ../Csro/fnd_input/%.c Csro/fnd_input/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Modbus_RTU" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_com" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_eeprom" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_input" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_output" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/motor_function_ert_rtw" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/motor_param_persist_ert_rtw" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/_sharedutils" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/change_monitor" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/motor_channel" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/motor_function" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/motor_param_persist" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Csro-2f-fnd_input

clean-Csro-2f-fnd_input:
	-$(RM) ./Csro/fnd_input/fnd_input.d ./Csro/fnd_input/fnd_input.o ./Csro/fnd_input/fnd_input_gpio.d ./Csro/fnd_input/fnd_input_gpio.o ./Csro/fnd_input/fnd_input_remote.d ./Csro/fnd_input/fnd_input_remote.o

.PHONY: clean-Csro-2f-fnd_input

