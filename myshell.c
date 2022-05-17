#include "shell.h"
/**
 * main - main loop of shell
 * Return: 0 on success
 */
int main(void)
{
	char *line, *path, *fullpath;
	char **tokens;
	bool get = false;
	int status, fork_status;

	signal(SIGINT, signal_to_handel);
	while (1)
	{
		_putchar('$');
		_putchar(' ');
		/*signal(SIGINT, signal_to_handel);*/
		line = _getline(stdin);
		tokens = parse(line);
		if (tokens[0] == NULL)
			continue;
		status = bexecute(tokens);
		if (status == 0 || status == -1)
		{
			free(tokens);
			free(line);
		}
		if (status == 0)
			continue;
		if (status == -1)
			_exit(EXIT_SUCCESS);
		path = _getenv("PATH");
		fullpath = selector(tokens[0], fullpath, path);
		if (fullpath == NULL)
			fullpath = tokens[0];
		else
			get = true;
		fork_status = forking(fullpath, tokens);
		if (fork_status == -1)
		{
			errors("error");
			return (-1);
		}
		free_all(tokens, path, line, fullpath, get);
	}
	return (0);
}
