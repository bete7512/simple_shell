#include "shell.h"
/**
 * _getenv - gets an environment variable
 * @name: environment variable to get
 * Return: pointer to environment variable or NULL if there is no match
 */
char *_getenv(const char *name)
{
char **copy, *variable, *value, *path, *single =  '\0';
int compare;
unsigned int path_length, environ_length = 0, length, i = 0;
	while (environ[environ_length] != NULL)
		environ_length++;
	copy = NULL;
	copy = copier(copy, environ_length);
	length = _strlen((char *)name);
	while (copy[i] != NULL)
	{
		variable = copy[i];
		compare = _strncmp((char *)name, variable, length);
		if (compare == 1)
		{
			value = strtok(variable, "=");
			value = strtok(NULL, "\n ");
			if (value == single)
			{
				errors(ERR_PATH);
				exit(EXIT_FAILURE);
			}
			path_length = _strlen(value);
			path = malloc(sizeof(char) * path_length + 1);
			if (path == NULL)
			{
				errors(ERR_MALLOC);
				return (NULL);
			}
			path = _strcpy(path, value);
			free_dp(copy, environ_length);
			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
 * copier - copies environment variable
 * @copy: pointer to copy of environment variable
 * @environ_length: length of environment variable
 * Return: double pointer to copy of environment variable
 */
char **copier(char **copy, unsigned int environ_length)
{
	char *variable;
	unsigned int variable_length;
	unsigned int i;

	copy = malloc(sizeof(char **) * (environ_length));
	if (copy == NULL)
	{
		errors(ERR_MALLOC);
		return (NULL);
	}

	i = 0;
	while (i < environ_length)
	{
		variable = environ[i];
		variable_length = _strlen(variable);

		copy[i] = malloc(sizeof(char) * variable_length + 1);
		if (copy[i] == NULL)
		{
			errors(ERR_MALLOC);
			return (NULL);
		}
		_strcpy(copy[i], environ[i]);
		i++;
	}

	return (copy);
}
