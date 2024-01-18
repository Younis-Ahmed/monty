#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct monty_s - global struct to hold all the things
 * @file: monty file
 * @line: line we are interpreting
 * @stack: the stack we are building
 * @line_number: current line number read
 * @is_queue: flag for stack/ queue
 *
 * Description: this is our single global and holds everything we need.
 */
typedef struct monty_s
{
	FILE *file;
	char *line;
	stack_t *stack;
	unsigned int line_number;
	bool is_queue;
} monty_t;

monty_t monty;

extern monty_t monty;

void montystruct_init(void);
void openfile(int, char *);
void read_line(void);
void free_all(void);
void free_stack(stack_t *h);
void push_queue(char *);
bool check_input(char *str);
void op_choose(stack_t **stack, char *opcode);
void push(char *);
void pall(stack_t **stack, __attribute__((unused))unsigned int);
void pint(stack_t **stack, __attribute__((unused))unsigned int);
void pop(stack_t **stack, __attribute__((unused))unsigned int);
void nop(stack_t **stack, __attribute__((unused))unsigned int);
void sub(stack_t **stack, __attribute__((unused))unsigned int);
void _div(stack_t **stack, __attribute__((unused))unsigned int);
void swap(stack_t **stack, __attribute__((unused))unsigned int);
void mul(stack_t **stack, __attribute__((unused))unsigned int);
void add(stack_t **stack, __attribute__((unused))unsigned int);
void pchar(stack_t **stack, __attribute__((unused))unsigned int);
void pstr(stack_t **stack, __attribute__((unused))unsigned int);
void rotl(stack_t **stack, __attribute__((unused))unsigned int);
void mod(stack_t **stack, __attribute__((unused))unsigned int);
void rotr(stack_t **stack, __attribute__((unused))unsigned int);
void _stack(stack_t **stack, __attribute__((unused))unsigned int);
void _queue(stack_t **stack, __attribute__((unused))unsigned int);


#endif
