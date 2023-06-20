#include "main.h"

/**
* pop - removes the top element of the stack
*
* @head: a double pointer to the first element on the stack
*/

void pop(stack_t **head)
{
	stack_t *curr = *head;

	if (curr == NULL)
	{
		write(1, "L<line_number>: can't pop an empty stack", 40);
		exit(EXIT_FAILURE);
	}
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	free(curr);
}
