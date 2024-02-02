#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct carrier_s - lineptr, file
 * @lineptr:lineptr
 * @file: file
 * @line_argv:2d array of op_words and or their parameters
 *
 * Description: carry values across program
 */
typedef struct carrier_s
{
	char *lineptr;
	FILE *file;
	char **line_argv;
	char *strdup;
} carrier_t;

extern carrier_t rack;

void malloc_fail(char **lineptr, char *strdup);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void unknown_op(char *line_dup, char **argv, char *lineptr, unsigned int
line_no);
char **line_tokeniser(char *line);
int token_count(char *s);
void (*get_op(char *op))(stack_t **stack, unsigned int line_number);
#endif /*MAIN_H*/
