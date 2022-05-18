#include "shell.h"

/**
 * _exit_function - exit function
 * @args: input arguments
 *
 * Return: 0
 */

int _exit_function(char **args)
{
	if (args[1] == NULL)
		exit(0);
	exit(strtol(args[1], NULL, 10));
	return (0);
}

/**
 *_cd_function - changes the directory
 *
 *@args: input arguments.
 *
 * Return: 0.
 */

int _cd_function(char **args)
{
	if (args[1] == NULL)
	{
		printf("expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}

	return (1);
}
