#include "monty.h"

/**
 * free_stack - frees a stack.
 * @stack: pointer sstack_t input
 * Return: Nothing.
 */
void free_stack(sstack_t **stack)
{
	sstack_t *aux = NULL;

	while (*stack)
	{
		aux = *stack;
		*stack = (*stack)->next;
		free(aux);
	}
}
