//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Alan Touring
#include <stdio.h>

int main() {
  int a = 31;   // 0001 1111 in binary
  int b = 16;   // 0001 0000 in binary
  int c = 0;    // Initialized to zero for demonstration purposes

  // Bitwise AND Operator Example
  printf("a & b = %d\n", a & b);   // 0001 0000

  // Bitwise OR Operator Example
  printf("a | b = %d\n", a | b);   // 0001 1111

  // Bitwise XOR Operator Example
  printf("a ^ b = %d\n", a ^ b);   // 0000 1111

  // Bitwise LEFT SHIFT Operator Example
  c = a << 1;    // Shift a by 1 bit to the left, 0011 1110
  printf("a << 1 = %d\n", c);

  // Bitwise RIGHT SHIFT Operator Example
  c = b >> 2;    // Shift b by 2 bits to the right, 0000 0100
  printf("b >> 2 = %d\n", c);

  // Bitwise COMPLEMENT Operator Example
  printf("~a = %d\n", ~a);    // 1110 0000

  return 0;
}