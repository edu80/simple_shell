#include "main.h"
#include <stdlib.h>

/**
 * ptr_array_print - prints an array of strings
 * @arr: an array of strings containing the variables
 * Return: the number of strings printed
 */
int ptr_array_print(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
	{
		print_string(arr[i]);
		_putchar('\n');
	}

	return (i - 1);
}

/**
 * exit_status - exits the program with specific exit status and frees mallocs.
 * @path: string containing the exit command
 * @commands: array of strings containing the rest of the command line
 * @caller: name of the executable program, aka the shell.
 * @buffer: the address of the memory allocated by getline.
 * @ret: the last return value before exit was entered.
 * @com_count: the command number in shell's history
 * Return: 2 if illegal number
 */
int exit_status(char *path, char **commands, char *caller, char *buffer,
		int ret, int com_count)
{
	int status = ret;

	if (commands[1] != NULL)
	{
		status = _atoi(commands[1]);
		if (status < 0)
		{
			perror_string(caller);
			perror_string(": ");
			perror_int(com_count);
			perror_string(": ");
			perror_string(commands[0]);
			perror_string(": Illegal number: ");
			perror_string(commands[1]);
			perror_string("\n");
			return (2);
		}
	}
	free(path);
	free(buffer);
	exit(status);
}

/**
 * echo_check - checks to see if user entered echo $? or $$.
 * @ret: the previous return value.
 * @command: the command from getline.
 * @flags: the array of commands from getline.
 * @env: the environment variables array
 * Return: 0 if successful.
 */
int echo_check(int ret, char *command, char **flags, char **env)
{
	char *temp = NULL, *var = NULL;
	int i;
	(void) command;

	if (_strcmp(flags[1], "$?"))
	{
		print_int(ret);
		_putchar('\n');
	}
	else if (_strcmp(flags[1], "$$"))
	{
		print_int(getpid());
		_putchar('\n');
	}
	else if (flags[1] != NULL && flags[1][0] == '$')
	{
		var = var_parse(flags[1]);
		temp = env_path_parse(env, var);
		if (temp != NULL)
			print_string(temp);
		_putchar('\n');
		free(var);
		free(temp);
	}
	else
	{
		for (i = 1; flags[i] != NULL; i++)
		{
			print_string(flags[i]);
			_putchar(' ');
		}
		_putchar('\n');
	}
	return (0);
}

/**
 * daddy - tells the user who their daddy is.
 * @av: the outside arguments coming in
 * Return: 0.
 */
int daddy(char **av)
{
	print_string(av[0]);
	print_string(" ==> ");
	print_string("JAIME IS YOUR DADDY\n");
	return (0);
}

