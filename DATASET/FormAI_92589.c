//FormAI DATASET v1.0 Category: Bitwise operations ; Style: bold
#include <stdio.h>

int main() {
  // bold headline
  printf("\033[1m");
  printf("Bitwise operations in C programming\n");
  printf("\033[0m");

  // binary numbers
  int a = 60; // 0011 1100
  int b = 13; // 0000 1101
  int c = 0;

  // AND bitwise operator
  printf("a & b = %d\n", a & b);
  /* Result should be 12 (0000 1100) */

  // OR bitwise operator
  printf("a | b = %d\n", a | b);
  /* Result should be 61 (0011 1101) */

  // XOR bitwise operator
  printf("a ^ b = %d\n", a ^ b);
  /* Result should be 49 (0011 0001) */

  // NOT bitwise operator
  printf("~a = %d\n", ~a);
  /* Result should be -61 (1100 0011) */

  // left shift bitwise operator
  c = a << 2; // shift a two places to the left
  printf("a << 2 = %d\n", c);
  /* Result should be 240 (1111 0000) */

  // right shift bitwise operator
  c = a >> 2; // shift a two places to the right
  printf("a >> 2 = %d\n", c);
  /* Result should be 15 (0000 1111) */

  return 0;
}