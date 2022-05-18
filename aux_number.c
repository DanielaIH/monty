#include "monty.h"

/**
 * _char_to_number - converts a char* to an int
 * @str: string to be converted to an int
 * Return: the string in int format
 */

unsigned int _char_to_number(char *str)
{
	unsigned int i = 0, digits = 1, j = 0, number = 0, temp = 0;

	if (!str)
		return (0);

	for (; str[i]; i++)
		digits *= 10;

	digits /= 10;

	while (str[j])
	{
		temp = (str[j] - '0') * digits;
		number += temp;
		digits /= 10;
		j++;
	}
	return (number);
}

/**
 * _isnumber - if input is a number
 * @str: string to be converted to an int
 * Return: 1 if input is a number, 0 if not.
 */

unsigned int _isnumber(char *str)
{
	int i;

    for (i = 0; str[i]; i++)
        if (!isdigit(str[i]))
            return (0);
    return (1);
}