#include "main.h"
/**
 * readline - read line
 * Return: line
*/
char *readline()
{
	char *line;
	size_t size;
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
		exit(0);
	}
	return (line);
}
