//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform addition
double add(double num1, double num2) {
  return num1 + num2;
}

// Function to perform subtraction
double subtract(double num1, double num2) {
  return num1 - num2;
}

// Function to perform multiplication
double multiply(double num1, double num2) {
  return num1 * num2;
}

// Function to perform division
double divide(double num1, double num2) {
  if (num2 == 0) {
    printf("Error: Division by zero\n");
    exit(0);
  }
  return num1 / num2;
}

// Function to perform power calculation
double power(double num1, double num2) {
  return pow(num1, num2);
}

// Function to perform square root calculation
double sqroot(double num) {
  if (num < 0) {
    printf("Error: Square root of negative number\n");
    exit(0);
  }
  return sqrt(num);
}

// Function to display the result
void display_result(double result) {
  printf("Result: %lf\n", result);
}

// Main function
int main() {
  int choice;
  double num1, num2, result;

  printf("Welcome to this C Scientific Calculator\n");

  // Display the available operations
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Power\n");
  printf("6. Square Root\n");
  printf("7. Exit\n");

  do {
    // Get user choice
    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // Addition
        printf("Enter two numbers to add: ");
        scanf("%lf %lf", &num1, &num2);
        result = add(num1, num2);
        display_result(result);
        break;

      case 2:
        // Subtraction
        printf("Enter two numbers to subtract: ");
        scanf("%lf %lf", &num1, &num2);
        result = subtract(num1, num2);
        display_result(result);
        break;

      case 3:
        // Multiplication
        printf("Enter two numbers to multiply: ");
        scanf("%lf %lf", &num1, &num2);
        result = multiply(num1, num2);
        display_result(result);
        break;

      case 4:
        // Division
        printf("Enter two numbers to divide: ");
        scanf("%lf %lf", &num1, &num2);
        result = divide(num1, num2);
        display_result(result);
        break;

      case 5:
        // Power
        printf("Enter a number and its power: ");
        scanf("%lf %lf", &num1, &num2);
        result = power(num1, num2);
        display_result(result);
        break;

      case 6:
        // Square root
        printf("Enter a number to find its square root: ");
        scanf("%lf", &num1);
        result = sqroot(num1);
        display_result(result);
        break;

      case 7:
        // Exit
        printf("Exiting...\n");
        exit(0);
        break;

      default:
        printf("Invalid choice\n");
        break;
    }
  } while (choice != 7);

  return 0;
}