//FormAI DATASET v1.0 Category: Bitwise operations ; Style: rigorous
#include <stdio.h>

int main() {
  // Initialize two integers with random values
  int x = 123;
  int y = 456;

  // Print the initial values
  printf("Initial values:\n");
  printf("x = %d\n", x);
  printf("y = %d\n", y);

  // Perform bitwise AND operation
  int result_and = x & y;

  // Perform bitwise OR operation
  int result_or = x | y;

  // Perform bitwise XOR operation
  int result_xor = x ^ y;

  // Print the results
  printf("\nResults:\n");
  printf("x & y = %d\n", result_and);
  printf("x | y = %d\n", result_or);
  printf("x ^ y = %d\n", result_xor);

  return 0;
}