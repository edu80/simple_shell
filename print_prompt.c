#include "main.h"

/**
 * _putchar - prints a character to std out.
 * @c: the character to be printed.
 * Return: 1 if successful, 0 if not.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}


/**
 * print_prompt - prints the command line prompt.
 */
void print_prompt(void)
{
	char prompt[12] = "$ ";
	int i;

	for (i = 0; prompt[i]; i++)
		write(STDOUT_FILENO, &prompt[i], 1);
}

/**
 * print_string - prints a string ended with \0.
 * @s: the string to be printed.
 * Return: the number of characters printed.
 */
int print_string(char *s)
{
	int i, j;

	if (s == NULL)
		return (0);

	for (i = 0; s[i]; i++)
		j += write(STDOUT_FILENO, &s[i], 1);

	return (j);
}

/**
  * _atoi - converts a string to an integer
  * @s: string
  * Return: integer
  */
int _atoi(char *s)
{
	int i, end;
	int sum = 0;

	if (s == NULL)
		return (0);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
	}
	end = _strlen(s);
	for (i = 0; i < end; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			sum = s[i] - '0';
			while (s[i + 1] >= '0' && s[i + 1] <= '9')
			{
				if (sum > 0)
					sum = sum * 10 + s[i + 1] - '0';
				else if (sum == 0)
					sum = sum + s[i + 1] - '0';
				i++;
			}
			i = end;
		}
	}
	return (sum);

}


/**
 * perror_string - prints a string to the standard error.
 * @s: the string to be printed.
 * Return: the number of char printed.
 */
int perror_string(char *s)
{
	int i, j;

	if (s == NULL)
		return (0);

	for (i = 0; s[i]; i++)
		j = j+ write(STDERR_FILENO, &s[i], 1);

	return (j);
}

