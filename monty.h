#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int queue_id;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void (*get_opcode(char *opc))(stack_t **, unsigned int);

void check_comment(char *line);

void push(stack_t **stack, unsigned int line_number);

void pall(stack_t **stack, unsigned int line_number);

void pint(stack_t **stack, unsigned int line_number);

void pop(stack_t **stack, unsigned int line_number);

void swap(stack_t **stack, unsigned int line_number);

void add(stack_t **stack, unsigned int line_number);

void nop(stack_t **stack, unsigned int line_number);

void sub(stack_t **stack, unsigned int line_number);

void _div(stack_t **stack, unsigned int line_number);

void _mul(stack_t **stack, unsigned int line_number);

void _mod(stack_t **stack, unsigned int line_number);

void pchar(stack_t **stack, unsigned int line_number);

void pstr(stack_t **stack, unsigned int line_number);

void rotl(stack_t **stack, unsigned int line_number);

void rotr(stack_t **stack, unsigned int line_number);

void _stack(stack_t **stack, unsigned int line_number);

void _queue(stack_t **stack, unsigned int line_number);

void free_stack(stack_t *head);

void error1(char *file);

void error2(void);

void error3(int line, char *cmd);

void error4(int line);

void error5(int line);

void error6(int line);

void error7(int line);

void error8(int line);

void error9(int line);

void error10(int line);

void error11(int line);

int _atoi(char *s);

int isnumber(char *s);

#endif
