#include "monty.h"
/**
 * _pop - pops stack
 * @stack:Double pointer to the stack
 * @line_number: value for includein the stack
 * Return: Nothing.
 */
void _pop(sstack_t **stack, unsigned int line_number)
{
	sstack_t *tmp;

	if (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	else
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
}
