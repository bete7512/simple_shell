#include "shell.h"

/**
 * free_all - frees all
 * @tokens: pointer to tokens of array
 * @path: pointer to path
 * @line: pointer to user input buffer
 * @fullpath: pointer to full path
 * @get:bool
 */
void free_all(char **tokens, char *path, char *line, char *fullpath, bool get)
{
	if (path == NULL)
		;
	else
		free(path);
	if(tokens == NULL)
		;
	else
		free(tokens);
	free(line);
	if (get == true)
		free(fullpath);
}

/**
 * free_dp - free double pointer
 * @array: double pointer
 * @length: length of double pointer
 */
void free_dp(char **array, unsigned int length)
{
	unsigned int i;

	i = 0;
	if (array == NULL)
		;
	else
	{
		while (i < length)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}
