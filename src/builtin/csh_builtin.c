#include "csh_builtin.h"

char *builtin_str[] = {
	"cd",
	"exit",
};

int (*builtin_func[])(char **) = {
	&csh_cd,
	&csh_exit,
};

int csh_builtins_count() { return sizeof(builtin_str) / sizeof(char *); }
