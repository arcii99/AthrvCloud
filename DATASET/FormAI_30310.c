//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  double num1, num2;
  char operator;

  printf("Welcome to the Scientific Calculator! \n");
  printf("Please enter your first number: ");
  scanf("%lf", &num1);

  printf("Please enter your operator (+, -, *, /, ^): ");
  scanf(" %c", &operator);

  if(operator == '^') {
    printf("Please enter your second number, which will represent the exponent: ");
    scanf("%lf", &num2);
    double result = pow(num1, num2);
    printf("%lf ^ %lf = %lf \n", num1, num2, result);
  }

  else {
    printf("Please enter your second number: ");
    scanf("%lf", &num2);

    if(operator == '+') {
      double result = num1 + num2;
      printf("%lf + %lf = %lf \n", num1, num2, result);
    }

    else if(operator == '-') {
      double result = num1 - num2;
      printf("%lf - %lf = %lf \n", num1, num2, result);
    }

    else if(operator == '*') {
      double result = num1 * num2;
      printf("%lf * %lf = %lf \n", num1, num2, result);
    }

    else if(operator == '/') {
      if(num2 == 0) {
        printf("Cannot divide by zero. \n");
      }

      else {
        double result = num1 / num2;
        printf("%lf / %lf = %lf \n", num1, num2, result);
      }
    }

    else {
      printf("Invalid operator. \n");
    }
  }

  return 0;
}