//FormAI DATASET v1.0 Category: Arithmetic ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int num1, num2, choice;
  float result;

  printf("Welcome to the Genius Calculator!\n");
  printf("Enter the first number: ");
  scanf("%d", &num1);
  printf("Enter the second number: ");
  scanf("%d", &num2);

  printf("Please choose an arithmetic operation:\n");
  printf("1. Addition (+)\n");
  printf("2. Subtraction (-)\n");
  printf("3. Multiplication (*)\n");
  printf("4. Division (/)\n");
  printf("5. Power (^)\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      result = num1 + num2;
      printf("%d + %d = %.2f\n", num1, num2, result);
      break;
    case 2:
      result = num1 - num2;
      printf("%d - %d = %.2f\n", num1, num2, result);
      break;
    case 3:
      result = num1 * num2;
      printf("%d * %d = %.2f\n", num1, num2, result);
      break;
    case 4:
      if (num2 == 0) {
        printf("Error: Division by zero!\n");
      } else {
        result = (float) num1 / num2;
        printf("%d / %d = %.2f\n", num1, num2, result);
      }
      break;
    case 5:
      result = pow(num1, num2);
      printf("%d ^ %d = %.2f\n", num1, num2, result);
      break;
    default:
      printf("Error: Invalid choice!\n");
  }

  printf("Thank you for using the Genius Calculator!\n");

  return 0;
}