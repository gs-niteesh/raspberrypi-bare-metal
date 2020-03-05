#include <stdarg.h>
#include <uart/uart.h>

void print_integer(unsigned int num, int base);
void print_string(const char *str);

/*
 * Simple implementation of printf.
 */
void printf(char *format, ...)
{
    va_list arg;
    va_start(arg, format);

    for(char *ptr = format; *ptr != '\0';)
    {
        while (*ptr != '%' && *ptr != '\0') {
			putchar(*ptr);
            ptr++;
        }
		
		if (*ptr == '\0') {
			break;
		}

        ptr++;
        switch (*ptr)
        {
        case 'd':
            print_integer(va_arg(arg, unsigned int), 10);
            break;
        case 'b':
			putchar('0');
			putchar('b');
            print_integer(va_arg(arg, unsigned int), 2);
            break;
        case 'x':
			putchar('0');
			putchar('x');
            print_integer(va_arg(arg, unsigned int), 16);
            break;
        case 'c': ;
            char c = (char)va_arg(arg, unsigned int);
            putchar(c);
            break;
        case 's':
            print_string(va_arg(arg, char *));
            break;
        default:
            break;
        }
		ptr++;
    }
}

void print_integer(unsigned int num, int base)
{
	const char *cp = "0123456789abcdef";
	char buff[64] = { 0 };
	char *ptr = &buff[63];
    do {
    	int rem = num % base;
		*ptr-- = *(cp + rem);
        num /= base;
    }while (num > 0);

	while(ptr != &buff[64]) {
		putchar(*ptr++);
	}
}

void print_string(const char *str)
{
	for(const char *c = str; *c != '\0'; c++)
		putchar(*c);
}