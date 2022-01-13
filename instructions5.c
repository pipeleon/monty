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

/**
 * pchar - prints the char at the top of the stack
 * @stack: Stack
 * @line_number: Line number
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		putchar((*stack)->n), printf("\n");
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: Stack
 * @line_number: Line number
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int n;

	(void)(line_number);
	tmp = *stack;
	n = tmp->n;

	while (tmp && n >= 1 && n <= 127)
	{
		putchar(n);

		tmp = tmp->next;
		n = tmp->n;
	}
	printf("\n");
}
