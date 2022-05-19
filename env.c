#include "shell.h"

/**
 * _getenv - get system environment
 * @path: String PATH
 * Return: NULL or PATH in environ
 */
char *_getenv(const char *path)
{
	int i, r;

	for (i = 0; environ[i]; i++)
	{
		r = _strcmp_path(path, environ[i]);
		if (r == 0)
			return (environ[i]);
	}
	return (NULL);
}

/**
 * printenv - Print environment var
 * Return: none
 */
void *printenv(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		i++;
	}
	return (0);
}
