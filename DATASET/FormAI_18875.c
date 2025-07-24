//FormAI DATASET v1.0 Category: Bitwise operations ; Style: active
#include <stdio.h>

int main() {
  // Bitwise AND operation
  int num1 = 42; // binary 00101010
  int num2 = 13; // binary 00001101
  int result = num1 & num2; // binary 00001000
  printf("Bitwise AND result of %d and %d is %d\n", num1, num2, result);

  // Bitwise OR operation
  int num3 = 7; // binary 00000111
  int num4 = 11; // binary 00001011
  result = num3 | num4; // binary 00001111
  printf("Bitwise OR result of %d and %d is %d\n", num3, num4, result);

  // Bitwise XOR operation
  int num5 = 25; // binary 00011001
  int num6 = 18; // binary 00010010
  result = num5 ^ num6; // binary 00001011
  printf("Bitwise XOR result of %d and %d is %d\n", num5, num6, result);

  // Bitwise NOT operation
  int num7 = 127; // binary 01111111
  result = ~num7; // binary 10000000
  printf("Bitwise NOT result of %d is %d\n", num7, result);

  // Left shift operation
  int num8 = 10; // binary 00001010
  result = num8 << 2; // binary 00101000
  printf("Left shift result of %d by 2 is %d\n", num8, result);

  // Right shift operation
  int num9 = 40; // binary 00101000
  result = num9 >> 3; // binary 00000101
  printf("Right shift result of %d by 3 is %d\n", num9, result);

  return 0;
}