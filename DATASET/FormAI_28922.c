//FormAI DATASET v1.0 Category: Bitwise operations ; Style: protected
#include <stdio.h>

int main() {
  unsigned int a = 60;              // 60 = 0011 1100
  unsigned int b = 13;              // 13 = 0000 1101
  int result = 0;

  // Bitwise AND '&'
  result = a & b;                   // 12 = 0000 1100
  printf("a & b = %d\n", result);

  // Bitwise OR '|'
  result = a | b;                   // 61 = 0011 1101
  printf("a | b = %d\n", result);

  // Bitwise XOR '^'
  result = a ^ b;                   // 49 = 0011 0001
  printf("a ^ b = %d\n", result);

  // Bitwise NOT '~'
  result = ~a;                      // -61 = 1100 0011
  printf("~a = %d\n", result);

  // Left shift '<<'
  result = a << 2;                  // 240 = 1111 0000
  printf("a << 2 = %d\n", result);

  // Right shift '>>'
  result = a >> 2;                  // 15 = 0000 1111
  printf("a >> 2 = %d\n", result);

  // Bitwise AND assignment '&='
  a &= b;                           // a = 0000 1100
  printf("a &= b: a = %d\n", a);

  // Bitwise OR assignment '|='
  a |= b;                           // a = 0000 1101
  printf("a |= b: a = %d\n", a);

  // Bitwise XOR assignment '^='
  a ^= b;                           // a = 0011 0001
  printf("a ^= b: a = %d\n", a);

  // Left shift assignment '<<='
  a <<= 2;                          // a = 1100 0100
  printf("a <<= 2: a = %d\n", a);

  // Right shift assignment '>>='
  a >>= 2;                          // a = 0011 0001
  printf("a >>= 2: a = %d\n", a);

  return 0;
}