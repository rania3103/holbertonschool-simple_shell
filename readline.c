#include "main.h"
/**
 * readline - read line
 * Return: line
*/
char *readline()
{
	char *line = NULL;
	size_t sizebuf = 0;
	int r;

	r = getline(&line, &sizebuf, stdin);
	if (r == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);

		else
		{
			perror("error in readling line");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
