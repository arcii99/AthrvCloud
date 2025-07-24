//FormAI DATASET v1.0 Category: Calculator ; Style: portable
#include <stdio.h>

int main() {
  int num1, num2, result, choice;

  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  printf("\n\nAvailable Operations:\n");
  printf("------------------------\n");
  printf("1. Addition (+)\n");
  printf("2. Subtraction (-)\n");
  printf("3. Multiplication (*)\n");
  printf("4. Division (/)\n");

  printf("Enter your choice (1-4): ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      result = num1 + num2;
      printf("The result of %d + %d is: %d\n", num1, num2, result);
      break;
    case 2:
      result = num1 - num2;
      printf("The result of %d - %d is: %d\n", num1, num2, result);
      break;
    case 3:
      result = num1 * num2;
      printf("The result of %d * %d is: %d\n", num1, num2, result);
      break;
    case 4:
      if(num2 == 0) {
        printf("Error: Cannot divide by zero\n");
      }
      else {
        result = num1 / num2;
        printf("The result of %d / %d is: %d\n", num1, num2, result);
      }
      break;
    default:
      printf("Error: Invalid operation selected\n");
  }

  return 0;
}