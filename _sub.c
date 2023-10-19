#include "monty.h"

/**
 * sub - sub the two top elements of the stack
 * @stack: The stack
 * @line_number: The current file line number
 * Return: Nothing or EXIT_FAILURE on failure
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int substraction = 0;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	substraction = glob.stack_n;
	pop(stack, line_number);
	substraction -= glob.stack_n;
	glob.stack_n = substraction * -1;
	_push(stack, line_number);
}
