#ifndef RTW_HEADER_motor_channel_h_
#define RTW_HEADER_motor_channel_h_
#ifndef motor_channel_COMMON_INCLUDES_
#define motor_channel_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

typedef struct
{
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
DW_motor_channel_T;

typedef struct
{
    int16_T debounce_cnt;
    int16_T long_cnt;
    int16_T longpress_cnt;
    int16_T short_cnt;
    int16_T transfer_cnt;
}
InstP_motor_channel_T;

typedef struct
{
    int16_T ch_btns[2];
    int16_T gp_btns[2];
    int16_T ch_coms[5];
    int16_T gp_coms[5];
    int16_T ch_rmts[5];
    int16_T gp_rmts[5];
    int16_T com_only;
}
ExtU_motor_channel_T;

typedef struct
{
    int16_T up_relay;
    int16_T down_relay;
}
ExtY_motor_channel_T;

extern DW_motor_channel_T motor_channel_DW;
extern InstP_motor_channel_T motor_channel_InstP;
extern ExtU_motor_channel_T motor_channel_U;
extern ExtY_motor_channel_T motor_channel_Y;
extern void motor_channel_initialize(void);
extern void motor_channel_step(void);
extern void motor_channel_terminate(void);

#endif
