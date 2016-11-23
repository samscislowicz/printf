#include "holberton.h"

/**
<<<<<<< HEAD
 * print_char - print char
 * @i: va_list char
 * Return: i
 **/
int print_char(va_list *i)
{
	return (_putchar(va_arg(*i, int)));
}

/**
 * print_string - print str
 * @ap: va_list str
 * Return: i
 **/
int print_string(va_list *arg)
=======
 * _printstring - print string using _putchar
 * @string: string to print
 *
 * Return: 1
 */
int _printstring(char *string)
>>>>>>> master
{
	unsigned int i;
	char *s;

	s = va_arg(*arg, char *);

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}
	return (i);
}

/**
 * print_rev - print str in rev
 * @s: str to rev
 * Return:  str
 **/
int print_rev(char *s)
{
	if (s[1] == '\0')
		return (_putchar(s[0]));

	return (print_rev(&s[1]) + _putchar(s[0]));
}

/**
 * print_alpha - print alpha str
 * @ap: va_list object
 * Return: length of str printed
 **/
int print_alpha(va_list *arg)
{
	int i;
	char *s;

	s = va_arg(*arg, char *);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{

		}
		else
			_putchar(s[i]);
	}
	return (i);
}
