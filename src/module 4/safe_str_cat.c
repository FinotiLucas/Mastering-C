// Safe String Concatenation
// =================================
//
// This module implements a safe string concatenation function, similar to
// strlcat, which appends one string to another while respecting the total
// buffer size and always null-terminating the result.
//
// Concepts Demonstrated:
// - Pointer manipulation with anchors
// - Buffer size awareness and truncation
// - Null-termination
// - NULL checks
//
// Author: Lucas Finoti
// Created: January 2026
// License: MIT

#include <stdio.h>
#include <stdlib.h>

char *str_cat(char *__dest, const char *__src, size_t size) {
  if (__dest == NULL || __src == NULL) {
    return NULL;
  }

  char *cdest = __dest;
  size_t len_dest = 0, len_src = 0;

  while (__src[len_src] != '\0') {
    len_src++;
  }

  while (*cdest != '\0') {
    len_dest++;
    cdest++;
  }

  if (len_dest >= size) {
    __dest[size - 1] = '\0';
    return __dest;
  }

  size_t space = size - len_dest - 1;
  size_t to_copy = len_src < space ? len_src : space;

  for (size_t i = 0; i < to_copy; i++) {
    *cdest = __src[i];
    cdest++;
  }

  *cdest = '\0';

  return __dest;
}

int main(void) {
  char src[] = "World !";
  char buffer[9] = "Hello ";

  str_cat(buffer, src, sizeof(buffer));

  printf("buffer: %zu, string 1: %s, string 2: %s\n", sizeof(buffer), src,
         buffer);

  return 0;
}
