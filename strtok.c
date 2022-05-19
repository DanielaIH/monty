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
	tokens[i] = token;
	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, "\t \n\r"), i++;
		tokens[i] = token;
		printf("%s\n", tokens[i]);
		if (tokens[i] == NULL || _isnumber(tokens[i]) == 0)
			tokens[i] = NULL;
	}
	i++, tokens[i] = NULL;
	return (tokens);
}