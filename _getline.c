#include "main.h"
#include <stdlib.h>

/**
 * del_newline - overwrites a newline char before the null char in a
 * string.
 * @s: the string to be modified.
 */
void del_newline(char *s)
{
	int i, nonspace = 0;

	if (s[0] == '#')
		s[0] = '\0';
	for (i = 0; s[i]; i++)
	{
		if (s[i] == '\t')
			s[i] = ' ';
		if (s[i] == '#' && i > 0 && s[i - 1] == ' ')
			s[i] = '\0';
		if (s[i] == '\n' && s[i + 1] == '\0')
			s[i] = '\0';
	}
	for (i = 0; s[i]; i++)
	{
		if (s[i] != ' ')
			nonspace++;
	}
	if (nonspace == 0)
		s[0] = '\0';
}

/**
 * _strdup - copies and allocates space for a string
 * @s: the string to be copied.
 * Return: pointer to malloc'd space containing the copy of the string.
 */
char *_strdup(char *s)
{
	int i = 0;
	char *dup;

	dup = malloc(sizeof(char) * (_strlen(s) + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; s[i]; i++)
		dup[i] = s[i];
	dup[i] = '\0';

	return (dup);
}

/**
 * _strcmp - compares two strings
 * @sea: string one
 * @bass: string two
 * Return: 1 if they are the same. 0 if they are not.
 */
int _strcmp(char *sea, char *bass)
{
	int i = 0;

	if (!sea || !bass)
		return (0);
	while (sea[i] && bass[i])
	{
		if (sea[i] != bass[i])
			return (0);
		i++;
	}
	if (sea[i] == '\0' && bass[i] == '\0')
		return (1);

	return (0);
}

/**
 * _strlen - returns the length of a string
 * @s: the string
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}

/**
 * var_parse - parses a "$var" into "var="
 * @var: the string to be parsed.
 * Return: malloc'd string. Caller must free.
 */
char *var_parse(char *var)
{
	int i, j;
	char *parsed_str;

	parsed_str = malloc(sizeof(char) * (_strlen(var) + 1));
	if (parsed_str == NULL)
		return (NULL);
	for (i = 1, j = 0; var[i]; i++, j++)
	{
		parsed_str[j] = var[i];
	}
	parsed_str[j] = '=';
	parsed_str[j + 1] = '\0';

	return (parsed_str);
}

