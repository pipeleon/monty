#include "monty.h"
/* 0x19. C - Stacks, Queues - LIFO, FIFO  */

/**
 * main - Program to read monty opcodes
 * @argc: Count of the arguments supplied to the program
 * @argv: Array of pointers to the strings which are those arguments
 * Description: Monty
 * Return: int
 */
int main(int argc, char **argv)
{
	char line[1024];
	char *read, *comando, *dato;
	int (*f)(stack_t **, unsigned int), status, line_number = 1;
	unsigned int data_int;
	stack_t *new = NULL;
	FILE *fp = fopen(argv[1], "r");

	if (argc != 2 || !fp)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	read = fgets(line, 1024, fp);

	while (read)
	{
		comando = strtok(line, " \t\r\n\a");
		dato = strtok(NULL, " \t\r\n\a");
		if (dato == NULL)
			dato_int = 0;
		else
			dato_int  = _atoi(dato);
		printf("Comando = %s - Dato = %s\n", comando, dato);
		f = get_opcode(comando);
		if (!f)
		{
			fprintf(stderr, "L/%d: unknown instruction %s", line_number, comando);
			return (EXIT_FAILURE);
		}
		status = f(&new, dato_int);

		read = fgets(line, 1024, fp);
		line_number++;
	}

	fclose(fp);

	return (EXIT_SUCCESS);
}
