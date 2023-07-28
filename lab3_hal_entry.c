#include "hal_data.h"
volatile int flag=0;
double t;
int value;
void hal_entry(void)
{
    g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_HIGH);
    g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_01, IOPORT_LEVEL_HIGH);
    g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_02, IOPORT_LEVEL_HIGH);
    R_BSP_SoftwareDelay(2, BSP_DELAY_UNITS_SECONDS);
    g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_LOW);
    g_timer0.p_api -> open(g_timer0.p_ctrl, g_timer0.p_cfg);
    g_timer0.p_api -> start(g_timer0.p_ctrl);
    g_external_irq0.p_api -> open(g_external_irq0.p_ctrl, g_external_irq0.p_cfg);
    while(flag==0)
    {
    }
    g_timer0.p_api -> counterGet(g_timer0.p_ctrl, &value);
    t = value * (0.0000000083333333);
    g_timer0.p_api -> stop(g_timer0.p_ctrl);
}
void timer0_callback(timer_callback_args_t*p_args0)
{
    g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_LOW);
}
void switch_callback(external_irq_callback_args_t*p_args)
{
    flag=1;
}


#include "hal_data.h"
volatile int flag=0;
void hal_entry(void)
{
    g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_HIGH);
    g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_01, IOPORT_LEVEL_HIGH);
    g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_02, IOPORT_LEVEL_HIGH);
    g_timer0.p_api -> open(g_timer0.p_ctrl, g_timer0.p_cfg);
    g_timer0.p_api -> start(g_timer0.p_ctrl);
    g_timer1.p_api -> open(g_timer1.p_ctrl, g_timer1.p_cfg);
    g_timer1.p_api -> start(g_timer1.p_ctrl);
}
void timer0_callback(timer_callback_args_t*p_args0)
{
    g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_LOW);
}
void timer1_callback(timer_callback_args_t*p_args1)
{
    if (flag==0)
    {
        flag=1;
    }
    else
    {
        flag=0;
    }
    g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_01, flag);
}


#include "hal_data.h"
volatile int flag=0;
void hal_entry(void)
{
    bsp_leds_t Leds;
    R_BSP_LedsGet(&Leds);
    g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_HIGH);
    g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_01, IOPORT_LEVEL_HIGH);
    g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_02, IOPORT_LEVEL_HIGH);
    g_external_irq0.p_api -> open(g_external_irq0.p_ctrl, g_external_irq0.p_cfg);
    while(1)
    {
        if (flag==0)
        {
            g_ioport.p_api -> pinWrite(Leds.p_leds[0], IOPORT_LEVEL_LOW);
            R_BSP_SoftwareDelay(250, BSP_DELAY_UNITS_MILLISECONDS);
            g_ioport.p_api -> pinWrite(Leds.p_leds[0], IOPORT_LEVEL_HIGH);
            R_BSP_SoftwareDelay(250, BSP_DELAY_UNITS_MILLISECONDS);
        }
        else if (flag==1)
        {
            g_ioport.p_api -> pinWrite(Leds.p_leds[1], IOPORT_LEVEL_LOW);
            R_BSP_SoftwareDelay(250, BSP_DELAY_UNITS_MILLISECONDS);
            g_ioport.p_api -> pinWrite(Leds.p_leds[1], IOPORT_LEVEL_HIGH);
            R_BSP_SoftwareDelay(250, BSP_DELAY_UNITS_MILLISECONDS);
        }
    }
}
void switch_callback(external_irq_callback_args_t*p_args)
{
    if (flag==1)
    {
    }
}
