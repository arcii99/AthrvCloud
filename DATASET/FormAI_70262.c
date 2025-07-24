//FormAI DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int a, b;
  char op;
  float result;
  bool input_valid = false;

  while (!input_valid) {
    printf("Enter the first number and operator separated by a space: ");
    scanf("%d %c", &a, &op);
    printf("Enter the second number: ");
    scanf("%d", &b);

    input_valid = true;

    switch (op) {
      case '+':
        result = a + b;
        break;
      case '-':
        result = a - b;
        break;
      case '*':
        result = a * b;
        break;
      case '/':
        if (b == 0) {
          printf("Division by zero is not allowed.\n");
          input_valid = false;
        } else {
          result = (float) a / b;
        }
        break;
      default:
        printf("Invalid operator '%c'.\n", op);
        input_valid = false;
        break;
    }
  }

  printf("Result: %.2f\n", result);

  return 0;
}