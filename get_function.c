#include "monty.h"
/**
 * get_function_stack - Gives the function to use.
 * @tokens: Array of tokens.
 * @stack: The stack.
 * Return: Nothing.
 */

int get_function_stack(char **tokens, sstack_t **stack)
{
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL} };
	int i = 0, j = 0, lines = 1;
	unsigned int number = 0;
	char **stacks = NULL;

	stacks = malloc(20 * sizeof(char *));
	stack = malloc(10 * sizeof(sstack_t));
	if (tokens[0] == NULL)
		tokens[0] = "spaces";
	for (j = 0; tokens[j]; j++)
	{
		for (i = 0; ops[i].opcode; i++)
			if (strcmp(ops[i].opcode, tokens[j]) == 0)
			{
				if (strcmp(tokens[j], "push") == 0)
				{
					if (tokens[j + 1] != NULL)
					{	number = _char_to_number(tokens[j + 1]);
						ops[i].f(stack, number);
					}	else
					{
						dprintf(2, "L%d: usage: push integer\n", lines);
						exit(EXIT_FAILURE);
					}
				}	else
					ops[i].f(stack, 0);
				stacks[lines] = ops[i].opcode;
				lines++;
			}
	}
	return (0);
}
