#include "monty.h"
/**
 * get_function_stack - Gives the function to use.
 * @tokens: Array of tokens.
 * @stack: The stack.
 * @lines: numbers of lines in the file
 * Return: Nothing.
 */

int get_function_stack(char **tokens, sstack_t **stack, unsigned int lines)
{
	instruction_t ops[] = { {"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop}, {"swap", _swap},	{"add", _add}, {"sub", _sub},
				{"div", _div}, {"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
				{"pstr", _pstr}, {"rotl", _rotl}, {"rotr", _rotr},
				{"nop", _nop}, {"\n", _nop}, {NULL, NULL} };
	int i = 0, j = 0, find_func = 0, number = 0, out = 0;

	for (j = 0; tokens[j]; j++)
	{
		for (i = 0; ops[i].opcode; i++)
		{
			if (strcmp(ops[i].opcode, tokens[j]) == 0)
			{	find_func = 1;
				if (strcmp(tokens[j], "push") == 0)
				{
					if (!tokens[j + 1])
						return (1);
					out = _char_to_number(tokens[j + 1], &number);
					if (out)
						return (1);
					if (!number || atoi(tokens[j + 1]) != 0)
					{	number = atoi(tokens[j + 1]), ops[i].f(stack, number);
						return (0);
					} else
						return (1);
				} else
				{
					ops[i].f(stack, lines);
					if (!strcmp(&STATUS[0], "F"))
						return (3);
					return (0);
				}
			} else
				find_func = 0;
		}
		if (find_func == 0)
			return (2);
	}
	return (0);
}
