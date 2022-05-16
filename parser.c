#include "shell.h"

/**
 * stringtotoken - tokenizes string
 * @str: user input
 * Return: pointer to array of tokens
 */
char **parse(char *str)
{
	char **tokens;
	char *token;
	unsigned int i;

	tokens = malloc(sizeof(char) * 1024);
	if (tokens == NULL)
	{
		errors(ERR_MALLOC);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, "\n\t\r ");

	i = 0;
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n\t\r ");
		i++;
	}

	tokens[i] = NULL;

	return (tokens);
}
