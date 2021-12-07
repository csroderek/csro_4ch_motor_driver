#ifndef RTW_HEADER_motor_function_h_
#define RTW_HEADER_motor_function_h_
#include "mb_config.h"
#ifndef motor_function_COMMON_INCLUDES_
#define motor_function_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "motor_channel.h"

#include "fnd_com.h"

typedef struct
{
    int16_T up_relay;
    int16_T down_relay;
    int16_T up_relay_g;
    int16_T down_relay_d;
    int16_T up_relay_j;
    int16_T down_relay_j;
    int16_T up_relay_j2;
    int16_T down_relay_g;
}
B_motor_function_T;

typedef struct
{
    MdlrefDW_motor_channel_T Model_InstanceData;
    MdlrefDW_motor_channel_T Model1_InstanceData;
    MdlrefDW_motor_channel_T Model2_InstanceData;
    MdlrefDW_motor_channel_T Model3_InstanceData;
}
DW_motor_function_T;

typedef struct
{
    InstP_motor_channel_T InstP_Model;
    InstP_motor_channel_T InstP_Model1;
    InstP_motor_channel_T InstP_Model2;
    InstP_motor_channel_T InstP_Model3;
}
InstP_motor_function_T;

extern B_motor_function_T motor_function_B;
extern DW_motor_function_T motor_function_DW;
extern InstP_motor_function_T motor_function_InstP;
extern void motor_function_initialize(void);
extern void motor_function_step(void);
extern void motor_function_terminate(void);

#endif
