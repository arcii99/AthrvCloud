//FormAI DATASET v1.0 Category: Bitwise operations ; Style: calm
#include <stdio.h>

int main() {
  int a = 13; // 1101 in binary
  int b = 9; // 1001 in binary
  int c;

  // Bitwise AND
  c = a & b; // 1001 in binary
  printf("Result of bitwise AND: %d\n", c);

  // Bitwise OR
  c = a | b; // 1101 in binary
  printf("Result of bitwise OR: %d\n", c);

  // Bitwise XOR
  c = a ^ b; // 0100 in binary
  printf("Result of bitwise XOR: %d\n", c);

  // Bitwise NOT
  c = ~a; // 0010 in binary
  printf("Result of bitwise NOT: %d\n", c);

  // Left shift
  c = a << 2; // 110100 in binary (52 in decimal)
  printf("Result of left shift: %d\n", c);

  // Right shift
  c = a >> 2; // 11 in binary (3 in decimal)
  printf("Result of right shift: %d\n", c);

  return 0;
}