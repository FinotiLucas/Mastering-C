// Simple Calculator
// =================
//
// A minimal command-line calculator for basic arithmetic operations.
//
// Supported operations:
//   +    addition
//   -    subtraction
//   *    multiplication
//   /    division
//
// Usage example:
//   5.2 + 3.8
//   -4 * 2.5
//
// Author: Lucas Finoti
// Created: Janeiro 2026
// License: MIT (see LICENSE file)
//

#include <ctype.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *skip_spaces(const char *p) {
  while (*p && isspace((unsigned char)*p))
    p++;
  return p;
}

int parse_expression(const char *input, double *out_a, double *out_b,
                     char *out_op) {
  const char *p = input;
  char *end;

  p = skip_spaces(p);

  *out_a = strtod(p, &end);
  if (end == p)
    return 1;
  p = end;

  p = skip_spaces(p);

  if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
    *out_op = *p++;
  } else {
    return 2;
  }

  p = skip_spaces(p);

  *out_b = strtod(p, &end);
  if (end == p)
    return 3;
  p = end;

  p = skip_spaces(p);

  if (*p != '\0' && *p != '\n')
    return 4;

  return 0;
}

int main(void) {
  char input[256];
  double a = 0.0, b = 0.0;
  char op = '\0';

  printf("Advanced Calculator (ex: -3.5 + 7.2)\n");
  printf("Enter expression: ");

  if (fgets(input, sizeof(input), stdin) == NULL) {
    printf("Input error\n");
    return 1;
  }

  input[strcspn(input, "\n")] = '\0';

  int result = parse_expression(input, &a, &b, &op);

  if (result != 0) {
    switch (result) {
    case 1:
      printf("The first number is invalid\n");
      break;
    case 2:
      printf("The operator is invalid (+ - * /)\n");
      break;
    case 3:
      printf("The second number is invalid\n");
      break;
    case 4:
      printf("Extra characters at the end\n");
      break;
    default:
      printf("Unknown error\n");
    }
    return 1;
  }

  double calc_result = 0.0;
  switch (op) {
  case '+':
    calc_result = a + b;
    break;
  case '-':
    calc_result = a - b;
    break;
  case '*':
    calc_result = a * b;
    break;
  case '/':
    if (fabs(b) < DBL_EPSILON) {
      printf("Division by zero\n");
      return 1;
    }
    calc_result = a / b;
    break;
  }

  printf("%.2f %c %.2f = %.2f\n", a, op, b, calc_result);

  return 0;
}
