#include "monty.h"
/**
 *  _add - pops stack
 * @stack:Double pointer to the stack
 * @line_number: value for includein the stack
 * Return: Nothing.
 */
void _add(sstack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack)
		printf("%d\n", (*stack)->n + (*stack)->next->n);
}
