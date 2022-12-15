#include "monty.h"

/**
 * get_inst - get instruction to execute
 * @opcode: opcode
 * Return: void pointer
 */

void (*get_inst(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t funcs[] = {
		{"push", push_val},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{NULL, NULL}
	};

	int i;

	for (i = 0; funcs[i].opcode; i++)
	{
		if (strcmp(funcs[i].opcode, opcode) == 0)
			break;
	}
	return (funcs[i].f);
}

/**
 * push_val - add value to stack
 * @stack: stack
 * @line_number: line
 * Return: void pointer
 */

void push_val(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int j;
	stack_t *new;

	arg = getarg(line_number);
	if (!arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (j = 0; j < (int) strlen(arg); j++)
	{
		if (isdigit(arg[j]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(arg);
	new->prev = NULL;
	if (*stack == NULL)
		new->next = NULL;
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
	}
	*stack = new;

	free(arg);
}

/**
 * pall_stack - print stack
 * @stack: stack
 * @line_number: line
 * Return: void pointer
 */

void pall_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (*stack && line_number)
	{
		while (tmp)
		{
			printf("%d\n", (tmp)->n);
			tmp = (tmp)->next;
		}
	}
}

 /**
  * pint_stack - prints the value at the top of the stack
  * @stack: stack
  * @line_number: line
  * Return: void pointer
  */

void pint_stack(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}		
}


 /**
  * pop_stack - removes the top element of the stack
  * @stack: stack
  * @line_number: line
  * Return: void pointer
  */

void pop_stack(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
	{
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}		
}
