#include "main.h"

/**
* print_character - function that print a character
* @arg: asdf asdf asdf
* Return: 1
*/
int print_character(va_list arg)
{
	char character = (char)va_arg(arg, int);

	if (!character)
		return (0);

	_putchar(character);
	return (1);
}


/**
* print_string - function to print a string
* @arg: asdf asdf asdf
* Return: length of the string that was printed
*/
int print_string(va_list arg)
{
	int i;
	char *string = va_arg(arg, char *);

	if (!string)
	{
		string = "(null)";
		return (-1);
	}
	else
	{
		for (i = 0; string[i]; i++)
			_putchar(string[i]);
		return (i);
	}
}

/**
 * print_percent_sign - exactly what it says on the tin
 * @arg: the argument
 * Return: 1
 */
int print_percent_sign(va_list arg)
{
	(void)arg;

	_putchar('%');
	return (1);
}

/**
* print_integer - function that print a decimal or an integr number
* @arg: asdf asdf asdf
* Return: length of the string that was printed
*/
int print_integer(va_list arg)
{
	int number_of_digits;
	int number = 0;

	number = va_arg(arg, int);
	number_of_digits = (int)(log10(abs(number)) + 1);

	if (number < 0)
	{
		_putchar('-');
		number *= -1;
	}

	print_digit_by_digit(number);

	return (number_of_digits + 1);
}

/**
* print_digit_by_digit - Recursively prints an integer digit by digit
* @number: integer to printed
* Return: void
*/
void print_digit_by_digit(int number)
{
	if (number / 10)
		print_digit_by_digit(number / 10);
	_putchar(number % 10 +  '0');
}
