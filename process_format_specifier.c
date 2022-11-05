#include "main.h"

/**
 * process_format_specifier - figure out which kind of string we're printing
 * @token: char
 * @arg: argument type va_list
 * Return: int
 */
int process_format_specifier(const char token, va_list arg)
{
	int place_in_table = 0;
	int which_function = 0;

	specifier_s format_specifier[] = {
		{'c', print_character},
		{'s', print_string},
		{'i', print_integer},
		{'d', print_integer},
		{'%', print_percent_sign},
		{0, NULL}
	};

	while (format_specifier[place_in_table].token)
	{
		if (format_specifier[place_in_table].token == token)
		{
			which_function = which_function + format_specifier[place_in_table].function(arg);
			return (which_function);
		}
		place_in_table++;
	}
	if (format_specifier[0].token != token)
	{
		_putchar('%');
		_putchar(token);
		return (2);
	}
	return (0);
}
