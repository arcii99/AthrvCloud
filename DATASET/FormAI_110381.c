//FormAI DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>

int main() {
  int num1, num2, sum, product, quotient, remainder;
  
  printf("Enter the first number: ");
  scanf("%d", &num1);
  
  printf("Enter the second number: ");
  scanf("%d", &num2);
  
  sum = num1 + num2;
  product = num1 * num2;
  quotient = num1 / num2;
  remainder = num1 % num2;
  
  printf("\nSum: %d\n", sum);
  printf("Product: %d\n", product);
  printf("Quotient: %d\n", quotient);
  printf("Remainder: %d\n", remainder);
  
  //swapping the numbers using arithmetic operations
  printf("\nBefore swapping: num1 = %d, num2 = %d\n", num1, num2);
  
  num1 = num1 + num2;
  num2 = num1 - num2;
  num1 = num1 - num2;
  
  printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
  
  return 0;
}