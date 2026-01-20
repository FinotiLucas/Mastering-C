// Memory Copy Utility
// ===================
//
// This module implements a manual version of the standard `memcpy` function,
// intended for educational purposes and pointer/memory management studies.
//
// The function copies a specified number of bytes from a source memory region
// to a destination memory region. It demonstrates key concepts such as:
//
// Concepts:
// - Manual memory handling without knowledge of the underlying type
// - Use of anchors (fixed pointers) vs movable markers for traversal
// - Safe byte-by-byte copying using `char *` casting
// - Explicit control of copy size via a length parameter
//
// Ownership rules:
// - The destination memory must be valid and large enough to receive `n` bytes
// - The function does not check for overlapping memory regions
// - The caller is responsible for ensuring that memory safety is maintained
//
// Author: Lucas Finoti
// Created: January 2026
// License: MIT

#include <stdio.h>
#include <string.h>

void *memmory_copy(void *restrict __dest, void *restrict __src, size_t __n) {
  char *csrc = (char *)__src;
  char *cdest = (char *)__dest;

  for (size_t i = 0; i < __n; i++) {
    cdest[i] = csrc[i];
  }

  return __dest;
}

int main(void) {
  char str1[] = "Hello World";
  char str2[12] = "";

  memmory_copy(str2, str1, sizeof(str1));

  printf("str2 after memmory_copy: ");
  printf("%s\n", str2);

  return 0;
}
