//FormAI DATASET v1.0 Category: Arithmetic ; Style: Alan Touring
#include <stdio.h>

int main() {
  // Declare and initialize variables
  int num1 = 10, num2 = 5;
  float decimalNum1 = 12.5, decimalNum2 = 3.8;
  
  // Addition
  int sum = num1 + num2;
  float decimalSum = decimalNum1 + decimalNum2;
  
  printf("Addition:\n");
  printf("Sum of %d and %d: %d\n", num1, num2, sum);
  printf("Sum of %.2f and %.2f: %.2f\n\n", decimalNum1, decimalNum2, decimalSum);
  
  // Subtraction
  int difference = num1 - num2;
  float decimalDifference = decimalNum1 - decimalNum2;
  
  printf("Subtraction:\n");
  printf("Difference between %d and %d: %d\n", num1, num2, difference);
  printf("Difference between %.2f and %.2f: %.2f\n\n", decimalNum1, decimalNum2, decimalDifference);
  
  // Multiplication
  int product = num1 * num2;
  float decimalProduct = decimalNum1 * decimalNum2;
  
  printf("Multiplication:\n");
  printf("Product of %d and %d: %d\n", num1, num2, product);
  printf("Product of %.2f and %.2f: %.2f\n\n", decimalNum1, decimalNum2, decimalProduct);
  
  // Division
  int quotient = num1 / num2;
  float decimalQuotient = decimalNum1 / decimalNum2;
  
  printf("Division:\n");
  printf("Quotient of %d and %d: %d\n", num1, num2, quotient);
  printf("Quotient of %.2f and %.2f: %.2f\n\n", decimalNum1, decimalNum2, decimalQuotient);
  
  // Modulus
  int remainder = num1 % num2;
  
  printf("Modulus:\n");
  printf("Remainder when %d is divided by %d: %d\n", num1, num2, remainder);
  
  return 0;
}