#include "monty.h"
/**
 * _push - insert new values in the stack.
 * @stack: Double pointer to the stack.
 * @line_number: value for include in the stack.
 * Return: Nothing.
 */
void _push(sstack_t **stack, unsigned int line_number)
{
	if (if_stack)
		add_stack(stack, line_number);
	else
		add_queue(stack, line_number);
}
