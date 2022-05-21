#include "monty.h"
/**
 * _sub - subtracts the top element
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
		(*stack)->next->n = sub;
		_pop(stack, 0);
	}
	else
	{
		STATUS[0] = 'F';
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
	}
}
