#include "main.h"
/**
 * construct_buffer - Construct the buffer path.
 * @path: Path to the command
 * @args: Command arguments
 *Return: Buffer containing the full path to the command
 */
char *construct_buffer(char *path, char *args)
{
	int path_len = strlen(path);
	int args_len = strlen(args);
	char *buffer = malloc(path_len + 1 + args_len + 1);

	if (buffer == NULL)
	{
		perror("error in buffer malloc for path");
		exit(EXIT_FAILURE);
	}
	sprintf(buffer, "%s%s", path, args);
	return (buffer);
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

/**
 * get_path - get the PATH variable
 * Return: pointer to the PATH pointer string
*/
char *get_path()
{
	char *p = getenv("PATH");

	if (p == NULL)
	{
		perror(" enviroment not found");
		exit(EXIT_FAILURE);
	}
	return (p);
}

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

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		perror("error in memory allocation");
		exit(EXIT_FAILURE);
	}
	token = strtok(p, ":");
	if (token == NULL)
		return (NULL);
	while (token != NULL)
	{
		buffer[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	buffer[i] = NULL;
	return (buffer);
}
