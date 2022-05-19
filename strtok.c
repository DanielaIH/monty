#include "monty.h"
/**
 * _strtok - Split in tokens an string.
 * @tokens: Array of tokens.
 * @string: input text from file.
 * Return: Exit status
 */
char **_strtok(char **tokens, char *string)
{
	char *token = NULL, **tmp = NULL, *tok_tmp = NULL;
	int i = 0, j, k = 0;
	char opcodes[20][10] = { {"push"}, {"pall"}, {"pint"}, {"pop"}, {"swap"}, {""} };

	tokens = malloc(1024 * sizeof(char *));
	if (tokens == NULL)
	{
		free(tokens);
		return (NULL);
	}

	token = strtok(string, "\n");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, "\n");
	}
	tokens[i] = NULL;
	tmp = malloc(1024 * sizeof(char *));
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	for (i = 0; tokens[i]; i++)
	{
		tok_tmp = strtok(tokens[i], "\t\r ");
		for (j = 0; j < 5; j++)
		{
			if (!strcmp(tok_tmp, opcodes[j]))
			{
				tmp[k] = tok_tmp, k++;
				if (strcmp(tok_tmp, "push") == 0)
				{
					tok_tmp = strtok(NULL, "\t\r ");
					tmp[k] = tok_tmp, k++;
				}
			}
		}
	}
	tmp[k] = NULL;
	for (i = 0; tmp[i]; i++)
		if (strcmp(tmp[i], "push") == 0)
			if (tmp[i + 1] == NULL || _isnumber(tmp[i + 1]) == 0)
				tmp[i + 1] = NULL;
	free(tokens);
	return (tmp);
}
