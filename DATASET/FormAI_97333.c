//FormAI DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include <stdio.h>

/* This program demonstrates basic arithmetic operations */

int main() {
  int num1, num2, sum, diff, prod, mod;
  float quo;

  // Prompt user for input
  printf("Enter two integers: ");
  scanf("%d %d", &num1, &num2);

  // Perform arithmetic operations
  sum = num1 + num2;
  diff = num1 - num2;
  prod = num1 * num2;
  
  if (num2 != 0) {
      quo = (float)num1 / num2;
      mod = num1 % num2;
  }

  // Display results
  printf("The sum of %d and %d is %d.\n", num1, num2, sum);
  printf("The difference of %d and %d is %d.\n", num1, num2, diff);
  printf("The product of %d and %d is %d.\n", num1, num2, prod);
  
  if (num2 != 0) {
      printf("The quotient of %d and %d is %.2f.\n", num1, num2, quo);
      printf("The remainder when divided by %d is %d.\n", num2, mod);
  } else {
      printf("Cannot perform division and modulo by 0.\n");
  }

  return 0;
}