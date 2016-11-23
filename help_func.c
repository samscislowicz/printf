#include "holberton.h"

/**
 * exponent - x to the power of y
 * @x: base number
 * @y: exponent
 * Description: calcuates x^y
 * Return: x^y
 *
 **/
int exponent(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);

	return (x * exponent(x, y - 1));
}


/**
 * print_int - print an int using only _putchar
 * @i: va_list containing number
 *
 * Return: sum
 **/
int print_int(va_list *i)
{
	int size, digit, number, sum;
	long counter, sign;

	number = va_arg(*i, int);
	sign = 1;
	digit = 0;
	size = 1;
	counter = number;
	sum = 0;

	if (number < 0)
	{
		_putchar('-');
		sign = -1;
		counter *= sign;
		sum++;
	}

	for (; counter >= 10; size++)
	{
		counter = counter / 10;
	}

	counter = sign * (long)number;

	while (size >= 2)
	{
		digit = (counter / exponent(10, size - 1));
		_putchar(digit + '0');
		counter = counter % exponent(10, size - 1);
		size--;
		sum++;
	}
	_putchar(counter % 10 + '0');
	sum++;
	return (sum);
}
