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

/**
 * error1 - Error cant open a file
 * @file: Name of file
 *
 * Return: void
 */
void error1(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

/**
 * error2 - Error no correct usage
 *
 * Return: void
 */
void error2(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * error3 - Error not command correct
 * @line: Line
 * @cmd: Command
 *
 * Return: void
 */
void error3(int line, char *cmd)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, cmd);
	exit(EXIT_FAILURE);
}

/**
 * error4 - Error not integer on push
 * @line: Line
 *
 * Return: void
 */
void error4(int line)
{
	fprintf(stderr, "L%d: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}
