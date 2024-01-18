#include "monty.h"
/**
* push_queue - push to the end of list
* @argument: int
*/
void push_queue(char *argument)
{
	int data;
	stack_t *new, *location;

	if (!check_input(argument))
	{
		fprintf(stderr, "L%u: usage: push integer\n",
			monty.line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	data = atoi(argument);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	location = monty.stack;
	new->n = data;
	new->next = NULL;
	if (!location)
	{
		new->prev = NULL;
		monty.stack = new;
		return;
	}
	while (location->next)
	{
		location = location->next;
	}
	location->next = new;
	new->prev = location;
}

/**
 * check_input- check the int
 *@str: the string we check
 *
 *Return: false til  int
 *
 */
bool check_input(char *str)
{

	int i = 0;


	if (!str)
	{
		return (false);
	}

	if (str[0] != '-' && !isdigit(str[0]))
	{
		return (false);
	}

	for (i = 1; str[i]; i++)
	{
		if (!isdigit(str[i]))
		{
			return (false);
		}
	}
	return (true);
}

/**
* op_choose - distrubtion middleware to match and call func
* @stack: pointer to pointer of stack
* @opcode: opcode from parsed file
*/

void op_choose(stack_t **stack, char *opcode)
{
	int i;
	char *op;
	instruction_t fncs[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	op = strtok(opcode, "\n");
	for (i = 0; fncs[i].opcode; i++)
	{
		if (strcmp(op, fncs[i].opcode) == 0)
		{
			fncs[i].f(stack, monty.line_number);
			return;
		}
	}
	if (strcmp(opcode, "push"))
	{
		fprintf(stderr, "L%u: ", monty.line_number);
		fprintf(stderr, "unknown instruction %s\n", opcode);
	}
	else
		fprintf(stderr, "L%u: usage: push integer\n", monty.line_number);
	exit(EXIT_FAILURE);
}
/**
 * push - add node to list
 * @argument: int
 */
void push(char *argument)
{
	int data;
	stack_t *new;

	if (!check_input(argument))
	{
		fprintf(stderr, "L%u: usage: push integer\n"
				, monty.line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	data = atoi(argument);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new->next = monty.stack;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
	monty.stack = new;
}
