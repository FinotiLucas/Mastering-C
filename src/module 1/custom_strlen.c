// Custom strlen implementation
// =============================
//
// A simple program demonstrating a custom implementation of strlen
// using pointer iteration, along with safe user input handling.
//
// This project is part of a personal study of the C language,
// focusing on pointers, memory representation, and idiomatic C code.
//
// Features:
// - Custom string length function (str_length)
// - Pointer-based string traversal
//
// Author: Lucas Finoti
// Created: January 2026
// License: MIT (see LICENSE file)


#include <stdio.h>
#include <string.h>

size_t str_length(const char *str) {
  size_t len = 0;

  for (const char *p = str; *p; p++) {
    len += 1;
  }

  return len;
}

int main(void) {
  char input[128];

  printf("Input a word: ");
  if (fgets(input, sizeof(input), stdin) == NULL) {
    return 1;
  }

  input[strcspn(input, "\n")] = '\0';

  size_t len = str_length(input);

  printf("The size of '%s' is: %zu\n", input, len);
  return 0;
}
