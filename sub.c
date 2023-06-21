#include "monty.h"

/**
 * sub - subs the top two elements of the stack
 *
 * @head: a double pointer to the head of a linked list
 * Return: returns a pointer to the head
 */

stack_t *sub(stack_t **head)
{
	stack_t *curr = *head;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can\'t add, stack too short\n", current_line);
		exit(EXIT_FAILURE);
	}
	curr->next->n -= curr->n;
	*head = curr->next;
	free(curr);

	return (*head);
}
