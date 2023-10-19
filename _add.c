#include "monty.h"

/**
 * add - adds the two top elements of the stack
 * @stack: The stack
 * @line_number: The current file line number
 * Return: Nothing or EXIT_FAILURE on failure
 */
void add(stack_t **stack, unsigned int line_number)
{
	int addition = 0;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	addition += glob.stack_n;
	pop(stack, line_number);
	addition += glob.stack_n;
	glob.stack_n = addition;
	_push(stack, line_number);
}
