#ifndef RTW_HEADER_motor_param_persist_h_
#define RTW_HEADER_motor_param_persist_h_
#include "mb_config.h"
#ifndef motor_param_persist_COMMON_INCLUDES_
#define motor_param_persist_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "change_monitor.h"

#include "ee.h"
#include "fnd_com.h"
#include "ee_commit.h"

typedef struct
{
    MdlrefDW_change_monitor_T Model_InstanceData;
}
DW_motor_param_persist_T;

extern DW_motor_param_persist_T motor_param_persist_DW;
extern void motor_param_persist_initialize(void);
extern void motor_param_persist_step(void);
extern void motor_param_persist_terminate(void);

#endif
