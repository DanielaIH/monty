#include "monty.h"
/**
 * _pall - print all values in the stack.
 * @stack: Double pointer to the stack.
 * @line_number: atribute without use.
 * Return: Nothing.
 */
void _pall(sstack_t **stack, __attribute__((unused))unsigned int line_number)
{
	sstack_t *aux = *stack;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
