//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  char operation;
  double num, result;

  printf("Welcome to my scientific calculator!\n");
  printf("Please enter an operation (+, -, *, /, sin, cos, tan, log, sqrt, pow): ");
  scanf("%c", &operation);

  switch(operation) {
    case '+':
      printf("Enter the first number: ");
      scanf("%lf", &num);
      printf("Enter the second number: ");
      scanf("%lf", &result);
      result += num;
      break;
    case '-':
      printf("Enter the first number: ");
      scanf("%lf", &num);
      printf("Enter the second number: ");
      scanf("%lf", &result);
      result = num - result;
      break;
    case '*':
      printf("Enter the first number: ");
      scanf("%lf", &num);
      printf("Enter the second number: ");
      scanf("%lf", &result);
      result *= num;
      break;
    case '/':
      printf("Enter the first number: ");
      scanf("%lf", &num);
      printf("Enter the second number: ");
      scanf("%lf", &result);
      if (num == 0.0) {
        printf("Error: divide by zero\n");
        exit(0);
      }
      result = num / result;
      break;
    case 's':
      printf("Enter the number: ");
      scanf("%lf", &num);
      result = sin(num);
      break;
    case 'c':
      printf("Enter the number: ");
      scanf("%lf", &num);
      result = cos(num);
      break;
    case 't':
      printf("Enter the number: ");
      scanf("%lf", &num);
      result = tan(num);
      break;
    case 'l':
      printf("Enter the number: ");
      scanf("%lf", &num);
      if (num <= 0.0) {
        printf("Invalid input for log\n");
        exit(0);
      }
      result = log(num);
      break;
    case 'q':
      printf("Enter the number: ");
      scanf("%lf", &num);
      if (num < 0.0) {
        printf("Invalid input for square root\n");
        exit(0);
      }
      result = sqrt(num);
      break;
    case 'p':
      printf("Enter the base: ");
      scanf("%lf", &num);
      printf("Enter the power: ");
      scanf("%lf", &result);
      result = pow(num, result);
      break;
    default:
      printf("Invalid operation\n");
      exit(0);
  }

  printf("Result: %lf\n", result);

  return 0;
}