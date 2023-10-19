#include "monty.h"

/**
 * stack - Changes the mode of push to a stack
 * @stack: The stack
 * @line_number: The current file line number
 * Return: Nothing
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	glob.stack_mode = PUSH_STACK;
}
