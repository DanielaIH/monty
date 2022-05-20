#ifndef _MONTY_H_
#define _MONTY_H_
/* #include <unistd.h> */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

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
} sstack_t;

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
	void (*f)(sstack_t **stack, unsigned int line_number);
} instruction_t;

char **_strtok(char **tokens, char *string);
int get_function_stack(char **tokens, sstack_t **stack);
int _char_to_number(char *str, int *ptr_number);
unsigned int _isnumber(char *str);
void _push(sstack_t **stack, unsigned int line_number);
void _pall(sstack_t **stack, unsigned int line_number);
void _pint(sstack_t **stack, unsigned int line_number);
void _pop(sstack_t **stack, unsigned int line_number);
void _swap(sstack_t **stack, unsigned int line_number);
void _add(sstack_t **stack, unsigned int line_number);
void _nop(sstack_t **stack, unsigned int line_number);
void _sub(sstack_t **stack, unsigned int line_number);
void _div(sstack_t **stack, unsigned int line_number);
void _mul(sstack_t **stack, unsigned int line_number);
void _mod(sstack_t **stack, unsigned int line_number);
void _pchar(sstack_t **stack, unsigned int line_number);
void _pstr(sstack_t **stack, unsigned int line_number);
void _rotl(sstack_t **stack, unsigned int line_number);
void _rotr(sstack_t **stack, unsigned int line_number);
void _stack(sstack_t **stack, unsigned int line_number);
void _queue(sstack_t **stack, unsigned int line_number);
void free_stack(sstack_t **stack);
void ts_handler(char *line);

#endif /* _MONTY_H_ */
