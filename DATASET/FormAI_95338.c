//FormAI DATASET v1.0 Category: Bitwise operations ; Style: ultraprecise
#include <stdio.h>

int main() {
  int a = 10;
  int b = 20;

  // Bitwise AND

  int result_AND = a & b;

  printf("The value of result_AND is: %d\n", result_AND);

  // Bitwise OR

  int result_OR = a | b;

  printf("The value of result_OR is: %d\n", result_OR);

  // Bitwise XOR

  int result_XOR = a ^ b;

  printf("The value of result_XOR is: %d\n", result_XOR);

  // Bitwise Complement

  int result_Complement = ~a;

  printf("The value of result_Complement is: %d\n", result_Complement);

  // Left Shift operator

  int result_LeftShift = a << 2;

  printf("The value of result_LeftShift is: %d\n", result_LeftShift);

  // Right Shift operator

  int result_RightShift = b >> 2;

  printf("The value of result_RightShift is: %d\n", result_RightShift);

  // Compound Bitwise AND

  a &= b;

  printf("The value of a after Compound Bitwise AND is: %d\n", a);

  // Compound Bitwise OR

  a |= b;

  printf("The value of a after Compound Bitwise OR is: %d\n", a);

  // Compound Bitwise XOR

  a ^= b;

  printf("The value of a after Compound Bitwise XOR is: %d\n", a);

  // Compound Left Shift operator

  a <<= 2;

  printf("The value of a after Compound Left Shift operator is: %d\n", a);

  // Compound Right Shift operator

  b >>= 2;

  printf("The value of b after Compound Right Shift operator is: %d\n", b);

  return 0;
}