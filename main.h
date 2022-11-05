#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

/**
 * struct  - format_specifier
 * @op: the symbole
 * @f: pointer to a function
 */
typedef struct format_specifier
{
	char token;
	int (*function)(va_list);
} specifier_s;

int _putchar(char c);
int process_format_specifier(const char c, va_list arg);
int print_character(va_list arg);
int print_string(va_list arg);
int print_percent_sign(va_list args);
int print_integer(va_list args);
void print_digit_by_digit(int number);
int _printf(const char *format, ...);

#endif

