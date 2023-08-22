#ifndef simpleshell
#define simpleshell
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
extern char **environ;
char *readline();
char **tokenize(char *line);
void execute(char **args);
void print_env(void);
char *get_path();
char **tokenize_path(char *p);
char *construct_buffer(char *path, char *args);
#endif
