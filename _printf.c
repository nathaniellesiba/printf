#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/*
*print - printing characters
*@args: character args
*return: number of characters
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
char c, *s;
va_start(args, format);
while (*format != '\0') {
if (*format == '%') {
format++;
switch (*format) {
case 'c':
c = va_arg(args, int);
putchar(c);
count++;
break;
case 's':
s = va_arg(args, char *);
while (*s != '\0') {
putchar(*s);
s++;
count++;
}
break;
case '%':
putchar('%');
count++;
break;
}
} else {
putchar(*format);
count++;
}
format++;
}
va_end(args);
return count;
}
int main(void)
{
int count;
count = _printf("Hello, %s! The answer is %d%c.\n", "world", 42, '%');
printf("Number of characters printed: %d\n", count);
return 0;
}

/*
*Custom function to convert
*unsigned int to binary
*/
void int_to_binary(unsigned int num)
{
if (num > 1)
int_to_binary(num / 2);
printf("%d", num % 2);
}
/*
*Custom printf function
*to handle b conversion specifier
*/
void custom_printf(char* format, ...)
{
/*Initialize arguments*/
va_list arg;
int i, val;
char c;
/*Start variable argument list*/
va_start(arg, format);
/*Loop through format string*/
for (i = 0; format[i] != '\0'; i++)
{
/*Check for conversion specifier*/
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'b':   /*Convert unsigned int to binary*/
val = va_arg(arg, unsigned int);
int_to_binary(val);
break;
default:
printf("Error: Unsupported conversion specifier %%%c\n", format[i]);
break;
}
}
else
{
/*Print regular character*/
putchar(format[i]);
}
}
/*End variable argument list*/
va_end(arg);
}
