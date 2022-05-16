#include "shell.h"

/**
 * child - function for child process
 * @fullpath: full path of executable
 * @tokens: tokenized user input
 * Return: 0 on success
 */
int child(char *fullpath, char **tokens)
{
	pid_t c_pid;
	int status;
	int stat;
	char **envp = environ;

	c_pid = fork();
	if (c_pid == -1)
	{
		errors(1);
		exit(EXIT_FAILURE);
	}
	if (c_pid == 0)
	{
		stat = execve(fullpath, tokens, envp);
		if (stat == -1)
			return (-1);
		return (EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
		return (0);
	}

	return (0);
}
