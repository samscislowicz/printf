#include "holberton.h"

/**
 * pull_print - prints va_list using the correct format
 * @ap: va_list to print
 * @c: character flag
 * Return: number of chars printed
 **/
int pull_print(char c, va_list *ap)
{
	int i;
	find_func funcs[] = {
		{'d', print_int},
		{'i', print_int},
		{'c', print_char},
		{'s', print_string},
		{'r', print_rstring},
		{'\0', NULL}
	};

	for (i = 0; funcs[i].letter != '\0'; i++)
	{
		if (funcs[i].letter == c)
		{
			return (funcs[i].prnt(ap));
		}
	}
	if (c == '%')
	{
		_putchar('%');
		return (1);
	}
	return (0);
}
