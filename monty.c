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
	int i;
	/* int in_func = 0; */
	char *buffer = NULL, **tokens = NULL;
	/* void (*func)(sstack_t, unsigned int); */
	struct stack_s **stack = NULL;
	(void)argc;

	printf("here\n");
	buffer = read_textfile(argv[1], 1024);
	if (!buffer)
		exit(EXIT_FAILURE);

	printf("here");
	tokens = _strtok(tokens, buffer);
	for (i = 0; tokens[i]; i++)
		printf("%s", tokens[i]);
	get_function_stack(tokens, stack);

	free(tokens);
	return (0);
}
