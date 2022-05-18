#ifndef BUILTINS_H
#define BUILTINS_H

int _exit_function(char **args);
int _cd_function(char **args);

char *builtin_str[] = {
	"exit",
	"cd"
};

int (*builtin_func[]) (char **) = {
	&_exit_function,
	&_cd_function
};
int num_builtins(void);
int call_builtins(char **tokens);
#endif
