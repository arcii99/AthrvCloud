//FormAI DATASET v1.0 Category: Arithmetic ; Style: romantic
#include <stdio.h>

int main() {
  int a, b, sum, diff, prod, quo, rem; // declare variables
  
  // read input values from user
  printf("Enter two integer values: ");
  scanf("%d %d", &a, &b);
  
  // perform arithmetic operations
  sum = a + b;
  diff = a - b;
  prod = a * b;
  quo = a / b;
  rem = a % b;
  
  // display results
  printf("\nSum of %d and %d is %d", a, b, sum);
  printf("\nDifference of %d and %d is %d", a, b, diff);
  printf("\nProduct of %d and %d is %d", a, b, prod);
  printf("\nQuotient of %d and %d is %d", a, b, quo);
  printf("\nRemainder of %d divided by %d is %d", a, b, rem);
  
  return 0; // terminate program
}