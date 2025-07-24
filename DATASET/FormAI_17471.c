//FormAI DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include <stdio.h>

int main() {
  int num1, num2; // initialize variables for holding user input
  int sum, product, quotient, remainder; // initialize variables for arithmetic operations

  printf("Welcome to the Arithmetic Program!\n");

  printf("Please enter the first number: ");
  scanf("%d", &num1);

  printf("Please enter the second number: ");
  scanf("%d", &num2);

  // perform arithmetic operations
  sum = num1 + num2;
  product = num1 * num2;
  quotient = num1 / num2;
  remainder = num1 % num2;

  // display results to user
  printf("\nArithmetic Results:\n");
  printf("Sum: %d\n", sum);
  printf("Product: %d\n", product);
  printf("Quotient: %d\n", quotient);
  printf("Remainder: %d\n", remainder);

  printf("\nThank you for using the Arithmetic Program!");
  
  return 0;
}