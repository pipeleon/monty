#include "monty.h"

/**
 * _atoi - convert a string to an integer
 * @s: String to convert
 * Description: convert a string to an integer.
 * Return: void
 */
int _atoi(char *s)
{
	int i;
	int j;
	int l;
	unsigned int a;
	int cont;

	i = 0;
	l = 0;
	while (s[i] != '\0')
	{
		l++;
		i++;
	}

	cont = 0;
	a = 0;

	for (j = 0 + cont; j <= l - 1; j++)
	{
		if (s[j] >= 48 && s[j] <= 57)
		{
			a = ((a * 10) + s[j] - '0');
			if (s[j + 1] < 48 || s[j + 1] > 57)
				break;
		}
	}

	cont = 0;
	j = 0;
	while (cont != 1)
	{
		if (s[j] >= 48 && s[j] <= 57)
			cont = 1;
		if (s[j] == 45)
			a = (a * -1);
		j++;
	}
	return (a);
}

/**
 * isnumber - checks if string is integer
 * @s: String to check
 *
 * Return: void
 */
int isnumber(char *s)
{
	int j;
	int l;

	if (s == NULL)
		return (0);

	l = 0;
	while (s[l] != '\0')
		l++;


	for (j = 0; j <= l - 1; j++)
	{
		if (s[j] >= 48 && s[j] <= 57)
		{
			continue;
		}
		else
			return (0);
	}
	return (1);
}
