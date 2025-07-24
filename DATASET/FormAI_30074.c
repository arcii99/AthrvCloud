//FormAI DATASET v1.0 Category: Syntax parsing ; Style: visionary
#include <stdio.h>

int main() {
  int input1, input2;
  char operator;

  printf("Enter first number: ");
  scanf("%d", &input1);
  printf("Enter second number: ");
  scanf("%d", &input2);
  printf("Enter an operator (+, -, *, /): ");
  scanf(" %c", &operator);

  if (operator == '+') {
    printf("%d + %d = %d", input1, input2, input1 + input2);
  } else if (operator == '-') {
    printf("%d - %d = %d", input1, input2, input1 - input2);
  } else if (operator == '*') {
    printf("%d * %d = %d", input1, input2, input1 * input2);
  } else if (operator == '/') {
    // check if division by zero
    if (input2 == 0) {
      printf("Error: Division by zero");
    } else {
      printf("%d / %d = %d", input1, input2, input1 / input2);
    }
  } else {
    printf("Error: Invalid operator");
  }

  return 0;
}