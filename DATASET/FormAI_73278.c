//FormAI DATASET v1.0 Category: Bitwise operations ; Style: calm
#include <stdio.h>

int main() {
  unsigned int a = 60;  // 0011 1100
  unsigned int b = 13;  // 0000 1101
  int result = 0;

  // Bitwise AND
  result = a & b;
  printf("a & b = %d\n", result);  // 0000001100

  // Bitwise OR
  result = a | b;
  printf("a | b = %d\n", result);  // 0011111101

  // Bitwise XOR
  result = a ^ b;
  printf("a ^ b = %d\n", result);  // 0011110001

  // Bitwise NOT
  result = ~a;
  printf("~a = %d\n", result);     // 1100000011

  // Bitwise left shift
  result = a << 2;
  printf("a << 2 = %d\n", result); // 11110000

  // Bitwise right shift
  result = a >> 2;
  printf("a >> 2 = %d\n", result); // 00001111

  return 0;
}