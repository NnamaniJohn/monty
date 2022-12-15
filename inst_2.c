#include "monty.h"

/**
 * swap_stack - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: line
 * Return: void pointer
 */

void swap_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
		tmp->prev = *stack;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}