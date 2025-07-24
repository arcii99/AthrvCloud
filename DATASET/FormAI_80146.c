//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main() {
  float num1, num2;
  int choice;
  float result;

  printf("Welcome to the C Scientific Calculator!");

  while (1) {

    printf("\n\nPlease select an operation: \n\n");
    printf("1. Addition \n2. Subtraction \n3. Multiplication \n4. Division \n5. Power \n6. Square Root \n7. Logarithm \n8. Exit\n\n");

    scanf("%d", &choice);

    if (choice == 8) {
      printf("\nThank you for using the C Scientific Calculator!\n");
      break;
    }

    if (choice >=1 && choice <= 6) {

      printf("Enter first number: ");
      scanf("%f", &num1);
      printf("Enter second number: ");
      scanf("%f", &num2);
    }
    else if (choice == 7) {
      printf("Enter number: ");
      scanf("%f", &num1);
    } 

    switch (choice) {
      case 1:
        result = num1 + num2;
        printf("\n%.2f + %.2f = %.2f\n", num1, num2, result);
        break;

      case 2:
        result = num1 - num2;
        printf("\n%.2f - %.2f = %.2f\n", num1, num2, result);
        break;

      case 3:
        result = num1 * num2;
        printf("\n%.2f x %.2f = %.2f\n", num1, num2, result);
        break;

      case 4:
        if (num2 == 0) {
          printf("Error: division by zero");
          break;
        }
        result = num1 / num2;
        printf("\n%.2f / %.2f = %.2f\n", num1, num2, result);
        break;

      case 5:
        result = pow(num1, num2);
        printf("\n%.2f ^ %.2f = %.2f\n", num1, num2, result);
        break;

      case 6:
        if (num1 < 0) {
          printf("Cannot calculate square root of negative numbers.");
          break;
        }
        result = sqrt(num1);
        printf("\nSquare Root of %.2f = %.2f\n", num1, result);
        break;

      case 7:
        if (num1 < 0) {
          printf("Cannot calculate logarithm of negative numbers.");
          break;
        }
        result = log10(num1);
        printf("\nLog of %.2f = %.2f\n", num1, result);
        break;

      default:
        printf("\nInvalid choice. Please try again.");
        break;
    }
  }

  return 0;
}