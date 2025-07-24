//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Greeting message
  printf("Welcome to the Amazing Scientific Calculator!\n");

  // Variable declaration and initialization
  double num1, num2, result;
  char operator;

  // User input section
  printf("Please enter your first number: ");
  scanf("%lf", &num1);
  printf("Please choose an operator (+, -, *, /, ^): ");
  scanf(" %c", &operator); //Note the space before %c
  printf("Please enter your second number: ");
  scanf("%lf", &num2);

  // Calculation section
  switch(operator) {
    case '+':
      result = num1 + num2;
      printf("The sum of %lf and %lf is %lf.\n", num1, num2, result);
      break;
    case '-':
      result = num1 - num2;
      printf("The difference between %lf and %lf is %lf.\n", num1, num2, result);
      break;
    case '*':
      result = num1 * num2;
      printf("%lf multiplied by %lf equals %lf.\n", num1, num2, result);
      break;
    case '/':
      if (num2 == 0) {
        printf("Error: Division by zero is undefined.\n");
        exit(0);
      }
      result = num1 / num2;
      printf("%lf divided by %lf equals %lf.\n", num1, num2, result);
      break;
    case '^':
      result = pow(num1, num2);
      printf("%lf raised to the power of %lf is %lf.\n", num1, num2, result);
      break;
    default:
      printf("Error: Unrecognized operator.\n");
      exit(0);
  }

  // Closing message
  printf("Thank you for using the Amazing Scientific Calculator!\n");

  return 0;
}