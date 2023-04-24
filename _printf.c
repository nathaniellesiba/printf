#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/*Return printed character numbers
*_putchar - writing character c to stdout
*@c: the charater to print
*/
void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
putchar(va_arg(args, int));
count++;
break;
case 's':
fputs(va_arg(args, char*), stdout);
count += strlen(va_arg(args, char*));
break;
case '%':
putchar('%');
count++;
break;
default:
break;
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);
return count;
}
