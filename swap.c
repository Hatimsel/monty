#include "main.h"

/**
 * swap - swaps the top two elements of the stack
 *
 * @head: a double pointer to the head of a linked list
 */

stack_t *swap(stack_t **head) {
  int tmp;
  stack_t *curr = *head;

  if (curr == NULL || curr->next == NULL) {
    write(1, "L<line_number>: can\'t swap, stack too short\n", 45);
    write(2, "L<line_number>: can\'t swap, stack too short\n", 45);
    exit(EXIT_FAILURE);
  }
  tmp = curr->n;
  curr->n = curr->prev->n;
  curr->prev->n = tmp;

  return (*head);
}
