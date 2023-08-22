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
		printf("simpleshell$");
		line_input = readline();
		args = tokenize(line_input);
		execute(args);
		free(line_input);
		free(args);
	}
	return (0);
}
