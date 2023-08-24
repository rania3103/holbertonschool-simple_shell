#include "main.h"
/**
 * tokenize - split line into tokens
 * @line: line
 * Return: pointer
*/
char **tokenize(char *line)
{
	char **tokens = NULL;
	char *token;
	int i;

	tokens = (char **) malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
	{
		perror("error in memory allocation");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \n\t");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \n\t");
	}
	tokens[i] = NULL;
	return (tokens);
}
