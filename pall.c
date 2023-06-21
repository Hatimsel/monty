#include "monty.h"

/**
 * pall - prints all the values on the stack
 *
 * @head: a double pointer to the head of a linked list
 */

void pall(stack_t **head)
{
	stack_t *curr = *head;

	if (*head == NULL)
	{
		return;
	}
	while (curr->next != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
