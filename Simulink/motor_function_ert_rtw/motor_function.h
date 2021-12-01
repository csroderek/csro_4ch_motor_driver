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
    MdlrefDW_motor_channel_T Model_InstanceData;
}
DW_motor_function_T;

typedef struct
{
    InstP_motor_channel_T InstP_Model;
}
InstP_motor_function_T;

typedef struct
{
    int16_T relay1;
    int16_T relay2;
}
ExtY_motor_function_T;

extern DW_motor_function_T motor_function_DW;
extern InstP_motor_function_T motor_function_InstP;
extern ExtY_motor_function_T motor_function_Y;
extern void motor_function_initialize(void);
extern void motor_function_step(void);
extern void motor_function_terminate(void);

#endif
