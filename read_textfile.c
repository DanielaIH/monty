#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * read_textfile - Read the monty file
 * @filename: name of the monty file
 * @text: Read text.
 * Return: Pointer to the read text.
 */
char *read_textfile(const char *filename, size_t text)
{
	int fd;
	ssize_t size_R;
	char *buffer;

	if (!filename)
	{
		dprintf(2, "USAGE: monty file\n");
		return (NULL);
	}

	fd = open(filename, O_RDWR);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		return (NULL);
	}

	buffer = (char *)malloc(sizeof(char) * text);
	if (!buffer)
	{
		dprintf(2, "Error: malloc failed\n");
		free(buffer);
		return (NULL);
	}

	size_R = read(fd, buffer, text);
	if (size_R == -1)
		return (NULL);

/*	printf("%s\n", buffer); */
	close(fd);
	return (buffer);
}

