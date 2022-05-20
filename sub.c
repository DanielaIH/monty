#include "monty.h"
/**
 * _sub - pops stack
 * @stack:Double pointer to the stack
 * @line_number: value for includein the stack
 * Return: Nothing.
 */
void _sub(sstack_t **stack, unsigned int line_number)
{
	int sub = 0;

	if (*stack && (*stack)->next)
	{
		sub = ((*stack)->next->n - (*stack)->n);
		_pop(stack, 0);
		(*stack)->n = sub;
	}
	else
	{
		STATUS[0] = 'F';
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
	}
}
