#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
*_printf - Printf function
*@format: format.
*Return: Printed chars.
*/
int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
/* write(1, &format[i], 1);*/
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;
printed = handle_print(format, &i, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_chars);
}
/**
*print_buffer - Prints buffer contents
*@buffer: Array of chars
*@buff_ind: Indexing
*/
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}



/**
* _printf - recreates printf function
* @format: string with format specifier
* Return: number of characters printed
*/
int _printf(const char *format, ...)
{
if (format != NULL)
{
int count = 0, i;
int (*m)(va_list);
va_list args;

va_start(args, format);
i = 0;
if (format[0] == '%' && format[1] == '\0')
return (-1);
while (format != NULL && format[i] != '\0')
{
if (format[i] == '%')
{
if (format[i + 1] == '%')
{
count += _putchar(format[i]);
i += 2;
}
else
{
m = get_func(format[i + 1]);
if (m)
count += m(args);
else
count = _putchar(format[i]) + _putchar(format[i + 1]);
i += 2;
}
}
else
{
count += _putchar(format[i]);
i++;
}
}
va_end(args);
return (count);
}
return (-1);
}
