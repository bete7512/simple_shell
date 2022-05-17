#include "shell.h"

/**
 * _strcmp - compares two strings
 * @str: string compared with
 * @holder: string to compare against
 * @length: length of name
 * Return: 1 or -1
 */
int _strcmp(char *str, char *holder, unsigned int length)
{
	unsigned int counter;
	unsigned int i;

	counter = _strlen(holder);
	if (counter != length)
		return (-1);

	i = 0;
	while (str[i] != '\0' && holder[i] != '\0')
	{
		if (str[i] != holder[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strncmp - compares two strings
 * @str: string compared with
 * @holder: variable to compare against
 * @count: length to compare up to
 * Return: 1 or -1
 */
int _strncmp(char *str, char *holder, unsigned int count)
{
	unsigned int i;

	i = 0;
	while (i < count)
	{
		if (str[i] != holder[i])
			return (-1);
		i++;
	}
	return (1);
}

/**
 * *_strcpy - copies string
 * @dest: string holder
 * @src: string source
 * Return: modified string returned
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int j = _strlen(src);

	for (i = 0; i <= j; i++)
		dest[i] = src[i];

	return (dest);
}
/**
 * _strlen - length of string counter
 * @str: string
 * Return: length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
/**
 *signal_to_handel - accepts ctrl + c and responces
 *@sig:signal to listen
 *
 *
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		_putchar('\n');
		_putchar('$');
		_putchar(' ');
	}
}

