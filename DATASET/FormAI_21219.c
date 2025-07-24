//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Donald Knuth
/* Donald Knuth style Scientific Calculator Implementation */

#include <stdio.h>
#include <math.h>

int main() {
  double num1, num2, result;
  int choice;

  printf("Welcome to the Donald Knuth Style Scientific Calculator\n\n");

  printf("Please select an operation to perform:\n");
  printf("1. Addition (+)\n");
  printf("2. Subtraction (-)\n");
  printf("3. Multiplication (*)\n");
  printf("4. Division (/)\n");
  printf("5. Square Root (√)\n");
  printf("6. Exponentiation (x^y)\n");
  printf("7. Logarithm (log)\n");
  printf("8. Sine (sin)\n");
  printf("9. Cosine (cos)\n");
  printf("10. Tangent (tan)\n");

  printf("\nEnter your choice (1-10): ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("\nEnter the first number: ");
      scanf("%lf", &num1);
      printf("\nEnter the second number: ");
      scanf("%lf", &num2);
      result = num1 + num2;
      printf("\nResult: %.2lf\n", result);
      break;

    case 2:
      printf("\nEnter the first number: ");
      scanf("%lf", &num1);
      printf("\nEnter the second number: ");
      scanf("%lf", &num2);
      result = num1 - num2;
      printf("\nResult: %.2lf\n", result);
      break;

    case 3:
      printf("\nEnter the first number: ");
      scanf("%lf", &num1);
      printf("\nEnter the second number: ");
      scanf("%lf", &num2);
      result = num1 * num2;
      printf("\nResult: %.2lf\n", result);
      break;

    case 4:
      printf("\nEnter the numerator: ");
      scanf("%lf", &num1);
      printf("\nEnter the denominator: ");
      scanf("%lf", &num2);
      if(num2 == 0) {
        printf("\nCannot divide by zero. Retry with a non-zero denominator.\n");
        break;
      }
      result = num1 / num2;
      printf("\nResult: %.2lf\n", result);
      break;

    case 5:
      printf("\nEnter the number: ");
      scanf("%lf", &num1);
      if(num1 < 0) {
        printf("\nCannot find square root of a negative number.\n");
        break;
      }
      result = sqrt(num1);
      printf("\nResult: %.2lf\n", result);
      break;

    case 6:
      printf("\nEnter the base number: ");
      scanf("%lf", &num1);
      printf("\nEnter the exponent: ");
      scanf("%lf", &num2);
      result = pow(num1, num2);
      printf("\nResult: %.2lf\n", result);
      break;

    case 7:
      printf("\nEnter the number: ");
      scanf("%lf", &num1);
      if(num1 <= 0) {
        printf("\nCannot find logarithm of zero or a negative number.\n");
        break;
      }
      result = log(num1);
      printf("\nResult: %.2lf\n", result);
      break;

    case 8:
      printf("\nEnter the angle in radians: ");
      scanf("%lf", &num1);
      result = sin(num1);
      printf("\nResult: %.2lf\n", result);
      break;

    case 9:
      printf("\nEnter the angle in radians: ");
      scanf("%lf", &num1);
      result = cos(num1);
      printf("\nResult: %.2lf\n", result);
      break;

    case 10:
      printf("\nEnter the angle in radians: ");
      scanf("%lf", &num1);
      result = tan(num1);
      printf("\nResult: %.2lf\n", result);
      break;

    default:
      printf("\nInvalid choice. Please choose from 1-10.\n");
  }

  printf("\nThank you for using the Donald Knuth Style Scientific Calculator.\n");

  return 0;
}