//FormAI DATASET v1.0 Category: Calculator ; Style: beginner-friendly
#include <stdio.h>

int main() {
  char operation;
  float num1, num2;

  printf("Welcome to Calculator Program\n\n");
  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &operation);

  printf("Enter first number: ");
  scanf("%f", &num1);

  printf("Enter second number: ");
  scanf("%f", &num2);

  switch (operation) {
    case '+':
      printf("%.2f + %.2f = %.2f", num1, num2, num1 + num2);
      break;
    case '-':
      printf("%.2f - %.2f = %.2f", num1, num2, num1 - num2);
      break;
    case '*':
      printf("%.2f * %.2f = %.2f", num1, num2, num1 * num2);
      break;
    case '/':
      if (num2 == 0) {
        printf("Error: Cannot divide by zero\n");
      } else {
        printf("%.2f / %.2f = %.2f", num1, num2, num1 / num2);
      }
      break;
    default:
      printf("Error: Invalid operator\n");
      break;
  }

  return 0;
}