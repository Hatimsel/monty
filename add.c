#include "monty.h"

/**
* add - adds the top two elements of the stack
*
* @head: a double pointer to the head of a linked list
*/

void add(stack_t **head)
{
	stack_t *curr = *head;

	if (curr == NULL || curr->next == NULL)
	{
		write(1, "L<line_number>: can\'t add, stack too short\n", 44);
		write(2, "L<line_number>: can\'t add, stack too short\n", 44);
		exit(EXIT_FAILURE);
	}
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->prev->n += curr->n;
	curr->prev->next = NULL;
	free(curr);
}
