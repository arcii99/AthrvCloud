//FormAI DATASET v1.0 Category: Game ; Style: multivariable
#include <stdio.h>

int main() {
  int num1, num2, sum, diff, prod, mod;
  
  // take input from user
  printf("Enter first number: ");
  scanf("%d", &num1);
  printf("Enter second number: ");
  scanf("%d", &num2);
  
  // perform calculations
  sum = num1 + num2;
  diff = num1 - num2;
  prod = num1 * num2;
  mod = num1 % num2;
  
  // print results
  printf("Sum: %d\n", sum);
  printf("Difference: %d\n", diff);
  printf("Product: %d\n", prod);
  printf("Modulus: %d\n", mod);
  
  return 0;
}