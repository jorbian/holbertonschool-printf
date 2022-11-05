#include "main.h"
/**
 *_printf - our own printf function
 *@format: the format specifier
 *Return: int
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int current_char = 0;
	int characters_printed = 0;
	int format_specifier = 0;

	va_start(arg, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	while (format[current_char] && format)
	{
		if (format[current_char] != '%')
		{
			_putchar(format[current_char]);
			characters_printed++;
		}
		if (format[current_char] == '%')
		{
			format_specifier = process_format_specifier(format[current_char + 1], arg);
			if (format_specifier)
			{
				characters_printed = characters_printed + format_specifier;
				current_char = current_char + 2;
				continue;
			}

			if (!format[current_char])
			{
				_putchar(format[current_char]);
				characters_printed++;
				return (-1);
			}
		}
		current_char++;
	}
	va_end(arg);
	return (characters_printed);
}
