#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

extern char *filename;

void (*get_inst(char *opcode))(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
void push_val(stack_t **stack, unsigned int line_number);
void pall_stack(stack_t **stack, unsigned int line_number);
void pint_stack(stack_t **stack, unsigned int line_number);
void pop_stack(stack_t **stack, unsigned int line_number);
void swap_stack(stack_t **stack, unsigned int line_number);
void add_stack(stack_t **stack, unsigned int line_number);
void nop_stack(stack_t **stack, unsigned int line_number);
void sub_stack(stack_t **stack, unsigned int line_number);
void div_stack(stack_t **stack, unsigned int line_number);
void mul_stack(stack_t **stack, unsigned int line_number);

char *getarg(unsigned int line_number);

#endif /* MAIN_H */
