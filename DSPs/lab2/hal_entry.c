#include "hal_data.h"
void hal_entry(void)
{
    ioport_level_t pin_levels1;
    ioport_level_t pin_levels2;
    while(1)
    {
        g_ioport.p_api -> pinRead(IOPORT_PORT_00_PIN_06, &pin_levels1);
        g_ioport.p_api -> pinRead(IOPORT_PORT_00_PIN_05, &pin_levels2);
        g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_HIGH);
        g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_01, IOPORT_LEVEL_HIGH);
        g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_02, IOPORT_LEVEL_HIGH);
        if (pin_levels1==0 && pin_levels2==1)
        {
            g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_LOW);
        }
        else if (pin_levels1==0 && pin_levels2==1)
        {
            g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_01, IOPORT_LEVEL_LOW);
        }
        else if (pin_levels1==0 && pin_levels2==0)
        {
            g_ioport.p_api -> pinWrite(IOPORT_PORT_06_PIN_02, IOPORT_LEVEL_LOW);
        }
    }
}
