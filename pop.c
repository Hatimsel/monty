#include "monty.h"

/**
 * pop - removes the top element of the stack
 *
 * @head: a double pointer to the first element on the stack
 * Return: returns a pointer to the head
 */

stack_t *pop(stack_t **head)
{
	stack_t *curr = *head;

	if (curr == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", current_line);
		exit(EXIT_FAILURE);
	}
	*head = curr->next;
	(*head)->prev = NULL;
	free(curr);
	return (*head);
}
