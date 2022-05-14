#include "shell.h"

/**
 * exec - function for executing commands
 * @buffer: command input
 * @argv: argv[0]
 * Return: None
 */
void exec(char *buffer, char *argv)
{
	pid_t child_id;
	char **tokens;

	tokens = tokenize(buffer);
	child_id = fork();
	if (child_id == -1)
	{
		printf("%s: No such file or directory\n", argv);
		exit(EXIT_FAILURE);
	}
	else if (child_id == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			printf("%s: No such file or directory\n", argv);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
