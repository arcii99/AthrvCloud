//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  printf("Welcome to the Surreal Scientific Calculator!\n");
  printf("Enter your operation:\n");

  char operation;
  scanf("%c", &operation);

  double num1, num2, result;

  switch (operation) {

    case '+':
      printf("Addition! Enter two numbers:\n");
      scanf("%lf %lf", &num1, &num2);
      result = num1 + num2;
      printf("The sum of %lf and %lf is %lf\n", num1, num2, result);
      break;

    case '-':
      printf("Subtraction! Enter two numbers:\n");
      scanf("%lf %lf", &num1, &num2);
      result = num1 - num2;
      printf("The difference between %lf and %lf is %lf\n", num1, num2, result);
      break;

    case '*':
      printf("Multiplication! Enter two numbers:\n");
      scanf("%lf %lf", &num1, &num2);
      result = num1 * num2;
      printf("The product of %lf and %lf is %lf\n", num1, num2, result);
      break;

    case '/':
      printf("Division! Enter two numbers:\n");
      scanf("%lf %lf", &num1, &num2);
      if (num2 == 0) {
        printf("Oops! Division by zero not possible.\n");
      } else {
        result = num1 / num2;
        printf("The quotient of %lf and %lf is %lf\n", num1, num2, result);
      }
      break;

    case '^':
      printf("Exponentiation! Enter two numbers:\n");
      scanf("%lf %lf", &num1, &num2);
      result = pow(num1, num2);
      printf("%lf raised to the power of %lf is %lf\n", num1, num2, result);
      break;

    case 'r':
      printf("Roots! Enter a number:\n");
      scanf("%lf", &num1);
      if (num1 < 0) {
        printf("Oops! Cannot take square root of a negative number.\n");
      } else {
        result = sqrt(num1);
        printf("The square root of %lf is %lf\n", num1, result);
      }
      break;

    case 's':
      printf("Sine! Enter an angle in degrees:\n");
      scanf("%lf", &num1);
      result = sin(num1 * M_PI / 180);
      printf("The sine of %lf degrees is %lf\n", num1, result);
      break;

    case 'c':
      printf("Cosine! Enter an angle in degrees:\n");
      scanf("%lf", &num1);
      result = cos(num1 * M_PI / 180);
      printf("The cosine of %lf degrees is %lf\n", num1, result);
      break;

    case 't':
      printf("Tangent! Enter an angle in degrees:\n");
      scanf("%lf", &num1);
      result = tan(num1 * M_PI / 180);
      printf("The tangent of %lf degrees is %lf\n", num1, result);
      break;

    default:
      printf("Invalid operation!\n");

  }

  return 0;

}