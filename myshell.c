#include "shell.h"
/**
 * main - main loop of shell
 * Return: 0 on success
 */
int main(__attribute__((unused))int argc,__attribute__((unused))char **argv)
{
	char *cmd, *path, *fullpath;
	char **tokens;
	bool get = false;
	int bstatus, fork_status;

	signal(SIGINT, signal_to_handel);
	while (1)
	{
		_putchar('$');
		_putchar(' ');
		/*signal(SIGINT, signal_to_handel);*/
		cmd = _getline(stdin);
		tokens = parse(cmd);
		if (tokens[0] == NULL)
			continue;
		bstatus = bexecute(tokens);
		if (bstatus == 0 || bstatus == -1)
		{
			free(tokens);
			free(cmd);
		}
		if (bstatus == 0)
			continue;
		if (bstatus == -1)
			return (0);
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
		free_all(tokens, path, cmd, fullpath, get);
	}
	return (0);
}
