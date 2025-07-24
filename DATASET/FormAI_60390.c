//FormAI DATASET v1.0 Category: Bitwise operations ; Style: automated
#include <stdio.h>

int main() {
  unsigned int a = 60; // 0011 1100 in binary
  unsigned int b = 13; // 0000 1101 in binary
  int c;

  // Bitwise AND
  c = a & b;      // 0000 1100
  printf("AND: %d\n", c);

  // Bitwise OR
  c = a | b;      // 0011 1101
  printf("OR: %d\n", c);

  // Bitwise XOR
  c = a ^ b;      // 0011 0001
  printf("XOR: %d\n", c);

  // Bitwise NOT
  c = ~a;         // 1100 0011
  printf("NOT: %d\n", c);

  // Left shift
  c = a << 2;     // 1111 0000
  printf("Left shift: %d\n", c);

  // Right shift
  c = a >> 2;     // 0000 1111
  printf("Right shift: %d\n", c);

  return 0;
}