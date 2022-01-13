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
	void (*f)(stack_t **, unsigned int);
	unsigned int dato_int, line_number = 1;
	stack_t *new = NULL;
	FILE *fp;

	if (argc != 2)
		error2();
	fp = fopen(argv[1], "r");
	if (!fp)
		error1(argv[1]);
	read = fgets(line, 1024, fp);
	while (read)
	{
		comando = strtok(line, " \t\r\n\a"), dato = strtok(NULL, " \t\r\n\a");
		if (comando != NULL)
		{
			f = get_opcode(comando);
			if (!f)
				free_stack(new), fclose(fp), error3(line_number, comando);
			if (f == push)
			{
				if (dato == NULL || isnumber(dato) == 0)
					free_stack(new), fclose(fp), error4(line_number);
				else
					dato_int = _atoi(dato);
			}
			else if (f == swap && (new == NULL || new->next == NULL))
				free_stack(new), fclose(fp), error5(line_number);
			else if (f == add && (new == NULL || new->next == NULL))
				free_stack(new), fclose(fp), error6(line_number);
			else if (f == sub && (new == NULL || new->next == NULL))
				free_stack(new), fclose(fp), error7(line_number);
			else if (f == _div && (new == NULL || new->next == NULL))
				free_stack(new), fclose(fp), error8(line_number);
			else if (f == _div && new->n == 0)
				free_stack(new), fclose(fp), error9(line_number);
			else
				dato_int = line_number;
			f(&new, dato_int);
		}
		read = fgets(line, 1024, fp), line_number++;
	}
	fclose(fp), free_stack(new);
	return (EXIT_SUCCESS);
}
