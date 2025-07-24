//FormAI DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
  int a = 10;
  int b = 5;
  int c = 0;

  // Addition
  c = a + b;
  printf("Addition: %d\n", c);

  // Subtraction
  c = a - b;
  printf("Subtraction: %d\n", c);

  // Multiplication
  c = a * b;
  printf("Multiplication: %d\n", c);

  // Division - integer division
  c = a / b;
  printf("Integer Division: %d\n", c);

  // Division - floating point division
  double d = (double)a / (double)b;
  printf("Floating Point Division: %f\n", d);

  // Modulus - remainder
  c = a % b;
  printf("Modulus - Remainder: %d\n", c);

  // Increment - post-increment
  c = a++;
  printf("Post-increment: %d\n", c);

  // Increment - pre-increment
  c = ++b;
  printf("Pre-increment: %d\n", c);

  // Decrement - post-decrement
  c = a--;
  printf("Post-decrement: %d\n", c);

  // Decrement - pre-decrement
  c = --b;
  printf("Pre-decrement: %d\n", c);

  return 0;
}