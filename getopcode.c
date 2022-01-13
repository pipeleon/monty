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
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
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

/**
 * check_comment - Checks if the line contains the # to reemplace for '\0'
 * @line: Line read by getline to check
 * Return: void
 */
void check_comment(char *line)
{
	int i = 0;

	while (*(line + i))
	{
		if (*(line + i) == 35)
		{
			*(line + i) = '\0';
			break;
		}
		i++;
	}
}
