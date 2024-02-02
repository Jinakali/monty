#include "monty.h"
/**
 * push-add a new element to the doubly list
 * @stack:pointer to sstack
 * @line_number: line_number of operation in file
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n = atoi(rack.line_argv[1]);
	stack_t *new_node;

	if (!n)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(rack.line_argv);
		malloc_fail(&rack.line_ptr, rack.str_dup);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
	}

	new_node->next = *stack;
	*stack = new_node;
}
/**
 * pall-print all values on the stack
 * @stack:pointer to stack
 * @line_number:line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (*stack)
	{
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}
