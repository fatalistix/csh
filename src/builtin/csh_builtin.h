#ifndef CSH_BUILTIN_H
#define CSH_BUILTIN_H

int csh_cd(char** args);
int csh_launch(char** args);

enum {
    CSH_BUILTIN_OK = 0,
    CSH_BUILTIN_TOO_MANY_ARGS = -1,
    CSH_BUILTIN_CHECK_ERRNO = -2,
};

#endif


// int csh_cd(char **args);
// int csh_help(char **args);
// int csh_exit(char **args);

// char *builtin_str[] = {
//     // "cd",
//     "help",
//     "exit"
// };

// int (*builtin_func[]) (char **) = {
//     // &csh_cd,
//     &csh_help,
//     &csh_exit,
// };

// int csh_num_builtins() {
//     return sizeof(builtin_str) / sizeof(char*);
// }

// int csh_help(char **args) {
//     printf("CSH\n");
//     printf("Simpliest shell implementation, written in C.\n");
//     printf("The following are built in:\n");

//     for (int i = 0; i < csh_num_builtins(); i++) {
//         printf("    %s\n", builtin_str[i]);
//     }

//     printf("Use the man command for information on other programs.\n");
//     return 0;
// }

// int csh_exit(char **args) {
//     return 1;
// }
