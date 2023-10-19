#include "monty.h"

/**
 * rotl - remove the top elemnt of the stack
 * @stack: The stack
 * @line_number: The current file line number
 * Return: Nothing or EXIT_FAILURE on failure
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tail, *new_node;
	int value;

	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;

	pop(stack, line_number);
	value = glob.stack_n;

	tail = *stack;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed");
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	while (tail->next)
	{
		tail = tail->next;
	}

	new_node->n = value;
	new_node->next = NULL;
	new_node->prev = tail;
	tail->next = new_node;
}
