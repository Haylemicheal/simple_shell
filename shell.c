#include "shell.h"

/**
 * main - main function of the shell
 * @argc: Size of arguments
 * @argv: Arguments array
 * Return: Success (0)
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char *buffer = NULL;
	char *fpath = NULL;
	char *path = NULL;
	char **input, *c = NULL;
	int exit = 0;

	signal(SIGINT, signal_to_handel);
	path = _getenv("PATH");
	if (path == NULL)
		return (1);
	do {
		input = NULL;
		if (isatty(STDIN_FILENO))
			prompt();
		buffer = readline();
		if (*buffer != '\0')
		{
			input = tokenize(buffer);
			if (input == NULL)
			{
				perror("Tokenization error");
				free(buffer);
				continue;
			}
			fpath = f_path(input, path, c);
			if (builtins(input, buffer, exit) != 0)
				continue;
			exit = execute(input, buffer, fpath, argv[0]);
		}
		else
			free(buffer);
	} while (1);
	return (0);
}
