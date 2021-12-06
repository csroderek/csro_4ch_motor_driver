#include "motor_param_persist.h"
#include "div_nde_s32_floor.h"

DW_motor_param_persist_T motor_param_persist_DW;
void motor_param_persist_step(void)
{
    boolean_T rtb_Model;
    int16_T rtb_DataStoreRead_o1;
    int16_T rtb_DataStoreRead_o2;
    int16_T rtb_DataStoreRead_o3;
    int16_T rtb_DataStoreRead_o4;
    int16_T rtb_DataStoreRead_o5;
    boolean_T rtb_FunctionCaller1;
    rtb_DataStoreRead_o1 = sys_regs.holdings[100];
    rtb_DataStoreRead_o2 = sys_regs.holdings[101];
    rtb_DataStoreRead_o3 = sys_regs.holdings[102];
    rtb_DataStoreRead_o4 = sys_regs.holdings[103];
    rtb_DataStoreRead_o5 = sys_regs.holdings[104];
    change_monitor(&rtb_DataStoreRead_o1, &rtb_DataStoreRead_o2, &rtb_DataStoreRead_o3, &rtb_DataStoreRead_o4, &rtb_DataStoreRead_o5,
                   &rtb_Model, &(motor_param_persist_DW.Model_InstanceData.rtdw));
    if (rtb_Model)
    {
        ee_ram[0] = (uint8_T)(sys_regs.holdings[100] - (int16_T)((int16_T)div_nde_s32_floor(sys_regs.holdings[100], 256) << 8));
        ee_ram[1] = (uint8_T)(sys_regs.holdings[100] >> 8);
        ee_ram[2] = (uint8_T)(sys_regs.holdings[101] - (int16_T)((int16_T)div_nde_s32_floor(sys_regs.holdings[101], 256) << 8));
        ee_ram[3] = (uint8_T)(sys_regs.holdings[101] >> 8);
        ee_ram[4] = (uint8_T)(sys_regs.holdings[102] - (int16_T)((int16_T)div_nde_s32_floor(sys_regs.holdings[102], 256) << 8));
        ee_ram[5] = (uint8_T)(sys_regs.holdings[102] >> 8);
        ee_ram[6] = (uint8_T)(sys_regs.holdings[103] - (int16_T)((int16_T)div_nde_s32_floor(sys_regs.holdings[103], 256) << 8));
        ee_ram[7] = (uint8_T)(sys_regs.holdings[103] >> 8);
        ee_ram[8] = (uint8_T)(sys_regs.holdings[104] - (int16_T)((int16_T)div_nde_s32_floor(sys_regs.holdings[104], 256) << 8));
        ee_ram[9] = (uint8_T)(sys_regs.holdings[104] >> 8);
        ee_commit(&rtb_FunctionCaller1);
    }
}

void motor_param_persist_initialize(void)
{
    {
        boolean_T rtb_FunctionCaller;
        sys_regs.holdings[100] = (int16_T)((int16_T)(ee_ram[1] << 8) + ee_ram[0]);
        sys_regs.holdings[101] = (int16_T)((int16_T)(ee_ram[3] << 8) + ee_ram[2]);
        sys_regs.holdings[102] = (int16_T)((int16_T)(ee_ram[5] << 8) + ee_ram[4]);
        sys_regs.holdings[103] = (int16_T)((int16_T)(ee_ram[7] << 8) + ee_ram[6]);
        sys_regs.holdings[104] = (int16_T)((int16_T)(ee_ram[9] << 8) + ee_ram[8]);
        if (ee_ram[100] != 1)
        {
            ee_ram[100] = 1U;
            ee_ram[0] = 4U;
            ee_ram[1] = 0U;
            ee_ram[2] = 100U;
            ee_ram[3] = 0U;
            ee_ram[4] = 112U;
            ee_ram[5] = 23U;
            ee_ram[6] = 20U;
            ee_ram[7] = 0U;
            ee_ram[8] = 50U;
            ee_ram[9] = 0U;
            ee_commit(&rtb_FunctionCaller);
        }
    }
}

void motor_param_persist_terminate(void)
{
}
