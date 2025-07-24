//FormAI DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>

int main() {
  // Declare variables
  int num1, num2, sum, diff, product;
  float quotient;

  // Ask user to enter two numbers
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  // Perform arithmetic operations
  sum = num1 + num2;
  diff = num1 - num2;
  product = num1 * num2;

  // Check if num2 is nonzero to avoid division by zero error
  if (num2 != 0) {
    quotient = (float) num1 / num2;
  }

  // Display results
  printf("Sum = %d\n", sum);
  printf("Difference = %d\n", diff);
  printf("Product = %d\n", product);

  // Check if quotient has been calculated before printing it
  if (num2 != 0) {
    printf("Quotient = %.2f\n", quotient);
  }
  
  return 0;
}