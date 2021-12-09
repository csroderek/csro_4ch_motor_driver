################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Simulink/slprj/ert/motor_channel/motor_channel.c 

OBJS += \
./Simulink/slprj/ert/motor_channel/motor_channel.o 

C_DEPS += \
./Simulink/slprj/ert/motor_channel/motor_channel.d 


# Each subdirectory must supply rules for building sources it contributes
Simulink/slprj/ert/motor_channel/%.o: ../Simulink/slprj/ert/motor_channel/%.c Simulink/slprj/ert/motor_channel/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Modbus_RTU" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_com" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_eeprom" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_input" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_output" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/motor_function_ert_rtw" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/motor_param_persist_ert_rtw" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/_sharedutils" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/change_monitor" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/motor_channel" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/motor_function" -I"C:/Users/Derek/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/motor_param_persist" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Simulink-2f-slprj-2f-ert-2f-motor_channel

clean-Simulink-2f-slprj-2f-ert-2f-motor_channel:
	-$(RM) ./Simulink/slprj/ert/motor_channel/motor_channel.d ./Simulink/slprj/ert/motor_channel/motor_channel.o

.PHONY: clean-Simulink-2f-slprj-2f-ert-2f-motor_channel

