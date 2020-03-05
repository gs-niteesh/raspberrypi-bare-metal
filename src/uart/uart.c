#include <gpio/gpio.h>
#include <uart/uart.h>
#include <util/util.h>

void mini_uart_init(uart_data *ud)
{

    SET_REG(AUX_ENABLES, GET_REG(AUX_ENABLES) | 0x1);
    SET_REG(AUX_MU_CNTL_REG, 0); // enable Tx, Rx

    SET_REG(AUX_MU_LCR_REG, 0x3);
    SET_REG(AUX_MU_MCR_REG, 0x0);
    SET_REG(AUX_MU_IER_REG, 0);
    SET_REG(AUX_MU_IIR_REG, 0xc6);
    SET_REG(AUX_MU_BAUD_REG, 270);

    gpio_set_pin_mode(14, ALTFUN5);
    gpio_set_pin_mode(15, ALTFUN5);
    gpio_set_resistor_mode(14, PUD_DISABLE);
    gpio_set_resistor_mode(15, PUD_DISABLE);

    SET_REG(AUX_MU_CNTL_REG, 3); // enable Tx, Rx

    putchar = &mini_uart_putc;
}

void mini_uart_putc(const char c)
{
    while (!(GET_REG(AUX_MU_LSR_REG) & 0x20));
    SET_REG(AUX_MU_IO_REG, c);
}

char mini_uart_getc()
{
    while (!(GET_REG(AUX_MU_LSR_REG) & 0x1));
    return (char)GET_REG(AUX_MU_IO_REG);
}


/*
 * TODO
 */
void pl011_init(uart_data *ud)
{

}

void pl011_putc(char c)
{

}