#include "holberton.h"

/**
 * _printf - replicate the printf function
 * @format: character string
 *
 * Return: number of characters printed (not including '\0')
 */
int _printf(const char *format, ...)
{
	va_list arg;
	unsigned int i, sum;

	sum = 0;
	va_start(arg, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			sum += pull_print(format[i + 1], &arg);
			i++;
		}
		else
		{
			_putchar(format[i]);
			sum++;
		}
	}
	va_end(arg);
	return (sum);
}
