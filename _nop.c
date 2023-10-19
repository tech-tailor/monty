#include "monty.h"

/**
 * nop - remove the top elemnt of the stack
 * @stack: The stack
 * @line_number: The current file line number
 * Return: Nothing or EXIT_FAILURE on failure
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (*stack == NULL)
		return;
}
