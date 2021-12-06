#include "motor_function.h"

InstP_motor_function_T motor_function_InstP =
{
    {
        4,
        6000,
        100,
        20,
        50
    },

    {
        4,
        6000,
        100,
        20,
        50
    },

    {
        4,
        6000,
        100,
        20,
        50
    },

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
extern const int16_T rtCP_pooled_i2hU6p9uLH6V[5];

#define rtCP_Constant_Value            rtCP_pooled_i2hU6p9uLH6V
#define rtCP_Constant23_Value          rtCP_pooled_i2hU6p9uLH6V
#define rtCP_Constant26_Value          rtCP_pooled_i2hU6p9uLH6V
#define rtCP_Constant29_Value          rtCP_pooled_i2hU6p9uLH6V

void motor_function_step(void)
{
    int32_T i;
    int16_T rtb_DataStoreRead3_o3[5];
    int16_T rtb_DataStoreRead_o1[2];
    int16_T rtb_DataStoreRead_o2[2];
    int16_T rtb_com_only3;
    sys_regs.inputs[120] = (int16_T)(sys_regs.holdings[18] & 1);
    sys_regs.inputs[121] = (int16_T)(sys_regs.holdings[0] & 1);
    sys_regs.inputs[122] = (int16_T)(sys_regs.holdings[6] & 1);
    sys_regs.inputs[123] = (int16_T)(sys_regs.holdings[24] & 1);
    sys_regs.inputs[124] = (int16_T)(sys_regs.holdings[12] & 1);
    sys_regs.inputs[125] = (int16_T)(sys_regs.holdings[18] >> 1 & 1);
    sys_regs.inputs[126] = (int16_T)(sys_regs.holdings[0] >> 1 & 1);
    sys_regs.inputs[127] = (int16_T)(sys_regs.holdings[6] >> 1 & 1);
    sys_regs.inputs[128] = (int16_T)(sys_regs.holdings[24] >> 1 & 1);
    sys_regs.inputs[129] = (int16_T)(sys_regs.holdings[12] >> 1 & 1);
    sys_regs.inputs[130] = (int16_T)(sys_regs.holdings[18] >> 2 & 1);
    sys_regs.inputs[131] = (int16_T)(sys_regs.holdings[0] >> 2 & 1);
    sys_regs.inputs[132] = (int16_T)(sys_regs.holdings[6] >> 2 & 1);
    sys_regs.inputs[133] = (int16_T)(sys_regs.holdings[24] >> 2 & 1);
    sys_regs.inputs[134] = (int16_T)(sys_regs.holdings[12] >> 2 & 1);
    sys_regs.inputs[135] = (int16_T)(sys_regs.holdings[18] >> 3 & 1);
    sys_regs.inputs[136] = (int16_T)(sys_regs.holdings[0] >> 3 & 1);
    sys_regs.inputs[137] = (int16_T)(sys_regs.holdings[6] >> 3 & 1);
    sys_regs.inputs[138] = (int16_T)(sys_regs.holdings[24] >> 3 & 1);
    sys_regs.inputs[139] = (int16_T)(sys_regs.holdings[12] >> 3 & 1);
    rtb_DataStoreRead_o1[0] = sys_regs.inputs[100];
    rtb_DataStoreRead_o2[0] = sys_regs.inputs[108];
    rtb_DataStoreRead_o1[1] = sys_regs.inputs[101];
    rtb_DataStoreRead_o2[1] = sys_regs.inputs[109];
    for (i = 0; i < 5; i++)
    {
        rtb_DataStoreRead3_o3[i] = sys_regs.inputs[i + 120];
    }

    rtb_com_only3 = sys_regs.holdings[37];
    motor_channel(&(motor_function_DW.Model_InstanceData.rtm), &rtb_DataStoreRead_o1[0], &rtb_DataStoreRead_o2[0], &rtb_DataStoreRead3_o3[0],
                  &rtCP_Constant_Value[0], &rtCP_Constant_Value[0], &rtCP_Constant_Value[0], &rtb_com_only3, &motor_function_Y.relay1,
                  &motor_function_Y.relay2, &(motor_function_DW.Model_InstanceData.rtdw));
    rtb_DataStoreRead_o1[0] = sys_regs.inputs[102];
    rtb_DataStoreRead_o2[0] = sys_regs.inputs[108];
    rtb_DataStoreRead_o1[1] = sys_regs.inputs[103];
    rtb_DataStoreRead_o2[1] = sys_regs.inputs[109];
    for (i = 0; i < 5; i++)
    {
        rtb_DataStoreRead3_o3[i] = sys_regs.inputs[i + 125];
    }

    rtb_com_only3 = sys_regs.holdings[37];
    motor_channel(&(motor_function_DW.Model1_InstanceData.rtm), &rtb_DataStoreRead_o1[0], &rtb_DataStoreRead_o2[0], &rtb_DataStoreRead3_o3[0],
                  &rtCP_Constant23_Value[0], &rtCP_Constant23_Value[0], &rtCP_Constant23_Value[0], &rtb_com_only3, &motor_function_Y.relay3,
                  &motor_function_Y.relay4, &(motor_function_DW.Model1_InstanceData.rtdw));
    rtb_DataStoreRead_o1[0] = sys_regs.inputs[104];
    rtb_DataStoreRead_o2[0] = sys_regs.inputs[108];
    rtb_DataStoreRead_o1[1] = sys_regs.inputs[105];
    rtb_DataStoreRead_o2[1] = sys_regs.inputs[109];
    for (i = 0; i < 5; i++)
    {
        rtb_DataStoreRead3_o3[i] = sys_regs.inputs[i + 130];
    }

    rtb_com_only3 = sys_regs.holdings[37];
    motor_channel(&(motor_function_DW.Model2_InstanceData.rtm), &rtb_DataStoreRead_o1[0], &rtb_DataStoreRead_o2[0], &rtb_DataStoreRead3_o3[0],
                  &rtCP_Constant26_Value[0], &rtCP_Constant26_Value[0], &rtCP_Constant26_Value[0], &rtb_com_only3, &motor_function_Y.relay5,
                  &motor_function_Y.relay6, &(motor_function_DW.Model2_InstanceData.rtdw));
    rtb_DataStoreRead_o1[0] = sys_regs.inputs[106];
    rtb_DataStoreRead_o2[0] = sys_regs.inputs[108];
    rtb_DataStoreRead_o1[1] = sys_regs.inputs[107];
    rtb_DataStoreRead_o2[1] = sys_regs.inputs[109];
    for (i = 0; i < 5; i++)
    {
        rtb_DataStoreRead3_o3[i] = sys_regs.inputs[i + 135];
    }

    rtb_com_only3 = sys_regs.holdings[37];
    motor_channel(&(motor_function_DW.Model3_InstanceData.rtm), &rtb_DataStoreRead_o1[0], &rtb_DataStoreRead_o2[0], &rtb_DataStoreRead3_o3[0],
                  &rtCP_Constant29_Value[0], &rtCP_Constant29_Value[0], &rtCP_Constant29_Value[0], &rtb_com_only3, &motor_function_Y.relay7,
                  &motor_function_Y.relay8, &(motor_function_DW.Model3_InstanceData.rtdw));
}

void motor_function_initialize(void)
{
    motor_function_DW.Model_InstanceData.rtm.motor_channel_InstP_ref = &motor_function_InstP.InstP_Model;
    motor_function_DW.Model1_InstanceData.rtm.motor_channel_InstP_ref = &motor_function_InstP.InstP_Model1;
    motor_function_DW.Model2_InstanceData.rtm.motor_channel_InstP_ref = &motor_function_InstP.InstP_Model2;
    motor_function_DW.Model3_InstanceData.rtm.motor_channel_InstP_ref = &motor_function_InstP.InstP_Model3;
    motor_channel_Init(&(motor_function_DW.Model_InstanceData.rtdw));
    motor_channel_Init(&(motor_function_DW.Model1_InstanceData.rtdw));
    motor_channel_Init(&(motor_function_DW.Model2_InstanceData.rtdw));
    motor_channel_Init(&(motor_function_DW.Model3_InstanceData.rtdw));
    motor_function_InstP.InstP_Model.debounce_cnt = sys_regs.holdings[100];
    motor_function_InstP.InstP_Model.longpress_cnt = sys_regs.holdings[101];
    motor_function_InstP.InstP_Model2.debounce_cnt = sys_regs.holdings[100];
    motor_function_InstP.InstP_Model2.longpress_cnt = sys_regs.holdings[101];
    motor_function_InstP.InstP_Model2.long_cnt = sys_regs.holdings[102];
    motor_function_InstP.InstP_Model2.short_cnt = sys_regs.holdings[36];
    motor_function_InstP.InstP_Model2.transfer_cnt = sys_regs.holdings[104];
    motor_function_InstP.InstP_Model3.debounce_cnt = sys_regs.holdings[100];
    motor_function_InstP.InstP_Model3.longpress_cnt = sys_regs.holdings[101];
    motor_function_InstP.InstP_Model3.long_cnt = sys_regs.holdings[102];
    motor_function_InstP.InstP_Model3.short_cnt = sys_regs.holdings[36];
    motor_function_InstP.InstP_Model3.transfer_cnt = sys_regs.holdings[104];
    motor_function_InstP.InstP_Model.long_cnt = sys_regs.holdings[102];
    motor_function_InstP.InstP_Model.short_cnt = sys_regs.holdings[36];
    motor_function_InstP.InstP_Model.transfer_cnt = sys_regs.holdings[104];
    motor_function_InstP.InstP_Model1.debounce_cnt = sys_regs.holdings[100];
    motor_function_InstP.InstP_Model1.longpress_cnt = sys_regs.holdings[101];
    motor_function_InstP.InstP_Model1.long_cnt = sys_regs.holdings[102];
    motor_function_InstP.InstP_Model1.short_cnt = sys_regs.holdings[36];
    motor_function_InstP.InstP_Model1.transfer_cnt = sys_regs.holdings[104];
}

void motor_function_terminate(void)
{
}
