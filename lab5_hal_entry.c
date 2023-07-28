#include "new_thread0.h"
#include <stdio.h>
#include <string.h>
double slope = 6.26;
double V_s;
char T[90];
double temperature;
float value = 1.0;
adc_data_size_t adc_data;
void new_thread0_entry(void)
{
    ssp_err_t err;
    ssp_err_t status;
    while(1)
    {
        status = g_adc0.p_api -> open (g_adc0.p_ctrl, g_adc0.p_cfg);
        status = g_adc0.p_api -> scanCfg (g_adc0.p_ctrl, g_adc0.p_channel_cfg);
        status = g_adc0.p_api -> scanStart (g_adc0.p_ctrl);
        g_adc0.p_api -> read (g_adc0.p_ctrl, ADC_REG_TEMPERATURE, &adc_data);
        V_s = adc_data * 3.3 / 4095;
        temperature = slope * V_s;
        snprintf(T, sizeof(T), "value of variable is %f\r\n", temperature);
        g_sf_comms.p_api -> write (g_sf_comms0.p_ctrl, T, (uint32_t) strlen ((const char*)T, TX_NO_WAIT);
    }
}
