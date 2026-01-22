// Singly Linked List Module (Dynamic Memory Pattern)
// =================================================
//
// This module implements a linear singly linked list with dynamic
// node allocation. It demonstrates the fundamental pointer-chasing
// technique required for custom data structures in C.
//
//
// Author: Lucas Finoti
// Created: January 2026

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void push(struct Node **header_ref, int new_data) {
  struct Node *new_node = malloc(sizeof(*new_node));
  if (new_node == NULL) {
    return;
  }

  new_node->data = new_data;
  new_node->next = *header_ref;

  *header_ref = new_node;

  return;
}

void delete_node(struct Node **head_ref, int key) {
  if (*head_ref == NULL) {
    return;
  }

  struct Node *current = *head_ref;
  struct Node *prev = NULL;

  while (current != NULL) {
    if (current->data == key) {

      if (prev == NULL) {
        *head_ref = current->next;
      } else {
        prev->next = current->next;
      }

      free(current);
      return;
    }
    prev = current;
    current = current->next;
  }
}

void free_list(struct Node *head) {
  if (head == NULL) {
    return;
  }
  struct Node *current = head;
  struct Node *next = NULL;

  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
}

int main(void) {
  int data[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  size_t n = sizeof(data) / sizeof(data[0]);

  struct Node *head = NULL;

  for (size_t i = 0; i < n; i++) {
    push(&head, data[i]);
  }

  delete_node(&head, 90);
  delete_node(&head, 80);
  delete_node(&head, 10);

  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");

  free_list(head);

  head = NULL;

  return 0;
}
