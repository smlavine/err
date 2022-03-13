#include <stdio.h>
#include <stdlib.h>

#include "../err.h"

int
main(int argc, char *argv[])
{
	char *word;

	argv0 = argv[0];

	if (argc > 2)
		err(EXIT_FAILURE, "multiple arguments provided");
	else if (argc == 1) {
		warn("no argument provided, using default word\n");
		word = "world";
	} else
		word = argv[1];

	printf("Hello, %s!\n", word);

	return EXIT_SUCCESS;
}
