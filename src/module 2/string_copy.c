// String Copy Function
// ====================
//
// This program demonstrates a simple implementation of the `strcpy`
// function. The function `string_copy` copies all characters from
// the source string to the destination, including the terminating
// null byte.
//
// Author: Lucas Finoti
// Created: January 2026
// License: MIT (see LICENSE file)


#include <stdio.h>

char *string_copy(char *restrict origin, char *restrict dest) {
  char *d = dest;

  while (*origin != '\0') {
    *d = *origin;
    origin++;
    d++;
  }

  *d = '\0';

  return dest;
}

int main(void) {
  char str[] = "Hello World";
  size_t len = sizeof(str);
  char cpy[len];

  string_copy(str, cpy);

  printf("%s\n", cpy);
  for (size_t i = 0; i < len; i++) {
    printf("address str = %p, address cpy = %p\n", (void *)&str[i],
           (void *)&cpy[i]);
  }

  return 0;
}
