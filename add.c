#include "monty.h"
/**
 *  _add - adds the top two elements
 * @stack:Double pointer to the stack
 * @line_number: value for includein the stack
 * Return: Nothing.
 */
void _add(sstack_t **stack, unsigned int line_number)
{
	int sum = 0;

	if (*stack && (*stack)->next)
	{
		sum = ((*stack)->n + (*stack)->next->n);
		_pop(stack, 0);
		(*stack)->n = sum;
	}
	else
	{
		STATUS[0] = 'F';
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
	}
}
