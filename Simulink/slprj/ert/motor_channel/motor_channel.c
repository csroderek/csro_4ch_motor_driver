#include "motor_channel.h"

#define motor_c_event_up_key_long_press (8)
#define motor_ch_event_short_down_event (4)
#define motor_cha_event_long_down_event (2)
#define motor_chan_event_down_key_click (0)
#define motor_chan_event_short_up_event (5)
#define motor_chann_IN_DOWN_KEY_PRESSED ((uint8_T)1U)
#define motor_chann_event_long_up_event (3)
#define motor_channe_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define motor_channe_event_up_key_click (7)
#define motor_channel_CALL_EVENT       (-1)
#define motor_channel_IN_DOWN_CLICK    ((uint8_T)1U)
#define motor_channel_IN_DOWN_DEBOUNCE ((uint8_T)2U)
#define motor_channel_IN_DOWN_LONGPRESS ((uint8_T)3U)
#define motor_channel_IN_DOWN_TO_LONGUP ((uint8_T)1U)
#define motor_channel_IN_IDLE          ((uint8_T)1U)
#define motor_channel_IN_IDLE_d        ((uint8_T)2U)
#define motor_channel_IN_LONG_DOWN     ((uint8_T)2U)
#define motor_channel_IN_LONG_UP       ((uint8_T)3U)
#define motor_channel_IN_MOTOR_CTRL    ((uint8_T)1U)
#define motor_channel_IN_OFF           ((uint8_T)4U)
#define motor_channel_IN_SHORT_DOWN    ((uint8_T)4U)
#define motor_channel_IN_SHORT_DOWN_f  ((uint8_T)5U)
#define motor_channel_IN_SHORT_UP      ((uint8_T)5U)
#define motor_channel_IN_SHORT_UP_m    ((uint8_T)6U)
#define motor_channel_IN_STOP          ((uint8_T)6U)
#define motor_channel_IN_UP_CLICK      ((uint8_T)1U)
#define motor_channel_IN_UP_DEBOUNCE   ((uint8_T)2U)
#define motor_channel_IN_UP_KEY_PRESSED ((uint8_T)3U)
#define motor_channel_IN_UP_LONGPRESS  ((uint8_T)3U)
#define motor_channel_IN_UP_TO_LONGDOWN ((uint8_T)7U)
#define motor_channel_event_stop_event (6)
#define motor_event_down_key_long_press (1)

#ifndef rtmGetmotor_channel_InstP_ref
#define rtmGetmotor_channel_InstP_ref(rtm) ((rtm)->motor_channel_InstP_ref)
#endif

#ifndef rtmSetmotor_channel_InstP_ref
#define rtmSetmotor_channel_InstP_ref(rtm, val) ((rtm)->motor_channel_InstP_ref = (val))
#endif

static void motor_channel_MOTOR(int16_T *rty_up_relay, int16_T *rty_down_relay, RT_MODEL_motor_channel_T * const motor_channel_M,
    DW_motor_channel_f_T *localDW);
