#include "monty.h"
/**
 * _mul - multiplies two first elements of the stack
 * @stack:Double pointer to the stack
 * @line_number: value for includein the stack
 * Return: Nothing.
 */
void _mul(sstack_t **stack, unsigned int line_number)
{
	int mul = 0;

	if (*stack && (*stack)->next)
	{
		mul = ((*stack)->next->n * (*stack)->n);
		(*stack)->next->n = mul;
		_pop(stack, 0);
	}
	else
	{
		STATUS[0] = 'F';
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
	}
}
