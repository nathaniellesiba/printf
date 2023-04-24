#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/*Return printed character numbers
*_putchar - writing character c to stdout
*@c: the charater to print
*
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
}*/

void print_buffer(char buffer[], int *buff_ind);
/*_printf - PRINTF FUNCTION
*@format: This is the format call
*Return: printed chars
*/
int _printf(const char *format, ...)
{int i, printed = 0, printed_char = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0';i++)
{if (format[i] != '%')
{buffer[buff_ind++ = format[i];
if(buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
printed_chars++;
}
else
{print_buffer(buffer, &buff_ind);
flags = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;
printed = handle_print(format, &i, list, buffer, flags, width, precision, size);
if(printed == -1)
return (-1);
printed_chars += printed;
}
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_chars);
}

/*print_buffer
 * @buffer: char arrays
 * @buff_ind: indexing
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0
}
