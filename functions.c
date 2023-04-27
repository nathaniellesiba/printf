#include <stdio.h>
#include <stdarg.h>
#include "main.h"

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
if (*format == 'c')
{
int c = va_arg(args, int);
putchar(c);
count++;
}
else if (*format == 's') 
{
char *s = va_arg(args, char *);
for (int i = 0; s[i] != '\0'; i++)
{
putchar(s[i]);
count++;
}
}
else if (*format == '%')
{
putchar('%');
count++;
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
