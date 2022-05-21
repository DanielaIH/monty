#include "monty.h"
/**
 * _div - pops stack
 * @stack:Double pointer to the stack
 * @line_number: value for includein the stack
 * Return: Nothing.
 */
void _div(sstack_t **stack, unsigned int line_number)
{
	int div = 0;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			STATUS[0] = 'F';
			dprintf(2, "L%d: division by zero\n", line_number);
			return;
		}
		div = ((*stack)->next->n / (*stack)->n);
		(*stack)->next->n = div;
		_pop(stack, 0);
	}
	else
	{
		STATUS[0] = 'F';
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
	}
}
