//FormAI DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>

int main() {
  int num1, num2, result;
  char operator;

  printf("Welcome to the visionary calculator\n");
  printf("Please enter your first number: ");
  scanf("%d", &num1);
  printf("Please enter your second number: ");
  scanf("%d", &num2);
  printf("Please enter your desired arithmetic operator (+, -, *, /): ");
  scanf(" %c", &operator);

  if (operator == '+') {
    result = num1 + num2;
    printf("%d + %d = %d", num1, num2, result);
  } else if (operator == '-') {
    result = num1 - num2;
    printf("%d - %d = %d", num1, num2, result);
  } else if (operator == '*') {
    result = num1 * num2;
    printf("%d * %d = %d", num1, num2, result);
  } else if (operator == '/') {
    result = num1 / num2;
    printf("%d / %d = %d", num1, num2, result);
  } else {
    printf("Invalid operator, please try again.");
  }

  return 0;
}