//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: brave
// Brave style implementation of a scientific calculator in C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265  // Define the value of PI

int main() {
  double firstNumber, secondNumber, result;
  int choice;

  printf("Welcome to the Brave Style Scientific Calculator in C\n");

  // Display the options to the user
  printf("Enter 1 for Addition (+)\n");
  printf("Enter 2 for Subtraction (-)\n");
  printf("Enter 3 for Multiplication (*)\n");
  printf("Enter 4 for Division (/)\n");
  printf("Enter 5 for Modulus (%%)\n");
  printf("Enter 6 for Square Root (√)\n");  
  printf("Enter 7 for Power (^)\n");
  printf("Enter 8 for Sine (sin)\n");
  printf("Enter 9 for Cosine (cos)\n");
  printf("Enter 10 for Tangent (tan)\n");

  printf("Please enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("You have selected Addition (+)\n");
      printf("Enter the first number: ");
      scanf("%lf", &firstNumber);
      printf("Enter the second number: ");
      scanf("%lf", &secondNumber);
      result = firstNumber + secondNumber;
      printf("%.2lf + %.2lf = %.2lf\n", firstNumber, secondNumber, result);
      break;

    case 2:
      printf("You have selected Subtraction (-)\n");
      printf("Enter the first number: ");
      scanf("%lf", &firstNumber);
      printf("Enter the second number: ");
      scanf("%lf", &secondNumber);
      result = firstNumber - secondNumber;
      printf("%.2lf - %.2lf = %.2lf\n", firstNumber, secondNumber, result);
      break;

    case 3:
      printf("You have selected Multiplication (*)\n");
      printf("Enter the first number: ");
      scanf("%lf", &firstNumber);
      printf("Enter the second number: ");
      scanf("%lf", &secondNumber);
      result = firstNumber * secondNumber;
      printf("%.2lf * %.2lf = %.2lf\n", firstNumber, secondNumber, result);
      break;

    case 4:
      printf("You have selected Division (/)\n");
      printf("Enter the first number: ");
      scanf("%lf", &firstNumber);
      printf("Enter the second number: ");
      scanf("%lf", &secondNumber);
      if (secondNumber == 0) {
        printf("Error: Division by zero is not possible.\n");
      } else {
        result = firstNumber / secondNumber;
        printf("%.2lf / %.2lf = %.2lf\n", firstNumber, secondNumber, result);
      }
      break;

    case 5:
      printf("You have selected Modulus (%%)\n");
      printf("Enter the first number: ");
      scanf("%lf", &firstNumber);
      printf("Enter the second number: ");
      scanf("%lf", &secondNumber);
      result = (int) firstNumber % (int) secondNumber;
      printf("%.2lf %% %.2lf = %.2lf\n", firstNumber, secondNumber, result);
      break;

    case 6:
      printf("You have selected Square Root (√)\n");
      printf("Enter a number: ");
      scanf("%lf", &firstNumber);
      if (firstNumber < 0) {
        printf("Error: Square root of a negative number is not possible.\n");
      } else {
        result = sqrt(firstNumber);
        printf("The square root of %.2lf is %.2lf\n", firstNumber, result);
      }
      break;

    case 7:
      printf("You have selected Power (^)\n");
      printf("Enter the base number: ");
      scanf("%lf", &firstNumber);
      printf("Enter the exponent: ");
      scanf("%lf", &secondNumber);
      result = pow(firstNumber, secondNumber);
      printf("%.2lf ^ %.2lf = %.2lf\n", firstNumber, secondNumber, result);
      break;

    case 8:
      printf("You have selected Sine (sin)\n");
      printf("Enter an angle in degrees: ");
      scanf("%lf", &firstNumber);
      result = sin(firstNumber * PI / 180);
      printf("sin(%.2lf) = %.2lf\n", firstNumber, result);
      break;

    case 9:
      printf("You have selected Cosine (cos)\n");
      printf("Enter an angle in degrees: ");
      scanf("%lf", &firstNumber);
      result = cos(firstNumber * PI / 180);
      printf("cos(%.2lf) = %.2lf\n", firstNumber, result);
      break;

    case 10:
      printf("You have selected Tangent (tan)\n");
      printf("Enter an angle in degrees: ");
      scanf("%lf", &firstNumber);
      result = tan(firstNumber * PI / 180);
      printf("tan(%.2lf) = %.2lf\n", firstNumber, result);
      break;

    default:
      printf("Error: Invalid choice\n");
  }

  return 0;
}