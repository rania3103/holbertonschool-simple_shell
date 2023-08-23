#include "main.h"
/**
 * main - entry point
 * Return: 0
*/
int main(void)
{
	char *line_input;
	char **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("simpleshell$");

		line_input = readline();
		args = tokenize(line_input);
		if (strcmp(args[0], "exit") == 0)
		{
			free(line_input);
			free(args);
			break;
		}
		execute(args);
		free(line_input);
		free(args);
	}
	return (0);
}
