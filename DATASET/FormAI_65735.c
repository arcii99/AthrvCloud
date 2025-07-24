//FormAI DATASET v1.0 Category: Calculator ; Style: thoughtful
#include <stdio.h>

int main() {

  int num1, num2, sum, diff, prod, quo, rem;

  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  // perform addition
  sum = num1 + num2;

  // perform subtraction
  diff = num1 - num2;

  // perform multiplication
  prod = num1 * num2;

  // perform division
  quo = num1 / num2;

  // find remainder
  rem = num1 % num2;

  printf("Sum = %d \n", sum);
  printf("Difference = %d \n", diff);
  printf("Product = %d \n", prod);
  printf("Quotient = %d \n", quo);
  printf("Remainder = %d \n", rem);

  return 0;
}