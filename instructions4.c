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
