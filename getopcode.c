#include "monty.h"

/**
 * get_opcode - Check if opc is a opcode.
 * @opc: Command to check.
 * Return: a function-potiner to execute de opcode, NULL on failure.
 */
int (*get_opcode(char *opc))(stack_t **, unsigned int)
{
	instruction_t command[] = {
		{"push", _push},
		{"pall", _pall},
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
