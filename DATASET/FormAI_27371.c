//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include<stdio.h>

int main() {
  // declare variables
  int num1, num2, result;

  printf("Enter first number: ");
  scanf("%d", &num1);

  printf("Enter second number: ");
  scanf("%d", &num2);

  printf("Performing bitwise AND operation...\n");
  result = num1 & num2;
  printf("Result: %d\n", result);

  printf("Performing bitwise OR operation...\n");
  result = num1 | num2;
  printf("Result: %d\n", result);

  printf("Performing bitwise XOR operation...\n");
  result = num1 ^ num2;
  printf("Result: %d\n", result);

  printf("Performing bitwise NOT operation on first number...\n");
  result = ~ num1;
  printf("Result: %d\n", result);

  printf("Performing left shift operation on first number...\n");
  result = num1 << 1;
  printf("Result: %d\n", result);

  printf("Performing right shift operation on first number...\n");
  result = num1 >> 1;
  printf("Result: %d\n", result);

  return 0;
}