//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: peaceful
#include <stdio.h>
#include <math.h>

int main() {
  float x, y, result;
  char operator;

  printf("Welcome to the peaceful scientific calculator.\n");
  printf("Please enter an operator (+, -, *, /, ^, s, c, t, l, r): ");
  scanf("%c", &operator);

  switch(operator) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
      printf("Enter the first number: ");
      scanf("%f", &x);
      printf("Enter the second number: ");
      scanf("%f", &y);
      break;
      
    case 's':
    case 'c':
    case 't':
    case 'l':
    case 'r':
      printf("Enter the number: ");
      scanf("%f", &x);
      break;

    default:
      printf("Invalid operator.\n");
      return 1;
  }

  switch(operator) {
    case '+':
      result = x + y;
      printf("The sum of %.2f and %.2f is %.2f.\n", x, y, result);
      break;

    case '-':
      result = x - y;
      printf("The difference between %.2f and %.2f is %.2f.\n", x, y, result);
      break;

    case '*':
      result = x * y;
      printf("The product of %.2f and %.2f is %.2f.\n", x, y, result);
      break;

    case '/':
      if (y == 0) {
        printf("Division by zero is undefined.\n");
        return 1;
      }
      result = x / y;
      printf("%.2f divided by %.2f is %.2f.\n", x, y, result);
      break;

    case '^':
      result = pow(x, y);
      printf("%.2f raised to the power of %.2f is %.2f.\n", x, y, result);
      break;

    case 's':
      result = sin(x);
      printf("The sine of %.2f is %.2f.\n", x, result);
      break;

    case 'c':
      result = cos(x);
      printf("The cosine of %.2f is %.2f.\n", x, result);
      break;

    case 't':
      result = tan(x);
      printf("The tangent of %.2f is %.2f.\n", x, result);
      break;

    case 'l':
      result = log(x);
      printf("The natural logarithm of %.2f is %.2f.\n", x, result);
      break;

    case 'r':
      result = sqrt(x);
      printf("The square root of %.2f is %.2f.\n", x, result);
      break;
  }

  printf("Thank you for using the peaceful scientific calculator!\n");
  return 0;
}