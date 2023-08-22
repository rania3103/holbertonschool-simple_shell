#include "main.h"
/**
 * execute - execute a line
 * @args: arguments
*/
void execute(char **args)
{
	pid_t pid;
	char **path;
	struct stat st;
	int i = 0;

	if (strcmp(args[0], "exit") == 0)
		exit(0);
	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return;
	}
	path = tokenize_path(get_path());
	while (path[i] != NULL)
	{
		char *buffer = construct_buffer(path[i], args[0]);

		if (stat(buffer, &st) == 0)
		{
			pid = fork();
			if (pid == -1)
				perror("error in fork");
			else if (pid == 0)
			{
				if (execve(buffer, args, NULL) == -1)
				{
					perror("Error in execve");
					exit(1);
				}
			}
			else
			{
				wait(NULL);
				break;
			}
		}
		i++;
	}
	free(path);
}
