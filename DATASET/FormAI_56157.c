//FormAI DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int num1, num2;
  char op;

  printf("Enter two numbers separated by a space: ");
  scanf("%d %d", &num1, &num2);

  printf("\nEnter an operator (+, -, *, /): ");
  scanf(" %c", &op);

  switch (op) {
    case '+':
      printf("The sum of %d and %d is %d", num1, num2, num1 + num2);
      break;
    case '-':
      printf("The difference between %d and %d is %d", num1, num2, num1 - num2);
      break;
    case '*':
      printf("The product of %d and %d is %d", num1, num2, num1 * num2);
      break;
    case '/':
      if (num2 == 0) {
        printf("Error: Cannot divide by zero");
      } else {
        printf("The quotient of %d and %d is %d with a remainder of %d", num1, num2, num1 / num2, num1 % num2);
      }
      break;
    default:
      printf("Invalid operator");
  }

  return(EXIT_SUCCESS);
}