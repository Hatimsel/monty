#include "monty.h"

/**
* pstr - prints the string starting at the top of the stack
* @stack: a double pointer to the last element in a stack
* @line_number: keeps tracking lines
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int x = 0;

	(void)line_number;
	if (curr == NULL)
	{
		putchar('\n');
		return;
	}
	while (curr != NULL)
	{
		x = curr->n;
		if (x < 32 || x > 126)
		{
			break;
		}
		putchar(x);
		curr = curr->next;
	}
	putchar('\n');
}
