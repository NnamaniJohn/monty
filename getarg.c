#include "monty.h"

/**
 * getarg - get argument from a file
 * @line_number: line of arg
 * Return: char *
 */

char *getarg(unsigned int line_number)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_no = 1, i = 0;
	char *opcode, *arg = NULL, *ret = NULL;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (line_number == line_no)
		{
			if ((line)[read - 1] == '\n')
				(line)[read - 1] = '\0';
			opcode = strtok(line, " ");
			if (opcode)
			{
				arg = strtok(NULL, " ");
				if (!arg)
					break;
				while (arg[i])
					i++;
				ret = malloc(sizeof(char) * (i + 1));
				if (!ret)
				{
					fprintf(stderr, "Error: malloc failed\n");
					if (line)
						free(line);
					exit(EXIT_FAILURE);
				}
				for (i = 0; arg[i]; i++)
					ret[i] = arg[i];
				ret[i] = '\0';
			}
			break;
		}
		line_no++;
	}
	fclose(fp);
	if (line)
		free(line);
	return (ret);
}
