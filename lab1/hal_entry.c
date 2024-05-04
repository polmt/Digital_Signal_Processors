#include "hal_data.h"
void hal_entry(void)
{
    bsp_leds_t Leds;
    R_BSP_LedsGet(&Leds);
    int i;
    while(1)
    {
        for (i=0; i<3; i++)
        {
            g_ioport.p_api -> pinWrite(Leds.p_leds[i], IOPORT_LEVEL_LOW);
            R_BSP_SoftwareDelay(250, BSP_DELAY_UNITS_MILLISECONDS);
            g_ioport.p_api -> pinWrite(Leds.p_leds[i], IOPORT_LEVEL_HIGH);
            R_BSP_SoftwareDelay(250, BSP_DELAY_UNITS_MILLISECONDS);
        }
    }
}
