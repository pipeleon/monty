#include "monty.h"

/**
 * get_opcode - Check if opc is a opcode.
 * @opc: Command to check.
 * Return: a function-potiner to execute de opcode, NULL on failure.
 */
void (*get_opcode(char *opc))(stack_t **, unsigned int)
{
	instruction_t command[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};
	int cont = 0;

	while (command[cont].opcode)
	{
		if (strcmp(opc, command[cont].opcode) == 0)
			return (*(command[cont].f));
		cont++;
	}

	return (NULL);
}
