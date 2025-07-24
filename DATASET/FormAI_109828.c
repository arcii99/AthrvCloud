//FormAI DATASET v1.0 Category: Educational ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int num1, num2, operation, result;

  printf("Welcome to the Turing Calculator!\n");
  printf("Please enter the first number: ");
  scanf("%d", &num1);
  printf("Please enter the second number: ");
  scanf("%d", &num2);

  printf("\nPlease select an operation:\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("Your choice: ");
  scanf("%d", &operation);

  switch(operation) {
    case 1:
      printf("\n%d + %d = %d\n", num1, num2, num1 + num2);
      break;
    case 2:
      printf("\n%d - %d = %d\n", num1, num2, num1 - num2);
      break;
    case 3:
      printf("\n%d x %d = %d\n", num1, num2, num1 * num2);
      break;
    case 4:
      if (num2 == 0) {
        printf("\nError: Cannot divide by zero!\n");
        return 0;
      } else {
        printf("\n%d / %d = %d\n", num1, num2, num1 / num2);
        break;
      }
    default:
      printf("\nError: Invalid operation!\n");
      return 0;
  }

  printf("\nThank you for using the Turing Calculator!\n");
  return 0;
}