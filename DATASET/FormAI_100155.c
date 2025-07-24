//FormAI DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>

int main() {
  int num1 = 12;
  int num2 = 6;
  int result = 0;

  printf("The value of num1 is %d and num2 is %d\n", num1, num2);

  // Bitwise AND operation
  result = num1 & num2;
  printf("Bitwise AND operation: %d & %d = %d\n", num1, num2, result);

  // Bitwise OR operation
  result = num1 | num2;
  printf("Bitwise OR operation: %d | %d = %d\n", num1, num2, result);

  // Bitwise XOR operation
  result = num1 ^ num2;
  printf("Bitwise XOR operation: %d ^ %d = %d\n", num1, num2, result);

  // Bitwise complement operation
  result = ~num1;
  printf("Bitwise complement of %d = %d\n", num1, result);

  // Left shift operation
  result = num1 << 2;
  printf("Left shift operation: %d << 2 = %d\n", num1, result);

  // Right shift operation
  result = num1 >> 2;
  printf("Right shift operation: %d >> 2 = %d\n", num1, result);

  return 0;
}