//FormAI DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables for user input and calculations
  int num1, num2, operation, result;

  // Print welcome message and accept user inputs
  printf("Welcome to the C Calculator.\n");
  printf("Enter the first number: ");
  scanf("%d", &num1);
  printf("Enter the second number: ");
  scanf("%d", &num2);

  // Display menu of operations and accept user selection
  printf("\nSelect an operation:\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("Enter the operation number: ");
  scanf("%d", &operation);

  // Perform the selected operation and store the result
  switch(operation) {
    case 1:
      result = num1 + num2;
      break;
    case 2:
      result = num1 - num2;
      break;
    case 3:
      result = num1 * num2;
      break;
    case 4:
      result = num1 / num2;
      break;
    default:
      printf("Invalid operation number. Please run the program again.\n");
      exit(0);
  }

  // Display the result to the user
  printf("\nThe result is: %d\n", result);

  return 0;
}