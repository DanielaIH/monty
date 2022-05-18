#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char *read_textfile(const char *filename, size_t text)
{
	int fd;
	ssize_t size_R;
	char *buffer;

	if (!filename)
	{
		printf("USAGE: monty file");
		return (NULL);
	}

	fd = open(filename, O_RDWR);
	if (fd == -1)
	{
		printf("Error: Can't open file %s", filename);
		return (NULL);
	}

	buffer = (char *)malloc(sizeof(char) * text);
	if (!buffer)
	{
		printf("Error: malloc failed");
		free(buffer);
		return (NULL);
	}

	size_R = read(fd, buffer, text);
	if (size_R == -1)
		return (NULL);

	printf("%s\n", buffer);
	
/*	free(buffer); */
	close(fd);
	return (buffer);
}

