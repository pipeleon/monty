#include "monty.h"

/**
 * free_stack - Free stacks
 * @head: Stack
 *
 * Return: void
 */

void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	if (head->next != NULL)
		free_stack(head->next);

	free(head);
}
