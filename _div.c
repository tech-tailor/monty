#include "monty.h"

/**
 * _div - divides the second top element of the stack by the top element.
 * @stack: The stack
 * @line_number: The current file line number
 * Return: Nothing or EXIT_FAILURE on failure
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int top, next;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	top = glob.stack_n;
	pop(stack, line_number);
	next = glob.stack_n;
	glob.stack_n = next / top;
	_push(stack, line_number);
}
