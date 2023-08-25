#include "main.h"
/**
 * main - entry point
 * Return: 0
*/
int main(void)
{
	char *line_input = NULL;
	int ex, r;
	size_t bufsize = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("simpleshell$");

		r = getline(&line_input, &bufsize, stdin);
		if (r == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				free(line_input);
				exit(EXIT_SUCCESS);
			}
			break;
		}
		if (strcmp(line_input, "exit\n") == 0)
		{
			free(line_input);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(line_input, "env\n") == 0)
		{
			print_env();
			free(line_input);
			exit(EXIT_SUCCESS);
		}
		ex = execute(line_input);
		if (ex == -1)
		{
			perror("error in execution");
			exit(EXIT_FAILURE);
		}
	}
	free(line_input);
	return (0);
}