#include "monty.h"


/**
 * pall - print all
 * @stack: double list
 * @linenum: line
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	stack_t *a = *stack;

	if (!*stack)
	{
		return;
	}
	while (a)
	{
		printf("%d\n", a->n);
		a = a->next;
	}
}


/**
 * pint - int in stack
 * @stack: double list
 * @linenum: line
 */
void pint(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", monty.line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
}



/**
 * pop - delete node from top of list
 * @stack: double list
 * @linenum: line
 */
void pop(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	stack_t *freeable = *stack;

	if (*stack)
	{
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(freeable);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n"
				, monty.line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
}

/**
 * swap - swap place of top two members in stack
 * @stack: double list
 * @linenum: line
 */
void swap(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	int tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
				monty.line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
}

/**
 * add - adds top two stack mems
 * @stack: double list
 * @linenum: line
 */
void add(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	stack_t *freeable;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		freeable = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(freeable);
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
				monty.line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
}
