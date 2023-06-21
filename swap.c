#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 *
 * @head: a double pointer to the head of a linked list
 * Return: returns a pointer to the head
 */

stack_t *swap(stack_t **head)
{
	int tmp;
	stack_t *curr = *head;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can\'t swap, stack too short\n", current_line);
		exit(EXIT_FAILURE);
	}
	tmp = curr->n;
	curr->n = curr->next->n;
	curr->next->n = tmp;

	return (*head);
}
