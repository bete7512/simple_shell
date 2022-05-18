#include "shell.h"

/**
 * parse - tokenizes string
 * @str: user input
 * Return: pointer to array of tokens
 */
char **parse(char *str)
{
	char **parsed;
	char *token;
	unsigned int i;

	parsed = malloc(sizeof(char) * BUFFER);
	if (parsed == NULL)
	{
		errors(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, "\n ");

	i = 0;
	while (token != NULL)
	{
		parsed[i] = token;
		token = strtok(NULL, "\n ");
		i++;
	}

	parsed[i] = NULL;

	return (parsed);
}
