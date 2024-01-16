#include "monty.h"

/**
 * pchar- prints the char at the top of
 * the stack, followed by a new line
 * @stack: points to head of stack
 * @linenum: current line no
 */
void pchar(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n"
				, monty.line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
				monty.line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * pstr- prints the string starting
 * at the top of the stack, followed by a new line.
 * @stack: head of stack
 * @linenum: current line num of monty
 */
void pstr(stack_t **stack,  __attribute__((unused))unsigned int linenum)
{
	stack_t *location = *stack;

	while (location && location->n > 0 && location->n <= 127)
	{
		putchar(location->n);
		location = location->next;
	}
	putchar('\n');
}


/**
 * rotl -rotates the stack to the top
 * @stack: head of stack
 * @linenum: current ln
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	stack_t *first, *second;

	if (!*stack || !(*stack)->next)
	{
		return;
	}

	first = *stack;
	second = (*stack)->next;
	*stack = second;
	second->prev = NULL;

	while (second->next)
	{
		second = second->next;
	}
	second->next = first;
	first->next = NULL;
	first->prev = second;
}

/**
 * rotr - otates the stack to the bottom.
 * @stack: head of stack
 * @linenum: current ln
 *
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	stack_t *first, *second;

	if (!(*stack) || !(*stack)->next)
	{
		return;
	}

	first = *stack;

	while (first->next->next)
	{
		first = first->next;
	}
	second = first->next;
	first->next = NULL;
	(*stack)->prev = second;
	second->next = *stack;
	second->prev = NULL;
	*stack = second;
}


