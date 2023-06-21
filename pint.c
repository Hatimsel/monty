#include "monty.h"

/**
* pint - prints the value at the top of the stack
*
* @head: a double pointer to the first element of a linked list
* Return: void
*/

void pint(stack_t **head)
{
	stack_t *curr = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "%d: can't pint, stack empty\n", current_line);
		exit(EXIT_FAILURE);
	}
	curr = *head;

	printf("%d\n", curr->n);
}
