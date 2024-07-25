#include "csh.h"

#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "util/csh_util.h"

int csh_launch(char **args) {
	pid_t pid;
	pid_t wpid;
	int status;

	pid = fork();
	if (pid == 0) {
		if (execvp(args[0], args) == -1) {
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		perror("lsh");
	} else {
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 0;
}

int csh_cd(char **args);
int csh_help(char **args);
int csh_exit(char **args);

char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};

int (*builtin_func[]) (char **) = {
    &csh_cd,
    &csh_help,
    &csh_exit,
};

int csh_num_builtins() {
    return sizeof(builtin_str) / sizeof(char*);
}

int csh_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "lsh: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("lsh");
        }
    }
    return 0;
}

int csh_help(char **args) {
    printf("CSH\n");
    printf("Simpliest shell implementation, written in C.\n");
    printf("The following are built in:\n");

    for (int i = 0; i < csh_num_builtins(); i++) {
        printf("    %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 0;
}

int csh_exit(char **args) {
    return 1;
}

int csh_execute(char **args) {
    if (args[0] == NULL) {
        return 0;
    }

    for (int i = 0; i < csh_num_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }

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
