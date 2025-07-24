//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: unmistakable
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main() {
  double num1, num2, result;
  int choice;

  printf("Welcome to the Scientific Calculator\n");
  printf("----------------------------------\n");
  printf("Please select an operation:\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Square root\n");
  printf("6. Exponent\n");
  printf("7. Logarithm\n");
  printf("8. Sine\n");
  printf("9. Cosine\n");
  printf("10. Tangent\n");
  printf("11. Exit\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter the first number: ");
      scanf("%lf", &num1);
      printf("Enter the second number: ");
      scanf("%lf", &num2);
      result = num1 + num2;
      printf("The sum of %lf and %lf is %lf\n", num1, num2, result);
      break;

    case 2:
      printf("Enter the first number: ");
      scanf("%lf", &num1);
      printf("Enter the second number: ");
      scanf("%lf", &num2);
      result = num1 - num2;
      printf("The difference between %lf and %lf is %lf\n", num1, num2, result);
      break;

    case 3:
      printf("Enter the first number: ");
      scanf("%lf", &num1);
      printf("Enter the second number: ");
      scanf("%lf", &num2);
      result = num1 * num2;
      printf("The product of %lf and %lf is %lf\n", num1, num2, result);
      break;

    case 4:
      printf("Enter the numerator: ");
      scanf("%lf", &num1);
      printf("Enter the denominator: ");
      scanf("%lf", &num2);
      if (num2 != 0) {
        result = num1 / num2;
        printf("%lf divided by %lf is %lf\n", num1, num2, result);
      }
      else {
        printf("Cannot divide by zero\n");
      }
      break;

    case 5:
      printf("Enter the number: ");
      scanf("%lf", &num1);
      result = sqrt(num1);
      printf("The square root of %lf is %lf\n", num1, result);
      break;

    case 6:
      printf("Enter the base: ");
      scanf("%lf", &num1);
      printf("Enter the exponent: ");
      scanf("%lf", &num2);
      result = pow(num1, num2);
      printf("%lf raised to the power of %lf is %lf\n", num1, num2, result);
      break;

    case 7:
      printf("Enter the number: ");
      scanf("%lf", &num1);
      if (num1 > 0) {
        result = log10(num1);
        printf("The logarithm of %lf is %lf\n", num1, result);
      }
      else {
        printf("Cannot take logarithm of zero or negative numbers\n");
      }
      break;

    case 8:
      printf("Enter the angle in degrees: ");
      scanf("%lf", &num1);
      result = sin(num1 * PI / 180);
      printf("The sine of %lf degrees is %lf\n", num1, result);
      break;

    case 9:
      printf("Enter the angle in degrees: ");
      scanf("%lf", &num1);
      result = cos(num1 * PI / 180);
      printf("The cosine of %lf degrees is %lf\n", num1, result);
      break;

    case 10:
      printf("Enter the angle in degrees: ");
      scanf("%lf", &num1);
      result = tan(num1 * PI / 180);
      printf("The tangent of %lf degrees is %lf\n", num1, result);
      break;

    case 11:
      printf("Exiting the calculator...\n");
      break;

    default:
      printf("Invalid choice\n");
      break;
  }

  return 0;
}