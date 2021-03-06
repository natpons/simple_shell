#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;

/*string manipulation functions*/
char *_strdup(char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/*Free and malloc */
void free_grid(char **grid);

/*basic shell*/
void handle_sigint(int sig);
int print_env(void);
int built_in(char **av, char *buffer);
void create_child_pid(char **av, char **argv);
char *_getenv(char *name);
char **array_directory_path(char *path_folder[]);
char *verify_path(char **av);

#endif
