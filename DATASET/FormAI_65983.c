//FormAI DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2, result;
  char operator;

  printf("Enter the first number: ");
  scanf("%d", &num1);
  printf("Enter the second number: ");
  scanf("%d", &num2);
  printf("Enter the operator (+, -, *, /): ");
  scanf(" %c", &operator);

  switch(operator) {
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
      if(num2 == 0) {
        printf("Error: division by zero.\n");
        exit(1);
      } else {
        result = num1 / num2;
        printf("%d / %d = %d\n", num1, num2, result);
      }
      break;
    default:
      printf("Error: invalid operator.\n");
      exit(1);
  }

  return 0;
}