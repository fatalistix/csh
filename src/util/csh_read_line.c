#include "csh_util.h"

#include <stdio.h>
#include <stdlib.h>

#define CSH_READ_LINE_CAP_STEP 1024

int csh_read_line(char **buffer_ptr) {
	size_t buf_size = CSH_READ_LINE_CAP_STEP;
	char *buffer = (char *)malloc(sizeof(char) * buf_size);
	if (!buffer) {
		return CSH_READ_LINE_ALLOCATION_ERR;
	}

	size_t pos = 0;
	int c;
	void *void_buffer = buffer;
	while (1) {
		c = getchar();

		if (c == EOF || c == '\n') {
			buffer[pos] = '\0';
			*buffer_ptr = buffer;
			return CSH_READ_LINE_OK;
		} else {
			buffer[pos] = c;
		}
		++pos;

		int err = csh_check_and_realloc(&void_buffer, &buf_size, pos,
										CSH_READ_LINE_CAP_STEP, sizeof(char));
		if (err) {
			return CSH_READ_LINE_ALLOCATION_ERR;
		}
	}
}
