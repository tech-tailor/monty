#include "monty.h"

/**
 * set_number - Set the number of line
 * @number: The number
 * Return: Nothing
 */
void set_number(char *number)
{
	int glob_n;

	if (strlen(number) > 0)
	{
		glob_n = atoi(number);
		printf("%d\n", glob_n);
	}
}
