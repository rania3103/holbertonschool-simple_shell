#include "main.h"

/**
 * tokenize_path - tokenize PATH variable
 * @p: full path
 * Return: array of pointers to path tokens
*/
char **tokenize_path(char *p)
{
	char **buffer;
	int i = 0;
	char *token;

	buffer = (char **) malloc(sizeof(char *) * 1024);
	if (buffer == NULL)
	{
		perror("error in memory allocation");
		exit(EXIT_FAILURE);
	}
	token = strtok(p, ":");
	while (token != NULL)
	{
		buffer[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	buffer[i] = NULL;
	return (buffer);
}
/**
 * get_path - get path
 * @cmd:command
 * Return: path or NULL on error
*/
char *get_path(char *cmd)
{
	char *envp, *copenvp, *res = NULL;
	char path[1024];
	char *token;
	struct stat st;

	envp = getenv("PATH");
	if (envp == NULL)
		return (NULL);
	copenvp = strdup(envp);
	token = strtok(copenvp, ":");
	while (token)
	{
		sprintf(path, "%s/%s", token, cmd);
		if (stat(path, &st) == 0)
		{
			res = strdup(path);
			free(copenvp);
			return (res);
		}
		token = strtok(NULL, ":");
	}
	free(copenvp);
	return (NULL);
}

/**
 * print_env - print the enviroment
*/
void print_env(void)
{
	char **enviroment = environ;

	while (*enviroment != NULL)
	{
		printf("%s\n", *enviroment);
		enviroment++;
	}
}