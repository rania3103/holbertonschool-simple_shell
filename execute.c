#include "main.h"
/**
 * execute - execute a command
 * @line_input: line
 * Return: 1
*/
int execute(char *line_input)
{
	char **args;
	char *path = NULL;
	pid_t pid;
	int status, exit_stat = 0;

	args = tokenize(line_input);
	if (args == NULL)
	{
		free(args);
		return (-1);
	}
	if (line_input[0] == '/')
		path = strdup(line_input);
	else
		path = get_path(args[0]);
	if (path == NULL)
	{
		free(args);
		free(path);
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
		exit_stat = execve(path, args, environ);
	else
	{
		wait(&status);
		free(args);
		free(path);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	free(path);
	free(args);
	return (exit_stat);
}
