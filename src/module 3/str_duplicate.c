// String Duplication Function
// ===========================
//
// This module provides a manual implementation of a string duplication
// routine equivalent to the standard `strdup` function. It is intended
// for educational purposes, focusing on pointer discipline and heap
// memory ownership in C.
//
// The implementation demonstrates the separation between:
// - A fixed base pointer (memory ownership anchor)
// - A movable iterator pointer (used for traversal and copying)
//
// Concepts covered:
// - Manual heap allocation with malloc
// - Explicit error handling for allocation failure
// - Pointer iteration vs. pointer ownership
// - Null-terminated string copying
// - Proper memory release with free
//
// Ownership rules:
// - The returned pointer owns the allocated memory
// - The caller is responsible for checking NULL
// - The caller must free the returned pointer exactly once
//
// This code intentionally mirrors the behavior and contract of `strdup`
// without relying on the standard library implementation.
//
// Author: Lucas Finoti
// Created: January 2026
// License: MIT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str_duplicate(const char *str) {
  size_t len = strlen(str);
  char *cpy = malloc(len + 1);

  if (cpy == NULL) {
    return NULL;
  }

  char *p = cpy;

  while (*str != '\0') {
    *p = *str;
    p++;
    str++;
  }

  *p = '\0';

  return cpy;
}

int main(void) {
  char source[] = "Hello Word";

  char *target = str_duplicate(source);

  if (target == NULL) {
    return -1;
  }

  printf("%s\n", target);

  free(target);

  return 0;
}
