#include "csh_builtin.h"

#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int csh_cd(char **args) {
	if (args[1] == NULL) {
		return CSH_BUILTIN_OK;
	}
	if (args[2] != NULL) {
		errno = E2BIG;
		return CSH_BUILTIN_CHECK_ERRNO;
	}
	if (chdir(args[1]) != 0) {
		return CSH_BUILTIN_CHECK_ERRNO;
	}

	return CSH_BUILTIN_OK;
}
