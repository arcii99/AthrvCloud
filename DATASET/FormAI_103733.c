//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scientific
#include <stdio.h>
#include <math.h>

int main() {
  char operator;
  double num1, num2, result;

  printf("Welcome to the Scientific Calculator.\n\n");
  printf("Please enter an operator (+, -, *, /, ^, s, c, t, l, e): ");
  scanf("%c", &operator);

  switch(operator) {

    case '+':
      printf("Enter two numbers separated by a space: ");
      scanf("%lf %lf", &num1, &num2);
      result = num1 + num2;
      printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
      break;

    case '-':
      printf("Enter two numbers separated by a space: ");
      scanf("%lf %lf", &num1, &num2);
      result = num1 - num2;
      printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
      break;

    case '*':
      printf("Enter two numbers separated by a space: ");
      scanf("%lf %lf", &num1, &num2);
      result = num1 * num2;
      printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
      break;

    case '/':
      printf("Enter two numbers separated by a space: ");
      scanf("%lf %lf", &num1, &num2);
      result = num1 / num2;
      printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
      break;

    case '^':
      printf("Enter two numbers separated by a space: ");
      scanf("%lf %lf", &num1, &num2);
      result = pow(num1, num2);
      printf("%.2lf ^ %.2lf = %.2lf", num1, num2, result);
      break;

    case 's':
      printf("Enter a number: ");
      scanf("%lf", &num1);
      result = sin(num1);
      printf("sin(%.2lf) = %.2lf", num1, result);
      break;

    case 'c':
      printf("Enter a number: ");
      scanf("%lf", &num1);
      result = cos(num1);
      printf("cos(%.2lf) = %.2lf", num1, result);
      break;

    case 't':
      printf("Enter a number: ");
      scanf("%lf", &num1);
      result = tan(num1);
      printf("tan(%.2lf) = %.2lf", num1, result);
      break;

    case 'l':
      printf("Enter a number: ");
      scanf("%lf", &num1);
      result = log(num1);
      printf("log(%.2lf) = %.2lf", num1, result);
      break;

    case 'e':
      printf("Enter a number: ");
      scanf("%lf", &num1);
      result = exp(num1);
      printf("e ^ %.2lf = %.2lf", num1, result);
      break;

    default:
      printf("Error: Please enter a valid operator.");
      break;
  }

  return 0;
}