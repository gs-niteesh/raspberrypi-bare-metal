#ifndef UART_H
#define UART_H

#include <stdint.h>

typedef struct uart_data_t{
    int baudrate;
    int stopbits;
    int parity;
}uart_data;

/*
 * Functions to initialize the UART hardware.
 */
void mini_uart_init(uart_data *ud);
void pl011_uart_init(uart_data *ud);

void mini_uart_putc(char c);
char mini_uart_getc();

/*
 * Function to print a character to the correct
 * UART hardware.
 */
typedef void (*putchar_t)(const char c);
putchar_t putchar;

/*
 * Register Definitions
 */

#define AUX_IRQ 	    (volatile uint32_t *)0x3F215000 
#define AUX_ENABLES 	(volatile uint32_t *)0x3F215004 
#define AUX_MU_IO_REG 	(volatile uint32_t *)0x3F215040 
#define AUX_MU_IER_REG 	(volatile uint32_t *)0x3F215044 
#define AUX_MU_IIR_REG 	(volatile uint32_t *)0x3F215048 
#define AUX_MU_LCR_REG 	(volatile uint32_t *)0x3F21504C 
#define AUX_MU_MCR_REG 	(volatile uint32_t *)0x3F215050 
#define AUX_MU_LSR_REG 	(volatile uint32_t *)0x3F215054 
#define AUX_MU_MSR_REG 	(volatile uint32_t *)0x3F215058 
#define AUX_MU_SCRATCH 	(volatile uint32_t *)0x3F21505C 
#define AUX_MU_CNTL_REG (volatile uint32_t *)0x3F215060 
#define AUX_MU_STAT_REG (volatile uint32_t *)0x3F215064 
#define AUX_MU_BAUD_REG (volatile uint32_t *)0x3F215068 

#endif