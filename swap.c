#include "monty.h"
/**
 * _swap - pops stack
 * @stack:Double pointer to the stack
 * @line_number: value for includein the stack
 * Return: Nothing.
 */
void _swap(sstack_t **stack, unsigned int line_number)
{
	sstack_t *swap = NULL;
	(void)line_number;

	if (*stack)
	{
		swap = *stack;
		*stack = (*stack)->next;
		swap->prev = *stack, swap->next = (*stack)->next;
		(*stack)->prev = NULL, (*stack)->next = swap;
	}

}
