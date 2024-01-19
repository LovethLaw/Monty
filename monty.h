#ifndef MONTY_H
#define MONTY_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*Linked list data structure*/
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

/*Opcode Instructions data structure*/
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

void push(stack_t **stack, unsigned int linenumber);
void pall(stack_t **stack, unsigned int linenumber);
void free_stack(stack_t **stack);
bool is_a_number(char *ch_arr);
void pint(stack_t **stack, unsigned int linenumber);
void pop(stack_t **stack, unsigned int linenumber);
void swap(stack_t **stack, unsigned int linenumber);
void add(stack_t **stack, unsigned int linenumber);
void nop(stack_t **stack, unsigned int linenumber);
void push_stack(stack_t **stack, int value);
void print_stack(stack_t *stack);
void sub(stack_t **stack, unsigned int linenumber);
void div_func(stack_t **stack, unsigned int linenumber);
void mul_func(stack_t **stack, unsigned int linenumber);
void op_div(stack_t **stack, unsigned int linenumber);
void mod(stack_t **stack, unsigned int linenumber);
void pchar(stack_t **stack, unsigned int linenumber);
#endif
