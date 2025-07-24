//FormAI DATASET v1.0 Category: Arithmetic ; Style: realistic
// C Arithmetic Example Program
#include <stdio.h>

int main() {
  int num1, num2, sum, difference, product;
  float quotient;

  printf("Enter first number: ");
  scanf("%d", &num1);

  printf("\nEnter second number: ");
  scanf("%d", &num2);

  // Perform arithmetic operations
  sum = num1 + num2;
  difference = num1 - num2;
  product = num1 * num2;
  quotient = (float) num1 / num2;

  // Display results
  printf("\nSum of %d and %d is %d", num1, num2, sum);
  printf("\nDifference of %d and %d is %d", num1, num2, difference);
  printf("\nProduct of %d and %d is %d", num1, num2, product);
  printf("\nQuotient of %d and %d is %.2f", num1, num2, quotient);

  return 0;
}