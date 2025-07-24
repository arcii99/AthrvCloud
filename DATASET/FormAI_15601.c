//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: high level of detail
#include <stdio.h>
#include <math.h> // Required for mathematical functions like sin, cos, tan, etc.

int main() {
  char operator;
  double num1, num2;

  printf("Welcome to the Scientific Calculator!\n");
  printf("Enter an operator (+, -, *, /, ^, s, c, t): ");
  scanf("%c", &operator);

  switch (operator) {
    case '+':
      printf("Please enter two numbers to add: ");
      scanf("%lf %lf", &num1, &num2);
      printf("%.2lf + %.2lf = %.2lf", num1, num2, num1 + num2);
      break;
    case '-':
      printf("Please enter two numbers to subtract: ");
      scanf("%lf %lf", &num1, &num2);
      printf("%.2lf - %.2lf = %.2lf", num1, num2, num1 - num2);
      break;
    case '*':
      printf("Please enter two numbers to multiply: ");
      scanf("%lf %lf", &num1, &num2);
      printf("%.2lf * %.2lf = %.2lf", num1, num2, num1 * num2);
      break;
    case '/':
      printf("Please enter two numbers to divide: ");
      scanf("%lf %lf", &num1, &num2);
      if (num2 == 0) {
        printf("Divide by Zero Error!");
      } else {
        printf("%.2lf / %.2lf = %.2lf", num1, num2, num1 / num2);
      }
      break;
    case '^':
      printf("Please enter two numbers to find power (base, exponent): ");
      scanf("%lf %lf", &num1, &num2);
      printf("%.2lf ^ %.2lf = %.2lf", num1, num2, pow(num1, num2));
      break;
    case 's':
      printf("Please enter a number to find its sine (in radians): ");
      scanf("%lf", &num1);
      printf("sin(%.2lf) = %.2lf", num1, sin(num1));
      break;
    case 'c':
      printf("Please enter a number to find its cosine (in radians): ");
      scanf("%lf", &num1);
      printf("cos(%.2lf) = %.2lf", num1, cos(num1));
      break;
    case 't':
      printf("Please enter a number to find its tangent (in radians): ");
      scanf("%lf", &num1);
      printf("tan(%.2lf) = %.2lf", num1, tan(num1));
      break;
    default:
      printf("Invalid operator");
  }

  return 0;
}