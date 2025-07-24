//FormAI DATASET v1.0 Category: Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  double num1, num2;
  int choice;

  printf("Welcome to the calculator program!\n\n");

  printf("Please enter the first number: ");
  scanf("%lf", &num1);

  printf("Please enter the second number: ");
  scanf("%lf", &num2);

  printf("\nHere are the available operations:\n");
  printf("\t1. Addition\n");
  printf("\t2. Subtraction\n");
  printf("\t3. Multiplication\n");
  printf("\t4. Division\n");
  printf("\t5. Exponentiation\n");
  printf("\t6. Square root\n\n");

  printf("Please enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("\nThe sum of %.2lf and %.2lf is: %.2lf\n", num1, num2, num1 + num2);
      break;
    case 2:
      printf("\nThe difference between %.2lf and %.2lf is: %.2lf\n", num1, num2, num1 - num2);
      break;
    case 3:
      printf("\nThe product of %.2lf and %.2lf is: %.2lf\n", num1, num2, num1 * num2);
      break;
    case 4:
      if (num2 == 0) {
        printf("\nError: division by zero is undefined.\n");
      } else {
        printf("\nThe quotient of %.2lf and %.2lf is: %.2lf\n", num1, num2, num1 / num2);
      }
      break;
    case 5:
      printf("\n%lf raised to the power of %lf is: %lf\n", num1, num2, pow(num1, num2));
      break;
    case 6:
      if (num1 < 0) {
        printf("\nError: cannot find the square root of a negative number.\n");
      } else {
        printf("\nThe square root of %.2lf is: %.2lf\n", num1, sqrt(num1));
      }
      break;
    default:
      printf("\nError: invalid option is selected.\n");
      break;
  }

  printf("\nThank you for using the calculator program!\n");

  return 0;
}