#include "shell.h"

/**
*f_path - find the path to call execve
*@input: the commands
*@PATH: the PATH
*@c: the string needed
*Return: string to call on execve
*/
char *f_path(char **input, char *PATH, char *c)
{
	char *token = NULL, *fpathbuff = NULL, *concat = NULL;
	static char tmp[256];
	int PATHc = 0, pflag = 0, i = 0, len = 0;
	struct stat x;

	c = NULL;
	c = _strdup(PATH);
	PATHc = path_members(c);
	token = strtok(c, ": =");
	while (token != NULL)
	{
		concat = concatation(tmp, input, token);
		if (stat(concat, &x) == 0)
		{
			fpathbuff = concat;
			pflag = 1;
			break;
		}
		if (i < PATHc - 2)
		{
			len = _strlen(token);
			if (token[len + 1] == ':')
			{
				if (stat(input[0], &x) == 0)
				{
					fpathbuff = input[0];
					pflag = 1;
					break;
				}
			}
		}
		i++;
		token = strtok(NULL, ":");
	}
	if (pflag == 0)
		fpathbuff = input[0];
	free(c);
	return (fpathbuff);
}

/**
*path_members - number of PATH members
*@s: string to count
*Return: Path elements
*/
int path_members(char *s)
{
	int i;
	int flag = 1, words = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != ':' && flag == 1)
		{
			words += 1;
			flag = 0;
		}
		if (s[i + 1] == ':')
			flag = 1;
	}
	return (words);
}
