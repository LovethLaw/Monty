#include "monty.h"
/**
 * push_stack - pushes a new node onto the stack
 * @stack: pointer to the stack
 * @value: value to be pushed onto the stack
 */
void push_stack(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * print_stack - prints all values on the stack
 * @stack: pointer to the stack
 */
void print_stack(stack_t *stack)
{
	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
/**
 * push - pushes an element onto the stack
 * @stack: pointer to the stack
 * @linenumber: line number in the file
 */
void push(stack_t **stack, unsigned int linenumber)
{
	char *valuestr;
	int value;

	valuestr = strtok(NULL, " \t\n");
	if (!valuestr || !is_a_number(valuestr))
	{
		fprintf(stderr, "L%u: usage: push integer\n", linenumber);
		exit(EXIT_FAILURE);
	}

	value = atoi(valuestr);

	push_stack(stack, value);
}

/**
 * pall - prints all values on the stack
 * @stack: pointer to the stack
 * @linenumber: line number in the file
 */
void pall(stack_t **stack, unsigned int linenumber)
{
	(void)linenumber;

	print_stack(*stack);
}


/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @linenumber: line number in the file
 */
void pint(stack_t **stack, unsigned int linenumber)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", linenumber);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
