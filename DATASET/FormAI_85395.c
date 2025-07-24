//FormAI DATASET v1.0 Category: Educational ; Style: shocked
#include <stdio.h>

int main() {
  printf("Oh my goodness, I can't believe what I just coded!\n");

  // Declare variables
  int num1, num2, result;
  char operator;

  // Get user input
  printf("Enter first number: ");
  scanf("%d", &num1);
  printf("Enter operator (+, -, *, /): ");
  scanf(" %c", &operator);
  printf("Enter second number: ");
  scanf("%d", &num2);

  // Perform calculation based on operator entered
  switch (operator) {
    case '+':
      result = num1 + num2;
      printf("The sum of %d and %d is %d\n", num1, num2, result);
      break;
    case '-':
      result = num1 - num2;
      printf("The difference between %d and %d is %d\n", num1, num2, result);
      break;
    case '*':
      result = num1 * num2;
      printf("The product of %d and %d is %d\n", num1, num2, result);
      break;
    case '/':
      result = num1 / num2;
      printf("The quotient when %d is divided by %d is %d\n", num1, num2, result);
      break;
    default:
      printf("Invalid operator. Please try again.\n");
  }

  printf("I never thought I could code something so cool and useful!\n");

  return 0;
}