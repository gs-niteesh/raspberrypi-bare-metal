#include <gpio/gpio.h>
#include <util/util.h>

void gpio_set_pin_mode(uint8_t pin, PINMODE mode)
{
    if (pin < 0 || pin > 53)
        return;
    
    /*
     * GPIOSEL -> pin's function select register.
     */
    volatile uint32_t *GPIOSEL = GPFSEL0 + (pin / 10);
    uint8_t mask = (pin % 10) * 3;
    *GPIOSEL &= ~(0x7 << mask);
    *GPIOSEL |= (mode << mask);
}

void gpio_set_resistor_mode(uint8_t pin, PULLMODE mode)
{
    volatile uint32_t *reg;

    pin = (pin/32 == 0) ? pin : (pin-32);
    reg = (pin/32 == 0) ? GPPUDCLK0 : GPPUDCLK1;

    SET_REG(GPPUD, mode);
    __delay(150);

    SET_REG(reg, BIT(pin));
    __delay(150);
    SET_REG(reg, 0x0);
}

void gpio_set_pin(uint8_t pin)
{
    volatile uint32_t *reg;

    pin = (pin/32 == 0) ? pin : (pin-32);
    reg = (pin/32 == 0) ? GPFSET0 : GPFSET1;

    SET_REG(reg, BIT(pin));
}

void gpio_clear_pin(uint8_t pin)
{
    volatile uint32_t *reg;

    pin = (pin/32 == 0) ? pin : (pin-32);
    reg = (pin/32 == 0) ? GPFCLR0 : GPFCLR1;

    SET_REG(reg, BIT(pin));
}

int gpio_get_pin(uint8_t pin)
{
    volatile uint32_t *reg;

    pin = (pin/32 == 0) ? pin : (pin-32);
    reg = (pin/32 == 0) ? GPLEV0 : GPLEV1;

    uint32_t status = GET_REG(reg);
    return status & BIT(pin);
}