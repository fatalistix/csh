#include "csh_builtin.h"

#include <stdio.h>
#include <unistd.h>

int csh_cd(char** args) {
    if (args[1] == NULL) {
        return CSH_BUILTIN_OK;
    }
    if (args[2] != NULL) {
        return CSH_BUILTIN_TOO_MANY_ARGS;
    }
    if (chdir(args[1]) != 0) {
        return CSH_BUILTIN_CHECK_ERRNO;
    }

    return CSH_BUILTIN_OK;
}
