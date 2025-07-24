//FormAI DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>

int main() {
  int num1, num2;
  char operator;

  printf("Welcome to the intelligent calculator!\n");
  printf("Please enter your first number: ");
  scanf("%d", &num1);

  printf("Please enter your second number: ");
  scanf("%d", &num2);

  printf("Please enter your operator (+, -, *, /): ");
  scanf(" %c", &operator);

  switch (operator) {
    case '+':
      printf("%d + %d = %d\n", num1, num2, num1 + num2);
      break;

    case '-':
      printf("%d - %d = %d\n", num1, num2, num1 - num2);
      break;

    case '*':
      printf("%d * %d = %d\n", num1, num2, num1 * num2);
      break;

    case '/':
      if (num2 == 0) {
        printf("Error! Division by zero.\n");
      } else {
        printf("%d / %d = %d\n", num1, num2, num1 / num2);
      }
      break;

    default:
      printf("Error! Invalid operator.\n");
      break;
  }

  printf("Thank you for using the intelligent calculator!\n");
  return 0;
}