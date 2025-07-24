//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Claude Shannon
#include <stdio.h>

int main() {
  int num1 = 10;  // Binary value is 1010
  int num2 = 3;   // Binary value is 0011

  // Bitwise AND operator
  int result1 = num1 & num2; // Binary value is 0010 (2 in decimal)
  printf("num1 & num2 = %d\n", result1);

  // Bitwise OR operator
  int result2 = num1 | num2; // Binary value is 1011 (11 in decimal)
  printf("num1 | num2 = %d\n", result2);

  // Bitwise XOR operator
  int result3 = num1 ^ num2; // Binary value is 1001 (9 in decimal)
  printf("num1 ^ num2 = %d\n", result3);

  // Bitwise NOT operator
  int result4 = ~num1; // Binary value is 0101 (5 in decimal)
  printf("~num1 = %d\n", result4);

  // Bitwise left shift operator
  int result5 = num1 << 2; // Binary value is 101000 (40 in decimal)
  printf("num1 << 2 = %d\n", result5);

  // Bitwise right shift operator
  int result6 = num1 >> 2; // Binary value is 0010 (2 in decimal)
  printf("num1 >> 2 = %d\n", result6);

  return 0;
}