#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * free_if_needed - frees a pointer if not null
 * @p: pointer
 */
void free_if_needed(char *p)
{
	if (p)
		free(p);
}

/**
 * free_array - frees the strings in a pointer array
 * @arr: the array of string pointers
 */
void free_array(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

