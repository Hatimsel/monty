#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: a double pointer to the head of a linked list
 * @line_number: The Line number of the opcode
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *tmp = *stack;

	(void)line_number; /* Unused parameter */

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	*stack = tmp;
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number; /* Unused parameter */

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int num = 0;

	(void)line_number; /* Unused parameter */

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	(*stack)->n = tmp->next->n;
	tmp->next->n = num;
	/*
	* (*stack)->n = (*stack)->next->n;
	* (*stack)->next->n = temp;
	*/
}

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
