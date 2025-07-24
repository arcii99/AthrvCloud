//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: cheerful
#include <stdio.h>
#include <math.h>

int main() {
  double num1, num2;
  char op;

  printf("Welcome to the Magical Calculator!\n");
  printf("Please enter your first number: ");
  scanf("%lf", &num1);

  printf("Please enter your second number: ");
  scanf("%lf", &num2);

  printf("Please enter your operation: Add(+), Subtract(-), Multiply(*) or Divide(/): ");
  scanf(" %c", &op);

  if(op == '+') {
    printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
  } else if(op == '-') {
    printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
  } else if(op == '*') {
    printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
  } else if(op == '/') {
    if(num2 == 0) {
      printf("Oops! Division by zero is invalid\n");
    } else {
      printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
    }
  } else {
    printf("Invalid operation! Please try again\n");
  }

  printf("Now, let's explore some advanced scientific calculations!\n");
  
  printf("Enter a number to find its square root: ");
  scanf("%lf", &num1);

  printf("The square root of %.2lf is %.2lf\n", num1, sqrt(num1));

  printf("Enter a number to find its cube root: ");
  scanf("%lf", &num1);

  printf("The cube root of %.2lf is %.2lf\n", num1, cbrt(num1));

  printf("Enter a number and its power (as an integer): ");
  scanf("%lf %lf", &num1, &num2);

  printf("%.2lf raised to the power of %.2lf is %.2lf\n", num1, num2, pow(num1, num2));

  printf("Thanks for using the Magical Calculator! Come back soon!\n");

  return 0;
}