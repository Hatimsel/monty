#include "monty.h"
#include <ctype.h>
/**
 * push - adds a new element to the stack
 * @stack: Double pointer to the stack
 * @line_number: The Line number of the opcode
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *value = strtok(NULL, " \t\n");
	stack_t *new_node = NULL;
	int num;

	if (value != NULL)
	{
	new_node = malloc(sizeof(stack_t));
	num = atoi(value);
	if (*value < 48 || *value > 57)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}
