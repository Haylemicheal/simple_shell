#include "shell.h"

/**
*builtins - command is built-in ?
*@input: the command
*@buff: string of the input
*@exitv: how to exit ?
*Return: 1 if yes 0 if not a built-in
*/
int builtins(char **input, char *buff, int exitv)
{
	int i;

	if (_strncmp(input[0], "env", _strlen(input[0])) == 0)
	{
		printenv();
		for (i = 0; input[i]; i++)
			free(input[i]);
		free(input);
		free(buff);
		return (1);
	}
	else if (_strncmp(input[0], "exit", _strlen(input[0])) == 0)
	{
		for (i = 0; input[i]; i++)
			free(input[i]);
		free(input);
		free(buff);
		exit(exitv);
	}
	else if (_strncmp(input[0], "cd", _strlen(input[0])) == 0)
	{
		_cd(input);
		for (i = 0; input[i]; i++)
		free(input[i]);
		free(input);
		free(buff);
		return (1);
	}
	else
		return (0);
}
/**
 * _cd - change directory.
 * @input: List of input.  input[0] is "cd".  input[1] is the directory.
 * Return: Always returns 1.
 */
int _cd(char **input)
{
	if (input[1] == NULL)
	{
		if (chdir(_getenv("HOME")) != 0)
			perror("hsh");
	}
	else if (chdir(input[1]) != 0)
		perror("hsh");
	return (1);
}

