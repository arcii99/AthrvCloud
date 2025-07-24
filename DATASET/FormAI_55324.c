//FormAI DATASET v1.0 Category: Arithmetic ; Style: Alan Touring
#include <stdio.h>

int main() {
  int num1, num2, sum, difference, product;
  float quotient;

  printf("Enter first number: ");
  scanf("%d", &num1);

  printf("Enter second number: ");
  scanf("%d", &num2);

  sum = num1 + num2;
  difference = num1 - num2;
  product = num1 * num2;
  quotient = (float) num1 / num2;

  printf("Sum of %d and %d is %d\n", num1, num2, sum);
  printf("Difference between %d and %d is %d\n", num1, num2, difference);
  printf("Product of %d and %d is %d\n", num1, num2, product);
  printf("Quotient of %d and %d is %.2f\n", num1, num2, quotient);

  return 0;
}