//FormAI DATASET v1.0 Category: Arithmetic ; Style: Linus Torvalds
#include <stdio.h>

int main() {
  printf("Enter two numbers to perform arithmetic operations: ");
  int num1, num2;
  scanf("%d %d", &num1, &num2); // takes input from user

  // Addition
  int sum = num1 + num2;
  printf("%d + %d = %d\n", num1, num2, sum);

  // Subtraction
  int diff = num1 - num2;
  printf("%d - %d = %d\n", num1, num2, diff);

  // Multiplication
  int product = num1 * num2;
  printf("%d * %d = %d\n", num1, num2, product);

  // Division
  float quotient = (float)num1 / num2; // typecasting
  printf("%d / %d = %.2f\n", num1, num2, quotient);

  // Modulus
  int remainder = num1 % num2;
  printf("%d %% %d = %d\n", num1, num2, remainder);

  // Increment and Decrement
  num1++; // increment operator
  num2--; // decrement operator
  printf("num1 incremented by 1 is %d\n", num1);
  printf("num2 decremented by 1 is %d\n", num2);

  return 0;
}