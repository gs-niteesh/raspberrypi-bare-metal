#include <gpio/gpio.h>
#include <uart/uart.h>
#include <util/util.h>
#include <util/printf.h>

/*
 * Blink LED (GPIO PIN:24)
 */
void main()
{
    const int pin = 24;

    gpio_set_pin_mode(pin, OUTPUT);

    while (1)
    {
        gpio_set_pin(pin);
        __delay(1000000);
        gpio_clear_pin(pin);
        __delay(1000000);
    }
}