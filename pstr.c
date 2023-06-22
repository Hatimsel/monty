#include "monty.h"

/**
* pstr - prints the string starting at the top of the stack
* @stack: a double pointer to the last element in a stack
* @line_number: keeps tracking lines
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	int x = 0;

	(void)line_number;
	if (*stack == NULL)
	{
		putchar('\n');
	}
	while (*stack != NULL)
	{
		x = (*stack)->n;
		if (x < 32 || x > 126 || x == 0)
		{
			break;
		}
		putchar(x);
		*stack = (*stack)->next;
	}
	putchar('\n');
}