static void motor_channel_MOTOR(int16_T *rty_up_relay, int16_T *rty_down_relay, RT_MODEL_motor_channel_T * const motor_channel_M,
    DW_motor_channel_f_T *localDW)
{
    InstP_motor_channel_T *motor_channel_InstP_arg = motor_channel_M->motor_channel_InstP_ref;
    switch (localDW->is_MOTOR)
    {
      case motor_channel_IN_DOWN_TO_LONGUP:
        if (localDW->temporalCounter_i3 >= (uint16_T)motor_channel_InstP_arg->transfer_cnt)
        {
            localDW->is_MOTOR = motor_channel_IN_LONG_UP;
            localDW->temporalCounter_i3 = 0U;
            *rty_up_relay = 1;
        }
        break;

      case motor_channel_IN_LONG_DOWN:
        if ((localDW->sfEvent == motor_chan_event_down_key_click) || (localDW->sfEvent == motor_channe_event_up_key_click) ||
                (localDW->sfEvent == motor_channel_event_stop_event) || (localDW->temporalCounter_i3 >= (uint16_T)
                motor_channel_InstP_arg->long_cnt))
        {
            *rty_down_relay = 0;
            localDW->is_MOTOR = motor_channel_IN_OFF;
        }
        else if ((localDW->sfEvent == motor_c_event_up_key_long_press) || (localDW->sfEvent == motor_chann_event_long_up_event))
        {
            *rty_down_relay = 0;
            localDW->is_MOTOR = motor_channel_IN_DOWN_TO_LONGUP;
            localDW->temporalCounter_i3 = 0U;
        }
        break;

      case motor_channel_IN_LONG_UP:
        if ((localDW->sfEvent == motor_event_down_key_long_press) || (localDW->sfEvent == motor_cha_event_long_down_event))
        {
            *rty_up_relay = 0;
            localDW->is_MOTOR = motor_channel_IN_UP_TO_LONGDOWN;
            localDW->temporalCounter_i3 = 0U;
        }
        else if ((localDW->sfEvent == motor_channe_event_up_key_click) || (localDW->sfEvent == motor_chan_event_down_key_click) ||
                 (localDW->sfEvent == motor_channel_event_stop_event) || (localDW->temporalCounter_i3 >= (uint16_T)
                  motor_channel_InstP_arg->long_cnt))
        {
            *rty_up_relay = 0;
            localDW->is_MOTOR = motor_channel_IN_OFF;
        }
        break;

      case motor_channel_IN_OFF:
        if ((localDW->sfEvent == motor_channe_event_up_key_click) || (localDW->sfEvent == motor_chan_event_short_up_event))
        {
            localDW->is_MOTOR = motor_channel_IN_SHORT_UP_m;
            localDW->temporalCounter_i3 = 0U;
            *rty_up_relay = 1;
        }
        else if ((localDW->sfEvent == motor_c_event_up_key_long_press) || (localDW->sfEvent == motor_chann_event_long_up_event))
        {
            localDW->is_MOTOR = motor_channel_IN_LONG_UP;
            localDW->temporalCounter_i3 = 0U;
            *rty_up_relay = 1;
        }
        else if ((localDW->sfEvent == motor_chan_event_down_key_click) || (localDW->sfEvent == motor_ch_event_short_down_event))
        {
            localDW->is_MOTOR = motor_channel_IN_SHORT_DOWN_f;
            localDW->temporalCounter_i3 = 0U;
            *rty_down_relay = 1;
        }
        else if ((localDW->sfEvent == motor_event_down_key_long_press) || (localDW->sfEvent == motor_cha_event_long_down_event))
        {
            localDW->is_MOTOR = motor_channel_IN_LONG_DOWN;
            localDW->temporalCounter_i3 = 0U;
            *rty_down_relay = 1;
        }
        break;

      case motor_channel_IN_SHORT_DOWN_f:
        if (localDW->temporalCounter_i3 >= (uint16_T)motor_channel_InstP_arg->short_cnt)
        {
            *rty_down_relay = 0;
            localDW->is_MOTOR = motor_channel_IN_OFF;
        }
        break;

      case motor_channel_IN_SHORT_UP_m:
        if (localDW->temporalCounter_i3 >= (uint16_T)motor_channel_InstP_arg->short_cnt)
        {
            *rty_up_relay = 0;
            localDW->is_MOTOR = motor_channel_IN_OFF;
        }
        break;

      case motor_channel_IN_UP_TO_LONGDOWN:
        if (localDW->temporalCounter_i3 >= (uint16_T)motor_channel_InstP_arg->transfer_cnt)
        {
            localDW->is_MOTOR = motor_channel_IN_LONG_DOWN;
            localDW->temporalCounter_i3 = 0U;
            *rty_down_relay = 1;
        }
        break;
    }
}

void motor_channel_Init(DW_motor_channel_f_T *localDW)
{
    localDW->sfEvent = motor_channel_CALL_EVENT;
}

