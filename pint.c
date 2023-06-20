#include "main.h"

/**
* pint - prints the value at the top of the stack
*
* @head: a double pointer to the first element of a linked list
* Return: returns the top value of a node
*/

int pint(stack_t **head)
{
	stack_t *curr = *head;
	int top = 0;

	if (*head == NULL)
	{
		printf("%d: can't pint, stack empty", line_num);
		exit(EXIT_FAILURE);
	}
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	top = curr->n;
	return (top);
}
