#include "shell.h"

/**
 * prompt - print $
 *
 * Return: none
 */
void prompt(void)
{
	char name[] = "$ ";
	int i = 0;

	while (name[i])
	{
		_putchar(name[i]);
		i++;
	}
}

