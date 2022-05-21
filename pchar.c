#include "monty.h"
/**
 * _pchar - print the ASCII char first element of the stack
 * @stack:Double pointer to the stack
 * @line_number: value for includein the stack
 * Return: Nothing.
 */
void _pchar(sstack_t **stack, unsigned int line_number)
{
char c;

if (*stack)
{
	c = (*stack)->n;
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		printf("%c\n", c);
	else
	{
		STATUS[0] = 'F';
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		return;
	}
}
else
{
	STATUS[0] = 'F';
	dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
}
}
