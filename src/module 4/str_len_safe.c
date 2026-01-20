// Safe String Length Utility
// ==========================

// This module demonstrates a safer alternative to the classic strlen().
// Instead of relying solely on a null-terminated string, it introduces
// an explicit length parameter as part of the function contract.
//
// Concepts covered:
// - C strings vs raw buffers
// - Sentinel-based termination ('\0')
// - Undefined Behavior caused by missing terminators
// - Contract design for safer APIs
// - Pointer traversal with explicit bounds
//
// Author: Lucas Finoti
// Created: January 2026
// License: MIT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t str_len_safe(const char *str, size_t max_len) {
  if (str == NULL) {
    return 0;
  }

  size_t i = 0;
  for (const char *p = str; i < max_len && *p != '\0'; p++, i++) {
  }

  return i;
}

int main(void) {
  char str[] = "Hello World";
  size_t o_len = strlen(str);
  size_t c_len = str_len_safe(str, sizeof(str));

  printf("str: %s\n", str);
  printf("strlen: %zu\n", o_len);
  printf("str_len: %zu\n", c_len);

  return 0;
}
