#include "monty.h"

char *filename = NULL;

void free_stack(stack_t **stack)
{	
	stack_t *tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

/**
 * execute - run opcode
 * @fp: file descriptor
 * Return: void
 */

void execute(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;
	char *opcode;
	void (*inst)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;

	while ((read = getline(&line, &len, fp)) != -1)
	{
		if ((line)[read - 1] == '\n')
			(line)[read - 1] = '\0';
		opcode = strtok(line, " ");
		if (opcode)
		{
			inst = get_inst(opcode);
			if (inst)
				inst(&stack, line_number);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, filename);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
		}

		line_number++;
	}

	free_stack(&stack);
	if (line)
		free(line);
}

/**
 * main - main program
 * @ac: argument count
 * @av: argument vector
 * Return: int
 */

int main(int ac, char *av[])
{
	FILE *fp;

	if (ac != 2 || !av)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = av[1];
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	execute(fp);

	fclose(fp);

	return (0);
}
