#include "monty.h"

/**
 * _ts_handler - function for handler tabs and spaces.
 * @line: char pointer input.
 * Return: Nothing.
 */

void ts_handler(char *line)
{
	char *cpyline = malloc((strlen(line) + 1) * sizeof(char));
	int i = 0, j = 0;

	strcpy(cpyline, line);
	while (cpyline[i])
	{
		if (cpyline[i] == ' ' || cpyline[i] == '\t')
		{
			if (i > 0 && (cpyline[i - 1] != ' ' && cpyline[i - 1] != '\t'))
				strcpy(&line[j], " "), j++;
			i++;
		}
		else
			strcpy(&line[j], &cpyline[i]), j++, i++;
	}
	if (line[j - 2] == ' ')
		line[j - 2] = '\0';
	free(cpyline);
}
