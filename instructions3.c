#include "monty.h"

/**
 * error5 - Error swap
 * @line: Line
 *
 * Return: void
 */
void error5(int line)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * error6 - Error add
 * @line: Line
 *
 * Return: void
 */
void error6(int line)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * add - Add the top element of the stack with the 2
 * @stack: Stack
 * @line_number: Line number
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int suma;
	stack_t *tmp;

	(void)(line_number);
	tmp = *stack;
	suma = (*stack)->n + ((*stack)->next)->n;
	*stack = (*stack)->next;
	(*stack)->n = suma;
	free(tmp);
}

/**
 * nop - Does nothing
 * @stack: Stack
 * @line_number: Line number
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
}

/**
 * sub - Sub the top element of the stack with the 2
 * @stack: Stack
 * @line_number: Line number
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int resta;
	stack_t *tmp;

	(void)(line_number);
	tmp = *stack;
	resta = ((*stack)->next)->n - (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->n = resta;
	free(tmp);
}
