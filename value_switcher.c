#include "main.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * switcher - directs traffic
 * @val: integer that tells me where to send other arguments
 * @com_path: string that contains either a absolute path or other command.
 * @flags: the rest of what was accepted from getline
 * @env: a copy of the environment variables
 * @av: a copy of the argument taken in from the command line at launch
 * @com_count: the command number in current shell session.
 * @buffer: the address of the memory allocated by getline.
 * @ret: the most recent return value
 * Return: 0 if successful
 */
int switcher(int val, char *com_path, char **flags, char **env, char **av,
		int com_count, char *buffer, int ret)
{
	switch (val)
	{
	case 0:
		perror_command(av[0], com_path, com_count);
		return (127);
	case 1:
		perror_permission(com_path, av[0], com_count);
		return (126);
	case 2:
		perror_command(av[0], com_path, com_count);
		return (127);
	case 3:
		return (executer(com_path, flags));
	case 4:
		ptr_array_print(env);
		return (0);
	case 5:
		return (exit_status(com_path, flags, av[0], buffer,
					ret, com_count));
	case 6:
		return (echo_check(ret, com_path, flags, env));
	case 7:
		return (daddy(av));
	}
	return (0);
 
}
/**
 * executer - forks current process to run execve
 * @command: the absolute path of an executable
 * @flags: an array of strings, including extra input for the command
 * Return: 0 if successful, -1 if not
 */
int executer(char *command, char **flags)
{
	pid_t kid_pid;
	int status;

	kid_pid = fork();
	if (kid_pid == -1)
		return (-1);
	if (kid_pid == 0)
	{
		execve(command, flags, NULL);
		exit(187);
	}
	else
		wait(&status);

	return (0);
}

