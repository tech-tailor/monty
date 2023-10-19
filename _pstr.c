#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: The stack
 * @line_number: The current file line number
 * Return: Nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void) line_number;
	node = *stack;
	while (node)
	{
		if (node->n == 0)
			break;
		if (node->n > 127 || node->n < 0)
			break;
		printf("%c", node->n);
		node = node->next;
	}
	putchar('\n');
}
