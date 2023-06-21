#include "main.h"

/**
 * pop - removes the top element of the stack
 *
 * @head: a double pointer to the first element on the stack
 */

stack_t *pop(stack_t **head) {
  stack_t *curr = *head;

  if (curr == NULL) {
    write(1, "L<line_number>: can't pop an empty stack", 40);
    exit(EXIT_FAILURE);
  }
  *head = curr->next;
  (*head)->prev = NULL;
  free(curr);
  return (*head);
}
