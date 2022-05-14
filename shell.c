#include "shell.h"

/**
 * main - main function of the shell
 * @argc: Size of arguments
 * @argv: Arguments array
 * Return: Success (0)
 */
int main(int argc, char **argv)
{
	char *buffer = NULL;
	size_t buffsize = 0;
	size_t line = 0;

	do {
		prompt();
		line = getline(&buffer, &buffsize, stdin);
		if (line == EOF)
		{
			free(buffer);
			_putchar('\n');
			return (EXIT_SUCCESS);
		}
		exec(buffer, argv[0]);
	} while (line != EOF);

	return (EXIT_SUCCESS);
}

