#ifndef CSH_BUILTIN_H
#define CSH_BUILTIN_H

int csh_cd(char **args);
int csh_launch(char **args);
int csh_exit(char **args);

enum {
	CSH_BUILTIN_EXIT = 1,
	CSH_BUILTIN_OK = 0,
	CSH_BUILTIN_CHECK_ERRNO = -1,
};

extern char *builtin_str[];
extern int (*builtin_func[])(char **);
int csh_builtins_count();

#endif
