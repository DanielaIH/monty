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
	size_t size = 0, i;
	char *buffer = NULL, **tokens = NULL;
	sstack_t *stack = NULL;
	(void)argc;

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&buffer, &size, fd)) != -1)
	{
		tokens = NULL, lines++;
		if (strcmp(buffer, "\n") != 0)
		{
			tokens = _strtok(tokens, buffer);
			for (i = 0; tokens[i]; i++)
				printf("tokens[%ld] : %s\n", i, tokens[i]);
			gf = get_function_stack(tokens, &stack);
			if (gf == 1)
			{
				dprintf(2, "L%d: usage: push integer\n", lines);
				exit(EXIT_FAILURE);
			}
			free(tokens);
		}
	}
	free(buffer);
	fclose(fd);
	free_stack(&stack);
	return (0);
}
