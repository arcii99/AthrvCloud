//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: thoughtful
#include <stdio.h>
#include <math.h>

// Function to add two numbers
double add(double x, double y) {
  return x + y;
}

// Function to subtract two numbers
double subtract(double x, double y) {
  return x - y;
}

// Function to multiply two numbers
double multiply(double x, double y) {
  return x * y;
}

// Function to divide two numbers
double divide(double x, double y) {
  return x / y;
}

// Function to calculate power of a number
double power(double x, double y) {
  return pow(x, y);
}

int main() {
  // Variables to hold the user input values
  double num1, num2;

  // Variable to hold the user selected operation
  char operation;

  // Ask user for input values
  printf("Enter first number: ");
  scanf("%lf", &num1);

  printf("Enter second number: ");
  scanf("%lf", &num2);

  // Ask user for operation
  printf("Select operation (+, -, *, /, p): ");
  scanf(" %c", &operation);

  // Perform operation based on user input
  double result;
  switch (operation) {
    case '+':
      result = add(num1, num2);
      break;

    case '-':
      result = subtract(num1, num2);
      break;

    case '*':
      result = multiply(num1, num2);
      break;

    case '/':
      if (num2 == 0) {
        printf("Error: Division by zero\n");
        return 1;
      }
      result = divide(num1, num2);
      break;

    case 'p':
      result = power(num1, num2);
      break;

    default:
      printf("Error: Invalid operator\n");
      return 1;
  }

  // Print the result
  printf("%.2lf %c %.2lf = %.2lf\n", num1, operation, num2, result);

  return 0;
}