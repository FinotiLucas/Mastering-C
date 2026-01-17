// Array Reversal Function
// ========================
//
// This program demonstrates a simple function to reverse an integer
// array in-place. The function `reverse_array` takes an array and its
// length, and reverses the elements without using extra space for
// another array.
//
// Author: Lucas Finoti
// Created: January 2026
// License: MIT (see LICENSE file)

#include <stdio.h>

void reverse_array(int arr[], int array_length) {
  int start = 0;
  int end = array_length - 1;

  while (start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    start++;
    end--;
  }
}

int main() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int array_length = sizeof(arr) / sizeof(arr[0]);

  printf("Array before reversal:\n");
  for (int i = 0; i < array_length; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n\n");

  reverse_array(arr, array_length);

  printf("Array after reversal:\n");
  for (int i = 0; i < array_length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
