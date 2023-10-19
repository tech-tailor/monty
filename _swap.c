#include "monty.h"

/**
 * swap - remove the top elemnt of the stack
 * @stack: The stack
 * @line_number: The current file line number
 * Return: Nothing or EXIT_FAILURE on failure
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int top, next;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	top = glob.stack_n;
	pop(stack, line_number);
	next = glob.stack_n;
	glob.stack_n = top;
	push(stack, line_number);
	glob.stack_n = next;
	_push(stack, line_number);
}
