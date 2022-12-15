#include "monty.h"

/**
 * mul_stack - multiply the top two elements of the stack
 * @stack: stack
 * @line_number: line
 * Return: void pointer
 */

void mul_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		(*stack)->n *= tmp->n;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
