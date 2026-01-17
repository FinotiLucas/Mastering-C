// Command-Line Arguments Printer
// ===============================
//
// This program prints all the command-line arguments passed to it.
// It demonstrates the use of the `argc` and `argv` parameters in C,
// which are used to access the arguments provided when the program is run.
//
// Author: Lucas Finoti
// Created: January 2026
// License: MIT (see LICENSE file)

#include <stdio.h>
int main(int argc, char *argv[]) {
  printf("You have entered %d arguments:\n", argc);

  for (int i = 0; i < argc; i++) {
    printf("Argument %d: %s\n", i + 1, argv[i]);
  }

  return 0;
}
