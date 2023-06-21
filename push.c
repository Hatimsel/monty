#include "monty.h"

/**
 * push- adds a new element to the stack
 *
 * @head: a double pointer to a linked list
 * @a: the element to be added
 * Return: returns a pointer to the head
 */

stack_t *push(stack_t **head, int a)
{
	stack_t *new_node = malloc(sizeof(stack_t)), *curr = *head;

	if (new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (*head == NULL)
	{
		new_node->n = a;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	if (*head != NULL)
	{
		new_node->n = a;
		new_node->next = curr;
		curr->prev = new_node;
		new_node->prev = NULL;
	}
	*head = new_node;
	return (*head);
}
