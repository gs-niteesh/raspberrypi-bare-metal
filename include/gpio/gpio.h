#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

/*
 * Data structures to capture pin characteristics.
 */
typedef enum{
    INPUT   = 0b000,
    OUTPUT  = 0b001,
    ALTFUN0 = 0b100,
    ALTFUN1 = 0b101,
    ALTFUN2 = 0b110,
    ALTFUN3 = 0b111,
    ALTFUN4 = 0b011,
    ALTFUN5 = 0b010,
}PINMODE;

typedef enum{
    LOW,
    HIGH
}LEVEL;

typedef enum{
    PUD_DISABLE,
    PULLDOWN,
    PULLUP
}PULLMODE;

/*
 * GPIO set pin mode.
 */
void gpio_set_pin_mode(uint8_t pin, PINMODE mode);

/*
 * GPIO set resistor mode.
 */
void gpio_set_resistor_mode(uint8_t pin, PULLMODE mode);

/*
 * GPIO set pin.
 * sets the pin HIGH.
 */
void gpio_set_pin(uint8_t pin);

/*
 * GPIO set pin.
 * sets the pin LOW.
 */
void gpio_clear_pin(uint8_t pin);

/*
 * GPIO get pin.
 * gets the current state of pin (HIGH(1) or LOW(0)) 
 */
int gpio_get_pin(uint8_t pin);


/*
 * Register definitions
 */

/*
 * GPIO function select registers
 */
#define GPFSEL0   (volatile uint32_t *)0x3F200000 
#define GPFSEL1   (volatile uint32_t *)0x3F200004 
#define GPFSEL2   (volatile uint32_t *)0x3F200008 
#define GPFSEL3   (volatile uint32_t *)0x3F20000C 
#define GPFSEL4   (volatile uint32_t *)0x3F200010 
#define GPFSEL5   (volatile uint32_t *)0x3F200014  

 /*
 * GPIO pin output set register
 */
#define GPFSET0   (volatile uint32_t *)0x3F20001C 
#define GPFSET1   (volatile uint32_t *)0x3F200020  

/*
 * GPIO pin output clear register
 */
#define GPFCLR0   (volatile uint32_t *)0x3F200028 
#define GPFCLR1   (volatile uint32_t *)0x3F20002C

/*
 * GPIO pin level register
 */
#define GPLEV0    (volatile uint32_t *)0x3F200034 
#define GPLEV1    (volatile uint32_t *)0x3F200038 

/*
 * GPIO pin event detect status register 
 */
#define GPEDS0    (volatile uint32_t *)0x3F200040 
#define GPEDS1    (volatile uint32_t *)0x3F200044 

/*
 * GPIO pin rising edge detect status register 
 */
#define GPREN0    (volatile uint32_t *)0x3F20004C 
#define GPREN1    (volatile uint32_t *)0x3F200050 

/*
 * GPIO pin falling edge detect status register 
 */
#define GPFEN0    (volatile uint32_t *)0x3F200058 
#define GPFEN1    (volatile uint32_t *)0x3F20005C 

/*
 * GPIO pin high detect enable 0
 */
#define GPHEN0    (volatile uint32_t *)0x3F200064 
#define GPHEN1    (volatile uint32_t *)0x3F200068 

/*
 * GPIO pin high detect enable 1
 */
#define GPLEN0    (volatile uint32_t *)0x3F200070 
#define GPLEN1    (volatile uint32_t *)0x3F200074 

/*
 * GPIO pin async rising edge detect status register 
 */
#define GPAREN0   (volatile uint32_t *)0x3F20007C 
#define GPAREN1   (volatile uint32_t *)0x3F200080 

/*
 *GPIO pin falling rising edge detect status register 
 */
#define GPAFEN0   (volatile uint32_t *)0x3F200088 
#define GPAFEN1   (volatile uint32_t *)0x3F20008C 

/*
 * GPIO pin pull up/down enable
 */
#define GPPUD     (volatile uint32_t *)0x3F200094 

/*
 * GPIO pin pull up/down enable clock
 */
#define GPPUDCLK0 (volatile uint32_t *)0x3F200098 
#define GPPUDCLK1 (volatile uint32_t *)0x3F20009C 

#endif