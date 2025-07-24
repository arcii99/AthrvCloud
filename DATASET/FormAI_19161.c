//FormAI DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>

int main() {
  int num1 = 10;
  int num2 = 15;
  
  printf("Let's perform some Bitwise operations on %d and %d!\n", num1, num2);
  printf("Original values:\nNum1 = %d\nNum2 = %d\n\n", num1, num2);

  // Bitwise AND
  int result_and = num1 & num2;
  printf("Bitwise AND:\nNum1 & Num2 = %d\n\n", result_and);

  // Bitwise OR
  int result_or = num1 | num2;
  printf("Bitwise OR:\nNum1 | Num2 = %d\n\n", result_or);

  // Bitwise XOR
  int result_xor = num1 ^ num2;
  printf("Bitwise XOR:\nNum1 ^ Num2 = %d\n\n", result_xor);

  // Bitwise NOT
  int result_not1 = ~num1;
  int result_not2 = ~num2;
  printf("Bitwise NOT:\n~Num1 = %d\n~Num2 = %d\n\n", result_not1, result_not2);

  // Bitwise Shift Left
  int result_shiftleft = num1 << 2;
  printf("Bitwise Shift Left:\nNum1 << 2 = %d\n\n", result_shiftleft);

  // Bitwise Shift Right
  int result_shiftright = num2 >> 2;
  printf("Bitwise Shift Right:\nNum2 >> 2 = %d\n\n", result_shiftright);

  printf("Wow! That was some bitwise fun! Until next time!\n");

  return 0;
}