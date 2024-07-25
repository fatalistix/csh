#include "csh_util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CSH_SPLIT_LINE_CAP_STEP 64
#define CSH_SPLIT_LINE_DELIM " \t\r\n\a"

int csh_split_line(char*** tokens_ptr, char* line) {
	size_t buf_size = CSH_SPLIT_LINE_CAP_STEP;
	char **tokens = malloc(buf_size * sizeof(char*));

	if (!tokens) {
	return CSH_SPLIT_LINE_ALLOCATION_ERR;
	}

	size_t pos = 0;
	char* token;
	void* void_tokens = tokens;
	token = strtok(line, CSH_SPLIT_LINE_DELIM);
	while (token != NULL) {
		tokens[pos] = token;
		++pos;

		int err = csh_check_and_realloc(&void_tokens, &buf_size, pos, CSH_SPLIT_LINE_CAP_STEP, sizeof(char*));
		if (err) {
		return CSH_READ_LINE_ALLOCATION_ERR;
		}

		token = strtok(NULL, CSH_SPLIT_LINE_DELIM);
	}
	tokens[pos] = NULL;
	*tokens_ptr = tokens;
	return CSH_SPLIT_LINE_OK;
}
