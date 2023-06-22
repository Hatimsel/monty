#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of arguments
 * @argv: Array of argument strings
 *
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	int current_line = 1;
	stack_t *stack = NULL;
	FILE *file;
	char buffer[MAX_LINE];
	char *opcode;
	instruction_t instruction_table[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"#", nop},
		{"sub", sub}, {"div", div_op}, {"mul", mul}, {"mod", mod},
		{"pchar", pchar}, {"pstr", pstr}, {NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, MAX_LINE, file) != NULL)
	{
		opcode = strtok(buffer, " \t\n");
		if (opcode != NULL)
		{
			process_instruction(opcode, &stack, current_line, instruction_table);
		}
		current_line++;
	}

	fclose(file);
	free(stack);
	return (0);
}
