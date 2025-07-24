//FormAI DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>

int main() {
  int a, b, c, result;
  char operator;

  printf("Enter the expression: ");
  scanf("%d %c %d", &a, &operator, &b);

  switch(operator) {
    case '+':
      result = a + b;
      printf("Result: %d\n", result);
      break;

    case '-':
      result = a - b;
      printf("Result: %d\n", result);
      break;

    case '*':
      result = a * b;
      printf("Result: %d\n", result);
      break;

    case '/':
      if(b == 0) {
        printf("Cannot divide by zero.\n");
      } else {
        result = a / b;
        printf("Result: %d\n", result);
      }
      break;

    case '%':
      if(b == 0) {
        printf("Cannot divide by zero.\n");
      } else {
        result = a % b;
        printf("Result: %d\n", result);
      }
      break;

    default:
      printf("Invalid operator.\n");
  }

  return 0;
}