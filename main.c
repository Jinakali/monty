#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - intepret monty files
 * @argc: argument count
 * @argv: array of pointers
 * Return:exit success or failure
 */
int main(int argc, char **argv)
{
	FILE *monty_f;
	stack_t *stackptr = NULL;
	char *lineptr, *line_dup = NULL, **op_argv;
	size_t len = 0;
	unsigned int line_no = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_f = fopen(argv[1], "r");
	if (monty_f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	rack.file = monty_f;
	while ((getline(&lineptr, &len, monty_f)) != EOF)
	{
		line_no++;
		line_dup = strdup(lineptr);
		if (!line_dup)
			malloc_fail(&lineptr, NULL);
		rack.str_dup = line_dup;

		op_argv = line_tokeniser(line_dup);
		rack.line_argv = op_argv;
		if (get_op(op_argv[0]))
			get_op(op_argv[0])(stackptr, line_no);
		else
			unknown_op(line_dup, op_argv, lineptr, line_no);

		free(line_dup);
		free(op_argv);
	}
	free(lineptr);
	fclose(monty_f);
	return (EXIT_SUCCESS);
}

/**
 * get_op-looks for and conducts operation
 * @op:operation name
 * Return:appropriate function
 */
void (*get_op(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t op_parser[] = {
		{"push", push},
		{"pall"}, pall,
		{"NULL", NULL}
	};
	int i;

	for (i = 0; op_parser[i].opcode; i++)
	{
		if (strcmp(op_parser[i].opcode, op) == 0)
		{
			return (op_parser[i].f());
		}
	}
	return (NULL);

}

/**
 * line_tokeniser- break line into words based on spaces
 * @line:lineline_number
 * Return: malloc'd tokens
 */
char **line_tokeniser(char *line)
{
	char **words;
	char *token;

	int 2d_size;
	int i;

	if (!line)
		return (NULL);

	2d_size = token_count(line);
	if (2d_size == -1)
		return (NULL);

	words = malloc(sizeof(char *) * (2d_size + 1));
	if (words == NULL)
		return (NULL);

	token = strtok(line_cpy, delim);
	for (i = 0; token != NULL; i++)
	{
		words[i] = token;
		token = strtok(NULL, delim);
	}
	words[i] = NULL;

	return (words);
}

/**
 * token_count-count tokens
 * @s:string
 * Return: no of tokens
 */
int token_count(char *s)
{
	int count;
	char *s_dup;

	count = 0;
	s_dup = strdup(s);
	if (s_dup == NULL)
		return (-1);

	if (strtok(s_dup, " "))
	{
		count++;
	}
	else
	{
		free(s_dup);
		return (-1);
	}

	while (strtok(NULL, " "))
	{
		count++;
	}
	free(s_dup);
	return (count);

}
