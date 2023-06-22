#include "monty.h"

/**
* rotl -  rotates the stack to the top.
* @stack: a double pointer to the last element in a stack
* @line_number: keeps tracking lines
*/

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack, *tmp;

	(void)line_number;
	if (curr == NULL || curr->next == NULL)
	{
		return;
	}
	tmp = *stack;
	*stack = curr->next;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = tmp;
	tmp->next = NULL;
}
