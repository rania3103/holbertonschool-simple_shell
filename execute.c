#include "main.h"
/**
 * execute - execute a command
 * @args: arguments
 * Return: 1
*/
int execute(char **args)
{
	char **path;
	int i, status;
	struct stat st;

	if (strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	if (strcmp(args[0], "env") == 0)
		print_env();
	path = tokenize_path(getenv("PATH"));
	if (path == NULL)
	{
		perror("failed to retrieve path");
		exit(EXIT_FAILURE);
	}
	for (i = 0; path[i] != NULL; i++)
	{
		char *buffer = construct_buffer(path[i], args[0]);

		if (stat(buffer, &st) == 0)
		{
			pid_t pid = fork();

			if (pid == -1)
				perror("Error in fork");
			else if (pid == 0)
			{
				if (execve(buffer, args, environ) == -1)
					perror("Error in execve");
				exit(EXIT_FAILURE);
			}
			else
			{
				do {
					waitpid(pid, &status, WUNTRACED);
				} while (!WIFEXISTED(status) && !WIFSIGNALED(status));
			}
		}
	}
	perror("command not found");
	return (1);
}
