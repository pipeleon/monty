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
