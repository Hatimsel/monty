#include "monty.h"

/**
* main - the main func
* @argc: arguments count
* @argv: command line arguments
*/
int line_num = 1;

int main(int argc, char *argv[])
{
	stack_t **head = malloc(sizeof(stack_t*));
	FILE *fp;
	char line[MAX_LEN], cmd[20];
	int i = 0, j = 0, x = 0, k = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		printf("Error: malloc failed\n");
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, MAX_LEN, fp) != NULL)
	{
		while (line[i] != '\0' && line[i] != '\n')
		{
			while(line[k] != '\0' && line[k] != '\n')
			{
				if (line[k] >= 48 && line[k] <= 57)
				{
					x = x * 10 + (line[k] - '0');
				}
				else if (line[k] != ' ')
				{
					cmd[j] = line[k];
					j++;
				}
				k++;
			}
		i++;
		}
		cmd[j] = '\0';
		if (strcmp(cmd, "push") == 0)
		{
			push(head, x);
			printf("check\n");
		}
		else if (strcmp(cmd, "pall") == 0)
		{
			printf("cheer\n");
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
			/*printf("L%d: unknown instruction %s\n", line_num, cmd);*/
			fprintf(stderr, "L%d: unknown %s instruction %d\n", line_num, cmd, x);
			exit(EXIT_FAILURE);
		}
		line_num++;
	}
	fclose(fp);
	free(*head);
	free(head);
	return (0);
}
