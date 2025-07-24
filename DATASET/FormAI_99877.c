//FormAI DATASET v1.0 Category: Bitwise operations ; Style: minimalist
#include <stdio.h>

int main() {
  unsigned int a = 60;   // binary: 0011 1100
  unsigned int b = 13;   // binary: 0000 1101
  int result;

  // Bitwise AND
  result = a & b;
  printf("a & b = %d\n", result); // binary: 0000 1100

  // Bitwise OR
  result = a | b;
  printf("a | b = %d\n", result); // binary: 0011 1101

  // Bitwise XOR
  result = a ^ b;
  printf("a ^ b = %d\n", result); // binary: 0011 0001

  // Bitwise NOT
  result = ~a;
  printf("~a = %d\n", result); // binary: 1100 0011

  // Left shift
  result = a << 2;
  printf("a << 2 = %d\n", result); // binary: 1111 0000

  // Right shift
  result = a >> 2;
  printf("a >> 2 = %d\n", result); // binary: 0000 1111

  return 0;
}