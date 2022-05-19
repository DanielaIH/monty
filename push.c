#include "monty.h"
/**
 * _push - insert new values in the stack.
 * @stack: Double pointer to the stack.
 * @line_number: value for include in the stack.
 * Return: Nothing.
 */
void _push(sstack_t **stack, unsigned int line_number)
{
	sstack_t *tmp;

	if (stack == NULL)
		return;
	tmp = malloc(sizeof(sstack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free(tmp);
		exit(EXIT_FAILURE);
	}
	tmp->n = line_number;
	if (*stack == NULL)
	{
		tmp->next = *stack;
		tmp->prev = NULL;
		*stack = tmp;
	}
	(*stack)->prev = tmp;
	tmp->next = (*stack);
	tmp->prev = NULL;
	*stack = tmp;
}
