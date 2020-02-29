#ifndef GENERIC_H
#define GENERIC_H

#define BIT(x) (1 << x)

#define SET_REG(x, val) (*x = val)
#define GET_REG(x) (*x)

#define __delay(delay) for(int i=0; i < delay; ++i) __asm("nop");

#endif