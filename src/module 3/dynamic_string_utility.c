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

#include <stddef.h>
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

int str_append(DynamicString *ds, const char *extra_str) {
  if (ds == NULL || extra_str == NULL) {
    return 0;
  }

  size_t extra_len = strlen(extra_str);
  size_t new_len = ds->length + extra_len;

  char *temp = realloc(ds->data, new_len + 1);

  if (temp == NULL) {
    return 0;
  }

  ds->data = temp;

  memcpy(ds->data + ds->length, extra_str, extra_len);

  ds->length = new_len;
  ds->data[ds->length] = '\0';

  return 1;
}

DynamicString *str_clone(const DynamicString *src) {
  if (src == NULL) {
    return NULL;
  }
  return str_create(src->data);
}

void str_free(DynamicString *ds) {
  if (ds == NULL) {
    return;
  }
  free(ds->data);
  free(ds);
}

int main(void) {
  DynamicString *s = str_create("Hello");
  DynamicString *clone = str_clone(s);

  if (s) {
    printf("\n\n%s (size: %zu)\n", s->data, s->length);

    str_append(s, " World");

    printf("\n%s (size: %zu)\n", s->data, s->length);

    printf("\n%s (size: %zu)\n\n", clone->data, clone->length);

    str_free(s);
    str_free(clone);
  }

  return 0;
}
