//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: realistic
#include <stdio.h>
#include <math.h>

int main(void) {
  char operation;
  double num1, num2, result;

  printf("Welcome to the Scientific Calculator! \n");
  printf("Enter your calculation in the format: num1 operator num2 \n");
  scanf("%lf %c %lf", &num1, &operation, &num2);

  switch(operation) {
    case '+':
      result = num1 + num2;
      printf("The sum is: %.2lf \n", result);
      break;
    case '-':
      result = num1 - num2;
      printf("The difference is: %.2lf \n", result);
      break;
    case '*':
      result = num1 * num2;
      printf("The product is: %.2lf \n", result);
      break;
    case '/':
      if(num2 == 0) {
        printf("Error: Division by zero is not allowed. \n");
      } else {
        result = num1 / num2;
        printf("The quotient is: %.2lf \n", result);
      }
      break;
    case '^':
      result = pow(num1, num2);
      printf("%.2lf to the power of %.2lf is: %.2lf \n", num1, num2, result);
      break;
    case 's':
      result = sin(num1);
      printf("The sine of %.2lf is: %.2lf \n", num1, result);
      break;
    case 'c':
      result = cos(num1);
      printf("The cosine of %.2lf is: %.2lf \n", num1, result);
      break;
    case 't':
      result = tan(num1);
      printf("The tangent of %.2lf is: %.2lf \n", num1, result);
      break;
    case 'q':
      result = sqrt(num1);
      printf("The square root of %.2lf is: %.2lf \n", num1, result);
      break;
    default:
      printf("Error: Invalid operator. \n");
      break;
  }

  return 0;
}