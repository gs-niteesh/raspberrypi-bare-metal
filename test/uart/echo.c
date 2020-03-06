#include <uart/uart.h>

void main()
{
    uart_data mini_uart = {
        .baudrate = 115200
    };

    const char *str = "Running Echo Program\n";

    mini_uart_init(&mini_uart);

    for(const char *c = str; *c != '\0'; c++){
        mini_uart_putc(*c);
    }

    while( 1 ) {
        char c = mini_uart_getc();
        mini_uart_putc(c == '\r' ? '\n' : c);
    }
}