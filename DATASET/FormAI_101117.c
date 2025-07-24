//FormAI DATASET v1.0 Category: Arithmetic ; Style: detailed
/*
  This program is a simple calculator that allows the user to 
  enter two numbers and perform basic arithmetic operations such as 
  addition, subtraction, multiplication and division.
*/
#include <stdio.h>

int main() {
  char operator;
  double num1, num2;

  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &operator);

  printf("Enter two numbers separated by space: ");
  scanf("%lf %lf", &num1, &num2);

  switch (operator) {
    case '+': // addition
      printf("%.2lf + %.2lf = %.2lf", num1, num2, num1 + num2);
      break;

    case '-': // subtraction
      printf("%.2lf - %.2lf = %.2lf", num1, num2, num1 - num2);
      break;

    case '*': // multiplication
      printf("%.2lf * %.2lf = %.2lf", num1, num2, num1 * num2);
      break;

    case '/': // division
      if (num2 == 0) {
        printf("Cannot divide by zero");
      } else {
        printf("%.2lf / %.2lf = %.2lf", num1, num2, num1 / num2);
      }
      break;

    default: // invalid operator
      printf("Invalid operator");
  }

  return 0;
}