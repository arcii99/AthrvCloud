//FormAI DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>

int main() {
  int num1, num2, result;
  char operator;

  printf("Enter an operation (+, -, *, /): ");
  scanf("%c", &operator);

  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

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
      if(num2 == 0) {
        printf("Cannot divide by zero.\n");
      } else {
        result = num1 / num2;
        printf("%d / %d = %d\n", num1, num2, result);
      }
      break;
    default:
      printf("Invalid operator.\n");
  }

  return 0;
}