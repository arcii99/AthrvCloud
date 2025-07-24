//FormAI DATASET v1.0 Category: Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
  char operator;
  double num1, num2;

  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &operator);
  printf("Enter two operands: ");
  scanf("%lf %lf", &num1, &num2);

  switch (operator) {
    case '+':
      printf("%.1lf + %.1lf = %.1lf", num1, num2, num1 + num2);
      break;
    case '-':
      printf("%.1lf - %.1lf = %.1lf", num1, num2, num1 - num2);
      break;
    case '*':
      printf("%.1lf * %.1lf = %.1lf", num1, num2, num1 * num2);
      break;
    case '/':
      if (num2 == 0) {
        printf("Error: Division by zero");
        exit(0);
      }
      printf("%.1lf / %.1lf = %.1lf", num1, num2, num1 / num2);
      break;
    default:
      printf("Invalid Operator");
  }

  return 0;
}