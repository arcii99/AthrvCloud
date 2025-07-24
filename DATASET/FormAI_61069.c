//FormAI DATASET v1.0 Category: Arithmetic ; Style: relaxed
#include <stdio.h>

/* This program takes two integers and performs arithmetic operations on them */

int main() {
  int num1, num2, sum, diff, prod, quot, mod;
  
  printf("Enter first integer: ");
  scanf("%d", &num1);
  
  printf("Enter second integer: ");
  scanf("%d", &num2);
  
  sum = num1 + num2;
  diff = num1 - num2;
  prod = num1 * num2;
  quot = num1 / num2;
  mod = num1 % num2;
  
  printf("\n\nArithmetic operations on %d and %d\n", num1, num2);
  printf("Sum: %d\n", sum);
  printf("Difference: %d\n", diff);
  printf("Product: %d\n", prod);
  printf("Quotient: %d\n", quot);
  printf("Modulus: %d\n", mod);
  
  return 0;
}