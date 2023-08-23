#include "main.h"
/**
 * main - entry point
 * Return: 0
*/
int main(void)
{
	char *line_input;
	char **args;
	int ex;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("simpleshell$");

		line_input = readline();
		args = tokenize(line_input);
		ex = execute(args);

		free(line_input);
		free(args);
	}
	return (0);
}
