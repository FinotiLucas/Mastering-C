/*
 * Safe Input Utility
 * =================
 *
 * This module demonstrates a safer way to read strings from stdin in C.
 * It wraps the classic fgets() function with additional safeguards and
 * contract rules to prevent common issues with C input handling.
 *
 * Author: Lucas Finoti
 * Created: January 2026
 * License: MIT
 */


#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool safe_input(char *buf, size_t max_len) {
  if (buf == NULL || max_len == 0) {
    return false;
  }

  if (fgets(buf, (int)max_len, stdin) == NULL) {
    return false;
  }

  size_t len = strcspn(buf, "\n");
  if (buf[len] == '\n') {
    buf[len] = '\0';
    return true;
  } else {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return false;
  }
}

int main(void) {
  char input[5];
  bool ok = safe_input(input, sizeof(input));

  printf("INPUT: %s\n", input);
  printf("Was the input fully captured? %s\n", ok ? "Yes" : "No");

  return 0;
}
