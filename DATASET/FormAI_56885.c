//FormAI DATASET v1.0 Category: Bitwise operations ; Style: introspective
#include <stdio.h>

int main() {
  // Declare two variables to be bitwise operated
  int num1 = 10; // binary value 1010
  int num2 = 5;  // binary value  101

  // Bitwise AND operator example
  int result1 = num1 & num2;
  printf("Result of num1 AND num2: %d\n", result1); // Output: 0 (binary value 0000)

  // Bitwise OR operator example
  int result2 = num1 | num2;
  printf("Result of num1 OR num2: %d\n", result2); // Output: 15 (binary value 1111)

  // Bitwise XOR operator example
  int result3 = num1 ^ num2;
  printf("Result of num1 XOR num2: %d\n", result3); // Output: 15 (binary value 1111)

  // Bitwise NOT operator example
  int result4 = ~num1;
  printf("Result of NOT num1: %d\n", result4); // Output: -11 (binary value 1111111111111111111...0101)

  // Bitwise Left Shift operator example
  int result5 = num1 << 2;
  printf("Result of num1 shifted left by 2: %d\n", result5); // Output: 40 (binary value 101000)

  // Bitwise Right Shift operator example
  int result6 = num1 >> 2;
  printf("Result of num1 shifted right by 2: %d\n", result6); // Output: 2 (binary value 10)

  return 0;
}