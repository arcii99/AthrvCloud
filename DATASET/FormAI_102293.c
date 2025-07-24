//FormAI DATASET v1.0 Category: Bitwise operations ; Style: minimalist
#include <stdio.h>

int main() {

  // Bitwise OR example
  unsigned int a = 60; // 0011 1100
  unsigned int b = 13; // 0000 1101
  unsigned int c = a | b; // 0011 1101
  printf("Result of %u | %u = %u\n", a, b, c);

  // Bitwise AND example
  a = 60; // 0011 1100
  b = 13; // 0000 1101
  c = a & b; // 0000 1100
  printf("Result of %u & %u = %u\n", a, b, c);

  // Bitwise XOR example
  a = 60; // 0011 1100
  b = 13; // 0000 1101
  c = a ^ b; // 0011 0001
  printf("Result of %u ^ %u = %u\n", a, b, c);

  // Bitwise left shift example
  a = 60; // 0011 1100 before left shift
  c = a << 2; // 1111 0000 after left shift
  printf("Result of %u << 2 = %u\n", a, c);

  // Bitwise right shift example
  a = 60; // 0011 1100 before right shift
  c = a >> 2; // 0000 1111 after right shift
  printf("Result of %u >> 2 = %u\n", a, c);

  return 0;
}