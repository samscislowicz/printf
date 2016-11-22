#include "holberton.h"

/**
 * _str_duplicate - create pointer to duplicate of @str
 * @str: string to duplicate
 *
 * Return: pointer
 */
char *_str_duplicate(char *str)
{
	char *s;
	int i, size;

	if (str == NULL)
		return (NULL);
	size = _strlen(str);
	s = malloc((size + 1) * sizeof(*s));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = str[i];
	return (s);
}

/**
 * _calloc - allocate memory for array using malloc
 * @nmemb: number of elements in the array
 * @size: size of bytes of each element
 *
 * Return: pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i <= (nmemb * size))
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
/**
 * _abs - computes absolute value of an integer
 * @i: interger to computer
 *
 * Return: absolute value;
 */
int _abs(int i)
{
	if (i < 0)
	{
		i = i * -1;
		return (i);
	}
	else
		return (i);
}

/**
 * itoa - convert integer to string
 * @num: integer to convert
 * @s: array of chars
 *
 * Return: int
 */
int itoa(int num, char s[])
{
	int i;

	i = 0;
	if (num / 10 != 0)
		i = itoa(num / 10, s);
	else if (num < 0)
		s[i++] = '-';
	/* make sure i is positive */
	s[i++] = _abs(num % 10) + '0';
	s[i] = '\0';

	return (i);
}
