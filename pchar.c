#include "monty.h"

/**
* pchar - prints the char at the top of the stack
* @stack: a double pointer to the last element in a stack
* @line_number: keeps tracking lines
*/

void pchar(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int x;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	x = (*stack)->n;
	if (x < 32 || x > 126)
	{
		printf("L%d: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(x);
}
