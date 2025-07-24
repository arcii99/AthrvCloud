//FormAI DATASET v1.0 Category: Bitwise operations ; Style: intelligent
#include <stdio.h>

int main() {
  unsigned int a = 60; // 0011 1100
  unsigned int b = 13; // 0000 1101
  int c = -4;          // 1111 1100 (two's complement of 4)

  // Bitwise AND operator
  printf("a & b = %u\n", a & b); // Output: 12 (0000 1100)

  // Bitwise OR operator
  printf("a | b = %u\n", a | b); // Output: 61 (0011 1101)

  // Bitwise XOR operator
  printf("a ^ b = %u\n", a ^ b); // Output: 49 (0011 0001)

  // Bitwise NOT operator
  printf("~a = %u\n", ~a); // Output: 4294967235 (two's complement of 60)

  // Left shift operator
  printf("a << 2 = %u\n", a << 2); // Output: 240 (1111 0000)

  // Right shift operator
  printf("a >> 2 = %u\n", a >> 2); // Output: 15 (0000 1111)

  // Two's complement operator
  printf("~c + 1 = %d\n", ~c + 1); // Output: 4

  return 0;
}