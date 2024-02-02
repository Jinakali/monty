#include "monty.h"
/**
 *malloc_fail- handle malloc failures
 *@lineptr:lineptr
 *@strdup: any strdup
 */
void malloc_fail(char **lineptr, char *strdup)
{
	if (strdup != NULL)
		free(strdup);
	free(*lineptr);
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 *unknown_op-unknown instruction
 *@line_dup:line_dup
 *@argv:argv
 *@lineptr:lineptr
 *@line_no:line_no
 */
void unknown_op(char *line_dup, char **argv, char *lineptr, unsigned int
line_no)
{
	free(line_dup);
	free(argv);
	free(lineptr);

	fprintf(stderr, "L%d: unknown instruction %s\n", line_no, argv[0]);
	exit(EXIT_FAILURE);
}
