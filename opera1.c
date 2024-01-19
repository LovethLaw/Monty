#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @linenumber: line number in the file
 */
void add(stack_t **stack, unsigned int linenumber)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", linenumber);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;

	pop(stack, linenumber);
}
/**
 * nop - function doesn't do anything
 * @stack: pointer to the stack
 * @linenumber: line number in the file
 */
void nop(stack_t **stack, unsigned int linenumber)
{
	(void)stack;
	(void)linenumber;
	/* This function does nothing */
}
/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @linenumber: line number in the file
 */
void pop(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", linenumber);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @linenumber: line number in the file
 */
void swap(stack_t **stack, unsigned int linenumber)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", linenumber);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
