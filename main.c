#include "main.h"

/**
* main - the main func
* @argc: arguments count
* @argv: command line arguments
*/
int line_num = 0;

int main(int argc, char *argv[])
{
	stack_t **head = malloc(sizeof(stack_t));
	FILE *fp;
	char line[MAX_LEN], cmd[20];
	int i = 0, j = 0, x = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		printf("Error: malloc failed\n");
		write(2, "Error: malloc failed", 20);
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		write(2, "Error: Can't open file <file>\n", 31);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, MAX_LEN, fp) != NULL)
	{
		while (line[i] != '\0' && line[i] != '\n')
		{
			if (line[i] >= 48 && line[i] <= 57)
			{
				x = (int)line[i];
			}
			else if (line[i] != ' ')
			{
				cmd[j] = line[i];
				j++;
			}
			i++;
		}
		if (strcmp(cmd, "push") == 0)
		{
			push(head, x);
		}
		else if (strcmp(cmd, "pall") == 0)
		{
			pall(head);
		}
		else if (strcmp(cmd, "pop") == 0)
		{
			pop(head);
		}
		else if (strcmp(cmd, "add") == 0)
		{
			add(head);
		}
		else if (strcmp(cmd, "swap") == 0)
		{
			swap(head);
		}
		else if (strcmp(cmd, "pint") == 0)
		{
			pint(head);
		}
		else
		{
			printf("L%d: unknown instruction %s\n", line_num, cmd);
			exit(EXIT_FAILURE);
		}
		line_num++;
	}
	fclose(fp);
	free(*head);
	free(head);
	return (0);
}
