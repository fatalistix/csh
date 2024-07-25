#include <stdlib.h>
#include "csh.h"

int main(int argc, char **argv) {
	// Load config files, if any

	// Run command loop
	csh_run();

	// Perform any shutdown/cleanup
	return EXIT_SUCCESS;
}
