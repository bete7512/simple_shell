#include "shell.h"
/**
 * errors - prints error
 * @error: error number associated with perror statement
 * Return: void
 */
void errors(char *error)
{
	write(STDERR_FILENO, error, _strlen(error));
	perror(" ");
}
