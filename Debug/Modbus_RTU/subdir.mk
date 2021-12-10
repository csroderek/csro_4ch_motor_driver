################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus_RTU/mb_master.c \
../Modbus_RTU/mb_slave.c 

OBJS += \
./Modbus_RTU/mb_master.o \
./Modbus_RTU/mb_slave.o 

C_DEPS += \
./Modbus_RTU/mb_master.d \
./Modbus_RTU/mb_slave.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus_RTU/%.o: ../Modbus_RTU/%.c Modbus_RTU/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Modbus_RTU" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_com" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_eeprom" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_input" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Csro/fnd_output" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/motor_function_ert_rtw" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/motor_param_persist_ert_rtw" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/_sharedutils" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/change_monitor" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/motor_channel" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/motor_function" -I"C:/Users/Litao/STM32CubeIDE/workspace_1.8.0/csro_4ch_motor_driver/Simulink/slprj/ert/motor_param_persist" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modbus_RTU

clean-Modbus_RTU:
	-$(RM) ./Modbus_RTU/mb_master.d ./Modbus_RTU/mb_master.o ./Modbus_RTU/mb_slave.d ./Modbus_RTU/mb_slave.o

.PHONY: clean-Modbus_RTU

