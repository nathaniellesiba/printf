#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
* _printf - Printf function
* @format: format.
* Return: Printed chars.
*/
#include "main.h"
/************************* WRITE HANDLE *************************/
/**
* handle_write_char - Prints a string
* @c: char types.
* @buffer: Buffer array to handle print
* @flags: Calculates active flags.
* @width: get width.
* @precision: precision specifier
* @size: Size specifier
**
Return: Number of chars printed.
*/
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
int i = 0;
char padd = ' ';
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
#include "main.h"
/************************* WRITE HANDLE *************************/
/**
* handle_write_char - Prints a string
* @c: char types.
* @buffer: Buffer array to handle print
* @flags: Calculates active flags.
* @width: get width.
* @precision: precision specifier
* @size: Size specifier
**
Return: Number of chars printed.
*/
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
int i = 0;
char padd = ' ';
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
* print_buffer - Prints the contents of the buffer if it exist
* @buffer: Array of chars
* @buff_ind: Index at which to add next char, represents the length.
*/
#include "main.h"
/************************* WRITE HANDLE *************************/
/**
* handle_write_char - Prints a string
* @c: char types.
* @buffer: Buffer array to handle print
* @flags: Calculates active flags.
* @width: get width.
* @precision: precision specifier
* @size: Size specifier
**
Return: Number of chars printed.
*/
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
int i = 0;
char padd = ' ';
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}
#include "main.h"
/************************* WRITE HANDLE *************************/
/**
* handle_write_char - Prints a string
* @c: char types.
* @buffer: Buffer array to handle print
* @flags: Calculates active flags.
* @width: get width.
* @precision: precision specifier
* @size: Size specifier
**
Return: Number of chars printed.
*/
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
int i = 0;
char padd = ' ';
