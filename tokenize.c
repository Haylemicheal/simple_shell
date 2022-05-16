#include "shell.h"

/**
 * tokenize - Splits a line
 * @buff: line input
 * @delim: Delimiter
 * Return: array of tokens
 */
char **tokenize(char *buff, char *delim)
{
	char *token = NULL;
	int i = 0, words = 0;
	char **input = NULL;

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
