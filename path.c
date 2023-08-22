#include "main.h"
/**
 * construct_buffer - Construct the buffer path.
 * @path: Path to the command
 * @args: Command arguments
 *Return: Buffer containing the full path to the command
 */
char *construct_buffer(char *path, char *args)
{
	char buffer[1024];

	strcpy(buffer, path);
	strcat(buffer, "/");
	strcat(buffer, args);
	return (strdup(buffer));
}
/**
 * print_env - print the enviroment
 * Return: pointer to the enviroment
*/
void print_env(void)
{
	char **enviroment;

	enviroment = environ;
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
		exit(1);
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
		free(buffer);
		exit(1);
	}

	token = strtok(p, ":");
	while (token != NULL)
	{
		buffer[i] = strdup(token);
		token = strtok(NULL, ":");
		i++;
	}
	buffer[i] = NULL;
	for (int j = 0; j < i; j++)
	{
    	free(buffer[j]);
	}
	free(buffer);
	return (buffer);
}
