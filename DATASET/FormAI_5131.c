//FormAI DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>

int main() {
  // Declare Variables
  int num1, num2, sum, difference, product;
  float quotient;

  // Take Input
  printf("Enter two integers: ");
  scanf("%d %d", &num1, &num2);

  // Perform Arithmetic Operations
  sum = num1 + num2;
  difference = num1 - num2;
  product = num1 * num2;
  quotient = (float)num1 / num2;

  // Print Output
  printf("Sum = %d\n", sum);
  printf("Difference = %d\n", difference);
  printf("Product = %d\n", product);
  printf("Quotient = %.2f\n", quotient);

  return 0;
}