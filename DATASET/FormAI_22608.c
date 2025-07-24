//FormAI DATASET v1.0 Category: Error handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2, result;

  printf("Enter the first number: ");
  if (scanf("%d", &num1) != 1) { // Error handling for invalid input
    printf("Invalid input. Please enter an integer.\n");
    exit(1); // Exit program with error code 1
  }

  printf("Enter the second number: ");
  if (scanf("%d", &num2) != 1) {
    printf("Invalid input. Please enter an integer.\n");
    exit(1);
  }

  if (num2 == 0) { // Error handling for division by zero
    printf("Error: Attempting to divide by zero.\n");
    exit(1);
  }

  result = num1 / num2;
  printf("%d divided by %d is %d\n", num1, num2, result);

  return 0;
}