#include "main.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * _strtok - extracts tokens from strings.
 * @s: the string to be tokenized
 * @delim: the char used to determine tokens
 * Return: pointer to the first char in the token.
 */
char *_strtok(char *s, const char *delim)
{
	char *token;
	static int tok_s;
	static char *buftok;

	if (s != NULL)
	{
		buftok = s;
		tok_s = 0;
	}

	while (buftok[tok_s] == *delim && buftok[tok_s] != '\0')
		tok_s++;
	if (buftok[tok_s] != '\0')
		token = &buftok[tok_s];
	else
		return (NULL);
	while (buftok[tok_s] != '\0')
	{
		if (buftok[tok_s] == *delim)
		{
			buftok[tok_s] = '\0';
			tok_s++;
			return (token);
		}
		tok_s++;
	}
	return (token);
}

/**
 * perror_int - prints an integer to std error.
 * @n: the integer to be printed.
 * Return: 0 if successful.
 */
int perror_int(int n)
{
	char num;

	if (n / 10 > 0)
		perror_int(n / 10);
	num = n % 10 + '0';
	write(STDERR_FILENO, &num, 1);

	return (0);
}

/**
 * print_int - prints an integer to std out.
 * @n: the integer to be printed.
 * Return: 0 if successful.
 */
int print_int(int n)
{
	char num;

	if (n / 10 > 0)
		print_int(n / 10);
	num = n % 10 + '0';
	write(STDOUT_FILENO, &num, 1);

	return (0);
}

