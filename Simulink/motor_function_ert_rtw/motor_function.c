#include "motor_function.h"

InstP_motor_function_T motor_function_InstP =
{
    {
        4,
        6000,
        100,
        20,
        50
    }
};

DW_motor_function_T motor_function_DW;
ExtY_motor_function_T motor_function_Y;
void motor_function_step(void)
{
    motor_channel(&(motor_function_DW.Model_InstanceData.rtm), (&(sys_regs.inputs[100])), (&(sys_regs.inputs[102])), (&(sys_regs.inputs[104])),
                  (&(sys_regs.inputs[109])), (&(sys_regs.inputs[114])), (&(sys_regs.inputs[119])), (&(sys_regs.inputs[124])),
                  &motor_function_Y.relay1, &motor_function_Y.relay2, &(motor_function_DW.Model_InstanceData.rtdw));
}

void motor_function_initialize(void)
{
    motor_function_DW.Model_InstanceData.rtm.motor_channel_InstP_ref = &motor_function_InstP.InstP_Model;
    motor_channel_Init(&(motor_function_DW.Model_InstanceData.rtdw));
}

void motor_function_terminate(void)
{
}
