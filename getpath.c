#include "shell.h"

/**
 * getpath - get commands from PATH
 * @str: command input
 * Return: execuatable command or NULL
 */
char *getpath(char *str)
{
	char **dirs;
	int x = 0;
	char *cwd = getcwd(NULL, 0);
	struct stat sb;
	char *path;

	path = malloc(_strlen(_getenv("PATH")));
	_strcpy(path, _getenv("PATH"));
	dirs = tokenize(path, ":");
	x = 0;
	while (dirs[x] != NULL)
	{
		chdir(dirs[x]);
		if (stat(str, &sb) == 0)
		{
			dirs[x] = _strcat(dirs[x], "/");
			str = _strcat(dirs[x], str);
			free(dirs);
			break;
		}
		x++;
	}

	chdir(cwd);

	return (str);
}
