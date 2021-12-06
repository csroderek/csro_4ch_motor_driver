#include "change_monitor.h"

void change_monitor(const int16_T *rtu_debounce, const int16_T *rtu_longpress, const int16_T *rtu_long, const int16_T *rtu_short, const
                    int16_T *rtu_transfer, boolean_T *rty_changed, DW_change_monitor_f_T *localDW)
{
    boolean_T rtb_FixPtRelationalOperator;
    boolean_T rtb_FixPtRelationalOperator_a;
    boolean_T rtb_FixPtRelationalOperator_e;
    boolean_T rtb_FixPtRelationalOperator_h;
    boolean_T rtb_FixPtRelationalOperator_hh;
    rtb_FixPtRelationalOperator = (*rtu_debounce != localDW->DelayInput1_DSTATE);
    localDW->DelayInput1_DSTATE = localDW->DelayInput1_DSTATE_e;
    rtb_FixPtRelationalOperator_h = (*rtu_longpress != localDW->DelayInput1_DSTATE);
    localDW->DelayInput1_DSTATE = localDW->DelayInput1_DSTATE_k;
    rtb_FixPtRelationalOperator_e = (*rtu_long != localDW->DelayInput1_DSTATE);
    localDW->DelayInput1_DSTATE = localDW->DelayInput1_DSTATE_m;
    rtb_FixPtRelationalOperator_hh = (*rtu_short != localDW->DelayInput1_DSTATE);
    localDW->DelayInput1_DSTATE = localDW->DelayInput1_DSTATE_i;
    rtb_FixPtRelationalOperator_a = (*rtu_transfer != localDW->DelayInput1_DSTATE);
    rtb_FixPtRelationalOperator = (rtb_FixPtRelationalOperator || rtb_FixPtRelationalOperator_h || rtb_FixPtRelationalOperator_e ||
        rtb_FixPtRelationalOperator_hh || rtb_FixPtRelationalOperator_a);
    localDW->Delay_DSTATE = (uint8_T)((uint32_T)rtb_FixPtRelationalOperator + localDW->Delay_DSTATE);
    if (localDW->Delay_DSTATE >= 100)
    {
        localDW->Delay_DSTATE = 100U;
    }

    *rty_changed = (rtb_FixPtRelationalOperator && (localDW->Delay_DSTATE >= 2));
    localDW->DelayInput1_DSTATE = *rtu_debounce;
    localDW->DelayInput1_DSTATE_e = *rtu_longpress;
    localDW->DelayInput1_DSTATE_k = *rtu_long;
    localDW->DelayInput1_DSTATE_m = *rtu_short;
    localDW->DelayInput1_DSTATE_i = *rtu_transfer;
}
