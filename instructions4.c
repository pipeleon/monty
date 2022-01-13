#include "monty.h"

/**
 * error7 - Error sub
 * @line: Line
 *
 * Return: void
 */
void error7(int line)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * error8- Error div 1
 * @line: Line
 *
 * Return: void
 */
void error8(int line)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * error9- Error div 2
 * @line: Line
 *
 * Return: void
 */
void error9(int line)
{
	fprintf(stderr, "L%d: division by zero\n", line);
	exit(EXIT_FAILURE);
}

/**
 * _div - Div the top element of the stack with the 2
 * @stack: Stack
 * @line_number: Line number
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int total;
	stack_t *tmp;

	(void)(line_number);
	tmp = *stack;
	total = ((*stack)->next)->n / (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->n = total;
	free(tmp);
}
