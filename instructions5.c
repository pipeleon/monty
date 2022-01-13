#include "monty.h"

/**
 * error10 - Error sub
 * @line: Line
 *
 * Return: void
 */
void error10(int line)
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line);
	exit(EXIT_FAILURE);
}
