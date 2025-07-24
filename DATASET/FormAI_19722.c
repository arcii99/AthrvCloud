//FormAI DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

int main() {
  int a = 5;  // 0101 in binary
  int b = 3;  // 0011 in binary
  int c;

  // Bitwise AND
  c = a & b;  // 0001 in binary
  printf("a & b = %d\n", c);

  // Bitwise OR
  c = a | b;  // 0111 in binary
  printf("a | b = %d\n", c);

  // Bitwise XOR
  c = a ^ b;  // 0110 in binary
  printf("a ^ b = %d\n", c);

  // Bitwise NOT
  c = ~a;  // 1010 in binary
  printf("~a = %d\n", c);

  // Bitwise LEFT SHIFT
  c = a << 1;  // 1010 in binary (10 in decimal)
  printf("a << 1 = %d\n", c);

  // Bitwise RIGHT SHIFT
  c = a >> 1;  // 0010 in binary (2 in decimal)
  printf("a >> 1 = %d\n", c);

  return 0;
}