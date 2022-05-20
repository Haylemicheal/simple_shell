#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

#define DELIM " \n"
extern char **environ;
int _putchar(char c);
int prompt(void);
int number_str(char *s);
char **tokenize(char *buff);
char *getpath(char *cmd);
char *_getenv(const char *member);
void *printenv(void);
int _strcmp_path(const char *PATH, const char *environ);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
int _strncmp(const char *s1, const char *s2, size_t n);
void signal_to_handel(int sig);
char *readline(void);
char *_strdup(char *s);
int path_members(char *s);
char *f_path(char **input, char *PATH, char *c);
char *concatation(char *tmp, char **input, char *token);
char *_memset(char *s, char c, unsigned int bytes);
int execute(char **input, char *buff, char *fpathbuff, char *argv);
void _puts(char *s);
int builtins(char **input, char *buff, int exitv);
int _cd(char **input);

#endif /*_SHELL_H_*/
