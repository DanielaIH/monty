#include "monty.h"
/**
 * _pop - deletes first element of the stack
 * @stack:Double pointer to the stack
 * @line_number: value for includein the stack
 * Return: Nothing.
 */
void _pop(sstack_t **stack, unsigned int line_number)
{
	sstack_t *tmp;

	if (!*stack)
	{
		STATUS[0] = 'F';
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		return;
	}
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;

	if (tmp)
		tmp->prev = NULL;
}
