#include "main.h"
/**
 * signal_handler - Handles Ctrl + C
 *
 */
void signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n%s", "simpleshell$ ");
	}
}
