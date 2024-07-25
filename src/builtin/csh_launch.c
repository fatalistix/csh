#include "csh_builtin.h"

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int csh_launch(char **args) {
    pid_t pid;
	pid_t wpid;
	int status;

	pid = fork();
	if (pid == 0) {
		if (execvp(args[0], args) == -1) {
		    exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	} else if (pid < 0) {
	    return CSH_BUILTIN_CHECK_ERRNO;
	} else {
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return CSH_BUILTIN_OK;
}
