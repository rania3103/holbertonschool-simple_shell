#include "main.h"
/**
 * tokenize - split line into tokens
 * @line: line
 * Return: pointer
*/
char **tokenize(char *line)
{
	char **tokens;
	char *token;
	int i, j;

	i = 0;
	tokens = (char **)malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
	{
		perror("error in memery allocation");
		exit(1);
	}
	token = strtok(line, " \n\t\r\a");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
		{
			perror("error in memory allocation");
			exit(1);
		}
		i++;
		token = strtok(NULL, " \n\t\r\a");
	}
	tokens[i] = NULL;
	for (j = 0; j < i; j++)
	{
    	free(tokens[j]);
	}
	free(tokens);
	return (tokens);
}
