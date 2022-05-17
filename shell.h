#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
typedef enum {false, true} bool;
#define ERR_MALLOC "memoray cannot allocate  space\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"

extern char **environ;
/**
 * struct builtin - linked list of builtins
 * @name: name of builtin
 * @p: pointer to function
 *
 * Description: struct for builtin functions.
**/
typedef struct _builtin{
	char *name;
	int (*p)(void);
}_builtin;
int _putchar(char c);
void signal_to_handel(int sig);
char *_getline(FILE *fp);
char **parse(char *str);
char *selector(char *command, char *fullpath, char *path);
int forking(char *fullpath, char **tokens);
void errors(char *error);
void _puts(char *str);
int _strlen(char *s);
int _strcmp(char *str, char *holder, unsigned int length);
int _strncmp(char *str, char *holder, unsigned int length);
char *_strcpy(char *dest, char *src);
int env_display(void);
int exiter(void);
int bexecute(char **tokens);
int builtin_counter(_builtin arr[]);
char *_getenv(const char *str);
char **copier(char **copy, unsigned int environ_count);
void free_all(char **tokens, char *path, char *line, char *fullpath,bool get);
void free_dp(char **array, unsigned int length);
#endif
