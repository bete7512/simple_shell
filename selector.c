#include "shell.h"
/**
 * selector - directory searcher
 * @command: to search for
 * @fullpath: full path of command to execute
 * @path: full PATH variable
 * Return: pointer to full_path
 */
char *selector(char *command, char *fullpath, char *path)
{
	unsigned int cmd_length, path_length, original;
	char *path_copy, *token;

	cmd_length = _strlen(command);
	original = _strlen(path);
	path_copy = malloc(sizeof(char) * original + 1);
	if (path_copy == NULL)
	{
		errors(ERR_MALLOC);
		return (NULL);
	}
	_strcpy(path_copy, path);
	token = strtok(path_copy, ":");
	if (token == NULL)
		token = strtok(NULL, ":");
	while (token != NULL)
	{
		path_length = _strlen(token);
		fullpath = malloc(sizeof(char) * (path_length + cmd_length) + 2);
		if (fullpath == NULL)
		{
			errors(ERR_MALLOC);
			return (NULL);
		}
		_strcpy(fullpath, token);
		fullpath[path_length] = '/';
		_strcpy(fullpath + path_length + 1, command);
		fullpath[path_length + cmd_length + 1] = '\0';
		if (access(fullpath, X_OK) != 0)
		{
			free(fullpath);
			fullpath = NULL;
			token = strtok(NULL, ":");
		}
		else
			break;
	}
	free(path_copy);
	return (fullpath);
}
