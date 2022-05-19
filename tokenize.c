#include "shell.h"

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

	words = number_str(buff);
	if (!words)
		return (NULL);
	input = malloc((words + 1) * sizeof(char *));
	if (input == NULL)
	{
		perror("Allocation Error");
		exit(1);
	}
	token = strtok(buff, DELIM);
	while (token != NULL)
	{
		input[i] = strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	input[i] = NULL;
	return (input);
}
