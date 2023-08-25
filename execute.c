#include "main.h"
/**
 * execute - Executes a command
 * @line_input: Line input from the user
 *
 * Return: exit_stat (0 on success or -1 on error)
*/
int execute(char *line_input)
{
	char **args = NULL;
	char *path = NULL;
	pid_t pid;
	int status, exit_stat = 0;

	args = tokenize(line_input);
	if (args == NULL)
		return (-1);

	if (line_input[0] == '/')
		path = strdup(line_input);
	else
		path = get_path(args[0]);
	if (path == NULL)
	{
		free_tokens(args);
		return (-1);
	}
	pid = fork();
	if (pid < 0)
	{
		free_tokens(args);
		free(path);
		return (-1);
	}
	else if (pid == 0)
		exit_stat = execve(path, args, environ);
	else
	{
		wait(&status);
		free(path);
		free(args);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	free_tokens(args);
	free(path);
	return (exit_stat);
}
