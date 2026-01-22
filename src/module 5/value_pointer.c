// Struct Memory Semantics & Performance Benchmark
// ===============================================
//
// This module explores the performance implications of "Pass-by-Value" vs.
// "Pass-by-Pointer" in C. It benchmarks the overhead of stack frame
// replication for large data structures.
//
// Performance Analysis Goal:
// --------------------------
// Quantify the "Tipping Point" where the cost of dereferencing a pointer
// becomes cheaper than the cost of copying the struct data.
//
// Author: Lucas Finoti
// Created: January 2026
// License: MIT

#include <stdio.h>
#include <time.h>

#define ITERATIONS 1000000
#define ARRAY_SIZE 1000

typedef struct {
  double data[ARRAY_SIZE];
  int id;
} BigData;

__attribute__((noinline)) double test_by_value(BigData b) { return b.data[0]; }

__attribute__((noinline)) double test_by_pointer(const BigData *b) {
  return b->data[0];
}

int main(void) {
  BigData b1 = {{1.0}, 42};

  clock_t start, end;
  double time_value, time_pointer;
  volatile double dummy = 0;

  printf("Starting benchmark with %d iterations...\n", ITERATIONS);
  printf("Struct size: %zu bytes\n\n", sizeof(BigData));

  start = clock();
  for (int i = 0; i < ITERATIONS; i++) {
    dummy += test_by_value(b1);
  }

  end = clock();
  time_value = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Pass by VALUE:   %.6f seconds\n", time_value);

  start = clock();
  for (int i = 0; i < ITERATIONS; i++) {
    dummy += test_by_pointer(&b1);
  }

  end = clock();
  time_pointer = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Pass by POINTER: %.6f seconds\n", time_pointer);

  if (time_pointer > 0) {
    printf("\nPassing by pointer was %.1fx faster!\n",
           time_value / time_pointer);
  }

  return 0;
}
