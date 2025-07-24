//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: inquisitive
#include <stdio.h>
#include <math.h>

// Function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double sqrt(double);
double absolute(double);

int main() {
  int choice;
  double x, y;
  char repeat;

  do {
    // Display menu options
    printf("Welcome to the scientific calculator!\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square root\n");
    printf("7. Absolute value\n");

    // Take user input for choice and operands
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 7) {
      printf("Enter first operand: ");
      scanf("%lf", &x);

      if (choice != 6 && choice != 7) {
        printf("Enter second operand: ");
        scanf("%lf", &y);
      }

      // Call appropriate function based on user choice
      switch (choice) {
        case 1:
          printf("Result: %.2lf\n", add(x, y));
          break;
        case 2:
          printf("Result: %.2lf\n", subtract(x, y));
          break;
        case 3:
          printf("Result: %.2lf\n", multiply(x, y));
          break;
        case 4:
          if (y == 0) {
            printf("Error: Division by zero!\n");
          } else {
            printf("Result: %.2lf\n", divide(x, y));
          }
          break;
        case 5:
          printf("Result: %.2lf\n", power(x, y));
          break;
        case 6:
          printf("Result: %.2lf\n", sqrt(x));
          break;
        case 7:
          printf("Result: %.2lf\n", absolute(x));
          break;
      }

      // Prompt user to repeat
      printf("Do you want to perform another operation? (y/n): ");
      scanf(" %c", &repeat);

    } else {
      printf("Error: Invalid choice!\n");

      // Prompt user to try again
      printf("Do you want to try again? (y/n): ");
      scanf(" %c", &repeat);
    }

  } while (repeat == 'y' || repeat == 'Y');

  // Exit message
  printf("Thank you for using the scientific calculator!\n");

  return 0;
}

// Function definitions
double add(double x, double y) {
  return x + y;
}

double subtract(double x, double y) {
  return x - y;
}

double multiply(double x, double y) {
  return x * y;
}

double divide(double x, double y) {
  return x / y;
}

double power(double x, double y) {
  return pow(x, y);
}

double sqrt(double x) {
  return sqrt(x);
}

double absolute(double x) {
  return abs(x);
}