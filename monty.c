#include "monty.h"

/**
 * main - interpretes Monty byte codes and executes them.
 * @argc: Number of argv
 * @argv: Arguments
 * Return: Exit status
 */

int main(int argc, char *argv[])
{
	int lines = 0, gf = 0;
	FILE *fd;
	/*ssize_t size_R; */
	size_t size = 0;
	char *buffer = NULL, **tokens = NULL;
	sstack_t *stack = NULL;

	if (argc != 2)
	{	dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{	dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&buffer, &size, fd)) != -1)
	{
		tokens = NULL, lines++;
		ts_handler(buffer);
		if (strcmp(buffer, "\n") != 0)
		{
			tokens = _strtok(tokens, buffer);
			gf = get_function_stack(tokens, &stack);
			if (gf == 1)
			{
				free(tokens), free(buffer), free_stack(&stack), fclose(fd);
				dprintf(2, "L%d: usage: push integer\n", lines), exit(EXIT_FAILURE);
			}
			if (gf == 2)
			{
				dprintf(2, "L%d: unknown instruction %s\n", lines, tokens[0]);
				free(buffer), free_stack(&stack), fclose(fd);
				free(tokens), exit(EXIT_FAILURE);
			} free(tokens);
		}
	}
	free(buffer), free_stack(&stack), fclose(fd);
	return (0);
}
