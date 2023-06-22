#include "monty.h"

void process_instruction(char *opcode, stack_t **stack,
								unsigned int line_number, instruction_t *instruction_table)
{
	int i = 0;

	while (instruction_table[i].opcode != NULL)
	{
		if (strcmp(opcode, instruction_table[i].opcode) == 0)
		{
			instruction_table[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