void motor_channel(RT_MODEL_motor_channel_T * const motor_channel_M, const int16_T rtu_ch_btns[2], const int16_T rtu_gp_btns[2], const
                   int16_T rtu_ch_coms[5], const int16_T rtu_gp_coms[5], const int16_T rtu_ch_rmts[5], const int16_T rtu_gp_rmts[5], const
                   int16_T *rtu_com_only, int16_T *rty_up_relay, int16_T *rty_down_relay, DW_motor_channel_f_T *localDW)
{
    InstP_motor_channel_T *motor_channel_InstP_arg = motor_channel_M->motor_channel_InstP_ref;
    int32_T h_previousEvent;
    int16_T Switch1;
    int16_T Switch2;
    boolean_T Switch3;
    boolean_T Switch4;
    boolean_T Switch5;
    boolean_T Switch6;
    boolean_T Switch7;
    if (*rtu_com_only != 0)
    {
        Switch1 = 0;
        Switch3 = ((rtu_ch_coms[0] != 0) || (rtu_gp_coms[0] != 0));
        Switch4 = ((rtu_ch_coms[1] != 0) || (rtu_gp_coms[1] != 0));
        Switch5 = ((rtu_ch_coms[2] != 0) || (rtu_gp_coms[2] != 0));
        Switch6 = ((rtu_ch_coms[3] != 0) || (rtu_gp_coms[3] != 0));
        Switch2 = 0;
        Switch7 = ((rtu_ch_coms[4] != 0) || (rtu_gp_coms[4] != 0));
    }
    else
    {
        Switch1 = (int16_T)((rtu_ch_btns[0] != 0) || (rtu_gp_btns[0] != 0));
        Switch3 = ((rtu_ch_coms[0] != 0) || (rtu_gp_coms[0] != 0) || ((rtu_ch_rmts[0] != 0) || (rtu_gp_rmts[0] != 0)));
        Switch4 = ((rtu_ch_coms[1] != 0) || (rtu_gp_coms[1] != 0) || ((rtu_ch_rmts[1] != 0) || (rtu_gp_rmts[1] != 0)));
        Switch5 = ((rtu_ch_coms[2] != 0) || (rtu_gp_coms[2] != 0) || ((rtu_ch_rmts[2] != 0) || (rtu_gp_rmts[2] != 0)));
        Switch6 = ((rtu_ch_coms[3] != 0) || (rtu_gp_coms[3] != 0) || ((rtu_ch_rmts[3] != 0) || (rtu_gp_rmts[3] != 0)));
        Switch2 = (int16_T)((rtu_ch_btns[1] != 0) || (rtu_gp_btns[1] != 0));
        Switch7 = ((rtu_ch_coms[4] != 0) || (rtu_gp_coms[4] != 0) || ((rtu_ch_rmts[4] != 0) || (rtu_gp_rmts[4] != 0)));
    }

    localDW->sfEvent = motor_channel_CALL_EVENT;
    if (localDW->temporalCounter_i1 < 32767U)
    {
        localDW->temporalCounter_i1++;
    }

    if (localDW->temporalCounter_i2 < 32767U)
    {
        localDW->temporalCounter_i2++;
    }

    if (localDW->temporalCounter_i3 < 32767U)
    {
        localDW->temporalCounter_i3++;
    }

    if (localDW->is_active_c3_motor_channel == 0U)
    {
        localDW->is_active_c3_motor_channel = 1U;
        localDW->is_c3_motor_channel = motor_channel_IN_MOTOR_CTRL;
        localDW->is_active_COM_CMD = 1U;
        localDW->is_COM_CMD = motor_channel_IN_IDLE;
        localDW->is_active_KEY_CMD = 1U;
        localDW->is_KEY_CMD = motor_channel_IN_IDLE_d;
        localDW->is_active_MOTOR = 1U;
        localDW->is_MOTOR = motor_channel_IN_OFF;
    }
    else if (localDW->is_c3_motor_channel == 1)
    {
        if (localDW->is_active_COM_CMD != 0U)
        {
            switch (localDW->is_COM_CMD)
            {
              case motor_channel_IN_IDLE:
                if (Switch7)
                {
                    localDW->is_COM_CMD = motor_channel_IN_LONG_DOWN;
                    localDW->temporalCounter_i1 = 0U;
                    h_previousEvent = localDW->sfEvent;
                    localDW->sfEvent = motor_cha_event_long_down_event;
                    if (localDW->is_active_MOTOR != 0U)
                    {
                        motor_channel_MOTOR(rty_up_relay, rty_down_relay, motor_channel_M, localDW);
                    }

                    localDW->sfEvent = h_previousEvent;
                }
                else if (Switch5)
                {
                    localDW->is_COM_CMD = motor_channel_IN_STOP;
                    localDW->temporalCounter_i1 = 0U;
                    h_previousEvent = localDW->sfEvent;
                    localDW->sfEvent = motor_channel_event_stop_event;
                    if (localDW->is_active_MOTOR != 0U)
                    {
                        motor_channel_MOTOR(rty_up_relay, rty_down_relay, motor_channel_M, localDW);
                    }

                    localDW->sfEvent = h_previousEvent;
                }
                else if (Switch3)
                {
                    localDW->is_COM_CMD = motor_channel_IN_SHORT_UP;
                    localDW->temporalCounter_i1 = 0U;
                    h_previousEvent = localDW->sfEvent;
                    localDW->sfEvent = motor_chan_event_short_up_event;
                    if (localDW->is_active_MOTOR != 0U)
                    {
                        motor_channel_MOTOR(rty_up_relay, rty_down_relay, motor_channel_M, localDW);
                    }

                    localDW->sfEvent = h_previousEvent;
                }
                else if (Switch4)
                {
                    localDW->is_COM_CMD = motor_channel_IN_LONG_UP;
                    localDW->temporalCounter_i1 = 0U;
                    h_previousEvent = localDW->sfEvent;
                    localDW->sfEvent = motor_chann_event_long_up_event;
                    if (localDW->is_active_MOTOR != 0U)
                    {
                        motor_channel_MOTOR(rty_up_relay, rty_down_relay, motor_channel_M, localDW);
                    }

                    localDW->sfEvent = h_previousEvent;
                }
                else if (Switch6)
                {
                    localDW->is_COM_CMD = motor_channel_IN_SHORT_DOWN;
                    localDW->temporalCounter_i1 = 0U;
                    h_previousEvent = localDW->sfEvent;
                    localDW->sfEvent = motor_ch_event_short_down_event;
                    if (localDW->is_active_MOTOR != 0U)
                    {
                        motor_channel_MOTOR(rty_up_relay, rty_down_relay, motor_channel_M, localDW);
                    }

                    localDW->sfEvent = h_previousEvent;
                }
                break;

              case motor_channel_IN_LONG_DOWN:
                if (localDW->temporalCounter_i1 >= (uint16_T)motor_channel_InstP_arg->short_cnt)
                {
                    localDW->is_COM_CMD = motor_channel_IN_IDLE;
                }
                break;

              case motor_channel_IN_LONG_UP:
                if (localDW->temporalCounter_i1 >= (uint16_T)motor_channel_InstP_arg->short_cnt)
                {
                    localDW->is_COM_CMD = motor_channel_IN_IDLE;
                }
                break;

              case motor_channel_IN_SHORT_DOWN:
                if (localDW->temporalCounter_i1 >= (uint16_T)motor_channel_InstP_arg->short_cnt)
                {
                    localDW->is_COM_CMD = motor_channel_IN_IDLE;
                }
                break;

              case motor_channel_IN_SHORT_UP:
                if (localDW->temporalCounter_i1 >= (uint16_T)motor_channel_InstP_arg->short_cnt)
                {
                    localDW->is_COM_CMD = motor_channel_IN_IDLE;
                }
                break;

              case motor_channel_IN_STOP:
                if (localDW->temporalCounter_i1 >= (uint16_T)motor_channel_InstP_arg->short_cnt)
                {
                    localDW->is_COM_CMD = motor_channel_IN_IDLE;
                }
                break;
            }
        }

        if (localDW->is_active_KEY_CMD != 0U)
        {
            switch (localDW->is_KEY_CMD)
            {
              case motor_chann_IN_DOWN_KEY_PRESSED:
                switch (localDW->is_DOWN_KEY_PRESSED)
                {
                  case motor_channel_IN_DOWN_CLICK:
                    if (Switch2 != 1)
                    {
                        h_previousEvent = localDW->sfEvent;
                        localDW->sfEvent = motor_chan_event_down_key_click;
                        if (localDW->is_active_MOTOR != 0U)
                        {
                            motor_channel_MOTOR(rty_up_relay, rty_down_relay, motor_channel_M, localDW);
                        }

                        localDW->sfEvent = h_previousEvent;
                        localDW->is_DOWN_KEY_PRESSED = motor_channe_IN_NO_ACTIVE_CHILD;
                        localDW->is_KEY_CMD = motor_channel_IN_IDLE_d;
                    }
                    else if (localDW->temporalCounter_i2 >= (uint16_T)motor_channel_InstP_arg->longpress_cnt)
                    {
                        localDW->is_DOWN_KEY_PRESSED = motor_channel_IN_DOWN_LONGPRESS;
                        h_previousEvent = localDW->sfEvent;
                        localDW->sfEvent = motor_event_down_key_long_press;
                        if (localDW->is_active_MOTOR != 0U)
                        {
                            motor_channel_MOTOR(rty_up_relay, rty_down_relay, motor_channel_M, localDW);
                        }

                        localDW->sfEvent = h_previousEvent;
                    }
                    break;

                  case motor_channel_IN_DOWN_DEBOUNCE:
                    if (localDW->temporalCounter_i2 >= (uint16_T)motor_channel_InstP_arg->debounce_cnt)
                    {
                        localDW->is_DOWN_KEY_PRESSED = motor_channel_IN_DOWN_CLICK;
                        localDW->temporalCounter_i2 = 0U;
                    }
                    else if (Switch2 != 1)
                    {
                        localDW->is_DOWN_KEY_PRESSED = motor_channe_IN_NO_ACTIVE_CHILD;
                        localDW->is_KEY_CMD = motor_channel_IN_IDLE_d;
                    }
                    break;

                  case motor_channel_IN_DOWN_LONGPRESS:
                    if (Switch2 != 1)
                    {
                        localDW->is_DOWN_KEY_PRESSED = motor_channe_IN_NO_ACTIVE_CHILD;
                        localDW->is_KEY_CMD = motor_channel_IN_IDLE_d;
                    }
                    break;
                }
                break;

              case motor_channel_IN_IDLE_d:
                if (Switch1 == 1)
                {
                    localDW->is_KEY_CMD = motor_channel_IN_UP_KEY_PRESSED;
                    localDW->is_UP_KEY_PRESSED = motor_channel_IN_UP_DEBOUNCE;
                    localDW->temporalCounter_i2 = 0U;
                }
                else if (Switch2 == 1)
                {
                    localDW->is_KEY_CMD = motor_chann_IN_DOWN_KEY_PRESSED;
                    localDW->is_DOWN_KEY_PRESSED = motor_channel_IN_DOWN_DEBOUNCE;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;

              case motor_channel_IN_UP_KEY_PRESSED:
                switch (localDW->is_UP_KEY_PRESSED)
                {
                  case motor_channel_IN_UP_CLICK:
                    if (Switch1 != 1)
                    {
                        h_previousEvent = localDW->sfEvent;
                        localDW->sfEvent = motor_channe_event_up_key_click;
                        if (localDW->is_active_MOTOR != 0U)
                        {
                            motor_channel_MOTOR(rty_up_relay, rty_down_relay, motor_channel_M, localDW);
                        }

                        localDW->sfEvent = h_previousEvent;
                        localDW->is_UP_KEY_PRESSED = motor_channe_IN_NO_ACTIVE_CHILD;
                        localDW->is_KEY_CMD = motor_channel_IN_IDLE_d;
                    }
                    else if (localDW->temporalCounter_i2 >= (uint16_T)motor_channel_InstP_arg->longpress_cnt)
                    {
                        localDW->is_UP_KEY_PRESSED = motor_channel_IN_UP_LONGPRESS;
                        h_previousEvent = localDW->sfEvent;
                        localDW->sfEvent = motor_c_event_up_key_long_press;
                        if (localDW->is_active_MOTOR != 0U)
                        {
                            motor_channel_MOTOR(rty_up_relay, rty_down_relay, motor_channel_M, localDW);
                        }

                        localDW->sfEvent = h_previousEvent;
                    }
                    break;

                  case motor_channel_IN_UP_DEBOUNCE:
                    if (localDW->temporalCounter_i2 >= (uint16_T)motor_channel_InstP_arg->debounce_cnt)
                    {
                        localDW->is_UP_KEY_PRESSED = motor_channel_IN_UP_CLICK;
                        localDW->temporalCounter_i2 = 0U;
                    }
                    else if (Switch1 != 1)
                    {
                        localDW->is_UP_KEY_PRESSED = motor_channe_IN_NO_ACTIVE_CHILD;
                        localDW->is_KEY_CMD = motor_channel_IN_IDLE_d;
                    }
                    break;

                  case motor_channel_IN_UP_LONGPRESS:
                    if (Switch1 != 1)
                    {
                        localDW->is_UP_KEY_PRESSED = motor_channe_IN_NO_ACTIVE_CHILD;
                        localDW->is_KEY_CMD = motor_channel_IN_IDLE_d;
                    }
                    break;
                }
                break;
            }
        }

        if (localDW->is_active_MOTOR != 0U)
        {
            motor_channel_MOTOR(rty_up_relay, rty_down_relay, motor_channel_M, localDW);
        }
    }
}
