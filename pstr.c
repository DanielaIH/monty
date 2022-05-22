#include "monty.h"
/**
 * _pstr - print the word from first element of the stack
 * @stack:Double pointer to the stack
 * @line_number: value for includein the stack
 * Return: Nothing.
 */
void _pstr(sstack_t **stack, unsigned int line_number)
{
	char c;
	sstack_t *tmp = *stack;

	(void) line_number;
	if (*stack)
	{
		while (tmp)
		{
			c = tmp->n;
			if ((c > 64 && c < 91) || (c > 96 && c < 123))
				printf("%c", c);
			if (!tmp->next || tmp->n == 0)
			{
				printf("\n");
				return;
			}
			else
			{
				tmp = tmp->next;
				c = tmp->n;
			}
		}
	}
	else
		printf("\n");
}
