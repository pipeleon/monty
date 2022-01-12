#include "monty.h"

void pull(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit (EXIT_FAILURE);
	}
	new->n = line_number;
	if (*head == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->next = *head;
		new->prev = NULL;
		(*head)->prev = new;
	}
	*head = new;
}

void pall(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);
	if ((*stack) != NULL)
	{
		printf("%d\n", (*stack)->n);
		if ((*stack)->next != NULL)
			pall((*stack)->next);
	}
}
