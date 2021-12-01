#ifndef RTW_HEADER_motor_channel_h_
#define RTW_HEADER_motor_channel_h_
#ifndef motor_channel_COMMON_INCLUDES_
#define motor_channel_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

typedef struct tag_RTM_motor_channel_T RT_MODEL_motor_channel_T;
typedef struct
{
    int32_T sfEvent;
    uint16_T temporalCounter_i1;
    uint16_T temporalCounter_i2;
    uint16_T temporalCounter_i3;
    uint8_T is_active_c3_motor_channel;
    uint8_T is_c3_motor_channel;
    uint8_T is_COM_CMD;
    uint8_T is_active_COM_CMD;
    uint8_T is_KEY_CMD;
    uint8_T is_active_KEY_CMD;
    uint8_T is_DOWN_KEY_PRESSED;
    uint8_T is_UP_KEY_PRESSED;
    uint8_T is_MOTOR;
    uint8_T is_active_MOTOR;
}
DW_motor_channel_f_T;

typedef struct
{
    int16_T debounce_cnt;
    int16_T long_cnt;
    int16_T longpress_cnt;
    int16_T short_cnt;
    int16_T transfer_cnt;
}
InstP_motor_channel_T;

struct tag_RTM_motor_channel_T
{
    InstP_motor_channel_T *motor_channel_InstP_ref;
};

typedef struct
{
    DW_motor_channel_f_T rtdw;
    RT_MODEL_motor_channel_T rtm;
}
MdlrefDW_motor_channel_T;

extern void motor_channel_Init(DW_motor_channel_f_T *localDW);
extern void motor_channel(RT_MODEL_motor_channel_T * const motor_channel_M, const int16_T rtu_ch_btns[2], const int16_T rtu_gp_btns[2],
    const int16_T rtu_ch_coms[5], const int16_T rtu_gp_coms[5], const int16_T rtu_ch_rmts[5], const int16_T rtu_gp_rmts[5], const int16_T
    *rtu_com_only, int16_T *rty_up_relay, int16_T *rty_down_relay, DW_motor_channel_f_T *localDW);

#endif
