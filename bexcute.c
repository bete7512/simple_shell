#include "shell.h"
/**
**bexecute - built in functions
**@tokens: arguments to be searched in builtin
**Return: tokens
**/
int bexecute(char **tokens)
{
	int status;
	unsigned int length;
	unsigned int i;
	unsigned int counter;

	_builtin builtin[] = {
		{"exit", exiter},
		{"env", env_display},
		{NULL, NULL}
	};
	if (tokens[0] == NULL)
		return (1);

	length = _strlen(tokens[0]);
	counter = builtin_counter(builtin);
	for (i = 0; i < counter; i++)
	{
		if (_strcmp(tokens[0], builtin[i].cmd, length) == 0)
		{
			status = (builtin[i].fun)();
			return (status);
		}
	}
	return (1);
}

/**
 *builtin_counter - counts builtin commands from a given array
 *@arr:array
 *Return:integer
 *
 */
int builtin_counter(_builtin arr[])
{
	unsigned int count = 0;

	while (arr[count].cmd != NULL)
	{
		count++;
	}
	return (count);
}
/**
**exiter - exits the shell of the programmm
**Return: void
**/
int exiter(void)
{
	return (-1);
}


/**
**env_display - prints enviromental viriables
**Return: void
**/
int env_display(void)
{
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
	return (0);
}

