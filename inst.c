#include "monty.h"

void (*get_inst(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t funcs[] = {
		{"push", push_val},
		{"pall", pall_stack},
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

	if (*stack == NULL)
	{
		new->n = atoi(arg);
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		new->n = atoi(arg);
		(*stack)->prev = new;
		new->next = *stack;
		new->prev = NULL;
		*stack = new;
	}

	free(arg);
	return;
}


void pall_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (*stack || line_number) 
	{
		while(tmp)
		{
			printf("%d\n", (tmp)->n);
			tmp = (tmp)->next;
		}
	}
	return;
}
