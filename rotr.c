#include "monty.h"

/**
* rotr -  rotates the stack to the bottom.
* @stack: a double pointer to the last element in a stack
* @line_number: keeps tracking lines
*/

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack, *tmp;

	(void)line_number;
	if (curr == NULL || curr->next == NULL)
	{
		return;
	}
	tmp = *stack;
	while (curr->next != NULL)
	{
		tmp = curr;
		curr = curr->next;
	}
	curr->next = *stack;
	*stack = curr;
	tmp->next = NULL;
}
