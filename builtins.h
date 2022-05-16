#ifndef BUILTINS_H
#define BUILTINS_H

int _exit_function(char **args);

char *builtin_str[] = {
	"exit"
};

int (*builtin_func[]) (char **) = {
	&_exit_function
};
int num_builtins(void);
void call_builtins(char **tokens);
#endif
