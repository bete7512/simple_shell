#include "shell.h"

/**
 * _getline - puts input from user into buffer line
 * @fp: buffer for user input
 * Return: buffer with user input
 */
char *_getline(FILE *fp)
{
	char *cmd;
	ssize_t status;
	size_t len;

	cmd = NULL;
	len = 0;
	status = getline(&cmd, &len, fp);
	if (status == -1)
	{
		free(cmd);
		exit(EXIT_SUCCESS);
	}

	return (cmd);
}
