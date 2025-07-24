//FormAI DATASET v1.0 Category: Arithmetic ; Style: immersive
#include <stdio.h>

int main() {
  int num1, num2, result;
  char operator;

  printf("Welcome to the immersive arithmetic calculator!\n\n");

  printf("Please enter your first number: ");
  scanf("%d", &num1);

  printf("Please enter your second number: ");
  scanf("%d", &num2);

  printf("Please select an operator (+, -, *, /): ");
  scanf(" %c", &operator);

  switch(operator) {
    case '+':
      result = num1 + num2;
      printf("\n%d + %d = %d\n\n", num1, num2, result);
      break;

    case '-':
      result = num1 - num2;
      printf("\n%d - %d = %d\n\n", num1, num2, result);
      break;

    case '*':
      result = num1 * num2;
      printf("\n%d x %d = %d\n\n", num1, num2, result);
      break;

    case '/':
      if(num2 == 0) {
        printf("\nError: division by zero.\n\n");
      }
      else {
        result = num1 / num2;
        printf("\n%d ÷ %d = %d\n\n", num1, num2, result);
      }
      break;

    default:
      printf("\nError: invalid operator selected.\n\n");
  }

  printf("Thank you for using the immersive arithmetic calculator!\n");

  return 0;
}