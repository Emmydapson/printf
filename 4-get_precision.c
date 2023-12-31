#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: The formatted string containig conversion specifiers
 * @i: current index in the format string
 * @list: va_list of arguments to be printed
 *
 * Return: calculated precision for the current conversion specifier
 */
int get_precision(const char *format, int *i, va_list list)
{
	int current_i = *i + 1;
	int precision = -1;

	if (format[current_i] != '.')
		return (precision);

	precision = 0;

	for (current_i += 1; format[current_i] != '\0'; current_i++)
	{
		if (is_digit(format[current_i]))
		{
			precision *= 10;
			precision += format[current_i] - '0';
		}
		else if (format[current_i] == '*')
		{
			current_i++;
			precision = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*i = current_i - 1;

	return (precision);
}

