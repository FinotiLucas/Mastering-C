// Linked List Persistence Module (Stream Parsing Pattern)
// =======================================================
//
// This module provides a robust implementation of a Singly Linked List with
// capabilities to reconstruct the data structure from flat text files.
//
//
// Author: Lucas Finoti
// Created: January 2026
// License: MIT

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

void parse_line_to_list(const char *line, struct Node **head_ref) {
  char *endptr;
  const char *p = line;

  while (*p != '\0' && *p != '\n') {
    long val = strtol(p, &endptr, 10);

    if (p == endptr) {
      p++;
      continue;
    }

    push(head_ref, (int)val);
    p = endptr;
  }
}

int main(void) {
  FILE *fptr = fopen("./data/module_6_ex_1.txt", "r");
  if (fptr == NULL) {
    perror("Erro ao abrir arquivo");
    return 1;
  }

  struct Node *head = NULL;
  char buff[1024];

  while (fgets(buff, sizeof(buff), fptr)) {
    parse_line_to_list(buff, &head);
  }

  fclose(fptr);

  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");

  free_list(head);
  return 0;
}
