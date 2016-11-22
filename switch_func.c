#include "holberton.h"

/**
 * string_app - append two strs
 * @base: initial string
 * @str: string to add
 * @location: position in format (i.e format[location])
 *
 * Return: pointer to appended base
 */
int string_app(char *base, char *str, int location)
{
	if (str == NULL)
	{
		_strcat(base, "(null)");
		return (location + 1);
	}
	else
	{
		_strcat(base, str);
		return (location + 1);
	}
}

/**
 * num_app - append string with converted number
 * @base: initial string
 * @num: number to be converted and added
 * @location: location in format (ex. format[location])
 *
 * Return: pointer to appended base
 */
int num_app(char *base, int num, int location)
{
	char temp[100];

	itoa(num, temp);
	string_app(base, temp, 0);
	return (location + 1);
}

/**
 * switchf - determine which format to use
 * @format: format string from _printf
 * @buffer: buffer string from _printf
 * @i: location in @format
 * @n: location in @buffer
 * @args: arguments
 *
 * Return: new position in @format
 */
int switchf(const char *format, char *buffer, int i, int n, va_list args, int *size)
{
	switch (format[i])
	{
	case '%':
		buffer[n] = '%';
		buffer[n + 1] = '\0';
		i++;
		break;
	case 'c':
		buffer[n] = va_arg(args, int) + 0;
		if (buffer[n] == '\0')
		{
			_printstring(buffer);
			_putchar(0);
			*size += (n + 1);
			n = 0;
			i++;
			buffer[n] = '\0';
			break;
		}
		buffer[n + 1] = '\0';
		i++;
		break;
	case 's':
		i = string_app(buffer, va_arg(args, char *), i);
		break;
	case 'i':
		i = num_app(buffer, va_arg(args, int), i);
		break;
	case 'd':
		i = num_app(buffer, va_arg(args, int), i);
		break;
	default:
		buffer[n] = '%';
		buffer[n + 1] = '\0';
		break;
	}
	return (i);
}
