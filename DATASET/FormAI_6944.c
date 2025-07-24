//FormAI DATASET v1.0 Category: Bitwise operations ; Style: innovative
#include <stdio.h>

int main() {
  unsigned int a = 60; // Binary representation: 0011 1100
  unsigned int b = 13; // Binary representation: 0000 1101
  unsigned int result;

  result = a & b; // Bitwise AND (0011 1100 & 0000 1101), binary result: 0000 1000
  printf("a & b = %u\n", result);

  result = a | b; // Bitwise OR (0011 1100 | 0000 1101), binary result: 0011 1101
  printf("a | b = %u\n", result);

  result = a ^ b; // Bitwise XOR (0011 1100 ^ 0000 1101), binary result: 0011 0001
  printf("a ^ b = %u\n", result);

  result = ~a; // Bitwise NOT (~0011 1100), binary result: 1100 0011 (2's complement)
  printf("~a = %u\n", result);

  result = a << 2; // Left shift (0011 1100 << 2), binary result: 1111 0000
  printf("a << 2 = %u\n", result);

  result = a >> 1; // Right shift (0011 1100 >> 1), binary result: 0001 1110
  printf("a >> 1 = %u\n", result);

  return 0;
}