#include "monty.h"
/**
 * _rotl - rotates the stack to the top.
 * @stack:Double pointer to the stack
 * @line_number: value for includein the stack
 * Return: Nothing.
 */
void _rotl(sstack_t **stack, unsigned int line_number)
{
	sstack_t *second_node, *last_node;
	(void)line_number;

	if (*stack && (*stack)->next)
	{
		second_node = (*stack)->next, last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = *stack;
		(*stack)->prev = last_node;
		(*stack)->next = NULL;
		second_node->prev = NULL;
		*stack = second_node;
	}
}
