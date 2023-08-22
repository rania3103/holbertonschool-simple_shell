#include "main.h"
/**
 * readline - read line
 * Return: line
*/
char *readline()
{
	char *line = NULL;
	size_t size = 0;
	int r;

	r = getline(&line, &size, stdin);

	if (r == -1)
	{
		perror("error reading line");
		free(line);
		exit(1);
	}
	if (r == EOF)
	{
		free(line);
		return (NULL);
	}
	if (line[r - 1] == '\n')
	{
		line[r - 1] = '\0';
	}
	free(line);
	return (line);
}
