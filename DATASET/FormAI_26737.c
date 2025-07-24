//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI (3.14159265)

// function to display menu and ask for user input
int display_menu() {
  int choice;
  printf("----Scientific Calculator Menu----\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Power\n");
  printf("6. Square Root\n");
  printf("7. Logarithm\n");
  printf("8. Sine\n");
  printf("9. Cosine\n");
  printf("10. Tangent\n");
  printf("11. Exit\n");

  printf("Enter your choice (1-11): ");
  scanf("%d", &choice);

  return choice;
}

int main() {
  int choice;
  double num1, num2, result;

  while (1) { // infinite loop until user exits
    choice = display_menu();

    switch (choice) {
      case 1:
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);
        result = num1 + num2;
        printf("Result: %lf\n", result);
        break;

      case 2:
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);
        result = num1 - num2;
        printf("Result: %lf\n", result);
        break;

      case 3:
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);
        result = num1 * num2;
        printf("Result: %lf\n", result);
        break;

      case 4:
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        if (num2 == 0) {
          printf("Error! Division by zero.\n");
        } else {
          result = num1 / num2;
          printf("Result: %lf\n", result);
        }
        break;

      case 5:
        printf("Enter base number: ");
        scanf("%lf", &num1);
        printf("Enter exponent: ");
        scanf("%lf", &num2);

        result = pow(num1, num2);
        printf("Result: %lf\n", result);
        break;

      case 6:
        printf("Enter a number: ");
        scanf("%lf", &num1);

        if (num1 < 0) {
          printf("Error! Square root of negative number not possible.\n");
        } else {
          result = sqrt(num1);
          printf("Result: %lf\n", result);
        }
        break;

      case 7:
        printf("Enter a number: ");
        scanf("%lf", &num1);

        if (num1 <= 0) {
          printf("Error! Logarithm of non-positive number not possible.\n");
        } else {
          result = log10(num1);
          printf("Result: %lf\n", result);
        }
        break;

      case 8:
        printf("Enter an angle in degrees: ");
        scanf("%lf", &num1);

        result = sin(num1 * PI / 180); // convert degrees to radians
        printf("Result: %lf\n", result);
        break;

      case 9:
        printf("Enter an angle in degrees: ");
        scanf("%lf", &num1);

        result = cos(num1 * PI / 180); // convert degrees to radians
        printf("Result: %lf\n", result);
        break;

      case 10:
        printf("Enter an angle in degrees: ");
        scanf("%lf", &num1);

        result = tan(num1 * PI / 180); // convert degrees to radians
        printf("Result: %lf\n", result);
        break;

      case 11:
        printf("Exiting calculator...\n");
        exit(0);
        break;

      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}