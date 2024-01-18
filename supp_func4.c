#include "monty.h"


/**
 * _stack -sets the format of the data to a stack (LIFO).
 *  This is the default behavior of the program.
 * @stack: head of stack
 * @linenum: current ln
 *
 */
void _stack(stack_t **stack, unsigned int linenum)
{
	(void)stack;
	(void)linenum;
	monty.is_queue = false;
}

/**
 * _queue -sets the format of the data to a queue (FIFO).
 * @stack: head of stack
 * @linenum: current ln
 */
void _queue(stack_t **stack, unsigned int linenum)
{
	(void)stack;
	(void)linenum;
	monty.is_queue = true;
}
