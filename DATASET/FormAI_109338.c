//FormAI DATASET v1.0 Category: Bitwise operations ; Style: excited
#include <stdio.h>

int main() {
  // Let's declare some variables
  int num1 = 23, num2 = 16;
  unsigned int result;
  printf("Let's perform some C bitwise operations! Aren't you excited?\n");
  
  // AND Operation
  result = num1 & num2;
  printf("The result of the AND operation between %d and %d is %u\n", num1, num2, result);

  // OR Operation
  result = num1 | num2;
  printf("The result of the OR operation between %d and %d is %u\n", num1, num2, result);

  // XOR Operation
  result = num1 ^ num2;
  printf("The result of the XOR operation between %d and %d is %u\n", num1, num2, result);

  // Left Shift Operation
  result = num1 << 1;
  printf("The result of the Left Shift operation on %d is %u\n", num1, result);

  // Right Shift Operation
  result = num1 >> 1;
  printf("The result of the Right Shift operation on %d is %u\n", num1, result);

  // Ones Complement Operator
  result = ~num1;
  printf("The result of the Ones Complement operation on %d is %u\n", num1, result);

  // Two's Complement Operator
  result = ~num2 + 1;
  printf("The result of the Two's Complement operation on %d is %u\n", num2, result);

  printf("Woohoo! We just performed some amazing C bitwise operations! Isn't it exciting?\n");
  return 0;
}