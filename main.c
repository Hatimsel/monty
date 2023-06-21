#include "main.h"
#include <stdbool.h>
#include <stdio.h>

#define FILENAME_SIZE 1024
#define MAX_LINE 2048

int main(int argc, char *argv[]) {
  stack_t *head = malloc(sizeof(stack_t));
  FILE *file;
  char cmd[100];
  bool keep_reading = true;
  int current_line = 0;

  int i = 0, j = 0, x = 0;

  // char filename[FILENAME_SIZE];
  char buffer[MAX_LINE];

  int read_line = 0;

  file = fopen(argv[1], "r");

  if (file == NULL) {
    printf("Error opening file. \n");
    return 1;
  }

  do {
    fgets(buffer, MAX_LINE, file);
    if (feof(file)) {
      keep_reading = false;
    } else {
      keep_reading = true;

      while (buffer[i] != '\0' && buffer[i] != '\n') {
        if (buffer[i] >= 48 && buffer[i] <= 57) {
          x = buffer[i] - 48;
        } else if (buffer[i] != ' ') {
          cmd[j] = buffer[i];
          j++;
        }
        i++;
      }
      if (strcmp(cmd, "push") == 0) {
        push(&head, x);
        // printf("%s", cmd);
        // printf("%d\n", x);
      } else if (strcmp(cmd, "pall") == 0) {
        pall(&head);
      } else if (strcmp(cmd, "pop") == 0) {
        pop(&head);
      }
      /*else if (strcmp(cmd, "add") == 0) {
        add(&head);
      } else if (strcmp(cmd, "swap") == 0) {
        swap(&head);
      }*/

      // printf("%s", cmd);
      // printf("%d\n", x);
    }

    i = 0;
    j = 0;
    current_line++;

  } while (keep_reading);

  fclose(file);

  return (0);
}
