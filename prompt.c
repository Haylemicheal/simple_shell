#include "shell.h"

/**
 * prompt - print $
 *
 * Return: 0 or 1
 */
int prompt(void)
{
	ssize_t w = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		w = write(1, "$ ", 2);
		if (w == -1)
			return (1);
	}
	return (0);
}

