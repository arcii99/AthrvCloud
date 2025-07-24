//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: innovative
#include <stdio.h>
#include <math.h>

int main() {
  printf("Welcome to the C Scientific Calculator\n");
  printf("Enter the corresponding number for the calculations you'd like to do:\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Exponents\n");
  printf("6. Square Root\n");
  printf("7. Logarithms\n");
  printf("8. Trigonometry\n");
  printf("9. Factorials\n");

  int choice;
  double num1, num2;

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter two numbers to add: ");
      scanf("%lf %lf", &num1, &num2);
      printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
      break;

    case 2:
      printf("Enter two numbers to subtract: ");
      scanf("%lf %lf", &num1, &num2);
      printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
      break;

    case 3:
      printf("Enter two numbers to multiply: ");
      scanf("%lf %lf", &num1, &num2);
      printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
      break;

    case 4:
      printf("Enter the numerator and denominator to divide: ");
      scanf("%lf %lf", &num1, &num2);
      if (num2 == 0) {
        printf("Error: cannot divide by zero\n");
      } else {
        printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
      }
      break;

    case 5:
      printf("Enter the base and exponent: ");
      scanf("%lf %lf", &num1, &num2); 
      printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, pow(num1, num2));
      break;

    case 6:
      printf("Enter a number to find the square root of: ");
      scanf("%lf", &num1);
      if (num1 < 0) {
        printf("Error: cannot find square root of negative number\n");
      } else {
        printf("The square root of %.2lf is %.2lf\n", num1, sqrt(num1));
      }
      break;

    case 7:
      printf("Enter a number to find the logarithm of (base 10): ");
      scanf("%lf", &num1);
      if (num1 < 0) {
        printf("Error: cannot find logarithm of negative number\n");
      } else {
        printf("The logarithm of %.2lf (base 10) is %.2lf\n", num1, log10(num1));
      }
      break;

    case 8:
      printf("Enter a number in degrees to find the sin, cos, and tan: ");
      scanf("%lf", &num1);
      printf("sin(%.2lf) = %.2lf\n", num1, sin(num1 * M_PI / 180));
      printf("cos(%.2lf) = %.2lf\n", num1, cos(num1 * M_PI / 180));
      printf("tan(%.2lf) = %.2lf\n", num1, tan(num1 * M_PI / 180));
      break;

    case 9:
      printf("Enter a number to find the factorial of: ");
      scanf("%lf", &num1);
      if (num1 < 0) {
        printf("Error: cannot find factorial of negative number\n");
      } else {
        double result = 1;
        for (int i = 1; i <= num1; i++) {
          result *= i;
        }
        printf("%.2lf! = %.2lf\n", num1, result);
      }
      break;

    default:
      printf("Error: invalid choice\n");
      break;
  }

  printf("Thank you for using the C Scientific Calculator\n");

  return 0;
}