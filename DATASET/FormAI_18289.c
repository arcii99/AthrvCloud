//FormAI DATASET v1.0 Category: Bitwise operations ; Style: satisfied
#include<stdio.h>

int main() {
  unsigned int a, b, result;

  a = 0b10101010; // binary value of 170
  b = 0b11110000; // binary value of 240

  // Bitwise AND
  result = a & b;
  printf("a & b = %u\n", result);

  // Bitwise OR
  result = a | b;
  printf("a | b = %u\n", result);

  // Bitwise XOR
  result = a ^ b;
  printf("a ^ b = %u\n", result);

  // Bitwise NOT
  result = ~a;
  printf("~a = %u\n", result);

  // Left Shift
  result = a << 2;
  printf("a << 2 = %u\n", result);

  // Right Shift
  result = b >> 3;
  printf("b >> 3 = %u\n", result);

  return 0;
}