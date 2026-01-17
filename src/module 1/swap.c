// Custom Swap Function Implementation
// ===================================
//
// This program demonstrates a custom implementation of a swap function
// that exchanges the values of two integers using pointers.
// It highlights the use of pass-by-reference in C, modifying the
// original variables by working directly with their memory addresses.
//
// Features:
// - Swap function using pointers to exchange integer values
// - Pass-by-reference implementation with pointer dereferencing
//
// Author: Lucas Finoti
// Created: January 2026
// License: MIT (see LICENSE file)

#include <stdio.h>

void swap(int *a, int *b) {
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

int main(void) {
  int x = 8;
  int y = 16;

  printf("Before swap: x = %d, y = %d\n", x, y);

  swap(&x, &y);

  printf("After swap: x = %d, y = %d\n", x, y);

  return 0;
}
