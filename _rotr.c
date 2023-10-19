#include "monty.h"

/**
 * rotr - remove the top elemnt of the stack
 * @stack: The stack
 * @line_number: The current file line number
 * Return: Nothing or EXIT_FAILURE on failure
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tail, *prev;

	(void) line_number;
	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;

	tail = *stack;
	prev = *stack;
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	prev->next = NULL;
	tail->prev = NULL;
	tail->next = *stack;
	(*stack)->prev = tail;
	*stack = tail;
}
