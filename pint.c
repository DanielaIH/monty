#include "monty.h"
/**
 * _pint - pops stack
 * @stack:Double pointer to the stack
 * @line_number: value for includein the stack
 * Return: Nothing.
 */
void _pint(sstack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
		printf("L%d: can't pint, stack empty\n", line_number);
}
