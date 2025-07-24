//FormAI DATASET v1.0 Category: Bitwise operations ; Style: ultraprecise
#include <stdio.h>

int main() {
  int a = 7; // 0111 in binary
  int b = 11; // 1011 in binary
  int c;

  // Bitwise OR (|)
  c = a | b;
  printf("a | b = %d\n", c); // This will print 15 (1111 in binary)

  // Bitwise AND (&)
  c = a & b;
  printf("a & b = %d\n", c); // This will print 3 (0011 in binary)

  // Bitwise XOR (^)
  c = a ^ b;
  printf("a ^ b = %d\n", c); // This will print 12 (1100 in binary)

  // Bitwise NOT (~)
  c = ~a;
  printf("~a = %d\n", c); // This will print -8 (1000 0111 in binary)

  // Bitwise Left Shift (<<)
  c = a << 2;
  printf("a << 2 = %d\n", c); // This will print 28 (11100 in binary)

  // Bitwise Right Shift (>>)
  c = b >> 1;
  printf("b >> 1 = %d\n", c); // This will print 5 (0101 in binary)

  return 0;
}