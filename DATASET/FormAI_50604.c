//FormAI DATASET v1.0 Category: Bitwise operations ; Style: detailed
#include <stdio.h>

int main() {
  unsigned int a = 60; // decimal value of 60 in binary is 0011 1100
  unsigned int b = 13; // decimal value of 13 in binary is 0000 1101

  // Bitwise AND Operation
  printf("a & b = %d\n", a & b); // 0000 1100 => decimal 12
  
  // Bitwise OR Operation
  printf("a | b = %d\n", a | b); // 0011 1101 => decimal 61
  
  // Bitwise NOT Operation
  printf("~a = %d\n", ~a); // 1100 0011 => decimal is -61 because of 2's complement

  // Bitwise XOR Operation
  printf("a ^ b = %d\n", a ^ b); // 0011 0001 => decimal 49

  // Left Shift Operation
  printf("a << 2 = %d\n", a << 2); // 1111 0000 => decimal 240
  
  // Right Shift Operation
  printf("a >> 2 = %d\n", a >> 2); // 0000 1111 => decimal 15
  
  // Bitwise AND Assignment
  a &= b; // a = 0000 1100 => decimal 12
  printf("a = %d\n", a);

  // Bitwise OR Assignment
  a |= b; // a = 0000 1101 => decimal 13
  printf("a = %d\n", a);

  // Bitwise XOR Assignment
  a ^= b; // a = 0011 0001 => decimal 49
  printf("a = %d\n", a);

  // Left Shift Assignment
  a <<= 2; // a = 1100 0100 => decimal 196
  printf("a = %d\n", a);

  // Right Shift Assignment
  a >>= 2; // a = 0011 0001 => decimal 49
  printf("a = %d\n", a);

  return 0;
}