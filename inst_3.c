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

/**
 * mod_stack - mod the top two elements of the stack
 * @stack: stack
 * @line_number: line
 * Return: void pointer
 */

void mod_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		else
		{
			tmp = *stack;
			*stack = (*stack)->next;
			(*stack)->prev = NULL;
			(*stack)->n %= tmp->n;
			free(tmp);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pchar_stack - prints char at the top of the stack
 * @stack: stack
 * @line_number: line
 * Return: void pointer
 */

void pchar_stack(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
			printf("%c\n", (*stack)->n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr_stack - prints string at the top of the stack
 * @stack: stack
 * @line_number: line
 * Return: void pointer
 */

void pstr_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (stack || line_number)
	{
		while (tmp)
		{
			if (tmp->n > 0 && tmp->n <= 127)
			{
					printf("%c", (tmp)->n);
					tmp = (tmp)->next;
			}
			else
				break;
		}
		printf("\n");
	}
}
