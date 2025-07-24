//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include <stdio.h>

int main() {
  int a = 548;    // Binary representation: 00000010 00110100
  int b = 365;    // Binary representation: 00000001 01101001
  int result;

  printf("C bit manipulation is so cool!\n");

  // Bitwise AND
  result = a & b; // 00000000 00100000
  printf("Result of a & b is %d\n", result);

  // Bitwise OR
  result = a | b; // 00000011 01111101
  printf("Result of a | b is %d\n", result);

  // Bitwise XOR
  result = a ^ b; // 00000011 01011101
  printf("Result of a ^ b is %d\n", result);

  // Bitwise NOT
  result = ~a;    // 11111101 11001011
  printf("Result of ~a is %d\n", result);

  // Left shift
  result = a << 3; // 00001000 11010000
  printf("Result of a << 3 is %d\n", result);

  // Right shift
  result = b >> 2; // 00000001 01011010
  printf("Result of b >> 2 is %d\n", result);

  printf("I never knew C could be so powerful!\n");

  return 0;
}