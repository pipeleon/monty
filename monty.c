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
	char *read, *comando, *dato; /**case_push = "push"*/
	void (*f)(stack_t **, unsigned int);
	int line_number = 1;
	unsigned int dato_int;
	stack_t *new = NULL;
	FILE *fp = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read = fgets(line, 1024, fp);
	while (read)
	{
		comando = strtok(line, " \t\r\n\a"), dato = strtok(NULL, " \t\r\n\a");
		if (comando != NULL)
		{
			f = get_opcode(comando);
			if (!f)
			{
				fprintf(stderr, "L/%d: unknown instruction %s\n", line_number, comando);
				return (EXIT_FAILURE);
			}
			if (f == push)
			{
				if (dato == NULL || isnumber(dato) == 0)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				else
					dato_int = _atoi(dato);
			}
			else
				dato_int = 0;
			f(&new, dato_int);
		}
		read = fgets(line, 1024, fp), line_number++;
	}
	fclose(fp);
	return (EXIT_SUCCESS);
}
