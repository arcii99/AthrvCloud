//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shape shifting
#include <stdio.h>

int main() {
  int a = 10, b = 5;
  int result;

  // AND operation
  printf("Before AND operation: a = %d, b = %d\n", a, b);
  result = a & b;
  printf("After AND operation: result = %d (binary: %d)\n", result, result);

  // OR operation
  printf("Before OR operation: a = %d, b = %d\n", a, b);
  result = a | b;
  printf("After OR operation: result = %d (binary: %d)\n", result, result);

  // XOR operation
  printf("Before XOR operation: a = %d, b = %d\n", a, b);
  result = a ^ b;
  printf("After XOR operation: result = %d (binary: %d)\n", result, result);

  // NOT operation
  printf("Before NOT operation: a = %d\n", a);
  result = ~a;
  printf("After NOT operation: result = %d (binary: %d)\n", result, result);

  // LEFT SHIFT operation
  printf("Before LEFT SHIFT operation: a = %d\n", a);
  result = a << 2;
  printf("After LEFT SHIFT operation: result = %d (binary: %d)\n", result, result);

  // RIGHT SHIFT operation
  printf("Before RIGHT SHIFT operation: a = %d\n", a);
  result = a >> 2;
  printf("After RIGHT SHIFT operation: result = %d (binary: %d)\n", result, result);

  return 0;
}