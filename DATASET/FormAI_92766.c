//FormAI DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include <stdio.h>

int main() {
  int num1, num2, sum, difference, product, quotient;
  
  printf("Enter the first number: ");
  scanf("%d", &num1);
  printf("Enter the second number: ");
  scanf("%d", &num2);
  
  sum = num1 + num2; // Adds the two numbers
  difference = num1 - num2; // Subtracts the second number from the first
  product = num1 * num2; // Multiplies the two numbers
  quotient = num1 / num2; // Divides the first number by the second
  
  printf("Sum: %d\n", sum); // Prints the sum
  printf("Difference: %d\n", difference); // Prints the difference
  printf("Product: %d\n", product); // Prints the product
  printf("Quotient: %d\n", quotient); // Prints the quotient
  
  return 0;
}