#include "monty.h"
/**
 * _strtok - Split in tokens an string.
 * @tokens: Array of tokens.
 * @string: input text from file.
 * Return: Exit status
 */
char **_strtok(char **tokens, char *string)
{
	char *token = NULL;
	int i = 0;

	tokens = malloc(1024 * sizeof(char *));
	if (tokens == NULL)
	{
		free(tokens);
		return (NULL);
	}

	token = strtok(string, "\t \n\r");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, "\t \n\r");
	}
	tokens[i] = NULL;
	i = 0;
	while (tokens[i])
	{
		if (strcmp(tokens[i], "push") == 0)
			if (tokens[i + 1] == NULL || _isnumber(tokens[i + 1]) == 0)
				tokens[i + 1] = NULL;
		i++;
	}
	free(token);
	return (tokens);
}
