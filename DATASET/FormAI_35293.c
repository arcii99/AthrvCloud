//FormAI DATASET v1.0 Category: Funny ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2, result;
  char operator;

  printf("Welcome to the Awesome Calculator!\n");
  printf("Please enter two numbers followed by an operator (+, -, *, /): ");
  scanf("%d %d %c", &num1, &num2, &operator);

  switch (operator) {
    case '+':
      result = num1 + num2;
      printf("%d + %d = %d\n", num1, num2, result);
      break;
    case '-':
      result = num1 - num2;
      printf("%d - %d = %d\n", num1, num2, result);
      break;
    case '*':
      result = num1 * num2;
      printf("%d * %d = %d\n", num1, num2, result);
      break;
    case '/':
      if (num2 == 0) {
        printf("Cannot divide by zero. Exiting program.\n");
        exit(0);
      }
      result = num1 / num2;
      printf("%d / %d = %d\n", num1, num2, result);
      break;
    default:
      printf("Invalid operator. Exiting program.\n");
      exit(0);
  }

  printf("Thank you for using the Awesome Calculator! Have a nice day!\n");

  return 0;
}