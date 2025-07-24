//FormAI DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>

int main() {
  // Declare and initialize variables
  int num1 = 10, num2 = 5;
  
  // Perform arithmetic operations
  int sum = num1 + num2;
  int difference = num1 - num2;
  int product = num1 * num2;
  int quotient = num1 / num2;
  int remainder = num1 % num2;

  // Print the results
  printf("Sum of %d and %d is %d\n", num1, num2, sum);
  printf("Difference of %d and %d is %d\n", num1, num2, difference);
  printf("Product of %d and %d is %d\n", num1, num2, product);
  printf("Quotient of %d and %d is %d\n", num1, num2, quotient);
  printf("Remainder of %d and %d is %d\n", num1, num2, remainder);

  // Update values and perform arithmetic operations again
  num1 = 13;
  num2 = 4;
  sum = num1 + num2;
  difference = num1 - num2;
  product = num1 * num2;
  quotient = num1 / num2;
  remainder = num1 % num2;

  // Print the updated results
  printf("\nAfter updating the values:\n");
  printf("Sum of %d and %d is %d\n", num1, num2, sum);
  printf("Difference of %d and %d is %d\n", num1, num2, difference);
  printf("Product of %d and %d is %d\n", num1, num2, product);
  printf("Quotient of %d and %d is %d\n", num1, num2, quotient);
  printf("Remainder of %d and %d is %d\n", num1, num2, remainder);

  return 0;
}