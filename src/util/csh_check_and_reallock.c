#include "csh_util.h"

#include <stdio.h>
#include <stdlib.h>

int csh_check_and_realloc(void** ptr, size_t* size, size_t pos, size_t cap_step, size_t size_of) {
    if (pos >= *size) {
        size_t new_size = *size + cap_step;
        *ptr = realloc(*ptr, new_size * size_of);
        if (!*ptr) {
            return CSH_CHECK_AND_REALLOCK_ALLOCATION_ERR;
        }

        *size = new_size;
    }

    return CSH_CHECK_AND_REALLOCK_OK;
}
