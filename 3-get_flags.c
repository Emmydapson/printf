#include "main.h"

/**
 * get_flags - Calculates active flags from the format string
 * @format: The formatted string containing conversion specifiers
 * @i: current index in the format string
 * Return: calculated flags for the current conversion specifier
 */
int get_flags(const char *format, int *i)
{
	/* Flags:'-', '+', '0', '#', ' ' */

	const char FLAGS_CHARACTERS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	int j, current_i;
	int flags = 0;

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		for (j = 0; FLAGS_CHARACTERS[j] != '\0'; j++)
		{
			if (format[current_i] == FLAGS_CHARACTERS[j])
			{
				flags |= FLAGS_VALUES[j];
				break;
			}
		}

		if (FLAGS_CHARACTERS[j] == 0)
			break;
	}

	*i = current_i - 1;

	return (flags);
}

