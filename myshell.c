#include "shell.h"
/**
 * main - main loop of shell
 * Return: 0 on success
 */
int main(void)
{
	char *line, *path, *fullpath;
	char **tokens;
	int flag, builtin_status, child_status;

	/*signal(SIGINT, signal_to_handel);*/
	while (TRUE)
	{
		_putchar('$');
		_putchar(' ');
		signal(SIGINT, signal_to_handel);
		line = _getline(stdin);
tokens = parse(line);
if (tokens[0] == NULL)
continue;
builtin_status = bexecute(tokens);
		if (builtin_status == 0 || builtin_status == -1)
		{
			free(tokens);
			free(line);
		}
		if (builtin_status == 0)
			continue;
		if (builtin_status == -1)
			_exit(EXIT_SUCCESS);
		flag = 0; /* 0 if full_path is not malloc'd */
		path = _getenv("PATH");
		fullpath = _which(tokens[0], fullpath, path);
		if (fullpath == NULL)
			fullpath = tokens[0];
		else
			flag = 1; /* if fullpath was malloc'd, flag to free */
		child_status = forking(fullpath, tokens);
		if (child_status == -1)
			errors(2);
		free_all(tokens, path, line, fullpath, flag);
	}
	return (0);
}
