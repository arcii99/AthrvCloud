//FormAI DATASET v1.0 Category: Bitwise operations ; Style: all-encompassing
#include <stdio.h>

// This program demonstrates Bitwise operations with integers

int main() {
  int num1 = 76; // Integer value 76 represented in binary: 01001100
  int num2 = 29; // Integer value 29 represented in binary: 00011101
  
  printf("The bitwise AND of %d and %d is %d\n", num1, num2, num1 & num2); // Prints 12 (00001100)
  printf("The bitwise OR of %d and %d is %d\n", num1, num2, num1 | num2); // Prints 93 (01011101)
  printf("The bitwise XOR of %d and %d is %d\n", num1, num2, num1 ^ num2); // Prints 81 (01010001)
  printf("The bitwise complement of %d is %d\n", num1, ~num1); // Prints -77 (10110011)
  printf("The left shift of %d by 3 is %d\n", num1, num1 << 3); // Prints 608 (1001100000)
  printf("The right shift of %d by 2 is %d\n", num2, num2 >> 2); // Prints 7 (00000111)
  
  return 0;
}