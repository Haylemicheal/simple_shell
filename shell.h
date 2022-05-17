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

extern char **environ;
int _putchar(char c);
void prompt(void);
int number_str(char *s);
char **tokenize(char *buff, char *delim);
void exec(char *buffer, char *argv);
void launch(pid_t child_id, char **tokens, char *argv, char *cmd);
char *getpath(char *cmd);
char *_getenv(const char *member);
void *printenv(void);
int _strcmp_path(const char *PATH, const char *environ);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
int _strncmp(const char *s1, const char *s2, size_t n);

#endif /*_SHELL_H_*/
