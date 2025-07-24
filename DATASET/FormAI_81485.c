//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
/*
    A statistical showcase of Bitwise operations in C programming language
*/

#include <stdio.h>

int main() {
  int a = 10;  // Binary 1010
  int b = 13;  // Binary 1101

  printf("Binary representation of %d: %d%d%d%d\n", a, a >> 3 & 1, a >> 2 & 1, a >> 1 & 1, a & 1);
  printf("Binary representation of %d: %d%d%d%d\n\n", b, b >> 3 & 1, b >> 2 & 1, b >> 1 & 1, b & 1);

  printf("AND operation: %d\n", a & b);  // Binary 1000
  printf("OR operation: %d\n", a | b);   // Binary 1111
  printf("XOR operation: %d\n\n", a ^ b); // Binary 0111

  int c = 7;   // Binary 0111
  int d = 15;  // Binary 1111

  printf("Binary representation of %d: %d%d%d%d\n", c, c >> 3 & 1, c >> 2 & 1, c >> 1 & 1, c & 1);
  printf("Binary representation of %d: %d%d%d%d\n\n", d, d >> 3 & 1, d >> 2 & 1, d >> 1 & 1, d & 1);

  printf("One's Complement of %d: %d\n", c, ~c);  // Binary 1000
  printf("One's Complement of %d: %d\n\n", d, ~d);  // Binary 0000

  printf("Left shift by 2 positions of %d: %d\n", a, a << 2);  // Binary 101000
  printf("Right shift by 2 positions of %d: %d\n", b, b >> 2); // Binary 0011
}