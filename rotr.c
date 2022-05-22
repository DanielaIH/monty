#include "monty.h"
/**
 * _rotr - rotates the stack to the bottom.
 * @stack:Double pointer to the stack
 * @line_number: value for includein the stack
 * Return: Nothing.
 */
void _rotr(sstack_t **stack, unsigned int line_number)
{
	sstack_t *last_node, *prev_last_node;
	(void)line_number;

	if (*stack && (*stack)->next)
	{
		last_node = *stack, prev_last_node = *stack;
		while (prev_last_node->next->next)
			prev_last_node = prev_last_node->next;
		while (last_node->next)
			last_node = last_node->next;
		prev_last_node->next = NULL;
		last_node->prev = NULL;
		last_node->next = *stack;
		(*stack)->prev = last_node;
		*stack = last_node;
	}
}
