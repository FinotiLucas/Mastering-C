// Dynamic String Utility
// =================================
//
// This module implements a basic dynamic string container. It demonstrates
// manual heap memory management, including nested allocations (struct and data)
// and explicit ownership rules as part of the C study plan.
//
// Concepts:
// - Manual Heap Allocation (malloc)
// - Memory Ownership and Lifecycle Management
// - Buffer Safety and Null-termination
//
// Author: Lucas Finoti
// Created: January 2026
// License: MIT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *data;
  size_t length;
} DynamicString;

DynamicString *str_create(const char *initial_text) {

  DynamicString *ds = malloc(sizeof(DynamicString));
  if (ds == NULL) {
    return NULL;
  }

  ds->length = strlen(initial_text);

  ds->data = (char *)malloc(ds->length + 1);
  if (ds->data == NULL) {
    free(ds);
    return NULL;
  }

  memcpy(ds->data, initial_text, ds->length);
  ds->data[ds->length] = '\0';

  return ds;
}

void str_free(DynamicString *ds) {
  if (ds == NULL) {
    return;
  }

  free(ds->data);
  free(ds);
}

int main(void) {
  DynamicString *s = str_create("Hello from C");

  if (s) {
    printf("\n\n%s (size: %zu)\n\n", s->data, s->length);
    str_free(s);
  }

  return 0;
}
