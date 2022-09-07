#include "main.h"

#include <stdio.h>

/**
 * perror_permission - prints the permission denied error message.
 * @file: the name of the file
 * @caller: the name of the executable file that tried to make the call.
 * @com_count: the number of commands in current shell session
 * Return: 0
 */
int perror_permission(char *file, char *caller, int com_count)
{
	perror_string(caller);
	perror_string(": ");
	perror_int(com_count);
	perror_string(": ");
	perror_string(file);
	perror_string(": Permission denied\n");

	return (126);
}

/**
 * perror_file - prints the no such file or directory error message
 * @file: the name of the file
 * @caller: the name of the executable file that made the call
 * @com_count: the number of commands in current shell session
 * Return: 0
 */
int perror_file(char *file, char *caller, int com_count)
{
	perror_string(caller);
	perror_string(": ");
	perror_int(com_count);
	perror_string(": ");
	perror_string(file);
	perror_string(": not found\n");
	return (127);
}

/**
 * perror_command - prints the command not found error message
 * @caller: the name of the shell's executable
 * @command: the command
 * @com_count: the number of commands in current shell session
 * Return: 0
 */
int perror_command(char *caller, char *command, int com_count)
{
	(void) command;

	perror_string(caller);
	perror_string(": ");
	perror_int(com_count);
	perror_string(": ");
	perror_string(command);
	perror_string(": not found\n");

	return (127);
}

