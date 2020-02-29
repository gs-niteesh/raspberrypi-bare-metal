#ifndef GENERIC_H
#define GENERIC_H

#define BIT(x) (1 << x)

#define SET_REG(x, val) (*x = val)
#define GET_REG(x) (*x)

inline void __delay_by_clock(int delay)
{
    while(--delay) __asm("nop");
}

#endif