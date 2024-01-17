#include "monty.h"


/**
 * nop - nothng
 * @stack: double list
 * @linenum: line
 */
void nop(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	(void)stack;
}

/**
 * sub -  the top element of the stack from
 *the second top element of the stack
 * @stack: double list
 * @linenum: line
 */
void sub(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	stack_t *freeable;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		freeable = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(freeable);
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
				monty.line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
}
/**
 * _div - divs top two stack mems
 * @stack: double list
 * @linenum: line
 */
void _div(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	stack_t *freeable;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n"
				, monty.line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", monty.line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n /= (*stack)->n;
		freeable = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(freeable);
	}
}
/**
 * mul -multiplies the second top element of the stack with the
 *top element of the stack
 * @stack: double list
 * @linenum: line
 */
void mul(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	stack_t *freeable;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n *= (*stack)->n;
		freeable = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(freeable);
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
				monty.line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
}
/**
 * mod - computes the rest of the division
 * of the second top element of the stack by the top element of the stack.
 * @stack: double list
 * @linenum: line
 */
void mod(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	stack_t *freeable;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n"
				, monty.line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", monty.line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n %= (*stack)->n;
		freeable = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(freeable);
	}
}
