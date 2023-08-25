#include "main.h"
/**
 *free_tokens - frees memory
 *@tokens:tokens
*/
void free_tokens(char **tokens)
{
	int i;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
