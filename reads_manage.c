#include "monty.h"

/**
 *montystruct_init - init struct
 */
void montystruct_init(void)
{
	monty.file = NULL;
	monty.line = NULL;
	monty.stack = NULL;
	monty.line_number = 1;
	monty.is_queue = false;
}

/**
 * openfile - input validation
 * @argc: args count
 * @filename: pointer to fiile
 */
void openfile(int argc, char *filename)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty.file = fopen(filename, "r");
	if (!monty.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * read_line - reads and executes each line
 */
void read_line(void)
{
	size_t len = 0;
	ssize_t read;
	char *opcode, *data;

	while ((read = getline(&monty.line, &len, monty.file) != -1))
	{
		opcode = strtok(monty.line, " ");
		if (*opcode == '#' || *opcode == '\n')
		{
			monty.line_number++;
			continue;
		}
		else if (strcmp(opcode, "push") == 0)
		{
			data = strtok(NULL, " \n");
			if (monty.is_queue)
			{
				push_queue(data);
			}
			else
				push(data);
		}
		else
			op_choose(&monty.stack, opcode);
		monty.line_number++;
	}
}
/**
* free_all - frees files
*/
void free_all(void)
{
	fclose(monty.file);
	free(monty.line);
	free_stack(monty.stack);
}

/**
 * free_stack - frees the stack
 * @h: the head of stack
 *
 *
 */
void free_stack(stack_t *h)
{
	stack_t *temp;
	stack_t *location = h;

	while (location)
	{
		temp = location;
		location = location->next;
		free(temp);
	}
}
