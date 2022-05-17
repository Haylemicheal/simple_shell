#include "shell.h"
#include "builtins.h"

/**
 *num_builtins - Get the number of bilitin functions
 *Return: Number of builtin functions
 */
int num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * call_builtins - call built in functions
 * @tokens: Tokenized strings
 * Return: None
 */
void call_builtins(char **tokens)
{
	int i = 0;

	for (i = 0; i < num_builtins(); i++)
	{
		if (_strncmp(tokens[0], builtin_str[i], _strlen(tokens[0])) == 0)
		{
			(*builtin_func[i])(tokens);
			exit(EXIT_SUCCESS);
		}
	}
}

/**
 * launch - Launch commands
 * @child_id: child pid
 * @tokens: Tokenized Strings
 * @argv: argv[0]
 * @cmd: command
 * Return: None
 */
void launch(pid_t child_id, char **tokens, char *argv, char *cmd)
{
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
	else if (_strncmp(tokens[0], "env", _strlen(tokens[0])) == 0)
	{
		printenv();
	}
	else
	{
		call_builtins(tokens);
		child_id = fork();
		launch(child_id, tokens, argv, cmd);
	}
}
