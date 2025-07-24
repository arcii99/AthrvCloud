//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  printf("Welcome to the Scientific Calculator!\n");

  int operation;
  double num1, num2, result;

  printf("Select an operation:\n");
  printf("1. Addition (+)\n");
  printf("2. Subtraction (-)\n");
  printf("3. Multiplication (*)\n");
  printf("4. Division (/)\n");
  printf("5. Exponentiation (^)\n");
  printf("6. Square Root (√)\n");
  printf("7. Logarithm (log)\n");
  printf("8. Absolute Value (|x|)\n");
  printf("9. Exit Calculator\n");

  printf("Enter your choice of operation: ");
  scanf("%d", &operation);

  while (operation != 9) {
    switch(operation) {
      case 1:
        printf("Enter the first number: ");
        scanf("%lf", &num1);
        printf("Enter the second number: ");
        scanf("%lf", &num2);
        result = num1 + num2;
        printf("Result: %lf\n\n", result);
        break;

      case 2:
        printf("Enter the first number: ");
        scanf("%lf", &num1);
        printf("Enter the second number: ");
        scanf("%lf", &num2);
        result = num1 - num2;
        printf("Result: %lf\n\n", result);
        break;

      case 3:
        printf("Enter the first number: ");
        scanf("%lf", &num1);
        printf("Enter the second number: ");
        scanf("%lf", &num2);
        result = num1 * num2;
        printf("Result: %lf\n\n", result);
        break;

      case 4:
        printf("Enter the first number: ");
        scanf("%lf", &num1);
        printf("Enter the second number: ");
        scanf("%lf", &num2);
        result = num1 / num2;
        printf("Result: %lf\n\n", result);
        break;

      case 5:
        printf("Enter the base: ");
        scanf("%lf", &num1);
        printf("Enter the exponent: ");
        scanf("%lf", &num2);
        result = pow(num1, num2);
        printf("Result: %lf\n\n", result);
        break;

      case 6:
        printf("Enter the number to find the square root of: ");
        scanf("%lf", &num1);
        result = sqrt(num1);
        printf("Result: %lf\n\n", result);
        break;

      case 7:
        printf("Enter the number to find the logarithm of: ");
        scanf("%lf", &num1);
        result = log(num1);
        printf("Result: %lf\n\n", result);
        break;

      case 8:
        printf("Enter the number to find the absolute value of: ");
        scanf("%lf", &num1);
        result = fabs(num1);
        printf("Result: %lf\n\n", result);
        break;

      default:
        printf("Invalid input.\n");
        break;
    }

    printf("Select an operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Exponentiation (^)\n");
    printf("6. Square Root (√)\n");
    printf("7. Logarithm (log)\n");
    printf("8. Absolute Value (|x|)\n");
    printf("9. Exit Calculator\n");

    printf("Enter your choice of operation: ");
    scanf("%d", &operation);
  }

  printf("Thank you for using the Scientific Calculator!\n");

  return 0;
}