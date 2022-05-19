#include "monty.h"
/**
 * _push - insert new values in the stack.
 * @stack: Double pointer to the stack.
 * @line_number: value for include in the stack.
 * Return: Nothing.
 */
void _push(sstack_t **stack, unsigned int line_number)
{
	sstack_t *new, *aux;

	aux = *stack;
	new = malloc(sizeof(sstack_t));
	if (new == NULL)
		return;

	new->n = line_number;
	new->prev = NULL;
	if (!aux)
		new->next = NULL;
	else
	{
		while (aux->prev)
			aux = aux->prev;
		aux->prev = new;
		new->next = aux;
	}
	*stack = new;
}
