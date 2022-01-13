#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: Stack
 * @line_number: Line number
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp2, *new;
	int n;

	(void)(line_number);
	tmp = *stack;

	if (tmp == NULL || tmp->next == NULL)
		return;

	n = tmp->n;

	*stack = (*stack)->next;
	free(tmp);

	tmp2 = *stack;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;

	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	new->prev = tmp2;
	tmp2->next = new;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: Stack
 * @line_number: Line number
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp2, *new;
	int n;

	(void)(line_number);
	tmp = *stack;

	if (tmp == NULL || tmp->next == NULL)
		return;

	while (tmp->next != NULL)
		tmp = tmp->next;

	n = tmp->n;
	tmp2 = tmp->prev;

	tmp2->next = NULL;
	free(tmp);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = *stack;
	new->prev = NULL;
	(*stack)->prev = new;
	*stack = new;
}
