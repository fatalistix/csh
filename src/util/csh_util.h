#ifndef CSH_UTIL_H
#define CSH_UTIL_H

#include <stdio.h>

int csh_check_and_realloc(void** ptr, size_t* size, size_t pos, size_t cap_step, size_t size_of);

enum {
    CSH_CHECK_AND_REALLOCK_OK = 0,
    CSH_CHECK_AND_REALLOCK_ALLOCATION_ERR = -1,
};

int csh_read_line(char** buffer_ptr);

enum {
    CSH_READ_LINE_OK = 0,
    CSH_READ_LINE_ALLOCATION_ERR = -1,
};

int csh_split_line(char*** tokens_ptr, char* line);

enum {
    CSH_SPLIT_LINE_OK = 0,
    CSH_SPLIT_LINE_ALLOCATION_ERR = -1,
};

#endif /* CSH_UTIL_H */
