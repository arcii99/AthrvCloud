//FormAI DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int num1, num2;
  char operator;

  printf("Enter first number: ");
  scanf("%d", &num1);

  printf("Enter operator (+, -, *, /): ");
  scanf(" %c", &operator);

  printf("Enter second number: ");
  scanf("%d", &num2);

  int result = 0;

  switch (operator) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      if (num2 == 0) {
        printf("Error: division by zero\n");
        exit(EXIT_FAILURE);
      }
      result = num1 / num2;
      break;
    default:
      printf("Invalid operator\n");
      exit(EXIT_FAILURE);
  }

  printf("%d %c %d = %d\n", num1, operator, num2, result);

  return 0;
}