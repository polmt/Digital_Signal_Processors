#include "hal_data.h"
void hal_entry(void)
{
    // 1) MSTPCRD (module stop control register D)
    volatile uint32_t *MSTPCRD = (uint32_t *) 0x40047008;
    *MSTPCRD &= (uint32_t) ~(1<<6);

    // 2) GTUDDTYC (general PWM timer count direction and duty setting register)
    volatile uint32_t *GTUDDTYC = (uint32_t *) 0x40078830;
    *GTUDDTYC &= (uint32_t) 0;
    *GTUDDTYC |= (uint32_t) (1<<0);

    // 3) GTPR (general PWM timer cycle setting register)
    volatile uint32_t *GTPR = (uint32_t *) 0x40078864;
    *GTPR = (uint32_t) 0x1D4BF;

    // 4) GTCCRA (general PWM timer compare capture register A)
    volatile uint32_t *GTCCRA = (uint32_t *) 0x4007884c;
    *GTCCRA = (uint32_t) 0x752F; //25%
    //*GTCCRA = (uint32_t) 0xEA60; //50%
    //*GTCCRA = (uint32_t) 0x15F90; //75%

    // 5) GTIOR (general PWM timer I/O control register)
    volatile uint32_t *GTIOR = (uint32_t *) 0x40078834;
    *GTIOR |= (uint32_t) (1<<0 | 1<<3 | 1<<4 |1<<8);

    // 6) GTCR (general PWM timer control register)
    volatile uint32_t *GTCR = (uint32_t *) 0x4007882c;
    *GTCR |= (uint32_t) (1<<0);

    // 7) a)PWPR (write protect register)
    volatile uint8_t *PWPR = (uint8_t *) 0x40040d03;
    *PWPR = (uint8_t) 0;
    *PWPR = (uint8_t) 0x40;

    // 7) b) P107PFS (port 107 pin function select register)
    volatile uint32_t *P107PFS = (uint32_t *) 0x4004085C;
    *P107PFS |= (uint32_t) (1<<16 | 1<<24 | 1<<25);
}
