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
	char *cmd = buffer;

	tokens = tokenize(buffer, " \n");
	if (cmd[0] != '/' && cmd[0] != '.')
	{
		cmd = getpath(tokens[0]);
	}
	if (!cmd)
	{
		perror("Access error\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		child_id = fork();
		if (child_id == -1)
		{
			printf("%s: No such file or directory\n", argv);
			exit(EXIT_FAILURE);
		}
		else if (child_id == 0)
		{
			tokens[0] = cmd;
			if (execve(tokens[0], tokens, NULL) == -1)
			{
				printf("%s %s\n", tokens[0], tokens[1]);
				printf("%s: No such file or directory\n", argv);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
	}
}
