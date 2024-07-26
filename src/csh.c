#include "csh.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "builtin/csh_builtin.h"
#include "util/csh_util.h"

int csh_execute(char **args) {
	if (args[0] == NULL) {
		return 0;
	}

	for (int i = 0; i < csh_builtins_count(); i++) {
		if (strcmp(args[0], builtin_str[i]) == 0) {
			return (*builtin_func[i])(args);
		}
	}

	return csh_launch(args);
}

int check_errno() {
	if (errno == E2BIG) {
		return 0;
	} else {
		return -1;
	}
}

void csh_run(void) {
	char *line;
	char **args;
	int err;

	do {
		printf("> ");

		err = csh_read_line(&line);
		if (err) {
			fprintf(stderr, "csh: allocation error\n");
			break;
		}

		err = csh_split_line(&args, line);
		if (err) {
			fprintf(stderr, "csh: allocation error\n");
			break;
		}

		err = csh_execute(args);
		if (err) {
			if (err == CSH_BUILTIN_EXIT) {
				printf("[exited]\n");
				break;
			} else {
				perror("csh");
				if (check_errno()) {
					break;
				}
			}
		}

		err = 0;

		free(line);
		free(args);
	} while (!err);
}
