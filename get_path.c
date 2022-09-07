#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


/**
 * path_combo - combines 2 strings, with a / in between them.
 * @dir: first part.
 * @comm: part 2.
 * Return: malloc'd string.
 */
char *path_combo(char *dir, char *comm)
{
	char *cat;
	int i, j;

	cat = malloc(sizeof(char) * (2 + _strlen(dir) + _strlen(comm)));
	if (cat == NULL)
		exit(33);
	for (i = 0; dir[i]; i++)
		cat[i] = dir[i];
	cat[i] = '/';
	for (i++, j = 0; comm[j]; i++, j++)
		cat[i] = comm[j];
	cat[i] = '\0';
	return (cat);
}

/**
 * env_path_parse - parses the path line from the environment variables.
 * @env: the array of strings with all environment variables.
 * @var: the name of the variable to return
 * Return: a mallocd string containing the environment variable line. Or null.
 */
char *env_path_parse(char **env, char *var)
{
	int i, j, flag;
	char *path_line = NULL;

	for (i = 0; env[i]; i++)
	{
		for (j = 0, flag = 1; flag && j < _strlen(var); j++)
		{
			if (env[i][j] != var[j])
				flag = 0;
		}
		if (flag)
		{
			for (j = 0; env[i][j] != '\0'; j++)
				;
			path_line = malloc(sizeof(char) * (j + 1));
			if (path_line == NULL)
			{
				return (NULL);
			}
			for (j = 0; env[i][j]; j++)
				path_line[j] = env[i][j + _strlen(var)];
			path_line[j] = '\0';
		}
	}
	return (path_line);
}
/**
 * get_path - returns absolute path to a command.
 * @comm: the command string
 * @env: the environment variables, in an array of strings.
 * @ret_value: int pointer to be changed depending on conditions.
 * Return: the absolute path to the command, if it exists.
 * If no file exists, return bad command.
 * Description:	ret_value will return...
 * 1 if path exists and permission is ok
 * 0 if path exists and no permission allowed
 * -1 if no path exists (command not found)
 */
char *get_path(char *comm, char **env, int *ret_value)
{
	int i = 0, flag, acc_ret, cur_dir_index;
	char *pathlist[32], *paths_in, *cat_temp, delim = ':';

	*ret_value = built_ins_abs_paths_check(comm);
	if (*ret_value == 2)
	{
		paths_in = env_path_parse(env, "PATH=");
		cur_dir_index = colon_check(paths_in);
		if (cur_dir_index > -1)
			pathlist[cur_dir_index] = "./";
		if (i == cur_dir_index)
			i++;
		pathlist[i] = _strtok(paths_in, &delim);
		for (i++, flag = 1; flag; i++)
		{
			if (i == cur_dir_index)
				i++;
			pathlist[i] = _strtok(NULL, &delim);
			if (pathlist[i] == NULL)
				flag = 0;
		}
		for (i = 0; pathlist[i]; i++)
		{
			cat_temp = path_combo(pathlist[i], comm);
			acc_ret = access(cat_temp, F_OK);
			if (acc_ret == 0)
			{
				*ret_value = 1;
				acc_ret = access(cat_temp, X_OK);
				if (acc_ret == 0)
					*ret_value = 3;
				free(paths_in);
				return (cat_temp);
			}
			free(cat_temp);
		}
	}
	if (*ret_value == 2)
		free(paths_in);
	return (_strdup(comm));
}

/**
 * built_ins_abs_paths_check - checks the initial command
 * @com: the command to check
 * Return: See lines below.
 * 0 if is path, but no file found.
 * 1 if file found, but no permission.
 * 2 if command not found (search path).
 * 3 if found and permission is granted.
 * 4 if command matches 'env'.
 */
int built_ins_abs_paths_check(char *com)
{
	int ret_value = 2;

	if (com[0] == '/' || com[0] == '.')
	{
		if (access(com, F_OK) == 0)
		{
			ret_value = 1;
			if (access(com, X_OK) == 0)
				ret_value = 3;
		}
	}
	else
	{
		if (_strcmp("env", com))
			return (4);
		if (_strcmp("exit", com))
			return (5);
		if (_strcmp("echo", com))
			return (6);
		if (_strcmp("daddy?", com))
			return (7);


	}
	return (ret_value);
}

/**
 * colon_check - checks a string for leading, appending, or back to back ':'.
 * @s: the string to be checked.
 * Return: -1 if no leading, ending, or double colons are present.
 * Otherwise, returns the corresponding index where the colon appears.
 */
int colon_check(char *s)
{
	int i = 0, count = 0;

	if (s[0] == ':')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == ':')
		{
			count++;
			i++;
			if (s[i] == ':' || s[i] == '\0')
				return (count);
		}
		i++;
	}

	return (-1);
}

