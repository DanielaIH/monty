#include "monty.h"
/**
 * main - interpretes Monty byte codes and executes them.
 * @argc: Number of argv
 * @argv: Arguments
 * Return: Exit status
 */

int main(int argc, char *argv[])
{
	/*ssize_t fd;*/
	int in_func = 0;
	char *buffer = NULL, **tokens = NULL;
	/* void (*func)(sstack_t, unsigned int); */
	struct stack_s **stack = NULL;
	(void)argc;

	buffer = read_textfile(argv[1], 1024);
	if (!buffer)
		return (EXIT_FAILURE);

	tokens = _strtok(tokens, buffer);
/*	while (tokens[i])
	{
		printf("opcode : %s\n", tokens[i]); only print the tokens 
		i++;
	}
*/
	in_func = get_function_stack(tokens, stack);
	if (in_func > 0)
		printf("I find a function");

	free(tokens);
	return (0);
}
