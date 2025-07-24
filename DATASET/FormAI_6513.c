//FormAI DATASET v1.0 Category: Calculator ; Style: portable
#include <stdio.h>

int main() {
  char operation;
  float num1, num2;

  printf("Enter operator (+, -, *, /): ");
  scanf("%c", &operation);

  printf("Enter first number:");
  scanf("%f", &num1);

  printf("Enter second number:");
  scanf("%f", &num2);

  switch(operation) {
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
      if(num2 == 0) {
        printf("Error! Cannot divide by zero.");
      } else {
        printf("%.2f / %.2f = %.2f", num1, num2, num1 / num2);
      }
      break;
    default:
      printf("Error! Invalid operator.");
      break;
  }

  return 0;
}