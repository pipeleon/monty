#include "monty.h"

/**
 * push - Prints all the elements of a stack
 * @stack: Stack
 * @line_number: Line number
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = line_number;
	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->next = *stack;
		new->prev = NULL;
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * pall - Prints all the elements of a stack
 * @stack: Stack
 * @line_number: Line number
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)(line_number);

	tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
