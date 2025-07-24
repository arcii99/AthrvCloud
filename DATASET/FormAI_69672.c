//FormAI DATASET v1.0 Category: Arithmetic ; Style: expert-level
#include <stdio.h>

int main() {
  int num1, num2, sum, diff, prod, quotient, remainder;

  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);
  
  // Addition of the two numbers
  sum = num1 + num2;
  
  // Subtraction of the two numbers
  diff = num1 - num2;
  
  // Multiplication of the two numbers
  prod = num1 * num2;
  
  // Division of the two numbers and finding the quotient and remainder
  quotient = num1 / num2;
  remainder = num1 % num2;

  // Displaying the results
  printf("Sum of %d and %d is: %d\n", num1, num2, sum);
  printf("Difference between %d and %d is: %d\n", num1, num2, diff);
  printf("Product of %d and %d is: %d\n", num1, num2, prod);
  printf("When %d is divided by %d, the quotient is: %d and the remainder is: %d\n", num1, num2, quotient, remainder);

  return 0;
}