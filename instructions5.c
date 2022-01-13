#include "monty.h"

/**
 * error10 - Error mul
 * @line: Line
 *
 * Return: void
 */
void error10(int line)
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * error11 - Error mod
 * @line: Line
 *
 * Return: void
 */
void error11(int line)
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * _mod - Mod the top element of the stack with the 2
 * @stack: Stack
 * @line_number: Line number
 *
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int total;
	stack_t *tmp;

	(void)(line_number);
	tmp = *stack;
	total = ((*stack)->next)->n % (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->n = total;
	free(tmp);
}
