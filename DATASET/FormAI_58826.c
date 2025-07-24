//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

int main() {
  double num1, num2;
  char op;

  printf("Enter the first number: ");
  scanf("%lf", &num1);
  printf("Enter the operator (+, -, *, /, ^, s, c, t, l, q): ");
  scanf(" %c", &op);

  if (op == 's' || op == 'c' || op == 't' || op == 'l' || op == 'q') {
    switch(op) {
      case 's':
        printf("sin(%.2lf) = %.2lf", num1, sin(num1));
        break;
      case 'c':
        printf("cos(%.2lf) = %.2lf", num1, cos(num1));
        break;
      case 't':
        printf("tan(%.2lf) = %.2lf", num1, tan(num1));
        break;
      case 'l':
        printf("log(%.2lf) = %.2lf", num1, log10(num1));
        break;
      case 'q':
        printf("sqrt(%.2lf) = %.2lf", num1, sqrt(num1));
        break;
    }
  } else {
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch(op) {
      case '+':
        printf("%.2lf + %.2lf = %.2lf", num1, num2, num1 + num2);
        break;
      case '-':
        printf("%.2lf - %.2lf = %.2lf", num1, num2, num1 - num2);
        break;
      case '*':
        printf("%.2lf * %.2lf = %.2lf", num1, num2, num1 * num2);
        break;
      case '/':
        if (num2 == 0) {
          printf("Cannot divide by zero");
        } else {
          printf("%.2lf / %.2lf = %.2lf", num1, num2, num1 / num2);
        }
        break;
      case '^':
        printf("%.2lf ^ %.2lf = %.2lf", num1, num2, pow(num1, num2));
        break;
      default:
        printf("Invalid operator");
    }
  }

  return 0;
}