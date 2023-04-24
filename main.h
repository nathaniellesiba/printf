#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(X) (void) (X)

/*
*referencing previous prject
*/
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
/*
*structure
*
*@fmt: format description
*@fn: associated first function
*/
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};

/*
*TYPE OF DEFINED STRUCTURE
*
*@fmt: format description
*@fm_t: associated second function
*/
typedef struct fmt fmt_t;

/*
*provided prototype
*/
int _printf(const char *format, ...);

/*
*function extension from STRUCTURE above
*/
int handle_print (const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS *********************/
/* more functions for printing char and strings and numbers*/
int print_char(va_list typrs, char buffer[],
int flags, int width, int precision, int size;
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size;
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size;
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size;
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size;
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size;
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size;
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size;
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size;
int print_hexa(va_list types, char map_to[],
char[], int flags, char flag_ch, int width, int precision, int size;

/*for not printing functions*/
int print_non_print(va_list types, char buffer[];
/*for handlers*/
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char buffer[], int flags, int width, int precesion,
int length, char padd, char extra_c);

/*for POINTERS or MEMORY*/
int write_pointer(char buffer[], int ind, int length,
int width, int flags, int precision, int size);
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*for ADHOC like REVERSE or ROT and OTHERS*/
int print_reverse(va_list types, char buffer[]
int flags, int width, int precision, int size
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size;
int write_unsgnd(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size;
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
#endif
