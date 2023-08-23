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

	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (0);
	}

	path = tokenize_path(getenv("PATH"));
	if (path == NULL)
	{
		perror("failed to retrieve path");
		free(path);
		return (1);
	}
	for (i = 0; path[i] != NULL; i++)
	{
		char *buffer = construct_buffer(path[i], args[0]);

		if (stat(buffer, &st) == 0)
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("Error in fork");
				free(buffer);
				free(path);
				return (1);
			}
			else if (pid == 0)
			{
				if (execve(buffer, args, environ) == -1)
				{
					perror("Error in execve");
					free(buffer),
					free(path);
					return (1);
				}
				exit(EXIT_FAILURE);
			}
			else
			{
				do {
					waitpid(pid, &status, WUNTRACED);
				} while (!WIFEXITED(status) && !WIFSIGNALED(status));
				free(buffer);
			}
		}
	}
	perror("command not found");
	free(path);
	return (1);
}
