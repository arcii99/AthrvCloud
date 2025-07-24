//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scientific
#include <stdio.h>
#include <math.h>

/* This is a scientific calculator program using C */

int main() {

  char operator;
  double num1, num2, result;

  printf("Welcome to our scientific calculator.\n");

  // Loop to keep the calculator running until user decides to exit
  while (1) {

    // Ask user to input operator
    printf("\nPlease enter an operator (+, -, *, /, ^, sqrt, sin, cos, tan, log):\n");
    scanf(" %c", &operator);

    // Check if user wants to exit
    if (operator == 'Q' || operator == 'q') {
      printf("\nGoodbye! Thank you for using our calculator.\n");
      break;
    }

    // Check if operation is valid
    if (operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '^' && operator != 's' && operator != 'c' && operator != 't' && operator != 'l') {
      printf("Invalid operator. Try again.\n");
      continue;
    }

    // Ask user to input numbers for calculation
    printf("\nEnter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    // Perform calculation based on operator input
    switch (operator) {
      
      // Addition
      case '+':
        result = num1 + num2;
        printf("\nResult: %.2lf\n", result);
        break;

      // Subtraction
      case '-':
        result = num1 - num2;
        printf("\nResult: %.2lf\n", result);
        break;

      // Multiplication
      case '*':
        result = num1 * num2;
        printf("\nResult: %.2lf\n", result);
        break;

      // Division
      case '/':
        if (num2 == 0) {
          printf("Cannot divide by zero. Try again.\n");
          continue;
        }
        result = num1 / num2;
        printf("\nResult: %.2lf\n", result);
        break;

      // Exponentiation
      case '^':
        result = pow(num1, num2);
        printf("\nResult: %.2lf\n", result);
        break;

      // Square root
      case 's':
        result = sqrt(num1);
        printf("\nResult: %.2lf\n", result);
        break;

      // Sine
      case 'S':
        result = sin(num1);
        printf("\nResult: %.2lf\n", result);
        break;

      // Cosine
      case 'c':
        result = cos(num1);
        printf("\nResult: %.2lf\n", result);
        break;

      // Tangent
      case 't':
        result = tan(num1);
        printf("\nResult: %.2lf\n", result);
        break;

      // Logarithm (base e)
      case 'l':
        if (num1 <= 0) {
          printf("Invalid input. Try again.\n");
          continue;
        }
        result = log(num1);
        printf("\nResult: %.2lf\n", result);
        break;

      // Invalid operator
      default:
        printf("Invalid operator. Try again.\n");
        break;
    }   
  } 

  return 0;
}