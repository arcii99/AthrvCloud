//FormAI DATASET v1.0 Category: Calculator ; Style: beginner-friendly
#include <stdio.h>

int main() {
  int num1, num2, result;
  char operator;

  printf("Enter first number: ");
  scanf("%d", &num1);
  printf("Enter operator (+, -, *, /): ");
  scanf(" %c", &operator);
  printf("Enter second number: ");
  scanf("%d", &num2);

  switch(operator) {
    case '+':
      result = num1 + num2;
      printf("\n%d + %d = %d\n", num1, num2, result);
      break;
    case '-':
      result = num1 - num2;
      printf("\n%d - %d = %d\n", num1, num2, result);
      break;
    case '*':
      result = num1 * num2;
      printf("\n%d * %d = %d\n", num1, num2, result);
      break;
    case '/':
      if(num2 == 0) {
        printf("\nError: Divide by zero\n");
      } else {
        result = num1 / num2;
        printf("\n%d / %d = %d\n", num1, num2, result);
      }
      break;
    default:
      printf("\nError: Invalid operator\n");
      break;
  }

  return 0;
}