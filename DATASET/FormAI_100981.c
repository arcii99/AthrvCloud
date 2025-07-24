//FormAI DATASET v1.0 Category: Bitwise operations ; Style: curious
#include <stdio.h>

int main() {
  int a = 13;
  int b = 7;

  // Bitwise AND operation
  int and_result = a & b;
  printf("Bitwise AND result of %d and %d is %d\n", a, b, and_result);

  // Bitwise OR operation
  int or_result = a | b;
  printf("Bitwise OR result of %d and %d is %d\n", a, b, or_result);

  // Bitwise XOR operation
  int xor_result = a ^ b;
  printf("Bitwise XOR result of %d and %d is %d\n", a, b, xor_result);

  // Bitwise NOT operation
  int not_result = ~a;
  printf("Bitwise NOT result of %d is %d\n", a, not_result);

  // Bitwise Left Shift operation
  int left_shift_result = a << 2;
  printf("Bitwise Left Shift result of %d by 2 is %d\n", a, left_shift_result);

  // Bitwise Right Shift operation
  int right_shift_result = b >> 2;
  printf("Bitwise Right Shift result of %d by 2 is %d\n", b, right_shift_result);

  // Bitwise AND assignment operator
  a &= b;
  printf("Bitwise AND assignment result of %d and %d is %d\n", a, b, a);

  // Bitwise OR assignment operator
  a |= b;
  printf("Bitwise OR assignment result of %d and %d is %d\n", a, b, a);

  // Bitwise XOR assignment operator
  a ^= b;
  printf("Bitwise XOR assignment result of %d and %d is %d\n", a, b, a);

  return 0;
}