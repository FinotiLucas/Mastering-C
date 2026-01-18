// Print Array Element Addresses
// =============================
//
// This program demonstrates how arrays are laid out in memory in C.
// It prints both the value and the memory address of each element
// in an integer array.
//
// The function `print_addresses` receives a pointer to the first
// element of the array and its length, illustrating how arrays
// decay to pointers when passed to functions.
//
//
// Author: Lucas Finoti
// Created: January 2026
// License: MIT (see LICENSE file)


#include <stdio.h>

void print_addresses(int *arr, size_t len) {
  for (size_t i = 0; i < len; i++) {
    printf("arr[%zu] = %d, address = %p\n", i, arr[i], &arr[i]);
  }
}

int main(void) {
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  size_t len = sizeof(arr) / sizeof(arr[0]);

  print_addresses(arr, len);

  return 0;
}
