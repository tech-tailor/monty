#include "monty.h"

/**
 * pchar - prints the value at the top of the stack, followed by a new line
 * @stack: The stack
 * @line_number: The current file line number
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 32 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
