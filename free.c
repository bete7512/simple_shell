#include "shell.h"

/**
 * free_all - frees all
 * @tokens: pointer to tokens of array
 * @path: pointer to path 
 * @line: pointer to user input buffer
 * @fullpath: pointer to full path
 * @flag: flag
 * Return: void
 */
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag)
{
	free(path);
	free(tokens);
	free(line);
	if (flag == 1)
		free(fullpath);
}

/**
 * free_dp - free double pointer
 * @array: double
 * @length: length of double pointer
 * Return: void
 */
void free_dp(char **array, unsigned int length)
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
