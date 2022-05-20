#include "monty.h"
/**
 * _sub - pops stack
 * @stack:Double pointer to the stack
 * @line_number: value for includein the stack
 * Return: Nothing.
 */
void _sub(sstack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack && (*stack)->next)
		printf("%d\n", (*stack)->n - (*stack)->next->n);
}
