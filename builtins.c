#include "shell.h"

/**
 * _exit_function - exit function
 *
 * Return: 0
 */

int _exit_function(void)
{
	return (0);
}

/**
 *_cd_function - changes the directory
 *
 *args: input arguments.
 *
 * Return: 0.
 */

int _cd_function(char **args __attribute__((unused)))
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("lsh");
		}
	}
	return (1);
}
