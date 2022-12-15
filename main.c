#include "main.h"

char *filename = NULL;

void execute(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;
	char *opcode;
	void (*inst)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;
	stack_t *tmp;

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
				exit(EXIT_FAILURE);
			}
		}

		line_number++;
	}

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}

	if (line)
		free(line);
}

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
