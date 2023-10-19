#include "monty.h"

/**
 * freestack- Free the memory
 * @stack: The stack
 */
void freestack(stack_t *stack)
{
	stack_t *node = stack;

	while (stack != NULL)
	{
		node = stack;
		stack = stack->next;
		free(node);
	}
}
