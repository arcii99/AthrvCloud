//FormAI DATASET v1.0 Category: Educational ; Style: calm
#include <stdio.h>

int main(void) {
  int num1, num2, sum, diff, product, quotient;

  printf("Enter first number: ");
  scanf("%d", &num1);

  printf("Enter second number: ");
  scanf("%d", &num2);

  sum = num1 + num2;
  diff = num1 - num2;
  product = num1 * num2;
  quotient = num1 / num2;

  printf("Sum of %d and %d is %d\n", num1, num2, sum);
  printf("Difference between %d and %d is %d\n", num1, num2, diff);
  printf("Product of %d and %d is %d\n", num1, num2, product);
  printf("Quotient of %d and %d is %d\n", num1, num2, quotient);

  return 0;
}