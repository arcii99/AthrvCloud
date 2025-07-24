//FormAI DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, sum, diff, product, quotient, remainder;
  
  // Generate random numbers between 1 and 100
  srand(time(NULL));
  num1 = rand() % 100 + 1;
  num2 = rand() % 100 + 1;
  
  // Perform arithmetic operations
  sum = num1 + num2;
  diff = num1 - num2;
  product = num1 * num2;
  quotient = num1 / num2;
  remainder = num1 % num2;
  
  // Print the results
  printf("Number 1: %d\nNumber 2: %d\n\n", num1, num2);
  printf("Sum: %d\nDifference: %d\nProduct: %d\nQuotient: %d\nRemainder: %d\n", sum, diff, product, quotient, remainder);
  
  return 0;
}