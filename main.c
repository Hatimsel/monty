#include "monty.h"

/**
* main - the main func
* @argc: arguments count
* @argv: command line arguments
* Return: returns 0 on success
*/

int current_line = 1;

int main(int argc, char *argv[])
{
	stack_t *head = malloc(sizeof(stack_t));
	FILE *file;
	char cmd[100], buffer[MAX_LINE];
	bool keep_reading = true;
	int i = 0, j = 0, x = 0;
	/*char filename[FILENAME_SIZE];*/

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error opening file. \n");
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	do {
		fgets(buffer, MAX_LINE, file);
		if (feof(file))
		{
			keep_reading = false;
		}
		else
		{
		keep_reading = true;

	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		if (buffer[i] >= 48 && buffer[i] <= 57)
		{
			x = buffer[i] - 48;
		}
		else if (buffer[i] != ' ')
		{
			cmd[j] = buffer[i];
			j++;
		}
		i++;
	}
	if (strcmp(cmd, "push") == 0)
	{
		push(&head, x);
	}
	else if (strcmp(cmd, "pall") == 0)
	{
		pall(&head);
	}
	else if (strcmp(cmd, "pop") == 0)
	{
		pop(&head);
	}
	else if (strcmp(cmd, "add") == 0)
	{
		add(&head);
	}
	else if (strcmp(cmd, "swap") == 0)
	{
		swap(&head);
	}
	else if (strcmp(cmd, "pint") == 0)
	{
		pint(&head);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction\n", current_line);
		exit(EXIT_FAILURE);
	}
	}
	i = 0;
	j = 0;
	memset(cmd, 0, sizeof(cmd));
	current_line++;
	} while (keep_reading);
	fclose(file);
	return (0);
}
