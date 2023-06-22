#include "monty.h"

/**
* _free - frees memory
* @stack: a pointer to the head of the stack
*/

void _free(stack_t *stack)
{
	stack_t *tmp;

	if (stack == NULL)
	{
		return;
	}
	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
