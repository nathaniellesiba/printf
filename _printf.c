#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/*Return printed character numbers
*_putchar - writing character c to stdout
*@c: the charater to print
*/
typedef struct custom_printf {
char *buffer;
int buffer_size;
int buffer_index;
int num_chars_printed;
int error_flag;
} custom_printf_t;
void flush_buffer(custom_printf_t *custom_printf);
void print_char(custom_printf_t *custom_printf, char c);
void print_string(custom_printf_t *custom_printf, char *str);
void print_percent(custom_printf_t *custom_printf);
int _printf(const char *format, ...)
{
va_list args;
custom_printf_t custom_printf = {0};
custom_printf.buffer_size = 1024;
custom_printf.buffer = malloc(custom_printf.buffer_size);
va_start(args, format);
while (*format) {
if (*format == '%') {
format++;
switch (*format) {
case 'c':
print_char(&custom_printf, va_arg(args, int));
break;
case 's':
print_string(&custom_printf, va_arg(args, char *));
break;
case '%':
print_percent(&custom_printf);
break;
default:
custom_printf.error_flag = 1;
break;
}
} else {
print_char(&custom_printf, *format);
}
format++;
}
va_end(args);
flush_buffer(&custom_printf);
int num_chars_printed = custom_printf.num_chars_printed;
free(custom_printf.buffer);
return num_chars_printed;
}
void flush_buffer(custom_printf_t *custom_printf)
{
if (custom_printf->buffer_index > 0) {
write(1, custom_printf->buffer, custom_printf->buffer_index);
custom_printf->buffer_index = 0;
}
}
void print_char(custom_printf_t *custom_printf, char c)
{
if (custom_printf->buffer_index == custom_printf->buffer_size) {
flush_buffer(custom_printf);
}
custom_printf->buffer[custom_printf->buffer_index++] = c;
custom_printf->num_chars_printed++;
}
void print_string(custom_printf_t *custom_printf, char *str)
{
while (*str) {
print_char(custom_printf, *str++);
}
}
void print_percent(custom_printf_t *custom_printf)
{
print_char(custom_printf, '%');
}
