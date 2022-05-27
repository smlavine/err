#include <stdio.h>
#include <stdlib.h>

#include "../err.h"

int
main(int argc, char *argv[])
{
	int i;

	program_invocation_name = argv[0];

	if (argc < 2)
		err(EXIT_FAILURE, "no files provided");

	for (i = 1; i < argc; i++) {
		FILE *fp;
		int c;

		if ((fp = fopen(argv[i], "r")) == NULL) {
			ewarn("%s", argv[i]);
			continue;
		}

		while ((c = fgetc(fp)) != EOF)
			putchar(c);

		fclose(fp);
	}

	return EXIT_SUCCESS;
}
