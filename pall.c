#include "main.h"

/**
 * pall - prints all the values on the stack
 *
 * @head: a double pointer to the head of a linked list
 */

void pall(stack_t **head) {
  if (*head == NULL) {
    return;
  }

  while (*head != NULL) {
    printf("%d\n", (*head)->n);
    *head = (*head)->next;
  }
}
