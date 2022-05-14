#include "main.h"

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

/**
 * tokenize - Splits a line
 * @buff: line input
 * Return: array of tokens
 */
char **tokenize(char *buff)
{
	char *token = NULL;
	int i = 0, words = 0;
	char **input = NULL;
	char *delim = "\n"

	words = number_str(buff);
	if (!words)
		return (NULL);
	input = malloc((words + 1) * sizeof(char *));
	if (input == NULL)
	{
		perror("Allocation Error");
		exit(1);
	}
	token = strtok(buff, delim);
	while (token != NULL)
	{
		input[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	input[i] = NULL;
	return (input);
}

