//FormAI DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

int main() {
  int a = 60; // Binary representation: 0011 1100
  int b = 13; // Binary representation: 0000 1101

  // Bitwise AND operator
  int c = a & b; // Bitwise AND of 0011 1100 and 0000 1101 gives 0000 1100 in binary (Decimal: 12)
  printf("Bitwise AND of %d and %d is %d\n", a, b, c);

  // Bitwise OR operator
  int d = a | b; // Bitwise OR of 0011 1100 and 0000 1101 gives 0011 1101 in binary (Decimal: 61)
  printf("Bitwise OR of %d and %d is %d\n", a, b, d);

  // Bitwise XOR operator
  int e = a ^ b; // Bitwise XOR of 0011 1100 and 0000 1101 gives 0011 0001 in binary (Decimal: 49)
  printf("Bitwise XOR of %d and %d is %d\n", a, b, e);

  // Bitwise NOT operator
  int f = ~a; // Bitwise NOT of 0011 1100 gives 1100 0011 in binary (Decimal: -61)
  printf("Bitwise NOT of %d is %d\n", a, f);

  // Left shift operator
  int g = a << 2; // Left shift of 0011 1100 by 2 bits gives 1111 0000 in binary (Decimal: 240)
  printf("Left shift of %d by 2 bits is %d\n", a, g);

  // Right shift operator
  int h = a >> 2; // Right shift of 0011 1100 by 2 bits gives 0000 1111 in binary (Decimal: 15)
  printf("Right shift of %d by 2 bits is %d\n", a, h);

  return 0;
}