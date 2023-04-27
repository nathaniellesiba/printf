#ifndef our_printf
#define our_printf
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
* struct specifier - struct specifier
* @valid: the valid character.
* @f: the functions associated.
*
*/
typedef struct specifier
{
char *valid;
int (*f)(va_list);
} spec;
int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_d(va_list args);
int print_i(va_list args);
int _putchar(char c);
int print_percent(va_list args);
int (*get_func(char x))(va_list args);
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_binary(unsigned int n);
int my_printf(const char *format, ...);
int print_u(unsigned int n, int base, int is_uppercase);
int print_o(unsigned int n);
int print_x(unsigned int n, int is_uppercase);
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);
int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);


/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size);

#endif
