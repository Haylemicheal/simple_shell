#include "shell.h"

/**
 * _strcmp_path - compares PATH with environ elements
 * @PATH: String PATH
 * @environ: System environment
 * Return: 0 or 1
 */
int _strcmp_path(const char *PATH, const char *environ)
{
	int i;

	for (i = 0; environ[i] != '='; i++)
	{
		if (PATH[i] != environ[i])
			return (1);
	}
	return (0);
}
/**
 * number_str - Returns character length.
 * @s: input string.
 * Return: length of 's'.
 */

int number_str(char *s)
{
	int i, flag = 1, words = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] != ' ' && flag == 1)
		{
			words += 1;
			flag = 0;
		}
		if (s[i + 1] == ' ')
			flag = 1;
	}
	return (words);
}

