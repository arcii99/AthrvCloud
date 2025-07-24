//FormAI DATASET v1.0 Category: Arithmetic ; Style: multivariable
#include <stdio.h>

int main() {
  // Initializing variables
  int num1, num2, sum, diff, prod, div;

  // Taking input from user
  printf("Enter the first number: ");
  scanf("%d", &num1);
  printf("Enter the second number: ");
  scanf("%d", &num2);

  // Performing Arithmetic operations
  sum = num1 + num2;
  diff = num1 - num2;
  prod = num1 * num2;
  div = num1 / num2;

  // Printing results
  printf("The sum of %d and %d is: %d\n", num1, num2, sum);
  printf("The difference between %d and %d is: %d\n", num1, num2, diff);
  printf("The product of %d and %d is: %d\n", num1, num2, prod);
  printf("The division of %d by %d is: %d\n", num1, num2, div);

  return 0;
}