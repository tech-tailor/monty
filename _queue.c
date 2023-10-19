#include "monty.h"

/**
 * queue - Changes the mode of push to a queue
 * @stack: The stack
 * @line_number: The current file line number
 * Return: Nothing
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	glob.stack_mode = PUSH_QUEUE;
}
