#include "monty.h"

/**
 * pop - remove the top elemnt of the stack
 * @stack: The stack
 * @line_number: The current file line number
 * Return: Nothing or EXIT_FAILURE on failure
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;

	glob.stack_n = node->n;
	free(node);
}
