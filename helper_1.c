#include "shell.h"

/**
*concatation - the commands get to the PATH
*@tmp: static array to store the new string
*@input: the user command
*@token: PATH token
*Return: the new PATH with user command in it
*/
char *concatation(char *tmp, char **input, char *token)
{
	int len = 0;

	_memset(tmp, 0, 256);
	len = _strlen(token) + _strlen(input[0]) + 2;
	_strcat(tmp, token);
	_strcat(tmp, "/");
	_strcat(tmp, input[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}

/**
*_memset - set the memory with a constant byte
*@s: array to fill
*@c: character to fill with
*@bytes: number of bytes to fill
*Return: new array
*/
char *_memset(char *s, char c, unsigned int bytes)
{
	unsigned int i;

	for (i = 0; i < bytes; i++)
		s[i] = c;
	return (s);
}

/**
*_puts - print a string
*@s: string to print
*/
void _puts(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		write(1, &s[i], 1);
	write(1, "\n", 1);
}
