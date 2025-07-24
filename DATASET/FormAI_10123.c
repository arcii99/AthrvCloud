//FormAI DATASET v1.0 Category: Arithmetic ; Style: shocked
#include <stdio.h>

int main() {
  int num1, num2, sum, diff, prod, quot, rem;

  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  // Arithmetic operations
  sum = num1 + num2;
  diff = num1 - num2;
  prod = num1 * num2;
  quot = num1 / num2;
  rem = num1 % num2;

  // Displaying results
  printf("Sum of %d and %d is %d.\n", num1, num2, sum);
  printf("Difference of %d and %d is %d.\n", num1, num2, diff);
  printf("Product of %d and %d is %d.\n", num1, num2, prod);
  printf("Quotient of %d and %d is %d.\n", num1, num2, quot);
  printf("Remainder of %d and %d is %d.\n", num1, num2, rem);

  return 0;
}