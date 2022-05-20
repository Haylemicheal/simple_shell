#include "shell.h"

/**
 * _strcmp_path - compares PATH with environ elements
 * @PATH: String PATH
 * @environ: System environment
 * Return: 0 or 1
 */
int _strcmp_path(const char *PATH, const char *environ)
{
	int i;

	for (i = 0; environ[i] != '='; i++)
	{
		if (PATH[i] != environ[i])
			return (1);
	}
	return (0);
}
/**
 * number_str - Returns character length.
 * @s: input string.
 * Return: length of 's'.
 */

int number_str(char *s)
{
	int i, flag = 1, words = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] != ' ' && flag == 1)
		{
			words += 1;
			flag = 0;
		}
		if (s[i + 1] == ' ')
			flag = 1;
	}
	return (words);
}

/**
 * signal_to_handel - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		exit(EXIT_SUCCESS);
	}
}

/**
*readline - read the line from stdin
*Return: pointer to the read line
*/
char *readline(void)
{
	ssize_t r = 0;
	size_t sl = 0;
	char *buff = NULL;
	int i = 0;

	r = getline(&buff, &sl, stdin);
	if (r == -1)
	{
		free(buff);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (buff[r - 1] == '\n' || buff[r - 1] == '\t')
		buff[r - 1] = '\0';
	for (i = 0; buff[i]; i++)
	{
		if (buff[i] == '#' && buff[i - 1] == ' ')
		{
			buff[i] = '\0';
			break;
		}
	}
	return (buff);
}
/**
*_strdup - Duplicated strings
*@s: string to make 2
*Return: pointer to s2
*/
char *_strdup(char *s)
{
{
	size_t len, i;
	char *str2;

	len = _strlen(s);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		str2[i] = s[i];
	}

	return (str2);
}
}
