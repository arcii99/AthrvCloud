//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: automated
#include <stdio.h>
#include <math.h>

int main() {
  char operator;
  double num1, num2, result;

  printf("Enter an operator (+, -, *, /, ^, s): ");
  scanf("%c", &operator);
  printf("\nEnter two operands: ");
  scanf("%lf %lf", &num1, &num2);

  switch(operator) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      result = num1 / num2;
      break;
    case '^':
      result = pow(num1, num2);
      break;
    case 's':
      result = sqrt(num1);
      break;
    default:
      printf("Invalid operator");
      return 1;
  }

  printf("%lf %c %lf = %lf", num1, operator, num2, result);
  return 0;
}