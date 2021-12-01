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

InstP_motor_channel_T motor_channel_InstP =
{

    4,

    6000,

    100,

    20,

    50
};

DW_motor_channel_T motor_channel_DW;
ExtU_motor_channel_T motor_channel_U;
ExtY_motor_channel_T motor_channel_Y;
static void motor_channel_MOTOR(const int32_T *sfEvent);
static void motor_channel_MOTOR(const int32_T *sfEvent)
{
    switch (motor_channel_DW.is_MOTOR)
    {
      case motor_channel_IN_DOWN_TO_LONGUP:
        if (motor_channel_DW.temporalCounter_i3 >= (uint16_T)motor_channel_InstP.transfer_cnt)
        {
            motor_channel_DW.is_MOTOR = motor_channel_IN_LONG_UP;
            motor_channel_DW.temporalCounter_i3 = 0U;
            motor_channel_Y.up_relay = 1;
        }
        break;

      case motor_channel_IN_LONG_DOWN:
        if ((*sfEvent == motor_chan_event_down_key_click) || (*sfEvent == motor_channe_event_up_key_click) || (*sfEvent ==
                motor_channel_event_stop_event) || (motor_channel_DW.temporalCounter_i3 >= (uint16_T)motor_channel_InstP.long_cnt))
        {
            motor_channel_Y.down_relay = 0;
            motor_channel_DW.is_MOTOR = motor_channel_IN_OFF;
        }
        else if ((*sfEvent == motor_c_event_up_key_long_press) || (*sfEvent == motor_chann_event_long_up_event))
        {
            motor_channel_Y.down_relay = 0;
            motor_channel_DW.is_MOTOR = motor_channel_IN_DOWN_TO_LONGUP;
            motor_channel_DW.temporalCounter_i3 = 0U;
        }
        break;

      case motor_channel_IN_LONG_UP:
        if ((*sfEvent == motor_event_down_key_long_press) || (*sfEvent == motor_cha_event_long_down_event))
        {
            motor_channel_Y.up_relay = 0;
            motor_channel_DW.is_MOTOR = motor_channel_IN_UP_TO_LONGDOWN;
            motor_channel_DW.temporalCounter_i3 = 0U;
        }
        else if ((*sfEvent == motor_channe_event_up_key_click) || (*sfEvent == motor_chan_event_down_key_click) || (*sfEvent ==
                  motor_channel_event_stop_event) || (motor_channel_DW.temporalCounter_i3 >= (uint16_T)motor_channel_InstP.long_cnt))
        {
            motor_channel_Y.up_relay = 0;
            motor_channel_DW.is_MOTOR = motor_channel_IN_OFF;
        }
        break;

      case motor_channel_IN_OFF:
        if ((*sfEvent == motor_channe_event_up_key_click) || (*sfEvent == motor_chan_event_short_up_event))
        {
            motor_channel_DW.is_MOTOR = motor_channel_IN_SHORT_UP_m;
            motor_channel_DW.temporalCounter_i3 = 0U;
            motor_channel_Y.up_relay = 1;
        }
        else if ((*sfEvent == motor_c_event_up_key_long_press) || (*sfEvent == motor_chann_event_long_up_event))
        {
            motor_channel_DW.is_MOTOR = motor_channel_IN_LONG_UP;
            motor_channel_DW.temporalCounter_i3 = 0U;
            motor_channel_Y.up_relay = 1;
        }
        else if ((*sfEvent == motor_chan_event_down_key_click) || (*sfEvent == motor_ch_event_short_down_event))
        {
            motor_channel_DW.is_MOTOR = motor_channel_IN_SHORT_DOWN_f;
            motor_channel_DW.temporalCounter_i3 = 0U;
            motor_channel_Y.down_relay = 1;
        }
        else if ((*sfEvent == motor_event_down_key_long_press) || (*sfEvent == motor_cha_event_long_down_event))
        {
            motor_channel_DW.is_MOTOR = motor_channel_IN_LONG_DOWN;
            motor_channel_DW.temporalCounter_i3 = 0U;
            motor_channel_Y.down_relay = 1;
        }
        break;

      case motor_channel_IN_SHORT_DOWN_f:
        if (motor_channel_DW.temporalCounter_i3 >= (uint16_T)motor_channel_InstP.short_cnt)
        {
            motor_channel_Y.down_relay = 0;
            motor_channel_DW.is_MOTOR = motor_channel_IN_OFF;
        }
        break;

      case motor_channel_IN_SHORT_UP_m:
        if (motor_channel_DW.temporalCounter_i3 >= (uint16_T)motor_channel_InstP.short_cnt)
        {
            motor_channel_Y.up_relay = 0;
            motor_channel_DW.is_MOTOR = motor_channel_IN_OFF;
        }
        break;

      case motor_channel_IN_UP_TO_LONGDOWN:
        if (motor_channel_DW.temporalCounter_i3 >= (uint16_T)motor_channel_InstP.transfer_cnt)
        {
            motor_channel_DW.is_MOTOR = motor_channel_IN_LONG_DOWN;
            motor_channel_DW.temporalCounter_i3 = 0U;
            motor_channel_Y.down_relay = 1;
        }
        break;
    }
}

