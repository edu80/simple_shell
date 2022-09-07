#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <stdbool.h>

typedef void (*sighandler_t)(int);

sighandler_t ignore;

/**
 * main - a simple shell
 * @ac: the number of arguments
 * @av: an array of strings taken in as arguments from the command line.
 * @env: an array of strings, the environmental variables.
 * Return: need to ammend.
 */
int main(int ac, char *av[], char *env[])
{
	char *buffer = NULL, *com[32], *com_path = NULL;
	ssize_t num_read = 1;
	size_t n = 0;
	int i, flag, path_value, com_count = 0, ret = 0, file_in_flag = 1;
	(void) ac;

	if (signal(SIGINT, SIG_IGN) != SIG_IGN)
		signal(SIGINT, ignore);
	while (num_read != EOF && file_in_flag)
	{
		if (isatty(STDIN_FILENO) && av[1] == NULL)
			print_prompt();
		if (av[1] != NULL)
		{
			buffer = _strdup(av[1]);
			file_in_flag = 0;
		}
		else
			num_read = getline(&buffer, &n, stdin);
		if (num_read == EOF)
		{
			free(buffer);
			return (ret);
		}
		com_count++;
		del_newline(buffer);
		if (buffer[0])
		{
			com[0] = _strtok(buffer, " ");
			for (i = 1, flag = 1; flag; i++)
			{
				com[i] = _strtok(NULL, " ");
				if (com[i] == NULL)
					flag = 0;
			}
			com_path = get_path(com[0], env, &path_value);
			ret = switcher(path_value, com_path, com,
					env, av, com_count, buffer, ret);
			free(com_path);
			if (av[1] != NULL)
				free(buffer);
		}
	}
	return (ret);
}

