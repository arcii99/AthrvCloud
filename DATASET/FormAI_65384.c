//FormAI DATASET v1.0 Category: Arithmetic ; Style: minimalist
#include<stdio.h>

int main() {
  // Declare variables
  int num1, num2, result, choice;

  // Display menu options
  printf("MENU OPTIONS: \n");
  printf("1. Add\n");
  printf("2. Subtract\n");
  printf("3. Multiply\n");
  printf("4. Divide\n");
  printf("Enter your choice: ");

  // Take input for choice
  scanf("%d", &choice);

  // Prompt for input of two numbers
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  // Perform operation based on choice
  switch(choice) {
    case 1:
      result = num1 + num2;
      printf("Addition of %d and %d is: %d\n", num1, num2, result);
      break;
    case 2:
      result = num1 - num2;
      printf("Subtraction of %d from %d is: %d\n", num2, num1, result);
      break;
    case 3:
      result = num1 * num2;
      printf("Multiplication of %d and %d is: %d\n", num1, num2, result);
      break;
    case 4:
      result = num1 / num2;
      printf("Division of %d by %d is: %d\n", num1, num2, result);
      break;
    default:
      printf("Invalid choice!\n");
  }

  return 0;
}