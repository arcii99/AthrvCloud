//FormAI DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>

// This is a program about bit manipulation in creative style
// We will be using various bit-wise operators like &, |, ~, ^ and <<, >> to perform operations

int main() {
  // Let's start with some binary number operations
  
  // Let's print some binary numbers
  printf("1 in binary is %b\n", 1); // Output: 1 in binary is 1
  printf("15 in binary is %b\n", 15); // Output: 15 in binary is 1111
  
  // Bitwise AND
  int num1 = 5; // Binary 101
  int num2 = 3; // Binary 011
  int result = num1 & num2; // Bitwise AND - 001
  printf("Result of Bitwise AND between %d and %d is %d\n", num1, num2, result); // Output: Result of Bitwise AND between 5 and 3 is 1
  
  // Bitwise OR
  num1 = 5; // Binary 101
  num2 = 3; // Binary 011
  result = num1 | num2; // Bitwise OR - 111
  printf("Result of Bitwise OR between %d and %d is %d\n", num1, num2, result); // Output: Result of Bitwise OR between 5 and 3 is 7
  
  // Bitwise NOT
  num1 = 5; // Binary 101
  result = ~num1; // Bitwise NOT - 010
  printf("Result of Bitwise NOT of %d is %d\n", num1, result); // Output: Result of Bitwise NOT of 5 is -6
  
  // Bitwise XOR
  num1 = 5; // Binary 101
  num2 = 3; // Binary 011
  result = num1 ^ num2; // Bitwise XOR - 110
  printf("Result of Bitwise XOR between %d and %d is %d\n", num1, num2, result); // Output: Result of Bitwise XOR between 5 and 3 is 6
  
  // Bitwise Left Shift
  num1 = 5; // Binary 101
  result = num1 << 2; // Bitwise Left Shift by 2 - 10100
  printf("Result of Bitwise Left Shift of %d by 2 is %d\n", num1, result); // Output: Result of Bitwise Left Shift of 5 by 2 is 20
  
  // Bitwise Right Shift
  num1 = 5; // Binary 101
  result = num1 >> 2; // Bitwise Right Shift by 2 - 001
  printf("Result of Bitwise Right Shift of %d by 2 is %d\n", num1, result); // Output: Result of Bitwise Right Shift of 5 by 2 is 1

  return 0;
}