//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
// C Scientific Calculator Implementation

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int choice;
  float result, num1, num2, base, exponent;

  printf("*** Welcome to the Expert Scientific Calculator ***\n");

  while (1) {
    printf("\nPlease choose an operation (1-6):\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n"); 
    printf("6. Square root\n");
    printf("7. Exit");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nEnter two numbers to add: ");
        scanf("%f %f", &num1, &num2);
        result = num1 + num2;
        printf("The sum of %.2f and %.2f is %.2f.\n", num1, num2, result);
        break;

      case 2:
        printf("\nEnter two numbers to subtract: ");
        scanf("%f %f", &num1, &num2);
        result = num1 - num2;
        printf("The difference between %.2f and %.2f is %.2f.\n", num1, num2, result);
        break;

      case 3:
        printf("\nEnter two numbers to multiply: ");
        scanf("%f %f", &num1, &num2);
        result = num1 * num2;
        printf("The product of %.2f and %.2f is %.2f.\n", num1, num2, result);
        break;

      case 4:
        printf("\nEnter two numbers to divide: ");
        scanf("%f %f", &num1, &num2);
        if (num2 == 0) {
          printf("Error: division by zero.\n");
        } else {
          result = num1 / num2;
          printf("The quotient of %.2f and %.2f is %.2f.\n", num1, num2, result);
        }
        break;

      case 5:
        printf("\nEnter a base number: ");
        scanf("%f", &base);
        printf("\nEnter an exponent number: ");
        scanf("%f", &exponent);
        result = pow(base, exponent);
        printf("%.2f to the power of %.2f is %.2f.\n", base, exponent, result);
        break;

      case 6:
        printf("\nEnter a number to find its square root: ");
        scanf("%f", &num1);
        if (num1 < 0) {
          printf("Error: square root of negative number.\n");
        } else {
          result = sqrt(num1);
          printf("The square root of %.2f is %.2f.\n", num1, result);
        }
        break;

      case 7:
        printf("\nThank you for using the Expert Scientific Calculator.\n");
        exit(0);
        break;

      default:
        printf("Error: invalid choice.\n");
    }
  }

  return 0;
}