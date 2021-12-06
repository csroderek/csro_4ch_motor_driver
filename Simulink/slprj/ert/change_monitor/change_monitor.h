#ifndef RTW_HEADER_change_monitor_h_
#define RTW_HEADER_change_monitor_h_
#ifndef change_monitor_COMMON_INCLUDES_
#define change_monitor_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

typedef struct
{
    int16_T DelayInput1_DSTATE;
    int16_T DelayInput1_DSTATE_e;
    int16_T DelayInput1_DSTATE_k;
    int16_T DelayInput1_DSTATE_m;
    int16_T DelayInput1_DSTATE_i;
    uint8_T Delay_DSTATE;
}
DW_change_monitor_f_T;

typedef struct
{
    DW_change_monitor_f_T rtdw;
}
MdlrefDW_change_monitor_T;

extern void change_monitor(const int16_T *rtu_debounce, const int16_T *rtu_longpress, const int16_T *rtu_long, const int16_T *rtu_short,
    const int16_T *rtu_transfer, boolean_T *rty_changed, DW_change_monitor_f_T *localDW);

#endif
