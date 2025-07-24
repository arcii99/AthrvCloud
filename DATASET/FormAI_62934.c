//FormAI DATASET v1.0 Category: Bitwise operations ; Style: detailed
// This program demonstrates a unique application of bitwise operations in C
#include <stdio.h>

int main() {
  unsigned int num1 = 731;  // 1011011011 in binary
  unsigned int num2 = 236;  // 11101100 in binary

  // Using bitwise operators to manipulate the bits of the numbers
  unsigned int andResult = num1 & num2;   // 10100100 in binary
  unsigned int orResult = num1 | num2;    // 1111111011 in binary
  unsigned int xorResult = num1 ^ num2;   // 1011101111 in binary
  unsigned int leftShiftResult = num1 << 3; // 1011011011000 in binary
  unsigned int rightShiftResult = num2 >> 2; // 111011 in binary
  unsigned int complementResult = ~num1;  // 1111111111111111111111100100100 in binary

  // Displaying the results
  printf("The result of num1 & num2 is %u\n", andResult);
  printf("The result of num1 | num2 is %u\n", orResult);
  printf("The result of num1 ^ num2 is %u\n", xorResult);
  printf("The result of num1 << 3 is %u\n", leftShiftResult);
  printf("The result of num2 >> 2 is %u\n", rightShiftResult);
  printf("The complement of num1 is %u\n", complementResult);

  return 0;
}