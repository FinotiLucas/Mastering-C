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
