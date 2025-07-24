//FormAI DATASET v1.0 Category: Bitwise operations ; Style: protected
#include <stdio.h>

int main() {
  unsigned int num1 = 5;
  unsigned int num2 = 9;

  printf("num1 = %u, num2 = %u\n\n", num1, num2);

  // Bitwise AND
  unsigned int result = num1 & num2;
  printf("num1 & num2 = %u\n", result);

  // Bitwise OR
  result = num1 | num2;
  printf("num1 | num2 = %u\n", result);

  // Bitwise XOR
  result = num1 ^ num2;
  printf("num1 ^ num2 = %u\n", result);

  // Bitwise NOT
  result = ~num1;
  printf("~num1 = %u\n", result);

  // Left shift
  result = num1 << 2;
  printf("num1 << 2 = %u\n", result);

  // Right shift
  result = num2 >> 2;
  printf("num2 >> 2 = %u\n", result);

  // Setting a bit
  result = num1 | (1 << 3);
  printf("Setting 4th bit of num1: %u\n", result);

  // Clearing a bit
  result = num2 & ~(1 << 2);
  printf("Clearing 3rd bit of num2: %u\n", result);

  // Toggling a bit
  result = num1 ^ (1 << 1);
  printf("Toggling 2nd bit of num1: %u\n", result);

  return 0;
}