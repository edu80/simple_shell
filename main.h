#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


void del_newline(char *s);
char *get_path(char *comm, char **env, int *ret_value);
char *env_path_parse(char **env, char *var);
int _strlen(char *s);
char *path_combo(char *dir, char *comm);
void print_prompt(void);
int print_string(char *s);
int _putchar(char c);
void free_array(char **arr);
char *_strdup(char *s);
int executer(char *command, char **flags);
int switcher(int val, char *com_path, char **flags, char **env,
		char **av, int, char *buffer, int ret);
int _strcmp(char *sea, char *bass);
int ptr_array_print(char **arr);
int perror_permission(char *file, char *caller, int com_count);
int perror_command(char *caller, char *command, int com_count);
int perror_file(char *file, char *caller, int com_count);
int perror_string(char *s);
int built_ins_abs_paths_check(char *com);
int exit_status(char *path, char **commands, char *caller, char *, int, int);
int _atoi(char *s);
char *_strtok(char *s, const char *delim);
int colon_check(char *s);
int perror_int(int n);
int print_int(int n);
int echo_check(int ret, char *command, char **flags, char **env);
int daddy(char **av);
char *var_parse(char *var);

#endif

