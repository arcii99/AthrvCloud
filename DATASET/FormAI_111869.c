//FormAI DATASET v1.0 Category: Arithmetic ; Style: relaxed
#include <stdio.h>

int main(void) {
  int num1, num2, result;
  char operator;

  printf("Welcome to the arithmetic calculator!\n");

  printf("Please enter the first integer: ");
  scanf("%d", &num1);

  printf("Please enter the operator (+, -, *, /): ");
  scanf(" %c", &operator);

  printf("Please enter the second integer: ");
  scanf("%d", &num2);

  if(operator == '+') {
    result = num1 + num2;
    printf("%d + %d = %d\n", num1, num2, result);
  }
  else if(operator == '-') {
    result = num1 - num2;
    printf("%d - %d = %d\n", num1, num2, result);
  }
  else if(operator == '*') {
    result = num1 * num2;
    printf("%d * %d = %d\n", num1, num2, result);
  }
  else if(operator == '/') {
    if(num2 == 0) {
      printf("Error! Divide by zero is not allowed.\n");
      return 0;
    }
    result = num1 / num2;
    printf("%d / %d = %d\n", num1, num2, result);
  }
  else {
    printf("Error! Operator not recognized.\n");
    return 0;
  }

  printf("Thank you for using the calculator!\n");

  return 0;
}