#include "csh.h"

#include <stdlib.h>

#include "builtin/csh_builtin.h"
#include "util/csh_util.h"

int csh_execute(char **args) {
    if (args[0] == NULL) {
        return 0;
    }

    // for (int i = 0; i < csh_num_builtins(); i++) {
    //     if (strcmp(args[0], builtin_str[i]) == 0) {
    //         return (*builtin_func[i])(args);
    //     }
    // }

    return csh_launch(args);
}

void csh_run(void) {
	char *line;
	char **args;
	int err;

	do {
		printf("> ");
		err = csh_read_line(&line);
		err = csh_split_line(&args, line);
		err = csh_execute(args);

		free(line);
		free(args);
	} while (!err);
}