void motor_channel_step(void)
{
    int32_T sfEvent;
    int16_T Switch1;
    int16_T Switch2;
    boolean_T Switch3;
    boolean_T Switch4;
    boolean_T Switch5;
    boolean_T Switch6;
    boolean_T Switch7;
    if (motor_channel_U.com_only != 0)
    {
        Switch1 = 0;
        Switch3 = ((motor_channel_U.ch_coms[0] != 0) || (motor_channel_U.gp_coms[0] != 0));
        Switch4 = ((motor_channel_U.ch_coms[1] != 0) || (motor_channel_U.gp_coms[1] != 0));
        Switch5 = ((motor_channel_U.ch_coms[2] != 0) || (motor_channel_U.gp_coms[2] != 0));
        Switch6 = ((motor_channel_U.ch_coms[3] != 0) || (motor_channel_U.gp_coms[3] != 0));
        Switch2 = 0;
        Switch7 = ((motor_channel_U.ch_coms[4] != 0) || (motor_channel_U.gp_coms[4] != 0));
    }
    else
    {
        Switch1 = (int16_T)((motor_channel_U.ch_btns[0] != 0) || (motor_channel_U.gp_btns[0] != 0));
        Switch3 = ((motor_channel_U.ch_coms[0] != 0) || (motor_channel_U.gp_coms[0] != 0) || ((motor_channel_U.ch_rmts[0] != 0) ||
                    (motor_channel_U.gp_rmts[0] != 0)));
        Switch4 = ((motor_channel_U.ch_coms[1] != 0) || (motor_channel_U.gp_coms[1] != 0) || ((motor_channel_U.ch_rmts[1] != 0) ||
                    (motor_channel_U.gp_rmts[1] != 0)));
        Switch5 = ((motor_channel_U.ch_coms[2] != 0) || (motor_channel_U.gp_coms[2] != 0) || ((motor_channel_U.ch_rmts[2] != 0) ||
                    (motor_channel_U.gp_rmts[2] != 0)));
        Switch6 = ((motor_channel_U.ch_coms[3] != 0) || (motor_channel_U.gp_coms[3] != 0) || ((motor_channel_U.ch_rmts[3] != 0) ||
                    (motor_channel_U.gp_rmts[3] != 0)));
        Switch2 = (int16_T)((motor_channel_U.ch_btns[1] != 0) || (motor_channel_U.gp_btns[1] != 0));
        Switch7 = ((motor_channel_U.ch_coms[4] != 0) || (motor_channel_U.gp_coms[4] != 0) || ((motor_channel_U.ch_rmts[4] != 0) ||
                    (motor_channel_U.gp_rmts[4] != 0)));
    }

    sfEvent = motor_channel_CALL_EVENT;
    if (motor_channel_DW.temporalCounter_i1 < 32767U)
    {
        motor_channel_DW.temporalCounter_i1++;
    }

    if (motor_channel_DW.temporalCounter_i2 < 32767U)
    {
        motor_channel_DW.temporalCounter_i2++;
    }

    if (motor_channel_DW.temporalCounter_i3 < 32767U)
    {
        motor_channel_DW.temporalCounter_i3++;
    }

    if (motor_channel_DW.is_active_c3_motor_channel == 0U)
    {
        motor_channel_DW.is_active_c3_motor_channel = 1U;
        motor_channel_DW.is_c3_motor_channel = motor_channel_IN_MOTOR_CTRL;
        motor_channel_DW.is_active_COM_CMD = 1U;
        motor_channel_DW.is_COM_CMD = motor_channel_IN_IDLE;
        motor_channel_DW.is_active_KEY_CMD = 1U;
        motor_channel_DW.is_KEY_CMD = motor_channel_IN_IDLE_d;
        motor_channel_DW.is_active_MOTOR = 1U;
        motor_channel_DW.is_MOTOR = motor_channel_IN_OFF;
    }
    else if (motor_channel_DW.is_c3_motor_channel == 1)
    {
        if (motor_channel_DW.is_active_COM_CMD != 0U)
        {
            switch (motor_channel_DW.is_COM_CMD)
            {
              case motor_channel_IN_IDLE:
                if (Switch7)
                {
                    motor_channel_DW.is_COM_CMD = motor_channel_IN_LONG_DOWN;
                    motor_channel_DW.temporalCounter_i1 = 0U;
                    sfEvent = motor_cha_event_long_down_event;
                    if (motor_channel_DW.is_active_MOTOR != 0U)
                    {
                        motor_channel_MOTOR(&sfEvent);
                    }

                    sfEvent = motor_channel_CALL_EVENT;
                }
                else if (Switch5)
                {
                    motor_channel_DW.is_COM_CMD = motor_channel_IN_STOP;
                    motor_channel_DW.temporalCounter_i1 = 0U;
                    sfEvent = motor_channel_event_stop_event;
                    if (motor_channel_DW.is_active_MOTOR != 0U)
                    {
                        motor_channel_MOTOR(&sfEvent);
                    }

                    sfEvent = motor_channel_CALL_EVENT;
                }
                else if (Switch3)
                {
                    motor_channel_DW.is_COM_CMD = motor_channel_IN_SHORT_UP;
                    motor_channel_DW.temporalCounter_i1 = 0U;
                    sfEvent = motor_chan_event_short_up_event;
                    if (motor_channel_DW.is_active_MOTOR != 0U)
                    {
                        motor_channel_MOTOR(&sfEvent);
                    }

                    sfEvent = motor_channel_CALL_EVENT;
                }
                else if (Switch4)
                {
                    motor_channel_DW.is_COM_CMD = motor_channel_IN_LONG_UP;
                    motor_channel_DW.temporalCounter_i1 = 0U;
                    sfEvent = motor_chann_event_long_up_event;
                    if (motor_channel_DW.is_active_MOTOR != 0U)
                    {
                        motor_channel_MOTOR(&sfEvent);
                    }

                    sfEvent = motor_channel_CALL_EVENT;
                }
                else if (Switch6)
                {
                    motor_channel_DW.is_COM_CMD = motor_channel_IN_SHORT_DOWN;
                    motor_channel_DW.temporalCounter_i1 = 0U;
                    sfEvent = motor_ch_event_short_down_event;
                    if (motor_channel_DW.is_active_MOTOR != 0U)
                    {
                        motor_channel_MOTOR(&sfEvent);
                    }

                    sfEvent = motor_channel_CALL_EVENT;
                }
                break;

              case motor_channel_IN_LONG_DOWN:
                if (motor_channel_DW.temporalCounter_i1 >= (uint16_T)motor_channel_InstP.short_cnt)
                {
                    motor_channel_DW.is_COM_CMD = motor_channel_IN_IDLE;
                }
                break;

              case motor_channel_IN_LONG_UP:
                if (motor_channel_DW.temporalCounter_i1 >= (uint16_T)motor_channel_InstP.short_cnt)
                {
                    motor_channel_DW.is_COM_CMD = motor_channel_IN_IDLE;
                }
                break;

              case motor_channel_IN_SHORT_DOWN:
                if (motor_channel_DW.temporalCounter_i1 >= (uint16_T)motor_channel_InstP.short_cnt)
                {
                    motor_channel_DW.is_COM_CMD = motor_channel_IN_IDLE;
                }
                break;

              case motor_channel_IN_SHORT_UP:
                if (motor_channel_DW.temporalCounter_i1 >= (uint16_T)motor_channel_InstP.short_cnt)
                {
                    motor_channel_DW.is_COM_CMD = motor_channel_IN_IDLE;
                }
                break;

              case motor_channel_IN_STOP:
                if (motor_channel_DW.temporalCounter_i1 >= (uint16_T)motor_channel_InstP.short_cnt)
                {
                    motor_channel_DW.is_COM_CMD = motor_channel_IN_IDLE;
                }
                break;
            }
        }

        if (motor_channel_DW.is_active_KEY_CMD != 0U)
        {
            switch (motor_channel_DW.is_KEY_CMD)
            {
              case motor_chann_IN_DOWN_KEY_PRESSED:
                switch (motor_channel_DW.is_DOWN_KEY_PRESSED)
                {
                  case motor_channel_IN_DOWN_CLICK:
                    if (Switch2 != 1)
                    {
                        sfEvent = motor_chan_event_down_key_click;
                        if (motor_channel_DW.is_active_MOTOR != 0U)
                        {
                            motor_channel_MOTOR(&sfEvent);
                        }

                        sfEvent = -1;
                        motor_channel_DW.is_DOWN_KEY_PRESSED = motor_channe_IN_NO_ACTIVE_CHILD;
                        motor_channel_DW.is_KEY_CMD = motor_channel_IN_IDLE_d;
                    }
                    else if (motor_channel_DW.temporalCounter_i2 >= (uint16_T)motor_channel_InstP.longpress_cnt)
                    {
                        motor_channel_DW.is_DOWN_KEY_PRESSED = motor_channel_IN_DOWN_LONGPRESS;
                        sfEvent = motor_event_down_key_long_press;
                        if (motor_channel_DW.is_active_MOTOR != 0U)
                        {
                            motor_channel_MOTOR(&sfEvent);
                        }

                        sfEvent = -1;
                    }
                    break;

                  case motor_channel_IN_DOWN_DEBOUNCE:
                    if (motor_channel_DW.temporalCounter_i2 >= (uint16_T)motor_channel_InstP.debounce_cnt)
                    {
                        motor_channel_DW.is_DOWN_KEY_PRESSED = motor_channel_IN_DOWN_CLICK;
                        motor_channel_DW.temporalCounter_i2 = 0U;
                    }
                    else if (Switch2 != 1)
                    {
                        motor_channel_DW.is_DOWN_KEY_PRESSED = motor_channe_IN_NO_ACTIVE_CHILD;
                        motor_channel_DW.is_KEY_CMD = motor_channel_IN_IDLE_d;
                    }
                    break;

                  case motor_channel_IN_DOWN_LONGPRESS:
                    if (Switch2 != 1)
                    {
                        motor_channel_DW.is_DOWN_KEY_PRESSED = motor_channe_IN_NO_ACTIVE_CHILD;
                        motor_channel_DW.is_KEY_CMD = motor_channel_IN_IDLE_d;
                    }
                    break;
                }
                break;

              case motor_channel_IN_IDLE_d:
                if (Switch1 == 1)
                {
                    motor_channel_DW.is_KEY_CMD = motor_channel_IN_UP_KEY_PRESSED;
                    motor_channel_DW.is_UP_KEY_PRESSED = motor_channel_IN_UP_DEBOUNCE;
                    motor_channel_DW.temporalCounter_i2 = 0U;
                }
                else if (Switch2 == 1)
                {
                    motor_channel_DW.is_KEY_CMD = motor_chann_IN_DOWN_KEY_PRESSED;
                    motor_channel_DW.is_DOWN_KEY_PRESSED = motor_channel_IN_DOWN_DEBOUNCE;
                    motor_channel_DW.temporalCounter_i2 = 0U;
                }
                break;

              case motor_channel_IN_UP_KEY_PRESSED:
                switch (motor_channel_DW.is_UP_KEY_PRESSED)
                {
                  case motor_channel_IN_UP_CLICK:
                    if (Switch1 != 1)
                    {
                        sfEvent = motor_channe_event_up_key_click;
                        if (motor_channel_DW.is_active_MOTOR != 0U)
                        {
                            motor_channel_MOTOR(&sfEvent);
                        }

                        sfEvent = -1;
                        motor_channel_DW.is_UP_KEY_PRESSED = motor_channe_IN_NO_ACTIVE_CHILD;
                        motor_channel_DW.is_KEY_CMD = motor_channel_IN_IDLE_d;
                    }
                    else if (motor_channel_DW.temporalCounter_i2 >= (uint16_T)motor_channel_InstP.longpress_cnt)
                    {
                        motor_channel_DW.is_UP_KEY_PRESSED = motor_channel_IN_UP_LONGPRESS;
                        sfEvent = motor_c_event_up_key_long_press;
                        if (motor_channel_DW.is_active_MOTOR != 0U)
                        {
                            motor_channel_MOTOR(&sfEvent);
                        }

                        sfEvent = -1;
                    }
                    break;

                  case motor_channel_IN_UP_DEBOUNCE:
                    if (motor_channel_DW.temporalCounter_i2 >= (uint16_T)motor_channel_InstP.debounce_cnt)
                    {
                        motor_channel_DW.is_UP_KEY_PRESSED = motor_channel_IN_UP_CLICK;
                        motor_channel_DW.temporalCounter_i2 = 0U;
                    }
                    else if (Switch1 != 1)
                    {
                        motor_channel_DW.is_UP_KEY_PRESSED = motor_channe_IN_NO_ACTIVE_CHILD;
                        motor_channel_DW.is_KEY_CMD = motor_channel_IN_IDLE_d;
                    }
                    break;

                  case motor_channel_IN_UP_LONGPRESS:
                    if (Switch1 != 1)
                    {
                        motor_channel_DW.is_UP_KEY_PRESSED = motor_channe_IN_NO_ACTIVE_CHILD;
                        motor_channel_DW.is_KEY_CMD = motor_channel_IN_IDLE_d;
                    }
                    break;
                }
                break;
            }
        }

        if (motor_channel_DW.is_active_MOTOR != 0U)
        {
            motor_channel_MOTOR(&sfEvent);
        }
    }
}

void motor_channel_initialize(void)
{
}

void motor_channel_terminate(void)
{
}
