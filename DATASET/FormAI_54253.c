//FormAI DATASET v1.0 Category: Calculator ; Style: beginner-friendly
#include <stdio.h>

int main() {
  double num1, num2, result;
  char operator;

  printf("Enter two numbers separated by a space: ");
  scanf("%lf %lf", &num1, &num2);

  printf("Enter an operator (+, -, *, /): ");
  scanf(" %c", &operator);

  switch(operator) {
    case '+':
      result = num1 + num2;
      printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
      break;
    case '-':
      result = num1 - num2;
      printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
      break;
    case '*':
      result = num1 * num2;
      printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
      break;
    case '/':
      if(num2 == 0) {
        printf("Error: Cannot divide by zero!");
      } else {
        result = num1 / num2;
        printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
      }
      break;
    default:
      printf("Error: Invalid operator!");
  }

  return 0;
}