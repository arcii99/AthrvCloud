//FormAI DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>

int main() {
  int num1 = 500;
  int num2 = 700;
  int result;

  printf("Get ready to witness the magic of arithmetic operations!\n\n");

  // Addition
  result = num1 + num2;
  printf("%d + %d = %d\n\n", num1, num2, result);

  // Subtraction
  result = num1 - num2;
  printf("%d - %d = %d\n\n", num1, num2, result);

  // Multiplication
  result = num1 * num2;
  printf("%d * %d = %d\n\n", num1, num2, result);

  // Division
  result = num1 / num2;
  printf("%d / %d = %d\n\n", num1, num2, result);

  // Modulo
  result = num1 % num2;
  printf("%d mod %d = %d\n\n", num1, num2, result);

  printf("What else do you want to see? The power of arithmetic operations?\n\n");

  // Power
  result = 1;
  for(int i=1; i<=5; i++) {
    result *= num1;
  }

  printf("%d raised to 5 = %d\n\n", num1, result);

  printf("Are you not entertained?");

  return 0;
}