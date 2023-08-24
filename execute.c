#include "main.h"
/**
 * execute - execute a command
 * @args: arguments
 * Return: 1
*/
int execute(char *line_input)
{
	char **args;
	char *path;
	pid_t pid;
	int exit_stat = 0; 
	int status;

	args = tokenize(line_input);
	if (args == NULL)
		return (-1);
	if (line_input[0] == '/')
	{
		path = strdup(line_input);
	}
	else
	{
		path = get_path(args[0]);
	}
	if (path == NULL)
	{
		free(args);
		return (-1);
	}
	pid = fork();
	if (pid < 0)
	{
		free(args);
		free(path);
		return (-1);
	}
	else if (pid == 0)
	{
		exit_stat = execve(path, args, environ);
	}
	else
	{
		wait(&status);
		free(args);
		free(path);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
	}
	return (exit_stat);
}
