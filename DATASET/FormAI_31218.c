//FormAI DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>

int main() {
  int a = 10;
  int b = 7;

  // Bitwise AND operation
  int result_and = a & b;
  printf("a & b = %d\n", result_and);

  // Bitwise OR operation
  int result_or = a | b;
  printf("a | b = %d\n", result_or);

  // Bitwise XOR operation
  int result_xor = a ^ b;
  printf("a ^ b = %d\n", result_xor);

  // Bitwise left shift operation
  int result_left_shift = a << 2;
  printf("a << 2 = %d\n", result_left_shift);

  // Bitwise right shift operation
  int result_right_shift = a >> 2;
  printf("a >> 2 = %d\n", result_right_shift);

  // Bitwise complement operation
  int result_complement = ~a;
  printf("~a = %d\n", result_complement);

  return 0;
}