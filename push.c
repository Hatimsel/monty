#include "main.h"

/**
* push- adds a new element to the stack
*
* @head: a double pointer to a linked list
* @a: the element to be added
*/

void push(stack_t **head, int a)
{
	stack_t *new_node = malloc(sizeof(stack_t)), *curr = *head;

	if (new_node == NULL)
	{
		printf("Error: malloc failed");	
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = a;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (curr == NULL)
	{
		curr = new_node;
	}
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new_node;
	new_node->prev = curr;
}
