//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
  int choice;
  double num1, num2, result;

  printf("Welcome to the Scientific Calculator\n");
  printf("Please choose an operation:\n");
  printf("1. Addition (+)\n");
  printf("2. Subtraction (-)\n");
  printf("3. Multiplication (*)\n");
  printf("4. Division (/)\n");
  printf("5. Power (^)\n");
  printf("6. Square Root (√)\n");
  printf("7. Sine (sin)\n");
  printf("8. Cosine (cos)\n");
  printf("9. Tangent (tan)\n");

  scanf("%d",&choice);

  switch(choice) {
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
      if(num2 != 0) {
        result = num1 / num2;
        printf("Result: %lf\n", result);
      }
      else {
        printf("Error: Divide by zero\n");
      }
      break;

    case 5:
      printf("Enter base: ");
      scanf("%lf", &num1);
      printf("Enter power: ");
      scanf("%lf", &num2);
      result = pow(num1, num2);
      printf("Result: %lf\n", result);
      break;

    case 6:
      printf("Enter a positive number: ");
      scanf("%lf", &num1);
      if(num1 >= 0) {
        result = sqrt(num1);
        printf("Result: %lf\n", result);
      }
      else {
        printf("Error: Cannot find square root of a negative number\n");
      }
      break;

    case 7:
      printf("Enter angle in radians: ");
      scanf("%lf", &num1);
      result = sin(num1);
      printf("Result: %lf\n", result);
      break;

    case 8:
      printf("Enter angle in radians: ");
      scanf("%lf", &num1);
      result = cos(num1);
      printf("Result: %lf\n", result);
      break;

    case 9:
      printf("Enter angle in radians: ");
      scanf("%lf", &num1);
      result = tan(num1);
      printf("Result: %lf\n", result);
      break;

    default:
      printf("Invalid Choice\n");
      break;
  }

  return 0;
}