#include "monty.h"
/**
 * _mod - computes the rest of the division two first elements of the stack
 * @stack:Double pointer to the stack
 * @line_number: value for includein the stack
 * Return: Nothing.
 */
void _mod(sstack_t **stack, unsigned int line_number)
{

	int mod = 0;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			STATUS[0] = 'F';
			dprintf(2, "L%d: division by zero\n", line_number);
			return;
		}
		mod = ((*stack)->next->n % (*stack)->n);
		(*stack)->next->n = mod;
		_pop(stack, 0);
	}
	else
	{
		STATUS[0] = 'F';
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
	}
}
